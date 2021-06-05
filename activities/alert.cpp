//
// Created by joulupukki on 05.06.2021.
//


#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "alert.h"



void open_alert_box(char *text, char *title) {
    sf::Event eventAlert;
    sf::Sprite background_sprite_alert;
    sf::Texture background_tex_alert;
    sf::Text alert;
    sf::Font fontAlert;
    sf::ContextSettings window_exit;
    window_exit.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode(500, 300), title, sf::Style::Close,
                            window_exit);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    background_tex_alert.loadFromFile("../sprites/background/alert.png", sf::IntRect(0, 0, 500, 300));
    background_sprite_alert.setTexture(background_tex_alert);
    background_sprite_alert.setPosition(sf::Vector2f(0.f, 0.f));
    fontAlert.loadFromFile("../fonts/ARCADECLASSIC.ttf");
    alert.setFont(fontAlert);
    alert.setString(text);
    alert.setCharacterSize(40);
    alert.setFillColor(sf::Color(71,30,20));
    sf::FloatRect textRect = alert.getLocalBounds();
    alert.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
    alert.setPosition(sf::Vector2f(500.0 / 2.0f, 200 / 2.0f));
    window.draw(background_sprite_alert);
    window.draw(alert);
    window.display();
    while (window.isOpen()) {

        while (window.pollEvent(eventAlert)) {
            if (eventAlert.type == sf::Event::Closed) {
                window.close();
            }
            if (eventAlert.type == sf::Event::KeyPressed) {
                if (eventAlert.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            if (eventAlert.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                if (localPosition.x >= 73 and localPosition.x <= 425)
                    if (localPosition.y >= 200 and localPosition.y <= 263)
                        window.close();

            }
        }
    }


}