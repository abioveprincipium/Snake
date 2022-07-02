#include "SnakeSFML.h"
#include "SnakeBoard.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
SnakeSFML::SnakeSFML(SnakeBoard &board): board(board) {
    Board = sf::RectangleShape(sf::Vector2f(20,20));
    Board.setFillColor(sf::Color::Black);

    Head = sf::CircleShape(7);Head.setFillColor(sf::Color::White);
    Tail = sf::CircleShape(7);Tail.setFillColor(sf::Color::Yellow);
}
void SnakeSFML::draw(sf::RenderWindow &widow) {
    int h =20;
    int w =20;

    for(int col = 0; col < w; col++){
        for(int row = 0; row < h; row++){
            int x = 20.5*col;//Position on X, with Offset
            int y = 20.5*row;

            Board.setPosition(x,y);widow.draw(Board);
            if(board.getFieldInfo(row,col)=='O')Head.setPosition(x+3,y+3);widow.draw(Head);
            if(board.getFieldInfo(row,col)=='o')Tail.setPosition(x+3,y+3);widow.draw(Tail);
        }
    }

}