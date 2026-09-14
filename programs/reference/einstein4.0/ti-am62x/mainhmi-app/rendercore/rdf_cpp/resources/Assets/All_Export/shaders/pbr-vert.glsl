attribute vec4 a_Position;
attribute vec2 a_UV0;
uniform mat4 u_MVPMatrix;
varying vec2 v_UV0;

void main()
{
  v_UV0 = a_UV0;
  gl_Position = u_MVPMatrix * a_Position; // needs w for proper perspective correction
}


