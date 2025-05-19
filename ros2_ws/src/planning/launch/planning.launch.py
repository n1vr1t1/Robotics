import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        Node(
            package='planning',
            executable='control_unit',
            name='control_node',
            output='screen'
        ),
        # Add the icp_pose_estimator_node node
        Node(
            package='planning',
            executable='trajectory_execution',
            name='trajectory_execution_node',
            output='screen'
        ),
    ])
