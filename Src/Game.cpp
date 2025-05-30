#include "Game.h"

Game::Game(float friction) {
    world = Box2DHelper::CreateWorld();

    // 🔹 Crear el piso en la posición correcta
    plane = Box2DHelper::CreateStaticPlane(world, 0.0f, -5.0f, 20.0f, 1.0f, friction);

    // 🔹 Subimos la posición de la caja al inicio
    box = Box2DHelper::CreateDynamicBox(world, 0.0f, 0.0f, 11.0f, 11.0f);  
}


void Game::Update() {
    world->Step(1.0f / 60.0f, 8, 3);
}

void Game::ApplyForce(float force) {
    b2Vec2 pushForce(force, 0.0f);
    box->ApplyForceToCenter(pushForce, true);  // 🔹 Aseguramos que la fuerza se aplique correctamente
}

b2Body* Game::GetBox() { return box; }
