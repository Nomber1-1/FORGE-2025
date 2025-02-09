#include <Servo.h>

// Joystick Ports
#define JOY1_X A1
#define JOY1_Y A0
#define JOY2_X A4
#define JOY2_Y A5
#define BUTTON_1 2
#define BUTTON_2 4

// Motor Ports
#define MOTOR_A1A 9
#define MOTOR_A1B 10
#define MOTOR_B1A 5 
#define MOTOR_B1B 6

Servo myservo;

int pos = 0;
int button_counter = 0;
int joystick_x_1;
int joystick_y_1;
int joystick_x_2;
int joystick_y_2;
int button_1;
int button_2;

void setup() {
  // put your setup code here, to run once:
  pinMode(JOY1_X, INPUT);
  pinMode(JOY1_Y, INPUT);
  pinMode(JOY2_X, INPUT);
  pinMode(JOY2_Y, INPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  
  // Right Wheel
  pinMode(MOTOR_A1A, OUTPUT);
  pinMode(MOTOR_A1B, OUTPUT);

  // Left Wheel
  pinMode(MOTOR_B1A, OUTPUT);
  pinMode(MOTOR_B1B, OUTPUT);
  Serial.begin(9600);

  // Kicking Servo
  myservo.attach(11);
}

void kick() {
  Serial.println("GOAL!!!!");
  for (pos = 70; pos >= -20; pos -= 1) {
    myservo.write(pos);
    delay(1);
  }
  for (pos = -20; pos <= 70; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
}

void turn_left() {
  Serial.println("Turn left");
  /*
  for (int speed = 0; speed < 255; speed++) {
    analogWrite(MOTOR_A1A, speed++);
    analogWrite(MOTOR_B1B, speed++);
    delay(10);
  }
  */
  // Right Wheel
  //analogWrite(MOTOR_A1A, 255);
  analogWrite(MOTOR_A1B, 0);
  // Left Wheel
  analogWrite(MOTOR_B1A, 0);
  analogWrite(MOTOR_B1B, 255);
  delay(100);
}

void turn_right() {
  Serial.println("Turn right");
  /*
  for (int speed = 0; speed < 255; speed++) {
    analogWrite(MOTOR_A1B, speed++);
    analogWrite(MOTOR_B1A, speed++);
    delay(10);
  }
  */
  // Right Wheel
  analogWrite(MOTOR_A1A, 0);
  //analogWrite(MOTOR_A1B, 255);
  // Left Wheel
  analogWrite(MOTOR_B1A, 255);
  analogWrite(MOTOR_B1B, 0);
  delay(100);
}

void go_forward() {
  Serial.println("Vamosssss");
  /*
  for (int speed = 0; speed < 255; speed++) {
    analogWrite(MOTOR_A1A, speed++);
    analogWrite(MOTOR_B1A, speed++);
    delay(10);
  }
  */
  // Right Wheel
  analogWrite(MOTOR_A1A, 255);
  analogWrite(MOTOR_A1B, 0);
  // Left Wheel
  analogWrite(MOTOR_B1A, 255);
  analogWrite(MOTOR_B1B, 0);
  delay(100);
}

void go_back() {
  Serial.println("Retreat");
  /*
  for (int speed = 0; speed < 255; speed++) {
    analogWrite(MOTOR_A1B, speed++);
    analogWrite(MOTOR_B1B, speed++);
    delay(10);
  }
  */
  // Right Wheel
  analogWrite(MOTOR_A1A, 0);
  analogWrite(MOTOR_A1B, 255);
  // Left Wheel
  analogWrite(MOTOR_B1A, 0);
  analogWrite(MOTOR_B1B, 255);
  delay(100);
}

void stay() {
    Serial.println("Stay");
    // Right Wheel
    analogWrite(MOTOR_A1A, 0);
    analogWrite(MOTOR_A1B, 0);

    // Left Wheel
    analogWrite(MOTOR_B1A, 0);
    analogWrite(MOTOR_B1B, 0);
    delay(100); 
}

void loop() {
  // put your main code here, to run repeatedly:
  joystick_x_1 = analogRead(JOY1_X);
  joystick_y_1 = analogRead(JOY1_Y);
  joystick_x_2 = analogRead(JOY2_X);
  joystick_y_2 = analogRead(JOY2_Y);
  button_1 = digitalRead(BUTTON_1);
  button_2 = digitalRead(BUTTON_2);

  if (joystick_x_1 > 800) { // Turn left
    turn_left();
  }  else if (joystick_x_1 < 300) { // Turn right
    turn_right();
  } else if (joystick_y_1 < 300) { // Go straight
    go_forward();
  } else if (joystick_y_1 > 700) { // Go back
    go_back();
  } else { // Stay
    stay();
  }

  if (button_1 == 0 || button_2 == 0){
    kick();
  }
}
