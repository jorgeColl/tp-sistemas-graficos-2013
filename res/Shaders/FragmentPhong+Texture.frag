#version 110

varying vec3 Normal_eye;
varying vec4 Position_eye;
varying vec2 TexCoord;

// PROPIEDADES DE LA LUZ , LUZ DEL ENTORNO
uniform vec4 LightPosition; // Light position in eye coords.
uniform vec3 La; // Ambient light intensity
uniform vec3 Ld; // Diffuse light intensity
uniform vec3 Ls; // Specular light intensity

// PROPIEDADES DEL MATERIAL
uniform vec3 Ka; // Ambient reflectivity (0<= ka <=1)
uniform vec3 Kd; // Diffuse reflectivity
uniform vec3 Ks; // Specular reflectivity ( max es (1,1,1) min es (0,0,0) )
uniform float Shininess; // Specular shininess factor

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;

// COORDENADA DE LA TEXTURA
uniform sampler2D Tex1;

vec3 phongModel( vec4 position, vec3 norm ) {	
	vec3 s = normalize(vec3(LightPosition - position));
	vec3 v = normalize(-position.xyz);
	vec3 r = reflect( -s, norm );
	vec3 ambient = La * Ka;
	float sDotN = max( dot(s,norm), 0.0 );
	vec3 diffuse = Ld * Kd * sDotN;
	vec3 spec = vec3(0.0);
	if( sDotN > 0.0 )
		spec = Ls * Ks * pow( max( dot(r,v), 0.0 ), Shininess );
	return ambient + diffuse + spec;
	//return diffuse;
	//return ambient;
	//return spec;
}

void main() {
	vec4 texColor = texture2D( Tex1, TexCoord );
	vec3 LightIntensity = phongModel( Position_eye, Normal_eye );
	gl_FragColor  = texColor * vec4 (LightIntensity, 1.0);
}
