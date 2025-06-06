import os
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([

        Node(
            package='planning',
            executable='control_node',
            name='control_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),

        Node(
            package='planning',
            executable='trajectory_execution_node',
            name='trajectory_execution_node',
            output='screen',
            parameters=[{'use_sim_time': True}]
        ),
    ])
