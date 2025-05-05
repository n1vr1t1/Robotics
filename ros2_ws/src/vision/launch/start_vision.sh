#!/bin/bash

# Source the ROS2 workspace setup.bash
source ~/ros2_ws/install/setup.bash

# Define the base path for your C++ executables
VISION_PATH="$HOME/ros2_ws/src/vision/src"

# Navigate to the directory containing your C++ executables
cd "$VISION_PATH"

# Run each C++ executable (ROS2 node) in the background
./pt_inference_node &  # Replace with your actual C++ executable name
./visualization_node & # Replace with your actual C++ executable name

# Wait for all background processes to finish
wait
