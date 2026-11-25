Hand Gesture Controlled Robotic Car

A wireless robotic car controlled using hand gestures. The system detects the movement of an accelerometer, converts the movement into directional commands, and transmits the commands wirelessly using an RF transmitter and receiver.

Project Overview

This project demonstrates a wireless gesture-based control system for a robotic car.

The accelerometer detects movement along the X and Y axes. The Arduino processes these values and determines whether the user wants the car to move:

Forward

Backward

Left

Right

Stop

The selected command is transmitted using an RF transmitter. A second Arduino receives the command through an RF receiver and controls the motors through a motor driver.


Working Principle

1. Sensor Initialization

The transmitter Arduino reads the initial accelerometer values:

x_val2 = analogRead(x);
y_val2 = analogRead(y);
z_val2 = analogRead(z);

These values are used as the reference position.

2. Gesture Detection

The current sensor values are continuously read:

x_val = analogRead(x);
y_val = analogRead(y);
z_val = analogRead(z);

The difference between the current and reference values is calculated:

x_axis = x_val - x_val2;
y_axis = y_val - y_val2;
z_axis = z_val - z_val2;

A threshold of approximately 50 is used to detect movement.

3. Gesture-to-Command Conversion

Sensor condition

Gesture/Movement

Command

y_axis >= +50

Backward

b

y_axis <= -50

Forward

f

x_axis >= +50

Left

l

x_axis <= -50

Right

r

Otherwise

Stop

s

4. Wireless Transmission

The command is transmitted using the VirtualWire library:

vw_send((uint8_t *)data, strlen(data));
vw_wait_tx();

The RF transmitter is connected to Arduino pin 12.

5. Command Reception

The receiver waits for an RF message:

if (vw_get_message(buf, &buflen))

The first character of the received message is checked.

6. Motor Control

Depending on the received command, the Arduino controls the motor driver.

'f' → Forward
'b' → Backward
'r' → Left
'l' → Right
's' → Stop

Motor Control Logic

Command

M1

M2

M3

M4

Action

f

HIGH

LOW

HIGH

LOW

Forward

b

LOW

HIGH

LOW

HIGH

Backward

r

HIGH

LOW

LOW

LOW

Left

l

LOW

LOW

HIGH

LOW

Right

s

LOW

LOW

LOW

LOW

Stop

Hardware Components

Arduino UNO × 2

Accelerometer/IMU sensor

RF Transmitter

RF Receiver

Motor Driver (L293D/L298N)

DC Motors × 2

Robotic Car Chassis

Battery

Connecting Wires

Software / Libraries

Arduino IDE

Embedded C / Arduino C++

VirtualWire Library

Pin Configuration

Transmitter

Component

Arduino Pin

X-axis

A0

Y-axis

A1

Z-axis

A2

RF Transmitter

D12

Receiver

Component

Arduino Pin

RF Receiver

D11

Motor 1 control

D2, D3

Motor 2 control

D4, D5

Project Modules

Transmitter

Accelerometer
     ↓
Arduino UNO
     ↓
Gesture Detection
     ↓
Command Generation
     ↓
RF Transmitter

Source code:

transmitter/transmitter.ino

Receiver

RF Receiver
     ↓
Arduino UNO
     ↓
Command Decoding
     ↓
Motor Driver
     ↓
DC Motors

Source code:

receiver/receiver.ino

Sensor Testing

The sensor-test program is used before wireless communication is added. It verifies whether the accelerometer correctly detects forward, backward, left and right movements.

Source code:

sensor_test/accelerometer_test.ino

Features

Wireless robotic car control

Gesture-based operation

RF communication

Real-time movement detection

Forward and backward movement

Left and right movement

Stop control

Simple Arduino-based implementation

Applications

Gesture-controlled robotics

Wireless robotic vehicles

Human-machine interfaces

Educational robotics

Assistive robotic systems

IoT and embedded-system demonstrations

Future Improvements

Replace threshold-based detection with calibrated gesture recognition

Add Bluetooth or Wi-Fi communication

Add obstacle detection using ultrasonic sensors

Add speed control using PWM

Add battery monitoring

Add autonomous/manual operating modes

Use a digital IMU such as MPU6050 with proper calibration and filtering

Learning Outcomes

Through this project, I worked with:

Arduino programming

Embedded C/C++

Analog sensor interfacing

Accelerometer-based gesture detection

RF wireless communication

VirtualWire library

Motor driver interfacing

DC motor control

Conditional logic

Hardware-software integration
