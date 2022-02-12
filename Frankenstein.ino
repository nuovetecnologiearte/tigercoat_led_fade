#include <FastLED.h>    // if not found, get it here http://fastled.io/
#define NUM_LEDS 50
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

float val;
float start;
float rosso, verde, blu;
int i;

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void setup() {
  
    
    delay(2000);
    Serial.begin(9600);
    FastLED.addLeds<GS1903, DATA_PIN, BRG>(leds, NUM_LEDS);           // Assafà
    start = analogRead(A0);
}

void loop() {
  val = analogRead(A0);
  Serial.println(analogRead(A0));
 
  rosso = mapfloat(val, start, 200, 0, 255);
  verde = mapfloat(val, start, 290, 0, 255);
  blu = mapfloat(val, start, 100, 0, 255);

  for (int i = 0; i < NUM_LEDS; i ++) {
    if (analogRead(A0)>200){
      leds[i].r   = rosso;
      leds[i].g   = verde;
      leds[i].b   = blu;
      //leds[i] = CRGB::Purple;
      FastLED.show();
      delay(40);
      //leds[i]= CRGB::Black;
    }
     else{
        leds[i]= CRGB::Black;
        FastLED.show();
        delay(40);
    }
  }
}
