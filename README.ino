# BAMRoboCode
HS STEM 2023
___________________

int clear = 40;
int trig = 2;
int echo = 3;
long duration;
int distance; 
int potPin = A0;
int potVal = 0;
int spin180 = 425;
int speed1 = 100;
int speed2 = 90;
// define motor pins
#define ENA 6 // PWM pin for controlling speed of motor A
#define ENB 11 // PWM pin for controlling speed of motor B
#define IN1 9  // direction control pin 1 for motor A
#define IN2 8  // direction control pin 2 for motor A
#define IN3 10 // direction control pin 1 for motor B  
#define IN4 7  // direction control pin 2 for motor B 

 void setup () {
  Serial.begin(9600);
  // set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop () {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
   
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034/2;
  if(distance > clear){
    Forward();
  }
  else {
    Back();
    delay(500);
    Right();
    delay(325);
  }
    
  // Serial.print("Distance:");
  // Serial.println(distance);
  // delay(1000);
  

  
}
void Forward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed1);
  analogWrite(ENB, speed2);
}
void Back() {  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, speed1);
  analogWrite(ENB, speed2);
}

void Left() {
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed1);
  analogWrite(ENB, speed2);
}

void Right() { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed1);
  analogWrite(ENB, speed2);
}
  
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  }

