# TP1_G02
---
## Introdução

Este trabalho tem como onjetivo, aprofundar o nosso conhecimento em programação em C++ e em Arduino.

Foi pedida a realização de 3 exercícios:

---
<strong>EX1 Desempenho CPU</strong>

Utilizando Leds criar uma sequência que liga apenas uma vez cada Led.

---
<strong>EX2 Sensor de Temperatura</strong>

Demonstrar o funcionamento de um sensor de temperatura (TMP36), utilizando o serial monitor para apresntar os resultados e Leds para demonstrar se o valor se encontra abaixo ou acima de certo limite.

---
<strong>EX3 Proximidade</strong>

Utilizando um sensor de proximidade (Sensor Ultrasonico) e um Piezo Buzzer, demonstrar o seu funcionamento, utilizando o serial monitor para introduzir os comandos necessários.

---

# EX1 Desempenho CPU
## Circuito

<img src="https://github.com/Cordelios810/TP1_g02/blob/main/Trabalho%20G02/EX1_Desempenho_CPU/Circuito_EX1.png" width="400"/>

| Componente    | Pin Digital |
| :---          |    :---:    |
| LED1 Verde    |      13     |
| LED2 Branco   |      12     |
| LED3 Vermelho |      11     |
| LED4 Verde    |      10     |
| LED5 Branco   |      9      |
| LED6 Vermelho |      8      |

## Código

```C++
#define led_green_1 13   //Led Green 1
#define led_white_1 12
#define led_red_1 11

#define led_green_2 10
#define led_white_2 9
#define led_red_2 8
```

Definir cada pin para o seu respetivo componente de forma a que mais tarde possamos referir aos componentes diretamente e não apenas aos pin que estão connectados, como no exemplo:

```C++
digitalWrite(led_green_1, HIGH);
digitalWrite(13, HIGH);
```

Ambas as linhas fazem o mesmo, contudo, o segundo é mais fácil de entender tanto enquanto está a ser escrito como quando está a ser revisto.
E muito resumidamente o que qualquer uma dessas duas linhas de código faz, é a base daquilo que é este programa.

```C++
digitalWrite(led_green_1, HIGH);
```

Define o pin em questão (neste caso led_green_1 e respetivamente o pin 13), como "*HIGH*", ou seja como ligado (5V).

```C++
digitalWrite(led_green_1, LOW);
```

Define esse mesmo pin como desligado (0V) ou "*LOW*".

```C++
digitalWrite(led_green_1, LOW);   // Turn off all pins
digitalWrite(led_white_1, LOW);
digitalWrite(led_red_1, LOW);

digitalWrite(led_green_2, LOW);
digitalWrite(led_white_2, LOW);
digitalWrite(led_red_2, LOW);
```

O bloco acima desliga todos os pins de forma a termos a certeza que estes se encontram desligados quando o programa começa e possamos assim ligá-los por ordem. Utilizando este após o próximo bloco de código faz também com que todos os Leds se voltem a desligar, como pretendido.

```C++
digitalWrite(led_green_1, HIGH);  // Turns pins on one by one
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
```

O bloco acima liga cada um dos pins com um segundo de pausa entre cada pela seguinte ordem:

1. Led Verde 1
2. Led Branco 1
3. Led Vermelho 1
4. Led Verde 2
5. Led Branco 2
6. Led Vermelho 2


Sendo que tudo o que a função delay() faz é parar o programa durante x tempo em milisegundos, é esta função que faz com que haja um delay entre cada pin a ser ligado.

De forma a poder tornar a ação criada mais simples e repetível esta foi criada dentro de uma nova função "*SEQ( )*" e de forma a que esta não se repita e apenas execute a ação pretendida uma vez, esta foi colocada dentro da função "*setup( )*".

---

# EX2 Sensor de Temperatura
## Circuito
<img src="https://github.com/PedroTorrado/TP1_g02/blob/main/Trabalho%20G02/EX2_Sensor_de_Temperatura/Circuito_EX2.png" width="400"/>

| Componente         | Pin Digital |
| :---               |    :---:    |
| LED Verde          |      13     |
| LED Vermelho       |      12     |
| Sensor Temperatura |      A1     |
| Buzzer             |      A2     |
| LED6 Vermelho      |      8      |

## Código

```C++
float tmp = analogRead(TMP);
```

