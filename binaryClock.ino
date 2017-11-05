#include <Time.h>
#include <TimeLib.h>


  // initialize variables to store time
  int seconds = 0;  
  int minutes = 0; 
  int hours = 0;

  // initalize buttons to increment time
  int min_button = 50;
  int hr_button = 51;

  // iniatlize buttons to set light shows
  int randomize_button = 52;
  int wave_button = 53;

  // inialize output pin variables
  // change the values here for pin layout
  
  // seconds
  int led1 = 22;
  int led2 = 23;
  int led3 = 24;
  int led4 = 25;
  int led5 = 26;
  int led6 = 27;
  int led7 = 28; 
  // minutes
  int led8 = 29;
  int led9 = 30;
  int led10 = 31;
  int led11 = 32;
  int led12 = 33;
  int led13 = 34;
  int led14 = 35;
  // hours
  int led15 = 36;
  int led16 = 37;
  int led17 = 38;
  int led18 = 39;
  int led19 = 40;
  int led20 = 41;

  int AM_PM = 0; // AM == 0 and PM == 1

void setup() {
  // initialize output pins for seconds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  // initialize output pins for minutes
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(led14, OUTPUT);

  // initialize output pins for hours
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(led19, OUTPUT);
  pinMode(led20, OUTPUT);

  // initalize input pins for inc buttons
  pinMode(min_button, INPUT);
  pinMode(hr_button, INPUT);
    
}

