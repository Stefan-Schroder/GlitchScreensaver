#include "ofApp.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//--------------------------------------------------------------
void ofApp::setup() {
    /*
#ifdef TARGET_OPENGLES
	shader.load("shadersES2/shader");
#else
	if(ofIsGLProgrammableRenderer()){
		shader.load("shadersGL3/shader");
	}else{
		shader.load("shadersGL2/shader");
	}
#endif
    */

    shader.load("shader/vs.vert", "shader/fs.frag");
    img.load("wallpaper.png");

    plane.set(1920, 1080);
    plane.mapTexCoords(0, 1080, 1920, 0);
    //plane.mapTexCoords(0, 0, img.getWidth(), img.getHeight());


    srand (time(NULL));
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

    // bind our texture. in our shader this will now be tex0 by default
    // so we can just go ahead and access it there.
    img.getTexture().bind();

    // start our shader, in our OpenGL3 shader this will automagically set
    // up a lot of matrices that we want for figuring out the texture matrix
    // and the modelView matrix
    shader.begin();

    // get mouse position relative to center of screen
    float mousePosition = ofMap(mouseX, 0, ofGetWidth(), 1.0, -1.0, true);
#ifndef TARGET_OPENGLES
    // when texture coordinates are normalised, they are always between 0 and 1.
    // in GL2 and GL3 the texture coordinates are not normalised,
    // so we have to multiply the normalised mouse position by the plane width.
    mousePosition *= plane.getWidth();
#endif

    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform1f("rand_1", rand() % 1000 + 1);
    shader.setUniform1f("rand_2", rand() % 1000 + 1);
    shader.setUniform1f("rand_3", rand() % 1000 + 1);
    shader.setUniform1f("rand_4", rand() % 1000 + 1);
    shader.setUniform1f("rand_5", rand() % 1000 + 1);
    shader.setUniform1f("rand_6", rand() % 1000 + 1);
    //shader.setUniform1f("u_time", ofGetElapsedTimeMillis());

    shader.setUniform1f("mouseX", mousePosition);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    plane.draw();

    ofPopMatrix();

    shader.end();

    img.getTexture().unbind();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
