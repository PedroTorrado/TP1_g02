#define led_green 13
#define led_red 12
#define TMP A1
#define Buzz A2

void setup(){  
  pinMode(led_green, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(Buzz, OUTPUT);
  pinMode(TMP, INPUT);
  Serial.begin(9600);
}

void loop(){
  float tmp = analogRead(TMP);
  tmp = (tmp/1024)*5000;
  tmp = (tmp - 500)/10;
  
  if(tmp>40){
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
    Serial.print("Temperatura: ");
    Serial.println(tmp);
    delay(500);
    digitalWrite(Buzz, HIGH);
  }
  
  else{
    digitalWrite(led_green, HIGH); 
    digitalWrite(led_red, LOW);
    digitalWrite(Buzz, LOW);
  }
}