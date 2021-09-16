/*
  description:
  The sample code is used to read the barcode value using RS232-TTL Converter
  This Module will transmit the barcode value in ASCⅡ and end up with 0D
  VCC -- VCC
  GND -- GND

*/
String code = "";           //initialize the output string
boolean endbit = 0;            //a flag to mark 0D received
char temp;

void setup() {
  Serial.begin(9600);       //initialize the Serial port
}

void loop() {
  if (Serial.available() > 0)     {
    temp = char( Serial.read());    //read the input data
    code += temp;
  }
  if (temp == 0x0D){           // Or temp == '\r'
    Serial.println(code);
    code = "";
    endbit = 0;
    temp = 0;
  }

}