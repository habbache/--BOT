#include <Servo.h>

Servo head;

void setup()
{
  head.attach(25);
  head.write(90);
}

void loop() {
  
}
