#define IR_SENSOR_R1 13
#define IR_SENSOR_R2 12
#define IR_SENSOR_M 11
#define IR_SENSOR_L2 10
#define IR_SENSOR_L1 9
#define MOTOR_SPEED 80

//right motor
int enableRightMotor=3;
int rightMotorPin1=4;
int rightMotorPin2=2;

//left motor
int enableLeftMotor=5;
int leftMotorPin1=8;
int leftMotorPin2=7;



void setup()
{
   

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_R1, INPUT);
  pinMode(IR_SENSOR_R2, INPUT);
  pinMode(IR_SENSOR_M, INPUT);
  pinMode(IR_SENSOR_L1, INPUT);
  pinMode(IR_SENSOR_L2, INPUT);
  
  rotateMotor(0,0); 
}

void loop()
{

  int R1IRSensorValue = digitalRead(IR_SENSOR_R1);
  int R2IRSensorValue = digitalRead(IR_SENSOR_R2);
  int MIRSensorValue = digitalRead(IR_SENSOR_M);
  int L1IRSensorValue = digitalRead(IR_SENSOR_L1);
  int L2IRSensorValue = digitalRead(IR_SENSOR_L2);

  //If none of the sensors detects black line, then go straight
  if 
  (
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && MIRSensorValue == HIGH && L1IRSensorValue == HIGH && L2IRSensorValue == HIGH || 
    MIRSensorValue == LOW && R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L1IRSensorValue == HIGH && L2IRSensorValue == HIGH
  )
  
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  
  //If right sensor detects black line, then turn right
  else if 
  (
    R1IRSensorValue == LOW && R2IRSensorValue == HIGH && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == HIGH||
    R1IRSensorValue == HIGH && R2IRSensorValue == LOW && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == HIGH ||
    R1IRSensorValue == LOW && R2IRSensorValue == LOW && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == HIGH ||
    R1IRSensorValue == LOW && R2IRSensorValue == LOW && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == LOW ||
    R1IRSensorValue == HIGH && R2IRSensorValue == LOW && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == HIGH ||
    R1IRSensorValue == LOW && R2IRSensorValue == HIGH && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == LOW ||
    R1IRSensorValue == HIGH && R2IRSensorValue == LOW && L2IRSensorValue == HIGH && L1IRSensorValue == HIGH && MIRSensorValue == LOW 
  )
  
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
  }
  //If left sensor detects black line, then turn left  
  else if 
  (
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == LOW && L1IRSensorValue == HIGH && MIRSensorValue == HIGH ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == HIGH && L1IRSensorValue == LOW && MIRSensorValue == HIGH ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == LOW && L1IRSensorValue == LOW && MIRSensorValue == HIGH  ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == LOW && L1IRSensorValue == LOW && MIRSensorValue == LOW ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == LOW && L1IRSensorValue == HIGH && MIRSensorValue == HIGH ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == HIGH && L1IRSensorValue == LOW && MIRSensorValue == LOW ||
    R1IRSensorValue == HIGH && R2IRSensorValue == HIGH && L2IRSensorValue == LOW && L1IRSensorValue == HIGH && MIRSensorValue == LOW
  )
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0,0);
  }
}

void rotateMotor(int rightMotorSpeed,int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));    
}
