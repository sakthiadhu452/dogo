#define BLYNK_TEMPLATE_ID "TMPL3L-nmKBXf"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "2m9tpFIEOIw_7gF4TePXxNijWzSbPXao"; // Enter your Blynk auth token
char ssid[] = "POCO X2"; // Enter your WiFi name
char pass[] = "12345678"; // Enter your WiFi password

#define AutomaticToggle 5 //D1
#define Forward 4 //d2  
#define UP  0 //d3
#define Right 15
#define Back 16 //D8

BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  Serial.print("1");
  if (value1 == 1) {
    digitalWrite(AutomaticToggle, LOW);
  } else {
    digitalWrite(AutomaticToggle, HIGH);
  }
}

BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  if (value2 == 1) {
    digitalWrite(Forward, HIGH);
  } else {
    digitalWrite(Forward, LOW);
  }
}

BLYNK_WRITE(V2) {
  bool value3 = param.asInt();
  if (value3 == 1) {
    digitalWrite(UP, LOW);
  } else {
    digitalWrite(UP, HIGH);
  }
}

BLYNK_WRITE(V4) {
  bool value4 = param.asInt();
  if (value4 == 1) {
    digitalWrite(Right, HIGH);
  } else {
    digitalWrite(Right, LOW);
  }
}

BLYNK_WRITE(V5) {
  bool value5 = param.asInt();
  if (value5 == 1) {
    digitalWrite(Back, HIGH);
  } else {
    digitalWrite(Back, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  delay(100);

  pinMode(AutomaticToggle, OUTPUT);
  pinMode(Forward, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(Right, OUTPUT);
  pinMode(Back, OUTPUT);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
