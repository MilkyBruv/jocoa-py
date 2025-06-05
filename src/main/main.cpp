#include <iostream>
#include <string>
#include <stdlib.h>

#if defined(__WIN32) || defined(__WIN64)
    #include <windows.h>
    #include <libgen.h>
    #define CP_SEPERATOR ';'
#elif defined(__linux__) || defined(__unix__)
    #include <unistd.h>
    #include <limits.h>
    #include <libgen.h>
    #include <linux/limits.h>
    #define CP_SEPERATOR ':'
#endif
    
int main(int argc, char const *argv[])
{
    // Path buffer
    char path[PATH_MAX];

    #if defined(__WIN32) || defined(__WIN64)
        GetModuleFileName(NULL, path, MAX_PATH);
    #elif defined(__linux__) || defined(__unix__)
        ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
        if (count != -1) {
            path[count] = '\0';
        }
    #endif

    char* dir = dirname(path);

    // Build command
    std::string command = "python " + std::string(dir) + "/jocoa-py-src/main.py";

    for (size_t i = 0; i < argc; i++)
    {
        command += " " + std::string(argv[i]);
    }

    // Run python
    system(command.c_str());

    return 0;
}
