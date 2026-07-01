#include <Arduino.h>
// mathertel/OneButton@2.6.2
// https://github.com/mathertel/OneButton
#include <OneButton.h>

// 定义按键 GPIO（你的接线：GPIO --- 按键 --- GND）
// OneButton btn_up(6, true);    // 亮度增加
OneButton btn_down(15, true); // 亮度减少
// OneButton btn_mode(19, true); // 模式切换
// OneButton btn_call(26, true); // 呼叫按键

void setup() {
  Serial.begin(115200);
  Serial.println("按键测试启动，按下任意按键试试…");

  // 事件绑定（按下触发）
  // btn_up.attachClick([]() { Serial.println("亮度增加键 按下"); });

  btn_down.attachClick([]() { Serial.println("亮度减少键 按下"); });

  // btn_mode.attachClick([]() { Serial.println("模式切换键 按下"); });

  // btn_call.attachClick([]() { Serial.println("呼叫键 按下"); });
}

void loop() {
  // OneButton 需要在 loop 中不断 tick()
  // btn_up.tick();
  btn_down.tick();
  // btn_mode.tick();
  // btn_call.tick();
}
