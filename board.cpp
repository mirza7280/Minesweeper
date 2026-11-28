#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"

using namespace std;

// Constructor
Board::Board()
{
    srand(time(0));

    initializeBoards();
    placeMines();
    countAdjacentMines();
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

// Count adjacent mines
void Board::countAdjacentMines()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // Skip mine cells
            if (internalBoard[i][j] == 'M')
            {
                continue;
            }

            int count = 0;

            // Check 8 neighboring cells
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    // Skip current cell
                    if (r == 0 && c == 0)
                    {
                        continue;
                    }

                    int newRow = i + r;
                    int newCol = j + c;

                    // Check board boundaries
                    if (newRow >= 0 && newRow < SIZE &&
                        newCol >= 0 && newCol < SIZE)
                    {
                        if (internalBoard[newRow][newCol] == 'M')
                        {
                            count++;
                        }
                    }
                }
            }

            // Convert integer to character
            internalBoard[i][j] = '0' + count;
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