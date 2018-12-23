#ifndef ColorSequencer_h
#define ColorSequencer_h

#include <Arduino.h>
#include "Constants.h"
#include "Timer.h"

class ColorSequencer
{
	public:
		ColorSequencer(	unsigned short color=0, 
						unsigned long speed=1000, 
						byte maxBrightness=255, 
						byte minBrightnessSum=250, 
						byte LedRed		=  50, 
						byte LedGreen 	= 100,
						byte LedBlue	= 150);

		void call(unsigned short Hour, bool init=false);
		void getNew();
		RGB actualColor = {50,50,50};
		
	private:
		unsigned short  colorSel;
		unsigned long	tickSpeed;
		byte  maxBright;
		byte  minBrightSum;
		byte  lRed;
		byte  lGreen;
		byte  lBlue;
		RGB showColor = {50,50,50};
		Timer tick;

};


#endif