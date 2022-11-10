 const int ldrPin1 = A2;// ldr1 is connected A2 pin
const int ldrPin2 = A1;// ldr2 is connected A1 pin
const int enA=9;// L298 motar driver enA is connected D9 pin
const int enB=10;//L298 motar driver enB is connected D10 pin
const int in1=5;//L298 motar driver in1 is connected  D5 pin
const int in2=6;//L298 motar driver in2 is connected  D6 pin  
const int in3=7;// L298 motar driver in3 is connected D7 pin
const int in4=8 ;//L298 motar driver in4 is connected D8 pin
int ldrs1=0;
int ldrs2=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT); 
  pinMode(in3,OUTPUT); 
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(ldrPin1,INPUT);
              pinMode(ldrPin2,INPUT);
              Serial.begin(9600);
           }

void loop() 
{
  // put your main code here, to run repeatedly:
 ldrs1=analogRead(ldrPin1);
ldrs2=analogRead(ldrPin2);
Serial.println("ldrstatus1");
Serial.println(ldrs1);
Serial.println("ldrstatus2");
Serial.println(ldrs2);
if (ldrs1<=200 && ldrs2<=200 )// if light intensity is low then car move forward with high speed
{
  analogWrite(enA,200);
  analogWrite(enB,200);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("1000 & 1000 ");
}






else if(ldrs1<=300 && ldrs2<=300)//if light intensity is medium and same intensity on both sides, then car will go slow                                              sensor then car is forword
{
  analogWrite(enA,100);
  analogWrite(enB,100);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("300 & 300 ");
  
}
else if(ldrs1<=300 && ldrs2<=800)// if light intensity one side more then car turn in low intensity direction
{
  analogWrite(enA,150);
  analogWrite(enB,150);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("800 & 300 ");
}




else if(ldrs1<=800 && ldrs2<=300) //if light intensity one side more then car turn in low intencity direction
{
  analogWrite(enA,150);
  analogWrite(enB,150);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  Serial.println("300 & 800 ");
}
else if(ldrs1<=1000 && ldrs2<=1000) // if light intensity is high and same as both sensore then car will stop
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  Serial.println("100 & 100 ");
}
delay(10);
}
