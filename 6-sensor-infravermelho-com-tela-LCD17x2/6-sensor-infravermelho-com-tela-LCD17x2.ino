#include <IRremote.hpp>
#include <LiquidCrystal.h>
#define IR_RECEIVE_PIN 10

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(115200); 
  lcd.begin(16, 2);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.command);
       if (IrReceiver.decodedIRData.command == 69) {
            lcd.setCursor(0, 0);
            lcd.print("");
            delay(1000);
            lcd.clear();
        }else if (IrReceiver.decodedIRData.command == 70) {
            
        }else if (IrReceiver.decodedIRData.command == 71) {
           
        }else{
          delay(3000); 
        }
      IrReceiver.resume(); 
  }
}
