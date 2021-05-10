//
// Created by joulupukki on 10.05.2021.
//

#include <stdio.h>
#include "movement.h"
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
    printf("lewo");
}

void right_action(int **matrix){
    fflush(stdout);
    printf("prawo");
}

void up_action(int **matrix){
    fflush(stdout);
    printf("gora");
}

void down_action(int **matrix){
    fflush(stdout);
    printf("dol");
}