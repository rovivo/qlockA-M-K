#include "ColorSequencer.h"

#define debug

ColorSequencer::ColorSequencer(	unsigned short ActHour,
								unsigned short color, 
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

void ColorSequencer::call(bool init) {
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
	else if (colorSel == 0) { 
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