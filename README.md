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

```

---

# EX2 Sensor de Temperatura
## Circuito
<img src="https://github.com/Cordelios810/TP1_g02/blob/main/Trabalho%20G02/EX2_Sensor_de_Temperatura/Circuito_EX2.png?raw=true" width="400"/>

| Componente         | Pin Digital |
| :---               |    :---:    |
| LED Verde          |      13     |
| LED Vermelho       |      12     |
| Sensor Temperatura |      A1     |
| Buzzer             |      A2     |
| LED6 Vermelho      |      8      |

## Código

```C++
#define led_green 13
#define led_red 12
#define TMP A1
#define Buzz A2
```

Definir cada pin para o seu respetivo componente de forma a que mais tarde possamos referir aos componentes diretamente e não apenas aos pin que estão connectados, como no exemplo:

```C++
digitalWrite(12, HIGH);
digitalWrite(led_red, HIGH);
```

Ambas as linhas fazem o mesmo, contudo, o segundo é mais fácil de entender tanto enquanto está a ser escrito como quando está a ser revisto.

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

1. Ligar o Led Vermelho;
2. Desligar o Pin Verde;
3. Apresentar a temperatura no Serial Monitor (Utilizado a partir do Arduino IDE ou equivalente);
4. Liga o Piezo Buzzer durante dois segundos e volta a desligá-lo.

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

Se não:

1. Ligar o Led Verde
2. Ligar o Led Red
3. Desligar o Piezo Buzzer

```C++
else{
  digitalWrite(led_green, HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(Buzz, LOW);
}
```

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

Definir as variáveis "*distance*" e "*input*" como variáveis globais, podendo assim não só utiliza-la entre funções como é o caso da variável "*distance*" ou apenas não ser afetada pelo início do loop() como é o caso de "*input*".

```C++
float distance;
char input = 'w'; //defining input as w (waiting) as default
```
