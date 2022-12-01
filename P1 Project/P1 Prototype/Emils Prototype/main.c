#include <stdio.h>
#include "menu.h"

int main() {
    //initial_screen();

    char str1[10], str2[10], str3[10];
    int year;
    FILE * fp;

    fp = fopen ("Test.txt", "w+");
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
    fputs("This is a 123", fp);

    rewind(fp);

    fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

    printf("Read String1 |%s|\n", str1 );
    printf("Read String2 |%s|\n", str2 );
    printf("Read String3 |%s|\n", str3 );
    printf("Read Integer |%d|\n", year );



    fclose(fp);

    return 0;
}

