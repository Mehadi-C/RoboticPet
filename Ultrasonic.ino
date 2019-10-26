int pin = 10; // connected to the Trig on the module, this serves as both Trigger and Echo
#define sensor A0
#include <Servo.h>
#include <AFMotor.h>;

Servo ultra;
AF_DCMotor leftmotor(3), rightmotor(4);

const int trigPin = 46;
const int echoPin = 48;
long duration;
int distance;

int i;
void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  digitalWrite(pin, HIGH); // Trig pin is normally HIGH

  // turn on motor
  leftmotor.setSpeed(255);
  rightmotor.setSpeed(255);
 
  leftmotor.run(RELEASE);
  rightmotor.run(RELEASE);
  
  ultra.attach(9);
}

//float distance(int pin)
//{
//  unsigned long time;
//  unsigned long sizeofpulse;
//  float range;
//
//  pinMode(pin, OUTPUT); //return digital pin to OUTPUT mode after reading
//  digitalWrite(pin, LOW);
//  delayMicroseconds(25);
//  digitalWrite(pin, HIGH); //Trig pin pulsed LOW for 25usec
//  time = micros(); //record timer
//  pinMode(pin, INPUT); //change pin to INPUT to read the echo pulse 
//  sizeofpulse = pulseIn(pin, LOW, 18000); //should be approx 150usec, timeout at 18msec
//  time = micros() - time - sizeofpulse; // amount of time elapsed since we sent the trigger pulse and detect the echo pulse, then subtract the size of the echo pulse
//  range = (time*340.29/2/10000)-3; // convert to distance in centimeters
//  return range;
//}

void loop()
{
//  forward();
//  delay(1000);
  
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance= duration*0.034/2;
    
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    if( distance <= 10.0 )
  {
//    stops();
//    delay(180);
//    ultra.write(180);
//    delay(180);
//    delay(180);
//    ultra.write(0);
//    delay(180);
//    delay(1000);

Serial.println("Hello");
    // Clears the trigPin
//    digitalWrite(trigPin, LOW);
//    delayMicroseconds(2);
//    
//    // Sets the trigPin on HIGH state for 10 micro seconds
//    digitalWrite(trigPin, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(trigPin, LOW);
//    
//    // Reads the echoPin, returns the sound wave travel time in microseconds
//    duration = pulseIn(echoPin, HIGH);
//    
//    // Calculating the distance
//    distance= duration*0.034/2;
  }
  
}

void forward()
{
   rightmotor.run(FORWARD);
   leftmotor.run(FORWARD);
   rightmotor.setSpeed(255);
   leftmotor.setSpeed(255);
   delay(10000);
}

void backwards()
{
   rightmotor.run(BACKWARD);
   leftmotor.run(BACKWARD);
    rightmotor.setSpeed(100); 
    leftmotor.setSpeed(100); 
    delay(10);
 
  for (i=255; i!=0; i--) {
    rightmotor.setSpeed(i);  
    leftmotor.setSpeed(i);
    delay(10);
 }
}

void stops()
{
  Serial.print("tech");
  leftmotor.run(RELEASE);
  rightmotor.run(RELEASE);
}
