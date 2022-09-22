#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
int vs = D8; // vibration sensor

WiFiClient client;//Nodemcu here is the client & ThingSpeak is the servor

long myChannelNumber = 1774573;
const char myWriteAPIKey[] = "TMNA7UY6AO3TPJKV";
const int httpPort = 80; 
//Sending data to Thingspeak and storing it there
//Therefore, Write API KEYS are being used
const char* ssid = "Galaxy M31s4A14";
const char* password = "MYAlbatross";
const char* host = "maker.ifttt.com";
void setup() {
    Serial.begin(9600);

    Serial.println("Email from Node Mcu");
    delay(100);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    ThingSpeak.begin(client);//To Run the libraries
    pinMode(vs ,INPUT);
    Serial.println("CLEARDATA");
    Serial.println("LABEL,Acolumn,Bcolumn");
    Serial.println("RESETTIMER");
}

void loop() {
  long measurement=pulseIn (vs, HIGH);
  long value=map(measurement,0,10000,100,5000);
  Serial.print("DATA,TIME,TIMER,");
  Serial.println(value);
  ThingSpeak.writeField(myChannelNumber, 1, value, myWriteAPIKey);
  if (!client.connect(host, httpPort)) {  
    Serial.println("connection failed");  
    return;
    }
  if(value > 105){
    
          
                    String url = "/trigger/Threshold_Vibration_Exceeded/with/key/dUc7c3GhH2unZCylq4MnUm"; 

          
                    Serial.print("Requesting URL: ");
                    Serial.println(url);
                 
                     client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
                                    "Host: " + host + "\r\n" +   
                                           "Connection: close\r\n\r\n");    
                                    }  
          
          
          else{
            Serial.println("No leakage");
            
          }
          delay(1000);      
}