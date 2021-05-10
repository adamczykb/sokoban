#include <SFML/Graphics.hpp>
#include "define.cpp"

void define();

int main() {
    define();

    sf::ContextSettings window_exit;
    window_exit.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Sokoban - Bartosz Adamczyk, Pawel Dopierala", sf::Style::Close, window_exit);
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
            if(event.type == sf::Event::MouseButtonPressed) {
                if (current == scenes::home_screen) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if(localPosition.x>=303 and localPosition.x<303+592.5){
                        if(localPosition.y>=375 and localPosition.y<375+105){ //play
                            current=scenes::game;
                        }
                        if(localPosition.y>=500 and localPosition.y<500+105){ //load
                            fflush(stdout);
                            printf("LOAD");
                        }
                        if(localPosition.y>=625 and localPosition.y<625+105){ //exit
                            exit(0);
                        }
                    }
                }
            }

        }
        window.clear();
        switch (current) {
            case home_screen:
                window.draw(background_sprite_home);
                window.draw(play_button_sprite);
                window.draw(load_button_sprite);
                window.draw(exit_button_sprite);
                break;
            case game:
                window.draw(background_sprite_game);
                break;
        }

        window.display();
    }

    return EXIT_SUCCESS;
}

void define() {

    background_tex_home.loadFromFile("../sprites/background/home.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite_home.setTexture(background_tex_home);
    background_sprite_home.setPosition(sf::Vector2f(0.f, 0.f));

    background_tex_game.loadFromFile("../sprites/background/game.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite_game.setTexture(background_tex_game);
    background_sprite_game.setPosition(sf::Vector2f(0.f, 0.f));

    play_button_tex.loadFromFile("../sprites/button/play_butt.png", sf::IntRect(0, 0, 592.5, 105));
    play_button_sprite.setTexture(play_button_tex);
    play_button_sprite.setPosition(sf::Vector2f(303.f, 375.f));

    load_button_tex.loadFromFile("../sprites/button/load_butt.png", sf::IntRect(0, 0, 592.5, 105));
    load_button_sprite.setTexture(load_button_tex);
    load_button_sprite.setPosition(sf::Vector2f(303.f, 500.f));

    exit_button_tex.loadFromFile("../sprites/button/exit_butt.png", sf::IntRect(0, 0, 592.5, 105));
    exit_button_sprite.setTexture(exit_button_tex);
    exit_button_sprite.setPosition(sf::Vector2f(303.f, 625.f));
}