// take as input time in sec, min, hr as ints and then output to Binary LED layout
void UpdateDisplay(int seconds, int minutes, int hours) {

  /* Seconds Count */

  int seconds_ones = 0;
  int seconds_tens = 0;
  
  //find seconds ones and tens
  seconds_ones = seconds % 10;
  seconds_tens = seconds / 10;
    
  // seconds 0-9 counter
  switch(seconds_ones) {
    case 0:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      break;
    case 1:
      digitalWrite(led1, HIGH);
      break;
    case 2:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      break;
    case 3:
      digitalWrite(led1, HIGH);
      break;
    case 4:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      break;
    case 5:
      digitalWrite(led1, HIGH);
      break;
    case 6:
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      break;
    case 7:
      digitalWrite(led1, HIGH);
      break;
    case 8:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      break;
    case 9:
      digitalWrite(led1, HIGH);
      break;
                         
    }


  // seconds 10-50 counter
  switch(seconds_tens) {
    case 1:
      digitalWrite(led5, HIGH);
      break;
    case 2: 
      digitalWrite(led5, LOW);
      digitalWrite(led6, HIGH);
      break;
    case 3:
      digitalWrite(led5, HIGH);
      break;
    case 4: 
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, HIGH);
      break;
    case 5:
      digitalWrite(led5, HIGH);
      break;
    case 6:
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
      digitalWrite(led7, LOW);
      break;         
  }

  // case to reset seconds after 59 have elapsed
  if (seconds_tens < 1) {
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);   
  }

  /* Minutes Count */
  
  int minutes_ones = 0;
  int minutes_tens = 0;
  
  //find minutes ones and tens
  minutes_ones = minutes % 10;
  minutes_tens = minutes / 10;

  // minutes 0-9 counter
  switch(minutes_ones) {
    case 0:
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
      digitalWrite(led11, LOW);
      break;
    case 1:
      digitalWrite(led8, HIGH);
      break;
    case 2:
      digitalWrite(led8, LOW);
      digitalWrite(led9, HIGH);
      break;
    case 3:
      digitalWrite(led8, HIGH);
      break;
    case 4:
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, HIGH);
      break;
    case 5:
      digitalWrite(led8, HIGH);
      break;
    case 6:
      digitalWrite(led8, LOW);
      digitalWrite(led9, HIGH);
      break;
    case 7:
      digitalWrite(led8, HIGH);
      break;
    case 8:
      digitalWrite(led8, LOW);
      digitalWrite(led9, LOW);
      digitalWrite(led10, LOW);
      digitalWrite(led11, HIGH);
     break;
    case 9:
      digitalWrite(led8, HIGH);
      break;
                         
    }


  // minutes 10-50 counter
  switch(minutes_tens) {
    case 1:
      digitalWrite(led12, HIGH);
      break;
    case 2: 
      digitalWrite(led12, LOW);
      digitalWrite(led13, HIGH);
      break;
    case 3:
      digitalWrite(led12, HIGH);
      break;
    case 4: 
      digitalWrite(led12, LOW);
      digitalWrite(led13, LOW);
      digitalWrite(led14, HIGH);
      break;
    case 5:
      digitalWrite(led12, HIGH);
      break;
    case 6:
      digitalWrite(led12, LOW);
      digitalWrite(led13, LOW);
      digitalWrite(led14, LOW);
      break;         
  }

  // case to resent minutes after 59 have elapsed
  if (minutes_tens < 1) {
    digitalWrite(led12, LOW);
    digitalWrite(led13, LOW);
    digitalWrite(led14, LOW);   
  }


  /* Hours Count */
  
  int hours_ones = hours % 10;
  int hours_tens = hours / 10; 
  
  switch(hours_ones) {
    case 0:
      digitalWrite(led15, LOW);
      digitalWrite(led16, LOW);
      digitalWrite(led17, LOW);
      digitalWrite(led18, LOW);
      break;
    case 1:
      digitalWrite(led15, HIGH);
      break;
    case 2:
      digitalWrite(led15, LOW);
      digitalWrite(led16, HIGH);
      break;
    case 3:
      digitalWrite(led15, HIGH);
      break;
    case 4:
      digitalWrite(led15, LOW);
      digitalWrite(led16, LOW);
      digitalWrite(led17, HIGH);
      break;
    case 5:
      digitalWrite(led15, HIGH);
      break;
    case 6:
      digitalWrite(led15, LOW);
      digitalWrite(led16, HIGH);
      break;
    case 7:
      digitalWrite(led15, HIGH);
      break;
    case 8:
      digitalWrite(led15, LOW);
      digitalWrite(led16, LOW);
      digitalWrite(led17, LOW);
      digitalWrite(led18, HIGH);
      break;
    case 9:
      digitalWrite(led15, HIGH);
      break;                     
    }


  // hours 10-50 counter
  switch(hours_tens) {
    case 1:
      digitalWrite(led19, HIGH);
      break;
    case 2: 
      digitalWrite(led19, LOW);
      digitalWrite(led20, HIGH);
      break;
  
  }

  // case to reset hours after 23 have elapsed
  if (hours_tens < 1) {
    digitalWrite(led19, LOW);
    digitalWrite(led20, LOW);  

  }
}
// function to reset the display after entering another mode
void ResetDisplay() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
  digitalWrite(led13, LOW);
  digitalWrite(led14, LOW);
  digitalWrite(led15, LOW);
  digitalWrite(led16, LOW);
  digitalWrite(led17, LOW);
  digitalWrite(led18, LOW);
  digitalWrite(led19, LOW);
  digitalWrite(led20, LOW);
}

// code to make a randomized light shown
void Randomize() {

  // to be added
 
}

// code for the audio visualizer
void Wave() {

  // to be added
    
  }

  
void loop() {

  // get user input from push buttons
  if (digitalRead(min_button) == LOW) {
    adjustTime(60); // add 60sec or 1 min
    }
     
  if (digitalRead(hr_button) == LOW) {
    adjustTime(3600); // add 3600 sec or 1 hr
  }

  if (digitalRead(randomize_button) == LOW) {
    Randomize();
  }

  if (digitalRead(wave_button) == LOW) {
    Wave();
  }
  
  // get new time and update display
  seconds = second();
  minutes = minute();
  hours = hour();

  UpdateDisplay(seconds, minutes, hours);
  delay(100);     


}



