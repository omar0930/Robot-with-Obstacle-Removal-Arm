#include <AFMotor.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver srituhobby = Adafruit_PWMServoDriver();
//defining pins and variables
#define left A2
#define right A3
#define trigPin A1 // TRIG pin
#define echoPin A0 // ECHO pin
#define servo1 0
#define servo2 1
#define servo3 2
#define servo4 3
float duration_us, distance_cm;
//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
void setup() {
 // begin serial port
 Serial.begin (9600);
 // configure the trigger pin to output mode
 pinMode(trigPin, OUTPUT);
 // configure the echo pin to input mode
pinMode(echoPin, INPUT);
 //declaring pin types
 pinMode(left,INPUT);
 pinMode(right,INPUT);
 srituhobby.begin();
 srituhobby.setPWMFreq(60);
 srituhobby.setPWM(servo1, 0, 340);
 srituhobby.setPWM(servo2, 0, 150);
 srituhobby.setPWM(servo3, 0, 300);
 srituhobby.setPWM(servo4, 0, 290);
 
}
void loop(){
 // generate 10-microsecond pulse to TRIG pin
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // measure duration of pulse from ECHO pin
 duration_us = pulseIn(echoPin, HIGH);
 // calculate the distance
 distance_cm = 0.017 * duration_us;
 // print the value to Serial Monitor
 Serial.print("distance: ");
 Serial.print(distance_cm);
 Serial.println(" cm");
 
 if(distance_cm <= 10.00){
 motor1.run(RELEASE);
 motor1.setSpeed(0);
 motor2.run(RELEASE);
 motor2.setSpeed(0);
 motor3.run(RELEASE);
 motor3.setSpeed(0);
 motor4.run(RELEASE);
 motor4.setSpeed(0);
 delay(1000);
 robotArm();
 }
 else{
 //printing values of the sensors to the serial monitor
 Serial.println(digitalRead(left));
 
 Serial.println(digitalRead(right));
 //line detected by both
 if(digitalRead(left)==0 && digitalRead(right)==0){
 //Forward
 motor1.run(FORWARD);
 motor1.setSpeed(120);
 motor2.run(FORWARD);
 motor2.setSpeed(120);
 motor3.run(FORWARD);
 motor3.setSpeed(120);
 motor4.run(FORWARD);
 motor4.setSpeed(120);
 }
//line detected by left sensor
 else if(digitalRead(left)==0 && !analogRead(right)==0){
 //turn left
 motor1.run(FORWARD);
 motor1.setSpeed(140);
 motor2.run(FORWARD);
 motor2.setSpeed(140);
 motor3.run(BACKWARD);
 motor3.setSpeed(140);
 motor4.run(BACKWARD);
 motor4.setSpeed(140);
 
 }
 //line detected by right sensor
 else if(!digitalRead(left)==0 && digitalRead(right)==0){
 //turn right
 motor1.run(BACKWARD);
 motor1.setSpeed(140);
 motor2.run(BACKWARD);
 motor2.setSpeed(140);
 motor3.run(FORWARD);
 motor3.setSpeed(140);
motor4.run(FORWARD);
 motor4.setSpeed(140);
 
 }
 //line detected by none
 else if(!digitalRead(left)==0 && !digitalRead(right)==0){
 //stop
 motor1.run(RELEASE);
 motor1.setSpeed(0);
 motor2.run(RELEASE);
 motor2.setSpeed(0);
 motor3.run(RELEASE);
 motor3.setSpeed(0);
 motor4.run(RELEASE);
 motor4.setSpeed(0);
 
 }
 }
 
 
}
void robotArm() {
 for (int S4value = 290; S4value <= 490; S4value++) {
 srituhobby.setPWM(servo4, 0, S4value);
 delay(10);
 }
 for (int S3value = 300; S3value <= 450; S3value++) {
 srituhobby.setPWM(servo3, 0, S3value);
 delay(10);
 }
for (int S2value = 150; S2value <= 190; S2value++) {
 srituhobby.setPWM(servo2, 0, S2value);
 delay(10);
 }
 for (int S4value = 490; S4value > 290; S4value--) {
 srituhobby.setPWM(servo4, 0, S4value);
 delay(10);
 }
 for (int S3value = 450; S3value > 300; S3value--) {
 srituhobby.setPWM(servo3, 0, S3value);
 delay(10);
 }
 for (int S2value = 190; S2value <= 320; S2value++) {
 srituhobby.setPWM(servo2, 0, S2value);
 delay(10);
 }
 for (int S1value = 340; S1value >= 150; S1value--) {
 srituhobby.setPWM(servo1, 0, S1value);
 delay(10);
 }
 for (int S3value = 300; S3value <= 410; S3value++) {
 srituhobby.setPWM(servo3, 0, S3value);
 delay(10);
 }
 for (int S4value = 290; S4value <= 490; S4value++) {
 srituhobby.setPWM(servo4, 0, S4value);
 delay(10);
 }
 for (int S4value = 490; S4value > 290; S4value--) {
 srituhobby.setPWM(servo4, 0, S4value);
 delay(10);
 }
 for (int S3value = 410; S3value > 300; S3value--) {
 srituhobby.setPWM(servo3, 0, S3value);
 delay(10);
 }
 for (int S2value = 320; S2value > 150; S2value--) {
 srituhobby.setPWM(servo2, 0, S2value);
 delay(10);
 }
 for (int S1value = 150; S1value < 340; S1value++) {
 srituhobby.setPWM(servo1, 0, S1value);
 delay(10);
 }
}

