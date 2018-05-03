// motor one
int enA = 2;
int in1 = 3;
int in2 = 4;
// motor two
int enB = 7;
int in3 = 5;
int in4 = 6;
//motor three
int enA_2 = 8;
int in1_2 = 9;
int in2_2 = 10;
// motor four
int enB_2 = 13;
int in3_2 = 11;
int in4_2 = 12;
void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA_2, OUTPUT);
  pinMode(enB_2, OUTPUT);
  pinMode(in1_2, OUTPUT);
  pinMode(in2_2, OUTPUT);
  pinMode(in3_2, OUTPUT);
  pinMode(in4_2, OUTPUT);
}
void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  //forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in1_2, HIGH);
  digitalWrite(in2_2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  analogWrite(enA_2, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in3_2, HIGH);
  digitalWrite(in4_2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  analogWrite(enB_2, 200);
  delay(2000);
  //backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  digitalWrite(in1_2, LOW);
  digitalWrite(in2_2, HIGH);  
  digitalWrite(in3_2, LOW);
  digitalWrite(in4_2, HIGH); 
  delay(2000);
//right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  
  digitalWrite(in1_2, HIGH);
  digitalWrite(in2_2, LOW);  
  
  digitalWrite(in3_2, LOW);
  digitalWrite(in4_2, HIGH); 
  
  delay(2000);
//left
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  
  digitalWrite(in1_2, LOW);
  digitalWrite(in2_2, HIGH);  
  
  digitalWrite(in3_2, HIGH);
  digitalWrite(in4_2, LOW); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in1_2, LOW);
  digitalWrite(in2_2, LOW);  
  digitalWrite(in3_2, LOW);
  digitalWrite(in4_2, LOW);

  delay(2000);
}
void demoTwo()
{
  //turn right
digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  analogWrite(enA_2, 255);
 
  digitalWrite(in1_2, LOW);
  digitalWrite(in2_2, HIGH);
  digitalWrite(in3_2, LOW);
  digitalWrite(in4_2, HIGH);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);
  analogWrite(enB_2, 255);
  delay(5000);
  
  //turn left
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  digitalWrite(in1_2, HIGH);
  digitalWrite(in2_2, LOW);  
  digitalWrite(in3_2, HIGH);
  digitalWrite(in4_2, LOW); 
  
  delay(5000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in1_2, LOW);
  digitalWrite(in2_2, LOW);  
  digitalWrite(in3_2, LOW);
  digitalWrite(in4_2, LOW);
  delay(2000);  
}
void loop()
{
 // demoOne();
  //delay(1000);
  demoTwo();
  //delay(1000);
}
