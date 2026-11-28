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
    // Constructor
    Board();

    // Initialize both boards
    void initializeBoards();

    // Place 10 random mines
    void placeMines();

    // Count mines around each cell
    void countAdjacentMines();

    // Display boards
    void showDisplayBoard();
    void showInternalBoard();
};

#endif