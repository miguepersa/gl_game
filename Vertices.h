#ifndef VERTICES_H
#define VERTICES_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "VertexBuffer.h"

// Vertices coordinates
Vertex tankVertices[] =
{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(0.0f,-1.0f, 0.0f), glm::vec2(2.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f,-1.0f, 0.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f,-1.0f, 0.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f,-1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(2.0f, 0.0f)},
	Vertex{glm::vec3(2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(2.0f, 0.0f)},
	Vertex{glm::vec3(2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f,-1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f,-1.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f,-1.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(-2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),	glm::vec3(0.0f, 0.0f,-1.0f), glm::vec2(2.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  0.0f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(-2.0f,  0.0f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(2.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  1.5f, -1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(2.0f, 2.0f)},
	Vertex{glm::vec3(2.0f,  1.5f,  1.5f),	glm::vec3(1.0f, 1.0f, 1.0f),    glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(2.0f, 0.0f)},
};
// Indices for vertices order
GLuint tankIndices[] =
{
	 0,		 1,		 2, // bottom side
	 0,		 2,		 3, // bottom side
	 4,		 5,		 6, // back side
	 4,		 7,		 5, // back side
	 8,		 9,		10, // right side
	 8,		10,		11, // right side
	12,		13,		14, // front side
	12,		14,		15, // front side
	16,		17,		18, // left side
	16,		18,		19, // left side
	20,		21,		22, // top side
	20,		22,		23, // top side
};


// V�rtices de la torreta
Vertex turretVertices[] =
{
	// Coordenadas             // Colores               // Normales             // Coordenadas de textura
	// Cara inferior
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.0f,  0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
	// Cara superior
	Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
	Vertex{glm::vec3(0.5f, 0.5f,  0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
	Vertex{glm::vec3(-0.5f, 0.5f,  0.5f), glm::vec3(0.6f, 0.6f, 0.6f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
};

// �ndices para los v�rtices de la torreta
GLuint turretIndices[] =
{
	// Cara inferior
	0, 1, 2, 0, 2, 3,
	// Cara superior
	4, 5, 6, 4, 6, 7,
	// Cara frontal
	3, 2, 6, 3, 6, 7,
	// Cara posterior
	0, 1, 5, 0, 5, 4,
	// Cara derecha
	1, 2, 6, 1, 6, 5,
	// Cara izquierda
	0, 3, 7, 0, 7, 4
};

// tank vertex
//Vertex tankVertices[] =
//{
//	// Base
//	Vertex{glm::vec3(-1.0f, 0.0f, -2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3( 1.0f, 0.0f, -2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
//	Vertex{glm::vec3( 1.0f, 0.0f,  2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(-1.0f, 0.0f,  2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
//	Vertex{glm::vec3(-1.0f, 1.0f, -2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3( 1.0f, 1.0f, -2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
//	Vertex{glm::vec3( 1.0f, 1.0f,  2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 1.0f)}, 
//	Vertex{glm::vec3(-1.0f, 1.0f,  2.0f), glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 1.0f)},
//
//	// Torreta
//	Vertex{glm::vec3(-0.5f, 1.0f, -0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3( 0.5f, 1.0f, -0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
//	Vertex{glm::vec3( 0.5f, 1.0f,  0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(-0.5f, 1.0f,  0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  1.0f, 0.0f), glm::vec2(0.0f, 1.0f)}, 
//	Vertex{glm::vec3(-0.5f, 1.7f, -0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  0.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3( 0.5f, 1.7f, -0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  0.0f, 1.0f), glm::vec2(1.0f, 0.0f)}, 
//	Vertex{glm::vec3( 0.5f, 1.7f,  0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  0.0f, 1.0f), glm::vec2(1.0f, 1.0f)}, 
//	Vertex{glm::vec3(-0.5f, 1.7f,  0.75f), glm::vec3(0.0f, 0.6f, 0.0f), glm::vec3(0.0f,  0.0f, 1.0f), glm::vec2(0.0f, 1.0f)}, 
//
//	// Canon
//	Vertex{glm::vec3(-0.1f, 1.6f, -0.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 0.0f)},
//	Vertex{glm::vec3( 0.1f, 1.6f, -0.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 0.0f)},
//	Vertex{glm::vec3( 0.1f, 1.6f, -2.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 1.0f)}, 
//	Vertex{glm::vec3(-0.1f, 1.6f, -2.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 1.0f)}, 
//	Vertex{glm::vec3(-0.1f, 1.8f, -0.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f)}, 
//	Vertex{glm::vec3( 0.1f, 1.8f, -0.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f)}, 
//	Vertex{glm::vec3( 0.1f, 1.8f, -2.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f)},
//	Vertex{glm::vec3(-0.1f, 1.8f, -2.75f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 1.0f)}
//};
//
//// tankk indexes
//GLuint tankIndices[] =
//{
//	// Base
//	0, 1, 2, 0, 2, 3,       // Cara inferior
//	4, 5, 6, 4, 6, 7,       // Cara superior
//	0, 1, 5, 0, 5, 4,       // Cara posterior
//	2, 3, 7, 2, 7, 6,       // Cara frontal
//	1, 2, 6, 1, 6, 5,       // Cara derecha
//	0, 3, 7, 0, 7, 4,       // Cara izquierda
//
//	// Torreta
//	8, 9, 10, 8, 10, 11,    // Cara inferior
//	12, 13, 14, 12, 14, 15, // Cara superior
//	8, 9, 13, 8, 13, 12,    // Cara posterior
//	10, 11, 15, 10, 15, 14, // Cara frontal
//	9, 10, 14, 9, 14, 13,   // Cara derecha
//	8, 11, 15, 8, 15, 12,   // Cara izquierda
//
//	// Cannon
//	16, 17, 18, 16, 18, 19, // Cara inferior
//	20, 21, 22, 20, 22, 23, // Cara superior
//	16, 17, 21, 16, 21, 20, // Cara posterior
//	18, 19, 23, 18, 23, 22, // Cara frontal
//	17, 18, 22, 17, 22, 21, // Cara derecha
//	16, 19, 23, 16, 23, 20  // Cara izquierda
//};

float skyboxVertices[] =
{
	//   Coordinates
	-1.0f, -1.0f,  1.0f,//        7--------6
	 1.0f, -1.0f,  1.0f,//       /|       /|
	 1.0f, -1.0f, -1.0f,//      4--------5 |
	-1.0f, -1.0f, -1.0f,//      | |      | |
	-1.0f,  1.0f,  1.0f,//      | 3------|-2
	 1.0f,  1.0f,  1.0f,//      |/       |/
	 1.0f,  1.0f, -1.0f,//      0--------1
	-1.0f,  1.0f, -1.0f
};

unsigned int skyboxIndices[] =
{
	// Right
	1, 2, 6,
	6, 5, 1,
	// Left
	0, 4, 7,
	7, 3, 0,
	// Top
	4, 5, 6,
	6, 7, 4,
	// Bottom
	0, 3, 2,
	2, 1, 0,
	// Back
	0, 1, 5,
	5, 4, 0,
	// Front
	3, 7, 6,
	6, 2, 3
};

Vertex floorVertices[] =
{ //               COORDINATES           /            COLORS          /           NORMALS         /       TEXTURE COORDINATES    //
	Vertex{glm::vec3(-50.0f, 0.0f,  50.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-50.0f, 0.0f, -50.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 25.0f)},
	Vertex{glm::vec3(50.0f, 0.0f, -50.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(25.0f, 25.0f)},
	Vertex{glm::vec3(50.0f, 0.0f,  50.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(25.0f, 0.0f)}
};

// Indices for vertices order
GLuint floorIndices[] =
{
	0, 1, 2,
	0, 2, 3
};

Vertex lightVertices[] =
{ //     COORDINATES     //
	Vertex{glm::vec3(-0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f, -0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f,  0.1f)},
	Vertex{glm::vec3(-0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f, -0.1f)},
	Vertex{glm::vec3(0.1f,  0.1f,  0.1f)}
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};

#endif