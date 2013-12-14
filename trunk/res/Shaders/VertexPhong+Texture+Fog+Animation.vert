#version 120

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

// PROPIEDADES DE LA NIEBLA
uniform float FogMaxDist;
uniform float FogMinDist;
uniform vec3  FogColor;

// PROPIEDADES DE LA ANIMACION SENOIDAL
uniform float Amp;
uniform float WaveNumber;
uniform float Velocity;
uniform float Time;

// MATRICES
uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;


void getAnimatedPositionAndNormal (out vec3 norm, out vec4 position) {
	norm = gl_Normal;
	position = gl_Vertex;
	float posY = position.y;
	float posZ = position.z;
	
	float u = WaveNumber * (posZ - Velocity * Time);
	float coeficient = clamp (posZ, 0.0, 1.0);
	
	// Translate the y coordinate
	position.y = (posY + coeficient * Amp * sin(u));
	
	// Compute the normal vector
	norm.z = (-WaveNumber * coeficient * Amp * cos(u));
	norm = normalize (norm);
}

void getEyeSpace (out vec3 norm, out vec4 position) {
	vec3 animatedNorm;
	vec4 animatedPosition;
	getAnimatedPositionAndNormal (animatedNorm, animatedPosition);
	norm = normalize (NormalMatrix * animatedNorm);
	position = ViewMatrix * ModelMatrix * animatedPosition;
}

void main() {
	vec3 eyeNorm;
	vec4 eyePosition;
	// Get the position and normal in eye space
	getEyeSpace(Normal_eye, Position_eye);
	// Pasamos la posicion
	gl_Position = ProjectionMatrix * Position_eye;
	// Pasamos las coordenadas de texturas a los FShaders
	TexCoord = gl_MultiTexCoord0.xy;
}









