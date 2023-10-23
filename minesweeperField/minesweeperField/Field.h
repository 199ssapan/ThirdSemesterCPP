#pragma once
#include <vector>
class Field
{
private:
	char** field;
	char** gameField;
	int rows;
	int columns;
	bool isValid(int row, int col);
	void fillInField();
	int countNeighboursMines(int row, int col);
	
	void openNeighbours(int row, int col);

public:
	Field(int height, int width);
	Field(int height, int width, int percent);
	void PrintField();
	void inputCoords(int x, int y);
};

