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

}
//bool SnakeBoard::turn_Left(){
//    for(int row=0;row<100;row++){
//        for(int col=0;col<100;col++)
//            if((board[row-1][col].Snake_bd==1)||(board[row][col-1].Snake_bd==1)){return true;}
//    }
//}
//bool SnakeBoard::turn_Right() {
//    for(int row=0;row<100;row++){
//        for(int col=0;col<100;col++)
//            if((board[row+1][col]).Snake_bd==1||(board[row][col+1]).Snake_bd==1){return true;}
//    }
//}
void SnakeBoard::update() {
    
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