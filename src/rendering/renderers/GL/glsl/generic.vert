
varying vec3 v;
varying out vec2 uv;
attribute vec4 gl_MultiTexCoord0;


void main(void)
{

    v = vec3(gl_ModelViewMatrix * gl_Vertex);       
   N = normalize(gl_NormalMatrix * gl_Normal);

   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
gl_TexCoord[0] = gl_MultiTexCoord0;
		gl_Position = ftransform();

}

