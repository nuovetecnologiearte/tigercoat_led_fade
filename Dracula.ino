int led = 3;    // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 3;    // how many points to fade the LED by

int led2 = 5;
int brightness2 = 75;
int fadeAmount2 = 3;

int led3 = 6;
int brightness3 = 150;
int fadeAmount3 = 3;

int led4 = 13;
int brightness4 = 225;
int fadeAmount4 = 3;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  analogWrite(led2, brightness2);
  analogWrite(led2, brightness2);
  analogWrite(led2, brightness2);

  if (brightness <=0){ delay(1000);}

  if (brightness2 <=0){delay(1000);}

  if (brightness3 <=0){delay(1000);}
  
  if (brightness4 <=0){delay(1000);}

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness2 = brightness2 + fadeAmount2;
  brightness3 = brightness3 + fadeAmount3;
  brightness4 = brightness4 + fadeAmount4;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {fadeAmount = -fadeAmount;}

  if (brightness2 <= 0 || brightness2 >= 255) {fadeAmount2 = -fadeAmount2;}

  if (brightness3 <= 0 || brightness3 >= 255) {fadeAmount3 = -fadeAmount3;}

  if (brightness4 <= 0 || brightness4 >= 255) {fadeAmount4 = -fadeAmount4;}

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