O valor lido pelo pin A1, é um valor analógico que pode variar entre vários valores (0 a 1023, 10 bits) conforme a tensão aplicada no mesmo. Contudo o que nós pretendemos obter do sensor de temperatura não é este valor mas sim a temperatura em graus celsius e para isso utiliza-se as seguintes equações:

```C++
tmp = (tmp/1024)*5000;
tmp = (tmp - 500)/10;
```

Sem fazer esta alteração nos resultados os valores seriam algo como 358.00 quando a temperatura fosse 124ºC, ou 133.00 quando a temperatura fosse 24.71ºC.

Após ler o resultado da temperatura utilizamos o mesmo de forma a que se possam criar as reações pretendidas do sistema conforme as condições do mesmo, sendo essas:

Se a temperatura for acima de 40ºC:

```C++
if(tmp>40){
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  Serial.print("Temperatura: ");
  Serial.println(tmp);
  delay(1000);
  digitalWrite(Buzz, HIGH);
  delay(2000);
  digitalWrite(Buzz, LOW);
}
```

1. Ligar o Led Vermelho;
2. Desligar o Pin Verde;
3. Apresentar a temperatura no Serial Monitor (Utilizado a partir do Arduino IDE ou equivalente);
4. Liga o Piezo Buzzer durante dois segundos e volta a desligá-lo.

```C++
else{
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(Buzz, LOW);
}
```

Se não:

1. Ligar o Led Verde
2. Ligar o Led Red
3. Desligar o Piezo Buzzer

---

# EX3 Proximidade
## Circuito

<img src="https://github.com/Cordelios810/TP1_g02/blob/main/Trabalho%20G02/EX3_Proximidade/Circuito_EX3.png?raw=true" width="400"/>

| Componente          | Pin Digital |
| :---                |    :---:    |
| LED Vermelho        |      13     |
| Buzzer              |      A5     |
| Sensor de distância |      A1     |

## Código

```C++
float distance;
char input = 'w'; //defining input as w (waiting) as default
```

Definindo as variáveis "*distance*" e "*input*" como variáveis globais, podemos assim não só utiliza-las entre funções como é o caso da variável "*distance*" ou apenas não ser afetada pelo início do loop( ) como é o caso de "*input*" que assim é definida como "w" apenas até ser alterada dentro do loop( ).

```C++
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
```

O pin definido como SIG é o pin de ligação ao sensor super sónico, e este funciona enviando um sinal e verificando quanto tempo demora o mesmo a ser recebido de volta. Assim, no bloco de código acima podemos verificar essa mesma ação.

SIG começa por ser definido como um OUTPUT podendo assim produzir um sinal quando indicado pelo Arduino, e é exatamente isso que procede a fazer, começa por ser definido como LOW, espera 3 milisegundos, é alterado para HIGH, produzindo assim um sinal e continuando a produzir o mesmo durante 5 milisegundos e voltando a mudar para LOW, parando de produzir o mesmo sinal.

Após isso este é alterado de novo para INPUT de forma a poder receber o sinal, o que faz a partir da função "*pulseIn( )*" interpretando também o tempo que demorou o sinal e dando-lhe um valor analógico, que é alterado para uma distância em centímetros no final da função "*superSonicSensor( )*" este (a distância em centímetros) é o valor valor devolvido pela função.

Continuando para a função "*Loop*":

De forma a se poder produzir som a partir de um Buzzer de forma controlada, pode utilizar-se a seguinte função : "*tone(PinOutput,Frequência)*"

De forma a utilizar-mos o buzzer de forma controlada e ter-mos resultados um pouco mais apreciáveis do que frequências aleatórias, decidi-mos utilizar notas músicais, mais especificamente as notas princípais de uma oitava (excluindo sustenidos e bemois), da 4ª oitava, incluindo ainda o Dó da 5ª oitava.

```C++
  int C4 = 262; //Dó 4
  int D4 = 294; //Ré
  int E4 = 330; //Mi
  int F4 = 349; //Fá
  int G4 = 392; //Sol
  int A4 = 440; //Lá
  int B4 = 494; //Si
  int C5 = 523; //Dó 5
```

Distribuindo assim os valores de frequência que terá que ser produzida pelo Buzzer para produzir essas notas em variáveis específicas com o nome de cada uma em forma do nome de acorde.

```C++
if(Serial.available() > 0){
  input = Serial.read();
  Serial.println(input);
}
```

O bloco de código acima tem como objetivo ler os valores lidos no Serial Monitor, da seguinte forma.

