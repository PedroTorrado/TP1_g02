// C++ code
//
#define G1 13 //Led Green 1
#define W1 12
#define R1 11

#define G2 10
#define W2 9
#define R2 8

int SEQ(){
  digitalWrite(G1, LOW);
  digitalWrite(W1, LOW);
  digitalWrite(R1, LOW);

  digitalWrite(G2, LOW);
  digitalWrite(W2, LOW);
  digitalWrite(R2, LOW);

  digitalWrite(G1, HIGH);
  delay(1000);
  digitalWrite(W1, HIGH);
  delay(1000);
  digitalWrite(R1, HIGH);
  delay(1000);

  digitalWrite(G2, HIGH);
  delay(1000);
  digitalWrite(W2, HIGH);
  delay(1000);
  digitalWrite(R2, HIGH);
  delay(1000);

  digitalWrite(G1, LOW);
  digitalWrite(W1, LOW);
  digitalWrite(R1, LOW);

  digitalWrite(G2, LOW);
  digitalWrite(W2, LOW);
  digitalWrite(R2, LOW);
}

void setup()
{
  pinMode(G1, OUTPUT);
  pinMode(W1, OUTPUT);
  pinMode(R1, OUTPUT);

  pinMode(G2, OUTPUT);
  pinMode(W2, OUTPUT);
  pinMode(R2, OUTPUT);

  SEQ();

}

void loop()
{
 
}
