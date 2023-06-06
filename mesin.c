/*Saya [Villeneuve Andhira Suwandhi] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

// procedure for starting the word machine
void start(char str[]) {
    // init
    idx = 0;
    wlen = 0;

    // if the character in the input is a space, the index continues advancing
    while (str[idx] == ' ') {
        idx++;
    }

    // if the input is a character other than 'space' and 'eop', the word is set to a global variable
    while ((str[idx] != ' ') && (str[idx] != ';')) {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // set the current word it's last index to 'null'
    cw[wlen] = '\0';
}

// procedure for clearing the machine-readable words
void reset() {
    // init and set current word to 'null'
    wlen = 0;
    cw[wlen] = '\0';
}

// function to check the end of the process (eop)
int eop(char str[]) {
    // checks if the current character is a word ending 'symbol'
    if (str[idx] == ';') {
        return 1;
    } else {
        return 0;
    }
}

// procedure for advancing the word
void inc(char str[]) {
    // init word length
    wlen = 0;

    // if the character in the input is a space, the index continues advancing
    while (str[idx] == ' ') {
        idx++;
    }

    // if the input is a character other than 'space' and 'eop', the word is set to a global variable
    while ((str[idx] != ' ') && (str[idx] != ';')) {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // set the current word it's last index to 'null'
    cw[wlen] = '\0';
}

// function to get current word length
int getlen() {
    return wlen;
}

// function to get the current word
char *getcw() {
    return cw;
}

/*=================================================================================================== CHECK/SCAN ===================================================================================================*/

// procedure for read file Characters.dat
void scan_Characters(eagames apex[], FILE *file, int *save, int n) {
    *save = 0;
    n = 0;
    fscanf(file, "%s %s %s", &apex[n].id, &apex[n].legends, &apex[n].real_name);
    if (strcmp(apex[n].id, "####") != 0) {         // if the data isn't empty,
        while (strcmp(apex[n].id, "####") != 0) {  // loop until finds the dummy file
            n++;
            fscanf(file, "%s %s %s", &apex[n].id, &apex[n].legends, &apex[n].real_name);
        }
    }
    *save = n;
    fclose(file);
}

// procedure for read file Weapons.dat
void scan_Weapons(eagames apex[], FILE *file, int *save, int n) {
    *save = 0;
    n = 0;
    fscanf(file, "%s %s %s", &apex[n].id, &apex[n].loadout, &apex[n].tier);
    if (strcmp(apex[n].id, "####") != 0) {         // if the data isn't empty,
        while (strcmp(apex[n].id, "####") != 0) {  // loop until finds the dummy file
            n++;
            fscanf(file, "%s %s %s", &apex[n].id, &apex[n].loadout, &apex[n].tier);
        }
    }
    *save = n;
    fclose(file);
}

/*=================================================================================================== DELETE ===================================================================================================*/

