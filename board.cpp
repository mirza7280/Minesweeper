
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

// Constructor
Board::Board()
{
    srand(time(0));

    initializeBoards();
    placeMines();
}

// Initialize both boards
void Board::initializeBoards()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Internal board
            internalBoard[i][j] = '0';

            // Display board
            displayBoardArray[i][j] = '#';
        }
    }
}

// Place 10 random mines
void Board::placeMines()
{
    int minesPlaced = 0;

    while (minesPlaced < 10)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (internalBoard[row][col] == '0')
        {
            internalBoard[row][col] = 'M';
            minesPlaced++;
        }
    }
}

// Display player board
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

// Display internal board for testing
void Board::showInternalBoard()
{
    cout << "\nINTERNAL BOARD (Testing)\n";

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Print character directly, not ASCII value
            cout << internalBoard[i][j] << "  ";
        }

        cout << endl;
    }
}

// Main function
int main()
{
    Board game;

    cout << "==== MINESWEEPER ====" << endl;

    game.showDisplayBoard();

    game.showInternalBoard();

    return 0;
}
