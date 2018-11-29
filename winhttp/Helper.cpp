#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>

char* logFilename = "LSX_Log.txt";

void OpenConsole()
{
	AllocConsole();
	freopen("conin$","r",stdin);
	freopen("conout$","w",stdout);
	freopen("conout$","w",stderr);
	HWND consoleHandle = GetConsoleWindow();
	MoveWindow(consoleHandle,1,1,680,480,1);
	printf("Console initialized.\n");
}

bool IsThisExeName(wchar_t* name)
{
	wchar_t szFileName[MAX_PATH + 1];
	GetModuleFileName(NULL, szFileName, MAX_PATH + 1);
	return wcsstr(szFileName, name) != NULL;
}

void StartThread(LPTHREAD_START_ROUTINE func)
{
	DWORD dwThreadId, dwThrdParam = 1;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, func, &dwThrdParam, 0, &dwThreadId);
}

void ClearFile(char* str)
{
	FILE* fp = fopen (str, "w");
	fclose(fp);
}

void LogToFile(char* str)
{
	FILE* fp = fopen(logFilename, "a+");
	fprintf(fp, str);
	fclose(fp);
}