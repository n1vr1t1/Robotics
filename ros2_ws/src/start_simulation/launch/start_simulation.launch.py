import launch
import launch_ros.actions
from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node  

def generate_launch_description():

    ros2_ur5_interface_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [FindPackageShare("ros2_ur5_interface"), "/launch/sim.launch.py"]
        )
    )

    #vision_launch = IncludeLaunchDescription(
    #    PythonLaunchDescriptionSource(
    #        [FindPackageShare("vision"), "/launch/vision.launch.py"]
    #    )
    #)

    #motion_launch = IncludeLaunchDescription(
    #    PythonLaunchDescriptionSource(
    #        [FindPackageShare("motion"), "/launch/motion.launch.py"]
    #    )
    #)

    #planning_launch = IncludeLaunchDescription(
    #    PythonLaunchDescriptionSource(
    #        [FindPackageShare("planning"), "/launch/planning.launch.py"]
    #    )
    #)

    return launch.LaunchDescription([
        ros2_ur5_interface_launch,
    #    vision_launch,
    #    motion_launch,
    #    planning_launch
    ])

