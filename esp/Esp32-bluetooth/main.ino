#include <BluetoothSerial.h> // instala as dependencias de blutooth e inicialização do esp32.
BluetoothSerial SerialBT;

const int ledPin = 2;   // configura a variavel do ledPin e trava o codigo para o esp32 nao mudar usando o const.
// ______________________________________________________// configuraçoes antes de inicializar o esp32 acima.

// ao inicializar:

void setup() { // inicializa o motor do esp32.
  
  Serial.begin(115200); // configura a velocidade do processador para ficar legivel ao linux/windows. 
  
  pinMode(ledPin, OUTPUT); // configura a entrada de energia ao led.
  
  SerialBT.begin("ESP32"); // configura o bluetooth e o nome do esp32.
  
  Serial.printf("bluetooth ativado"); // mensagem avisando ao bluetooth conectado/ativado.
} 

void loop() {
  // O loop fica pronto para receber a lógica do LED
}
