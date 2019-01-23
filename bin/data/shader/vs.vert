/*
attribute vec4 a_position;
attribute vec2 a_texCoord0;
uniform mat4 u_projTrans;
varying vec2 v_texCoords;


void main(){
    v_texCoords = a_texCoord0;
    //varyingTexCoord = a_texCoord0;
    gl_Position = u_projTrans * a_position;
}
*/
#version 150

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

// this is something we're creating for this shader
out vec2 texCoordVarying;

// this is coming from our C++ code
//uniform float mouseX;

void main()
{
    // here we move the texture coordinates
    //texCoordVarying = vec2(texcoord.x + mouseX, texcoord.y);
    texCoordVarying = texcoord;

    // send the vertices to the fragment shader
	gl_Position = modelViewProjectionMatrix * position;
}