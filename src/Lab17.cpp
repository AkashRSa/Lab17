/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Akash/IoTCamp2023/Lab17/src/Lab17.ino"
#include "MQTT.h"

void setup();
void loop();
#line 3 "c:/Users/Akash/IoTCamp2023/Lab17/src/Lab17.ino"
SYSTEM_THREAD(ENABLED);

void callback(char *topic, byte *payload, unsigned int length);

MQTT client("lab.thewcl.com", 1883, callback);

void setup()
{
  Serial.begin(9600);
  client.subscribe("Lab17/north");
  client.subscribe("Lab17/east");
  Serial.println("works?");
}

void loop()
{
  if (client.isConnected())
  {
    client.loop();
  }
  else
  {
    client.connect(System.deviceID());
    client.subscribe("Lab17/north");
    client.subscribe("Lab17/east");
  }
}

void callback(char *topic, byte *payload, unsigned int length)
{
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  Serial.printf("%s", p);

  if (strcmp(topic, "Lab17/north") == 0) {
    Serial.println("north");
  }
  else if (strcmp(topic, "Lab17/east") == 0) {
    Serial.println("east");
  }
  
}