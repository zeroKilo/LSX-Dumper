
extern char* logFilename;

void OpenConsole();
bool IsThisExeName(wchar_t* name);
void StartThread(LPTHREAD_START_ROUTINE func);
void ClearFile(char* str);
void LogToFile(char* str);