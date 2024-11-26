/*******************************************************************************************************
  Programs for Arduino - Copyright of the author Stuart Robinson - 08/02/20

  This program is supplied as is, it is up to the user of the program to decide if the program is
  suitable for the intended purpose and free from errors.
*******************************************************************************************************/

/*******************************************************************************************************
  Program Operation - This program demonstrates the transmitting of a structure as a LoRa packet. The
  contents of the structure are the same as in the '8_LoRa_LowMemory_TX' program. The packet sent is
  typical of what might be sent from a GPS tracker.

  The structure type is defined as trackerPacket and an instance called location1 is created. The struture
  which includes a character array (text) is filled with values and transmitted.

  The matching receiving program '15_LoRa_RX_Structure' can be used to receive and display the packet,
  though the program '9_LoRa_LowMemory_RX' should receive it as well, since the contents are the same.

  Note that the structure definition and variable order (including the buffer size) used in the transmitter
  need to match those used in the receiver.

  The contents of the packet transmitted should be;

  "tracker1" (buffer)      - trackerID
  1+             (uint32_t)    - packet count
  51.23456       (float)       - latitude
  -3.12345       (float)       - longitude
  199            (uint16_t)    - altitude
  8              (uint8_t)     - number of satellites
  3999           (uint16_t)    - battery voltage
  -9             (int8_t)      - temperature

  Good luck.

  Serial monitor baud rate is set at 9600.

*******************************************************************************************************/
#include <SPI.h>
#include <SX128XLT.h>
#include "Settings.h"

SX128XLT LT;

uint32_t TXpacketCount = 1;
uint32_t startmS, endmS;
/*
struct trackerPacket
{
  uint8_t trackerID[13];
  uint32_t txcount;
  float latitude;
  float longitude;
  uint16_t altitude;
  uint8_t satellites;
  uint16_t voltage;
  int8_t temperature;
} __attribute__((packed, aligned(1)));                 //remove structure padding so there is compatibility between 8bit and 32bit Arduinos

struct trackerPacket location1;                        //define an instance called location1 of the structure trackerPacket
*/

// Array de inteiros com 80 elementos
int numeros[80] = {
  359, 356, 353, 358, 359, 353, 356, 359, 354, 356, 
  359, 357, 356, 361, 358, 352, 360, 358, 355, 361, 
  363, 361, 368, 375, 372, 377, 381, 375, 370, 370, 
  365, 361, 362, 358, 353, 357, 358, 352, 355, 357, 
  351, 352, 356, 353, 350, 355, 353, 344, 334, 325, 
  337, 407, 501, 577, 606, 533, 407, 344, 331, 327, 
  331, 341, 341, 338, 343, 343, 340, 344, 346, 338, 
  345, 351, 347, 347, 352, 350, 350, 356, 355, 352
};

void setup() {
  pinMode(LED1, OUTPUT);                     
  Serial.begin(9600);
  SPI.begin();

  if (LT.begin(NSS, NRESET, RFBUSY, DIO1, DIO2, DIO3, RX_EN, TX_EN, LORA_DEVICE)) {
    Serial.println(F("Transmitter ready"));
  } else {
    Serial.println(F("Device error"));
    while (1) {
      digitalWrite(LED1, HIGH);
      delay(50);
      digitalWrite(LED1, LOW);
      delay(50);
    }
  }

  LT.setupLoRa(Frequency, Offset, SpreadingFactor, Bandwidth, CodeRate);
}

void loop() {
  /*
  pinMode(LED1, OUTPUT);                       //setup pin as output for indicator LED
  led_Flash(2, 125);                           //two quick LED flashes to indicate program start

  Serial.begin(9600);

  SPI.begin();

  if (LT.begin(NSS, NRESET, RFBUSY, DIO1, DIO2, DIO3, RX_EN, TX_EN, LORA_DEVICE))
  {
    led_Flash(2, 125);
  }
  else
  {
    Serial.println(F("Device error"));
    while (1)
    {
      led_Flash(50, 50);                        //long fast speed flash indicates device error
    }
  }
  */


  // Array de caracteres para armazenar a mensagem
  char caracteres[400]; 
  int pos = 0;

  // Converte cada número inteiro do array para string com um separador
  for (int i = 0; i < 80; i++) {
    char temp[10];
    itoa(numeros[i], temp, 10);

    for (int j = 0; temp[j] != '\0'; j++) {
      caracteres[pos++] = temp[j];
    }

    if (i < 79) {
      caracteres[pos++] = '#';
    }
  }
  caracteres[pos] = '\0'; // Finaliza a string

  // Envia a string por LoRa
  digitalWrite(LED1, HIGH);
  startmS = millis();

  if (LT.transmit((uint8_t *)caracteres, sizeof(caracteres), 0, TXpower, WAIT_TX)) {
    endmS = millis();
    digitalWrite(LED1, LOW);
    TXpacketCount++;
    Serial.print("Pacote ");
    Serial.print(TXpacketCount);
    Serial.print(" enviado: ");
    Serial.println(caracteres);
    Serial.print("Tempo de envio: ");
    Serial.print(endmS - startmS);
    Serial.println(" ms");
  } else {
    Serial.print(F("Erro ao enviar - IRQreg,"));
    Serial.println(LT.readIrqStatus(), HEX);
  }

  digitalWrite(LED1, LOW);
  delay(packet_delay);
}
