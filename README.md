# ESP32 Bluetooth v2 - Ponte Serial Bidirecional

## Propósito Educacional

Este projeto demonstra como criar uma ponte de comunicação bidirecional entre dois canais de comunicação: serial (USB) e Bluetooth. O objetivo é ensinar como dados podem fluir em ambas as direções simultaneamente.

## O que você vai aprender

1. Comunicação bidirecional (duplex completo)
2. Verificação de disponibilidade de dados com available()
3. Leitura de dados com read()
4. Escrita de dados com write()
5. Estrutura condicional para múltiplos fluxos de dados

## Funcionamento do Código

**Setup (executado uma única vez):**
- Inicializa serial a 115200 baud
- Aguarda 2 segundos para estabilização do hardware
- Inicializa Bluetooth com nome "ESP32"
- Exibe mensagem de status no monitor serial

**Loop (executado continuamente):**
O programa monitora dois canais simultaneamente:

Canal 1 - Serial para Bluetooth:
- Verifica se há dados disponíveis na porta serial (USB)
- Se houver, lê o caractere e transmite via Bluetooth

Canal 2 - Bluetooth para Serial:
- Verifica se há dados disponíveis via Bluetooth
- Se houver, lê os dados e escreve no monitor serial

## Fluxo de Dados

Computador (USB Serial) ↔ ESP32 ↔ Smartphone (Bluetooth)

## Hardware Necessário

- 1 placa ESP32 (DevKit v1 recomendado)
- 1 cabo USB-C ou Micro-USB
- 1 smartphone com Bluetooth
- Aplicativo de terminal Bluetooth (Serial Bluetooth Terminal, BLE Terminal)

## Como Usar

1. Configure a Arduino IDE para ESP32
2. Copie o código para o PlatformIO (src/main.cpp)
3. Faça o upload do código
4. Abra o monitor serial (Ctrl+Shift+M) a 115200 baud
5. No smartphone, instale aplicativo de terminal Bluetooth
6. Procure por "ESP32" e pareie
7. Conecte ao dispositivo via aplicativo

## Teste Prático

**Teste 1 - Serial para Bluetooth:**
- No monitor serial, digite: "Olá"
- Veja a mensagem aparecer no aplicativo do smartphone

**Teste 2 - Bluetooth para Serial:**
- No aplicativo do smartphone, envie: "Teste"
- Veja a mensagem aparecer no monitor serial do PC

**Teste 3 - Comunicação Simultânea:**
- Mantenha o monitor serial aberto
- Abra o aplicativo Bluetooth no smartphone
- Digite simultaneamente nos dois lados e observe o fluxo

## Conceitos Explicados no Código

**#include "BluetoothSerial.h"**
- Importa biblioteca para módulo Bluetooth do ESP32

**BluetoothSerial SerialBT;**
- Cria objeto que representa a porta Bluetooth
- Funciona de forma similar ao Serial, mas sem fio

**Serial.begin(115200);**
- Inicializa comunicação serial via USB
- 115200 baud é velocidade padrão

**delay(2000);**
- Aguarda 2 segundos antes de inicializar Bluetooth
- Evita conflitos de hardware

**SerialBT.begin("ESP32");**
- Ativa Bluetooth com nome "ESP32"
- Nome aparecerá ao procurar por dispositivos

**if (Serial.available())**
- Verifica se há dados na fila de entrada serial
- Se verdadeiro, há pelo menos 1 byte disponível

**SerialBT.write(Serial.read());**
- Lê 1 byte da serial
- Transmite pelo Bluetooth para o smartphone

**if (SerialBT.available())**
- Verifica se há dados chegando via Bluetooth

**Serial.write(SerialBT.read());**
- Lê dados Bluetooth
- Escreve no monitor serial

## Estrutura do Projeto

esp32-bluetooth-v2/
- .gitignore
- .vscode/
- platformio.ini (configuração do projeto)
- src/main.cpp (código principal)
- README.md (este arquivo)

## Diferenças com esp32-bluetooth (v1)

v1: Loop vazio (template), Comunicação unidirecional
v2: Loop implementado (funcional), Comunicação bidirecional

## Exercícios para Praticar

1. Modifique o código para ecoar dados: tudo que vem do Bluetooth volta para o Bluetooth
2. Adicione um contador: cada vez que recebe dados, incrementa e exibe
3. Implemente um comando: se receber "LIGA", execute ação; se receber "DESLIGA", execute outra ação
4. Crie um filtro: ignore caracteres numéricos, transmita apenas letras
5. Adicione timestamp: coloque a hora antes de cada mensagem transmitida

## Aplicações Práticas

1. Controle remoto de LED via Bluetooth mais feedback serial
2. Aplicativo móvel que controla ESP32
3. Debug remoto sem cabo USB
4. Telemetria de sensores para smartphone
5. Interface de teste para protótipos

## Hardware Testado

- ESP32 DevKit v1
- PlatformIO com core ESP32
- Arduino IDE 1.8.x+
- Smartphones Android 4.0+

## Próximos Passos

Após dominar este projeto:
1. Implemente controle de LEDs via comandos Bluetooth
2. Adicione sensores que enviam dados via Bluetooth
3. Estude WiFi como alternativa ao Bluetooth
4. Explore comunicação NFC
5. Crie aplicativo Android para interface gráfica

## Dicas de Debug

Se não funcionar:
1. Verifique a taxa de baud (deve ser 115200 em ambos os lados)
2. Confirme que o ESP32 foi programado corretamente
3. Reinicie o ESP32 após carregar o código
4. Verifique se o smartphone tem Bluetooth ativado
5. Tente um aplicativo diferente de terminal Bluetooth

## Licença

Projeto educacional livre para estudos e aprendizado em sistemas embarcados.
