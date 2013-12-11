#version 130

varying  vec3 Normal_eye;
varying  vec4 Position_eye;
varying  vec2 TexCoord;

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

void main() {
	vec3 eyeNorm;
	vec4 eyePosition;
	// Get the position and normal in eye space
	getEyeSpace(Normal_eye, Position_eye);
	// Pasamos la posicion
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * gl_Vertex;
	// Pasamos las coordenadas de texturas a los FShaders
	TexCoord = gl_MultiTexCoord0.xy;
}









