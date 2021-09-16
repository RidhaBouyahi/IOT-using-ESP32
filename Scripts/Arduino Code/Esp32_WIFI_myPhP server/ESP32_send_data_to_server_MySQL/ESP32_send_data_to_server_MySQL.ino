#include <SoftwareSerial.h>
#include <WiFi.h>
#define Rxscan 40
#define Txscan 41


SoftwareSerial mySerial(Rxscan,Txscan); // RX, TX

const char* ssid     = "your_ssid";
const char* password = "your_password";
const char* host = "your_hostname";
unsigned char Barcode ;

void setup()
{
  
     Serial.begin(9600);
       mySerial.begin(115200);
     pinMode(Rxscan,INPUT);
     pinMode(Txscan,OUTPUT);
  
    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}



void loop()
{
  
if (mySerial.available()) {
    Barcode = mySerial.read();
        Serial.println(Barcode);
  }
  Serial.println ();
   
    Serial.print("connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    const int httpPort = 5555;
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }

 


    // This will send the request to the server
 client.print(String("GET http://your_hostname/iot_project/connect.php?") + 
                          ("&Barcode=") + Barcode +
                          " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 1000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    // Read all the lines of the reply from server and print them to Serial
    while(client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
        
    }

    Serial.println();
    Serial.println("closing connection");
}
