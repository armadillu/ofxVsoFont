//
//  ofxVsoFont.h
//  fontsExample
//
//  Created by Oriol Ferrer Mesià on 22/05/12.
//  Copyright (c) 2012 uri.cat. All rights reserved.
//

/*
 
 The MIT License
 
 Copyright (c) 2012, Oriol Ferrer Mesià.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */


// TODO: implement getBoundingBoxSize() for text with multiple lines!

#ifndef ofxVsoFont_h
#define ofxVsoFont_h

#include "ofMain.h"

extern "C" {
	#include "defines.h"
	#include "vsofont.h"
}


class ofxVsoFont{

	public:
		
		ofxVsoFont();
		~ofxVsoFont();
	
		//call this to set your font file (.vsofont)
		bool setup( string fontFile, float lineHeightPercent = 1.0f );
	
		void setColor( float r, float g, float b, float a );
		void setSpacing( float s );
	
		void draw( string text, float x, float y, bool centered );
		void drawMultiLine( string text, float x, float y, bool centered );
		
		ofRectangle getBoundingBoxSize( string text, float x, float y );

	private:
		
		struct vsofont *font;
		float lineHeight;
	
};


#endif
