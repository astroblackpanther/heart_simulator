//Original Code by RoboPandaPDX for Haley's Heart
//https://github.com/RoboPandaPDX/Haley-s-Heart
//https://www.instructables.com/Haleys-Heart/
//Edited for ULACIT 2025 Prototyping Workshop

#include <Adafruit_NeoPixel.h>
//#include <Wire.h> //for the Teensy 4.0, the SDA Pin is 18, and SCL is 19
#include <LCD_I2C.h>
#define PIN 3
#define NUMPIXELS 26
long randRed = 100;
long randBlue = 0;
long randGreen = 0;
int count = 0;
float heartRate = 80;
float heartDelay = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
LCD_I2C lcd(0x27, 16, 2);

int button1 = 11;
int button2 = 12;
int button3 = 20;

void setup(){
	pixels.begin();
	//Need to replace all Serials with I2C code
	//Serial.begin(9600);
	//Serial3.begin(9600);
	lcd.begin();
	lcd.backlight(); 
	randomSeed(analogRead(2));
	pinMode(button1, INPUT_PULLUP);
	pinMode(button2, INPUT_PULLUP);
	pinMode(button3, INPUT_PULLUP);
}

void loop(){
	int heartRateInt = heartRate;
	//Serial3.write(12); //Clear
	lcd.clear();
	delay(10);
	//Serial3.print("Haley's Heart"); //First Line
	lcd.print("Haley's Heart");
	//Serial3.write(13); //Form feed
	lcd.setCursor(0,1);
	delay(10);
	//Serial3.print(heartRateInt);
	lcd.print(heartRateInt);
	delay(10);
	//Serial3.print(" BPM ");
	lcd.print(" BPM ");
	lcd.setCursor(0,0);
	delay(10);
	//Serial3.write(17); //Backlight byte, unneeded
	//delay(10);
	
	if(digitalRead(button1==HIGH)){
	}else{
		while(digitalRead(button1) == LOW && heartRate <= 420)
		{
			heartRate++;
			delay(70);
			//Serial3.write(12);
			lcd.clear();
			lcd.setCursor(0,0);
			delay(10);
			//Serial3.print(heartRate);
			lcd.print(heartRate);
			delay(10);
			lcd.print(" BPM ");
			delay(10);
			if(heartRate >=420){
				break;
			}
		}
	}
	
	if(digitalRead(button2) == HIGH && heartRate > 40){
	}else{
		while(digitalRead(button2) == LOW)
		{
			heartRate--;
			delay(70);
			//Serial3.write(12);
			lcd.clear();
			lcd.setCursor(0,0);
			delay(10);
			//Serial3.print(heartRate);
			lcd.print(heartRate);
			delay(10);
			//Serial3.print(" BPM ");
			lcd.print(" BPM ");
			delay(10);
			if(heartRate <= 40){
				break;
			}
		}
	}
	
	if(digitalRead(button3) == HIGH){
	}else{
		while(digitalRead(button3) == LOW)
		{
			//Serial3.write(12);
			lcd.clear();
			lcd.setCursor(0,0);
			//Serial3.print("New Color :)");
			lcd.print("New Color :)");
			randRed = random(150);
			randBlue = random(150);
			randGreen = random(150);
			for(int i=0;i<NUMPIXELS;i++){
				pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen));
				pixels.show();
			}
			delay(20);
		}
	}
	
	heartDelay = (1000 * (60/heartRate))/4;
	
	delay (heartDelay);
	for(int i = 25; i >= 16; i--){
		pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen));
		pixels.show();
		delay(heartDelay*0.1);
	}
	for(int i = 25; i >= 13; i--){
		pixels.setPixelColor(i, pixels.Color(0,0,0));
		pixels.show();
	}
	
	delay(heartDelay/10);
	delay(heartDelay/10);
	for(int i = 0; i <= 9; i++){
		pixels.setPixelColor(i, pixels.Color(randRed,randBlue,randGreen));
		pixels.show();
		delay(heartDelay*0.1);
	}
	for(int i = 0; i <= 9; i++){
		pixels.setPixelColor(i, pixels.Color(0,0,0));
	}
	
	delay(heartDelay);
	
}
	
	
	
			
	