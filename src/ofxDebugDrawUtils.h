//
//  ofxDebugDrawUtils.h
//  AllTrackers
//
//  Created by Oriol Ferrer Mesià on 27/04/2018.
//
//

#pragma once
#include "ofMain.h"

class ofxDebugDrawUtils{

public:

	static void drawArrow(ofMesh & m, const glm::vec2 & src, const glm::vec2 & dst,
						  float headSize, float headAngle = 30, bool colorize = false, const ofColor & c = ofColor::black);

};

