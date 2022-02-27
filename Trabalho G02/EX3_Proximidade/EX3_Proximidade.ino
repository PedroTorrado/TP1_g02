#define SIG A0      //defining pin A0 as SIG (sginal)
#define led_red 13
#define Buzzer A5

float distance;
char input = 'w'; //defining input as w (waiting) as default

void setup(){
  pinMode(SIG, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
}

int superSonicSensor(){
  //function to use value read by the sensor
  pinMode(SIG, OUTPUT);
  digitalWrite(SIG,LOW);
  delayMicroseconds(3);
  digitalWrite(SIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(SIG,LOW);

  pinMode(SIG, INPUT);
  float impulseDuration = pulseIn(SIG,HIGH);
  distance = (impulseDuration/29.4)/2;
  Serial.println(distance);

  return distance;
}

void loop(){

  int C4 = 262; //Dó 4
  int D4 = 294; //Ré
  int E4 = 330; //Mi
  int F4 = 349; //Fá
  int G4 = 392; //Sol
  int A4 = 440; //Lá
  int B4 = 494; //Si
  int C5 = 523; //Dó 5

  if(Serial.available() > 0){
  	input = Serial.read();
  	Serial.println(input);
  }

  //if input is w (waiting) the program does nothing and waits for a valid input
  if(input == 'w'){}

  //if user types R, LED and Buzzer turn on
  else if(input == 'R' or input == 'r'){

    digitalWrite(led_red, HIGH);

    distance = superSonicSensor();
    float max_distance_value = 330.71;
    float min_distance_value = 2.23;
    float range_distance_value = max_distance_value - min_distance_value;
    float interval = range_distance_value/8; //41.05125

    if(distance < min_distance_value + 1 * interval)){tone(Buzzer, C5);}
    else if(distance < (min_distance_value + 2 * interval)){tone(Buzzer, B4);}
    else if(distance < (min_distance_value + 3 * interval)){tone(Buzzer, A4);}
    else if(distance < (min_distance_value + 4 * interval)){tone(Buzzer, G4);}
    else if(distance < (min_distance_value + 5 * interval)){tone(Buzzer, F4);}
    else if(distance < (min_distance_value + 6 * interval)){tone(Buzzer, E4);}
    else if(distance < (min_distance_value + 7 * interval)){tone(Buzzer, D4);}
    else{tone(Buzzer, C4);}
  }

  //if user types D, LED and Buzzer turn off
  else if(input == 'D' or input == 'd'){
    digitalWrite(led_red, LOW);
    noTone(Buzzer);
  }

  //if the user input is not as intended it is informed and gets back to 'wait' state
  else{
    Serial.println("The input was not recognized.");
    Serial.println("Please use R or D to turn ON or OFF");
    input = 'w';
  }
}
