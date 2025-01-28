#include <Arduino.h>
#include <BleKeyboard.h>
BleKeyboard bleKeyboard("Naadi", "HID", 100);

#define LED_BUILTIN 2

void volumeIncrement();
void volumeDecrement();
void playMedia();
int myFunction(int, int);

void setup()
{
  int result = myFunction(2, 3);
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
    volumeIncrement();
    delay(5000);
    playMedia();
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

int myFunction(int x, int y)
{
  return x + y;
}