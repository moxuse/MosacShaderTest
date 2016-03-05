#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
//    ofGLWindowSettings setting;
//    setting.setGLVersion(3,2);
//    ofCreateWindow(setting);

    ofSetupOpenGL(1024, 768,OF_WINDOW);
	
    ofRunApp(new ofApp());

}
