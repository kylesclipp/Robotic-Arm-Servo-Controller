/*
  Robotic Arm Motion Sequence
  ---------------------------
  Board: Arduino + PCA9685 Servo Driver (Adafruit_PWMServoDriver)
  Servos: 6 DOF arm (wrist, elbow, tilt, hand, shoulder, rotate)

  Description:
    - Sends a predefined multi-stage movement sequence to the robotic arm.
    - Uses incremental position updates with delays for smooth motion.
    - All servo pulse values are generated directly via pwm.setPWM().
    - Motion sequence is hard-coded for demonstration and testing.
  
  Notes:
    - pos0–pos5 track servo positions throughout runtime.
    - Values sent to setPWM() represent PCA9685 "off" ticks (0–4095).
    - Code maintains original functionality EXACTLY as provided.
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// Global servo position variables
float pos0, pos1, pos2, pos3, pos4, pos5;

int interval = 20;   // unused but kept for compatibility
int next = 350;      // unused but kept for compatibility

void setup() {
  pwm.begin();
  pwm.setPWMFreq(50);   // 50 Hz for standard hobby servos
  delay(10);
}

void loop() {

  // --------------------------
  // Reset arm to starting pose
  // --------------------------

  delay(1000);
  pos0 = 100.0;   // wrist
  pos1 = 120.0;   // elbow
  pos2 = 280.0;   // tilt
  pos3 = 300.0;   // hand open/close
  pos4 = 380.0;   // shoulder
  pos5 = 300.0;   // base rotation
  
  pwm.setPWM(0, 0, pos0);
  pwm.setPWM(1, 0, pos1);
  pwm.setPWM(2, 0, pos2);
  pwm.setPWM(4, 0, pos4);
  pwm.setPWM(3, 0, pos3);
  pwm.setPWM(5, 0, pos5);

  delay(2500);

  // --------------------------
  // Movement Sequence Begins
  // --------------------------

  for (int i = 0; i <= 82; i++) {
    pos5 += 1;
    pwm.setPWM(5, 0, pos5);
    delay(10);
  }

  delay(800);

  for (int i = 0; i <= 50; i++) {
    pos4 -= 1;
    pwm.setPWM(4, 0, pos4);
    delay(20);
  }

  delay(800);

  for (int i = 0; i <= 50; i++) {
    pos4 -= 0.9;
    pos1 += 1.35;
    pos0 += 0.5;

    pwm.setPWM(4, 0, pos4);
    pwm.setPWM(1, 0, pos1);
    pwm.setPWM(0, 0, pos0);
    delay(18);
  }

  delay(800);

  for (int i = 0; i <= 40; i++) {
    pos3 += 1;
    pwm.setPWM(3, 0, pos3);
    delay(8);
  }

  delay(800);

  for (int i = 0; i <= 80; i++) {
    pos4 += 1;
    pwm.setPWM(4, 0, pos4);
    delay(20);
  }

  delay(800);

  for (int i = 0; i <= 80; i++) {
    pos5 -= 0.8;
    pos4 -= 0.78;
    pos1 += 0.35;
    pos0 += 0.22;

    pwm.setPWM(5, 0, pos5);
    pwm.setPWM(4, 0, pos4);
    pwm.setPWM(1, 0, pos1);
    pwm.setPWM(0, 0, pos0);
    delay(12);
  }

  delay(800);

  for (int i = 0; i <= 80; i++) {
    pos2 -= 1;
    pos5 -= 0.35;

    pwm.setPWM(2, 0, pos2);
    pwm.setPWM(5, 0, pos5);
    delay(20);
  }

  delay(800);

  for (int i = 0; i <= 80; i++) {
    pos2 += 1;
    pos5 += 0.35;

    pwm.setPWM(2, 0, pos2);
    pwm.setPWM(5, 0, pos5);
    delay(20);
  }

  delay(800);

  for (int i = 0; i <= 80; i++) {
    pos5 += 0.78;
    pos4 += 0.7;
    pos1 -= 0.35;
    pos0 -= 0.25;

    pwm.setPWM(5, 0, pos5);
    pwm.setPWM(4, 0, pos4);
    pwm.setPWM(1, 0, pos1);
    pwm.setPWM(0, 0, pos0);
    delay(12);
  }

  delay(800);

  for (int i = 0; i <= 65; i++) {
    pos4 -= 1;
    pwm.setPWM(4, 0, pos4);
    delay(20);
  }

  delay(800);

  for (int i = 0; i <= 40; i++) {
    pos3 -= 1;
    pwm.setPWM(3, 0, pos3);
    delay(8);
  }

  for (int i = 0; i <= 50; i++) {
    pos4 += 1;
    pos1 -= 2;
    pos0 -= 0.5;

    pwm.setPWM(4, 0, pos4);
    pwm.setPWM(1, 0, pos1);
    pwm.setPWM(0, 0, pos0);
    delay(18);
  }

  for (int i = 0; i <= 77; i++) {
    pos5 -= 1;
    pwm.setPWM(5, 0, pos5);
    delay(10);
  }

  for (int i = 0; i <= 70; i++) {
    pos4 -= 1.5;
    pos1 += 0.8;

    pwm.setPWM(4, 0, pos4);
    pwm.setPWM(1, 0, pos1);
    delay(10);
  }

  delay(5000);
}
