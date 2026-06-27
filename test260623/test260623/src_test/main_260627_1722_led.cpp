#include <Arduino.h>

// 设置 LED 引脚
int ledPin = 12;

void TaskBlink(void *pvParameters) {
  pinMode(12, OUTPUT);
  while (1) {
    digitalWrite(12, HIGH);
    Serial.println("TaskBlink: LED ON");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    digitalWrite(12, LOW);
    Serial.println("TaskBlink: LED OFF");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void TaskSerial(void *pvParameters) {
  while (1) {
    Serial.println("TaskSerial: Running...");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  xTaskCreate(TaskBlink, "Blink", 2048, NULL, 1, NULL);

  xTaskCreate(TaskSerial, "Serial", 2048, NULL, 1, NULL);
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
