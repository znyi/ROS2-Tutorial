#from example_interfaces.srv import AddTwoInts
from tutorial_interfaces.srv import AddThreeInts

import rclpy
from rclpy.node import Node


class MinimalService(Node):

    def __init__(self):
        super().__init__('minimal_service')
        # self.srv = self.create_service(AddTwoInts, 'py_add_two_ints', self.add_two_ints_callback)
        self.srv = self.create_service(AddThreeInts, 'py_add_three_ints', self.add_three_ints_callback)

    # def add_two_ints_callback(self, request, response):
    def add_three_ints_callback(self, request, response):
        # response.sum = request.a + request.b
        # self.get_logger().info('Incoming request\na: %d b: %d' % (request.a, request.b))
        
        response.sum = request.a + request.b + request.c
        self.get_logger().info('Incoming request\na: %d b: %d c: %d' % (request.a, request.b, request.c))

        return response


def main(args=None):
    rclpy.init(args=args)

    minimal_service = MinimalService()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()