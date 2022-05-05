#include "SnakeBoard.h"

void SnakeBoard::clear_board() {
    for(int row=0;row<100;row++){
        for(int col=0;col<100;col++)
           board[row][col]={0,0,0};
    }
    board[0][0]={0,0,1};
}
bool SnakeBoard::turn_Left(){
    for(int row=0;row<100;row++){
        for(int col=0;col<100;col++)
            if((board[row-1][col].snake==1)||(board[row][col-1].snake==1)){return true;}
    }
}
bool SnakeBoard::turn_Right() {
    for(int row=0;row<100;row++){
        for(int col=0;col<100;col++)
            if((board[row+1][col]).snake==1||(board[row][col+1]).snake==1){return true;}
    }
}
void SnakeBoard::update() {
    
}