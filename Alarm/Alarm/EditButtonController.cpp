#include "EditButtonController.hpp"
#include <Windows.h>
#include <cstdio>

EditButtonController::EditButtonController(HWND hWnd, int lMacroHandler, int rMacroHandler, int x, int y, int downLimit, int upperLimit)
{
	CreateWindowW(L"Button", L"<", WS_VISIBLE | WS_CHILD, x, y + 20, 25, 20, hWnd, (HMENU)lMacroHandler, NULL, NULL);
	CreateWindowW(L"Button", L">", WS_VISIBLE | WS_CHILD, x + 25, y + 20, 25, 20, hWnd, (HMENU)rMacroHandler, NULL, NULL);
	this->hEdit = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, x, y, 50, 20, hWnd, NULL, NULL, NULL);
	this->dLim = downLimit;
	this->upLim = upperLimit;
}

EditButtonController::EditButtonController() {}

void EditButtonController::SetValueEdit(WORD value)
{
	TCHAR buffer[10];
	_swprintf(buffer, L"%i", value);
	SetWindowTextW(this->hEdit, buffer);
}

int EditButtonController::GetValueEdit()
{
	TCHAR buf[5];
	GetWindowTextW(this->hEdit, buf, 5);
	int res = _wtoi(buf);
	return res;
}

void EditButtonController::incr()
{
	TCHAR buf[5];
	GetWindowTextW(this->hEdit, buf, 5);
	int res = _wtoi(buf);
	if (res >= this->upLim)
		return;
	res++;
	_itow(res, buf, 10);
	SetWindowTextW(this->hEdit, buf);
}

void EditButtonController::decr()
{
	TCHAR buf[5];
	GetWindowTextW(this->hEdit, buf, 5);
	int res = _wtoi(buf);
	if (res <= this->dLim)
		return;
	res--;
	_itow(res, buf, 10);
	SetWindowTextW(this->hEdit, buf);
}