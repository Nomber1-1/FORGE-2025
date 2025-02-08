int variable;

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

int x = 100;
int y;
int button_counter = 0;
int joystick_x_1;
int joystick_y_1;
int joystick_x_2;
int joystick_y_2;
int button_1;

int readJoystick() {
  int x;
  // reading things from the joystick
  return x;
}

void goForward(int speed) {
  //analogWrite(MOTOR, speed);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(JOY1_X, INPUT);
  pinMode(JOY1_Y, INPUT);
  pinMode(JOY2_X, INPUT);
  pinMode(JOY2_Y, INPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);  //active high so when pressed is 0
  pinMode(BUTTON_2, INPUT_PULLUP);  //active high so when pressed is 0
  
  // Right Wheel
  pinMode(MOTOR_A1A, OUTPUT);
  pinMode(MOTOR_A1B, OUTPUT);

  // Left Wheel
  pinMode(MOTOR_B1A, OUTPUT);
  pinMode(MOTOR_B1B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystick_x_1 = analogRead(JOY1_X);
  joystick_y_1 = analogRead(JOY1_Y);  //
  joystick_x_2 = analogRead(JOY2_X);
  joystick_y_2 = analogRead(JOY2_Y);  //
  button_1 = digitalRead(BUTTON_2);

  /*
  if (button_1 == 0){
    button_counter +=1;
    delay(1000);
  }
  */

  if (joystick_x_1 > 800) { // Turn left
    Serial.println("Turn left");

    for (int speed = 0; speed < 255; speed++) {
      analogWrite(MOTOR_A1A, speed++);
      analogWrite(MOTOR_B1B, speed++);
    }
    // Right Wheel
    //analogWrite(MOTOR_A1A, 255);
    analogWrite(MOTOR_A1B, 0);

    // Left Wheel
    analogWrite(MOTOR_B1A, 0);
    //analogWrite(MOTOR_B1B, 255);
    delay(100);
  }  else if (joystick_x_1 < 300) { // Turn right
    Serial.println("Turn right");

    for (int speed = 0; speed < 255; speed++) {
      analogWrite(MOTOR_A1B, speed++);
      analogWrite(MOTOR_B1A, speed++);
    }
    // Right Wheel
    analogWrite(MOTOR_A1A, 0);
    //analogWrite(MOTOR_A1B, 255);

    // Left Wheel
    //analogWrite(MOTOR_B1A, 255);
    analogWrite(MOTOR_B1B, 0);
    delay(100);
  } else if (joystick_y_1 < 300) { // Go straight
    Serial.println("Vamosssss");

    
    // Right Wheel
    analogWrite(MOTOR_A1A, 255);
    analogWrite(MOTOR_A1B, 0);

    // Left Wheel
    analogWrite(MOTOR_B1A, 255);
    analogWrite(MOTOR_B1B, 0);
    delay(100);
  } else if (joystick_y_1 > 700) { // Go back
    Serial.println("Retreat");
    // Right Wheel
    analogWrite(MOTOR_A1A, 0);
    analogWrite(MOTOR_A1B, 255);

    // Left Wheel
    analogWrite(MOTOR_B1A, 0);
    analogWrite(MOTOR_B1B, 255);
    delay(100);
  } else { // Stay
    Serial.println("Stay");
    // Right Wheel
    analogWrite(MOTOR_A1A, 0);
    analogWrite(MOTOR_A1B, 0);

    // Left Wheel
    analogWrite(MOTOR_B1A, 0);
    analogWrite(MOTOR_B1B, 0);
    delay(100); 
  }
  /*
  if (button_counter % 4 == 0){
    Serial.print("side movement right: "); // 0 = right / 1023 = left
    Serial.println(joystick_x_1);

  }
  else if (button_counter % 4 == 1){
    Serial.print("up movement right: "); // 0 = up / 1023 = down
    Serial.println(joystick_y_1);

  }
  else if (button_counter % 4 == 2){
    Serial.print("side movement left: ");
    Serial.println(joystick_x_2);
  }
  else {
    Serial.print("up movement left: ");
    Serial.println(joystick_y_2);
  }
  */
}
