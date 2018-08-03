/*
 * 
 * Advanced_Debug_Using_Blink
 * 
 * Version 1.01
 * 
 * By: Joe Conway
 * 
 * Published: 08/02/2018
 * 
 * Github Link: https://github.com/chris84567/Base_Sketch_File_for_Arduino
 *  
*/

This sketch uses the following sketch as a base:

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

To enable Debug mode put a jumper between pin 12 and GND.
If Debug mode is enabled the LED tied to pin 13 should light up.
When the jumper is put between pin 12 and GND the arduino will automatically reset itself and boot into debug mode.
Debug is inverse (if var debug is false debug mode is on).

Hook LED with current limiting resistor to pin 11 and GND with negative towards GND.
LED should blink off and on for a period of 1s each.
