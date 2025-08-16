# HUSKYLENS Arduino Examples

This repository contains Arduino C++ examples for the HUSKYLENS AI Machine Vision Sensor. The HUSKYLENS is an easy-to-use AI vision sensor that can perform object recognition, face recognition, line tracking, color recognition, and more.

## Files Included

1. **`huskylens_example.ino`** - Basic example showing object recognition via I2C
2. **`huskylens_advanced_example.ino`** - Advanced example demonstrating all HUSKYLENS algorithms
3. **`huskylens_robot_control.ino`** - Robot control example with PID tracking

## Hardware Requirements

- Arduino board (Uno, Leonardo, Mega, etc.)
- HUSKYLENS AI Machine Vision Sensor
- Jumper wires for I2C connection

## Wiring Instructions

Connect HUSKYLENS to Arduino via I2C:

| HUSKYLENS | Arduino                             |
| --------- | ----------------------------------- |
| VCC       | 5V                                  |
| GND       | GND                                 |
| SDA       | SDA (Pin 20 on Mega, Pin A4 on Uno) |
| SCL       | SCL (Pin 21 on Mega, Pin A5 on Uno) |

## Library Installation

1. Copy the `HUSKYLENSArduino` folder to your Arduino libraries directory:

   - **Windows**: `Documents\Arduino\libraries\`
   - **macOS**: `~/Documents/Arduino/libraries/`
   - **Linux**: `~/Arduino/libraries/`

2. Restart the Arduino IDE

## Basic Example Usage

The `huskylens_example.ino` provides a basic demonstration:

1. Upload the sketch to your Arduino
2. Open the Serial Monitor (115200 baud)
3. On the HUSKYLENS device:
   - Go to General Settings → Protocol Type → I2C
   - Learn an object by pressing the learn button
4. The Arduino will detect and report the learned object

## Advanced Example Features

The `huskylens_advanced_example.ino` demonstrates all HUSKYLENS algorithms:

- **Object Recognition** - Learn and recognize custom objects
- **Face Recognition** - Recognize learned faces
- **Line Tracking** - Track lines and arrows
- **Color Recognition** - Detect and track colors
- **Tag Recognition** - Read AprilTags
- **Object Classification** - Classify objects into categories
- **QR Code Recognition** - Read QR codes

### Serial Commands

Send these commands via Serial Monitor to switch algorithms:

- `1` - Object Recognition
- `2` - Face Recognition
- `3` - Line Tracking
- `4` - Color Recognition
- `5` - Tag Recognition
- `6` - Object Classification
- `7` - QR Code Recognition

## Robot Control Example

The `huskylens_robot_control.ino` demonstrates:

- Object tracking for robot navigation
- PID control for smooth tracking
- Motor control based on object position
- Real-time object following

### Motor Connection

Connect motors to these pins (adjust as needed):

- Left Motor Forward: Pin 5
- Left Motor Backward: Pin 6
- Right Motor Forward: Pin 9
- Right Motor Backward: Pin 10

### PID Tuning

Send commands via Serial Monitor:

- `PID:P,I,D` - Set PID parameters (e.g., `PID:0.5,0.1,0.2`)
- `STOP` - Stop all motors
- `STATUS` - Get current status

## HUSKYLENS Setup

### Learning Objects

1. Power on the HUSKYLENS
2. Select the desired algorithm (Object Recognition, Face Recognition, etc.)
3. Point the camera at the object you want to learn
4. Press the learn button (the object will be assigned ID 1)
5. Repeat for additional objects (they'll get IDs 2, 3, etc.)

### Algorithm Selection

Use the HUSKYLENS touchscreen to select algorithms:

- **Object Recognition**: Learn custom objects
- **Face Recognition**: Learn and recognize faces
- **Line Tracking**: Track lines and arrows
- **Color Recognition**: Detect specific colors
- **Tag Recognition**: Read AprilTags
- **Object Classification**: Classify objects
- **QR Code Recognition**: Read QR codes

## Troubleshooting

### Common Issues

1. **"Begin failed!" message**

   - Check I2C connections
   - Verify HUSKYLENS is set to I2C protocol
   - Ensure proper power supply

2. **"Nothing learned" message**

   - Learn objects on the HUSKYLENS device first
   - Make sure you're using the correct algorithm

3. **No objects detected**

   - Check lighting conditions
   - Ensure objects are within camera view
   - Verify algorithm selection

4. **Poor tracking performance**
   - Adjust PID parameters for robot control
   - Improve lighting conditions
   - Ensure stable camera mounting

### Serial Monitor Settings

- Baud Rate: 115200
- Line Ending: Both NL & CR

## API Reference

### Main Functions

```cpp
// Initialize HUSKYLENS
bool begin(TwoWire &wire);

// Request data
bool request();
bool requestBlocks();
bool requestArrows();
bool requestLearned();

// Check data availability
int available();
bool isLearned();

// Read results
HUSKYLENSResult read();
```

### Result Structure

```cpp
typedef struct {
    uint8_t command;
    int16_t xCenter, yCenter;  // For blocks
    int16_t xOrigin, yOrigin;  // For arrows
    int16_t xTarget, yTarget;  // For arrows
    int16_t width, height;     // For blocks
    int16_t ID;               // Object ID
} HUSKYLENSResult;
```

## License

This code is based on the HUSKYLENS Arduino library by DFRobot, licensed under the GNU Lesser General Public License.

## Support

For more information about HUSKYLENS:

- [DFRobot HUSKYLENS Product Page](https://www.dfrobot.com/product-1922.html)
- [HUSKYLENS Wiki](https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336)
- [HUSKYLENS Protocol Documentation](https://github.com/DFRobot/HUSKYLENS)
