# Robotics

source startup.sh 

colcon build --cmake-args -DCMAKE_PREFIX_PATH="/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/external/libtorch/libtorch"

source install/setup.bash

ros2 launch start_simulation start_simulation.launch.py
