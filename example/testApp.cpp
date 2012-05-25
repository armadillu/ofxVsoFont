#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(22, 22, 22, 255);
	ofEnableSmoothing();

	font.setup("example.vsofont", 1.5); //load verdana font, set lineHeight to be 130%
	font.setSpacing(1.3);
}


//--------------------------------------------------------------
void testApp::draw(){
	
	float x = 50;
	float y = 50;	
	string demoText = "This is my text drawn using vsofont: left aligned";
	
	// draw demo: left aligned /////////////////////////////////////////////
	
	drawPoint(x, y);		//draw insertion point
	
	font.setColor(1, 1, 1, 1);
	font.draw(
			  demoText,		//text to draw
			  x,			//x coord where to draw
			  y,			//y coord where to draw
			  false			//not centered
			  );


	// bounding box demo ///////////////////////////////////////////////////
	
	ofSetColor(255, 0, 0, 64);
	ofRectangle bbox = font.getBoundingBoxSize( demoText, x, y);
	ofRect( bbox );

	
	// draw demo: centered /////////////////////////////////////////////////
	
	x = ofGetWidth()/2;
	y = 100;
	
	drawPoint(x, y);		//draw insertion point	
	demoText = "This is my text drawn using vsofont: centered";
	font.draw(
			  demoText,		//text to draw
			  x,			//x coord where to draw
			  y,			//y coord where to draw
			  true			//centered
			  );
	
	
	// draw multiline text /////////////////////////////////////////////////
	
	x = ofGetWidth()/2;
	y = ofGetHeight()/2;
	
	drawPoint(x, y);		//draw insertion point

	font.setColor(1, 0, 1, 1);
	string s = (string)"this paragraph has" + "\n" + "multiple lines.";
	font.drawMultiLine( s, x, y, false /*not centered*/ );
		
	
	// draw numbers ///////////////////////////////////////////////////////
	font.draw( ofToString( ofGetFrameRate(), 2), 20, ofGetHeight() - 20, false);
}

void testApp::drawPoint(float x, float y){

	ofSetColor(0, 255, 0, 128);	
	ofCircle(x, y, 2);
}

