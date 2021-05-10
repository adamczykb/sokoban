//
// Created by joulupukki on 10.05.2021.
//

#include <SFML/Graphics.hpp>

sf::Texture play_button_tex;
sf::Texture load_button_tex;
sf::Texture exit_button_tex;
sf::Texture background_tex_home;
sf::Texture background_tex_game;
sf::Sprite play_button_sprite;
sf::Sprite load_button_sprite;
sf::Sprite exit_button_sprite;
sf::Sprite background_sprite_home;
sf::Sprite background_sprite_game;
sf::Event event;
enum scenes {
    home_screen, game
};
enum scenes current;
sf::Font font;

