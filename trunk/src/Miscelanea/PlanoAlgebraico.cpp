#include "PlanoAlgebraico.h"


PlanoAlgebraico::PlanoAlgebraico (glm::vec3 punto, glm::vec3 normal) {
	this->a = normal.x;
	this->b = normal.y;
	this->c = normal.z;
	
	float producto = glm::dot (normal, punto);
	this->d = (-1.0) * producto;
}

glm::vec3 PlanoAlgebraico::proyectar (glm::vec3 vector) {
	glm::vec3 normal = glm::normalize ( glm::vec3 (a,b,c) );
	float lambda = glm::dot (vector, normal);
	glm::vec3 proyeccion_normal = (normal * lambda);
	return (vector - proyeccion_normal);
}
