#include <Servo.h>

Servo head;
#define trigPin 26
#define echoPin 27
int duration, distance;
int minDistance = 50;
int rightDistance;
int leftDistance;
int frontDistance;

int enA = 3;
int in1 = 4;
int in2 = 5;
int enB = 9;
int in3 = 6;
int in4 = 7;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  head.attach(25);
  head.write(90);

  Serial.begin(9600); // Starts the serial communication
}

/*-------------- Setup Basic Movement functions --------------*/

void forward () {
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
}

void backward () {
  

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
  
}

void fullStop () {
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    
}

void right (){
            
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
}

void left (){
            
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 100);
    analogWrite(enB, 100);
}

/*-------------- Setup Avoidance functions --------------*/

void avoidRight (){
          head.write(90);
          right();
          delay(1000);
          forward();
}

void avoidLeft(){
          head.write(90);
          left();
          delay(1000);
          forward(); 
}

/*-------------- Setup Obstacle Detection functions --------------*/

void rightCheck (){
    fullStop();
    head.write(-180);
    delay(1000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("Right distance is: ");
    Serial.println(distance);
    rightDistance = distance;
}

void leftCheck (){
    fullStop();
    head.write(180);
    delay(1000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("Left distance is: ");
    Serial.println(distance);
    leftDistance = distance;
}

void frontCheck (){
    head.write(90);
    delay(1000);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.print("front distance is: ");
    Serial.println(distance);
    frontDistance = distance;
}
void loop() {
    frontCheck();
    if (frontDistance > minDistance) {
        forward();
    }
    else {
            fullStop();
            backward();
            delay (1000);
      
            rightCheck();
            leftCheck();
      
                  if (rightDistance > minDistance && rightDistance > leftDistance) {
                      avoidRight();
                  }
                  else if (leftDistance > minDistance && leftDistance > rightDistance) {
                    avoidLeft();
                  }
    }    
}
