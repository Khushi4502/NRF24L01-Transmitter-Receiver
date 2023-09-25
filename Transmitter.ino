#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(10,9);  // CE,CSN


void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(0xF0F0F0E1);
  radio.setPALevel(RF24_PA_HIGH);
  // radio.stopListening();

};

void loop() {
 const char txt[] = "Hello Word";
 radio.write(&txt,sizeof(txt));
 delay(1000);
 Serial.println("Text send");
};
