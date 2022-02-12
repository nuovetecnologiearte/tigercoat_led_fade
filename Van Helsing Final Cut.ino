#include <SimpleTimer.h>
SimpleTimer timer;



class Fader {
  // Class Member Variables
  // These are initialized at startup
  int ledPin;  // the number of the LED pin


  // define directions for LED fade
  #define UP 0
  #define DOWN 1

  // constants for min and max PWM
  const int minPWM = 0;
  const int maxPWM = 255;

  // State Variable for Fade Direction
  byte fadeDirection = UP;

  // Global Fade Value
  // but be bigger than byte and signed, for rollover
  int fadeValue = 0;

  // How smooth to fade?
  byte fadeIncrement = 5;

  // millis() timing Variable, just for fading
  unsigned long previousFadeMillis;

  // How fast to increment?
  int fadeInterval = 50;


  // Constructor - creates a Flasher
  // and initializes the member variables and state
  public:
    Fader(int pin) {
     ledPin = pin;
     pinMode(ledPin, OUTPUT);
    }


  void Update(unsigned long currentMillis) {
    // is it time to update yet?
    // if not, nothing happens
    if (currentMillis - previousFadeMillis >= fadeInterval) {
      // yup, it's time!
      if (fadeDirection == UP) {
        fadeValue = fadeValue + fadeIncrement;
        if (fadeValue >= maxPWM) {
          // At max, limit and change direction
          fadeValue = maxPWM;
          fadeDirection = DOWN;
        }
      } else {
        //if we aren't going up, we're going down
        fadeValue = fadeValue - fadeIncrement;
        if (fadeValue <= minPWM) {
          // At min, limit and change direction
          fadeValue = minPWM;
          //fadeDirection = UP;
        }
      }
      // Only need to update when it changes
      analogWrite(ledPin, fadeValue);

      // reset millis for the next iteration (fade timer only)
      previousFadeMillis = currentMillis;
    }
  }
};

bool check = false;
const int buttonPin = 2;
int buttonState = 0;

void buttonReset(){

  check=false;
  buttonState=0;

}

//#define EXE_INTERVAL_1 1000
//#define EXE_INTERVAL_2 2000

//#define INTERRUPTION_1 5100
//#define INTERRUPTION_2 6100
//#define INTERRUPTION_3 7100

Fader led1(3);
Fader led2(5);
Fader led3(6);

void setup()
{
  timer.setInterval(10000, buttonReset);
  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();
  long interval;

  Serial.println(check);

  if (!(check)) {
    buttonState = digitalRead(buttonPin);
  }

  if (buttonState) {
    check = true;
    timer.run();     
    //Serial.println("high");
      }  

  if(check){
          
      led1.Update(currentMillis);

    //if (currentMillis >= EXE_INTERVAL_1) {
   
      led2.Update(currentMillis);

    //}

    //if (currentMillis >= EXE_INTERVAL_2) {
   
     led3.Update(currentMillis);

    //}
  } 
}