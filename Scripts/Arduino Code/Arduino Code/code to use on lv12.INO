#include <SoftwareSerial.h>
#define Rxscan 40
#define Txscan 41

SoftwareSerial mySerial(Rxscan,Txscan); // RX, TX

Unsigned char Barcode

void setup() {
 	 Serial.begin(9600);
  	   mySerial.begin(115200);
 		 pinMode(Rxscan,INPUT);
 		 pinMode(Txscan,OUTPUT);
}

void loop() {
				  // run over and over
  if (mySerial.available()) {
  	Barcode = mySerial.read();
    		Serial.println(Barcode);
  }
  Serial.println ();
}
