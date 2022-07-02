#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H
#include <vector>
#include <deque> //XX
#include <fstream>

enum GameMode{EASY, MEDIUM, HARD};
enum GameState{RUNNING, FINISHED};
enum SnakeCrawl{TOP, RIGHT, BOTTOM, LEFT};


struct Snake{
   int Head_X;
   int Head_Y;
  // int Tail_X;
   //int Tail_Y;
};
class SnakeBoard {
private:
    int width;
    int height;
    std::vector<Snake> Snake_Head;
    Snake Head_poss;
    SnakeCrawl way_bf;
    GameState state;
public:
    SnakeBoard();
    SnakeBoard(int width, int height);
    bool OnBoard()const;
    void update();
    void turn_Left();
    void turn_Right();
    void turn_Top();
    void turn_Bottom();
    GameState getGameState() const;
    void debug_display();//for text play
    char getFieldInfo(int row, int col);
    void clear_board();
    void snake_len();
    void WSAD();//for text play
    int Movement(int rate);
    SnakeCrawl getSnakeWay()const;
};


#endif //SNAKE_SNAKEBOARD_H
