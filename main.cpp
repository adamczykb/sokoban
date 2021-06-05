#include <SFML/Graphics.hpp>
#include "activities/homescreen.h"
#include "activities/worldrender.h"
#include "activities/movement.h"
#include "activities/filehandling.h"
#include "activities/alert.h"

sf::Event event;
enum scenes {
    home_screen, game
};
enum scenes current;
sf::Font font;
File_data file_data;

int main() {
    sf::Clock clock;
    sf::Time time;
    home_declare();
    game_declare();
    sf::ContextSettings window_exit;
    window_exit.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Sokoban - Bartosz Adamczyk, Pawel Dopierala", sf::Style::Close,
                            window_exit);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    current = home_screen;

    if (!font.loadFromFile("../fonts/ARCADECLASSIC.ttf"))
        return EXIT_FAILURE;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                if(current == scenes::game){
                    if(save_map(file_data) == 1){
                        printf("Poprawnie zapisano gre\n");
                    } else {
                        printf("Niepoprawnie zapisano gre\n");
                    }
                }
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && current == scenes::game) {
                if(event.key.code == sf::Keyboard::Escape){
                    if(save_map(file_data) == 1){
                        printf("Poprawnie zapisano gre\n");
                    } else {
                        printf("Niepoprawnie zapisano gre\n");
                    }
                    current = home_screen;
                } else {
                    manage_action(&event, file_data.matrix);
                    file_data.steps++;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (current == scenes::home_screen) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if (localPosition.x >= 303 and localPosition.x < 303 + 592.5) {
                        if (localPosition.y >= 375 and localPosition.y < 375 + 105) { //play
                            file_data = read_new_map();
                            if (file_data.correct_file == 1) {
                                current = scenes::game;
                                time = sf::seconds(0);
                            } else
                                printf("Niepoprawny plik");
                        }
                        if (localPosition.y >= 500 and localPosition.y < 500 + 105) { //load
                            file_data = read_saved_map();
                            if (file_data.correct_file == 1){
                                current=scenes::game;
                                time = sf::seconds(file_data.game_time);
                            }
                            else
                                printf("Niepoprawny plik");

                        }
                        if (localPosition.y >= 625 and localPosition.y < 625 + 105) { //exit
                            exit(0);
                        }
                    }
                }
            }

        }
        window.clear();
        switch (current) {
            case home_screen:
                render_home_window(&window);

                break;
            case game:
                time += clock.restart();
                file_data.game_time = time.asSeconds();
                render_game_window(&window, &font, file_data.matrix, file_data.steps, file_data.game_time);
                break;
        }

        window.display();
    }

    return EXIT_SUCCESS;
}

