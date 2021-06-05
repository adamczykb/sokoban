//
// Created by joulupukki on 10.05.2021.
//

#include "stdio.h"
#include "movement.h"

Hero find_hero(int **matrix){
    Hero hero;
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            if(matrix[i][j] == 4){
                hero.i = i;
                hero.j = j;
                hero.target_place = 0;
            } else if(matrix[i][j] == 5) {
                hero.i = i;
                hero.j = j;
                hero.target_place = 1;
            }
        }
    }
    return hero;
}

void manage_action(sf::Event *event, int **matrix){
    switch (event->key.code) {
        case sf::Keyboard::Left:
            left_action(matrix);
            break;
        case sf::Keyboard::Right:
            right_action(matrix);
            break;
        case sf::Keyboard::Up:
            up_action(matrix);
            break;
        case sf::Keyboard::Down:
            down_action(matrix);
            break;
    }
}

void left_action(int **matrix){
    fflush(stdout);
    Hero hero = find_hero(matrix);
    printf("Bohater jest w miejscu %d, %d i ma target_place = %d\n", hero.i, hero.j, hero.target_place);
    matrix[0][0] = 3;
}

void right_action(int **matrix){
    fflush(stdout);
    matrix[0][11] = 3;
}

void up_action(int **matrix){
    fflush(stdout);
    matrix[11][0] = 3;
}

void down_action(int **matrix){
    fflush(stdout);
    matrix[11][11] = 3;
}