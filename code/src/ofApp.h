#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"


class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		
    ofSnake mySnake{};
	ofFood myFood{};

	bool gameStarted = false;
	bool gameOver = false;
	float gameOverTime;
    
};
