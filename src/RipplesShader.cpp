//
//  RipplesShader.cpp
//  ISH
//
//  Created by Koichiro Mori on 2016/02/18.
//
//

#include "RipplesShader.h"


//--------------------------------------------------------------
void RipplesShader::setup(int width, int height)
{
    shader.load("Ripples");
    fbo.allocate(width, height);
    
    this->setupFbo(width, height);
}

//--------------------------------------------------------------
void RipplesShader::draw(ofTexture &target)
{
    ofClear(0, 0, 0, 0);
    fbo.begin();
    {
        mesh.draw();
    }
    fbo.end();
    
    //fbo.draw(0, 0);
    
    fbo.getTexture().bind();
    target.bind();
    
    shader.begin();
    {
        shader.setUniformTexture("targetTexture", target, 0);
        shader.setUniformTexture("baseTexture", fbo.getTexture(), 1);

        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        glBegin(GL_QUADS);
        glTexCoord2f(0 , 0);
        glVertex2f(0, 0);
        glTexCoord2f(ofGetWidth(), 0);
        glVertex2f(ofGetWidth(), 0);
        glTexCoord2f(ofGetWidth(), ofGetHeight());
        glVertex2f(ofGetWidth(), ofGetHeight());
        glTexCoord2f(0, ofGetHeight());
        glVertex2f(0, ofGetHeight());
        glEnd();
    }
    shader.end();

    fbo.getTexture().unbind();
    target.unbind();
}


//--------------------------------------------------------------
void RipplesShader::setupFbo (int width, int height)
{
    fbo.clear();
    
    fbo.allocate(width, height);
    
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    const float section_width = width / NUM_GRID_DIVISIOIN;
    const float section_height = height / NUM_GRID_DIVISIOIN;
    
    for (int i = 0; i < NUM_GRID_DIVISIOIN; i++)
    {
        for (int j = 0; j < NUM_GRID_DIVISIOIN; j++)
        {
            const float x_ = i * section_width;
            const float y_ = j * section_height;
            
            const ofFloatColor ca_ = ofFloatColor(ofRandom(1.0), ofRandom(1.0) , ofRandom(1.0));
            const ofFloatColor cb_ = ofFloatColor(ofRandom(1.0), ofRandom(1.0) , ofRandom(1.0));
            const ofFloatColor cc_ = ofFloatColor(ofRandom(1.0), ofRandom(1.0) , ofRandom(1.0));
            const ofFloatColor cd_ = ofFloatColor(ofRandom(1.0), ofRandom(1.0) , ofRandom(1.0));
            
            mesh.addVertex(ofVec3f(x_ - section_width * 0.5, y_ ,0));
            mesh.addVertex(ofVec3f(x_ + section_width * 0.5, y_ ,0));
            mesh.addVertex(ofVec3f(x_, y_ + section_height ,0));
            
            mesh.addColor(ca_); //A
            mesh.addColor(cb_); //B
            mesh.addColor(cc_); //C
            
            mesh.addVertex(ofVec3f(x_ + section_width, y_ + section_height, 0));
            mesh.addVertex(ofVec3f(x_ + section_width * 0.5, y_ ,0));
            mesh.addVertex(ofVec3f(x_, y_ + section_height ,0));
            
            mesh.addColor(cd_); //D
            mesh.addColor(cc_); //B
            mesh.addColor(cb_); //C
        }
    }
    mesh.setupIndicesAuto();
}
