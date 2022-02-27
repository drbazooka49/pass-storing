#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"

//check if not set, then set it, else - argv[1] - password to app -- done
//if file with pass exists, but no pass at run - exit and can't acces -- done
//if wrong pass - error message and retype or exit app -- done
//register new source,alias and pass -- done
//list all stored pass -- done
//add search and display by search result -- done

//add change option


int main(int argc, char *argv[]){
    char pass[10];
    char *ptr = pass;
    FILE *fname = NULL;
    
    if(argc == 1){
        if(CheckFile() == 1){
            //can take in new lines and spaces, so be careful
            printf("No existing file detected! Create password(max 9 characters):\n");
            scanf("%s", pass);
            //printf("%s", pass);
            fname = CreateFile();
            WritePass(fname, sizeof(pass), ptr);
        }else if(CheckFile() == 0){
            printf("Pass already created! Run again with your pass.");
            return 0;
        }
    }else if(argc == 3){
        int len = strlen(argv[1]);
        int len2 = strlen(argv[2]);
        char arg1[len + 1];
        char arg2[len2 + 1];
        char *pass;
        strcpy(arg1, argv[1]);
        strcpy(arg2, argv[2]);
        pass = ReadPass();
        if(strcmp(arg1, pass) == 0 && strcmp(arg2, "list\0") == 0){
            ListAll();
        }else if(strcmp(arg1, pass) == 0 && strcmp(arg2, "new\0") == 0){
            char fullname[20];
            int len_full = 0;
            char alias[20];
            int len_alias = 0;
            char password[20];
            int len_pass = 0;
            printf("Input new record: fullname alias password\n");
            while(scanf("%s %s %s", fullname, alias, password) == 3){
                len_full = strlen(fullname);
                len_alias = strlen(alias);
                len_pass = strlen(password);
                printf("Input: %s %s %s", fullname, alias, password);
                WriteToFile(len_full, len_alias, len_pass, 
                        fullname, alias, password);
            }
        }else if(strcmp(arg1, pass) == 0 && arg2 != NULL){
            FindWord(arg2);
        }else if(strcmp(arg1, pass) == 0){
            printf("No idea why\n");
        }
        return 0;
    }
}
