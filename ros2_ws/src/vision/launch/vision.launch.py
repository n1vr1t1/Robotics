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
