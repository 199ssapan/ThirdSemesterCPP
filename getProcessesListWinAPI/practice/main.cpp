#include <windows.h>
#include <tlhelp32.h>
#include "ProcWork.hpp"
#include <string>


INT main() 
{
    ProcWork pw = ProcWork();
    pw.Init();
    pw.Print();
    pw.SortBy([](const PROCESSENTRY32W& a, const PROCESSENTRY32W& b) {
        std::wstring nameA(a.szExeFile);
        std::wstring nameB(b.szExeFile);
        return nameA < nameB; 
        });
    pw.Print();
    pw.SortBy([](const PROCESSENTRY32W& a, const PROCESSENTRY32W& b) {
        return a.th32ProcessID < b.th32ProcessID;
        });
    pw.Print();
}