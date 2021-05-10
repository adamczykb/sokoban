//
// Created by joulupukki on 10.05.2021.
//

#include <SFML/Graphics.hpp>
#include "homescreen.h"
sf::Texture play_button_tex;
sf::Texture load_button_tex;
sf::Texture exit_button_tex;
sf::Texture background_tex_home;
sf::Sprite play_button_sprite;
sf::Sprite load_button_sprite;
sf::Sprite exit_button_sprite;
sf::Sprite background_sprite_home;


void render_home_window(sf::RenderWindow *window){
    window->draw(background_sprite_home);
    window->draw(play_button_sprite);
    window->draw(load_button_sprite);
    window->draw(exit_button_sprite);
}

void home_declare() {

    background_tex_home.loadFromFile("../sprites/background/home.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite_home.setTexture(background_tex_home);
    background_sprite_home.setPosition(sf::Vector2f(0.f, 0.f));

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