Se uma alteração for detetada nos valores produzidos no serial monitor (sem alteração produz repetidamente o valor "-1"), e iguala o valor introduzido a uma variável "input". Após isso imprime a mesma como forma do utilizador puder verificar o que colocou.

```C++
//if input is w (waiting) the program does nothing and waits for a valid input
if(input == 'w'){}
```

Se o input for w (como é definido no inicio do programa e também assim o seu valor default), este não faz nada, daí o if statement se encontrar vazio, este é utilizado apenas como forma de esperar pela introdução de um dos valores válidos como "R" ou "D".

```C++
else if(input == 'R' or input == 'r'){

  digitalWrite(led_red, HIGH);

  distance = superSonicSensor();

```

Se o valor de input for "R" ou "r" o programa liga o Led vermelhor e procede a utilzar a função "*superSonicSensor( )*" para obter o resultado da distância e iguala-lo a uma variavél (distance), após isso são feitos alguns cálculos.

```C++
  float max_distance_value = 330.71;
  float min_distance_value = 2.23;
  float range_distance_value = max_distance_value - min_distance_value;
  float interval = range_distance_value/8; //41.05125
```

Estes cálculos têm como objetivo começar por determinar o intervalo entre o qual o sensor pode medir distância e utilizando esse valor criar 8 intervalos entre os quais podem ser definidas as notas antes específicadas (O valor entre intervalo deve ser aproximadamente 41).

```C++
  if(distance < min_distance_value + 1 * interval)){tone(Buzzer, C5);}
  else if(distance < (min_distance_value + 2 * interval)){tone(Buzzer, B4);}
  else if(distance < (min_distance_value + 3 * interval)){tone(Buzzer, A4);}
  else if(distance < (min_distance_value + 4 * interval)){tone(Buzzer, G4);}
  else if(distance < (min_distance_value + 5 * interval)){tone(Buzzer, F4);}
  else if(distance < (min_distance_value + 6 * interval)){tone(Buzzer, E4);}
  else if(distance < (min_distance_value + 7 * interval)){tone(Buzzer, D4);}
  else{tone(Buzzer, C4);}
}
```

Cada if statemente resumidamente faz o o cálculo da distância entre cada intervalo de forma a definir uma nota para cada e proceder a produzir esse som a partir da função tone( ), préviamente explicada.

Estas distâncias estão definidas da mesma forma que no gráfico abaixo.

<img src="https://github.com/PedroTorrado/TP1_g02/blob/main/Trabalho%20G02/EX3_Proximidade/Distance%20Sensor%20Representation.jpg" width="400"/>


```C++
//if user types D, LED and Buzzer turn off
else if(input == 'D' or input == 'd'){
  digitalWrite(led_red, LOW);
  noTone(Buzzer);
}
```

Caso o input seja "D" ou "d" este desliga o led e o Buzzer.

```C++
else{
  Serial.println("The input was not recognized.");
  Serial.println("Please use R or D to turn ON or OFF");
  input = 'w';
}
```
Este else refere-se ao if relacionado ao input de caracteres, sendo assim, se o input não for "R" ou "r", "D" ou "d" ou "w", este produz uma mensagem de erro a dizer que o input não é reconhecido e pede que selecione R para ligar o sistema ou D para o desligar e por fim, iguala o input a w deixando-o no estado de espera.

---

# EX3_C Proximidade
## Circuito

<img src="https://github.com/Cordelios810/TP1_g02/blob/main/Trabalho%20G02/EX3_Proximidade_C/EX3_Proximidade_C.jpg" width="400"/>

| Componente          | Pin Digital |
| :---                |    :---:    |
| LED Vermelho        |      13     |
| Sensor PIR          |      A5     |

O objectivo deste exercício é definir distância através de um sensor infravermelho, visto que o sensor PIR não consegue calcular distancias, pois este apenas detecta movimentos resolvemos realizar um circuito onde quando o sensor infravermelho detecta movimento um LED vermelho liga.

Criar uma variavel "*val*" e defenir o valor desta variavel para 0.

```C++
int val = 0;
```
Após ler o resultado enviado pelo sensor que varia entre 0 (se não detetar nada) e 1018 (se detetar algum movimento) utilizamos o mesmo de forma a que se possam criar as reações pretendidas do sistema conforme as condições do mesmo, sendo essas:

Se o valor for igual a 1018:
1. O led vermelho liga.

```C++
if(val==1018){
  digitalWrite(led_red, HIGH);
  }
```
Se não:
1. O led vermelho desliga.

```C++
else{
  digitalWrite(led_red, LOW);
  }
```
