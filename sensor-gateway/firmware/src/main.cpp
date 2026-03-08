#include <Arduino.h>
#include "protocol.h"

// LD6002 串口（请按实际硬件修改）
static HardwareSerial radarSerial(1);

static VitalSample latest = {0, 0, 0, 0, 0.0f};

bool parseLd6002Frame(VitalSample &sample) {
  // TODO: 按 LD6002 协议解帧
  // 这里先做占位：模拟心率/呼吸
  sample.ts = millis();
  sample.heartRate = 72;
  sample.respRate = 16;
  sample.presence = 1;
  sample.confidence = 0.90f;
  return true;
}

void publishTelemetry(const VitalSample &sample) {
  Serial.printf(
      "{\"ts\":%lu,\"heart_rate\":%d,\"resp_rate\":%d,\"presence\":%d,\"radar_conf\":%.2f}\n",
      sample.ts,
      sample.heartRate,
      sample.respRate,
      sample.presence,
      sample.confidence);
}

void setup() {
  Serial.begin(115200);
  radarSerial.begin(256000, SERIAL_8N1, 18, 17); // RX, TX

  // TODO: 初始化圆形触摸屏（SPI + I2C Touch）
}

void loop() {
  if (parseLd6002Frame(latest)) {
    // TODO: 将 latest 同步渲染到圆屏 UI
    publishTelemetry(latest);
  }

  delay(300);
}
