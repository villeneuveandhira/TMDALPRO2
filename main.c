/*Saya [Villeneuve Andhira Suwandhi] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    // variable declaration
    char tape[501];
    eagames apex[255];

    printf("\n");
    printf("Welcome to DBMS 'APEX LEGENDS' [by Villeneuve Andhira]\n");
    printf("v1.6.2\n\n");
    printf("--Pick your character. Round up your squad. Show everyone what Legends are made of.--\n");
    warning();
    printf("\n");

    // waiting for the next query until receive input 'stop;'
    int stop = 0;
    while (stop == 0) {
        // input string
        printf("\n");
        printf("dbms Villen> ");
        scanf(" %500[^\n]s", &tape);

        start(tape);
        int last = strlen(tape);

        if (tape[last - 1] != ';') {
            printf("#1064 error!- You have an error in your 'SQL' syntax;\n");
            warning();
            stop = 0;
        } else if ((strcmp(getcw(), "insert") == 0) || (strcmp(getcw(), "INSERT") == 0)) {
            insert_Data(tape, apex);
            stop = 0;
        } else if ((strcmp(getcw(), "delete") == 0) || (strcmp(getcw(), "DELETE") == 0)) {
            delete_Data(tape, apex);
            stop = 0;
        } else if ((strcmp(getcw(), "update") == 0) || (strcmp(getcw(), "UPDATE") == 0)) {
            update_Data(tape, apex);
            stop = 0;
        } else if ((strcmp(getcw(), "select") == 0) || (strcmp(getcw(), "SELECT") == 0)) {
            select_Data(tape, apex);
            stop = 0;
        } else if ((strcmp(getcw(), "play") == 0) || (strcmp(getcw(), "PLAY") == 0)) {
            stop = 1;
        } else {
            printf("#1064 error!- You have an error in your 'SQL' syntax;\n");
            warning();
            stop = 0;
        }
    }

    printf("\nShow 'em what you're made of in Apex Legends, a free-to-play hero shooter where contenders from across the Frontier team up to battle for glory, fame, and fortune.\nGOOD LUCK, LEGENDS..\n");

    return 0;
}