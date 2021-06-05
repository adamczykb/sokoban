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
int free_place(int **matrix, Hero hero, int step_i, int step_j);
int move_box(int **matrix, Hero hero, int step_i, int step_j, int behind_step_i, int behind_step_j);
int check_win(int **matrix);
void win_action();

#endif //LLC_GAME_MOVEMENT_H
