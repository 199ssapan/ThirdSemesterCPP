#include "ProcWork.hpp"
#include <Windows.h>
#include <tlhelp32.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

void ProcWork::Init()
{
    data = std::vector<PROCESSENTRY32>();
    PROCESSENTRY32 peProcessEntry;
    TCHAR szBuff[1024];
    DWORD dwTemp;
    HANDLE CONST hSnapshot = CreateToolhelp32Snapshot(
        TH32CS_SNAPPROCESS, 0);
    if (INVALID_HANDLE_VALUE == hSnapshot) {
        return;
    }
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &peProcessEntry);
    do {
        data.push_back(peProcessEntry);
    } while (Process32Next(hSnapshot, &peProcessEntry));
}

void ProcWork::Print()
{
    for (auto v : data)
    {
        std::wcout << v.th32ProcessID << "\t" << v.szExeFile << "\n";
    }
}
