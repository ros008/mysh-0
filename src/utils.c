#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
        char **ws;
        char *t;
        const char *temp;
        const char *word;
        int num = 0;
        int i;
        int sp = 1;
        int wlen = 0;


        temp = command;

        if(*temp){
                while(*temp){
                        if(*temp == ' ' || *temp == '\t' || *temp == '\n'){
                                sp = 1;
                        }
                        else{
                                if(sp)
                                        num++;
                                sp =0;
                        }
                        *temp++;
                }

                ws = (char **)malloc(sizeof(char *)*num);
                t = (char *)malloc(strlen(command)+1);

                strcpy(t, command);

                i = 0;
                sp = 1;
                word = NULL;
                while(*t){
                        if(*t == ' ' || *t == '\n' || *t == '\t'){
                                if(wlen>0){
                                        ws[i] = (char *)malloc(sizeof(char)*wlen+1);
                                        strncpy(ws[i], word, wlen);
                                        ws[i][wlen] = '\0';
                                        i++;
                                }
                                wlen = 0;
                        }

                        else{
                                if(wlen == 0){
                                        word = t;

                                }
                                wlen++;
                        }
                        t++;
                }
                if(wlen){
                         ws[i] = (char *)malloc(sizeof(char)*wlen+1);
                         strncpy(ws[i], word, wlen);
                         ws[i][wlen] = '\0';
                }
        }
        if(num == 0){
                ws[0] = (char *)malloc(sizeof(char)*1);
                ws[0][0] = 0;
                num++;
        }
        *argc = num;
        *argv = ws;
}
