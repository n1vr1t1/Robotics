import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    script_path = os.path.join(
        os.getcwd(), 'src', 'vision', 'launch', 'start_vision.sh'
    )

    return LaunchDescription([
        ExecuteProcess(
            cmd=[script_path],
            shell=True,
            output='screen'
        ),
        Node(
            package='vision',
            executable='position',
            name='pose_from_camera_node',
            output='screen'
        ),
        Node(
            package='vision',
            executable='detection',
            name='yolo_detection_node',
            output='screen'
        ),
        
    ])
