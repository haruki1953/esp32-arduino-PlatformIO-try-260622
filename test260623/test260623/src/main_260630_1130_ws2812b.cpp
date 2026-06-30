// fastled/FastLED@3.10.3
// https://github.com/FastLED/FastLED
#include <FastLED.h>

// ---------------------------------------------------------
// WS2812B 灯带硬件配置
// ---------------------------------------------------------
#define LED_PIN 18   // ESP32 GPIO18
#define LED_COUNT 30 // 灯珠数量
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[LED_COUNT];

// ---------------------------------------------------------
// 颜色数组
// ---------------------------------------------------------
CRGB COLOR_LIST[] = {
    CRGB(255, 0, 0),   CRGB(255, 32, 0),  CRGB(255, 64, 0),  CRGB(255, 96, 0),
    CRGB(255, 128, 0), CRGB(255, 160, 0), CRGB(255, 192, 0), CRGB(255, 224, 0),
    CRGB(255, 255, 0), CRGB(224, 255, 0), CRGB(192, 255, 0), CRGB(160, 255, 0),
    CRGB(128, 255, 0), CRGB(96, 255, 0),  CRGB(64, 255, 0),  CRGB(32, 255, 0),
    CRGB(0, 255, 0),   CRGB(0, 255, 32),  CRGB(0, 255, 64),  CRGB(0, 255, 96),
    CRGB(0, 255, 128), CRGB(0, 255, 160), CRGB(0, 255, 192), CRGB(0, 255, 224),
    CRGB(0, 255, 255), CRGB(0, 224, 255), CRGB(0, 192, 255), CRGB(0, 160, 255),
    CRGB(0, 128, 255), CRGB(0, 96, 255),  CRGB(0, 64, 255),  CRGB(0, 32, 255),
    CRGB(0, 0, 255),   CRGB(32, 0, 255),  CRGB(64, 0, 255),  CRGB(96, 0, 255),
    CRGB(128, 0, 255), CRGB(160, 0, 255), CRGB(192, 0, 255), CRGB(224, 0, 255),
    CRGB(255, 0, 255), CRGB(255, 0, 224), CRGB(255, 0, 192), CRGB(255, 0, 160),
    CRGB(255, 0, 128), CRGB(255, 0, 96),  CRGB(255, 0, 64)};

const int COLOR_COUNT = sizeof(COLOR_LIST) / sizeof(CRGB);

// ---------------------------------------------------------
// 主程序
// ---------------------------------------------------------
void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, LED_COUNT);
  FastLED.setBrightness(16); // 与 Python 版本一致
}

void loop() {
  static int idx = 0;

  // 设置所有灯珠为当前颜色
  for (int i = 0; i < LED_COUNT; i++) {
    leds[i] = COLOR_LIST[idx];
  }

  FastLED.show();

  // 下一个颜色
  idx = (idx + 1) % COLOR_COUNT;

  delay(50); // 0.05 秒
}
