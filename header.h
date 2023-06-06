/*Saya [Villeneuve Andhira Suwandhi] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char id[255];         // this contains character id
    char legends[255];    // ------------- character name code
    char real_name[255];  // ------------- the character's real name
    char loadout[255];    // ------------- a list of weapons
    char tier[255];       // ------------- ----------------- tier list
} eagames;                // the name of the data struct

// global variable declaration
int idx,      // index of the last character of the word
    wlen;     // word length
char cw[52];  // current word

// procedure or function declaration
/*word machine*/
void start(char str[]);
void reset();
int eop(char str[]);
void inc(char str[]);
int getlen();
char *getcw();

/*queries*/
void scan_Characters(eagames apex[], FILE *file, int *save, int x);
void scan_Weapons(eagames apex[], FILE *file, int *save, int x);
void insert_Data(char tape[], eagames apex[]);
void delete_Data(char tape[], eagames apex[]);
void update_Data(char tape[], eagames apex[]);
void print_Char(char s, int n);
void select_Data(char tape[], eagames apex[]);

/*if syntax error(guidance)*/
void warning();