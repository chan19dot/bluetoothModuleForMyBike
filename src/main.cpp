#include <Arduino.h>
#include <BleKeyboard.h>
// #include <BleHIDDevice.h>
// #include <BLEServer.h>
// #include <BLEDevice.h>
BleKeyboard bleKeyboard("Naadi", "HID", 100);

#define LED_BUILTIN 2
// BLEHIDDevice *hid;
// BLECharacteristic *input;

void volumeIncrement();
void volumeDecrement();
void playMedia();
void liftCall();
void hangup();
void okGoogle();
void playnext();
void playPrevious();

// void sendConsumerReport(uint16_t cmd)
// {
//   uint8_t report[2];
//   report[0] = cmd & 0xFF;
//   report[1] = (cmd >> 8) & 0xFF;
//   input->setValue(report, 2);
//   input->notify();
//   delay(100);

//   report[0] = 0;
//   report[1] = 0;
//   input->setValue(report, 2);
//   input->notify();
// }

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello from the setup");
  bleKeyboard.begin();
  Serial.println("bluetooth Connection started............");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  if (bleKeyboard.isConnected())
  {
    Serial.println("Ze Bluetooth is connected Successfully");
    digitalWrite(LED_BUILTIN, HIGH);
    // volumeIncrement();
    liftCall();
    delay(5000);
    hangup();
    // playMedia();
  }
  else
  {
    Serial.println("Bluetooth not connected.");
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("HIGH");
    delay(1000);
    Serial.println("LOW");
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void volumeIncrement()
{
  bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
  delay(400);
  bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
  delay(200);
  bleKeyboard.releaseAll();
  Serial.println("Volume Increment Successful");
}

void volumeDecrement()
{
  bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  delay(400);
  bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
  bleKeyboard.releaseAll();
  Serial.println("Volume Decrement Successful");
}

void playMedia()
{
  bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  bleKeyboard.releaseAll();
  Serial.println("Play/Pause Operation Successful");
}

void liftCall()
{
  bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  bleKeyboard.releaseAll();
  Serial.println("lift call successful");
}

void hangup()
{
  // bleKeyboard.write(KEY_MEDIA_STOP);
  // bleKeyboard.releaseAll();
  // delay(1000);
  // sendConsumerReport(0x2F);
  Serial.println("hang up call successful");
}

void okGoogle()
{
}

void playnext()
{
  bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
  bleKeyboard.releaseAll();
  Serial.println("Play next");
}

void playPrevious()
{
  bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
  bleKeyboard.releaseAll();
  Serial.println("Play previous");
}
