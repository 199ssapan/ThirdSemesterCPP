#pragma once
#include <Windows.h>
class EditButtonController
{
public:
	EditButtonController(HWND hWnd, int lMacroHandler, int rMacroHandler, int x, int y, int downLimit, int upperLimit);
	EditButtonController();
	void SetValueEdit(WORD value);
	int GetValueEdit();
	void incr();
	void decr();
private:
	HWND hEdit;
	int dLim;
	int upLim;
};

