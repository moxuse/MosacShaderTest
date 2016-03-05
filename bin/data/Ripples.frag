#version 120

uniform sampler2DRect baseTexture;
uniform sampler2DRect targetTexture;


void main() {
    float modRadius = 100;
    
    vec2 uv = gl_TexCoord[0].st;
    
    float modX = sin(texture2DRect(baseTexture, uv).r * 6.0) * modRadius;
    float modY = -cos(texture2DRect(baseTexture, uv).g * 6.0) * modRadius;
    
    vec2 modUv = uv + vec2(modX, modY);
    gl_FragColor = texture2DRect(targetTexture, uv) + texture2DRect(targetTexture, modUv);
    
}
