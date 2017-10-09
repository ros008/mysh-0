#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "commands.h"

int do_cd(int argc, char** argv) {
        if (!validate_cd_argv(argc, argv))
                return -1;
        //chdir(argv[1]);

        return 0; 
}

int do_pwd(int argc, char** argv) {
        if (!validate_pwd_argv(argc, argv))
                return -1;

        char buffer[256];
        getcwd(buffer, 256);
        printf("%s\n", buffer);

        return 0;
}

int validate_cd_argv(int argc, char** argv) {
        if(argc > 2)
                return 0;

        ////////////not existing file or directory
        else if(chdir(argv[1])!=0)//not succeed
                return 0;


        return 1;
}

int validate_pwd_argv(int argc, char** argv) {
        char buffer[256];
        if(argc != 1)
                return 0;
        else if(getcwd(buffer, 256) == NULL)
                return 0;

        return 1;
}
