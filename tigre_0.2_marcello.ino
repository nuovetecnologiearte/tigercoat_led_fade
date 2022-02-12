#include <SimpleTimer.h>
#include <FadeLed.h>
#define elements(x) sizeof(x)/sizeof(x[0])
SimpleTimer timer;
FadeLed leds[] = {3, 5, 6};
bool check = false;
const int buttonPin = 2;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  leds[0].setTime(1000);
  leds[1].setTime(1000);
  leds[2].setTime(1000);
  timer.setInterval(1000, led0);
  timer.setInterval(1200, led1);
  timer.setInterval(1500, led2);
}

void loop() {
  FadeLed::update();
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    //Serial.println("high");
    check = true;
  } 
  if (check) {
    timer.run();
  }

  if ( ( leds[2].get() == 0  )) {
      //then we are done fading up, let's fade down again
        
        leds[0].off();
        leds[1].off();
        leds[2].off();
        Serial.println("sono a zero");
        check = false;
    }
}


void led0() {

  leds[0].set(255);
  if (leds[0].done()) {
 
    if (leds[0].get()) {
      leds[0].off();
    }
  }

}
void led1() {
  leds[1].set(255);
  if (leds[1].done()) {
    //.get() will return the current brightness
    //so this will tell us if we are not at 0
    if (leds[1].get()) {
      //then we are done fading up, let's fade down again
      leds[1].off();
    }
  }
}

void led2() {
  leds[2].set(255);
  if (leds[2].done()) {
    //.get() will return the current brightness
    //so this will tell us if we are not at 0
    if (leds[2].get()) {
      //then we are done fading up, let's fade down again
      leds[2].off();
    }
  }
  

}
