// Interval is how long we wait
// add const if this should never change
int interval = 600000;
// Tracks the time since last event fired
unsigned long previousMillis=0;

const int numReadings = 20;
const int scarto = 50;

int readings1;          // the readings from the analog input
int readIndex1 = 0;     // the index of the current reading
int total1 = 0;         // the running total
int readings2;          // the readings from the analog input
int readIndex2 = 0;     // the index of the current reading
int total2 = 0;         // the running total
int average1 = 0;      // the average
int average2 = 0;

int led1=2;
int led2=3;
int led3=4;
int led4=5;
int led5=6;
int led6=7;
int led7=8;
int led8=9;
int led9=10;
int led10=11;
int led11=12;
int led12=13;

int velocita = 10;
int fade = 5;
int soglia1;
int soglia2;

bool check1 = false;
bool check2 = false;
//const int buttonPin = 2;
//int buttonState = 0;


void aver1() {


  for (readIndex1 = 0; readIndex1 < numReadings; readIndex1 = readIndex1 + 1) {

    // read from the sensor:
    readings1 = analogRead(A0);
    
    // add the reading to the total:
    total1 = total1 + readings1;
  }
   // when we're at the end of the array wrap around to the beginning:
    readIndex1 = 0;

    // calculate the average:

      average1 = total1 / numReadings;
      Serial.println(average1);
      Serial.println("----------");
    total1 = 0;
}

void aver2() {


  for(readIndex2 = 0; readIndex2 < numReadings; readIndex2 = readIndex2 + 1) {

    // read from the sensor:
    readings2 = analogRead(A1);
    
    // add the reading to the total:
    total2 = total2 + readings2;
  }
   // when we're at the end of the array wrap around to the beginning:
    readIndex2 = 0;

    // calculate the average:

      average2 = total2 / numReadings;
      Serial.println(average2);
      Serial.println("_____________");
    total2 = 0;
}

void setup() {

  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  aver1();
  aver2();
}
 
void loop() {

  soglia1 = analogRead(A0);
  soglia2 = analogRead(A1);
  
   // Get snapshot of time
   unsigned long currentMillis = millis();
 
   // How much time has passed, accounting for rollover with subtraction!
   if ((unsigned long)(currentMillis - previousMillis) >= interval) {
      // It's time to do something!
      aver1();
      aver2();
 
      // Use the snapshot to set track time until next event
      previousMillis = currentMillis;

   }

  if (soglia1 < average1 - scarto && soglia1 < soglia2) {

    check1 = true;
    check2 = false;
  }
  else if (soglia2 < average2 - scarto && soglia2 < soglia1){

    check1 = false;
    check2 = true;
  }
  else {

    check1 = false;
    check2 = false;
  }

  if (check1){

    for (int value = 0; value <= 1355; value += fade){
      
      if (value <= 255){
        analogWrite(led1, value);
      }

      if (value >= 100 && value <= 355){
        analogWrite(led2, value-100);
      }

      if (value >= 200 && value <= 455){
        analogWrite(led3, value-200);
      }

      if (value >= 300 && value <= 555){
        analogWrite(led4, value-300);
      }

      if (value >= 400 && value <= 655){
        analogWrite(led5, value - 400);
      }

      if (value >= 500 && value <= 755){
        analogWrite(led6, value - 500);
      }

      if (value >= 600 && value <= 855){
        analogWrite(led7, value - 600);
      }

      if (value >= 700 && value <= 955){
        analogWrite(led8, value - 700);
      }

      if (value >= 800 && value <= 1055){
        analogWrite(led9, value - 800);
      }
      if (value >= 900 && value <= 1155){
        analogWrite(led10, value - 900);
      }  

      if (value >= 1000 && value <= 1255){
        analogWrite(led11, value - 1000);
      }

      if (value >= 1100 && value <= 1355){
        analogWrite(led12, value - 1100);
      }   

      delay(velocita);
    }

    for (int value = 1355; value >= 0; value -= fade){
     
      if (value<= 1355 && value >= 1100){
        analogWrite(led1, value - 1100);
     }

      if (value<= 1255 && value >= 1000){
        analogWrite(led2, value - 1000);
     }

      if (value<= 1155 && value >= 900){
        analogWrite(led3, value - 900);
     }

      if (value <= 1055 && value >= 800){
        analogWrite(led4, value - 800);
     }

      if (value <= 955 && value >= 700){
        analogWrite(led5, value - 700);
     }

      if (value <= 855 && value >= 600){
        analogWrite(led6, value - 600);
     }

      if (value <= 755 && value >= 500){
        analogWrite(led7, value - 500);
     }

      if (value <= 655 && value >= 400){
        analogWrite(led8, value - 400);
     }                               

      if (value <= 555 && value >= 300){
        analogWrite(led9, value - 300);
    }

      if (value <= 455 && value >= 200){
        analogWrite(led10, value - 200);
    }

      if (value <= 355 && value >= 100){
        analogWrite(led11, value - 100);
     }
      if (value <= 255){
        analogWrite(led12, value);
     }
      delay(velocita);
     }
    }

  if (check2){
    for (int value = 0; value <= 1355; value += fade){
      
      if (value <= 255){
        analogWrite(led12, value);
      }
      if (value >= 100 && value <= 355){
        analogWrite(led11, value-100);
      }
      if (value >= 200 && value <= 455){
        analogWrite(led10, value-200);
      }
      if (value >= 300 && value <= 555){
        analogWrite(led9, value-300);
      }
      if (value >= 400 && value <= 655){
        analogWrite(led8, value-400);
      }
      if (value >= 500 && value <= 755){
        analogWrite(led7, value-500);
      }
      if (value >= 600 && value <= 855){
        analogWrite(led6, value - 600);
      }
      if (value >= 700 && value <= 955){
        analogWrite(led5, value - 700);
      }
      if (value >= 800 && value <= 1055){
        analogWrite(led4, value - 800);
      }
      if (value >= 900 && value <= 1155){
        analogWrite(led3, value - 900);
      }
      if (value >= 1000 && value <= 1255){
        analogWrite(led2, value - 1000);
      }
      if (value >= 1100 && value <= 1355){
        analogWrite(led1, value - 1100);
      }                  
      delay(velocita);
    }
    for (int value = 1355; value >= 0; value -= fade){

      if (value<= 1355 && value >= 1100){
        analogWrite(led12, value - 1100);
     }
      if (value <= 1255 && value >= 1000){
        analogWrite(led11, value - 1000);
     }
      if (value <= 1155 && value >= 900){
        analogWrite(led10, value - 900);
     }
      if (value <= 1055 && value >= 800){
        analogWrite(led9, value - 800);
     }
      if (value <= 955 && value >= 700){
        analogWrite(led8, value - 700);
     }
      if (value <= 855 && value >= 600){
        analogWrite(led7, value - 600);
     }                               
      if (value <= 755 && value >= 500){
        analogWrite(led6, value - 500);
       }
      if (value <= 655 && value >= 400){
        analogWrite(led5, value - 400);
       }
      if (value <= 555 && value >= 300){
        analogWrite(led4, value - 300);
     }
      if (value <= 455 && value >= 200){
        analogWrite(led3, value - 200);
     }
      if (value <= 355 && value >= 100){
        analogWrite(led2, value - 100);
     }
      if (value <= 255){
        analogWrite(led1, value);
     }
      delay(velocita);
     }
    }    
  check1 = false;
  check2 = false;

}