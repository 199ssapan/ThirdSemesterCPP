#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <string.h>
#include <iostream>

#define OPEN_FILE_BUTTON 1
#define BUFSIZE 1024
#define MD5LEN  16

HWND hOut;
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void AddControls(HWND);
void open_file(HWND hWnd);
int getHash(wchar_t* fileName);


HWND hMainWindow;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"GetHashWindowClass";
    WNDCLASSW wc = { };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);
    hMainWindow = CreateWindowW(CLASS_NAME, L"Get Hash", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN, 100, 100, 300, 150, NULL, NULL, NULL, NULL);

    MSG msg = { };
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

void open_file(HWND hWnd)
{
    OPENFILENAME ofn;

    wchar_t file_name[100];

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFile = file_name;
    ofn.lpstrFile[0] = L'\0';
    ofn.nMaxFile = 100;
    ofn.lpstrFilter = L"All files\0*.*\0Source Files\0*.CPP\0Text Files\0*.TXT\0";
    ofn.nFilterIndex = 1;
    GetOpenFileNameW(&ofn);
    getHash(file_name);
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (wp)
        {
        case OPEN_FILE_BUTTON:
            open_file(hWnd);
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
        return DefWindowProc(hWnd, msg, wp, lp);
    }
}

void AddControls(HWND hWnd)
{
    CreateWindowW(L"Button", L"Open File", WS_VISIBLE | WS_CHILD, 10, 10, 140, 36, hWnd, (HMENU)OPEN_FILE_BUTTON, NULL, NULL);
    hOut = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 80, 270, 20, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Hash of the transmitted file", WS_VISIBLE | WS_CHILD, 10, 45, 150, 30, hWnd, NULL, NULL, NULL);
}

int getHash(wchar_t* fileName)
{
    DWORD dwStatus = 0;
    BOOL bResult = FALSE;
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HANDLE hFile = NULL;
    BYTE rgbFile[BUFSIZE];
    DWORD cbRead = 0;
    BYTE rgbHash[MD5LEN];
    DWORD cbHash = 0;
    CHAR rgbDigits[] = "0123456789abcdef";
    LPCWSTR filename = fileName;
    // Logic to check usage goes here.

    hFile = CreateFileW(filename,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_SEQUENTIAL_SCAN,
        NULL);

    if (INVALID_HANDLE_VALUE == hFile)
    {
        dwStatus = GetLastError();

        return dwStatus;
    }

    // Get handle to the crypto provider
    if (!CryptAcquireContext(&hProv,
        NULL,
        NULL,
        PROV_RSA_FULL,
        CRYPT_VERIFYCONTEXT))
    {
        dwStatus = GetLastError();
        CloseHandle(hFile);
        return dwStatus;
    }

    if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
    {
        dwStatus = GetLastError();
        CloseHandle(hFile);
        CryptReleaseContext(hProv, 0);
        return dwStatus;
    }

    while (bResult = ReadFile(hFile, rgbFile, BUFSIZE,
        &cbRead, NULL))
    {
        if (0 == cbRead)
        {
            break;
        }

        if (!CryptHashData(hHash, rgbFile, cbRead, 0))
        {
            dwStatus = GetLastError();
            CryptReleaseContext(hProv, 0);
            CryptDestroyHash(hHash);
            CloseHandle(hFile);
            return dwStatus;
        }
    }

    if (!bResult)
    {
        dwStatus = GetLastError();
        CryptReleaseContext(hProv, 0);
        CryptDestroyHash(hHash);
        CloseHandle(hFile);
        return dwStatus;
    }

    cbHash = MD5LEN;
    char buffer[33] = { 0 };
    if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
    {

        int index = 0;
        for (DWORD i = 0; i < cbHash; i++)
        {
            buffer[index] = rgbDigits[rgbHash[i] >> 4];
            buffer[index + 1] = rgbDigits[rgbHash[i] & 0xf];
            index += 2;

        }
    }
    else
    {
        dwStatus = GetLastError();
    }

    buffer[32] = '\0';

    char text[] = "something";
    wchar_t wtext[33];
    std::mbstowcs(wtext, buffer, strlen(buffer) + 1);
    LPWSTR ptr = wtext;


    SetWindowText(hOut, wtext);


    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
    CloseHandle(hFile);
}
