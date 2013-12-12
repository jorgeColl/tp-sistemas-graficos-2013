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

// COORDENADA DE LA TEXTURA
uniform sampler2D Tex1;
uniform sampler2D NormalMapTex;

vec3 phongModel( vec3 norm, vec3 diffR ) {
	vec3 r = reflect( -LightDir, norm );
	vec3 ambient = La * Ka;
	float sDotN = max( dot(LightDir, norm), 0.0 );
	vec3 diffuse = Ld * diffR * sDotN;
	vec3 spec = vec3(0.0);
	if( sDotN > 0.0 )
		spec = Ls * Ks * pow( max( dot(r,ViewDir), 0.0 ), Shininess );
	return ambient + diffuse + spec;
}

void main() {
	//vec4 texColor = texture2D( Tex1, TexCoord );
	//    //vec3 LightIntensity = phongModel( Position_eye, Normal_eye );
	//vec3 LightIntensity = vec3 (0.5,0.5,0.5);
	//gl_FragColor  = texColor * vec4 (LightIntensity, 1.0);
	
	// Lookup the normal from the normal map
	vec4 normal = texture2D( NormalMapTex, TexCoord );
	// The color texture is used as the diffuse reflectivity
	vec4 texColor = texture2D( Tex1, TexCoord );
	gl_FragColor = vec4( phongModel(normal.xyz, texColor.rgb),1.0 );

}
