#include <Servo.h>
int pos=0;
int pos1;
#define uint8 unsigned char //used to indicate the state of button4 key
uint8 b1state = 0;
#define button1 8 //the number of the button 1
Servo servo_9;
int lightCal;
int lightVal;
int LDR = A0;
float temp;
int tempPin = A1;
const int trigPin = 2;
const int echoPin = 3;
const int trigPin1 = 4;
const int echoPin1 = 5;
const int trigPin2 = 6;
const int echoPin2 = 7;
const int trigPin3 = 11;
const int echoPin3 = 12;
// defines variables
long A,B,C,D,E,F,H,area,volume,L,Bre;
void setup()
{
pinMode(LDR, INPUT);
pinMode(tempPin, INPUT);
servo_9.attach(9);
digitalWrite(9,LOW);
pinMode(button1,INPUT_PULLUP);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT);// Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
servo_9.write(pos);
b1state = digitalRead(button1);
if(b1state == 0) ////////////////////////////////pushbutton///////////////////////////////////////////
{
ldr();
temprature();
length();
breath();
ultrasonic1();
ultrasonic2();
delay(500);
hight();
ultrasonic3();
ultrasonic4();
delay(500);
area = Bre*L;
Serial.print("area =");
Serial.println(area);
volume = area * H;
Serial.print("volume= ");
Serial.println(volume);
}
}
void length(){
servo_9.write(pos);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
A = pulseIn(echoPin, HIGH);
// Calculating the distance
A = A*0.034/2;
delay(1000);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
B = pulseIn(echoPin1, HIGH);
// Calculating the distance
B = B*0.034/2;
// Prints the distance on the Serial Monitor
delay(1000);
L = A+B;
Serial.print("length = ");
Serial.print(L);
Serial.println();
delay(2000);
}
void breath(){
pos1=pos+90;
servo_9.write(pos1);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
C = pulseIn(echoPin, HIGH);
// Calculating the distance
C = C*0.034/2;
delay(1000);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
D = pulseIn(echoPin1, HIGH);
// Calculating the distance
D = D*0.034/2;
// Prints the distance on the Serial Monitor
delay(1000);
Bre = C+D;
Serial.print("breath = ");
Serial.print(Bre);
Serial.println();
delay(2000);
}
void hight()
{
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
E = pulseIn(echoPin2, HIGH);
// Calculating the distance
E = E*0.034/2;
// Prints the distance on the Serial Monitor
delay(1000);
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
F = pulseIn(echoPin3, HIGH);
// Calculating the distance
F = F*0.034/2;
// Prints the distance on the Serial Monitor
delay(1000);
H = F+E;
Serial.print("hight= ");
Serial.print(H);
Serial.println();
delay(500);
}
void ultrasonic1(){
digitalWrite(trigPin, LOW);
digitalWrite(echoPin, LOW);
}
void ultrasonic2(){
digitalWrite(trigPin1, LOW);
digitalWrite(echoPin1, LOW);
}
void ultrasonic3(){
digitalWrite(trigPin2, LOW);
digitalWrite(echoPin2, LOW);
}
void ultrasonic4(){
digitalWrite(trigPin3, LOW);
digitalWrite(echoPin3, LOW);
}
void ldr(){
// on sensor pin and store it in lightVal
lightVal = analogRead(LDR);
if(lightVal>=526)
{
Serial.print("its bright outside");
}
else
{
Serial.print("its dark outside");
}
delay(500);
}
void temprature()
{
temp = analogRead(tempPin);
// read analog volt from sensor and save to variable temp
temp = temp * 0.48828125;
temp=temp-50;
Serial.println();// convert the analog volt to its temperature equivalent
Serial.print("TEMPERATURE = ");
Serial.print(temp);// display temperature value
Serial.print("*C");
Serial.println();
delay(500);
}