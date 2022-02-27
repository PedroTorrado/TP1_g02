// C++ code
//
#define led_red 13
#define PIS A5 //Passive infrared sensor
int val = 0;
void setup()
{
  Serial.begin(9300);
  pinMode(led_red, OUTPUT);
  pinMode(PIS, INPUT);
}

void loop()
{
  val= analogRead(PIS);
  Serial.println(val);
  
  if(val==1018){
  digitalWrite(led_red, HIGH);
  }
  else{
  digitalWrite(led_red, LOW);
  }
}
