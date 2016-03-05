#pragma once

#include "ofMain.h"
#include "MosaicShader.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    private:
        MosaicShader shader;
        ofFbo fbo;
};
