//https://hackaday.io/project/173660-esp8266-ajax-outputs-control
//https://github.com/Digital1O1/AJAX_Toggle_LED.git
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "webpage.h" // Header file containing HTML+JS script for website

char ssid[] = "I Shouldntve Eaten That Burrito";
char pass[] = "valeriepooping";

WiFiServer server(80);
String request = "";
const int OUT0 = 16;
const int OUT1 = 5;
const int OUT2 = 4;
const int OUT3 = 0;
int output_Pins[] = {OUT0, OUT1, OUT2, OUT3};
//Test
String readState()
{
  String output_3, output_2, output_1, output_0; // {OUT3, OUT2, OUT1, OUT0}
  String data_out;

  if (digitalRead(OUT3) == HIGH)
  {
    output_3 = "1";
  }
  else
  {
    output_3 = "0";
  }

  if (digitalRead(OUT2) == HIGH)
  {
    output_2 = "1";
  }
  else
  {
    output_2 = "0";
  }

  if (digitalRead(OUT1) == HIGH)
  {
    output_1 = "1";
  }
  else
  {
    output_1 = "0";
  }

  if (digitalRead(OUT0) == HIGH)
  {
    output_0 = "1";
  }
  else
  {
    output_0 = "0";
  }

  data_out = output_3 + ":" + output_2 + ":" + output_1 + ":" + output_0;
  return data_out;
}

void setup()
{
  // Initialize outputs
  for (int i = 0; i < sizeof(output_Pins) / sizeof(output_Pins[0]); i++)
  {
    pinMode(output_Pins[i], OUTPUT);
    digitalWrite(output_Pins[i], LOW);
  }

  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("[CONNECTED]");
  Serial.print("[IP ");
  Serial.print(WiFi.localIP());
  Serial.println(" ]");

  // start a server
  server.begin();
  Serial.println("Server started");
}

void loop()
{
  String data;

  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }

  // Read the first line of the request || request is a String variable
  request = client.readStringUntil('\r');

  Serial.print("request: ");
  Serial.println(request);

  /* Recieves requests from HTML website
     'Response' from website will look like this : request: GET /H3 HTTP/1.1
  */
  if (request.indexOf("H3") > 0)
  {
    digitalWrite(OUT3, HIGH);
    client.print(readState());
  }
  else if (request.indexOf("L3") > 0)
  {
    digitalWrite(OUT3, LOW);
    client.print(readState());
  }

  else if (request.indexOf("H2") > 0)
  {
    digitalWrite(OUT2, HIGH);
    client.print(readState());
  }
  else if (request.indexOf("L2") > 0)
  {
    digitalWrite(OUT2, LOW);
    client.print(readState());
  }

  else if (request.indexOf("H1") > 0)
  {
    digitalWrite(OUT1, HIGH);
    client.print(readState());
  }
  else if (request.indexOf("L1") > 0)
  {
    digitalWrite(OUT1, LOW);
    client.print(readState());
  }

  else if (request.indexOf("H0") > 0)
  {
    digitalWrite(OUT0, HIGH);
    client.print(readState());
  }
  else if (request.indexOf("L0") > 0)
  {
    digitalWrite(OUT0, LOW);
    client.print(readState());
  }

  else if (request.indexOf("STATE") > 0)
  {
    client.print(readState());
  }

  else
  {
    // Discard any bytes that have been written to the client but not yet read.
    client.flush();
    client.print(html_1);
  }
  delay(5);
}