// procedure for deleting data
void delete_Data(char tape[], eagames apex[]) {
    // init
    int n = 0;
    int save;
    /* mark for tables */
    int characters = 0;
    int weapons = 0;
    /* mark for deleted_id */
    char no_id[255];

    // first of all, advance the current word,
    inc(tape);
    // then, compare the string :
    if (strcmp(getcw(), "legend") == 0) {                                                                                                               // if the input string is legend,
        characters = 1;                                                                                                                                 // change value of the mark for table 'legend'.
    } else if (strcmp(getcw(), "loadout") == 0) {                                                                                                       // if the input string is loadout,
        weapons = 1;                                                                                                                                    // change value of the mark for table 'loadout'.
    } else if (strcmp(getcw(), "delete") == 0 || strcmp(getcw(), "DELETE") == 0 || strcmp(getcw(), "select") == 0 || strcmp(getcw(), "SELECT") == 0) {  // if the next query are multiplied queries delete/select,
        printf("#504 - Syntax Error!\n");                                                                                                               // error.
    } else if (strcmp(getcw(), "update") == 0 || strcmp(getcw(), "UPDATE") == 0) {                                                                      // if the next query is update after the first query,
        update_Data(tape, apex);                                                                                                                        // updating data
    } else if (strcmp(getcw(), "insert") == 0 || strcmp(getcw(), "INSERT") == 0) {                                                                      // if the next query is insert after the first query,
        insert_Data(tape, apex);                                                                                                                        // inserting data
    } else {                                                                                                                                            // if the input string exclude "legend or loadout",
        printf("Table doesn't existed!\n");
        printf("It takes grit, talent, and a lot of luck to become a legend. Pick your favorite and see what their unique set of skills can do for your squad.\n");
        printf("CHOOSE from 'legend' or 'loadout'.\n");
    }
    // AFTER the inputs, if the value of the mark for table 'legend' is changed,
    if (characters == 1) {
        // read data or records from the file which will be stored/used later in the program
        FILE *fcharacter;
        fcharacter = fopen("characters.dat", "r");
        scan_Characters(apex, fcharacter, &save, n);
        n = save;
        int mark = 0;                                                                                                      // this mark is for how many data(s)/record(s) will be stored in the file
        while (eop(tape) == 0) {                                                                                           // looping until finds eop
            if ((strcmp(getcw(), "delete") != 0 || strcmp(getcw(), "DELETE") != 0) && (strcmp(getcw(), "legend") != 0)) {  // iteration 'mark' exclude the query and the table's name
                mark++;
            }
            inc(tape);  // advancing the current word on the tape
        }
        strcpy(no_id, getcw());  // store the last word before eop
        if (mark > 1) {          // this is for conditions where the query aren't fulfilled
            printf("#754 Error! - Query failed.\n");
            printf("Data is rejected!\n");
            strcpy(no_id, "gone");
        }
        // To know that data/record is deleted or not, checks again the file
        int del = 0;
        for (int i = 0; i < n; i++) {              // loop the entire file
            if (strcmp(apex[i].id, no_id) == 0) {  // if the id is same compare to the id that want to be delete
                strcpy(apex[i].id, "gone");        // change it into 'gone'
                del = 1;                           // and change the value into 1 (true) or this is a sign for something has changed.
            }
        }
        if (del != 1) {  // this message is for a FAILED delete query
            printf("Would you like to try again(?) :3\n");
        } else {  // and this is for a SUCCESS delete query
            printf("The LEGEND Deleted! ^-^\n");
        }

        // write data or records from the program into a file.
        fcharacter = fopen("characters.dat", "w");
        for (int i = 0; i < n; i++) {                                                               // loop the entire file.
            if (strcmp(apex[i].id, "gone") != 0) {                                                  // this is condition for id which is not 'gone'
                fprintf(fcharacter, "%s %s %s\n", apex[i].id, apex[i].legends, apex[i].real_name);  // write the tape (inputs)
            }
        }
        fprintf(fcharacter, "#### #### ####\n");  // the last data/records is filled with dummy data
        fclose(fcharacter);
    } else if (weapons == 1) {  // else if the value of the mark for table 'loadout' is changed,
        // read data or records from the file which will be stored/used later in the program
        FILE *fweapon;
        fweapon = fopen("weapons.dat", "r");
        scan_Weapons(apex, fweapon, &save, n);
        n = save;
        int mark = 0;                                                                                                       // this mark is for how many data(s)/record(s) will be stored in the file
        while (eop(tape) == 0) {                                                                                            // looping until finds eop
            if ((strcmp(getcw(), "delete") != 0 || strcmp(getcw(), "DELETE") != 0) && (strcmp(getcw(), "loadout") != 0)) {  // iteration 'mark' exclude the query and the table's name
                mark++;
            }
            inc(tape);  // advancing the current word on the tape
        }
        strcpy(no_id, getcw());  // store the last word before eop
        if (mark > 1) {          // this is for conditions where the query aren't fulfilled
            printf("#754 Error! - Query failed.\n");
            printf("Data is rejected!\n");
            strcpy(no_id, "gone");
        }
        // To know that data/record is deleted or not, checks again the file
        int del = 0;
        for (int i = 0; i < n; i++) {              // loop the entire file
            if (strcmp(apex[i].id, no_id) == 0) {  // if the id is same compare to the id that want to be delete
                strcpy(apex[i].id, "gone");        // change it into 'gone'
                del = 1;                           // and change the value into 1 (true) or this is a sign for something has changed.
            }
        }
        if (del != 1) {  // this message is for a FAILED delete query
            printf("Would you like to try again(?) :3\n");
        } else {  // and this is for a SUCCESS delete query
            printf("The LEGEND Deleted! ^-^\n");
        }

        // write data or records from the program into a file.
        fweapon = fopen("weapons.dat", "w");
        for (int i = 0; i < n; i++) {                                                       // loop the entire file.
            if (strcmp(apex[i].id, "gone") != 0) {                                          // this is condition for id which is not 'gone'
                fprintf(fweapon, "%s %s %s\n", apex[i].id, apex[i].loadout, apex[i].tier);  // write the tape (inputs)
            }
        }
        fprintf(fweapon, "#### #### ####\n");  // the last data/records is filled with dummy data
        fclose(fweapon);
    }
}

