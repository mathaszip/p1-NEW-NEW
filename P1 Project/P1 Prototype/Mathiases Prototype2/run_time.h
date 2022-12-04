#ifndef P1_PROTOTYPE_RUN_TIME_H
#define P1_PROTOTYPE_RUN_TIME_H

#endif //P1_PROTOTYPE_RUN_TIME_H

#include "main.h"
#include "distance.h"
#include "file_management.h"


char user_groceries[100][15];

int create_shoppinglist(FILE *list);
void print(groceries_list grocery_list[], userdata user, store_t new_stores[]);
userdata create_user();
void bsortDesc(store_t stores[], int s);
void sumOfProducts(groceries_list list[], store_t store[]);
int findSaleProducts(groceries_list list[], int store, int item);
void setOnSale(groceries_list list[]);
int random1();
int random2();
int checkShoppingList(groceries_list list[], int store, int item, int list_item);
void checkForInvalidProducts(groceries_list list[], userdata user);
void print_promotions(groceries_list list[], int store);