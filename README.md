# PathTracker

# Line Following Robot

## Overview
This project implements a **Line Following Robot** using Arduino. The robot is equipped with infrared (IR) sensors to detect a black line on a surface and motor controls to follow the line. The robot adjusts its movement based on the sensor readings, allowing it to stay on track by moving straight, turning left, or turning right.

---

## Features
- Utilizes five IR sensors to detect the line’s position.
- Smooth movement using motor speed control.
- Autonomous navigation based on sensor feedback.
- Customizable speed and motor configurations.

---

## Components
### Hardware Requirements:
- Arduino Board
- IR Sensors (x5)
- Motor Driver Module (e.g., L298N)
- DC Motors (x2)
- Robot Chassis
- Wheels (x2)
- Power Supply (e.g., 7.4V Li-Po battery)
- Connecting Wires

### Software Requirements:
- Arduino IDE

---

## Circuit Diagram
- **IR Sensors** are connected to digital pins 9, 10, 11, 12, and 13.
- **Right Motor** connected to pins 2, 4 (control) and 3 (PWM).
- **Left Motor** connected to pins 7, 8 (control) and 5 (PWM).

---

## Setup and Configuration
1. **Install Arduino IDE**: Download and install the latest version of Arduino IDE from the [official website](https://www.arduino.cc/en/software).
2. **Connect Components**: Assemble the hardware as per the circuit diagram.
3. **Upload Code**:
   - Connect the Arduino board to your computer using a USB cable.
   - Open the provided Arduino sketch in the IDE.
   - Select the correct board and COM port from the "Tools" menu.
   - Click the "Upload" button to upload the code to the Arduino.
4. **Power the Robot**: Connect the power supply to the motor driver and Arduino.
5. **Test the Robot**: Place the robot on a track with a clear black line and observe its movement.

---

## How It Works
1. **Sensor Input**: The IR sensors detect the presence or absence of a black line.
   - `HIGH` indicates no line detected (white surface).
   - `LOW` indicates line detected (black surface).
2. **Decision Making**:
   - If the middle sensor detects the line, the robot moves forward.
   - If the left or right sensors detect the line, the robot adjusts by turning left or right accordingly.
   - If no sensor detects the line, the robot stops.
3. **Motor Control**: Based on sensor input, the code adjusts motor speed and direction to align the robot with the line.

---

## Functions
### `void setup()`
Initializes pin modes for IR sensors and motor control.

### `void loop()`
Continuously reads IR sensor values and controls the robot's movement based on predefined conditions.

### `void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)`
Controls the speed and direction of the right and left motors.

---

## Customization
- **Adjust Motor Speed**: Modify the `#define MOTOR_SPEED` value to control the robot's speed.
- **Change Sensor Pins**: Update the `#define` values for IR sensors to match your wiring.

---

## Troubleshooting
- **Robot not moving**: Check motor driver connections and power supply.
- **Erratic behavior**: Verify the placement and alignment of IR sensors.
- **No line detection**: Ensure sensors are calibrated and positioned correctly over the track.

---

## Future Enhancements
- Add support for obstacle detection using ultrasonic sensors.
- Implement PID control for smoother navigation.
- Expand functionality for intersection detection and decision-making.

---

## License
This project is open-source and can be freely modified or distributed. Attribution to the original author is appreciated.

---

## Author
Harry To

