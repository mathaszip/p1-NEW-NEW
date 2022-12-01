#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "utilities.h"

int size_of_file(FILE *file){
    int size = 0;

    if (file == NULL){
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)){

    }

}