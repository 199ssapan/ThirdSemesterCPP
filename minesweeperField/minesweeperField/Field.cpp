#include "Field.h"
#include <ctime>
#include <iostream>
#include <algorithm>

Field::Field(int rows, int columns)
{
	srand((unsigned)time(0));
	this->rows = rows;
	this->columns = columns;
	this->field = new char* [rows];
	this->gameField = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->field[i] = new char[columns];
		this->gameField[i] = new char[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int putMine = rand() % 101;
			if (putMine < 20) this->field[i][j] = '*';
			else this->field[i][j] = ' ';
			this->gameField[i][j] = '#';
		}
	}
	this->fillInField();
}

Field::Field(int rows, int columns, int percent)
{
	srand((unsigned)time(0));
	this->rows = rows;
	this->columns = columns;
	this->field = new char* [rows];
	this->gameField = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->field[i] = new char[columns];
		this->gameField[i] = new char[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int putMine = rand() % 101;
			if (putMine < percent) this->field[i][j] = '*';
			else this->field[i][j] = ' ';
			this->gameField[i][j] = '#';
		}
	}
	this->fillInField();
}

void Field::PrintField()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			std::cout << this->gameField[i][j] << "|";
		}
		std::cout << std::endl;
	}
}

void Field::openNeighbours(int row, int col)
{
	if (this->isValid(row, col) == true)
	{
		this->gameField[row][col] = this->field[row][col];
	}
	if (this->isValid(row - 1, col) == true)
	{
		this->gameField[row - 1][col] = this->field[row - 1][col];
	}

	if (isValid(row + 1, col) == true)
	{
		this->gameField[row + 1][col] = this->field[row + 1][col];
	}

	if (isValid(row, col + 1) == true)
	{
		this->gameField[row][col + 1] = this->field[row - 1][col + 1];
	}

	if (isValid(row, col - 1) == true)
	{
		this->gameField[row][col - 1] = this->field[row][col - 1];
	}

	if (isValid(row - 1, col + 1) == true)
	{
		this->gameField[row - 1][col + 1] = this->field[row - 1][col + 1];
	}

	if (isValid(row - 1, col - 1) == true)
	{
		this->gameField[row - 1][col - 1] = this->field[row - 1][col - 1];
	}

	if (isValid(row + 1, col + 1) == true)
	{
		this->gameField[row + 1][col + 1] = this->field[row + 1][col + 1];
	}

	if (isValid(row + 1, col - 1) == true)
	{
		this->gameField[row + 1][col - 1] = this->field[row + 1][col - 1];
	}
}

void Field::fillInField()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (this->field[i][j] != '*')
			{
				this->field[i][j] = char('0' + this->countNeighboursMines(i, j));
			}
		}
	}
}


bool Field::isValid(int row, int col)
{
	return (row >= 0) && (row < this->rows) &&
		(col >= 0) && (col < this->columns);
}

int Field::countNeighboursMines(int row, int col)
{

    int i;
    int count = 0;

    if (this->isValid(row - 1, col) == true)
    {
        if (this->field[row - 1][col] == '*')
            count++;
    }

    if (isValid(row + 1, col) == true)
    {
		if (this->field[row + 1][col] == '*')
			count++;
    }

    if (isValid(row, col + 1) == true)
    {
		if (this->field[row][col + 1] == '*')
			count++;
    }

    if (isValid(row, col - 1) == true)
    {
		if (this->field[row][col - 1] == '*')
			count++;
    }

    if (isValid(row - 1, col + 1) == true)
    {
		if (this->field[row - 1][col + 1] == '*')
			count++;
    }

    if (isValid(row - 1, col - 1) == true)
    {
		if (this->field[row - 1][col - 1] == '*')
			count++;
    }

    if (isValid(row + 1, col + 1) == true)
    {
		if (this->field[row + 1][col + 1] == '*')
			count++;
    }

    if (isValid(row + 1, col - 1) == true)
    {
		if (this->field[row + 1][col - 1] == '*')
			count++;
    }
    return count;
}

void Field::inputCoords(int x, int y)
{
	if (x < 0 || y < 0) return;
	if (this->field[x][y] == '0')
	{
		this->openNeighbours(x, y);
	}
	else if (this->field[x][y] == '*')
	{
		std::cout << "You lose" << std::endl;
	}
	else this->gameField[x][y] = this->field[x][y];
}

