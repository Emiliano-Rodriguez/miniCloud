#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define FASTLED_INTERNAL



#include <Wire.h>

#include "FastLED.h"

#define PIN 9
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10 , PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
int led = 0;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
const int buttonPin = 2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int mode = 0; 
int flag = 0; 
int timeStart = 0;
int randi = 0; 
int const NUM_LEDS = 10;

int fade_h;
int fade_hl;
int fade_directionl = -1;
int fade_direction = 1;

CRGB leds[NUM_LEDS];

void setup() {



 FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS);
  // starts the audio samples array at volume 15. 
  
  //Serial.begin(9600);
  Wire.begin(9); // Start I2C Bus as a Slave (Device Number 9)
  //Start cloud with blue LED mode 
  //mode = CLOUD;
  randomSeed(analogRead(4));

  


  

    pinMode(led, OUTPUT);
      pinMode(buttonPin, INPUT);  

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(200);

 
  strip.show(); // Initialize all pixels to 'off'
  //delay(3000);
  
}
void loop() {
    strip.setBrightness(200);


 if (digitalRead(2) == HIGH)    
     mode++; 

     
  if(mode > 20){
    mode = 0; 
    delay(1000);
  }

timeStart = millis()/1000;
randi = random(1,4);
switch(mode){
   case 0: detect_thunder();while((millis()/1000) - timeStart <= randi){ if(digitalRead(2) == HIGH) {delay(100);mode=1;}}; break;
   case 1:
  colorWipe(strip.Color(255, 0, 0), 0); // Red
    break;
  case 2:
  colorWipe(strip.Color(0, 255, 0), 0); // Red
    break;
      case 3:
  colorWipe(strip.Color(30, 144, 255), 0); // Red
  break;
    case 4:
  colour_fade();
  break;
  case 5:
  colorWipe2(strip.Color(0, 0, 0), 0); // Red
  break;
  case 6:
  delay(150);
  colorWipeRound(strip.Color(255, 255, 255), 50); // Red
  colorWipeRound(strip.Color(0, 0, 0), 50); // Red
  break;
    case 7:
  colorWipe(strip.Color(random(0,255),random(0,255),random(0,255)), 0);
  delay(200);
  while(1){
    if(digitalRead(2) == HIGH)
      mode++;
      delay(150);
      break;
  }
  break;
  case 8:
  delay(200);
  rainbowCycle(20);
    if(digitalRead(2) == HIGH){
    mode++;
  break;
    }
    break;
  case 9:
  delay(100);
    colorWipe(strip.Color(30, 144, 255), 0); // Red
while(flag == 0) {
colorWipe(strip.Color(30, 144, 255), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}


  delay(200);
  }
    flag = 0;
    mode = 10;
    delay(200);
    break;
  case 10:
  delay(100);
while(flag == 0) {
colorWipe(strip.Color(255, 255, 10), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}


  delay(200);
  }
    flag = 0;
    mode = 11;
    delay(200);
    break;
  case 11:
  delay(100);
while(flag == 0) {
colorWipe(strip.Color(255, 0, 255), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}


  delay(200);
  }
    flag = 0;
    mode = 12;
    delay(200);
    break;

case 12:
  delay(100);
while(flag == 0) {
colorWipe(strip.Color(random(0,255), 255, random(1,255)), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}

  delay(200);
  }
    flag = 0;
    mode = 13;
    delay(200);
    break;
case 13:
  delay(100);
while(flag == 0) {
colorWipe(strip.Color(255, random(0,255), random(1,255)), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}

  delay(200);
  }
    flag = 0;
    mode = 14;
    delay(200);
    break;
case 14:
  delay(100);
while(flag == 0) {
colorWipe(strip.Color(random(0,255), random(0,255),255), 0); // Red
for (int i=1; i<200; i++) { 
  strip.setBrightness(i); strip.show(); delay(10); 
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
for (int i=200; i>0; i--) { 
  strip.setBrightness(i); strip.show(); delay(10); 
    if(digitalRead(2) == HIGH){
    flag = 1;
    break;
    }
}

  delay(200);
  }
    flag = 0;
    mode = 15;
    delay(200);
    break;
  case 15:
  delay(100);
colorWipe(strip.Color(random(0,255),random(0,255),random(0,255)), 0);
while(flag == 0) {
  if(digitalRead(2) == HIGH){
    flag = 1; 
    break;
  }
}
flag = 0;
  delay(250);
  break;
  
  default:
  break;
} 
delay(100);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


void colorWipeRound(uint32_t c, uint8_t wait) {
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {

    if(digitalRead(2)==HIGH){
      mode++;
      break; 
    }
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}



void colorWipe2(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<3; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));

    strip.show();
  }
   for(uint16_t i=3; i<6; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 0));
    strip.show();
   }
   for(uint16_t i=6; i<10; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
        analogWrite(led, brightness);
      brightness = brightness + fadeAmount;

 if (brightness <= 0 || brightness >= 255) 
    fadeAmount = -fadeAmount;

    delay(wait);
  }
}

