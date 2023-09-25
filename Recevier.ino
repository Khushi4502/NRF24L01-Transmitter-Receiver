#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(10,9);  // CE,CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,0XF0F0F0E1LL);
  // radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

};

void loop() {
  if(radio.available()){
    char txt[32]="";
    radio.read(&txt,sizeof(txt));
    Serial.println(txt);
  };
};
