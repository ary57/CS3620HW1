#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sumCols(char* fileName);

int main(int argc, char **argv){
    char* fileName = argv[1];
    sumCols(fileName);
    return 0; 
}


void sumCols(char* fileName){
    FILE *the_file = fopen(fileName, "r");
    if(the_file == NULL){
        perror("Unable to open the file.");
        exit(1);
    }

    FILE *newFile = fopen("problem4Result.csv", "w+");

    char line[200];

    while(fgets(line, sizeof(line), the_file)){
        char *token = strtok(line, ",");
        int a = atoi(token);
        int b = atoi(strtok(NULL, ","));
        int c = a+b;
        fprintf(newFile, "%d,%d,%d\n",a,b,c);
    }
    fclose(newFile); 
    fclose(the_file);

}