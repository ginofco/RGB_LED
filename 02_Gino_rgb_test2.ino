
/*
 * RGB LED test
 */
int bright_red = 0;    // how bright the RED LED is
int bright_green = 0;    // how bright the GREEN LED is
int bright_blue = 0;    // how bright the BLUE LED is
int fadeAmount_red = 5;    // how many points to fade the LED by
int fadeAmount_green = 5;    // how many points to fade the LED by
int fadeAmount_blue = 5;    // how many points to fade the LED by

int LED_RED = 3;   // PWM pin for red LED
int LED_GREEN = 5; // PWM pin for green LED
int LED_BLUE = 6;  // PWM pin for blue LED


void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  bright_red = 254; fadeAmount_red = -1;
  bright_green = 0; fadeAmount_green = 1;
  for (int i=1;i<255;i++) {
  
    analogWrite(LED_RED,   bright_red);
    analogWrite(LED_GREEN, bright_green);

    bright_red   = bright_red   + fadeAmount_red;
    bright_green = bright_green + fadeAmount_green;

    delay(30);
  }

  bright_green = 254; fadeAmount_green = -1;
  bright_blue  = 0;   fadeAmount_blue = 1;
  for (int i=1;i<255;i++) { 

    analogWrite(LED_GREEN, bright_green);
    analogWrite(LED_BLUE, bright_blue);

    bright_green = bright_green + fadeAmount_green;
    bright_blue = bright_blue + fadeAmount_blue;

    delay(20);
  }
  
  bright_blue = 254; fadeAmount_blue = -1;
  bright_red  = 0;   fadeAmount_red = 1;
  for (int i=1;i<255;i++) { 
    
    analogWrite(LED_BLUE, bright_blue);
    analogWrite(LED_RED,  bright_red);

    bright_blue = bright_blue + fadeAmount_blue;
    bright_red = bright_red + fadeAmount_red;

    delay(10);
  }
 
}
