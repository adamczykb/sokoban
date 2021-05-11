//
// Created by joulupukki on 10.05.2021.
//

#include "worldrender.h"

sf::Texture background_tex_game;
sf::Sprite background_sprite_game;

void game_declare() {
    background_tex_game.loadFromFile("../sprites/background/game.png", sf::IntRect(0, 0, 1200, 800));
    background_sprite_game.setTexture(background_tex_game);
    background_sprite_game.setPosition(sf::Vector2f(0.f, 0.f));
}

void render_game_window(sf::RenderWindow *window, int **matrix) {
    window->draw(background_sprite_game);
    map_render(window, matrix);
}

void map_render(sf::RenderWindow *window, int **matrix) {
    sf::Texture tileset;
    sf::VertexArray vertices;
    sf::Vector2u tileSize = sf::Vector2u(67, 67);
    tileset.loadFromFile("../sprites/graphic/tiles.png");
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(12 * 12 * 8);
    // resize the vertex array to fit the level size

    for (unsigned int j = 0; j < 12; ++j)
        for (unsigned int i = 0; i < 12; ++i)
        {
            // get the current tile number
            int tileNumber = matrix[j][i];

            // find its position in the tileset texture
            int tu = tileNumber % (tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * 12) * 8];

            // define its 4 corners
            quad[0].position = sf::Vector2f(198+i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f(198+(i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f(198+(i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(198+i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, 0 * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, 0 * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, 1 * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, 1 * tileSize.y);
        }
    sf::RenderStates states;
    // apply the transform
    sf::Transformable transformable;
    states.transform *= transformable.getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    window->draw(vertices,states);
}