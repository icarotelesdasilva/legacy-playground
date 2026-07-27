#include <WiFi.h>

void setup() {
    Serial.begin(115200);
    Serial.printf("feito por icr\n");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    
    int n = WiFi.scanNetworks();
    Serial.printf("scan feito: %d redes encontradas\n", n);
}

void loop() {
    int n = WiFi.scanNetworks();
    Serial.printf("scan feito: %d redes encontradas\n", n);
    delay(5000);
}