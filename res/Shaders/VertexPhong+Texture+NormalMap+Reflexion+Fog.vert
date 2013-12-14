#version 120

// PROPIEDADES DEL PUNTO
varying vec3 Position_eye;
varying vec3 LightDir;
varying vec2 TexCoord;
varying vec3 ViewDir;
varying vec3 ReflectDir;


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

// MATRICES
uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;

// PARA EL REFLEJO DEL MUNDO
uniform vec3 WorldCameraPosition;

void getEyeSpace( out vec3 norm, out vec3 tang, out vec3 position ) {
	norm = normalize (NormalMatrix * gl_Normal);
	tang = normalize(NormalMatrix * vec3(gl_Color));
	position = vec3 (ViewMatrix * ModelMatrix * gl_Vertex);
}

void main() {
	// Get the position and normal in eye space
	vec3 normal_eye;
	vec3 tangent_eye;
	getEyeSpace (normal_eye, tangent_eye, Position_eye);
	// Compute the binormal
	vec3 binormal = normalize( cross( normal_eye, tangent_eye ) ) * gl_Color.w;
	// Matrix for transformation to tangent space
	mat3 toObjectLocal = mat3(	tangent_eye.x, binormal.x, normal_eye.x,
								tangent_eye.y, binormal.y, normal_eye.y,
								tangent_eye.z, binormal.z, normal_eye.z ) ;

	LightDir = normalize( toObjectLocal * (LightPosition.xyz - Position_eye) );
	ViewDir = toObjectLocal * normalize(-Position_eye);

	// Pasamos la posicion
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * gl_Vertex;
	// Pasamos las coordenadas de texturas a los FShaders
	TexCoord = gl_MultiTexCoord0.xy;
	
	
	// para el reflejo
	vec3 worldPos = vec3( ModelMatrix * gl_Vertex );
	vec3 worldNorm = normalize (vec3 (ModelMatrix * vec4(gl_Normal,0.0))) ;
	vec3 worldView = normalize( WorldCameraPosition - worldPos ); 
	ReflectDir = reflect(-worldView, worldNorm );
}









