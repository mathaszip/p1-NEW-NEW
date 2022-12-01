#ifndef P1_PROTOTYPE_MAIN_H
#define P1_PROTOTYPE_MAIN_H

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100         // Amount of products
#define MAX_STORES 5    // Amount of stores

typedef struct groceries {
    int id[MAX];
    double cost[MAX];
    char *name[MAX];
    int onSale[MAX];
} groceries_list;

typedef struct store {
    double x_coordinates, y_coordinates;
    char name[30];
    char address[30];
    double sum;
    double distance; //distance from user
} store_t;

typedef struct userdata {
    char name[30];
    double location_x;
    double location_y;
    int amount;
    int mode;
    double distance;
} userdata;

static char *product_names[] ={"Sushi", "Snow Peas", "Condensed milk", "Raspberries", "Radishes",
                               "Curry leaves", "Thyme", "Cloves", "Snapper", "Honeydew melons",
                               "Green beans", "Onion powder", "Breadfruit", "Lima beans", "Pepper",
                               "Catfish", "Lettuce", "Clams", "Cappuccino Latte", "Sage",
                               "Mussels", "Kiwi", "Cabbage", "Pumpkin seeds", "Brussels sprouts",
                               "Octopus", "Chard", "Cocoa powder", "Pineapples", "Fennel",
                               "Chocolate", "Vinegar", "Sazon", "Honey", "Pistachios",
                               "Bacon", "Shitakes", "Split peas", "Red snapper", "Wild rice",
                               "Jelly beans", "Bruschetta", "Breadcrumbs", "Tea", "Olive oil",
                               "Turnips", "Acorn squash", "Sauerkraut", "White beans", "Strawberries",
                               "Pasta", "Baking powder", "Chili sauce", "Lemon juice", "Dill",
                               "Chickpeas", "Cream", "Cantaloupes", "Dumpling", "Cauliflower",
                               "Coriander", "Rice paper", "Barley", "Apricots", "Barley sugar",
                               "Kahlua", "Maraschino cherries", "Beets", "Moo shu wrappers", "Peanuts",
                               "Prosciutto", "Macaroni", "Adobo", "Water", "Chicory",
                               "Spinach", "Trout", "Almonds", "Brown sugar", "Paprika",
                               "Pork", "Lobsters", "Havarti cheese", "Bouillon", "Grapes",
                               "Cider", "Anchovy paste", "Half-and-half", "Beef", "Swiss cheese",
                               "Rice", "Tarragon", "Romaine lettuce", "Rosemary", "Ginger ale",
                               "Canola oil", "Amaretto", "Blueberries", "Powdered sugar", "Coffee"};
static char *transport_names[] = {"On foot", "Bike", "Car"};

void run_time();