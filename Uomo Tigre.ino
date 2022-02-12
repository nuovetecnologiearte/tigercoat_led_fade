const int numReadings = 20;
const int scarto = 50;

int readings[numReadings];  // the readings from the analog input
int readIndex = 0;        // the index of the current reading
int total = 0;          // the running total
int average = 0; 
int averaver = 0;     // the average
long averagetot;
int soglia;

int inputPin = A0;

int incr=0;
int counter=0;


void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}

SIGNAL(TIMER0_COMPA_vect) 
{
  incr = incr+1;

  if ( ( incr < 500)) {

    aver();

}
  if (incr = 10000) { 

    incr = 0;

  }
}

void aver() {

    // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  total=0;
  averagetot = averagetot + average;
  counter = counter + 1;

  if (counter == 500){
    
    soglia = (averagetot / 500) - scarto;
    Serial.println(soglia);
    counter = 0;
    averagetot = 0;
  }

}



void loop() {
  
  // put your main code here, to run repeatedly:

}
