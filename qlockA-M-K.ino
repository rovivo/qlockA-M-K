#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#include "Constants.h"
#include "MyClock.h"
#include "Input.h"
#include "Timer.h"
#include "MatrixFunctions.h"
#include "ColorSequencer.h"
#include "EventHandler.h"

//#define debug

// Matrix Einstellungen können direkt in der MatrixFunctions.cpp eingestellt werden
	// 	1. links rechts vertauscht
	//	2. Oben und unten vertauscht
	//	3. RGB LEDs von links nach rechts verkabelt (kürzester Weg)

// Farben der LEDs
	// Farbwechsel oder statische farbe? 0 = Farbwechsel, 1 = rot, 2 = grün, 3 = blau, 4 = weiss, 5 = individuell (MaxBrightness ohne funktion)
	#define Color       		5
	// Farbwechselgeschwindigkeit grössere Zahl = langsamerer Wechsel
	#define ColorSpeed			1
	// maximale helligkeit (1-255)
	#define MaxBrightness	  200
	// minimale helligkeit in Summe (nur bei Farbwechsler)
	#define minBrightnessSum  250
	// individuelle Farbe (Color muss 5 sein)	
	#define LedRed			  240
	#define LedGreen		  156
	#define LedBlue 		  11

// IOs
	// Funkempfänger Uhr
	#define PIN_DCF				9

	// Echtzeituhr
	// 		PIN_RTC_D (SDA, D)	A4	! depends on board !
	// 		PIN_RTC_C (SCL, C)	A5  ! depends on board !
	#define PIN_RTC_ON			4	// not needed

	// Taster
	#define PIN_BTN_MODE		7
	#define PIN_BTN_UP			5
	#define PIN_BTN_DOWN		6

	// Lichtsensor
	#define PIN_LDR				A3	// LDR Analog in for brightness adjustment (not used)

	// RGB LEDs Datenleitung und Anzahl
	#define PIN_NEOPIXEL		8
	#define PIXELS_MAX			110

	// Wenn Minuten LED separat auf digitalen IOs
	#define PIN_1MIN			10
	#define PIN_2MIN			13
	#define PIN_3MIN			12
	#define PIN_4MIN			11


// Verfügbare Funktionen
#define	MODE_CLOCK			0
#define MODE_DCFDIAG		1
#define MODE_ADDHOUR		2
#define MODE_ADDMIN			3
#define MODE_ADDWDAY		4
#define MODE_ADDDAY			5
#define MODE_ADDMON			6
#define MODE_ADDYEAR		7

#define MODE_SCHWEIZ		8
#define MODE_DAILY			9

#define	MODE_SLEEP			20
#define	MODE_WAKEUP			21

// maximum states to choose with mode button
#define maxState			7


Adafruit_NeoPixel	neo		= Adafruit_NeoPixel(PIXELS_MAX,  PIN_NEOPIXEL,  NEO_GRB + NEO_KHZ800);
MyClock 			clk		= MyClock(PIN_DCF, PIN_RTC_ON, &neo);
Input				inp		= Input(PIN_BTN_UP, PIN_BTN_MODE, PIN_BTN_DOWN);
EventHandler		event	= EventHandler();

// 
ColorSequencer		seq		= ColorSequencer(0, Color, ColorSpeed, MaxBrightness, minBrightnessSum, LedRed, LedGreen, LedBlue);

PATTERN 			matrix;

Timer				tmrDiagPrintTime;
Timer				tmrToclock;

