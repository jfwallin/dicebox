


// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            5
// 4 - nano pin 5
// 5 - uno pin d4
// 7 - nano pin d7


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      7

#define ncolors 120

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500; // delay for half a second

int dt;
int icount;
int reds[ncolors], greens[ncolors], blues[ncolors];
int colorNumber;

void setup() {
  
    dt = 2;

 
    pixels.begin(); // This initializes the NeoPixel library.
    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,0));      
    }

    pixels.show();
    delay(4000);


  int j;
  int ns;
  
  ns = 10;
  // total number of colors = 

  // red to yellow
  j = 0;
  for (int i = 0; i < 256; i= i + ns) {
    reds[j] = 255;
    greens[j] = i;
    blues[j] = 0;
    j = j + 1;  
  }

  // yellow to green
  for (int i = 0; i < 256; i= i + ns) {
    reds[j] = 255 -i ;
    greens[j] = 255;
    blues[j] = 0;
    j = j + 1;  
  }


  // green to aqua
  for (int i = 0; i < 256; i= i + ns) {
    reds[j] = 0 ;
    greens[j] = 255;
    blues[j] = i;    
    j = j + 1;  
  }

  // aqua to blue
  for (int i = 0; i < 256; i= i + ns) {
    reds[j] = 0 ;
    greens[j] = 255 -i;
    blues[j] = 255;  
    j = j + 1;   
  }

  colorNumber = j;
  icount = 0;


}


void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

   int dt = 50;
   rainbowCircle(dt);
}


void rainbowCircle(int dt) {

int r,g,b;
int ncycle = 1000;
int icolor;

int lightStep;
int intensityLevel;
int intensityLevel2;
int i;

lightStep = 5;
intensityLevel = 50;
intensityLevel2 = 155;
i = icount;


for (int j = 0; j < NUMPIXELS-1; j++) {
      icolor = (icount*lightStep) % colorNumber;
      
      r = reds[icolor] * intensityLevel / 255;
      g = greens[icolor] * intensityLevel / 255;   
      b = blues[icolor] * intensityLevel / 255;        
      pixels.setPixelColor(j, pixels.Color(r,g,b));
      //pixels.show();
      icount = icount + 1;
      delay(dt);
}

      icolor = (icount*lightStep + colorNumber/2) % colorNumber;
      r = reds[icolor] * intensityLevel2 / 255;
      g = greens[icolor] * intensityLevel2 / 255;   
      b = blues[icolor] * intensityLevel2 / 255;  
      pixels.setPixelColor(NUMPIXELS-1, pixels.Color(r,g,b));
      pixels.show();
      delay(dt*2);

}



void rainbowCircle2(int dt) {

int r,g,b;
int ncycle = 1000;
int icolor;

int lightStep;
int intensityLevel;
int intensityLevel2;
int i;

lightStep = 3;
intensityLevel = 50;
intensityLevel2 = 155;
i = icount;


for (int j = 0; j < NUMPIXELS; j++) {
      icolor = (icount*lightStep) % colorNumber;
      
      r = reds[icolor] * intensityLevel / 255;
      g = greens[icolor] * intensityLevel / 255;   
      b = blues[icolor] * intensityLevel / 255;        
      pixels.setPixelColor(j, pixels.Color(r,g,b));

      icount = icount + 1;
      delay(50);
}
      pixels.show();


}



 
