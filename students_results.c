// Read student results from results.dat (binary file)
/*
Name STEPHEN M KAMAMA 
reg no CT100/G/26235/25
Course BSC IT
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char regNo[20];
    int totalMarks;
};

int main() {
    FILE *file;
    struct Student s;

    file = fopen("results.dat", "rb");
    if (file == NULL) {
        printf("Error opening results.dat! (Make sure the file exists)\n");
        return 1;
    }

    printf("Student Name\t\tRegistration No\tTotal Marks\n");
    printf("-------------------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, file)) {
        printf("%-20s\t%-15s\t%d\n", s.name, s.regNo, s.totalMarks);
    }

    fclose(file);
    printf("\nAll records displayed successfully.\n");

    return 0;
}