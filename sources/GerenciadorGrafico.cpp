#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico()
        : window(sf::VideoMode(800, 600), "LaggAndo") {
    window.setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico() {}

void GerenciadorGrafico::loop() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        float dt = clock.restart().asSeconds();
        if (dt > 1.f / 20.f) { dt = 1.f / 20.f; }
        window.display();

    }
}
