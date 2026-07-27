#include <Arduino.h>

const int ledPin = 2; // configura o pino do LED e impede esp32 de alterar o valor.

void setup() { // inicializa a comunicação serial e configura o pino do LED como saída.
  Serial.begin(115200); // inicia a comunicação serial com uma taxa de transmissão de 115200 bps.
  pinMode(ledPin, OUTPUT); // configura o pino do LED como saída.
  Serial.println("Olá, mundo!"); // imprime a mensagem "Olá, mundo!" no monitor serial para indicar que o programa foi iniciado com sucesso.

} // fecha a função setup().

void loop() { // pisca o LED conectado ao pino 2, acendendo-o por 1 segundo e apagando-o por 1 segundo em um loop infinito.
digitalWrite(ledPin, HIGH); // acende o LED.
delay(1000); // acende o LED e aguarda por 1 segundo antes de apagar o LED.
digitalWrite(ledPin, LOW); // apaga o LED.
delay(1000); // aguarda por 1 segundo antes de repetir o ciclo, criando um efeito de piscar do LED.

} // fecha a função loop() e o programa continua a executar indefinidamente, mantendo o LED piscando.