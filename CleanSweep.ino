int r_motor_n = 10; //PWM control Right Motor +
int r_motor_p = 11; //PWM control Right Motor -
int l_motor_p = 9; //PW
int l_motor_n = 6; //PWM control Left Motor +
int pump = 4;
int mop = 5;
int fan = 8;
int speedy = 255;
int incomingByte = 0; // for incoming serial data

void setup()
{
pinMode(r_motor_n, OUTPUT); //Set control pins to be outputs
pinMode(r_motor_p, OUTPUT);
pinMode(l_motor_p, OUTPUT);
pinMode(l_motor_n, OUTPUT);
pinMode(pump, OUTPUT);
pinMode(mop, OUTPUT);
pinMode(fan, OUTPUT);
digitalWrite(r_motor_n, LOW); //set both motors off for start-up
digitalWrite(r_motor_p, LOW);
digitalWrite(l_motor_p, LOW);
digitalWrite(l_motor_n, LOW);
digitalWrite(pump, LOW);
digitalWrite(mop, LOW);
digitalWrite(fan, LOW);
Serial.begin(9600);
}


void loop()
{

if (Serial.available() > 0) 
{
incomingByte = Serial.read();
}

switch(incomingByte)
{

case 'S': // control to stop the robot
digitalWrite(r_motor_n, LOW); 
digitalWrite(r_motor_p, LOW);
digitalWrite(l_motor_p, LOW);
digitalWrite(l_motor_n, LOW);
Serial.println("Stop");
incomingByte='*';
break;

case 'R': //control for right
analogWrite(r_motor_n, speedy); 
digitalWrite(r_motor_p, LOW);
analogWrite(l_motor_p, speedy);
digitalWrite(l_motor_n, LOW);
Serial.println("right");
incomingByte='*';
break;


case 'L': //control for left
digitalWrite(r_motor_n, LOW); 
analogWrite(r_motor_p, speedy);
digitalWrite(l_motor_p, LOW);
analogWrite(l_motor_n, speedy);
Serial.println("left");
incomingByte='*';
break;


case 'F': //control for forward
analogWrite(r_motor_n, speedy); 
digitalWrite(r_motor_p, LOW);
digitalWrite(l_motor_p, LOW);
analogWrite(l_motor_n, speedy);
Serial.println("forward");
incomingByte='*';
break;


case 'B': //control for backward
digitalWrite(r_motor_n, LOW); 
analogWrite(r_motor_p, speedy);
analogWrite(l_motor_p, speedy);
digitalWrite(l_motor_n, LOW);
Serial.println("back");
incomingByte='*';
break;


case 'P': // pump on
digitalWrite(pump, HIGH);
Serial.println("pump on");
incomingByte='*';
break;

case 'p': // pump off
digitalWrite(pump, LOW); 
Serial.println("pump off");
incomingByte='*';
break;

case 'M':
digitalWrite(mop, HIGH); // mopper on
Serial.println("mopper on");
incomingByte='*';
break;

case 'm':
digitalWrite(mop, LOW); // mopper off
Serial.println("mopper off");
incomingByte='*';
break;

case 'U': // fan on
digitalWrite(fan, HIGH);
Serial.println("fan on");
incomingByte='*';
break;

case 'u': // fan off
digitalWrite(fan, LOW);
Serial.println("fan off");
incomingByte='*';
break;


case '1':
speedy = 155;
Serial.println("speed= 10");
incomingByte='*';
break;

case '2':
speedy = 185;
Serial.println("speed= 25");
incomingByte='*';
break;

case '3':
speedy = 215;
Serial.println("speed= 75");
incomingByte='*';
break;

case '4':
speedy = 255;
Serial.println("speed= 100");
incomingByte='*';
break;

delay(5000);
}
}
