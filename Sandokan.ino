int led1=4;
int led2=5;
int led3=6;
int led4=7;
int led5=8;
int led6=9;
int led7=10;
int led8=11;
int led9=12;
int led10=13;

int velocita=10;
int soglia1;
int soglia2;

bool check1 = false;
bool check2 = false;
//const int buttonPin = 2;
//int buttonState = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  soglia1 = analogRead(A0);
  soglia2 = analogRead(A1);
  Serial.println(soglia1);
  Serial.println(soglia2);
   // buttonState = digitalRead(buttonPin);

  if (soglia1 < 150 && soglia1 < soglia2) {
    check1 = true;
    check2 = false;
  }
  if (soglia2 < 150 && soglia2 < soglia1){
    check1 = false;
    check2 = true;
  }
  else {
    check1 = false;
    check2 = false;
  }

  if (check1){
    for (int value = 0; value <= 1155; value += 5){
      
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
      delay(velocita);
    }
    for (int value = 1155; value >= 0; value -= 5){

      if (value<= 1155 && value >= 900){
        analogWrite(led1, value - 900);
     }
      if (value <= 1055 && value >= 800){
        analogWrite(led2, value - 800);
     }
      if (value <= 955 && value >= 700){
        analogWrite(led3, value - 700);
     }
      if (value <= 855 && value >= 600){
        analogWrite(led4, value - 600);
     }
      if (value <= 755 && value >= 500){
        analogWrite(led5, value - 500);
     }
      if (value <= 655 && value >= 400){
        analogWrite(led6, value - 400);
     }                               
      if (value <= 555 && value >= 300){
        analogWrite(led7, value - 300);
       }
      if (value <= 455 && value >= 200){
        analogWrite(led8, value - 200);
       }
      if (value <= 355 && value >= 100){
        analogWrite(led9, value - 100);
     }
      if (value <= 255){
        analogWrite(led10, value);
     }
      delay(velocita);
     }
    }

  if (check2){
    for (int value = 0; value <= 1155; value += 5){
      
      if (value <= 255){
        analogWrite(led10, value);
      }
      if (value >= 100 && value <= 355){
        analogWrite(led9, value-100);
      }
      if (value >= 200 && value <= 455){
        analogWrite(led8, value-200);
      }
      if (value >= 300 && value <= 555){
        analogWrite(led7, value-300);
      }
      if (value >= 400 && value <= 655){
        analogWrite(led6, value - 400);
      }
      if (value >= 500 && value <= 755){
        analogWrite(led5, value - 500);
      }
      if (value >= 600 && value <= 855){
        analogWrite(led4, value - 600);
      }
      if (value >= 700 && value <= 955){
        analogWrite(led3, value - 700);
      }
      if (value >= 800 && value <= 1055){
        analogWrite(led2, value - 800);
      }
      if (value >= 900 && value <= 1155){
        analogWrite(led1, value - 900);
      }                  
      delay(velocita);
    }
    for (int value = 1155; value >= 0; value -= 5){

      if (value<= 1155 && value >= 900){
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