#version 430
out vec4 color;	// out indicates vec4 color is an output
void main(void)
{
if(gl_FragCoord.x < 295)color = vec4(1,0,0,1); else color = vec4(0,0,1,1);
}	// If the pixel's x position is <295 then the fragment color is red, else its blue.
