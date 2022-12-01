#ifndef P1_PROTOTYPE_MENU_H
#define P1_PROTOTYPE_MENU_H

#endif //P1_PROTOTYPE_MENU_H

#include "settings.h"
#include <stdbool.h>

typedef enum transport_options{Walk, Bicycle, Car, Bus}e_transport;

typedef struct shopping_list_struct{
    int         id;
    char*       name;
    int         price;
    bool        discount;
}t_shopping_list;

typedef struct user_profile_struct{
    char*       name;
    char*       address;
    char*       username;
    char*       password;
    double      longitude;
    double      latitude;
    double      max_distance;
    int         age;
    e_transport transport;
}t_user_profile;

//store struct

void main_menu(t_user_profile);
void initial_screen();