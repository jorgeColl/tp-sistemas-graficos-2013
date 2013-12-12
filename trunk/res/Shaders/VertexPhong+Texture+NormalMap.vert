#version 120

varying vec3 LightDir;
varying vec2 TexCoord;
varying vec3 ViewDir;

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

void getEyeSpace( out vec3 norm, out vec3 tang, out vec3 position ) {
	norm = normalize( NormalMatrix * gl_Normal);
	tang = normalize(NormalMatrix * vec3(gl_SecondaryColor));
	position = vec3 (ViewMatrix * gl_Vertex);
}

void main() {
	// Get the position and normal in eye space
	vec3 normal_eye;
	vec3 position_eye;
	vec3 tangent_eye;
	getEyeSpace (normal_eye, tangent_eye, position_eye);
	// Compute the binormal
	vec3 binormal = normalize( cross( normal_eye, tangent_eye ) ) * gl_SecondaryColor.w;
	// Matrix for transformation to tangent space
	mat3 toObjectLocal = mat3(	tangent_eye.x, binormal.x, normal_eye.x,
								tangent_eye.y, binormal.y, normal_eye.y,
								tangent_eye.z, binormal.z, normal_eye.z ) ;

	LightDir = normalize( toObjectLocal * (LightPosition.xyz - position_eye) );
	ViewDir = toObjectLocal * normalize(-position_eye);

	// Pasamos la posicion
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * gl_Vertex;
	// Pasamos las coordenadas de texturas a los FShaders
	TexCoord = gl_MultiTexCoord0.xy;
	
}









