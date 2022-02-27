#ifndef LIB_H 
#define LIB_H

#include<stdio.h>

int CheckFile();
FILE *CreateFile();
void WritePass(FILE *filename, int len, char *to_write);
char *ReadPass();
void WriteToFile(int len_name, int len_alias, int len_pass, 
                    char *fullname, char *alias, char *password);
void FindWord(char *word);
void ListAll();
#endif