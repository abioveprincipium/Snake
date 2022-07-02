#include "SnakeBoard.h"
#include <iostream>

SnakeBoard::SnakeBoard(int width, int height){
    width = width;
    height = height;
    Head_poss = {width/2,height/2};
    Snake_Head.push_back(Head_poss);
}
void SnakeBoard::clear_board() {
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++)
           board[row][col]={0,0};
    }
    way_bf = RIGHT;
    state = RUNNING;
    // energy balls for snake
}
bool SnakeBoard::OnBoard()const {
    if (Snake_Head.back().Head_X <= 0 && Snake_Head.back().Head_Y<=0){
        if(Snake_Head.back().Head_X > height && Snake_Head.back().Head_Y >  width){
            return true;
        } else return false;
    } else return false;
}
bool SnakeBoard::turn_Left(){
    if(way_bf==RIGHT)way_bf=TOP;
    else if(way_bf==TOP)way_bf=LEFT;
    else if(way_bf==LEFT)way_bf=BOTTOM;
    else if(way_bf==BOTTOM)way_bf=RIGHT;
}
bool SnakeBoard::turn_Right() {
    if(way_bf==RIGHT)way_bf=BOTTOM;
    else if(way_bf==BOTTOM)way_bf=LEFT;
    else if(way_bf==LEFT)way_bf=TOP;
    else if(way_bf==TOP)way_bf=LEFT;
}
void SnakeBoard::update() {
    if(OnBoard() != true){state=FINISHED;}
}
void SnakeBoard::snake_len(){              //CHECK AGAIN
    if(way_bf==RIGHT){
        Head_poss={Snake_Head.back().Head_X+1,Snake_Head.back().Head_Y};
        Snake_Head.push_back(Head_poss);
    }
    else if(way_bf==TOP){
        Head_poss={Snake_Head.back().Head_X,Snake_Head.back().Head_Y+1};
        Snake_Head.push_back(Head_poss);
    }
    else if(way_bf==LEFT){
        Head_poss={Snake_Head.back().Head_X-1,Snake_Head.back().Head_Y};
        Snake_Head.push_back(Head_poss);
    }
    else if(way_bf==BOTTOM){
        Head_poss={Snake_Head.back().Head_X,Snake_Head.back().Head_Y-1};
        Snake_Head.push_back(Head_poss);
    }
    else Snake_Head.erase(Snake_Head.begin());
}
GameState SnakeBoard::getGameState() const {
    return state;
}
SnakeCrawl SnakeBoard::getSnakeWay() const {
    return way_bf;
}
void SnakeBoard::debug_display(int width, int height) {

    std::cout<<std::endl;
    for(int row=0;row<height;row++){
        std::cout<<"_ ";
    }
    std::cout<<std::endl;
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            for(size_t t=0; t<Snake_Head.size();t++){

                     if((Snake_Head.back().Head_X==Snake_Head[t].Head_X)&&(Snake_Head.back().Head_Y==Snake_Head[t].Head_Y)){
                        if(Snake_Head.back().Head_X == row && Snake_Head[t].Head_Y==col){
                            std::cout<<"O";
                        }
                     }
                     else{if(Snake_Head[t].Head_X==row && Snake_Head[t].Head_Y)std::cout<<"o";}
                }
        }
        std::cout<<std::endl;
    }
    for(int col=0;col<width;col++){
        std::cout<<"_ ";

    }

}