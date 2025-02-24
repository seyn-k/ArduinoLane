// Motor driver pins
#define ENA 9
#define ENB 10
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 11

// Ultrasonic sensor pins
#define TRIG 3
#define ECHO 2

void setup() {
    // Motor driver pin setup
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
  
    // Ultrasonic sensor pin setup
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
  
    Serial.begin(9600);
}

void moveForward() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);  // Adjust speed (0-255)
    analogWrite(ENB, 150);
}

void moveBackward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
}

void turnLeft() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    delay(500);
}

void turnRight() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    delay(500);
}

void stopRobot() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

long measureDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long duration = pulseIn(ECHO, HIGH);
    return duration * 0.034 / 2; // Convert to cm
}

void loop() {
    long distance = measureDistance();
    Serial.println(distance);

    if (distance > 15) {
        moveForward();
    } else {
        stopRobot();
        delay(500);
        turnLeft();  // Try turning left
        delay(500);
    }
}
