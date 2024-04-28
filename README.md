# Chemical Miller ESP32

In this project of C2 P1 of mechatronics engineering, I made a ball mill, which has the purpose of grinding chemical elements (one or more) with the point of making a uniform and fine union between the two elements.

The objective of the project is to make a uniform and fine mixture of two chemical elements to perform a combustion, the combustion must not have residues, so it must be a well done grinding.

Frontend of this project: [Miller-front](https://github.com/jdic/MIller-front).

## Hardware requirements

- ESP32
- DC Motor
- Ultrasonic HC-SR04
- Buzzer

## Software Requirements

- [VSCode](https://code.visualstudio.com/) | [Arduino IDE](https://www.arduino.cc/en/software) (Rest optional)
- Extensions:
  - [PlatformIO](https://platformio.org/)
  - [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
- Libraries:
  - Ultrasonic-HC-SR04

## Configuration

1. Connect the ESP32/Arduino to the Ultrasonic en DC Engine.
2. Upload the provided code to the ESP32/Arduino using the PlatformIO Extensiom.

## Usage

1. Turn on the ESP32/Arduino.
2. When an object comes within the set range, the dispenser will automatically activate for a set time.
3. After dispensing, the system verifies that the object initiating the dispensing state has been removed so that it can be activated again.

## Functionalities

- The ultrasonic sensor detects the distance between the object and the sensor.
- When the object is within the specified distance range, the dispenser is activated.
- After dispensing for a predetermined time, the system verifies that the object initiating the dispensing state has been removed so that it can be activated again.

Best part of the code:

```c++
void awake()
{
  Serial.begin(115200);

  Serial.println("──────▄▀▄─────▄▀▄");
  Serial.println("─────▄█░░▀▀▀▀▀░░█▄");
  Serial.println("─▄▄──█░░░░░░░░░░░█──▄▄");
  Serial.println("█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█");

  pinMode(IN, OUTPUT);
  digitalWrite(IN, HIGH);
}
```

This project was created by JMota during the C2 P2.