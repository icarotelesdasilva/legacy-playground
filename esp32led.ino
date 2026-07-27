#include <Arduino.h>

const int ledPin = 2;   // configuração de led.

void setup() { // liga o esp32.


Serial.begin(115200); // coloca a velocidade padrão.
 
pinMode(ledPin, OUTPUT); // configura o pino

} // fecha o comando e vai pro proximo.

void loop() {  // loop infinito para o led nao piscar nem desligar.

digitalWrite(ledPin, HIGH); // cofigura para o led ficar ligado mais alto possivel. 

delay(1000); // delay para nao dar problemas

} // simplesmente acabou o comando

// lembrando que o script foi feito e testado e aprovado num esp32 devkitv1.
