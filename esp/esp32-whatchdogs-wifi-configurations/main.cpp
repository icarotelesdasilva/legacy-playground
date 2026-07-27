#include <Arduino.h> 
#include <WiFi.h>
#include <esp_task_wdt.h> // as bibliotecas nescessarias que usarei nesse codigo.
#define WDT_TIMEOUT 5

const int ledPin = 13;  //  cria uma variavel com numeração aleatoria para o pino do led.

void esperarComMillis(unsigned long ms) { // função para esperar um tempo determinado usando millis, e durante esse tempo o watchdog é alimentado para evitar que o sistema reinicie.
  unsigned long tempoInicial = millis(); // variavel para armazenar o tempo inicial.
  while (millis() - tempoInicial < ms) { // enquanto o tempo atual menos o tempo inicial for menor que o tempo desejado, o sistema continua esperando.
    esp_task_wdt_reset();  // alimenta o watchdog para evitar que o sistema reinicie durante a espera.
    yield();            // permite que outras tarefas sejam executadas durante a espera, evitando bloqueios.
  }
}

void setup() { // função de configuração, onde o sistema é inicializado e configurado.
  Serial.begin(115200); // inicia a comunicação serial com uma taxa de transmissão de 115200 bps.
  delay(1000);  // pequena pausa para garantir que a comunicação serial esteja pronta antes de enviar mensagens.
  
  Serial.println("WDT: Sistema inicializado."); // mensagem de inicialização do sistema.
 
  pinMode(ledPin, OUTPUT); // configura o pino do led como saída.
  digitalWrite(ledPin, LOW); // garante que o led comece desligado.

  Serial.println("WDT: Inicializando o Watchdog Timer."); // mensagem indicando que o watchdog timer está sendo inicializado.
  
  esp_task_wdt_config_t wdt_config = { // configuração do watchdog timer, onde o tempo limite é definido, quais núcleos serão monitorados e se o sistema deve entrar em pânico quando o watchdog estourar.
      .timeout_ms = WDT_TIMEOUT * 1000, // tempo limite em milissegundos (5 segundos).
      .idle_core_mask = (1 << portNUM_PROCESSORS), // monitora ambos os núcleos do ESP32.
      .trigger_panic = true // se true, o sistema entrará em pânico (reiniciará) quando o watchdog estourar.

  }; 

  
  esp_task_wdt_init(&wdt_config); // inicializa o watchdog timer com a configuração definida.
  esp_task_wdt_add(NULL);  // adiciona a tarefa atual (loop principal) ao monitoramento do watchdog timer.
  Serial.println("WDT: Watchdog ativo e monitorando."); // mensagem indicando que o watchdog timer está ativo e monitorando a tarefa atual.

  esp_reset_reason_t reason = esp_reset_reason(); // obtém a razão da última reinicialização do ESP32 para verificar se foi causada pelo watchdog timer ou por uma reinicialização normal.
  if (reason == ESP_RST_TASK_WDT || reason == ESP_RST_WDT) { // verifica se a razão da reinicialização foi causada pelo watchdog timer.
    Serial.println("WDT: ALERTA: O ESP32 FOI REINICIADO PELO WATCHDOG TIMER (TRAVOU)!"); // mensagem de alerta indicando que o ESP32 foi reiniciado pelo watchdog timer, o que significa que o sistema travou e não conseguiu alimentar o watchdog a tempo.
  
} else { // se a razão da reinicialização não foi causada pelo watchdog timer, é uma reinicialização normal (power-on ou reset físico).

    Serial.println("WDT: INFO: Reinicialização normal (Power-on / Reset físico)."); // mensagem informando que a reinicialização foi normal, o que é esperado na primeira inicialização do sistema ou após um reset físico.
  }

  const char* ssid = "ESP32_Rede";  // nome da rede Wi-Fi que será criada pelo ESP32 como ponto de acesso.
  const char* password = "senha12345678"; // senha para a rede Wi-Fi do ponto de acesso (deve ter pelo menos 8 caracteres para ser válida).

  Serial.print("WDT: Wi-Fi Conectando-se à rede: "); // mensagem indicando que o ESP32 está tentando criar um ponto de acesso Wi-Fi com o nome da rede especificada.
  Serial.println(ssid); // imprime o nome da rede Wi-Fi que está sendo criada.
  
  WiFi.softAP(ssid, password); // cria um ponto de acesso Wi-Fi com o nome e senha especificados, permitindo que outros dispositivos se conectem a ele. 


  Serial.println("Wi-Fi Ponto de acesso criado com sucesso."); // mensagem indicando que o ponto de acesso Wi-Fi foi criado com sucesso, o que significa que outros dispositivos agora podem se conectar a ele usando o nome e senha fornecidos.
  Serial.print("Wi-Fi Endereço IP do ponto de acesso "); // mensagem indicando que o endereço IP do ponto de acesso Wi-Fi será exibido a seguir, o que é útil para os usuários que desejam se conectar ao ponto de acesso e precisam saber o endereço IP para acessar serviços ou recursos hospedados no ESP32.
  Serial.println(WiFi.softAPIP()); 
  
  Serial.println("WDT: Entrando no Loop Principal."); // mensagem indicando que o sistema está entrando no loop principal, onde o código continuará a ser executado repetidamente, e o watchdog timer continuará monitorando a tarefa para garantir que ela não trave ou demore demais para responder.
}

void loop() { // função principal do programa, onde o código é executado repetidamente. Aqui, o watchdog timer é alimentado regularmente para evitar que o sistema reinicie, e um LED pisca para indicar que o sistema está funcionando normalmente. Além disso, um delay longo é introduzido para demonstrar o comportamento do watchdog timer quando o sistema não responde a tempo.
  
  esp_task_wdt_reset(); 

  Serial.println("WDT: LOOP Watchdog alimentado."); // mensagem indicando que o watchdog timer foi alimentado no início de cada iteração do loop, o que é essencial para evitar que o sistema reinicie devido a um timeout do watchdog timer.

    digitalWrite(ledPin, HIGH); // liga o LED para indicar que o sistema está funcionando normalmente.
  esperarComMillis(1000); // espera por 1 segundo usando a função personalizada que alimenta o watchdog timer durante a espera para evitar reinicializações indesejadas.
  digitalWrite(ledPin, LOW); // desliga o LED após a espera, criando um efeito de piscar.
  esperarComMillis(1000); // espera por mais 1 segundo usando a função personalizada, mantendo o watchdog timer alimentado durante a espera.

  esp_task_wdt_reset(); // alimenta o watchdog timer novamente para garantir que ele não reinicie o sistema durante a próxima parte do código, onde um delay mais longo será introduzido para demonstrar o comportamento do watchdog timer quando o sistema não responde a tempo.
    Serial.println("WDT: LOOP Watchdog alimentado novamente."); // mensagem indicando que o watchdog timer foi alimentado novamente antes de entrar em um delay mais longo, o que é importante para evitar reinicializações indesejadas durante a demonstração do comportamento do watchdog timer.
    
} 
