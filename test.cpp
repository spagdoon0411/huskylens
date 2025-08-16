#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Arduino Nano Every Test");
    Serial.println("Serial communication working!");
}

void loop() {
    Serial.println("Hello from Nano Every!");
    delay(1000);
} 