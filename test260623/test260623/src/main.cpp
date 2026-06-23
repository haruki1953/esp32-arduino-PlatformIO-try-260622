#include <Arduino.h>

// 设置 LED 引脚
int ledPin = 12;

void setup() {
  // 设定引脚为输出模式
  pinMode(ledPin, OUTPUT);

  // 初始化串口，波特率 115200（ESP32 常用）
  Serial.begin(115200);

  // 等待串口连接（可选）
  delay(1000);
  Serial.println("ESP32 已启动，开始闪烁 LED...");
}

void loop() {
  // 点亮 LED
  digitalWrite(ledPin, HIGH);
  Serial.println("LED 已点亮aaaa");
  // 等待一段时间
  delay(1000);
  
  // 关闭 LED
  digitalWrite(ledPin, LOW);
  Serial.println("LED 已关闭aaaa");
  // 等待一段时间
  delay(1000);
}


// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }