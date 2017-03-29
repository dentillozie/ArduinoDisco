#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,16,2);

int analogPin = 0;
int i;
int mode;

int red, green, blue = 0;
int colorselect = 1;

int GREEN = 9;
int BLUE = 5;
int RED = 6;
int delayTime = 2;
void setup() {
  Serial.begin(9600); 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
 mode = analogRead(1);
 
 if(mode < 250)
 { 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Own color");
   individual();
 }else if(mode > 251 && mode < 520)
 {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Hardscycle");
   hardSycle();
 }else if(mode > 521 && mode < 750)
 {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("flow");
   flow();
 }else if(mode > 751 && mode < 980)
 {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("sound (loud)");
   microDink();
 }else if(mode > 981 && mode < 1024)
 {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("sound (random)");
   verassing();
 }
  
}

void standaard()
{
  flow();
  flow();
  flow();
  flow();
  flow();
  hardSycle();
  hardSycle();
  hardSycle();
  hardSycle();
  
  int ii = 750;
  while(ii > 0)
  {
    ii--;
    microDink();
    
  }
}

void hardSycle()
{
  lcd.setCursor(0,1);
  lcd.print(analogRead(2));
  analogWrite(9,255);
  analogWrite(5,255);
  analogWrite(6,0);
  delay(analogRead(2));
  analogWrite(9,255);
  analogWrite(5,0);
  analogWrite(6,255);
  delay(analogRead(2));
  analogWrite(9,0);
  analogWrite(5,255);
  analogWrite(6,255);
  delay(analogRead(2));
}

void microDink()
{
  i=analogRead(0);
  i=i;
  analogWrite(9,255-i);
  analogWrite(5,255-i);
  analogWrite(6,255-i);
  delay(10);
}
void verassing()
{
  analogWrite(9,random(0, 255));
  analogWrite(5,random(0, 255));
  analogWrite(6,random(0, 255));
  delay(analogRead(0));

}

void individual()
{
  
  if(digitalRead(4))
      colorselect++;
  
  if(colorselect == 1){
      red = analogRead(2)/4;
      lcd.setCursor(0,1);
      lcd.print("G:       ");
      lcd.setCursor(4,1);
      lcd.print(red);
  }
  if(colorselect == 2){
      green = analogRead(2)/4;
      lcd.setCursor(0,1);
      lcd.print("R:       ");
      lcd.setCursor(4,1);
      lcd.print(green);
  }
  if(colorselect == 3){
      blue = analogRead(2)/4;
      lcd.setCursor(0,1);
      lcd.print("B:        ");
      lcd.setCursor(4,1);
      lcd.print(blue);
  }
  if(colorselect == 4){
      colorselect = 0;
      lcd.setCursor(0,1);
      lcd.print("            ");    
  }
  delay(150);   
  analogWrite(9,255-red);
  analogWrite(5,255-green);
  analogWrite(6,255-blue);
}

void flow()
{
   int redVal = 255;
  int blueVal = 0;
  int greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    greenVal += 1;
    redVal -= 1;
    analogWrite( GREEN, 255 - greenVal );
    analogWrite( RED, 255 - redVal );

    delay( analogRead(2)/4 );
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );

    delay( analogRead(2)/4 );
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );

    delay( analogRead(2)/4 );
  }

}
