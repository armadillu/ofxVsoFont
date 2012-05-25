//
//  ofxVsoFont.cpp
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


#include <iostream>
#include "ofxVsoFont.h"

ofxVsoFont::ofxVsoFont(){
	lineHeight = 1.0f;
	font = NULL;
}

ofxVsoFont::~ofxVsoFont(){
	if(font != NULL) vsofont_free(font);
}

bool ofxVsoFont::setup( string fontFile, float lineHeightPercent ){
	
	if ( font == NULL ){
		int r = vsofont_read_font_from_file( (char*)ofToDataPath(fontFile).c_str() , &font);
		lineHeight = lineHeightPercent;
		if ( r == SUCCEEDED){
			printf("ofxVsoFont : loaded font %s\n", fontFile.c_str() );
			return true;
		}else{
			printf("ofxVsoFont : Can't load font! %s\n", fontFile.c_str() );
		}
	}else{
		printf("ofxVsoFont : don't call setup() more than once! %s\n", fontFile.c_str() );
	}
	return false;
}


void ofxVsoFont::setSpacing( float s ){
	if (font != NULL){
		vsofont_set_spacing(font, s);
	}else{
		printf("ofxVsoFont : can't setSpacing() without having been setup first!\n");
	}		
}


void ofxVsoFont::setColor( float r, float g, float b, float a ){
	if (font != NULL){
		vsofont_set_color(font, r, g, b, a);
	}else{
		printf("ofxVsoFont : can't setColor() without having been setup first!\n");
	}		
}

void ofxVsoFont::draw( string text, float x, float y , bool centered){
	
	glEnableClientState(GL_VERTEX_ARRAY);
	if (font != NULL){
		if(centered)
			vsofont_write_string_2D_centered(font, (char*)text.c_str(), x, y);		
		else
			vsofont_write_string_2D(font, (char*)text.c_str(), x, y);		
	}else{
		printf("ofxVsoFont : can't draw() without having been setup first!\n");
	}		
}

void ofxVsoFont::drawMultiLine( string text, float x, float y, bool centered ){

	
	if (font != NULL){
		
		stringstream ss(text);
		string s;
		int line = 0;
		while ( getline(ss, s, '\n') ) {
			//cout << s << endl;
			if(centered)
				vsofont_write_string_2D_centered(font, (char*)s.c_str(), x, y + fabs(font->scale_y) * lineHeight * line);		
			else
				vsofont_write_string_2D(font, (char*)s.c_str(), x, y + fabs(font->scale_y) * lineHeight * line);		
			line ++;
		}
		
	}else{
		printf("ofxVsoFont : can't drawMultiLine() without having been setup first!\n");
	}		
}

ofRectangle ofxVsoFont::getBoundingBoxSize( string text, float x, float y ){

	ofRectangle r;
	
	if (font != NULL){

		float w = vsofont_get_string_width(font, (unsigned char*)text.c_str());
		r.width = w;
		r.height = fabs(font->scale_y);
		r.x = x;
		r.y = y - r.height;
	}else{
		printf("ofxVsoFont : can't getBoundingBoxSize() without having been setup first!\n");
	}		
		
	return r;
}
