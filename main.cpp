#include <SFML/Graphics.hpp>
#include <unistd.h>

int main() {
    sf::ContextSettings window_settings;
    sf::Font font;
    window_settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Dungeon fighter | Bartosz Adamczyk", sf::Style::Titlebar, window_settings);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    sf::Texture play_button_tex;
    sf::Texture load_button_tex;
    sf::Texture settings_button_tex;
    sf::Texture background_tex;
    sf::Sprite play_button_sprite;
    sf::Sprite load_button_sprite;
    sf::Sprite settings_button_sprite;
    sf::Sprite background_sprite;

    background_tex.loadFromFile("../sprites/background/home.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite.setTexture(settings_button_tex);
    background_sprite.setPosition(sf::Vector2f(0.f, 0.f));

    play_button_tex.loadFromFile("../sprites/button/play_butt.png", sf::IntRect(0, 0, 790*0.75, 140*0.75));
    play_button_sprite.setTexture(play_button_tex);
    play_button_sprite.setPosition(sf::Vector2f(303.f, 375.f));

    load_button_tex.loadFromFile("../sprites/button/load_butt.png", sf::IntRect(0, 0, 790*0.75, 140*0.75));
    load_button_sprite.setTexture(load_button_tex);
    load_button_sprite.setPosition(sf::Vector2f(303.f, 500.f));

    settings_button_tex.loadFromFile("../sprites/button/settings_butt.png", sf::IntRect(0, 0, 790*0.75, 140*0.75));
    settings_button_sprite.setTexture(settings_button_tex);
    settings_button_sprite.setPosition(sf::Vector2f(303.f, 625.f));


    enum scenes {
        home_screen, settings, game
    };
    enum scenes current;
    current = home_screen;

    if (!font.loadFromFile("../fonts/arial.ttf"))
        return EXIT_FAILURE;



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Keyboard::Escape)
                current = home_screen;

        }
        window.clear();
        switch (current) {
            case home_screen:
                window.draw(background_sprite);
                window.draw(play_button_sprite);
                window.draw(load_button_sprite);
                window.draw(settings_button_sprite);

                break;
            case settings:
                break;
            case game:
                break;
        }

        window.display();
    }

    return EXIT_SUCCESS;
}