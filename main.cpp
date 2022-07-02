#include <iostream>
#include "SnakeBoard.h"
#include "conio.h"
#include "SnakeSFML.h"
int intro(){
   std::cout<<"AJG XXXX96"<<std::endl;
}
int main() {
   // intro();

    SnakeBoard SnakeBoard(20,20);
    SnakeSFML draw(SnakeBoard);
    int W_W = 20*20.5;
    int W_H = 20*20.5;

    sf::RenderWindow widow(sf::VideoMode(W_W,W_H), "SNAKE GAME");

    while(SnakeBoard.getGameState()==RUNNING){
        SnakeBoard.snake_len();
        sf::Event event;
        widow.setFramerateLimit(SnakeBoard.Movement(5));

        while (widow.pollEvent(event)){

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Left){SnakeBoard.turn_Left();std::cout<<"Left Arrow Pressed"<<std::endl;}
                if(event.key.code == sf::Keyboard::Right){SnakeBoard.turn_Right();std::cout<<"Right Arrow Pressed"<<std::endl;}
                if(event.key.code == sf::Keyboard::Up){SnakeBoard.turn_Top();std::cout<<"Top Arrow Pressed"<<std::endl;}
                if(event.key.code == sf::Keyboard::Down){SnakeBoard.turn_Bottom();std::cout<<"Bottom Arrow Pressed"<<std::endl;}
            }
            if(event.type == sf::Event::Closed){widow.close();}
        }
        widow.clear();
        draw.draw(widow);
        widow.display();
        SnakeBoard.update();
    }
    if(SnakeBoard.getGameState()==FINISHED){
        std::cout<<"GAME OVER"<<std::endl;
    }
    return 0;
}
