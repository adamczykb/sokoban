//
// Created by joulupukki on 10.05.2021.
//

#include <SFML/Graphics.hpp>
#ifndef LLC_GAME_FILEHANDLING_H
#define LLC_GAME_FILEHANDLING_H
struct File_data {
    int **matrix;
    int steps;
    int game_time;
    int correct_file;
};
File_data read_new_map();
File_data read_saved_map();
File_data read_map(FILE *f);
#endif //LLC_GAME_FILEHANDLING_H