void setup(){
	Serial.begin(9600);
	randomSeed(analogRead(0));
	neo.begin();
	clk.setup();
	inp.setup();

	pinMode(PIN_1MIN, OUTPUT);
	pinMode(PIN_2MIN, OUTPUT);
	pinMode(PIN_3MIN, OUTPUT);
	pinMode(PIN_4MIN, OUTPUT);
	///////////////////////////////////////////////////////
	//# ADD EVENTS (-1 for all values)
	//			MODE			Year	Month	Day		Hour 	Minute	Second		Weekday		// DD.MM.YYYY / HH:II:SS
	//event.add(	MODE_TEMP,		-1,		-1,		-1,		-1,		-1,		26,			-1		);	// ??.??.???? / ??:??:30 // Temperaturanzeige

	// Montag
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 6,		 0,		 0,			 1		);	// WAKE UP FROM SLEEP
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		23,		 0,		 0,			 1		);	// GO SLEEP
	// Dienstag
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 6,		 0,		 0,			 2		);	// WAKE UP FROM SLEEP
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		23,		 0,		 0,			 2		);	// GO SLEEP
	// Mittwoch
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 6,		 0,		 0,			 3		);	// WAKE UP FROM SLEEP
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		23,		 0,		 0,			 3		);	// GO SLEEP
	// Donnerstag
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 6,		 0,		 0,			 4		);	// WAKE UP FROM SLEEP
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		23,		 0,		 0,			 4		);	// GO SLEEP
	// Freitag
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 6,		 0,		 0,			 5		);	// WAKE UP FROM SLEEP
	// Samstag
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		 1,		 0,		 0,			 5		);	// GO SLEEP
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 8,		30,		 0,			 6		);	// WAKE UP FROM SLEEP
	// Sonntag
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		 1,		 0,		 0,			 6		);	// GO SLEEP
	//event.add(	MODE_WAKEUP,	-1,		-1,		-1,		 9,		 0,		 0,			 7		);	// WAKE UP FROM SLEEP
	//event.add(	MODE_SLEEP,		-1,		-1,		-1,		23,		 0,		 0,			 7		);	// GO SLEEP
	
	//event.add(	MODE_SCHWEIZ,	-1,		 8,		 1,		-1,		 0,		25,			-1		);
	
	//event.add(	MODE_NINA,		-1,		 6,		 5,		-1,		-1,		45,			-1		);
	//event.add(	MODE_URS,		-1,		 7,		31,		-1,		-1,		45,			-1		);
	
	Serial.println("QlockRovivoRGB");
    Serial.print("compiled: ");
    Serial.print(__DATE__);
	Serial.print(" ");
    Serial.println(__TIME__);
	
}

unsigned short state=0;
int action=0;

