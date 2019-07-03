int app = 0;
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
  Serial.begin(9600);  
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

void loop() {

  if (Serial.available() > 0) {
     app = Serial.read();
     if (app == 'u'){
      forward();
     }
     if (app == 'd'){
      backward();
     }
     if (app == 'l'){
      left();
     }
     if (app == 'r'){
     right();
     }
     if (app == 's'){
      fullStop();
     }
     }
  }
