// Motor Control Pins
const int motorLeftForward = 9;
const int motorLeftBackward = 10;
const int motorRightForward = 5;
const int motorRightBackward = 6;

// Line Sensor Pins
const int leftSensorPin = A0;
const int centerSensorPin = A1;
const int rightSensorPin = A2;

void setup() {
  // Set up motor pins
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);

  // Set up sensor pins
  pinMode(leftSensorPin, INPUT);
  pinMode(centerSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Read line sensor values
  int leftSensor = analogRead(leftSensorPin);
  int centerSensor = analogRead(centerSensorPin);
  int rightSensor = analogRead(rightSensorPin);

  // Define threshold for black/white detection
  int threshold = 500;

  Serial.print("Left: ");
  Serial.print(leftSensor);
  Serial.print(" Center: ");
  Serial.print(centerSensor);
  Serial.print(" Right: ");
  Serial.println(rightSensor);

  if (leftSensor < threshold && centerSensor >= threshold && rightSensor < threshold) {
    // Center sensor on black line -> Move Forward
    moveForward();
  } else if (leftSensor < threshold) {
    // Left sensor detects line -> Turn Left
    turnLeft();
  } else if (rightSensor < threshold) {
    // Right sensor detects line -> Turn Right
    turnRight();
  } else {
    // All sensors detect white -> Stop or map the boundary
    stopCar();
  }

  delay(100);
}

void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}

void stopCar() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}

