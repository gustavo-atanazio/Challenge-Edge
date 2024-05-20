#include <DHT.h>

#define DHTPIN A5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int temp;
int pinosLedBar[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};
int nivelLed;

void setup() {
    Serial.begin(9600);
    dht.begin();

    for (int x = 0; x < 10; x++) {
        pinMode(pinosLedBar[x], OUTPUT);
        digitalWrite(pinosLedBar[x], LOW);
    }
}

void loop() {
    delay(1000);
    temp = dht.readTemperature();

    // Limita o nível do LED entre 0 e 10
    nivelLed = map(temp, -40, 80, 0, 10);
    nivelLed = constrain(nivelLed, 0, 10);

    // Desliga todos os LEDs
    for (int i = 0; i < 10; i++) {
        digitalWrite(pinosLedBar[i], LOW);
    }

    // Se a temperatura for maior que 50, acende todos os LEDs
    if (temp > 50) {
        for (int i = 0; i < 10; i++) {
            digitalWrite(pinosLedBar[i], HIGH);
        }
    } else {
        // Acende os LEDs conforme o nível calculado
        for (int i = 0; i < nivelLed; i++) {
            digitalWrite(pinosLedBar[i], HIGH);
        }
    }

    // Envia a temperatura para o monitor serial
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.println(" °Celsius");
}