/*=================================================================================================== UPDATE ===================================================================================================*/

// procedure for updating data
void update_Data(char tape[], eagames apex[]) {
    // init
    int n = 0;
    int save;
    /* mark for tables */
    int characters = 0;
    int weapons = 0;
    /* mark for updates */
    char temp_id[255];
    char temp_name[255];
    char temp_value[255];

    // first of all, advance the current word,
    inc(tape);
    // then, compare the string :
    if (strcmp(getcw(), "legend") == 0) {                                                                                                               // if the input string is legend,
        characters = 1;                                                                                                                                 // change value of the mark for table 'legend'.
    } else if (strcmp(getcw(), "loadout") == 0) {                                                                                                       // if the input string is loadout,
        weapons = 1;                                                                                                                                    // change value of the mark for table 'loadout'.
    } else if (strcmp(getcw(), "delete") == 0 || strcmp(getcw(), "DELETE") == 0) {                                                                      // if the next query is delete after the first query,
        delete_Data(tape, apex);                                                                                                                        // deleting data
    } else if (strcmp(getcw(), "insert") == 0 || strcmp(getcw(), "INSERT") == 0) {                                                                      // if the next query is insert after the first query,
        insert_Data(tape, apex);                                                                                                                        // inserting data
    } else if (strcmp(getcw(), "update") == 0 || strcmp(getcw(), "UPDATE") == 0 || strcmp(getcw(), "select") == 0 || strcmp(getcw(), "SELECT") == 0) {  // if the next query are multiplied queries update/select,
        printf("#504 - Syntax Error!\n");                                                                                                               // error
    } else {                                                                                                                                            // if the input string exclude "legend or loadout",
        printf("Table doesn't existed!\n");
        printf("It takes grit, talent, and a lot of luck to become a legend. Pick your favorite and see what their unique set of skills can do for your squad.\n");
        printf("CHOOSE from 'legend' or 'loadout'.\n");
    }
    // AFTER the inputs, if the value of the mark for table 'legend' is changed,
    if (characters == 1) {
        // read data or records from the file which will be stored/used later in the program
        FILE *fcharacter;
        fcharacter = fopen("characters.dat", "r");
        scan_Characters(apex, fcharacter, &save, n);
        n = save;
        int mark = 0;                                                                                                      // this mark is for how many data(s)/record(s) will be stored in the file
        while (eop(tape) == 0) {                                                                                           // looping until finds eop
            if ((strcmp(getcw(), "update") != 0 || strcmp(getcw(), "UPDATE") != 0) && (strcmp(getcw(), "legend") != 0)) {  // iteration 'mark' exclude the query and the table's name
                if (mark == 0) {                                                                                           // also, the first mark is for id (value = 0)
                    strcpy(temp_id, getcw());                                                                              // copy string 'id'
                } else if (mark == 1) {                                                                                    // and the second mark is for data's name (either legend or loadout)
                    strcpy(temp_name, getcw());                                                                            // copy string 'name'
                }
                mark++;  // mark for the next string
            }
            inc(tape);  // advancing the current word
        }
        strcpy(temp_value, getcw());  // copy the last string before the eop
        if (mark >= 3) {              // this is for conditions where the query aren't fulfilled
            printf("#867 Error! - Query failed.\n");
            printf("Data is over the limit!\n");
            strcpy(temp_id, "gone");
        }
        // To know that data/record is updated or not, checks again the file
        int success = 0;
        if (strcmp(temp_name, "legends") == 0) {          // this is for the 'legends' changes
            for (int i = 0; i < n; i++) {                 // loop
                if (strcmp(apex[i].id, temp_id) == 0) {   // if the id is same
                    success = 1;                          // mark for successfully query
                    strcpy(apex[i].legends, temp_value);  // and copy the string
                }
            }
        } else if (strcmp(temp_name, "real_name") == 0) {  // same but this is for the 'real_name' changes
            for (int i = 0; i < n; i++) {
                if (strcmp(apex[i].id, temp_id) == 0) {
                    success = 1;
                    strcpy(apex[i].real_name, temp_value);
                }
            }
        }
        if (success == 0) {  // this message is for a FAILED update query
            printf("Would you like to try again(?) :3\n");
        } else {  // and this is for a SUCCESS update query
            printf("New LEGEND Updated! ^-^\n");
        }

        // write data or records from the program into a file.
        fcharacter = fopen("characters.dat", "w");
        for (int i = 0; i < n; i++) {                                                               // loop the entire file.
            if (strcmp(apex[i].id, "gone") != 0) {                                                  // this is condition for id which is not 'gone'
                fprintf(fcharacter, "%s %s %s\n", apex[i].id, apex[i].legends, apex[i].real_name);  // write the tape (inputs)
            }
        }
        fprintf(fcharacter, "#### #### ####\n");  // the last data/records is filled with dummy data
        fclose(fcharacter);
    } else if (weapons == 1) {
        // read data or records from the file which will be stored/used later in the program
        FILE *fweapon;
        fweapon = fopen("weapons.dat", "r");
        scan_Weapons(apex, fweapon, &save, n);
        n = save;
        int mark = 0;                                                                                                       // this mark is for how many data(s)/record(s) will be stored in the file
        while (eop(tape) == 0) {                                                                                            // looping until finds eop
            if ((strcmp(getcw(), "update") != 0 || strcmp(getcw(), "UPDATE") != 0) && (strcmp(getcw(), "loadout") != 0)) {  // iteration 'mark' exclude the query and the table's name
                if (mark == 0) {                                                                                            // also, the first mark is for id (value = 0)
                    strcpy(temp_id, getcw());                                                                               // copy string 'id'
                } else if (mark == 1) {                                                                                     // and the second mark is for data's name (either legend or loadout)
                    strcpy(temp_name, getcw());                                                                             // copy string 'name'
                }
                mark++;  // mark for the next string
            }
            inc(tape);  // advancing the current word
        }
        strcpy(temp_value, getcw());  // copy the last string before the eop
        if (mark >= 3) {              // this is for conditions where the query aren't fulfilled
            printf("#867 Error! - Query failed.\n");
            printf("Data is over the limit!\n");
            strcpy(temp_id, "gone");
        }
        // To know that data/record is updated or not, checks again the file
        int success = 0;
        if (strcmp(temp_name, "loadout") == 0) {          // this is for the 'loadout' changes
            for (int i = 0; i < n; i++) {                 // loop
                if (strcmp(apex[i].id, temp_id) == 0) {   // if the id is same
                    success = 1;                          // mark for successfully query
                    strcpy(apex[i].loadout, temp_value);  // and copy the string
                }
            }
        } else if (strcmp(temp_name, "tier") == 0) {  // same but this is for the 'tier' changes
            for (int i = 0; i < n; i++) {
                if (strcmp(apex[i].id, temp_id) == 0) {
                    success = 1;
                    strcpy(apex[i].tier, temp_value);
                }
            }
        }
        if (success == 0) {  // this message is for a FAILED update query
            printf("Would you like to try again(?) :3\n");
        } else {  // and this is for a SUCCESS update query
            printf("New LEGEND Updated! ^-^\n");
        }

        // write data or records from the program into a file.
        fweapon = fopen("weapons.dat", "w");
        for (int i = 0; i < n; i++) {                                                       // loop the entire file.
            if (strcmp(apex[i].id, "gone") != 0) {                                          // this is condition for id which is not 'gone'
                fprintf(fweapon, "%s %s %s\n", apex[i].id, apex[i].loadout, apex[i].tier);  // write the tape (inputs)
            }
        }
        fprintf(fweapon, "#### #### ####\n");  // the last data/records is filled with dummy data
        fclose(fweapon);
    }
}

