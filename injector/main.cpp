#include <string>

#include "injector.h"
#include "process.h"

int main(int argc, char* argv[])
{
    // check argument length
    if (argc < 3)
    {
        // throw exception
        exception exception("Correct Usage: inject <dll> <pid>", INCORRECT_USAGE);
        exception.throw_exception();
        exit(0);
    }


    // get path to DLL & PID
    LPCSTR dll_path = (LPCSTR)argv[1];
    int process_id = 0;

    // convert to integer
    try
    {
        // set process ID
        process_id = std::stoi(argv[2]);
    }
    catch (...)
    {
        // create name buffer
        std::string name = argv[2];

        // check argument length
        if (argc > 3)
        {
            for (int i = 3; i < argc; i++)
                name = name + " " + argv[i];
        }
        // if no spaces, set to third argument
        else name = argv[2];

        // add .exe extension
        name = name + ".exe";

        // get by ID
        process_id = get_process_id_from_name(name);
    }

    // inject
    injector injector(dll_path, process_id);
    injector.inject();

    return 0;
}