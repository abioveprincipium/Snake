#ifndef SNAKE_SNAKESFML_H
#define SNAKE_SNAKESFML_H
#include "SnakeBoard.h"
#include "SFML/Graphics.hpp"

class SnakeSFML {
    SnakeBoard & board;
    sf::CircleShape Head;
    sf::CircleShape Tail;
    sf::RectangleShape Board;
    sf::CircleShape EneryBall;
public:
    explicit SnakeSFML(SnakeBoard & board);
    void draw(sf::RenderWindow & widow);
};


#endif //SNAKE_SNAKESFML_H
