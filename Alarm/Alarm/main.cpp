#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <iostream>
#include "EditButtonController.hpp"
#include <vector>
#include "Timer.h"
#include <string>



LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void AddControls(HWND);


HWND hMainWindow;
EditButtonController hoursCtrl;
EditButtonController minutesCtrl;

EditButtonController daysCtrl;
EditButtonController monthsCtrl;
EditButtonController yearsCtrl;

SYSTEMTIME LOCAL_TIME;

Timer TIMER;

HWND hCombo;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"Alarm";
    WNDCLASSW wc = { };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);
    
    hMainWindow = CreateWindowW(CLASS_NAME, L"Alarm", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN, 100, 100, 600, 500, NULL, NULL, NULL, NULL);

    HICON hIcon = (HICON)LoadImage(hInstance, L".\\pics\\clock.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE);
    SendMessage(hMainWindow, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

    MSG msg = { };
    int flag = 0;
    SYSTEMTIME prevLocalTime;
    GetLocalTime(&prevLocalTime);
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        GetLocalTime(&LOCAL_TIME);
        if (prevLocalTime.wMinute != LOCAL_TIME.wMinute)
        {
            flag = 0;
        }
        int i;
        if ((i =TIMER.CheckTime(LOCAL_TIME)) != -1 && flag == 0)
        {
            TIMER.StartSound(hMainWindow, i);
            flag = 1;
            GetSystemTime(&prevLocalTime);
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    TCHAR buf[5];
    int mon;
    int days;
    int hours;
    int mins;
    int years;
    int selectedItemIndex = 0;
    switch (msg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case DELETE_ENTRY_BUTTON:
            selectedItemIndex = SendMessage(hCombo, CB_GETCURSEL, 0, 0);

            if (selectedItemIndex != CB_ERR)
            {
                int result = MessageBox(hWnd, L"Are you sure you want to delete the entry?", L"Confirmation", MB_OKCANCEL | MB_ICONQUESTION);

                if (result == IDOK)
                {
                    SendMessage(hCombo, CB_DELETESTRING, selectedItemIndex, 0);
                    TIMER.DeleteTime(selectedItemIndex);
                }
            }
            break;
        case SET_TIME_BUTTON:
            mon = monthsCtrl.GetValueEdit();
            days = daysCtrl.GetValueEdit();
            hours = hoursCtrl.GetValueEdit();
            mins = minutesCtrl.GetValueEdit();
            years = yearsCtrl.GetValueEdit();
            if (years == LOCAL_TIME.wYear)
            {
                if (mon <= LOCAL_TIME.wMonth)
                {
                    if (days <= LOCAL_TIME.wDay)
                    {
                        if (hours <= LOCAL_TIME.wHour)
                        {
                            if (mins <= LOCAL_TIME.wMinute)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            
            TIMER.Push_back(mins, hours, days, mon, years, hCombo);
            break;
        case STOP_SOUND_BUTTON:
            TIMER.StopSound();
            selectedItemIndex = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
            if (selectedItemIndex != CB_ERR)
            {
                SendMessage(hCombo, CB_DELETESTRING, selectedItemIndex, 0);
                TIMER.DeleteTime(selectedItemIndex);
                UpdateWindow(hCombo);
            }
            break;
        case INCREMENT_HOURS:
            hoursCtrl.incr();
            break;
        case DECREMENT_HOURS:
            hoursCtrl.decr();
            break;
        case INCREMENT_MINUTES:
            minutesCtrl.incr();
            break;
        case DECREMENT_MINUTES:
            minutesCtrl.decr();
            break;
        case INCREMENT_DAYS:
            daysCtrl.incr();
            break;
        case DECREMENT_DAYS:
            daysCtrl.decr();
            break;
        case INCREMENT_MONTHS:
            monthsCtrl.incr();
            break;
        case DECREMENT_MONTHS:
            monthsCtrl.decr();
            break;
        case INCREMENT_YEARS:
            yearsCtrl.incr();
            break;
        case DECREMENT_YEARS:
            yearsCtrl.decr();
            break;
        case IDC_COMBO:
            switch (HIWORD(wParam))
            {
            /*case CBN_SELCHANGE:
                
                selectedIndex = SendMessage(hCombo, CB_GETCURSEL, 0, 0);

                if (selectedIndex != CB_ERR) 
                {
                    int result = MessageBox(hWnd, L"Are you sure you want to delete the entry?", L"Confirmation", MB_OKCANCEL | MB_ICONQUESTION);

                    if (result == IDOK) 
                    {
                        SendMessage(hCombo, CB_DELETESTRING, selectedIndex, 0);
                        TIMER.DeleteTime(selectedIndex);
                    }
                }
                break;*/
            }
            break;
        case SET_MUSIC_BUTTON:
            int selectedItemIndex = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
            if (selectedItemIndex != CB_ERR)
            {
                TIMER.SetMusic(hWnd, selectedItemIndex);
            }
            break;
        }
        break;
    case WM_CREATE:
        AddControls(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}


void AddControls(HWND hWnd)
{
    SYSTEMTIME lt;
    GetLocalTime(&lt);

    hoursCtrl = EditButtonController(hWnd, DECREMENT_HOURS, INCREMENT_HOURS, 110, 10, 0, 23);
    minutesCtrl = EditButtonController(hWnd, DECREMENT_MINUTES, INCREMENT_MINUTES, 160, 10, 0, 59);
    daysCtrl = EditButtonController(hWnd, DECREMENT_DAYS, INCREMENT_DAYS, 220, 10, 1, 31);
    monthsCtrl = EditButtonController(hWnd, DECREMENT_MONTHS, INCREMENT_MONTHS, 270, 10, 1, 12);
    yearsCtrl = EditButtonController(hWnd, DECREMENT_YEARS, INCREMENT_YEARS, 320, 10, lt.wYear, INT_MAX);

    CreateWindowW(L"Button", L"Set Time", WS_VISIBLE | WS_CHILD, 130, 50, 120, 50, hWnd, (HMENU)SET_TIME_BUTTON, NULL, NULL);
    hoursCtrl.SetValueEdit(lt.wHour);
    minutesCtrl.SetValueEdit(lt.wMinute);
    daysCtrl.SetValueEdit(lt.wDay);
    monthsCtrl.SetValueEdit(lt.wMonth);
    yearsCtrl.SetValueEdit(lt.wYear);

    hCombo = CreateWindowExW(NULL,                              
        L"COMBOBOX",                                                            
        NULL,                                                                 
        WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | CBS_AUTOHSCROLL | CBS_SORT,        
        100, 150,                                                          
        280, 200,                                      
        hWnd,                                  
        (HMENU)IDC_COMBO,                                                  
        NULL,                                                        
        NULL);
    CreateWindowW(L"Button", L"Set Music", WS_VISIBLE | WS_CHILD, 400, 10, 120, 40, hWnd, (HMENU)SET_MUSIC_BUTTON, NULL, NULL);
    CreateWindowW(L"Button", L"Delete Entry", WS_VISIBLE | WS_CHILD, 400, 150, 120, 40, hWnd, (HMENU)DELETE_ENTRY_BUTTON, NULL, NULL);
}