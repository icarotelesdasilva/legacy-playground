# ESP32 Bluetooth Básico - Configuração de Comunicação Sem Fio

## Propósito Educacional

Este projeto ensina como inicializar e configurar o módulo Bluetooth clássico do ESP32. O foco é demonstrar a comunicação sem fio básica e a integração entre componentes de hardware.

## O que você vai aprender

1. Como importar e usar bibliotecas externas (BluetoothSerial)
2. Inicialização do Bluetooth com nome customizado
3. Comunicação serial com taxa de transmissão fixa
4. Diferença entre setup (configuração) e loop (execução contínua)
5. Uso de constantes para proteger valores críticos

## Funcionamento do Código

**Setup (executado uma única vez):**
- Inicializa comunicação serial a 115200 baud
- Aguarda 2 segundos para estabilização
- Inicializa o módulo Bluetooth com nome "ESP32"
- Exibe mensagem no monitor serial informando o status

**Loop (executado continuamente):**
- O programa fica em espera esperando por dados
- Aguarda uma ação do usuário (conexão via Bluetooth)

Este é um template: o loop está propositalmente vazio para que o iniciante complete com sua própria lógica.

## Hardware Necessário

- 1 placa ESP32 (DevKit v1 recomendado)
- 1 LED (opcional para extensão do projeto)
- 1 resistor de 220Ω (se usar LED)
- 1 cabo USB para programação
- Smartphone com suporte Bluetooth (para testes)

## Como Usar

1. Abra a Arduino IDE
2. Copie o código do arquivo main.ino para um novo projeto
3. Instale a biblioteca BluetoothSerial (já vem integrada no core do ESP32)
4. Selecione: Ferramentas > Placa > ESP32 Dev Module
5. Selecione a porta USB
6. Faça o upload do código
7. No smartphone, acesse Bluetooth e procure por "ESP32"
8. Pareie com o dispositivo (sem senha necessária)

## Resultado Esperado

Após programar:
- O ESP32 exibirá "Bluetooth ativado" no monitor serial
- O smartphone detectará "ESP32" como dispositivo Bluetooth disponível
- A conexão será estabelecida sem autenticação necessária

## Conceitos Explicados no Código

**#include <BluetoothSerial.h>**
- Importa a biblioteca de Bluetooth do ESP32
- Integrada ao core, não precisa instalar separadamente

**BluetoothSerial SerialBT;**
- Cria um objeto SerialBT que representa a porta Bluetooth
- Funciona como um "canal de comunicação sem fio"

**const int ledPin = 2;**
- Constante que não pode ser alterada
- Protege valores críticos de modificação acidental

**Serial.begin(115200);**
- Inicia comunicação serial via USB
- 115200 baud é a velocidade padrão para leitura clara

**delay(2000);**
- Pausa 2 segundos antes de inicializar Bluetooth
- Permite que o hardware se estabilize

**SerialBT.begin("ESP32");**
- Inicializa o Bluetooth com nome de identificação "ESP32"
- Este nome aparecerá quando procurar por Bluetooth disponível

**Serial.printf("bluetooth ativado");**
- Envia mensagem de debug para o monitor serial
- Útil para verificar se o código executou corretamente

## Exercícios para Praticar

1. Altere o nome do Bluetooth de "ESP32" para um nome customizado (seu nome ou apelido)
2. Complete o loop() para receber dados via Bluetooth e exibir no monitor serial
3. Complete o loop() para receber dados do monitor serial e enviar via Bluetooth
4. Adicione um LED que acenda quando Bluetooth conectar (verificar disponibilidade de dados)
5. Crie uma sequência de inicialização com múltiplas mensagens com delay entre elas

## Comparação com Conectividade Cabeada

**Comunicação Serial (USB):**
- Conectado por cabo
- Alcance: 2-3 metros (limitado pelo cabo)
- Velocidade: até 230400 baud
- Poder: fornecido via USB

**Comunicação Bluetooth (ESP32-bluetooth):**
- Sem fio
- Alcance: até 100 metros (dependendo da versão)
- Velocidade: até 115200 baud (limitação do Bluetooth clássico)
- Poder: fornecido por bateria ou USB

## Hardware Testado

- ESP32 DevKit v1
- Arduino IDE 1.8.x e superior
- Smartphones Android 4.0+
- iPhones com iOS 8.0+ (requer adaptador especial)

## Próximos Passos

Após dominar este projeto:
1. Complete o loop() com lógica de envio/recebimento de dados
2. Estude esp32-bluetooth-v2 para ponte bidirecional
3. Implemente controle de LED via Bluetooth
4. Explore comunicação WiFi como alternativa
5. Combine Bluetooth com sensores para aplicações IoT

## Licença

Projeto educacional livre para estudos e aprendizado em sistemas embarcados.
