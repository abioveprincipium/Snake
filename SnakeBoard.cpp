#include "SnakeBoard.h"
#include <iostream>
#include "conio.h"

SnakeBoard::SnakeBoard(int width, int height){
    SnakeBoard::width = width;
    SnakeBoard:: height = height; ///XXXXXXXXX

    way_bf = RIGHT;
    state = RUNNING;

    Head_poss = {height/2,width/2};
    Snake_Head.push_back(Head_poss);
    Head_poss = {height/2,width/2-1};
    Snake_Head.push_back(Head_poss);

    int score=0;
    putEnergy();
}
//void SnakeBoard::clear_board() {
//    for(int row=0;row<width;row++){
//        for(int col=0;col<height;col++)
//           board[row][col]={0,0};
//    }
//
//    // energy balls for snake
//}
bool SnakeBoard::OnBoard()const {
    if (Snake_Head.back().Head_X < 0 || Snake_Head.back().Head_Y<0||Snake_Head.back().Head_X >= height|| Snake_Head.back().Head_Y >=  width){
            return true;
    } else return false;
}
void SnakeBoard::turn_Left(){
    if(way_bf==RIGHT)way_bf=TOP;
    else if(way_bf==TOP)way_bf=LEFT;
    else if(way_bf==LEFT)way_bf=BOTTOM;
    else if(way_bf==BOTTOM)way_bf=RIGHT;
}
void SnakeBoard::turn_Top(){ // zawracanie snakiem
    if(way_bf==RIGHT)way_bf=LEFT;
    else if(way_bf==TOP)way_bf=BOTTOM;
    else if(way_bf==LEFT)way_bf=RIGHT;
    else if(way_bf==BOTTOM)way_bf=TOP;
}
void SnakeBoard::turn_Bottom(){ // zawracanie snakiem
    if(way_bf==TOP)way_bf=BOTTOM;
    else if(way_bf==BOTTOM)way_bf=TOP;
    else if(way_bf==LEFT)way_bf=RIGHT;
    else if(way_bf==RIGHT)way_bf=LEFT;
}
void SnakeBoard::turn_Right() {
    if(way_bf==RIGHT)way_bf=BOTTOM;
    else if(way_bf==BOTTOM)way_bf=LEFT;
    else if(way_bf==LEFT)way_bf=TOP;
    else if(way_bf==TOP)way_bf=RIGHT;
}
void SnakeBoard::update() {
     if(OnBoard()){ state=FINISHED;}
    else state=RUNNING;
}
void SnakeBoard::WSAD() { //Text play
    if(_kbhit()){
        switch (_getch()) {
            default:break;
            case 'w':
                way_bf=TOP;
                break;
            case 's':
                way_bf=BOTTOM;
                break;
            case 'a':
                way_bf=LEFT;
                break;
            case 'd':
                way_bf=RIGHT;
                break;
        }
    }
}

void SnakeBoard::snake_len(){
    int Tail_x;
    int Tail_y;
    //TO CHECK AGAIN
    if(way_bf==RIGHT){
        Tail_x=Snake_Head.back().Head_X+1;
        Tail_y=Snake_Head.back().Head_Y;
    }
    if(way_bf==TOP){
        Tail_x=Snake_Head.back().Head_X;
        Tail_y=Snake_Head.back().Head_Y+1;
    }
    if(way_bf==LEFT){
        Tail_x=Snake_Head.back().Head_X-1;
        Tail_y=Snake_Head.back().Head_Y;
    }
    if(way_bf==BOTTOM){
        Tail_x=Snake_Head.back().Head_X;
        Tail_y=Snake_Head.back().Head_Y-1;
    }
    if((Snake_Head.back().Head_X == energy.En_X)&&Snake_Head.back().Head_Y == energy.En_Y){
        putEnergy(); SnakeBoard::score++;
    }
    Snake_Head.erase(Snake_Head.begin());

    Head_poss={Tail_x,Tail_y};
    Snake_Head.push_back(Head_poss);
}
GameState SnakeBoard::getGameState() const {
    return state;
}
SnakeCrawl SnakeBoard::getSnakeWay() const {
    return way_bf;
}
char SnakeBoard::getFieldInfo(int row, int col) {
    if(col>=width||row>=height||col<0||row<0){return '#';}

    if((Snake_Head.back().Head_X == row) && (Snake_Head.back().Head_Y == col)){return 'O';}
    else if(energy.En_X == row && energy.En_X == col){return 'E';}
    else {
        for (size_t t = 0; t < Snake_Head.size(); ++t) {
            if (Snake_Head[t].Head_X == row && Snake_Head[t].Head_Y == col) { return 'o'; }
        }
    }
    return 0;
}
int SnakeBoard::Movement(int rate) {

    return rate;
}
int SnakeBoard::IncreaseScore(){
    return score;
}
void SnakeBoard::debug_display() {

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
                     else if(Snake_Head[t].Head_X==row && Snake_Head[t].Head_Y)std::cout<<"o";
            }
            std::cout<<"_ ";
        }
        std::cout<<std::endl;
    }
    for(int col=0;col<width;col++){
        std::cout<<"_ ";

    }

}
void SnakeBoard::putEnergy() {
    energy.En_X = rand()%height;
    energy.En_Y = rand()%width;
}
