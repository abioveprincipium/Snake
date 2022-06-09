#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H
#include <vector>

enum GameMode{EASY, MEDIUM, HARD};
enum GameState{RUNNING, FINISH_LOSS};

struct Field{
    bool energy;
   // bool miss;
    bool Snake_bd;
};
struct Snake{
   int Head_X;
   int Head_Y;
  // int Tail_X;
   //int Tail_Y;
};
class SnakeBoard {
private:
    Field board[20][20];
    int width;
    int height;
    std::vector<Snake> Snake_Head;
    Snake Head_poss;
public:
    SnakeBoard(int width, int height);
    void update();
    bool turn_Left();
    bool turn_Right();
    void debug_display(int width, int height);
    void clear_board();
    void snake_len();
};


#endif //SNAKE_SNAKEBOARD_H
