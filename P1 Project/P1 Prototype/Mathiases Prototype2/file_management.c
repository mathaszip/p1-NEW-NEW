#include "main.h"
#include "distance.h"
#include "file_management.h"

store_t * open_stores(userdata session) {
    char filename1[20];
    FILE *myFile1;
    store_t* arrayOfStores = malloc(MAX_STORES * sizeof *arrayOfStores);

    for (int k = 0; k < MAX_STORES; k++) {
        sprintf(filename1, "%d_info.txt", k);
        myFile1 = fopen(filename1, "r");
        arrayOfStores[k] = collect_store_info(myFile1);
        arrayOfStores[k].distance = distance(session.location_x, session.location_y,
                                             arrayOfStores[k].x_coordinates, arrayOfStores[k].y_coordinates);
        fclose(myFile1);
    }

    return arrayOfStores;
}

groceries_list * open_files() {
    char filename[20];
    FILE *myFile;
    groceries_list* arrayOfGroceryLists = malloc(MAX_STORES * sizeof *arrayOfGroceryLists);

    for (int i = 0; i < MAX_STORES; i++) {
        sprintf(filename, "%d_groceries.txt", i);
        myFile = fopen(filename, "r");
        arrayOfGroceryLists[i] = collect_list_of_groceries(myFile);
        fclose(myFile);
    }
    return arrayOfGroceryLists;
}

groceries_list collect_list_of_groceries(FILE *fp) {
    groceries_list groceriesList;

    if (fp == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    } else {
        for (int i = 0; i < MAX; i++) {
            fscanf(fp, " %lf", &groceriesList.cost[i]);
            groceriesList.id[i] = i;
            groceriesList.name[i] = product_names[i];
        }
    }
    return groceriesList;
}

store_t collect_store_info(FILE *fp1) {
    store_t store_info;

    if (fp1 == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    else {
        fscanf(fp1, "%s %s %lf %lf", store_info.name, store_info.address, &store_info.x_coordinates, &store_info.y_coordinates);
    }
    return store_info;
}