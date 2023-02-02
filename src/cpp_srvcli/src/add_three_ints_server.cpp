#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp" //package dependencies

#include <memory>

void add(const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
          std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response>      response)
{
  response->sum = request->a + request->b + request->c;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{ 
  rclcpp::init(argc, argv); //init ros2 cpp client library

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_three_ints_server"); //create server node named "add_two_ints_server"

  rclcpp::Service<tutorial_interfaces::srv::AddThreeInts>::SharedPtr service =
    node->create_service<tutorial_interfaces::srv::AddThreeInts>("add_three_ints", &add); //create service named "add_two_ints", automatically advertise the service over the networks with &add method

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add three ints."); //print log when ready

  rclcpp::spin(node);
  rclcpp::shutdown();
}