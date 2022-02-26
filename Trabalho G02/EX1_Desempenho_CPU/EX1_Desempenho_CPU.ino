// C++ code
//
#define led_green_1 13   //Led Green 1
#define led_white_1 12
#define led_red_1 11

#define led_green_2 10
#define led_white_2 9
#define led_red_2 8

int SEQ(){
  digitalWrite(led_green_1, LOW);
  digitalWrite(led_white_1, LOW);
  digitalWrite(led_red_1, LOW);

  digitalWrite(led_green_2, LOW);
  digitalWrite(led_white_2, LOW);
  digitalWrite(led_red_2, LOW);

  digitalWrite(led_green_1, HIGH);
  delay(1000);
  digitalWrite(led_white_1, HIGH);
  delay(1000);
  digitalWrite(led_red_1, HIGH);
  delay(1000);

  digitalWrite(led_green_2, HIGH);
  delay(1000);
  digitalWrite(led_white_2, HIGH);
  delay(1000);
  digitalWrite(led_red_2, HIGH);
  delay(1000);

  digitalWrite(led_green_1, LOW);
  digitalWrite(led_white_1, LOW);
  digitalWrite(led_red_1, LOW);

  digitalWrite(led_green_2, LOW);
  digitalWrite(led_white_2, LOW);
  digitalWrite(led_red_2, LOW);
}

void setup()
{
  pinMode(led_green_1, OUTPUT);
  pinMode(led_white_1, OUTPUT);
  pinMode(led_red_1, OUTPUT);

  pinMode(led_green_2, OUTPUT);
  pinMode(led_white_2, OUTPUT);
  pinMode(Led_red_2, OUTPUT);

  SEQ();
}

void loop(){}
