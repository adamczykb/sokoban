//
// Created by joulupukki on 10.05.2021.
//

#include "worldrender.h"
sf::Texture background_tex_game;
sf::Sprite background_sprite_game;
void game_declare(){
    background_tex_game.loadFromFile("../sprites/background/game.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite_game.setTexture(background_tex_game);
    background_sprite_game.setPosition(sf::Vector2f(0.f, 0.f));
}
void render_game_window(sf::RenderWindow *window){
    window->draw(background_sprite_game);

}