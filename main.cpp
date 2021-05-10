#include <SFML/Graphics.hpp>
#include "define.cpp"

void define();

int main() {
    define();
    enum scenes {
        home_screen, game
    };
    enum scenes current;
    sf::ContextSettings window_exit;
    window_exit.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Dungeon fighter", sf::Style::Default, window_exit);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    current = home_screen;

    if (!font.loadFromFile("../fonts/arial.ttf"))
        return EXIT_FAILURE;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    current = home_screen;
                }
            }
        }
        window.clear();
        switch (current) {
            case home_screen:
                window.draw(background_sprite);
                window.draw(play_button_sprite);
                window.draw(load_button_sprite);
                window.draw(exit_button_sprite);
                break;
            case game:
                break;
        }

        window.display();
    }

    return EXIT_SUCCESS;
}

void define() {

    background_tex.loadFromFile("../sprites/background/home.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite.setTexture(background_tex);
    background_sprite.setPosition(sf::Vector2f(0.f, 0.f));

    play_button_tex.loadFromFile("../sprites/button/play_butt.png", sf::IntRect(0, 0, 790 * 0.75, 140 * 0.75));
    play_button_sprite.setTexture(play_button_tex);
    play_button_sprite.setPosition(sf::Vector2f(303.f, 375.f));

    load_button_tex.loadFromFile("../sprites/button/load_butt.png", sf::IntRect(0, 0, 790 * 0.75, 140 * 0.75));
    load_button_sprite.setTexture(load_button_tex);
    load_button_sprite.setPosition(sf::Vector2f(303.f, 500.f));

    exit_button_tex.loadFromFile("../sprites/button/exit_butt.png", sf::IntRect(0, 0, 790 * 0.75, 140 * 0.75));
    exit_button_sprite.setTexture(exit_button_tex);
    exit_button_sprite.setPosition(sf::Vector2f(303.f, 625.f));
}