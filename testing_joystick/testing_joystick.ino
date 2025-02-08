int variable;

#define JOY1_X A1
#define JOY1_Y A0
#define JOY2_X A2
#define JOY2_Y A3
#define BUTTON_1 2
#define BUTTON_2 4

#define SW 2

#define PI 3.14
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

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  joystick_x_1 = analogRead(JOY1_X);
  joystick_y_1 = analogRead(JOY1_Y);  //
  joystick_x_2 = analogRead(JOY2_X);
  joystick_y_2 = analogRead(JOY2_Y);  //
  button_1 = digitalRead(BUTTON_2);
  //delay(1000);

  if (button_1 == 0){
    button_counter +=1;
    delay(1000);
  }
  if (button_counter % 4 == 0){
    Serial.print("side movement right: ");
    Serial.println(joystick_x_1);
  }
  else if (button_counter % 4 == 1){
    Serial.print("up movement right: ");
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
  //Serial.end();
}
