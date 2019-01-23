#version 150
/*
#ifdef GL_ES
    precision highp float;
#endif
*/

uniform float u_time;
uniform sampler2DRect tex0;

//varying vec2 texCoordVarying;
in vec2 texCoordVarying;

out vec4 outputColor;

float random(vec2 c){
    return fract(sin(dot(c.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

const float interval = 3.0;

#define SHIFTDIFF 15.0

void main(void){

    float shfTime = 0.5*(sin(u_time + 0.5 * random(vec2(u_time))) + 1.0);
    if(shfTime>=0.8){
        shfTime /= 1.0;
    }
    else{
        shfTime = 0.0;
    }

    vec2 shake = vec2(
        sin(2*3.14*random(vec2(u_time, u_time))),
        sin(2*3.14*random(vec2(u_time, u_time)))
    );

    /*
    vec2 shake = vec2(
        2*random(vec2(u_time, texCoordVarying.x)),
        2*random(vec2(texCoordVarying.y, u_time))
    );
    */

    float shifHor = SHIFTDIFF*shfTime;
    float shifVer = 0.3*SHIFTDIFF*shfTime*random(vec2(u_time,u_time*u_time));
    float move = 0*1920*step(10000*0.5*(sin(0.001 * texCoordVarying.y + mod(0.01*random(vec2(u_time,u_time))*u_time, 1) + u_time-200)+1), 1000);
    float moveInv = 1.0;
    if(move==0.0){
        moveInv = -1.0;
    }
    float move2 = 10*step(9999.9 , 10000*0.5*(sin(0.001 * texCoordVarying.y + u_time+200)+1));

    float r = texture(tex0, shake + vec2(move - moveInv*(move2 + texCoordVarying.x + shifHor), texCoordVarying.y + shifVer)).r;
    float g = texture(tex0, shake + vec2(move - moveInv*(move2 + texCoordVarying.x),texCoordVarying.y)).g;
    float b = texture(tex0, shake + vec2(move - moveInv*(move2 + texCoordVarying.x - shifHor), texCoordVarying.y - shifVer)).b;

    float alpha = texture(tex0, texCoordVarying).a;

    float strength = smoothstep(interval * 0.5, interval, interval - mod(u_time, interval));
    float whiteNoise = (random(texCoordVarying + mod(u_time, 10.0)) * 2.0 - 1.0) * (0.15 + strength * 0.15);

    outputColor = vec4(r, g, b, alpha) + whiteNoise*0.5;

}
