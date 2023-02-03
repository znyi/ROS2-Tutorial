from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='python_parameters',
            executable='py_minimal_param_node', #the executable!!
            name='custom_minimal_param_node',
            output='screen',  # we ensure our output
            emulate_tty=True, # is printed in our console
            parameters=[
                {'my_parameter': 'earth'}
            ]
        )
    ])