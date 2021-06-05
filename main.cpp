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
    int win = 0;

    if (!font.loadFromFile("../fonts/ARCADECLASSIC.ttf"))
        return EXIT_FAILURE;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                if(current == scenes::game){
                    if(save_map(file_data) == 1){
                        open_alert_box("Poprawnie zapisano gre","Komunikat");
                    } else {
                        open_alert_box("Niepoprawnie zapisano gre","Komunikat");
                    }
                }
                window.close();
            } else if (event.type == sf::Event::KeyPressed && current == scenes::game) {
                if(event.key.code == sf::Keyboard::Escape){
                    if(save_map(file_data) == 1){
                        open_alert_box("Poprawnie zapisano gre","Komunikat");
                    } else {
                        open_alert_box("Niepoprawnie zapisano gre","Komunikat");
                    }
                    current = home_screen;
                } else if (event.key.code == sf::Keyboard::R) {
                    file_data = read_new_map();
                    if (file_data.correct_file == 1) {
                        current = scenes::game;
                        time = sf::seconds(0);
                    } else
                        open_alert_box("Niepoprawny plik","Komunikat");
                } else if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
                    win = manage_action(&event, file_data.matrix) == 1;
                    file_data.steps++;
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (current == scenes::home_screen) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if (localPosition.x >= 303 and localPosition.x < 303 + 592.5) {
                        if (localPosition.y >= 375 and localPosition.y < 375 + 105) { //play
                            file_data = read_new_map();
                            if (file_data.correct_file == 1) {
                                current = scenes::game;
                                time = sf::seconds(0);
                            } else
                                open_alert_box("Niepoprawny plik","Komunikat");

                        }
                        if (localPosition.y >= 500 and localPosition.y < 500 + 105) { //load
                            file_data = read_saved_map();
                            if (file_data.correct_file == 1){
                                current=scenes::game;
                                time = sf::seconds(file_data.game_time);
                            }
                            else
                                open_alert_box("Niepoprawny plik","Komunikat");

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
        if(win == 1){
            open_alert_box("Wygrales   gre!\nGratulujemy!","Gratulacje!");
            win = 0;
            current = home_screen;
        }
    }

    return EXIT_SUCCESS;
}