void colorWipe3(uint32_t c, uint8_t wait) {
  for(uint16_t i=strip.numPixels(); i>0; i--) {
          if(digitalRead(2) == HIGH){
          //  mode++;
            break;
          }
        strip.setPixelColor(i, c);
    strip.show();
        analogWrite(led, brightness);
      brightness = brightness + fadeAmount;

 if (brightness <= 0 || brightness >= 255) 
    fadeAmount = -fadeAmount;

    delay(wait);
  }
}

void colorWipe4(uint32_t c, uint8_t wait) {
  for(uint16_t i=strip.numPixels(); i>=0; i--) {
            if(digitalRead(2) == HIGH){
             // mode++;
            break;
          }
    strip.setPixelColor(i, c);
    strip.show();
        analogWrite(led, brightness);
      brightness = brightness + fadeAmount;

 if (brightness <= 0 || brightness >= 255) 
    fadeAmount = -fadeAmount;

    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++)
  {
      if(digitalRead(2) == HIGH){
        mode=9;
    delay(100); 
    break;
  }// 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
        if(digitalRead(2) == HIGH){
          mode=9;
    delay(100);
    break;
  }
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip.setPixelColor(i + 5, Wheel(((i+5) * 256 / strip.numPixels()) + (j+5) & 255));

    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void detect_thunder() {


    //3 types of lightning. Each cycle, picking a random one. 
    switch(2){
       //switch(3){
      case 1:
       // thunderburst();
        delay(random(10,500));
        break;
       
      case 2:
        rolling();
        break;
        
      case 3:
       // crack();
        delay(random(50,250));
        break;   
      
    }
  
}


void rolling(){
  // a simple method where we go through every LED with 1/10 chance
  // of being turned on, up to 10 times, with a random delay wbetween each time
  for(int r=0;r<random(2,10);r++){
    //iterate through every LED
    for(int i=0;i<NUM_LEDS;i++){
      if(random(0,100)>90){
        leds[i] = CHSV( 0, 0, 255); 

      }
      else{
        //dont need reset as we're blacking out other LEDs her 
        leds[i] = CHSV(0,0,0);
      }
    }
    FastLED.show();
    delay(random(5,150));
    reset();
    
  }
}


void reset(){
  for (int i=0;i<strip.numPixels();i++){
    colorWipe(strip.Color(0, 0, 0),0);
  }
  strip.show();
   
}

void colour_fade(){
  //mood mood lamp that cycles through colours
  for (int i=0;i<NUM_LEDS;i++){
    leds[i] = CHSV( fade_h, 255, 255);
  }
  if(fade_h >254){
    fade_direction = -1; //reverse once we get to 254
  }
  else if(fade_h < 0){
    fade_direction = 1;
  }
    
  fade_h += fade_direction;
  FastLED.show();
  delay(5);
}

 
