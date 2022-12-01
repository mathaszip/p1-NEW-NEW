#ifndef P1_PROTOTYPE_RUN_TIME_H
#define P1_PROTOTYPE_RUN_TIME_H

#endif //P1_PROTOTYPE_RUN_TIME_H

#include "main.h"
#include "distance.h"
#include "file_management.h"

char user_groceries[100][15];

int create_shoppinglist(FILE *list);
store_t * eliminate_stores(userdata user, store_t store_list[], int num);
int find_amount_of_eliminated_stores(userdata user, store_t store_list[]);
void print(groceries_list grocery_list[], userdata user, store_t new_stores[], int num, double arr[]);
userdata create_user();
int valueinarray(int product, int store_id, groceries_list groceries_list[]);
groceries_list * eliminate_groceries(userdata user, store_t store_list[], groceries_list groceries[], int num);
double * sumOfProducts(groceries_list groceriesList[], int num, userdata user);