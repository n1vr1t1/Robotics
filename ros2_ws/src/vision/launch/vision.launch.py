import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    script_path = os.path.join(
        os.getcwd(), 'src', 'vision', 'launch', 'start_vision.sh'
    )

    return LaunchDescription([
        # Run the shell script to start the original node
        ExecuteProcess(
            cmd=[script_path],
            shell=True,
            output='screen'
        ),

        # Add the vision_node node
        Node(
            package='vision',
            executable='vision_node',
            name='vision_node',
            output='screen'
        ),
        
        # Add the detection_result_republisher node
        Node(
            package='vision',
            executable='detection_result_republisher',
            name='detection_result_republisher',
            output='screen'
        ),
        
    ])
