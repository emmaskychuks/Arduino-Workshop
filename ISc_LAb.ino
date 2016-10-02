#define M1_F 1  // Names digital pin #1 on the Arduino board as M1, If High, and m1_r LOW, motor goes forward.
#define M1_R 2   // Names digital pin #2  on the Arduino board as M2
#define M2_F 5  // Names digital pin #5 on the Arduino board as M1
#define M2_R 6   // Names digital pin #6 on the Arduino board as M2
#define x 13
#define  y 0
int stateX = digitalRead(x);
int greatY = digitalRead(x);
void setup() 
{
 pinMode(M1_F, OUTPUT);
 pinMode(M1_R, OUTPUT);
 pinMode(M2_F, OUTPUT);
 pinMode(M2_R, OUTPUT);
 
}

void loop() 
{
  if((stateX == HIGH)&&(greatY==LOW))
  {
  digitalWrite(M1_F, HIGH); //
  digitalWrite(M1_R, LOW);
  digitalWrite(M2_F, HIGH); //
  digitalWrite(M2_R, LOW);
  }
  else if ((stateX == LOW)&&(greatY== HIGH))
  {
   digitalWrite(M1_F, HIGH);
  digitalWrite(M1_R, LOW);
  digitalWrite(M2_F, LOW); //
  digitalWrite(M2_R, HIGH);
  }
  else
  {
  digitalWrite(M1_F, LOW); //
  digitalWrite(M1_R, HIGH);
  digitalWrite(M2_F, HIGH); //
  digitalWrite(M2_R, LOW);
    
  }
}
 
