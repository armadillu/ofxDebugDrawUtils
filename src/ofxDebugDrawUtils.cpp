//
//  ofxDebugDrawUtils.cpp
//  AllTrackers
//
//  Created by Oriol Ferrer Mesià on 27/04/2018.
//
//

#include "ofxDebugDrawUtils.h"

void ofxDebugDrawUtils::drawArrow(ofMesh & m, const glm::vec2 & src, const glm::vec2 & dst, float headSize,
								  float headAngle, bool shrinkHeadSizeToVectorLen, bool colorize, const ofColor & c){

	ofIndexType firstIndex = m.getVertices().size();
	
	auto src3 = glm::vec3(src, 0);
	auto dst3 = glm::vec3(dst, 0);
	auto idir = glm::normalize(src - dst);
	float arrowHeadAng = headAngle * DEG_TO_RAD;
	auto right = glm::vec3(glm::rotate(idir, arrowHeadAng), 0);
	auto left = glm::vec3(glm::rotate(idir, -arrowHeadAng), 0);

	float headScale = 1.0f;
	if(shrinkHeadSizeToVectorLen){
		headScale = ofMap(glm::distance(src3, dst3) * 0.85f, 0.0f, headSize, 0.15f, 1.0f, true);
	}

	m.addVertex(src3); 						// 0
	m.addVertex(dst3); 						// 1
	m.addVertex(dst3 + right * headSize * headScale); 	// 2
	m.addVertex(dst3 + left * headSize * headScale); 	// 3

	vector<ofIndexType> indices = {	ofIndexType(firstIndex + 0), 
									ofIndexType(firstIndex + 1), //main line
									ofIndexType(firstIndex + 1), 
									ofIndexType(firstIndex + 2), //left arrow line
									ofIndexType(firstIndex + 1), 
									ofIndexType(firstIndex + 3)
									};
	m.addIndices( indices );
	if(colorize){
		m.addColors({c,c,c,c});
	}
}