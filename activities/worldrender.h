//
// Created by joulupukki on 10.05.2021.
//

#ifndef LLC_GAME_WORLDRENDER_H
#define LLC_GAME_WORLDRENDER_H

#include <SFML/Graphics.hpp>

void game_declare();

void map_render(sf::RenderWindow *window, int **matrix);

void render_game_window(sf::RenderWindow *window, sf::Font *font, int **matrix, int steps, int game_time);

void render_infos(sf::RenderWindow *window, sf::Font *font, int steps, int game_time);

#endif //LLC_GAME_WORLDRENDER_H
