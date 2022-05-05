#ifndef SNAKE_SNAKEBOARD_H
#define SNAKE_SNAKEBOARD_H

enum GameMode{EASY, MEDIUM, HARD};

struct Field{
    bool energy;
    bool miss;
    bool snake;
};
class SnakeBoard {
private:
    Field board[100][100];
public:
    void update();
    bool turn_Left();
    bool turn_Right();
    void debug_display();
    void clear_board();
    void snake_len();
};


#endif //SNAKE_SNAKEBOARD_H
