/*
	Light Flicker for Arduino
	With original styles from Quake (1996)
	(https://github.com/id-Software/Quake)

	By Rodrigo Feliciano
	https://www.youtube.com/pakequis
*/

#define BLED  9			/* Output LED pin */
#define LIGHT_STYLE 10	/* Flicker style */
#define MAX_STYLES 11	/* Max light style index */

#define FTIME 100  		/* Flicker time - 100 ms - I get it with a gameplay video and a video editor... */

/* Original styles from https://github.com/id-Software/Quake/blob/master/qw-qc/world.qc */
//
// Setup light animation tables. 'a' is total darkness, 'z' is maxbright.
//

  String  lightstyle[] = {
	// 0 normal
	"m",
	
	// 1 FLICKER (first variety)
	"mmnmmommommnonmmonqnmmo",

	// 2 SLOW STRONG PULSE
	"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba",
	
	// 3 CANDLE (first variety)
	"mmmmmaaaaammmmmaaaaaabcdefgabcdefg",
	
	// 4 FAST STROBE
	"mamamamamama",
	
	// 5 GENTLE PULSE 1
	"jklmnopqrstuvwxyzyxwvutsrqponmlkj",
	
	// 6 FLICKER (second variety)
	"nmonqnmomnmomomno",
	
	// 7 CANDLE (second variety)
	"mmmaaaabcdefgmmmmaaaammmaamm",
	
	// 8 CANDLE (third variety)
	"mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa",
	
	// 9 SLOW STROBE (fourth variety)
	"aaaaaaaazzzzzzzz",
	
	// 10 FLUORESCENT FLICKER
	"mmamammmmammamamaaamammma",

	// 11 SLOW PULSE NOT FADE TO BLACK
	"abcdefghijklmnopqrrqponmlkjihgfedcba",
	
	// styles 32-62 are assigned by the light program for switchable lights

	// 63 testing
	"a"
  };

  int i, value, l;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); 	//Onboard LED off...
  pinMode(BLED, OUTPUT);

  l = lightstyle[LIGHT_STYLE].length();	//Length of the string style
}

void loop() 
{
  for (i = 0; i < l; i++)
  {
    value = (lightstyle[LIGHT_STYLE][i]) - 'a'; //Get the value from a to z from the string array minus 'a' (ASCII 0x61). This returns a value from 0 to 26.
    map(value, 0, 26, 0, 255); // convert from 0-26 to 0-255
    analogWrite(BLED, value); // Put the value in the pin 9 (PWM)
    delay(FTIME); // Wait the time for one step
  }
}