void loop(){
	// Haupt-Klassen
	clk.call();	// Clock handler
	inp.call();	// Input handler

	// RTC-Infos bereitstellen
	unsigned short Hour		= clk.getRtcHour();
	unsigned short Minute	= clk.getRtcMinute();
	unsigned short Second	= clk.getRtcSecond();
	unsigned short Year		= clk.getRtcYear();
	unsigned short Month	= clk.getRtcMonth();
	unsigned short Day		= clk.getRtcDay();
	unsigned short Wday		= clk.getRtcWday();

	// Funktions-Klassen
	// color ColorSequencer
	seq.call();

	#ifdef debug
		Serial.print("Time from RTC: ");
		Serial.print(Hour);
		Serial.print(":");
		Serial.print(Minute);
		Serial.print(":");
		Serial.println(Second);
		Serial.print("Date from RTC: ");
		Serial.print(Day);
		Serial.print(".");
		Serial.print(Month);
		Serial.print(".");
		Serial.println(Year);
	#endif

	// Event-Handler
	action = event.check(Year, Month, Day, Hour, Minute, Second, Wday);
	if(action and state == MODE_CLOCK){
		state = action;
	}
	
	// Inputs & allgemeines
	if(inp.doReset()){
		clk.resetRtc();
		inp.call();	// clears click-functions
	}
	
	
	if(inp.clickMode()){
		state++;
		tmrToclock.ton(false);
		if(state > maxState)
			state = 0;
		#ifdef debug
			Serial.print("Mode-Change to: ");
			Serial.println(state);
		#endif
	}
	
	switch(state){
		case MODE_ADDHOUR:{
			if(inp.clickUp())
				clk.addHour();
			if(inp.clickDown())
				clk.addHour(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcHour();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'H', 5, 6);
			writeMatrix(&matrix, 'R', 5, 2);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		case MODE_ADDMIN:{
			if(inp.clickUp())
				clk.addMinute();
			if(inp.clickDown())
				clk.addMinute(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcMinute();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'M', 5, 6);
			writeMatrix(&matrix, 'N', 5, 0);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		case MODE_ADDWDAY:{
			if(inp.clickUp())
				clk.addWday();
			if(inp.clickDown())
				clk.addWday(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcWday();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'W', 5, 4);
			writeMatrix(&matrix, 'D', 5, 0);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		case MODE_ADDDAY:{
			if(inp.clickUp())
				clk.addDay();
			if(inp.clickDown())
				clk.addDay(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcDay();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'D', 5, 6);
			writeMatrix(&matrix, 'D', 5, 2);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		case MODE_ADDMON:{
			if(inp.clickUp())
				clk.addMonth();
			if(inp.clickDown())
				clk.addMonth(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcMonth();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'M', 5, 4);
			writeMatrix(&matrix, 'T', 5, 0);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		case MODE_ADDYEAR:{
			if(inp.clickUp())
				clk.addYear();
			if(inp.clickDown())
				clk.addYear(true);
			const RGB	colorParamHeader = { 0, 0,50};
			const RGB 	colorParamValue  = {0,150,50};
			int temp = (int)clk.getRtcYear();
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'Y', 5, 7);
			writeMatrix(&matrix, 'Y', 5, 3);
			writeNeo(&matrix, &neo, &colorParamHeader, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix,   temp/10, 0, 6);
			writeMatrix(&matrix,   temp%10, 0, 2);
			writeNeo(&matrix, &neo, &colorParamValue);
			break;
		}
		
		
		case MODE_SLEEP:
		case MODE_WAKEUP:{
			const RGB colorOff = {0,0,0};
			clearMatrix(&matrix);
			writeNeo(&matrix, &neo, &colorOff, true);
			if(action == MODE_WAKEUP)
				state = MODE_CLOCK;
			break;
		}
		case MODE_DAILY:{
			if(tmrToclock.ton(true,2000)){
				tmrToclock.ton(false);
				state = MODE_CLOCK;
			}
			const RGB col1 = {0,50,150};
			const RGB col2 = {0,150,50};
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'D', 5, 7);
			writeMatrix(&matrix, 'A', 5, 3);
			writeMatrix(&matrix, 'I', 5, 1);
			writeNeo(&matrix, &neo, &col1, true);
			clearMatrix(&matrix);
			writeMatrix(&matrix, 'L', 0, 6);
			writeMatrix(&matrix, 'Y', 0, 2);
			writeNeo(&matrix, &neo, &col2);
			break;
		}
		case MODE_SCHWEIZ:{
			if(tmrToclock.ton(true,10000)){
				tmrToclock.ton(false);
				state = MODE_CLOCK;
			}
			const RGB white = {50,50,50};
			const RGB red = {50,0,0};
			const struct PATTERN 	View_SchweizWhite =  {
				 0b00000000000,
				 0b00001110000,
				 0b00001110000,
				 0b00001110000,
				 0b01111111110,
				 0b01111111110,
				 0b01111111110,
				 0b00001110000,
				 0b00001110000,
				 0b00001110000};
			const struct PATTERN 	View_SchweizRed =  {
				 0b11111111111,
				 0b11110001111,
				 0b11110001111,
				 0b11110001111,
				 0b10000000001,
				 0b10000000001,
				 0b10000000001,
				 0b11110001111,
				 0b11110001111,
				 0b11110001111};
			writeNeo(&View_SchweizRed, &neo, &red);
			writeNeo(&View_SchweizWhite, &neo, &white);
			break;
		}
		
		case MODE_DCFDIAG:{
			clk.view_stream();
			if(tmrDiagPrintTime.ton(true,10000)){
				tmrDiagPrintTime.ton(false);
				clk.printDateTime();
			}
			break;
		}
		case MODE_CLOCK:{
			generateClockMatrix(&matrix, Hour, Minute);
			writeNeo(&matrix, &neo, &seq.actualColor, true);
			// Einzelne Minuten (1-4)
			//digitalWrite(PIN_1MIN, LOW);  digitalWrite(PIN_2MIN, LOW);  digitalWrite(PIN_3MIN, LOW);  digitalWrite(PIN_4MIN, LOW);
			switch(Minute%5){
				case 0:digitalWrite(PIN_1MIN, LOW);  digitalWrite(PIN_2MIN, LOW);  digitalWrite(PIN_3MIN, LOW);  digitalWrite(PIN_4MIN, LOW); break;
				case 1:digitalWrite(PIN_1MIN, HIGH); digitalWrite(PIN_2MIN, LOW);  digitalWrite(PIN_3MIN, LOW);  digitalWrite(PIN_4MIN, LOW); break; 
				case 2:digitalWrite(PIN_1MIN, HIGH); digitalWrite(PIN_2MIN, HIGH); digitalWrite(PIN_3MIN, LOW);  digitalWrite(PIN_4MIN, LOW); break; 
				case 3:digitalWrite(PIN_1MIN, HIGH); digitalWrite(PIN_2MIN, HIGH); digitalWrite(PIN_3MIN, HIGH); digitalWrite(PIN_4MIN, LOW); break; 
				case 4:digitalWrite(PIN_1MIN, HIGH); digitalWrite(PIN_2MIN, HIGH); digitalWrite(PIN_3MIN, HIGH); digitalWrite(PIN_4MIN, HIGH);break; 
				}
			break;
		}
		default:{
			state = MODE_CLOCK;
			break;
		}
	}
	neo.show();
}
