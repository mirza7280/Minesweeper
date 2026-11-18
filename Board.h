#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;

class Board
{
private:

    static const int SIZE = 9;
    static const int MINES = 10;

    vector<vector<int>> internalBoard;
    vector<vector<char>> displayBoard;

    void placeMines();
    void calculateNumbers();

public:

    Board();

    void showBoard();

    int getCellValue(int row, int col);

    bool isValid(int row, int col);

};

#endif