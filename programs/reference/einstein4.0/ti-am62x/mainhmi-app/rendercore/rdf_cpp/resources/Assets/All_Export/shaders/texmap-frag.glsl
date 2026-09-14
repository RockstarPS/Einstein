//
// This fragment shader defines a reference implementation for simple texture mapping.
//
precision highp float;
uniform sampler2D baseColorTexture;
uniform vec4 baseColorFactor;
varying vec2 v_UV0;
uniform float u_Opacity;
void main()
{
    lowp vec4 baseColor = texture2D(baseColorTexture, v_UV0) * baseColorFactor;
	baseColor.a = baseColor.a * u_Opacity;
    gl_FragColor = baseColor;
}
