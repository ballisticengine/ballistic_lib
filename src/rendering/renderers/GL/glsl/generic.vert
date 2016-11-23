
varying vec3 v;



void main(void)
{

   v = vec3(gl_ModelViewMatrix * gl_Vertex);       
 

   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
  
    
    gl_Position = ftransform();

}

