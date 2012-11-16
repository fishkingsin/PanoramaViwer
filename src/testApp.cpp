#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0,0,0);
	
	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	
	glEnable(GL_DEPTH_TEST); //enable depth comparisons and update the depth buffer
	ofDisableArbTex(); //needed for textures to work with gluSphere
	earth.loadImage("earth.jpg");
	
	//prepare quadric for sphere
	quadric = gluNewQuadric();
	gluQuadricTexture(quadric, GL_TRUE);
	gluQuadricNormals(quadric, GLU_SMOOTH);
}

//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	
	//change origin to center
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
	
	//rotate sphere over time
	ofRotateY(ofGetFrameNum());
	ofRotateX(-90); //north pole facing up
	
	//bind and draw texture
	earth.getTextureReference().bind();
	gluSphere(quadric, ofGetWidth(), 100, 100);
	earth.getTextureReference().unbind();
	
}
void testApp::dragEvent(ofDragInfo dragInfo) {
	if(dragInfo.files.size()==1)
	{
		ofFile file= dragInfo.files[0];
		if(file.getExtension()=="JPG" || file.getExtension()=="jpg")
		{
			ofDisableArbTex();
			earth.loadImage(file);
		}
	}
}
