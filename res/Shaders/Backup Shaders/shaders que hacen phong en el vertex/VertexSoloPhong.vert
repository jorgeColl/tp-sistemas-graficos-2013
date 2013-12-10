#version 110

varying vec3 LightIntensity;

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

void getEyeSpace( out vec3 norm, out vec4 position ) {
	norm = normalize( NormalMatrix * gl_Normal);
	position = ViewMatrix * gl_Vertex;
}
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
	vec3 eyeNorm;
	vec4 eyePosition;
	// Get the position and normal in eye space
	getEyeSpace(eyeNorm, eyePosition);
	// Evaluate the lighting equation.
	LightIntensity = phongModel( eyePosition, eyeNorm );
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * gl_Vertex;
}