/*=================================================================================================== INSERT ===================================================================================================*/

// procedure for inserting data
void insert_Data(char tape[], eagames apex[]) {
    // init
    int n = 0;
    int save;
    int duplicate = 0;
    /* mark for tables */
    int characters = 0;
    int weapons = 0;

    // first of all, advance the current word,
    inc(tape);
    // then, compare the string :
    if (strcmp(getcw(), "legend") == 0) {                                                                                                                       // if the input string is legend,
        characters = 1;                                                                                                                                         // change value of the mark for table 'legend'.
    } else if (strcmp(getcw(), "loadout") == 0) {                                                                                                               // if the input string is loadout,
        weapons = 1;                                                                                                                                            // change value of the mark for table 'loadout'.
    } else if ((strcmp(getcw(), "delete") == 0) || (strcmp(getcw(), "DELETE") == 0)) {                                                                          // if the next query is delete after the first query,
        delete_Data(tape, apex);                                                                                                                                // deleting data
    } else if ((strcmp(getcw(), "update") == 0) || (strcmp(getcw(), "UPDATE") == 0)) {                                                                          // if the next query is update after the first query,
        update_Data(tape, apex);                                                                                                                                // updating data
    } else if ((strcmp(getcw(), "insert") == 0) || (strcmp(getcw(), "INSERT") == 0) || (strcmp(getcw(), "select") == 0) || (strcmp(getcw(), "SELECT") == 0)) {  // if the next query are multiplied queries insert/select,
        printf("#504 - Syntax Error!\n");                                                                                                                       // error
    } else {                                                                                                                                                    // if the input string exclude "legend or loadout",
        printf("Table doesn't existed!\n");
        printf("It takes grit, talent, and a lot of luck to become a legend. Pick your favorite and see what their unique set of skills can do for your squad.\n");
        printf("CHOOSE from 'legend' or 'loadout'.\n");
    }
    // AFTER the inputs, if the value of the mark for table 'legend' is changed,
    if (characters == 1) {
        // read data or records from the file which will be stored/used later in the program
        FILE *fcharacter;
        fcharacter = fopen("characters.dat", "r");
        scan_Characters(apex, fcharacter, &save, n);
        n = save;
        int counter = 0;                                                                                                   // this is a counter for data
        while (eop(tape) == 0) {                                                                                           // loop until finds eop 'semicolom'
            if ((strcmp(getcw(), "insert") != 0 || strcmp(getcw(), "INSERT") != 0) && (strcmp(getcw(), "legend") != 0)) {  // iteration counter exclude the query and the table's name
                if ((strcmp(getcw(), "####") != 0) && counter == 0) {                                                      // also, the first data is for id (value = 0)
                    strcpy(apex[n].id, getcw());                                                                           // copy string 'id'
                } else if ((strcmp(getcw(), "####") != 0) && counter == 1) {                                               // and the second data is for data's name (either legend or loadout)
                    strcpy(apex[n].legends, getcw());                                                                      // copy string 'name'
                }
                counter++;  // counter for the next data
            }
            inc(tape);  // advancing the current word
        }
        strcpy(apex[n].real_name, getcw());  // copy the last string before the eop
        n++;
        // To overcome data duplication,
        if (counter == 2) {                                     // until the counter reaches value = 2, it means that all data is copied
            for (int i = 0; i < n - 1; i++) {                   // loop
                if (strcmp(apex[i].id, apex[n - 1].id) == 0) {  // but it needs to be checked if the id is already 'existed'
                    duplicate = 1;                              // the 'duplicate' counter value change
                }
            }
            if (duplicate == 0) {  // this is is a message that notify if the data is fullfilled to be stored in the file
                printf("The Apex Games welcome all comers - survive long enough, and they call you a Legend.\n");
            } else if (duplicate == 1) {  // and this is a message if there's already an existing id in the file
                printf("Apex Legends is always evolving, 'id' is already existed\n");
                strcpy(apex[n - 1].id, "gone");
            }
        } else {  // notification for manually checks the syntax or there's an error that implied in the tape
            printf("Whether you're battling on a massive floating city in Battle Royale or dueling in close-quarters Arenas. You'll need to think fast!\n");
            printf("#101 Error! - Data not inserted :v\n");
            strcpy(apex[n - 1].id, "gone");
        }

        // write data or records from the program into a file.
        fcharacter = fopen("characters.dat", "w");
        for (int i = 0; i < n; i++) {
            if (strcmp(apex[i].id, "gone") != 0) {                                                  // input data into file except duplicated or failed query
                fprintf(fcharacter, "%s %s %s\n", apex[i].id, apex[i].legends, apex[i].real_name);  // write the tape (inputs)
            }
        }
        fprintf(fcharacter, "%s %s %s\n", "####", "####", "####");  // the last data/records is filled with dummy data
        fclose(fcharacter);
    } else if (weapons == 1) {  // if the value of the mark for table 'loadout' is changed,
        // read data or records from the file which will be stored/used later in the program
        FILE *fweapon;
        fweapon = fopen("weapons.dat", "r");
        scan_Weapons(apex, fweapon, &save, n);
        n = save;
        int counter = 0;                                                                                                    // this is a counter for data
        while (eop(tape) == 0) {                                                                                            // loop until finds eop 'semicolom'
            if ((strcmp(getcw(), "insert") != 0 || strcmp(getcw(), "INSERT") != 0) && (strcmp(getcw(), "loadout") != 0)) {  // iteration counter exclude the query and the table's name
                if ((strcmp(getcw(), "####") != 0) && counter == 0) {                                                       // also, the first data is for id (value = 0)
                    strcpy(apex[n].id, getcw());                                                                            // copy string 'id'
                } else if ((strcmp(getcw(), "####") != 0) && counter == 1) {                                                // and the second data is for data's name (either legend or loadout)
                    strcpy(apex[n].loadout, getcw());                                                                       // copy string 'name'
                }
                counter++;  // counter for the next data
            }
            inc(tape);  // advancing the current word
        }
        strcpy(apex[n].tier, getcw());  // copy the last string before the eop
        n++;
        // To overcome data duplication,
        if (counter == 2) {                                     // until the counter reaches value = 2, it means that all data is copied
            for (int i = 0; i < n - 1; i++) {                   // loop
                if (strcmp(apex[i].id, apex[n - 1].id) == 0) {  // but it needs to be checked if the id is already 'existed'
                    duplicate = 1;                              // the 'duplicate' counter value change
                }
            }
            if (duplicate == 0) {  // this is is a message that notify if the data is fullfilled to be stored in the file
                printf("The Apex Games welcome all comers - survive long enough, and they call you a Legend.\n");
            } else if (duplicate == 1) {  // and this is a message if there's already an existing id in the file
                printf("Apex Legends is always evolving, 'id' is already existed\n");
                strcpy(apex[n - 1].id, "gone");
            }
        } else {  // notification for manually checks the syntax or there's an error that implied in the tape
            printf("Whether you're battling on a massive floating city in Battle Royale or dueling in close-quarters Arenas. You'll need to think fast!\n");
            printf("#101 Error! - Data not inserted :v\n");
            strcpy(apex[n - 1].id, "gone");
        }

        // write data or records from the program into a file.
        fweapon = fopen("weapons.dat", "w");
        for (int i = 0; i < n; i++) {
            if (strcmp(apex[i].id, "gone") != 0) {                                          // input data into file except duplicated or failed query
                fprintf(fweapon, "%s %s %s\n", apex[i].id, apex[i].loadout, apex[i].tier);  // write the tape (inputs)
            }
        }
        fprintf(fweapon, "%s %s %s\n", "####", "####", "####");  // the last data/records is filled with dummy data
        fclose(fweapon);
    }
}

