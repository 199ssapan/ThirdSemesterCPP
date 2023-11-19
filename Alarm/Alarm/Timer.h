#pragma once
#include <vector>
#include <Windows.h>
#include <string>

#define SET_TIME_BUTTON 1
#define INCREMENT_HOURS 2
#define DECREMENT_HOURS 3
#define INCREMENT_MINUTES 4
#define DECREMENT_MINUTES 5
#define INCREMENT_DAYS 6
#define DECREMENT_DAYS 7
#define INCREMENT_MONTHS 8
#define DECREMENT_MONTHS 9
#define INCREMENT_YEARS 10
#define DECREMENT_YEARS 11
#define IDC_COMBO 12
#define STOP_SOUND_BUTTON 13
#define SET_MUSIC_BUTTON 14
#define DELETE_ENTRY_BUTTON 15

class Timer
{
public:
	Timer();
	void Push_back(WORD minutes, WORD hours, WORD days, WORD months, WORD years, HWND hCombo);
	void StartSound(HWND hMainWindow, int index);
	void StopSound();
	int CheckTime(SYSTEMTIME systime);
	void DeleteTime(int index);
	void SetMusic(HWND hWnd, int index);
protected:
	class TIME_BLOCK
	{
	public:
		TIME_BLOCK(WORD minutes, WORD hours, WORD days, WORD months, WORD years, const wchar_t* fileName);
		WORD minutes;
		WORD hours;
		WORD days;
		WORD months;
		WORD years;
		std::wstring file_name;
	};
	std::vector<TIME_BLOCK> data;
	
private:
	static std::wstring joinTime(std::wstring str, WORD num)
	{
		std::wstring res;
		if (num / 10 == 0)
		{
			res = std::to_wstring(0);
			res += std::to_wstring(num);
		}
		else
		{
			res = std::to_wstring(num);
		}
		return res;
	}
};


