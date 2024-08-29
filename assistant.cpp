#include "assistant.h"

Assistant::Assistant(QObject *parent) : QObject(parent)
{

}

void Assistant::openNotepadAndType(const QString &text)
{
    const wchar_t* notepadPath = L"C:\\Windows\\System32\\notepad.exe";

    STARTUPINFO startupInfo;
    PROCESS_INFORMATION processInfo;

    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory(&processInfo, sizeof(processInfo));

    if (CreateProcess(
            notepadPath,
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &startupInfo,
            &processInfo)
        ) {
        WaitForInputIdle(processInfo.hProcess, 1000);
        typeText(text.toStdString());
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    } else {
        qWarning("Failed to start Notepad.");
    }
}

void Assistant::typeText(const std::string &text)
{
    for(char c: text)
    {
        SHORT vk = VkKeyScanA(c);
        keybd_event(vk,0,0,0);
        keybd_event(vk,0,KEYEVENTF_KEYUP,0);
    }
}
