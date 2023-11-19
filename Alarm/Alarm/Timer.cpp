#include "Timer.h"
#include <cwchar>
#include <string>

HWND stopButton;

Timer::Timer(){}

void Timer::Push_back(WORD minutes, WORD hours, WORD days, WORD months, WORD years, HWND hCombo)
{
	const wchar_t* wcharRes;
	TIME_BLOCK time = TIME_BLOCK(minutes, hours, days, months, years, L".\\sounds\\standardSignal.wav");
	data.push_back(time);
	std::wstring res = L"";
	res += Timer::joinTime(res, hours);
	res += L":";
	res += Timer::joinTime(res, minutes);
	res += L" ";
	res += Timer::joinTime(res, days);
	res += L".";
	res += Timer::joinTime(res, months);
	res += L".";
	res += Timer::joinTime(res, years);
	wcharRes = res.c_str();
	SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)wcharRes);
	UpdateWindow(hCombo);
}

void Timer::StartSound(HWND hMainWindow, int index)
{
	const wchar_t* wcharFilename;
	stopButton = CreateWindowW(L"Button", L"Stop PLaying", WS_VISIBLE | WS_CHILD, 250, 50, 120, 50, hMainWindow, (HMENU)STOP_SOUND_BUTTON, NULL, NULL);
	UpdateWindow(hMainWindow);
	wcharFilename = this->data[index].file_name.c_str();
	PlaySound(wcharFilename, NULL, SND_FILENAME | SND_ASYNC);

}

void Timer::StopSound()
{
	PlaySound(NULL, NULL, 0);
	DestroyWindow(stopButton);
}

int Timer::CheckTime(SYSTEMTIME systime)
{
	for (int i = 0; i < this->data.size(); i++)
	{
		if (systime.wYear == this->data[i].years && systime.wMonth == this->data[i].months &&
			systime.wDay == this->data[i].days && systime.wHour == this->data[i].hours &&
			systime.wMinute == this->data[i].minutes)
			return i;
	}
	return -1;
}

void Timer::DeleteTime(int index)
{
	this->data.erase(this->data.begin() + index);
}

void Timer::SetMusic(HWND hWnd, int index)
{
	OPENFILENAME ofn;

	wchar_t file_name[100];

	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = file_name;
	ofn.lpstrFile[0] = L'\0';
	ofn.nMaxFile = 100;
	ofn.lpstrFilter = L"All files\0*.*\0*.wav\0*.mp3\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = L".\\sounds";
	GetOpenFileNameW(&ofn);
	this->data[index].file_name = file_name;
}

Timer::TIME_BLOCK::TIME_BLOCK(WORD minutes, WORD hours, WORD days, WORD months, WORD years, const wchar_t* fileName)
{
	this->days = days;
	this->hours = hours;
	this->minutes = minutes;
	this->months = months;
	this->years = years;
	this->file_name = fileName;
}
