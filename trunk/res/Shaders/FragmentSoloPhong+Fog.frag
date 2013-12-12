#version 120

varying  vec3 Normal_eye;
varying  vec4 Position_eye;

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

float getFogFactor (float positionZ) {
	float dist = abs (positionZ);
	float fogFactor = (FogMaxDist - dist) / (FogMaxDist - FogMinDist);
	return clamp (fogFactor, 0.0, 1.0);
}

void main() {
	// Calculo del fog factor
	float fogFactor = getFogFactor (Position_eye.z);
	
	// Se obtiene el color de la malla, se lo mezcla con la niebla y se construye el color del fragmento
	vec3 shadeColor = phongModel (Position_eye, Normal_eye);
	vec3 color = mix (FogColor, shadeColor, fogFactor);
	gl_FragColor = vec4(color, 1.0);
}
