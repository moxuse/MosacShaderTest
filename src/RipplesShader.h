//
//  RipplesShader.h
//  ISH
//
//  Created by Koichiro Mori on 2016/02/18.
//
//

#ifndef RipplesShader_h
#define RipplesShader_h

#include <stdio.h>
#include "ofMain.h"

#define NUM_GRID_DIVISIOIN 6

class RipplesShader
{
    
    public:
        RipplesShader(){};
        virtual ~RipplesShader(){};
        void setup(int width, int height);
        void draw(ofTexture &target);
        void setupFbo(int width, int height);
    
    private:
        ofShader shader;
        ofMesh mesh;
        ofFbo fbo;
    
};


#endif /* RipplesShader_h */
