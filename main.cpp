#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board game;

    cout << "Welcome to Minesweeper!\n";

    // Display Player Board
    game.showBoard();

    // Display Internal Board for Testing
    game.showInternalBoard();

    // Verify Total Mines
    cout << "Total Mines: " << game.countMines() << endl;

    return 0;
}