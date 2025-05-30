#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(Game& game) : game(game) {
    boxShape.setSize(sf::Vector2f(60.0f, 60.0f));
    boxShape.setFillColor(sf::Color::Yellow);
    boxShape.setOrigin(30.0f, 30.0f);

    planeShape.setSize(sf::Vector2f(800.0f, 20.0f));
    planeShape.setFillColor(sf::Color::Blue);
    planeShape.setPosition(0, 500);
}

void SFMLRenderer::Render(sf::RenderWindow& window) {
    b2Vec2 boxPos = game.GetBox()->GetPosition();
    float scale = 30.0f;

    // 🔹 Ajustamos la posición de la caja para que aparezca en el centro sobre el piso
    boxShape.setPosition(boxPos.x * scale + 400, 600 - (boxPos.y * scale + 100));

    window.draw(planeShape);
    window.draw(boxShape);
}
