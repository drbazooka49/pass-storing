#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int CheckFile(){
    if(access("passes.txt", F_OK) == 0){
        return 0;
    }else{
        return 1;
    }
}
//Create file with passwords
FILE *CreateFile(){
    //input your path, ex: D://filename.txt, otherwise will be stored where the code is
    FILE *filename = fopen("passes.txt", "w+");
    if(filename == NULL){
        perror("fopen()");
        exit(1);
    }
    fclose(filename);
    printf("\nFile passes.txt created");
    return filename;
}
//Write app password to file
void WritePass(FILE *filename, int len, char* to_write ){
    filename = fopen("passes.txt", "w");
    for(int i = 0; i < len; i++){
        fputc(to_write[i], filename);
    }
    fputc('\n', filename);
    fclose(filename);
    printf("\nPass written in file");
    
}
//Read and return app password
char *ReadPass(){
    FILE *filename;
    char password[10];
    char *pass = password;
    filename = fopen("passes.txt", "r+");
    fscanf(filename, "%s", pass);
    //printf("%s", password);
    fclose(filename);
    return pass;
}
//Write fullname alias password to file
void WriteToFile(int len_name, int len_alias, int len_pass, 
                    char *fullname, char *alias, char *password){
    FILE *filename = fopen("passes.txt", "a+");
    for(int i = 0; i < len_name; i++){
        fputc(fullname[i], filename);
    }
    printf("\nFullname -- done");
    fputc(' ', filename);
    for(int i = 0; i < len_alias; i++){
        fputc(alias[i], filename);
    }
    printf("\nAlias -- done");
    fputc(' ', filename);
    for(int i = 0; i < len_pass; i++){
        fputc(password[i], filename);
    }
    printf("\nPassword -- done");
    fputc('\n', filename);
    fclose(filename);
}
//Find word in file
void FindWord(char *word){
    char line[1024];
    FILE *fp = fopen("passes.txt", "r");
    while(fgets(line, sizeof(line), fp) != NULL){
        if(strstr(line, word) != NULL){
            printf("%s", line);
        }
    }
}
//List all file
void ListAll(){
    char line[1024];
    int i = 0;
    FILE *fp = fopen("passes.txt", "r");
    while(fgets(line, sizeof(line), fp) != NULL){
        if(i > 0){
            printf("%s", line);
        }
        i++;
    }
}
