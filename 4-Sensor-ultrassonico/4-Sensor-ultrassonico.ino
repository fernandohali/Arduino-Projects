#include <NewPing.h>

// C++ code

int distanceThreshold = 0;

int cm = 0;

int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT); // Limpe o gatilho
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Define o pino de disparo para o estado ALTO por 10 microssegundos
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    // Lê o pino de eco e retorna o tempo de viagem da onda sonora em microssegundos
    return pulseIn(echoPin, HIGH);
}

void setup()
{
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop()
{
    // defina a distância limite para ativar os LEDs
    distanceThreshold = 350;
    // medir o tempo de ping em cm
    cm = 0.01723 * readUltrasonicDistance(7, 6);
    // converter em polegadas dividindo por 2.54
    inches = (cm / 2.54);
    Serial.print(cm);
    Serial.print("cm, ");
    Serial.print(inches);
    Serial.println("in");
    if (cm > distanceThreshold)
    {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    if (cm <= distanceThreshold && cm > distanceThreshold - 100)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 250)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    }
    if (cm <= distanceThreshold - 250 && cm > distanceThreshold - 350)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    if (cm <= distanceThreshold - 350)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(100); // Wait for 100 millisecond(s)
}