/*=================================================================================================== SELECT ===================================================================================================*/

// function for making space
void print_Char(char s, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", s);
    }
}

// procedure for displaying data
void select_Data(char tape[], eagames apex[]) {
    // init
    int n = 0;
    /* mark for tables */
    int characters = 0;
    int weapons = 0;

    // first of all, advance the current word,
    inc(tape);
    if (strcmp(getcw(), "legend") == 0) {          // if the input string is legend,
        characters = 1;                            // change value of the mark for table 'legend'.
    } else if (strcmp(getcw(), "loadout") == 0) {  // if the input string is loadout,
        weapons = 1;                               // change value of the mark for table 'loadout'.
    } else {                                       // if the input string exclude "legend or loadout",
        printf("Table doesn't existed!\n");
        printf("It takes grit, talent, and a lot of luck to become a legend. Pick your favorite and see what their unique set of skills can do for your squad.\n");
        printf("CHOOSE from 'legend' or 'loadout'.\n");
    }
    // AFTER the select, if the value of the mark for table 'legend' is changed,
    if (characters == 1) {
        int dummy = 0;  // a counter for each data in the file
        // read data or records from the file which will be stored/used later in the program
        FILE *fcharacter;
        fcharacter = fopen("characters.dat", "r");
        fscanf(fcharacter, "%s %s %s", &apex[n].id, &apex[n].legends, &apex[n].real_name);
        if (strcmp(apex[n].id, "####") != 0) {         // if there's another id that isn't '####'
            while (strcmp(apex[n].id, "####") != 0) {  // loop as long as id is not equal to '####'
                n++;
                fscanf(fcharacter, "%s %s %s", &apex[n].id, &apex[n].legends, &apex[n].real_name);
            }
            dummy++;
        } else {  // if the data is empty
            printf("Empty Data 0-0\n");
        }
        fclose(fcharacter);

        // OUTPUT data
        if (dummy != 0) {
            // counting for the max length of the data's word
            int maxNO, maxID, maxLEGENDS, maxNAME;
            maxNO = 2;
            maxID = strlen(apex[0].id);
            maxLEGENDS = strlen(apex[0].legends);
            maxNAME = strlen(apex[0].real_name);
            for (int i = 1; i < n; i++) {          // loop entire data except the first data (starts i = 1)
                if (strlen(apex[i].id) > maxID) {  // basically if there's a word more than the max length,
                    maxID = strlen(apex[i].id);    // the max length data changes to the new word.
                }
                if (strlen(apex[i].legends) > maxLEGENDS) {
                    maxLEGENDS = strlen(apex[i].legends);
                }
                if (strlen(apex[i].real_name) > maxNAME) {
                    maxNAME = strlen(apex[i].real_name);
                }
            }

            printf("\nMEET THE LEGENDS!\n");

            // displaying data using table
            print_Char('=', maxID + maxLEGENDS + maxNAME + 19);
            printf("\n");

            // row 1
            printf("| NO");
            print_Char(' ', maxNO - 2 + 2);
            printf("| LEGENDS");
            print_Char(' ', maxLEGENDS - 7 + 2);
            printf("| REAL-NAME");
            print_Char(' ', maxNAME - 9 + 2);
            printf("| id");
            print_Char(' ', maxID - 2 + 2);
            printf("|\n");

            // make boundaries
            print_Char('-', maxID + maxLEGENDS + maxNAME + 19);
            printf("\n");

            // rows for data/records
            int num = 1;
            for (int i = 0; i < n; i++) {
                printf("| %d", num++);
                print_Char(' ', num > 10 ? maxNO - 2 + 2 : maxNO - 1 + 2);
                printf("| %s", apex[i].legends);
                print_Char(' ', maxLEGENDS - strlen(apex[i].legends) + 2);
                printf("| %s", apex[i].real_name);
                print_Char(' ', maxNAME - strlen(apex[i].real_name) + 2);
                printf("| %s", apex[i].id);
                print_Char(' ', maxID - strlen(apex[i].id) + 2);
                printf("|\n");
            }

            // boundaries
            print_Char('=', maxID + maxLEGENDS + maxNAME + 19);
            printf("\n");
        }
    } else if (weapons == 1) {
        int dummy = 0;  // a counter for each data in the file
        // read data or records from the file which will be stored/used later in the program
        FILE *fweapon;
        fweapon = fopen("weapons.dat", "r");
        fscanf(fweapon, "%s %s %s", &apex[n].id, &apex[n].loadout, &apex[n].tier);
        if (strcmp(apex[n].id, "####") != 0) {         // if there's another id that isn't '####'
            while (strcmp(apex[n].id, "####") != 0) {  // loop as long as id is not equal to '####'
                n++;
                fscanf(fweapon, "%s %s %s", &apex[n].id, &apex[n].loadout, &apex[n].tier);
            }
            dummy++;
        } else {  // if the data is empty
            printf("Empty Data 0-0\n");
        }
        fclose(fweapon);

        // OUTPUT data
        if (dummy != 0) {
            // counting for the max length of the data's word
            int maxNO, maxID, maxLOADOUT, maxTIER;
            maxNO = 2;
            maxID = strlen(apex[0].id);
            maxLOADOUT = strlen(apex[0].loadout);
            maxTIER = strlen(apex[0].tier);
            for (int i = 1; i < n; i++) {          // loop entire data except the first data (starts i = 1)
                if (strlen(apex[i].id) > maxID) {  // basically if there's a word more than the max length,
                    maxID = strlen(apex[i].id);    // the max length data changes to the new word.
                }
                if (strlen(apex[i].loadout) > maxLOADOUT) {
                    maxLOADOUT = strlen(apex[i].loadout);
                }
                if (strlen(apex[i].tier) > maxTIER) {
                    maxTIER = strlen(apex[i].tier);
                }
            }

            printf("\nMEET THE LEGENDS!\n");

            // displaying data using table
            print_Char('=', maxID + maxLOADOUT + maxTIER + 19);
            printf("\n");

            // row 1
            printf("| NO");
            print_Char(' ', maxNO - 2 + 2);
            printf("| LOADOUT");
            print_Char(' ', maxLOADOUT - 7 + 2);
            printf("| TIER");
            print_Char(' ', maxTIER - 4 + 2);
            printf("| id");
            print_Char(' ', maxID - 2 + 2);
            printf("|\n");

            // make boundaries
            print_Char('-', maxID + maxLOADOUT + maxTIER + 19);
            printf("\n");

            // rows for data/records
            int num = 1;
            for (int i = 0; i < n; i++) {
                printf("| %d", num++);
                print_Char(' ', num > 10 ? maxNO - 2 + 2 : maxNO - 1 + 2);
                printf("| %s", apex[i].loadout);
                print_Char(' ', maxLOADOUT - strlen(apex[i].loadout) + 2);
                printf("| %s", apex[i].tier);
                print_Char(' ', maxTIER - strlen(apex[i].tier) + 2);
                printf("| %s", apex[i].id);
                print_Char(' ', maxID - strlen(apex[i].id) + 2);
                printf("|\n");
            }

            // boundaries
            print_Char('=', maxID + maxLOADOUT + maxTIER + 19);
            printf("\n");
        }
    }
}

/*=================================================================================================== HELP ===================================================================================================*/

// procedure for guidance
void warning() {
    printf("WARNING!!\nchoose between INSERT/UPDATE/DELETE/SELECT [table name], and don't forget add the semicolom at the end ';'\n");
    printf("-> INSERT [legend/loadout] [id] [name code/weapon] [real_name/tiers] ;\n");
    printf("-> UPDATE [legend/loadout] [id] [legends/real_name || loadout/tier] [changes] ;\n");
    printf("-> DELETE [legend/loadout] [id] ;\n");
    printf("-> SELECT [legend/loadout] ;\n");
    printf("-> PLAY   for exit the program\n");
}