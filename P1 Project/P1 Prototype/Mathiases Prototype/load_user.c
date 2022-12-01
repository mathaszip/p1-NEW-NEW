#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 100
#define MAX_STORES 5
#define pi 3.14159265358979323846

typedef struct groceries {
    int id[MAX];
    double cost[MAX];
    char *name[MAX];
} groceries_list;

typedef struct store {
    double x_coordinates, y_coordinates;
    char name[30];
    char address[30];
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

char userproducts[100][15];

groceries_list make_groceries (FILE *fp);
store_t make_stores(FILE *fp);
void print_groceries(groceries_list grocery_list[], store_t store_list[]);
groceries_list * open_files();
store_t * open_stores();
userdata create_user();
int create_shoppinglist(FILE *list);
void print(groceries_list grocery_list[], userdata user, store_t store[], store_t new_stores[], int num);
double distance(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double);
double rad2deg(double);
store_t * eliminate_stores(userdata user, store_t store_list[], int num);
int find_amount_of_eliminated_stores(userdata user, store_t store_list[]);

int main(void) {
    groceries_list final_list[MAX_STORES];
    groceries_list *ptr = final_list;

    store_t store_list[MAX_STORES];
    store_t *ptr1 = store_list;

    store_t new_list[MAX_STORES];
    store_t *ptr2 = new_list;

    ptr = open_files();
    ptr1 = open_stores();

    userdata user = create_user();
    int numberOfStores = find_amount_of_eliminated_stores(user, ptr1);
    ptr2 = eliminate_stores(user, ptr1, numberOfStores);

    print(ptr, user, ptr1, ptr2, numberOfStores);
}

int find_amount_of_eliminated_stores(userdata user, store_t store_list[]) {
    int i, k = 0;
    for (i = 0; i < MAX_STORES; i++) {
        if (distance(user.location_x, user.location_y, store_list[i].x_coordinates, store_list[i].y_coordinates) < user.distance) {
            k++;
        }
    }
    return k;
}

store_t * eliminate_stores(userdata user, store_t store_list[], int num) {
    int i, k = 0;

    store_t* lists2 = malloc(num * sizeof *lists2);
    for (i = 0; i < MAX_STORES; i++) {
        if (distance(user.location_x, user.location_y, store_list[i].x_coordinates, store_list[i].y_coordinates) < user.distance) {
            lists2[k] = store_list[i];
            k++;
        }
    }
return lists2;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    }
    else {
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist); //returns the arc cosine (inverse cosine) of a number in radians.
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        dist = dist * 1.609344;
    }
    return dist;
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts decimal degrees to radians             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double deg) {
    return (deg * pi / 180);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts radians to decimal degrees             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

void print(groceries_list grocery_list[], userdata user, store_t store[], store_t new_stores[], int num) {
    printf("\nYour name is set to: %s "
           "\nYour location is: %lf %lf"
           "\nYour preferred mode of transport is %s and your max travel distance is set to %lf km."
           "\nYou have %d item(s) in your shopping list:", user.name, user.location_x, user.location_y, transport_names[user.mode - 1], user.distance, user.amount);

    for (int i = 0; i < user.amount; i++) {
        printf("\n%s", userproducts[i]);
    }

    printf("\nStores found within %lf km from your location:", user.distance);
    for (int i = 0; i < num; i++) {
        printf("\nThe store %s has been found and is located %lf km away from you,\nand has these products and prices:", new_stores[i].name, distance(user.location_x, user.location_y, new_stores[i].x_coordinates, new_stores[i].y_coordinates));

        for (int k = 0; k < MAX; k++) {
            printf("\nProduct %d:\nName: %s \nPrice: %lf\n", grocery_list[i].id[k], grocery_list[i].name[k], grocery_list[i].cost[k]);
        }
    }
}

userdata create_user() {
    userdata session;
    printf("\nEnter name please: ");
    scanf(" %s", session.name);
    printf("\nPlease enter your location in a coordinate format (latitude / longitude): ");
    scanf(" %lf %lf", &session.location_x, &session.location_y);
    printf("\nPlease enter the number of your preferred mode of transport:\n(1) On foot\n(2) Bike\n(3) Car\n");
    scanf(" %d", &session.mode);
    printf("\nHow far are you willing to travel %s in kilometers", transport_names[session.mode - 1]);
    scanf(" %lf", &session.distance);

    char filename[30] = "shoppinglist.txt";
    FILE *myFile;

    myFile = fopen(filename, "r");
    session.amount = create_shoppinglist(myFile);

    return session;
}

/**
 * Name:
 * Description:
 * @param list
 * @return
 */
int create_shoppinglist(FILE *list) {
    int i = 0;

    if (list == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    } else {
        while (!feof(list)) {
            fscanf(list, " %s", userproducts[i]);
            i++;
        }
    }
    return i;
}

store_t * open_stores() {
    char filename1[20];
    FILE *myFile1;
    store_t* lists1 = malloc(MAX_STORES * sizeof *lists1);

    for (int k = 0; k < MAX_STORES; k++) {
        sprintf(filename1, "%d_info.txt", k);
        myFile1 = fopen(filename1, "r");
        lists1[k] = make_stores(myFile1);
        fclose(myFile1);
    }

    return lists1;
}

groceries_list * open_files() {
    char filename[20];
    FILE *myFile;
    groceries_list* lists = malloc(MAX_STORES * sizeof *lists);

    for (int i = 0; i < MAX_STORES; i++) {
        sprintf(filename, "%d_groceries.txt", i);
        myFile = fopen(filename, "r");
        lists[i] = make_groceries(myFile);
        fclose(myFile);
    }
    return lists;
}

void print_groceries(groceries_list grocery_list[], store_t store_list[]) {

    for (int i = 0; i < MAX_STORES; i++) {
        printf("\nThe store %s has these products:\n", store_list[i].name);
        for (int k = 0; k < MAX; k++) {
            printf("\nProduct %d:\nName: %s \nPrice: %lf\n", grocery_list[i].id[k], grocery_list[i].name[k], grocery_list[i].cost[k]);
        }
    }
}

groceries_list make_groceries (FILE *fp) {
    groceries_list list;

    if (fp == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    } else {
        for (int i = 0; i < MAX; i++) {
            fscanf(fp, " %lf", &list.cost[i]);
            list.id[i] = i;
            list.name[i] = product_names[i];
        }
    }
    return list;
}

store_t make_stores(FILE *fp1) {
    store_t list1;

    if (fp1 == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    else {
        fscanf(fp1, "%s %s %lf %lf", list1.name, list1.address, &list1.x_coordinates, &list1.y_coordinates);
    }
    return list1;
}