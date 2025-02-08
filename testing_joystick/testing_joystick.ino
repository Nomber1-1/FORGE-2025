int variable;

#define JOYX A0
#define JOYY A1
#define SW 2

#define PI 3.14
int x = 100;
int y;

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
  pinMode(JOYX,INPUT);
  pinMode(JOYY,INPUT);
  pinMode(SW,INPUT_PULLUP);//designed high so when pressed is 0
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int joystick_x = analogRead(JOYX);
  int joystick_y = analogRead(JOYY); //
  //delay(1000);

  if (x > 1) {
    // if true !!!!
    Serial.println(" is bigger than 1");
    Serial.println(x);
    x = x - 1;
  } else if (x == 1) {
    Serial.println("One left");
    Serial.println(x);
    x = x - 1;
  } else {
    Serial.println("And done");
    Serial.end();
  }
}
