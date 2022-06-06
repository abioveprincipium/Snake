#include <iostream>
#include "SnakeBoard.h"
int intro(){
   std::cout<<"AJG XXXX96"<<std::endl;
}
int main() {
    intro();
    SnakeBoard SnakeBoard(0,0);
    SnakeBoard.debug_display(20,10);
    return 0;
}
