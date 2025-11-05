/*
Name STEPHEN M KAMAMA 
Reg no CT100/G/26235/25
COURSE BSC IT
 DESCRIPTION  Append book titles to borrowed_books.txt without deleting existing records.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 256
int main(void) {
    char title[MAX_TITLE];

    printf("Enter book title (max %d chars):\n", MAX_TITLE - 1);
    if (!fgets(title, sizeof(title), stdin)) {
        fprintf(stderr, "Error reading title.\n");
        return 1;
    }

    /* Remove trailing newline if present */
    size_t len = strlen(title);
    if (len > 0 && title[len-1] == '\n') title[len-1] = '\0';

    FILE *fp = fopen("borrowed_books.txt", "a"); /* append mode */
    if (!fp) {
        perror("Unable to open borrowed_books.txt");
        return 1;
    }

    fprintf(fp, "%s\n", title);

    if (fclose(fp) != 0) {
        perror("Error closing file");
        return 1;
    }

    printf("Title successfully stored in borrowed_books.txt\n");
    return 0;
}