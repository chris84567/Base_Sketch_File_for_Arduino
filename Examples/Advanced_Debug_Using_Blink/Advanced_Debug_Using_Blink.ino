/*
 * 
 * Advanced_Debug_Using_Blink
 * 
 * Version 1.0
 * 
 * By: Joe Conway
 * 
 * Published: 08/02/2018
 * 
 * Github Link: https://github.com/chris84567/Base_Sketch_File_for_Arduino
 *  
*/

//Load External Files
#include "Config.h"


//Variables for Debugging
const int Debug_Pin = Config_Debug_Pin;             //Set Debug Pin to Pin declared in Config.h
const int Debug_Light_Pin = Config_Debug_Light_Pin; //Set Debug Light Pin to Pin declared in Config.h
boolean Debug = true;                               //Set Debug Mode off

//Variable for LED
const int LED_Pin = Config_LED_Pin;                 //Set LED Pin to Pin declared in Config.h
const int LED_Blink_Delay = Config_LED_Blink_Delay; //Set LED Blink Delay to delay declared in Config.h

void setup() { //Setup Arduino

  //Arduino Boot Serial
  Serial.begin(9600);                 //Open Serial
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Arduino Booting");  //Post Debug Info
  Serial.println("Jumper from pin 12 to ground for Debug Mode");
  Serial.end();                       //Close Serial
    
  //Declare Outputs
  pinMode(Debug_Light_Pin, OUTPUT); //Declare Debug Light Pin as output
  pinMode(LED_Pin, OUTPUT);         //Declare LED Pin as output
 
  //Set Outputs to off state
  digitalWrite(Debug_Light_Pin, LOW);   //Turn off Debug Light
  digitalWrite(LED_Pin, LOW);           //Turn off LED

  //Declare Inputs
  pinMode(Debug_Pin, INPUT_PULLUP);  //Declare Debug Pin as input with pullup resistor

  //Debug initialization
  Debug = digitalRead(Debug_Pin); //Set Debug Mode to value of Debug Pin

  if(Debug == false){  //if Debug Mode is enabled

    Serial.begin(9600);                   //Open Serial
    Serial.println();
    Serial.println("Debug Mode Enabled"); //Post Sketch Info in Serial
    Serial.println();
    Serial.println("Current Sketch: Advanced Debug Using Blink");
    Serial.println("Version: 1.0")
    Serial.println("Made by: Joe Conway");
    Serial.println("Published to Github on: 08/02/2018");
    Serial.println("Github Link: https://github.com/chris84567/Base_Sketch_File_for_Arduino");
    Serial.println();
    digitalWrite(Debug_Light_Pin, HIGH);  //Turn on debug light
    Serial.println("Debug light on");
    
  }

}

void(*resetFunc) (void) = 0; 

void loop() { //Main Code

  //Resart for Debug Mode if jumper is placed or unpluged
  if(Debug == true){ //If debug mode is not already enabled

    Debug = digitalRead(Debug_Pin); //Update Debug Mode

    if(Debug == false){  //If debug mode is now enabled

      resetFunc();
      
    }
    
  }

  if(Debug == false){ //If debug mode is enabled

    Debug = digitalRead(Debug_Pin); //Update Debug Mode

    if(Debug == true){  //If debug mode is now disabled

      resetFunc();
      
    }
    
  }

  //LED Blink Code
  digitalWrite(LED_Pin, HIGH);  //Turn on LED

  if(Debug == false){ //If Debug mode is enabled

    Serial.println(); //Post current state in Serial Monitor
    Serial.println("LED is on");
    Serial.print("Waiting for ");
    Serial.print(LED_Blink_Delay/1000);
    Serial.println("s");
    
  }

  delay(LED_Blink_Delay);

  digitalWrite(LED_Pin, LOW);  //Turn off LED

  if(Debug == false){ //If Debug mode is enabled

    Serial.println(); //Post current state in Serial Monitor
    Serial.println("LED is off");
    Serial.print("Waiting for ");
    Serial.print(LED_Blink_Delay/1000);
    Serial.println("s");
    
  }

  delay(LED_Blink_Delay);
 
}


