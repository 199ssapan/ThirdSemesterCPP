#pragma once
#include <Windows.h>
#include <vector>
#include <tlhelp32.h>
#include <functional>
#include <algorithm>

class ProcWork
{
	std::vector<PROCESSENTRY32> data;
public:
	void Init();
	void Print();
	ProcWork() {};
	template <typename Lambda>
	void SortBy(Lambda comp)
	{
		std::sort(this->data.begin(), this->data.end(), comp);
	}
};

