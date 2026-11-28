
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    static const int SIZE = 9;

    // Internal Board
    char internalBoard[SIZE][SIZE];

    // Display Board
    char displayBoardArray[SIZE][SIZE];

public:
    Board();

    void initializeBoards();
    void placeMines();

    void showDisplayBoard();
    void showInternalBoard();
};

#endif
