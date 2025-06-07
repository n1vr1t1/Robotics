# Robotics Project – Fundamentals of Robotics @ University of Trento

![Languages](https://img.shields.io/badge/languages-C++%2C%20Python%2C%20CMake%2C%20Shell%2C%20Dockerfile-blue)
![Repo Size](https://img.shields.io/github/repo-size/SaraFrancavilla/Robotics)

## Project OverviewA

This repository contains the codebase and resources for the project in the Fundamentals of Robotics course at the University of Trento. The project involves designing and implementing a robotic system that autonomously picks and sorts objects using an anthropomorphic manipulator with a two-fingered gripper, guided by a calibrated 3D sensor.

The system is capable of:
- Perceiving various objects with known geometry on an initial stand.
- Picking up each object and placing it on a final stand according to a specified order and class-based position.
- Integrating perception, motion planning, and high-level task planning.

This project was run and tested in simulation on a virtual machine environment.  

## Table of Contents

- [Project Description](#project-description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Virtual Machine Setup](#virtual-machine-setup)
- [Usage](#usage)

## Project Description

### Assignment

A set of objects (e.g., lego-blocks) are placed randomly on an initial stand within the workspace of a robotic manipulator (an anthropomorphic arm with a spherical wrist and a two-fingered gripper). Each object belongs to a different class and has a known geometry. The goal is to:
- Locate each object using a pre-calibrated 3D sensor and a YOLOv11 model for object detection and coordinate extraction.
- Pick each object from the initial stand.
- Place each object at a prescribed position on a final stand, matching its class and silhouette.

### Objectives

- Develop robust perception algorithms for object localization and identification.
- Implement reliable robot motion planning for object manipulation.
- Design a high-level planner to sequence the pick-and-place operations.

## Features

- Object detection and localization using a 3D sensor and finetuned YOLOv11 model
- Grasp planning and manipulation with a two-fingered gripper
- Class-based sorting and placement
- Modular C++ and Python codebase
- ROS 2 workspace structure for organization and compatibility
- Automated scripts for setup and running

## Prerequisites

- C++ Compiler (GCC, Clang)
- Python 3.x
- ROS 2 Humble
- CMake (>= 3.10)
- Docker (optional, for containerized development)
- Git

## Virtual Machine Setup

This project is intended to be run and tested on a virtual machine configured for robotics simulation.  
**For step-by-step setup instructions, refer to the [pla10/ros2_ur5_interface](https://github.com/pla10/ros2_ur5_interface) repository.**  
Follow the environment setup process described there to ensure your virtual machine is ready to execute this project.

## Usage

### Clone the Repository
After correctly setting up the virtual environment, open a terminal in the environment and ensure you are in the **/home/ubuntu/ros2_ws/src** directory before cloning the repository:
```bash
git clone https://github.com/SaraFrancavilla/Robotics.git
```

### Using Startup Script
Run the following script to install the pytorch library aimed for C++
```bash
cd Robotics/ros2_ws
source startup.sh
```

### Building and Running Simulation
Ensure you have all the necessary dependencies before building and eventually running the project with the following commands:
```bash
cd src
colcon build --cmake-args -DCMAKE_PREFIX_PATH="/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/external/libtorch/libtorch"
source install/setup.bash
ros2 launch start_simulation start_simulation.launch.py
```

---
