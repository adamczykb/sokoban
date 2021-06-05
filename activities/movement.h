//
// Created by joulupukki on 10.05.2021.
//

#include <SFML/Graphics.hpp>
#ifndef LLC_GAME_MOVEMENT_H
#define LLC_GAME_MOVEMENT_H
struct Hero{
    int i;
    int j;
    int target_place;
};
Hero find_hero(int **matrix);
void manage_action(sf::Event *event, int **matrix);
void left_action(int **matrix);
void right_action(int **matrix);
void up_action(int **matrix);
void down_action(int **matrix);

#endif //LLC_GAME_MOVEMENT_H
