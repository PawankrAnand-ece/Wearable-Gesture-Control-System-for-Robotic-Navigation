#include <ESP8266WiFi.h>
#include <espnow.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Data packet structure
struct DataPacket {
  char command;
};
DataPacket packet;

// Receiver MAC Address (Robot ESP8266)
uint8_t carMAC[] = {0xDC, 0x4F, 0x22, 0x4D, 0x23, 0xC5};

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu.initialize();
  if (mpu.testConnection())
    Serial.println("MPU6050 Connected");
  else
    Serial.println("MPU6050 Connection Failed");

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW Initialization Failed");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_add_peer(carMAC, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float pitch = atan2(ax, sqrt(ay * ay + az * az)) * 180 / PI;
  float roll  = atan2(ay, sqrt(ax * ax + az * az)) * 180 / PI;

  char cmd = 'S';

  if (pitch > 45) cmd = 'F';
  else if (pitch < -45) cmd = 'B';
  else if (roll > 45) cmd = 'R';
  else if (roll < -45) cmd = 'L';

  packet.command = cmd;
  esp_now_send(carMAC, (uint8_t *)&packet, sizeof(packet));

  Serial.print("Pitch: "); Serial.print(pitch);
  Serial.print(" | Roll: "); Serial.print(roll);
  Serial.print(" | Command: "); Serial.println(cmd);

  delay(50);
}
