#include "stdafx.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include "Helper.h"
#include "DetouredFunctions.h"

WORD ordDecrypt = -1;
WORD ordEncrypt = -1;
TCHAR* dllName = L"OriginClient.dll";

void FindExports()
{
	HMODULE lib = LoadLibraryEx(dllName, NULL, DONT_RESOLVE_DLL_REFERENCES);
	PIMAGE_NT_HEADERS header = (PIMAGE_NT_HEADERS)((BYTE *)lib + ((PIMAGE_DOS_HEADER)lib)->e_lfanew);
	PIMAGE_EXPORT_DIRECTORY exports = (PIMAGE_EXPORT_DIRECTORY)((BYTE *)lib + header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
	BYTE** names = (BYTE**)((int)lib + exports->AddressOfNames);
	for (int i = 0; i < exports->NumberOfNames; i++)
	{
		char* name = (char*)((BYTE *)lib + (int)names[i]);
		if(strstr(name, "decrypt@Simple") != NULL)
			ordDecrypt = i + 1;
		if(strstr(name, "encrypt@Simple") != NULL)
			ordEncrypt = i + 1;
	}
	FreeLibrary(lib);
}
DWORD WINAPI WaitForOriginClientDLL(LPVOID lpParam)
{
	HMODULE hMod;
	while((hMod = GetModuleHandle(dllName)) == NULL)
		Sleep(1000);
	printf("\"%S\" loaded...\n", dllName);
	DoDetours(dllName, ordDecrypt, ordEncrypt);
	return 1;
}

void HackMain()
{
	if(!IsThisExeName(L"Origin.exe"))
		return;
	//OpenConsole();
	printf("Args = %S\n", GetCommandLine());
	FindExports();
	if(ordDecrypt != -1) printf("Decryption Export Ordinal = %d\n", ordDecrypt);
	if(ordEncrypt != -1) printf("Encryption Export Ordinal = %d\n", ordEncrypt);
	ClearFile(logFilename);
	MessageBox(NULL, _T("LSX Dumper active!"), _T("by Warranty Voider"), NULL);
	StartThread(WaitForOriginClientDLL);
}

void HackExit()
{
}