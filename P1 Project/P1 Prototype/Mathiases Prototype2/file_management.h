//
// Created by Mathias on 21-11-2022.
//

#ifndef P1_PROTOTYPE_FILE_MANAGEMENT_H
#define P1_PROTOTYPE_FILE_MANAGEMENT_H

#endif //P1_PROTOTYPE_FILE_MANAGEMENT_H


groceries_list * open_files();
store_t * open_stores(userdata session);
groceries_list collect_list_of_groceries (FILE *fp);
store_t collect_store_info(FILE *fp);