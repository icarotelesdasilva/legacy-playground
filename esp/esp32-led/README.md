# ESP32 Health - Teste de Funcionamento Básico

## Propósito Educacional

Este projeto ensina os conceitos fundamentais de programação em sistemas embarcados usando ESP32. O foco é demonstrar a configuração de hardware e o controle de um LED através da saída digital.

## O que você vai aprender

1. Estrutura básica de um programa Arduino (setup e loop)
2. Como configurar um pino digital como saída
3. Como controlar um LED com digitalWrite
4. Como trabalhar com delays (atrasos)
5. Comunicação serial para debug

## Funcionamento do Código

O programa executa as seguintes etapas:

**Setup (executado uma única vez ao iniciar):**
- Inicializa a comunicação serial a 115200 baud (velocidade padrão para leitura no monitor)
- Configura o pino 2 como OUTPUT (saída de 5V ou 3.3V)

**Loop (executado continuamente):**
- Envia 5V para o pino 2 (digitalWrite HIGH)
- Aguarda 1 segundo
- O LED permanece ligado continuamente

## Hardware Necessário

- 1 placa ESP32 (DevKit v1 recomendado)
- 1 LED (cor opcional)
- 1 resistor de 220Ω (proteção do LED)
- 1 cabo USB-C ou Micro-USB (para programação)
- Jumpers para conexão
- Protoboard (opcional mas recomendado)

## Esquema de Ligação

```
ESP32 Pino 2 ----[LED(+)]
LED(-) ----[Resistor 220Ω]----[GND]
```

## Como Usar

1. Abra a Arduino IDE ou PlatformIO
2. Copie o código do arquivo esp32led.ino
3. Selecione a placa: Ferramentas > Placa > ESP32 Dev Module
4. Selecione a porta da placa
5. Carregue o código com Ctrl+U (ou Upload)
6. Observe o LED acender no pino 2

## Resultado Esperado

Após programar a placa:
- O LED conectado ao pino 2 acenderá imediatamente
- O LED permanecerá aceso continuamente
- A comunicação serial mostrará a mensagem de inicialização

## Conceitos Explicados no Código

**const int ledPin = 2;**
- Cria uma constante que não pode ser alterada durante o programa
- Protege o valor da memória
- Boa prática em sistemas embarcados

**pinMode(ledPin, OUTPUT);**
- Configura o pino como saída de energia
- Permite que o ESP32 envie sinal para controlar o LED

**digitalWrite(ledPin, HIGH);**
- Envia nível lógico alto (5V ou 3.3V) ao pino
- HIGH liga o LED, LOW desligaria

**delay(1000);**
- Pausa a execução por 1000 milissegundos (1 segundo)
- Evita problemas de velocidade de execução

## Exercícios para Praticar

1. Modifique o código para fazer o LED piscar: ligue por 500ms, desligue por 500ms
2. Adicione um terceiro estado: ligue por 200ms, desligue por 200ms
3. Use a variável de posição do loop para criar padrões de piscagem (acende x vezes, apaga x vezes)
4. Capture o estado do LED em uma variável booleana e inverta ela a cada ciclo

## Hardware Testado

- ESP32 DevKit v1
- IDE: Arduino 1.8.x e superior
- Compilador: GCC arm-none-eabi

## Próximos Passos

Após dominar este projeto:
1. Aprenda a ler entrada digital com pinMode(INPUT) e digitalRead()
2. Estude Esp32-bluetooth para adicionar controle remoto
3. Explore PWM (Pulse Width Modulation) para controlar brilho do LED
4. Combine com sensores para criar projetos interativos

## Licença

Projeto educacional livre para estudos e aprendizado em sistemas embarcados.