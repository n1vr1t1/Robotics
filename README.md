# Robotics Project  
### Fundamentals of Robotics – University of Trento

![Languages](https://img.shields.io/badge/languages-C++%2C%20Python%2C%20CMake%2C%20Shell%2C%20Dockerfile-blue)
![Repo Size](https://img.shields.io/github/repo-size/SaraFrancavilla/Robotics)

---

Welcome! This repository contains the codebase and resources for the project of the Fundamentals of Robotics course at the University of Trento.  
The project challenges students to program a robotic manipulator to autonomously **detect**, **pick**, and **sort objects** using state-of-the-art computer vision and motion planning techniques.

---

## Table of Contents

- [Project Description](#project-description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Virtual Machine Setup](#virtual-machine-setup)
- [Usage](#usage)

---

## Project Description

**Assignment:**  
A collection of objects (e.g., lego-blocks) are scattered on an initial stand within reach of a robotic arm (anthropomorphic manipulator with a spherical wrist and two-fingered gripper).  
Mission:
- **Detect & Locate:** Use a calibrated 3D sensor and a fine-tuned YOLOv11 deep learning model to detect and localize each object.
- **Pick & Place:** Program the robot to pick up each object and place it in a specified slot on the final stand, matching its silhouette and class.
- **Sequence:** Ensure the process follows a prescribed order and leverages robust perception, planning, and control.

**Objectives:**
- Build robust perception pipelines for object recognition and localization
- Implement efficient and reliable robot motion planning
- Design a high-level planner for automated pick-and-place tasks

---

## Features

- **Deep Learning Perception**: YOLOv11 model for accurate object detection & position extraction.
- **3D Sensor Integration**: Realistic simulation of robot perception.
- **Grasp Planning & Control**: Manipulate objects with a two-fingered gripper.
- **Class-based Sorting**: Place each object in its designated position.
- **ROS 2 Workspace**: Modular structure for easy extension and compatibility.
- **Automation Scripts**: For building, launching, and testing.

---

## Prerequisites

- C++ Compiler (GCC/Clang)
- Python 3.x
- [ROS 2 Humble](https://docs.ros.org/en/humble/)
- CMake (>= 3.10)
- Docker *(optional, for containerized development)*
- Git

---

## Virtual Machine Setup

> **Recommended:** Run and test this project inside a dedicated robotics simulation virtual machine.

For **detailed VM setup instructions**, follow the guide in [pla10/ros2_ur5_interface](https://github.com/pla10/ros2_ur5_interface).  
This will walk you through all system and ROS dependencies, ensuring a smooth project experience.

---

## Usage

#### 1. Clone the Repository

After setting up your virtual machine, open a terminal in the environment and navigate to the ROS2 workspace source directory:

```bash
cd /home/ubuntu/ros2_ws/src
git clone https://github.com/SaraFrancavilla/Robotics.git
```

#### 2. Install PyTorch C++ (libtorch) via Startup Script

```bash
cd Robotics/ros2_ws
source startup.sh   # Installs libtorch and sets up environment
```

#### 3. Build the Packages

```bash
colcon build --cmake-args -DCMAKE_PREFIX_PATH="/home/ubuntu/ros2_ws/src/Robotics/ros2_ws/external/libtorch/libtorch"
```

#### 4. Source the Workspace

```bash
source install/setup.bash
```

#### 5. Launch the Simulation

```bash
ros2 launch start_simulation start_simulation.launch.py
```

---
