#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "detours.h"
#include "Helper.h"

DWORD (__thiscall* orgDecrypt) (void* , DWORD , DWORD);
DWORD (__thiscall* orgEncrypt) (void* , DWORD , DWORD);

DWORD __fastcall myDecrypt(void *THIS, DWORD EDX, DWORD a1, DWORD a2) {
	DWORD result = orgDecrypt(THIS, a1, a2);
	LogToFile("Decrypt:\n");
	LogToFile((char*)*(DWORD*)result);
	return result;
}

DWORD __fastcall myEncrypt(void *THIS, DWORD EDX, DWORD a1, DWORD a2) {
	LogToFile("Encrypt:\n");
	LogToFile((char*)*(DWORD*)a2);
	return orgEncrypt(THIS, a1, a2);
}

void DoDetours(TCHAR* dllName, WORD ordDecrypt, WORD ordEncrypt)
{
	HMODULE h;
    FARPROC address;
	printf("Start API detouring...\n");
	if((h = GetModuleHandle(dllName)) != nullptr)
    {
        printf("%S Module = 0x%x\n", dllName, h);          
		if(ordDecrypt != -1 && (address = GetProcAddress(h, (LPCSTR)ordDecrypt)) != nullptr)
        {
            printf("Decrypt Address = 0x%x\n", address);
			orgDecrypt = (DWORD(__thiscall*) (void*, DWORD, DWORD)) DetourFunction((PBYTE)address, (PBYTE)myDecrypt);
        }
		if(ordEncrypt != -1 && (address = GetProcAddress(h, (LPCSTR)ordEncrypt)) != nullptr)
        {
            printf("Encrypt Address = 0x%x\n", address);
			orgEncrypt = (DWORD(__thiscall*) (void*, DWORD, DWORD)) DetourFunction((PBYTE)address, (PBYTE)myEncrypt);
        }
	}
	printf("Finished API detouring\n");
}