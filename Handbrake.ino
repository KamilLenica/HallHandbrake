 //510 - 710


#include <Joystick.h>

uint32_t mappedAxis = 0;

// Create the Joystick
Joystick_ Joystick(
  0x03, // hidReportId
  0x04, // joystickTyoe
  0,    // buttonCount
  0,    // hatSwitchCount
  false, // X Axis
  false, // Y Axis
  false, // Z Axis
  false, // Rx Axis
  false, // Ry Axis
  false, // Rz Axis
  false, // Rudder
  false, // Throttle
  false, // Accelerator
  true, // Brake
  false  // Steering
  );

void setup() {

  Serial.begin(115200);
  Joystick.setBrakeRange(0, 1023);
  Joystick.begin();
}

void loop() {
  uint32_t axis = analogRead(A2);
  if(axis <= 510)
  {
    mappedAxis = 0;
  }
  else if (axis >= 710)
  {
    mappedAxis = 1023;
  }
  else
  {
    mappedAxis = map(axis, 510, 710, 0, 1023);
  }
  Joystick.setBrake(mappedAxis);
  Serial.println(mappedAxis);
}
