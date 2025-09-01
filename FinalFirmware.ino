#include <BleKeyboard.h>

// Battery precentage logic
const int batteryPin = 35; // ADC pin for battery divider
unsigned long lastBatteryUpdate = 0;
const unsigned long batteryUpdateInterval = 30000; // 30s

float readBatteryVoltage() {
  int raw = analogRead(batteryPin);
  float voltage = raw / 4095.0 * 3.3 * 2; // 10k:10k resistor divider calc
  return voltage;
}

int getBatteryPercent() {
  float voltage = readBatteryVoltage();
  int percent = (voltage - 3.3) / (4.2 - 3.3) * 100;
  if (percent > 100) percent = 100;
  if (percent < 0) percent = 0;
  return percent;
}

// BLE keyboard initialization with battery precentage
BleKeyboard bleKeyboard("StreamDeck", "Maksotm", getBatteryPercent());

// Buttons
const int buttonPins[8] = {23, 22, 21, 19, 18, 5, 17, 16};
int lastButtonState[8];
unsigned long lastButtonTime[8];
const unsigned long debounceDelay = 50; // 50 ms debounce

const uint8_t buttonKeys[8] = {KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8};

// Encoder 1
const int enc1A = 32;
const int enc1B = 33;
const int enc1Btn = 25;
int lastEnc1Btn = HIGH;
int lastEnc1A = HIGH;
unsigned long lastEnc1Time = 0;

// Encoder 2
const int enc2A = 26;
const int enc2B = 27;
const int enc2Btn = 14;
int lastEnc2Btn = HIGH;
int lastEnc2A = HIGH;
unsigned long lastEnc2Time = 0;

void setup() {
  bleKeyboard.begin();

  for (int i = 0; i < 8; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    lastButtonState[i] = HIGH;
    lastButtonTime[i] = 0;
  }

  pinMode(enc1A, INPUT_PULLUP);
  pinMode(enc1B, INPUT_PULLUP);
  pinMode(enc1Btn, INPUT_PULLUP);

  pinMode(enc2A, INPUT_PULLUP);
  pinMode(enc2B, INPUT_PULLUP);
  pinMode(enc2Btn, INPUT_PULLUP);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    unsigned long currentTime = millis();

    // -Battery update every 30s
    if (currentTime - lastBatteryUpdate > batteryUpdateInterval) {
      int percent = getBatteryPercent();
      bleKeyboard.setBatteryLevel(percent);
      lastBatteryUpdate = currentTime;
    }

    // Buttons (debounce added)
    for (int i = 0; i < 8; i++) {
      int state = digitalRead(buttonPins[i]);
      if (state != lastButtonState[i] && (currentTime - lastButtonTime[i] > debounceDelay)) {
        lastButtonState[i] = state;
        lastButtonTime[i] = currentTime;
        if (state == LOW) {
          bleKeyboard.press(KEY_LEFT_SHIFT);
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press(KEY_LEFT_ALT);
          bleKeyboard.press(buttonKeys[i]);
        } else {
          bleKeyboard.release(buttonKeys[i]);
          bleKeyboard.release(KEY_LEFT_SHIFT);
          bleKeyboard.release(KEY_LEFT_CTRL);
          bleKeyboard.release(KEY_LEFT_ALT);
        }
      }
    }

    // Encoder 1 (vol)
    int enc1AState = digitalRead(enc1A);
    if (enc1AState != lastEnc1A && enc1AState == LOW) {
      if (digitalRead(enc1B) == LOW) {
        bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
      } else {
        bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
      }
    }
    lastEnc1A = enc1AState;

    // Encoder button 1 (Debounce added)
    int enc1BtnState = digitalRead(enc1Btn);
    if (enc1BtnState != lastEnc1Btn && (currentTime - lastEnc1Time > debounceDelay)) {
      lastEnc1Btn = enc1BtnState;
      lastEnc1Time = currentTime;
      if (enc1BtnState == LOW) {
        bleKeyboard.write(KEY_MEDIA_MUTE);
      }
    }

    // Encoder 2
    int enc2AState = digitalRead(enc2A);
    if (enc2AState != lastEnc2A && enc2AState == LOW) {
      if (digitalRead(enc2B) == LOW) {
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_F9);
        bleKeyboard.release(KEY_F9);
        bleKeyboard.release(KEY_LEFT_SHIFT);
        bleKeyboard.release(KEY_LEFT_CTRL);
        bleKeyboard.release(KEY_LEFT_ALT);
      } else {
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_F10);
        bleKeyboard.release(KEY_F10);
        bleKeyboard.release(KEY_LEFT_SHIFT);
        bleKeyboard.release(KEY_LEFT_CTRL);
        bleKeyboard.release(KEY_LEFT_ALT);
      }
    }
    lastEnc2A = enc2AState;

    // Encoder button 2 (Debounce added)
    int enc2BtnState = digitalRead(enc2Btn);
    if (enc2BtnState != lastEnc2Btn && (currentTime - lastEnc2Time > debounceDelay)) {
      lastEnc2Btn = enc2BtnState;
      lastEnc2Time = currentTime;
      if (enc2BtnState == LOW) {
        bleKeyboard.press(KEY_LEFT_SHIFT);
        bleKeyboard.press(KEY_LEFT_CTRL);
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press(KEY_F11);
        bleKeyboard.release(KEY_F11);
        bleKeyboard.release(KEY_LEFT_SHIFT);
        bleKeyboard.release(KEY_LEFT_CTRL);
        bleKeyboard.release(KEY_LEFT_ALT);
      }
    }
  }
}
