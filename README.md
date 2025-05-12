# Robotics

chmod +x startup.sh 

./startup.sh

colcon build

source install/setup.bash

ros2 launch start_simulation start_simulation.launch.py


# TODO:
- need to transform coordinates from camera's frame to base's frame
- create destination locations for each block
- execute trajectory plan to pick up block from the predicted location to the destination
- get the array of results from the vision node and initialize the variable related to the trajectory node
- publish the coordinates of one block at a time
