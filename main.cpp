#include <SFML/Graphics.hpp>
#include "activities/homescreen.h"
#include "activities/worldrender.h"
#include "activities/movement.h"
#include "activities/filehandling.h"

sf::Event event;
enum scenes {
    home_screen, game
};
enum scenes current;
sf::Font font;
File_data file_data;
int main() {
    home_declare();
    game_declare();
    sf::ContextSettings window_exit;
    window_exit.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Sokoban - Bartosz Adamczyk, Pawel Dopierala", sf::Style::Close, window_exit);
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);

    current = home_screen;

    if (!font.loadFromFile("../fonts/arial.ttf"))
        return EXIT_FAILURE;


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    current = home_screen;
                }else{
                    if(current == scenes::game)
                        manage_action(&event,file_data.matrix);
                        file_data.steps++;
                }
            }
            if(event.type == sf::Event::MouseButtonPressed) {
                if (current == scenes::home_screen) {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                    if(localPosition.x>=303 and localPosition.x<303+592.5){
                        if(localPosition.y>=375 and localPosition.y<375+105){ //play
                            current=scenes::game;
                            file_data = read_new_map();
                        }
                        if(localPosition.y>=500 and localPosition.y<500+105){ //load
                            file_data = read_saved_map();
                        }
                        if(localPosition.y>=625 and localPosition.y<625+105){ //exit
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
                render_game_window(&window);
                break;
        }

        window.display();
    }

    return EXIT_SUCCESS;
}

