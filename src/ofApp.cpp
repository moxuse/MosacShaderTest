#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(36);
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    
    shader.setup(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofClear(0, 0, 0, 0);
    
    fbo.begin();
    {
        ofClear(0, 0, 0, 0);
        ofNoFill();
        ofSetColor(255, 255, 255);
        ofSetLineWidth(6);
        for (int i = 0; i < 5; i++) {
            ofDrawCircle(mouseX, mouseY, 200 - i * 25);
        }
    }
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){

    shader.draw(fbo.getTexture());

}

