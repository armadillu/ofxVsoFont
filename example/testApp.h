#pragma once

#include "ofMain.h"
#include "ofxVsoFont.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void draw();
		
		void drawPoint(float x, float y);

		ofxVsoFont font;
};
