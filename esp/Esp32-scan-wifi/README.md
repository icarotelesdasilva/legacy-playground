ESP32 Wi-Fi Scanner

Scanner básico de redes Wi-Fi utilizando ESP32.

O projeto faz uma varredura simples e mostra apenas a quantidade total de redes encontradas próximas ao dispositivo.

Requisitos

* ESP32
* Arduino IDE
* Biblioteca ESP32 instalada

Instalação do suporte ESP32

abra o arduino IDE va em: Arquivo > Preferências

Em “URLs adicionais para Gerenciadores de Placas”, adicione: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Depois vai em: Ferramentas > Placa > Gerenciador de Placas

pesquise esp32 
    Instale o pacote da Espressif Systems

Como usar

1. Abra o projeto

wifi-scanner.ino

Configure a placa
Ferramentas > Placa > ESP32 Dev Module
Ferramentas > Porta
connect o esp32 e aperte em upload.


depois acesse: Monitor Serial

Após enviar o código, coloque baud rate: 115200

exemplo de saida: Escaneando redes Wi-Fi...

Total de redes encontradas: 12


estrutura do projeto: esp32-wifi-scanner/
│
├── wifi-scanner.ino
└── README.md