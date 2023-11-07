# Fan-Controller

## Description

Welcome to the Temperature-Controlled Fan Controller! This system, utilizing the ATmega32 microcontroller, monitors temperature and automatically controls the fan speed based on the detected temperature. The LM35 temperature sensor and ADC are employed to measure temperature, and the system drives the fan motor with varying speeds to maintain optimal conditions.

## Features

- **Temperature Monitoring:** The LM35 temperature sensor continuously provides analog output, converted to digital values using the ADC module. The microcontroller processes these values to determine the temperature, displaying it on an LCD screen.

- **Dynamic Fan Speed Control:** Based on the temperature reading, the fan operates at different speeds:
    - Below 30°C: Fan turned off.
    - 30-59°C: Fan runs at 25% speed.
    - 60-89°C: Fan operates at 50% speed.
    - 90-119°C: Fan runs at 75% speed.
    - Above 120°C: Fan operates at 100% speed.

- **DC-Motor Direction:** The system controls the DC-Motor's direction based on the fan's state, spinning clockwise or stopped, ensuring optimal cooling.

## Usage

1. **Hardware Setup:** Configure the ATmega32 microcontroller with the required drivers for the ADC, GPIO, LCD, Temperature Sensor, and DC-Motor. Follow the connection specifications mentioned in the requirements.

2. **Temperature Calculation:** The microcontroller processes the ADC digital output to determine the temperature. Display the temperature and fan state continuously on the LCD.

3. **Fan Speed Control:** Set the different fan speeds based on the predefined temperature thresholds to maintain the desired cooling conditions.

4. **DC-Motor Rotation:** Implement DC-Motor driver functions to control the motor's direction and speed based on the fan state.

5. **PWM Signal Generation:** Utilize the PWM driver to manage the DC motor's speed control, ensuring the generated PWM signal operates at the desired duty cycle.

## Layered Architecture Implementation

- **ADC Driver:** Configure the ADC driver using polling design, with an ADC_ConfigType structure.

- **GPIO Driver:** Use the GPIO driver to manage digital input and output operations.

- **LCD Driver:** Employ the LCD driver using 8-bit data mode for temperature and fan state display.

- **Temperature Sensor Driver:** Use the temperature sensor driver to interface with the LM35 temperature sensor connected to ADC channel 2.

- **DC-Motor Driver:** Implement the DC-Motor driver with functions to initialize and rotate the motor based on specified states and speeds.

- **PWM Driver:** Utilize the PWM Timer0 function to control the generated PWM signal for DC-Motor speed adjustment.

