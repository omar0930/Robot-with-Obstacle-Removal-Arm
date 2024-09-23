# Arduino Line Following Robot with Obstacle Removal Arm

This project demonstrates an Arduino-based robot that can autonomously follow a line and remove obstacles using a robotic arm. It also uses machine learning to detect LEGO bricks with a laptop camera.

## Project Overview

This project combines:
- **Line following functionality**: The robot detects a line on the ground using infrared sensors and autonomously follows it.
- **Obstacle removal**: When an obstacle (like a LEGO brick) is detected, the robotic arm removes it from the path.
- **LEGO detection**: The system uses a machine learning model to detect LEGO bricks and control the robotic arm to remove them.

## Hardware Used

- Arduino UNO
- L293D motor driver
- Servo motors
- Robot arm
- IR sensors
- Ultrasonic sensor
- Gear motors and wheels
- Li-ion batteries
- Laptop camera

## Software Used

- Arduino IDE
- Roboflow for dataset processing
- Jupyter Notebook for running the trained machine learning model

## How to Run

### Arduino Code
1. Upload the `real_ino_code.ino` file to the Arduino UNO using the Arduino IDE.
2. Connect the sensors and motors as described in the circuit diagram (`car diagram.png`).

### Jupyter Notebook
1. Install required Python libraries (e.g., `opencv`, `roboflow`).
2. Run the notebook file `logo_detection.ipynb` in Jupyter.
3. The system will use your laptop camera to detect LEGO bricks. You can see the output in `camera detection.png`.

## Project Files
- **car diagram**: The diagram showing how the robot car is structured.
- **car photo**: A photo of the completed robot car.
- **camera detection**: A photo showing the machine learning model detecting LEGO bricks.
- **real ino code**: The Arduino code to run the robot and the arm.
- **logo detection**: The Python code used to detect LEGO bricks with the camera.

## Project Outputs
- The robot follows the line and removes obstacles.
- The LEGO detection model identifies bricks with high accuracy.
