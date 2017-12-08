#include <ESP8266WiFi.h>

#define WIFI_SSID ""
#define PASSWORD ""

String  i;
WiFiServer server(80);

#define LEFT_WHEEL 4
#define RIGHT_WHEEL 5
#define LEFT_WHEEL_DIRECTION 2 // LOW is forwards
#define RIGHT_WHEEL_DIRECTION 0 // HIGH is backwards

void setup()
{
  Serial.begin(115200);

  pinMode(LEFT_WHEEL, OUTPUT);
  pinMode(RIGHT_WHEEL, OUTPUT);
  pinMode(LEFT_WHEEL_DIRECTION, OUTPUT);
  pinMode(RIGHT_WHEEL_DIRECTION, OUTPUT);
  
  WiFi.disconnect();
  delay(2000);
  Serial.println("Connecting to WIFI");
  WiFi.begin(WIFI_SSID,PASSWORD);
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");
  }Serial.println("I am Connected");
  Serial.println("My Local IP is : ");
  Serial.print((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    if (i == "forward") {
      digitalWrite(RIGHT_WHEEL,HIGH);
      digitalWrite(RIGHT_WHEEL_DIRECTION,LOW);
            
      digitalWrite(LEFT_WHEEL,HIGH);
      digitalWrite(LEFT_WHEEL_DIRECTION,LOW);
      
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("forward");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "reverse") {
      digitalWrite(RIGHT_WHEEL,HIGH);
      digitalWrite(RIGHT_WHEEL_DIRECTION,HIGH);
            
      digitalWrite(LEFT_WHEEL,HIGH);
      digitalWrite(LEFT_WHEEL_DIRECTION,HIGH);
      
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("reverse");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "right") {
      digitalWrite(RIGHT_WHEEL,LOW);
      digitalWrite(RIGHT_WHEEL_DIRECTION,LOW);
            
      digitalWrite(LEFT_WHEEL,HIGH);
      digitalWrite(LEFT_WHEEL_DIRECTION,LOW);
      
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("right");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "left") {
      digitalWrite(RIGHT_WHEEL,HIGH);
      digitalWrite(RIGHT_WHEEL_DIRECTION,LOW);
            
      digitalWrite(LEFT_WHEEL,LOW);
      digitalWrite(LEFT_WHEEL_DIRECTION,LOW);
      
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("left");
      client.println("</html>");
      client.stop();
      delay(1);

    }
    if (i == "stop") {
      digitalWrite(2,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("stop");
      client.println("</html>");
      client.stop();
      delay(1);

    }

}
