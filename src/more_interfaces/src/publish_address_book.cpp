#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/address_book.hpp"
//#include "rosidl_tutorials_msgs/msg/contact.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node
{
public:
  AddressBookPublisher()
  : Node("address_book_publisher")
  {
    address_book_publisher_ =
      this->create_publisher<more_interfaces::msg::AddressBook>("address_book", 10); //"address_book" is the topic name

    auto publish_msg = [this]() -> void {
        auto message = more_interfaces::msg::AddressBook(); 
        message.first_name = "John";
        message.last_name = "Doe";
        message.age = 30;
        message.gender = message.MALE;
        message.address = "unknown";
        std::cout << "Publishing Contact\nFirst:" << message.first_name <<
         "  Last:" << message.last_name << std::endl;

        this->address_book_publisher_->publish(message);
      };

      //   auto messages = std::make_shared<more_interfaces::msg::AddressBook>(); //addressbook is an array of contacts (contacts is an existing msg type defined in rosidl_tutorials_msgs)
      //   //std::make_shared - gives a pointer from heap https://cplusplus.com/reference/memory/make_shared/ 
      // {
      //   rosidl_tutorials_msgs::msg::Contact contact;
      //   contact.first_name = "John";
      //   contact.last_name = "Doe";
      //   contact.age = 30;
      //   contact.gender = message.MALE;
      //   contact.address = "unknown";
      //   messages->address_book.push_back(contact);
      // }
      // {
      //   rosidl_tutorials_msgs::msg::Contact contact;
      //   contact.first_name = "Jane";
      //   contact.last_name = "Doe";
      //   contact.age = 20;
      //   contact.gender = message.REMALE;
      //   contact.address = "unknown";
      //   messages->address_book.push_back(contact);
      // }

      //   std::cout << "Publishing address book: " << std::endl;
      //   for(auto contact : msg->address_book){
      //     std::cout << "First:" << contact.first_name <<
      //       "  Last:" << contact.last_name << std::endl;
      //   }
      //   address_book_publisher_->publish(*messages);
      // };

    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::Publisher<more_interfaces::msg::AddressBook>::SharedPtr address_book_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressBookPublisher>());
  rclcpp::shutdown();

  return 0;
}