#pragma once

#include "ofMain.h"
#include "RipplesShader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    private:
        RipplesShader shader;
        ofFbo fbo;
};
