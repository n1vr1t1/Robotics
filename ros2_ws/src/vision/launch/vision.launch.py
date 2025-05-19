import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    script_path = os.path.join(
        os.getcwd(), 'src', 'vision', 'launch'
    )

    return LaunchDescription([
        
        # Add the vision_node node
        Node(
            package='vision',
            executable='pose_from_camera_node',
            name='pose_from_camera_node',
            output='screen'
        ),
        
        # Add the detection_result_republisher node
        Node(
            package='vision',
            executable='yolo_detection_node',
            name='yolo_detection_node',
            output='screen'
        ),
        
    ])
