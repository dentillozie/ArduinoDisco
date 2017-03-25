int analogPin = 0;
int i;
int mode;

int GREEN = 9;
int BLUE = 5;
int RED = 6;
int delayTime = 2;
void setup() {
  Serial.begin(9600); 

}

void loop() {
 mode = analogRead(1);
 Serial.println(mode);
 if(mode < 250)
 {
   standaard();
 }else if(mode > 251 && mode < 520)
 {
   hardSycle();
 }else if(mode > 521 && mode < 750)
 {
   flow();
 }else if(mode > 751 && mode < 1024)
 {
   microDink();
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
  analogWrite(9,255);
  analogWrite(5,255);
  analogWrite(6,0);
  delay(500);
  analogWrite(9,255);
  analogWrite(5,0);
  analogWrite(6,255);
  delay(500);
  analogWrite(9,0);
  analogWrite(5,255);
  analogWrite(6,255);
  delay(500);
}

void microDink()
{
  i=analogRead(0);
  i=i/2;
  analogWrite(9,255-i);
  analogWrite(5,255-i);
  analogWrite(6,255-i);
  delay(10);
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

    delay( delayTime );
  }
 
  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for( int i = 0 ; i < 255 ; i += 1 ){
    blueVal += 1;
    greenVal -= 1;
    analogWrite( BLUE, 255 - blueVal );
    analogWrite( GREEN, 255 - greenVal );

    delay( delayTime );
  }
 
  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for( int i = 0 ; i < 255 ; i += 1 ){
    redVal += 1;
    blueVal -= 1;
    analogWrite( RED, 255 - redVal );
    analogWrite( BLUE, 255 - blueVal );

    delay( delayTime );
  }

}
