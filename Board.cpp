#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Board::Board()
{
    srand(time(0));

    // Initialize Internal Board with 0
    internalBoard = vector<vector<int>>(SIZE, vector<int>(SIZE, 0));

    // Initialize Display Board with #
    displayBoard = vector<vector<char>>(SIZE, vector<char>(SIZE, '#'));

    placeMines();

    calculateNumbers();
}


// Place 10 Random Mines
void Board::placeMines()
{
    int count = 0;

    while (count < MINES)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (internalBoard[row][col] != -1)
        {
            internalBoard[row][col] = -1;
            count++;
        }
    }
}


// Calculate Neighboring Mines
void Board::calculateNumbers()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (internalBoard[row][col] == -1)
                continue;

            int mines = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newRow = row + i;
                    int newCol = col + j;

                    if (newRow >= 0 && newRow < SIZE &&
                        newCol >= 0 && newCol < SIZE)
                    {
                        if (internalBoard[newRow][newCol] == -1)
                        {
                            mines++;
                        }
                    }
                }
            }

            internalBoard[row][col] = mines;
        }
    }
}


// Display Player Board
void Board::showBoard()
{
    cout << "\n       MINESWEEPER GAME\n\n";

    cout << "    ";

    for (int col = 0; col < SIZE; col++)
    {
        cout << setw(3) << col;
    }

    cout << "\n\n";

    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(3) << row << " ";

        for (int col = 0; col < SIZE; col++)
        {
            cout << setw(3) << displayBoard[row][col];
        }

        cout << endl;
    }

    cout << "\n";
}


// Display Internal Board (Testing Only)
void Board::showInternalBoard()
{
    cout << "\n       INTERNAL BOARD (TESTING)\n\n";

    cout << "    ";

    for (int col = 0; col < SIZE; col++)
    {
        cout << setw(3) << col;
    }

    cout << "\n\n";

    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(3) << row << " ";

        for (int col = 0; col < SIZE; col++)
        {
            cout << setw(3) << internalBoard[row][col];
        }

        cout << endl;
    }

    cout << "\n";
}


// Count Total Mines
int Board::countMines()
{
    int count = 0;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (internalBoard[row][col] == -1)
            {
                count++;
            }
        }
    }

    return count;
}


// Check Valid Position
bool Board::isValid(int row, int col)
{
    return (row >= 0 && row < SIZE &&
            col >= 0 && col < SIZE);
}


// Get Internal Cell Value
int Board::getCellValue(int row, int col)
{
    if (isValid(row, col))
    {
        return internalBoard[row][col];
    }

    return -2;
}