//
//  MosaicShader.h
//
//  Created by Koichiro Mori on 2016/02/18.
//
//

#ifndef MosaicShader_h
#define MosaicShader_h

#include <stdio.h>
#include "ofMain.h"

#define NUM_GRID_DIVISIOIN 6

class MosaicShader
{
    
    public:
        MosaicShader(){};
        virtual ~MosaicShader(){};
        void setup(int width, int height);
        void draw(ofTexture &target);
        void setupFbo(int width, int height);
    
    private:
        ofShader shader;
        ofMesh mesh;
        ofFbo fbo;
    
};


#endif /* MosaicShader_h */
