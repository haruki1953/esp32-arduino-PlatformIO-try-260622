#include <Arduino.h>

// 设置 LED 引脚
const int ledPin = 12;

void TaskBlink(void *pvParameters) {
  pinMode(ledPin, OUTPUT);
  while (true) {
    digitalWrite(ledPin, HIGH);
    Serial.println("TaskBlink: LED ON");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    digitalWrite(ledPin, LOW);
    Serial.println("TaskBlink: LED OFF");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskSerial(void *pvParameters) {
  while (true) {
    Serial.println("TaskSerial: Running...");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  xTaskCreate(TaskBlink, "Blink", 2048, nullptr, 1, nullptr);

  xTaskCreate(TaskSerial, "Serial", 2048, nullptr, 1, nullptr);
}

void loop() {
  // loop 可以空着
}

//

// void setup()
// {
//   // 设定引脚为输出模式
//   pinMode(ledPin, OUTPUT);

//   // 初始化串口，波特率 115200（ESP32 常用）
//   Serial.begin(115200);

//   // 等待串口连接（可选）
//   delay(1000);
//   Serial.println("ESP32 已启动，开始闪烁 LED...");
// }

// void loop()
// {
//   // 点亮 LED
//   digitalWrite(ledPin, HIGH);
//   Serial.println("LED 已点亮aaaa");
//   // 等待一段时间
//   delay(1000);

//   // 关闭 LED
//   digitalWrite(ledPin, LOW);
//   Serial.println("LED 已关闭aaaa");
//   // 等待一段时间
//   delay(1000);
// }
