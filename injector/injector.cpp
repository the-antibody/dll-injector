#include "injector.h"

// constructor
injector::injector(LPCSTR dll_path, int process_id)
{
    this->dll_path = dll_path;
    this->process_id = process_id;
}

// inject function
void injector::inject()
{
    // process handle
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->get_process_id());

    // check if process was found
    if (hProcess == 0000000000000000)
    {
        // throw exception
        exception exception("Process not found.", PROCESS_NOT_FOUND);
        exception.throw_exception();
        return;
    }

    // dll base address
    LPVOID baseAddress = VirtualAllocEx(hProcess, NULL, strlen(this->get_dll_path()) + 1, MEM_COMMIT, PAGE_READWRITE);

    // check if base address is null
    if (baseAddress == 0000000000000000)
    {
        // throw exception
        exception exception("Couldn't allocate memory to process.", INJECTION_EXCEPTION);
        exception.throw_exception();
        return;
    }

    try
    {
        // write to process memory
        WriteProcessMemory(hProcess, baseAddress, (LPCVOID)this->get_dll_path(), strlen(this->get_dll_path()) + 1, NULL);
    }
    catch (...)
    {
        // throw exception
        exception exception("Couldn't write to process memory.", INJECTION_EXCEPTION);
        exception.throw_exception();
        return;
    }

    // create a remote thread in the process
    LPVOID loadLibrary = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    HANDLE hLoadThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)loadLibrary, baseAddress, 0, 0);

    if (hLoadThread == 0)
    {
        // throw exception
        exception exception("Coudln't create a thread inside of the process.", INJECTION_EXCEPTION);
        exception.throw_exception();
        return;
    }

    // wait to inject, then free memory
    WaitForSingleObject(hLoadThread, INFINITE);
    VirtualFreeEx(hProcess, baseAddress, strlen(this->get_dll_path()) + 1, MEM_RELEASE);

    // print
    std::cout << "DLL successfully injected into " << process_id << std::endl;
}