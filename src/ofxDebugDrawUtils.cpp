//
//  ofxDebugDrawUtils.cpp
//  AllTrackers
//
//  Created by Oriol Ferrer Mesià on 27/04/2018.
//
//

#include "ofxDebugDrawUtils.h"

void ofxDebugDrawUtils::drawArrow(ofMesh & m, const glm::vec2 & src, const glm::vec2 & dst, float headSize, bool colorize, const ofColor & c){

	auto src3 = glm::vec3(src, 0);
	auto dst3 = glm::vec3(dst, 0);
	m.addVertex(src3);
	m.addVertex(dst3);
	auto idir = glm::normalize(src - dst);
	const float arrowHeadAng = 45 * DEG_TO_RAD;
	auto right = glm::vec3(glm::rotate(idir, arrowHeadAng), 0);
	auto left = glm::vec3(glm::rotate(idir, -arrowHeadAng), 0);
	m.addVertex(dst3);
	m.addVertex(dst3 + right * headSize);
	m.addVertex(dst3);
	m.addVertex(dst3 + left * headSize);
	if(colorize){
		for(int i = 0; i < 6; i++){
			m.addColor(c);
		}
	}
}