#ifndef BOX2DHELPER_H
#define BOX2DHELPER_H

#include <Box2D/Box2D.h>

namespace Box2DHelper {
    inline b2World* CreateWorld() {
        static b2Vec2 gravity(0.0f, -9.8f); // 🔹 Simula gravedad terrestre
        static b2World world(gravity);
        return &world;
    }

    inline b2Body* CreateStaticPlane(b2World* world, float x, float y, float width, float height, float friction) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x, y);
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(width / 2.0f, height / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 0.0f;
        fixtureDef.friction = friction;  // 🔹 Se puede modificar el coeficiente de rozamiento
        fixtureDef.restitution = 0.0f;  // 🔹 No debe rebotar
        body->CreateFixture(&fixtureDef);

        return body;
    }

    inline b2Body* CreateDynamicBox(b2World* world, float x, float y, float width, float height) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
        b2Body* body = world->CreateBody(&bodyDef);

        b2PolygonShape box;
        box.SetAsBox(width / 2.0f, height / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.2f;  // 🔹 Ajustable para ver efectos del rozamiento
        fixtureDef.restitution = 0.1f;  // 🔹 No debe rebotar demasiado
        body->CreateFixture(&fixtureDef);

        return body;
    }
}

#endif
