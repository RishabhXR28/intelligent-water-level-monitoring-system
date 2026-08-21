# Intelligent Water Level Monitoring & Pump Logic System

An Arduino-based automated water-level monitoring and pump-control system designed to reduce manual water-tank monitoring and prevent water overflow.

## Project Role

### Team Leader & Embedded Systems Developer
Led the project team and worked on firmware development, control logic, system integration, and testing.

### Team Members

**Jenish Patel — Hardware & Sensor Integration**
- Physical prototype assembly
- HC-SR04 sensor integration
- Hardware wiring and connections
- Relay and pump integration

**Tirth Patel — Presentation & Documentation**
- Project presentation
- Canva-based visual materials
- Diagrams and documentation
- Project presentation and explanation

## Technologies & Components

- Arduino UNO R3
- HC-SR04 Ultrasonic Sensor
- 1-Channel Active-LOW Relay Module
- DC Water Pump
- Arduino C/C++
- Arduino IDE
- Serial Monitor
- Embedded Systems
- Sensor Interfacing

## How It Works

The HC-SR04 ultrasonic sensor measures the distance between the sensor and the water surface.

### Pump Control Logic

- Distance >= 10 cm → Pump ON
- Distance <= 2 cm → Pump OFF
- 2 cm < Distance < 10 cm → Maintain current pump state

This creates a hysteresis band that helps prevent unnecessary relay switching.

## Sensor Processing

The system:

1. Takes five ultrasonic readings.
2. Filters invalid measurements.
3. Calculates the average of valid readings.
4. Uses the previous valid reading if no valid measurement is available.
5. Sends the measured distance to the Serial Monitor.
6. Controls the pump based on the defined thresholds.

## Features

- Automatic water-level monitoring
- Automatic pump control
- Non-contact ultrasonic sensing
- Sensor reading validation
- Multiple-reading averaging
- Invalid-reading fallback
- Pump-state tracking
- Hysteresis-based control
- Serial Monitor feedback

## Testing

The system was tested against defined test cases covering:

- System startup
- Pump activation
- Pump deactivation
- Hysteresis behavior
- Invalid sensor readings
- Prevention of repeated relay triggering
- Continuous operation

The project report records all 10 defined test cases as PASS.

## Future Improvements

- ESP32/Wi-Fi connectivity
- Mobile application
- Cloud-based monitoring
- OLED display
- Water-flow measurement
- Multi-tank monitoring
- Data logging
- Water-quality monitoring

## Project

First Year Engineering Project  
Computer Engineering  
Saffrony Institute of Technology  
Academic Year 2025–2026