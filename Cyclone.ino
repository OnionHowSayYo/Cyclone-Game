// Initializing buttons and pins
int resetbutton = 13;
int redbutton = 2;
int yellowbutton = 12;
int selectedpin = 11;

// Initializing variables
int redbuttonholdtime = 0;
int yellowbuttonholdtime = 0;
int redplayerscore = 0;
int yellowplayerscore = 0;
int winning = 1;
int i;

boolean redbuttonpress = false;
boolean yellowbuttonpress = false;
boolean backwards = false;

// Reset Function, creates a custom reset button other than the one on the arduino board
void(* resetFunc) (void) = 0;





void setup() {

  // Declaring inputs
  pinMode(resetbutton, INPUT);
  pinMode(redbutton, INPUT);
  pinMode(yellowbutton, INPUT);

  // Declaring outputs of the LEDs
  for (i = 3; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }










  // Main Menu

  while(redbuttonholdtime < 5000 && yellowbuttonholdtime < 5000) {
    // To make a built in clock in the main menu so that the codes below acts out every 1s, also checks out for checking if the hold time is being pressed for 5 seconds
    delay(1000); 


    
    // A reset code
    if (digitalRead(resetbutton) == HIGH) {
      for (i = 3; i <= 11; i++) {
        digitalWrite(i, LOW);
      }
      resetFunc(); // Calling the reset Function
    }



    // Reading if red button is being pressed
    if (digitalRead(redbutton)) {
      redbuttonpress = true;
      redbuttonholdtime = redbuttonholdtime + 1000;
    }

    else {
      redbuttonpress = false;
      redbuttonholdtime = 0;
    }



    // Reading if yellow button is being pressed
    if (digitalRead(yellowbutton)) {
      yellowbuttonpress = true;
      yellowbuttonholdtime = yellowbuttonholdtime + 1000;
    }

    else {
      yellowbuttonpress = false;
      yellowbuttonholdtime = 0;
    }



    // Menu Lighting Program
    if (backwards == false) {
      
      if (selectedpin != 11) {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin - 1), LOW);
        selectedpin = selectedpin + 1;
      }

      else {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin - 1), LOW);
        selectedpin = selectedpin - 1;
        backwards = true;
      }
      
    }

    else {

      if (selectedpin != 3) {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin + 1), LOW);
        selectedpin = selectedpin - 1;
      }

      else {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin + 1), LOW);
        selectedpin = selectedpin + 1;
        backwards = false;
      }

    }
    
  }










  // Exit Main Menu Lighting Program
  for (int j = 0; j < 3; j++) {
    for (i = 3; i <=11; i++) {
      digitalWrite(i, LOW);
    }
    delay(500);
    
    for (i = 3; i <= 11; i++) {
      digitalWrite(i, HIGH);
    }
    delay(500);
  }

  // Reset all LEDs
  for (i = 3; i <= 11; i++) {
    digitalWrite(i, LOW);
  }
  
}










void loop() {

  // To make the system have a built in "clock" and repeat these codes every 50ms
  delay(50);

  // Reset Function
  if (digitalRead(resetbutton) == HIGH) {
    for (i = 3; i <= 11; i++) {
      digitalWrite(i, LOW);
    }
    resetFunc();
  }









  
  // Reading red button being pressed
  if (digitalRead(redbutton) == HIGH) {
    redbuttonpress = true;

    // Check if red player scores
    if (selectedpin == 11) {
      redplayerscore = redplayerscore + 1;

      // Check if red player wins
      if (redplayerscore >= 5) {
        for (i = 3; i <= 11; i++){
          digitalWrite(i, LOW);
        }

        // The winning lighting program, will keep going until reset button is pressed
        while (winning == 1) {

          digitalWrite(11, HIGH);
          delay(500);
          digitalWrite(11, LOW);
          delay(500);

          // test if reset button is pressed
          if (digitalRead(resetbutton) == HIGH) {
            for (i = 3; i <= 11; i++) {
              digitalWrite(i, LOW);
            }
            resetFunc();
          }
        } // end of while loop for lighting program for winning player
      } // end of if red player wins

      // Turn all LEDs off
      for (i = 3; i <= 11; i++) {
        digitalWrite(i, LOW);
      }

      // Lighting program if red player scores
      for (i = 1; i <= redplayerscore; i++) {
        digitalWrite(11, LOW);
        delay(500);
        digitalWrite(11, HIGH);
        delay(500);
      }
      
    } // end of if red player presses button on score LED

    // Turn off all LEDs
    for (i = 3; i <= 11; i++) {
      digitalWrite(i, LOW);
    }

    // Lighting program for if the red player presses the button but not on score LED
    digitalWrite(selectedpin, HIGH);
    delay(500);
    digitalWrite(selectedpin, LOW);
    
  } // End of if red player presses button

  else {
    redbuttonpress = false;
  }










  // Reading yellow button being pressed
  if (digitalRead(yellowbutton) == HIGH) {
    yellowbuttonpress = true;

    // Check if yellow player scores
    if (selectedpin == 3) {
      yellowplayerscore = yellowplayerscore + 1;

      // Check if yellow player wins
      if (yellowplayerscore >= 5) {
        for (i = 3; i <= 11; i++){
          digitalWrite(i, LOW);
        }

        // The winning lighting program, will keep going until reset button is pressed
        while (winning == 1) {

          digitalWrite(3, HIGH);
          delay(500);
          digitalWrite(3, LOW);
          delay(500);

          // test if reset button is pressed
          if (digitalRead(resetbutton) == HIGH) {
            for (i = 3; i <= 11; i++) {
              digitalWrite(i, LOW);
            }
            resetFunc();
          }
        } // end of while loop for lighting program for winning player
      } // end of if yellow player wins

      // Turn all LEDs off
      for (i = 3; i <= 11; i++) {
        digitalWrite(i, LOW);
      }

      // Lighting program if yellow player scores
      for (i = 1; i <= yellowplayerscore; i++) {
        digitalWrite(3, LOW);
        delay(500);
        digitalWrite(3, HIGH);
        delay(500);
      }
      
    } // end of if yellow player presses button on score LED

    // Turn off all LEDs
    for (i = 3; i <= 11; i++) {
      digitalWrite(i, LOW);
    }

    // Lighting program for if the yellow player presses the button but not on score LED
    digitalWrite(selectedpin, HIGH);
    delay(500);
    digitalWrite(selectedpin, LOW);
    
  } // End of if yellow player presses button

  else {
    yellowbuttonpress = false;
  }
 










    // Game Lighting Program
    if (backwards == false) {
      
      if (selectedpin != 11) {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin - 1), LOW);
        selectedpin = selectedpin + 1;
      }

      else {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin - 1), LOW);
        selectedpin = selectedpin - 1;
        backwards = true;
      }
      
    }

    else {

      if (selectedpin != 3) {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin + 1), LOW);
        selectedpin = selectedpin - 1;
      }

      else {
        digitalWrite(selectedpin, HIGH);
        digitalWrite((selectedpin + 1), LOW);
        selectedpin = selectedpin + 1;
        backwards = false;
      }

    }

  

}
