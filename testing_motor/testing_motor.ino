#define MOTOR_A1A 9
#define MOTOR_A1B 10

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_A1A, OUTPUT);
  pinMode(MOTOR_A1B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(MOTOR_A1A, 255);
  analogWrite(MOTOR_A1B, 0);
  delay(2000);

  // to stop
  analogWrite(MOTOR_A1A, 0);
  analogWrite(MOTOR_A1B, 0);
  delay(1000);
}
