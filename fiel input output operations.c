#include <stdio.h>
#include <stdlib.h>

void createAndWriteFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    fprintf(fp, "This is the initial content written to the file.\n");
    fclose(fp);
    printf("File created and written successfully.\n");
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a"); 
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }
    fprintf(fp, "This is the appended content.\n");
    fclose(fp);
    printf("Content appended successfully.\n");
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char ch;
    if (fp == NULL) {
        printf("Error reading file!\n");
        return;
    }
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    const char *filename = "codtech_task1.txt";

    createAndWriteFile(filename);   
    appendToFile(filename);         
    readFile(filename);     

    return 0;
}