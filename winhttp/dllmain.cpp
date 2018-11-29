#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include "Hack.h"
#pragma pack(1)



extern "C" BOOL WINAPI DllMain(HINSTANCE hInst,DWORD reason,LPVOID)
{
	static HINSTANCE hL;
	if (reason == DLL_PROCESS_ATTACH)
	{
		hL = LoadLibrary(_T(".\\winhttp_org.dll"));
		if (!hL) return false;
		HackMain();
	}
	if (reason == DLL_PROCESS_DETACH)
	{
		HackExit();
		FreeLibrary(hL);
	}
	return TRUE;
}

#pragma comment(linker, "/export:WinHttpCloseHandle=winhttp_org.WinHttpCloseHandle")

#pragma comment(linker, "/export:WinHttpSetOption=winhttp_org.WinHttpSetOption")

#pragma comment(linker, "/export:WinHttpCreateUrl=winhttp_org.WinHttpCreateUrl")

#pragma comment(linker, "/export:WinHttpOpenRequest=winhttp_org.WinHttpOpenRequest")

#pragma comment(linker, "/export:WinHttpOpen=winhttp_org.WinHttpOpen")

#pragma comment(linker, "/export:WinHttpSetStatusCallback=winhttp_org.WinHttpSetStatusCallback")

#pragma comment(linker, "/export:WinHttpSendRequest=winhttp_org.WinHttpSendRequest")

#pragma comment(linker, "/export:WinHttpReceiveResponse=winhttp_org.WinHttpReceiveResponse")

#pragma comment(linker, "/export:WinHttpQueryHeaders=winhttp_org.WinHttpQueryHeaders")

#pragma comment(linker, "/export:WinHttpReadData=winhttp_org.WinHttpReadData")

#pragma comment(linker, "/export:WinHttpSetTimeouts=winhttp_org.WinHttpSetTimeouts")

#pragma comment(linker, "/export:WinHttpGetProxyForUrl=winhttp_org.WinHttpGetProxyForUrl")

#pragma comment(linker, "/export:WinHttpCrackUrl=winhttp_org.WinHttpCrackUrl")

#pragma comment(linker, "/export:WinHttpDetectAutoProxyConfigUrl=winhttp_org.WinHttpDetectAutoProxyConfigUrl")

#pragma comment(linker, "/export:WinHttpConnect=winhttp_org.WinHttpConnect")

#pragma comment(linker, "/export:WinHttpAddRequestHeaders=winhttp_org.WinHttpAddRequestHeaders")

#pragma comment(linker, "/export:WinHttpGetIEProxyConfigForCurrentUser=winhttp_org.WinHttpGetIEProxyConfigForCurrentUser")

#pragma comment(linker, "/export:WinHttpGetDefaultProxyConfiguration=winhttp_org.WinHttpGetDefaultProxyConfiguration")

#pragma comment(linker, "/export:WinHttpWriteData=winhttp_org.WinHttpWriteData")

#pragma comment(linker, "/export:WinHttpQueryDataAvailable=winhttp_org.WinHttpQueryDataAvailable")

#pragma comment(linker, "/export:SvchostPushServiceGlobals=winhttp_org.SvchostPushServiceGlobals")

#pragma comment(linker, "/export:WinHttpAutoProxySvcMain=winhttp_org.WinHttpAutoProxySvcMain")

#pragma comment(linker, "/export:WinHttpQueryOption=winhttp_org.WinHttpQueryOption")

#pragma comment(linker, "/export:Private1=winhttp_org.Private1")

#pragma comment(linker, "/export:WinHttpTimeToSystemTime=winhttp_org.WinHttpTimeToSystemTime")

#pragma comment(linker, "/export:WinHttpTimeFromSystemTime=winhttp_org.WinHttpTimeFromSystemTime")

#pragma comment(linker, "/export:WinHttpSetDefaultProxyConfiguration=winhttp_org.WinHttpSetDefaultProxyConfiguration")

#pragma comment(linker, "/export:WinHttpCheckPlatform=winhttp_org.WinHttpCheckPlatform")

#pragma comment(linker, "/export:WinHttpQueryAuthSchemes=winhttp_org.WinHttpQueryAuthSchemes")

#pragma comment(linker, "/export:WinHttpSetCredentials=winhttp_org.WinHttpSetCredentials")

#pragma comment(linker, "/export:DllCanUnloadNow=winhttp_org.DllCanUnloadNow")

#pragma comment(linker, "/export:DllGetClassObject=winhttp_org.DllGetClassObject")


