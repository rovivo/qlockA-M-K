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
						unsigned short maxBrightness=255, 
						int minBrightnessSum=250, 
						unsigned short LedRed	=  50, 
						unsigned short LedGreen = 100,
						unsigned short LedBlue	= 150);

		void call(unsigned short Hour, bool init=false);
		void getNew();
		RGB actualColor = {50,50,50};
		
	private:
		unsigned short  colorSel;
		unsigned long	tickSpeed;
		unsigned short	maxBright;
		int				minBrightSum;
		unsigned short  lRed;
		unsigned short  lGreen;
		unsigned short  lBlue;
		RGB showColor = {50,50,50};
		Timer tick;

};


#endif