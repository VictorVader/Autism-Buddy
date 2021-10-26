// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLvUOtRFp5"
#define BLYNK_DEVICE_NAME "Buddy"
#define BLYNK_AUTH_TOKEN "8uF1Imzyuh3Y0o9gN6-sfK9cNrT1hjd-"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

#include "FastLED.h"
#define NUM_LEDS 100
CRGB leds[NUM_LEDS];
#define PIN 7
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 8;

int value1 = 0;
int buttonState1 = 0;
int value2 = 0;
int buttonState2 = 0;
int value3 = 0;
int buttonState3 = 0;
int value4 = 0;
int buttonState4 = 0;
int value5 = 0;
int buttonState5 = 0;
int value6 = 0;
int buttonState6 = 0;

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HelloThere";
char pass[] = "minecraft";

unsigned long last_pressed = 0;
unsigned long current_millis = 0;
unsigned long interval_pause = 10000;

// This is the function that turns on the built-in LED and sends notification regarding its state
BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  
  if(pinValue == 1)
    Blynk.logEvent("test_event_led_on");
  else
    Blynk.logEvent("test_event_led_off");
  
  digitalWrite(LED_BUILTIN,pinValue);
}

// This function is for the parent's response
BLYNK_WRITE(V5)
{
  int pinValue2 = param.asInt();
  
  if(pinValue2 == 1){
    Blynk.logEvent("reply_to_buddy_on");
    FadeInOut(0x00, 0xff, 0xff);
  }    
}

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  Serial.begin(9600);
  // Debug console
  pinMode(LED_BUILTIN, OUTPUT); //pin 13
  
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  
  FastLED.addLeds<WS2812, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  fill_solid(leds, NUM_LEDS, CRGB(0,0,0));
  FastLED.show();
}

void loop() {
  Blynk.run();
  timer.run();

  current_millis = millis();
  if(current_millis - last_pressed > interval_pause)
  {
      value1 = digitalRead(buttonPin1);
      if(value1 == 0){
        value2 = digitalRead(buttonPin2);
        if(value2 == 0){
          value3 = digitalRead(buttonPin3);
          if(value3 == 0){
            value4 = digitalRead(buttonPin4);
            if(value4 == 0){
              value5 = digitalRead(buttonPin5);
              if(value5 == 0){
                value6 = digitalRead(buttonPin6);
              }
            }
          }
        }
      }
  }
   
  if(value1 == 1){
    Blynk.logEvent("happiness");
    last_pressed = current_millis;
    value1 = 0;
    buttonState1 = 1;
  } else if (buttonState1 == 1) {
   FadeInOut(0x95, 0xff, 0x00);//Happiness, Lime Green
   if(buttonState1 == 1)
    buttonState1 = 0;
    Serial.println(buttonState1);
  }
  
  if(value2 == 1) {
    Blynk.logEvent("anger");
    last_pressed = current_millis;
    value2 = 0;
    buttonState2 = 1;
  }else if(buttonState2 == 1){
   FadeInOut(0xff, 0x00, 0x00);//Anger, Red
   if(buttonState2 == 1)
    buttonState2 = 0;
    Serial.println(buttonState2);
  }

  if(value3 == 1) {
    Blynk.logEvent("sadness");
    last_pressed = current_millis;
    value3 = 0;
    buttonState3 = 1;
  }else if(buttonState3 == 1){
   FadeInOut(0x00, 0x00, 0xff);//Sadness, Blue
   if(buttonState3 == 1)
    buttonState3 = 0;
    Serial.println(buttonState3);
  }

   if(value4 == 1) {
    Blynk.logEvent("disgust");
    last_pressed = current_millis;
    value4 = 0;
    buttonState4 = 1;
  }else if(buttonState4 == 1){
   FadeInOut(0x05, 0x30, 0x01);//Disgust, Dark Green
   if(buttonState4 == 1)
    buttonState4 = 0;
    Serial.println(buttonState4);
  }

    if(value5 == 1) {
    Blynk.logEvent("fear");
    last_pressed = current_millis;
    value5 = 0;
    buttonState5 = 1;
  }else if(buttonState5 == 1){
   FadeInOut(0xa2, 0x00, 0xff);//Fear, Purple
   if(buttonState5 == 1)
    buttonState5 = 0;
    Serial.println(buttonState5);
  }

    if(value6 == 1) {
    Blynk.logEvent("leave_me_alone");
    last_pressed = current_millis;
    value6 = 0;
    buttonState6 = 1;
  }else if(buttonState6 == 1){
   FadeInOut(0x96, 0x4b, 0x00);//Leave me alone, Brown
   if(buttonState6 == 1)
    buttonState6 = 0;
    Serial.println(buttonState6);
  }
  
}

void FadeInOut(byte red, byte green, byte blue){
  float r, g, b;
     
  for(int k = 0; k < 256; k=k+1) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
   
  }
     
  for(int k = 255; k >= 0; k=k-2) {
    r = (k/256.0)*red;
    g = (k/256.0)*green;
    b = (k/256.0)*blue;
    setAll(r,g,b);
    
  }
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
