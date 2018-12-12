#include "ColorSequencer.h"

//#define debug

ColorSequencer::ColorSequencer(	unsigned short color, 
								unsigned long speed,
								unsigned short maxBrightness, 
								int minBrightnessSum, 
								unsigned short LedRed, 
								unsigned short LedGreen,
								unsigned short LedBlue)
								{
	tick.ton(false);
	colorSel		= color;
	tickSpeed		= speed;
	maxBright		= maxBrightness;
	minBrightSum	= minBrightnessSum;
	lRed 			= LedRed;
	lGreen			= LedGreen;
	lBlue			= LedBlue;
}

void ColorSequencer::call(unsigned short Hour, bool init) {
	#ifdef debug
		Serial.print("colorSel: ");
		Serial.println(colorSel);
	#endif
	if(init and colorSel == 0){
		getNew();
		actualColor.r	=	showColor.r;
		actualColor.g	=	showColor.g;
		actualColor.b	=	showColor.b;
	}
	else if (colorSel == 0) { 		// random color
		if(tick.ton(true, tickSpeed)){
			tick.ton(false);
			if(actualColor.r > showColor.r)
				actualColor.r -= 1;
			if(actualColor.r < showColor.r)
				actualColor.r += 1;
			
			if(actualColor.g > showColor.g)
				actualColor.g -= 1;
			if(actualColor.g < showColor.g)
				actualColor.g += 1;
			
			if(actualColor.b > showColor.b)
				actualColor.b -= 1;
			if(actualColor.b < showColor.b)
				actualColor.b += 1;
			
			if(actualColor.r == showColor.r && actualColor.g == showColor.g && actualColor.b == showColor.b) {
				getNew();
			}
		}
	}
	else if (colorSel == 1) { 		// red
		actualColor.r = showColor.r	= maxBright;
		actualColor.g = showColor.g	= 0;
		actualColor.b = showColor.b	= 0;
	}
	else if (colorSel == 2) { 		// green
		actualColor.r = showColor.r	= 0;
		actualColor.g = showColor.g	= maxBright;
		actualColor.b = showColor.b	= 0;
	}
	else if (colorSel == 3) { 		// blue
		actualColor.r = showColor.r	= 0;
		actualColor.g = showColor.g	= 0;
		actualColor.b = showColor.b	= maxBright;
	}
	else if (colorSel == 4) { 		// white
		actualColor.r = showColor.r	= maxBright;
		actualColor.g = showColor.g	= maxBright;
		actualColor.b = showColor.b	= maxBright;
	}
	else if (colorSel == 5) { 		// individual
		actualColor.r = showColor.r	= lRed;
		actualColor.g = showColor.g	= lGreen;
		actualColor.b = showColor.b	= lBlue;
	}
	else if (colorSel == 6) { 		// depends on time
		if (Hour > 4 && Hour <= 6) {	// 4 hour to 6 hour
			actualColor.r = showColor.r	= 0;
			actualColor.g = showColor.g	= 245;
			actualColor.b = showColor.b	= 255;
		}
		else if (Hour > 6 && Hour <= 8) {	// 6 hour to 8 hour
			actualColor.r = showColor.r	= 193;
			actualColor.g = showColor.g	= 255;
			actualColor.b = showColor.b	= 193;
		}
		else if (Hour > 8 && Hour <= 10) {	// 8 hour to 10 hour
			actualColor.r = showColor.r	= 0;
			actualColor.g = showColor.g	= 255;
			actualColor.b = showColor.b	= 0;
		}
		else if (Hour > 10 && Hour <= 12) {	// 10 hour to 12 hour
			actualColor.r = showColor.r	= 255;
			actualColor.g = showColor.g	= 255;
			actualColor.b = showColor.b	= 0;
		}
		else if (Hour > 12 && Hour <= 14) {	// 12 hour to 14 hour
			actualColor.r = showColor.r	= 255;
			actualColor.g = showColor.g	= 48;
			actualColor.b = showColor.b	= 48;
		}
		else if (Hour > 14 && Hour <= 16) {	// 14 hour to 16 hour
			actualColor.r = showColor.r	= 255;
			actualColor.g = showColor.g	= 52;
			actualColor.b = showColor.b	= 179;
		}
		else if (Hour > 16 && Hour <= 18) {	// 16 hour to 18 hour
			actualColor.r = showColor.r	= 191;
			actualColor.g = showColor.g	= 62;
			actualColor.b = showColor.b	= 255;
		}
		else if (Hour > 18 && Hour <= 20) {	// 18 hour to 20 hour
			actualColor.r = showColor.r	= 131;
			actualColor.g = showColor.g	= 111;
			actualColor.b = showColor.b	= 255;
		}
		else if (Hour > 20 && Hour <= 22) {	// 20 hour to 22 hour
			actualColor.r = showColor.r	= 0;
			actualColor.g = showColor.g	= 0;
			actualColor.b = showColor.b	= 255;
		}
		else {// (Hour > 22 || Hour <= 4) {		// 22 hour to 4 hour
			actualColor.r = showColor.r	= 0;
			actualColor.g = showColor.g	= 0;
			actualColor.b = showColor.b	= 128;
		}


	}
	else { 							// fallback
		actualColor.r = showColor.r	= 10;
		actualColor.g = showColor.g	= 10;
		actualColor.b = showColor.b	= 10;
	}
	#ifdef debug
		Serial.print("ActHour: ");
		Serial.println(ActHour);
		Serial.print("Colors r: ");
		Serial.print(showColor.r);
		Serial.print(" g: ");
		Serial.print(showColor.g);
		Serial.print(" b: ");
		Serial.println(showColor.b);
	#endif
}

void ColorSequencer::getNew(){
	do{
		showColor.r		= random(maxBright);
		showColor.g		= random(maxBright);
		showColor.b		= random(maxBright);
	}while( (showColor.r + showColor.g + showColor.b) < minBrightSum);
}