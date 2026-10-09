#include <Servo.h>
#include <LedControl.h>

LedControl matrix = LedControl(12, 10, 11, 1);
Servo rightLeft;

int ServoPin = 9;
int Trig = 2;
int Echo = 3;

const int MAX_DISTANCE_CM = 40;

long readDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long duration = pulseIn(Echo, HIGH, 25000);
  if (duration == 0) return 999;

  return duration * 0.0343 / 2;
}

void maS(int angle) {
  rightLeft.write(angle);
  delay(20);

  long distance = readDistance();

  Serial.print("Winkel: ");
  Serial.print(angle);
  Serial.print(" | Distanz: ");
  Serial.println(distance);

  matrix.clearDisplay(0);

  int col = map(angle, 0, 180, 0, 7);

  if (distance > 0 && distance <= MAX_DISTANCE_CM) {
    int col = map(angle, 0, 180, 0, 7);
    int objectRow = map(distance, 1, MAX_DISTANCE_CM, 7, 0);
    matrix.setLed(0, objectRow, col, true);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  rightLeft.attach(ServoPin);

  matrix.shutdown(0, false);
  matrix.setIntensity(0, 2);
  matrix.clearDisplay(0);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 2) {
    maS(pos);
  }

  for (int pos = 180; pos >= 0; pos -= 2) {
    maS(pos);
  }
}