#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SoftwareSerial.h>


#define Rxscan 40
#define Txscan 41
#define FIREBASE_HOST "Link"
#define FIREBASE_AUTH "Token"
#define WIFI_SSID "Wifi_ssid"
#define WIFI_PASSWORD "password"



SoftwareSerial mySerial(Rxscan,Txscan); // RX, TX

Unsigned char Barcode

//Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;

// int Vrdata = 0;

void setup()
{

  Serial.begin(115200);
      mySerial.begin(115200);
    pinMode(Rxscan,INPUT);
    pinMode(Txscan,OUTPUT);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  /*
  This option allows get and delete functions (PUT and DELETE HTTP requests) works for device connected behind the
  Firewall that allows only GET and POST requests.

  Firebase.enableClassicRequest(firebaseData, true);
  */

  //String path = "/data";


  Serial.println("------------------------------------");
  Serial.println("Connected...");

}

void loop()
{

  if (mySerial.available()) {
    Barcode = mySerial.read();
        Serial.println(Barcode);
  }
  Serial.println ();
}
  json.set("/data", Barcode);
  Firebase.updateNode(firebaseData,"/Product",json);


}
