#pragma once

#ifndef PROCESS_H
#define PROCESS_H
#endif

#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

// get process by it's name
int get_process_id_from_name(std::string name)
{
    DWORD process_id = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 process_entry;
        process_entry.dwSize = sizeof(process_entry);

        if (Process32First(hSnap, &process_entry))
        {
            // name as string and wide string
            std::wstring w_str;
            std::string exe_name;

            while (Process32Next(hSnap, &process_entry))
            {
                // convert from wchar_t*
                w_str = std::wstring(process_entry.szExeFile);
                exe_name = std::string(w_str.begin(), w_str.end());

                // check for match
                if (name == exe_name)
                {
                    // set ID & break
                    process_id = process_entry.th32ProcessID;
                    break;
                }
            }
        }
    }

    // close the handle
    CloseHandle(hSnap);
    return process_id;
}