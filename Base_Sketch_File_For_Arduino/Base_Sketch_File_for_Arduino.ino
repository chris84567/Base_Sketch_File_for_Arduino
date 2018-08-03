/*
 * 
 * Base_Sketch_File_for_Arduino
 * 
 * Version 1.2
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
  pinMode(Debug_Light_Pin, OUTPUT);  //Declare Debug Light Pin as output
 
  //Set Outputs to off state
  digitalWrite(Debug_Light_Pin, LOW);   //Turn off Debug Light

  //Declare Inputs
  pinMode(Debug_Pin, INPUT_PULLUP);  //Declare Debug Pin as input with pullup resistor

  //Debug initialization
  Debug = digitalRead(Debug_Pin); //Set Debug Mode to value of Debug Pin

  if(Debug == false){  //if Debug Mode is enabled

    Serial.begin(9600);                   //Open Serial
    Serial.println();
    Serial.println("Debug Mode Enabled"); //Post Sketch Info in Serial
    Serial.println();
    Serial.println("Current Sketch: Base Sketch File for Arduino");
    Serial.println("Version: 1.2");
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

  //Resart for Debug Mode if jumper is placed
  if(Debug == true){ //If debug mode is not already enabled

    Debug = digitalRead(Debug_Pin); //Update Debug Mode

    if(Debug == false){  //If debug mode is now enabled

      resetFunc();
      
    }
    
  }

  //Resart for Debug Mode if jumper is removed
  if(Debug == false){ //If debug mode is already enabled

    Debug = digitalRead(Debug_Pin); //Update Debug Mode

    if(Debug == true){  //If debug mode is now disabled

      resetFunc();
      
    }
    
  }
  

  
  
}
