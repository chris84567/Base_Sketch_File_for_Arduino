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

This is a base file you can use to start your sketches from.

It has a Debug mode built in that will reset your arduino when a configurable pin is pulled to ground.

You are free to use this as you wish but I would apreciate it if you would give me credit if you post a file using this online.

To enable Debug mode put a jumper between pin 12 and GND.
If Debug mode is enabled the LED tied to pin 13 should light up.
When the jumper is put between pin 12 and GND the arduino will automatically reset itself and boot into debug mode.

To disable Debug mode remove the jumper between pin 12 and GND.
The LED tied to pin 13 should turn off when it is disabled.
When the jumper is removed between pin 12 and GND the arduino will automatically reset itself and boot out of debug mode.
