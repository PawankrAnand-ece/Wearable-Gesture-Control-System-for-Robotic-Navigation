#include <ESP8266WiFi.h>
#include <espnow.h>

// Command structure
struct DataPacket {
  char command;
};
DataPacket incoming;

// Motor pins
#define R_IN1 D1
#define R_IN2 D2
#define R_IN3 D5
#define R_IN4 D6

#define L_IN1 D7
#define L_IN2 D8
#define L_IN3 D3
#define L_IN4 D4

// Ultrasonic pins
#define TRIG_PIN D0
#define ECHO_PIN RX

long duration;

// Motor control functions
void rightForward()  { digitalWrite(R_IN1,HIGH); digitalWrite(R_IN2,LOW);  digitalWrite(R_IN3,HIGH); digitalWrite(R_IN4,LOW); }
void rightBackward() { digitalWrite(R_IN1,LOW);  digitalWrite(R_IN2,HIGH); digitalWrite(R_IN3,LOW);  digitalWrite(R_IN4,HIGH); }
void leftForward()   { digitalWrite(L_IN1,HIGH); digitalWrite(L_IN2,LOW);  digitalWrite(L_IN3,HIGH); digitalWrite(L_IN4,LOW); }
void leftBackward()  { digitalWrite(L_IN1,LOW);  digitalWrite(L_IN2,HIGH); digitalWrite(L_IN3,LOW);  digitalWrite(L_IN4,HIGH); }

void stopAll() {
  digitalWrite(R_IN1,LOW); digitalWrite(R_IN2,LOW);
  digitalWrite(R_IN3,LOW); digitalWrite(R_IN4,LOW);
  digitalWrite(L_IN1,LOW); digitalWrite(L_IN2,LOW);
  digitalWrite(L_IN3,LOW); digitalWrite(L_IN4,LOW);
}

void moveForward()  { rightForward(); leftForward(); }
void moveBackward() { rightBackward(); leftBackward(); }
void turnLeft()     { rightForward(); leftBackward(); }
void turnRight()    { rightBackward(); leftForward(); }

// Ultrasonic distance
int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH, 20000);
  return duration * 0.034 / 2;
}

// ESP-NOW receive callback
void onData(uint8_t *mac, uint8_t *data, uint8_t len) {
  memcpy(&incoming, data, sizeof(incoming));
  char cmd = incoming.command;
  int dist = getDistance();

  if (dist > 0 && dist < 20 && cmd == 'F') {
    stopAll();
    return;
  }

  if (cmd == 'F') moveForward();
  else if (cmd == 'B') moveBackward();
  else if (cmd == 'L') turnLeft();
  else if (cmd == 'R') turnRight();
  else stopAll();
}

void setup() {
  Serial.begin(115200);

  pinMode(R_IN1,OUTPUT); pinMode(R_IN2,OUTPUT);
  pinMode(R_IN3,OUTPUT); pinMode(R_IN4,OUTPUT);
  pinMode(L_IN1,OUTPUT); pinMode(L_IN2,OUTPUT);
  pinMode(L_IN3,OUTPUT); pinMode(L_IN4,OUTPUT);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);

  stopAll();

  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(onData);
}

void loop() {}
