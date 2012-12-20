#include <SoftwareSerial.h> //Loads the software serial library
int inputPin = 2;           //Sets the input pin as 2 on the arduino
int pirState = LOW;        // Assumes that the PIR sensor isn't sensing anything
int message = 0;            //A variable that allows us to set the value of the sensor
SoftwareSerial lcd = SoftwareSerial(2, 6); //Sets the ouput pins for the LCD and speaker (For me, these are on the same board)
String ds;
 
void setup(){
      
  lcd.begin(9600);                          //start serial connection, so we can see the printed message on the LCD
      pinMode(inputPin, INPUT);            //Sets the PIR sensor as an INPUT to the arduino board
      lcd.write(12);                      
}

void loop(){
  int pirState = digitalRead(inputPin);          //Sets the PIR sensor's status to the input reading for the arduino, for now
  if(pirState){                                    //Begins the control flow, asking "If the pir state is...
    if(message == 0){                              //0, then...
   
    //Here is where the POST to twitter using Thingspeak would go, if I had either direct Ethernet connection or a WIFI shield.  This will be a future improvement.
    
      lcd.write("The Cookies are in Danger!!!!!");      //Print out "The cookies are in Danger!!!!!" on the LCD screen
      lcd.write(18);                                    //Turns the LCD's background light off
      lcd.write(128);                                  //
      lcd.write(17);                                        // Turns the LCD's background light on
      /*
      lcd.write(220);                                    //Plays a note.
      lcd.write(220);                                    //Plays a note.
      lcd.write(220);                                  //Plays a note.  
      lcd.write(230);                                      //Plays a note.
      lcd.write(231);                                      //Plays a note.
      lcd.write(228);                                      //Plays a note.
      */
      delay(5000);                                          //Delays for 5 seconds (5000 milliseconds)
      message = 1;                                            //Switches the stored variable to 1, so another reading can be done by the PIR sensor
}
  }

  else {                                                    //If the above "If" question is not answered with a true...
    if (message) {                                              
      delay(2000);
      lcd.write(12);                                      //Turn the LCD on
      lcd.write("The Cookies are Safe. Carry On.");        //Prints "The Cookies are safe, carry on." to the LCD screen.
      /*lcd.write(220);                                    //Plays a note.
      lcd.write(220);                                      //Plays a note.
      lcd.write(220);                                      //Plays a note.
      lcd.write(220);                                        //Plays a note.
      */
      lcd.write(17);                                          //Turns the LCD's backlight on.
      delay(5000);                                          //Wait for 3 seconds (3,000 milliseconds)
      lcd.write(18);                                            //Turns the LCD's backlight off.
      lcd.write(12);                                            //Clears the Screen, so future readings can be done.
      message = 0;                                            //Sets the variable back to its original state, so a further reading can be done.
    }
    }
}

  
