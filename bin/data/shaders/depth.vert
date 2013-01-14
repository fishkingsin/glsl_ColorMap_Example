varying float  oriBrightness;
uniform sampler2DRect tex;
varying vec2  TexCoord;
uniform int maxHeight;
varying vec4 newVertexPos;
void main(void)
{
	gl_TexCoord[0] = gl_MultiTexCoord0;
	TexCoord = gl_MultiTexCoord0.st;

	vec4 bumpColor = texture2DRect(tex, gl_TexCoord[0].st);
	float df = 0.30*bumpColor.x + 0.59*bumpColor.y + 0.11*bumpColor.z;
	newVertexPos = vec4(gl_Normal * df * float(maxHeight), 0.0) + gl_Vertex;

	gl_Position = gl_ModelViewProjectionMatrix * newVertexPos;
}