// Projectile.cpp

#include "Projectile.h"

// Constructor: definici�n
Projectile::Projectile(Mesh& mesh, glm::vec3 startPosition, glm::vec3 direction, float speed)
    : mesh(mesh), position(startPosition), direction(glm::normalize(direction)), speed(speed), lifeTime(5.0f) // Vida de 5 segundos
{
}

// M�todo Update: definici�n
void Projectile::Update(float deltaTime)
{
    // Actualizar la posici�n del proyectil
    position += direction * speed * deltaTime;

    // Reducir el tiempo de vida
    lifeTime -= deltaTime;
}

// M�todo Draw: definici�n
void Projectile::Draw(Shader& shader, Camera& camera)
{
    // Actualizar la posici�n de la malla
    mesh.Position = position;

    // Dibujar el proyectil
    mesh.Draw(shader, camera);
}

// M�todo IsAlive: definici�n
bool Projectile::IsAlive() const
{
    return lifeTime > 0.0f;
}