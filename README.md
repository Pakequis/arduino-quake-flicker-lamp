# arduino-quake-flicker-lamp
A flicker lamp for Arduino with Quake styles.

# Context: 

[Somebody in reddit found the same pattern of the flicker lamp in Half Life and Half Life Alyx in June](https://www.reddit.com/r/HalfLife/comments/nwrtol/valve_still_uses_the_same_light_flicker_pattern/)

[And more games use the same patterns, first one is Quake from 1996](https://www.pcgamer.com/half-life-alyxs-lights-flicker-just-like-they-did-in-quake-almost-25-years-later/)

So I made a emergency lamp flicker with the same original Quake styles, with some code adaptations. The hardware:

![sHardware](https://github.com/Pakequis/arduino-quake-flicker-lamp/blob/main/extras/circuit-1.jpg?raw=true)

# The code:

[First I get the original world.qc with the original styles.](https://github.com/id-Software/Quake/blob/bf4ac424ce754894ac8f1dae6a3981954bc9852d/QW/progs/world.qc#L307)

For the Arduino version I get the styles and put in a string array: 
```
String  lightstyle[] = {
  "string1", 
  "string2", 
  "strin3",
  ..., 
  "stringN" }
````

The Quake flicker use the letters a to z to indicate the brightness of the light. Where "a" is for total darkness and "z" for total brightness.

So for make this work with the Arduino and the LEDs, I get the pin 9 of the board (both for Arduino Uno or Arduino Mini Pro) and use the analogWrite() to control the brightness. This require a conversion from "a" to "z" from the original code to 0-255 for the analogWrite() function. This is made whit this simple code, in the Arduino loop():

```
  for (i = 0; i < l; i++)
  {
    value = (lightstyle[LIGHT_STYLE][i]) - 'a'; //Get the value from a to z from the string array minus 'a' (ASCII 0x61). This returns a value from 0 to 26.
    map(value, 0, 26, 0, 255);    // convert from 0-26 to 0-255
    analogWrite(BLED, value);     // Put the value in the pin 9 (PWM)
    delay(FTIME);       // Wait the time for one step
  }
```

The FTIME value of 100 ms I get with a video of Quake gameplay and a vídeo editor app (Vegas Pro) and pen and paper.


# Vídeo demo: 

[![lamp demo video](https://img.youtube.com/vi/ldI8LOxTwaM/0.jpg)](https://www.youtube.com/watch?v=ldI8LOxTwaM)

# Schematics for one LED:
![schematic for one LED](https://github.com/Pakequis/arduino-quake-flicker-lamp/blob/main/extras/schematic-one-led.png?raw=true)

# Schematics for 30 LED:
![schematic for one LED](https://github.com/Pakequis/arduino-quake-flicker-lamp/blob/main/extras/schematic.png?raw=true)
