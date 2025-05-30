#ifndef GAME_H
#define GAME_H

#include "Box2DHelper.h"

class Game {
public:
    Game(float friction); // 🔹 Permite probar distintos coeficientes de rozamiento
    void Update();
    void ApplyForce(float force);  // 🔹 Mueve la caja con las teclas izquierda/derecha
    b2Body* GetBox();

private:
    b2World* world;
    b2Body* box;
    b2Body* plane;
};

#endif

