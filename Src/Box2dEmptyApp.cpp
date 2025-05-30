#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SFMLRenderer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sliding Box with Friction");
    Game game(0.3f); // 🔹 Modifica este valor para probar distintos coeficientes de rozamiento
    SFMLRenderer renderer(game);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // 🔹 Control de usuario: Aplica fuerza a la izquierda/derecha
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            game.ApplyForce(-300.0f);  // 🔹 Aplica fuerza a la izquierda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            game.ApplyForce(300.0f);  // 🔹 Aplica fuerza a la derecha
        }

        game.Update();

        window.clear();
        renderer.Render(window);
        window.display();
    }

    return 0;
}
