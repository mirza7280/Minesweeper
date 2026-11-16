
#include <iostream>
#include "Board.h"

using namespace std;

// Constructor
Board::Board()
{
    initializeBoards();
}

// Initialize both boards
void Board::initializeBoards()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Internal board
            internalBoard[i][j] = 0;

            // Display board
            displayBoardArray[i][j] = '#';
        }
    }
}

// Display board
void Board::showDisplayBoard()
{
    cout << "\n       ";

    // Column numbers
    for (int j = 0; j < SIZE; j++)
    {
        cout << j + 1 << "  ";
    }

    cout << endl;

    // Rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        cout << "   " << i + 1 << "   ";

        for (int j = 0; j < SIZE; j++)
        {
            cout << displayBoardArray[i][j] << "  ";
        }

        cout << endl;
    }
}

// Main function
int main()
{
    Board game;

    cout << "========== MINESWEEPER ==========" << endl;

    game.showDisplayBoard();

    return 0;
}
