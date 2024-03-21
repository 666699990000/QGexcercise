#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LEN sizeof(Slist)

typedef struct Single_Linklist {
	int num;
	struct Single_Linklist* next;
}Slist;

void menu();
int choice();
Slist* create();
void print(Slist* head);
Slist* insert(Slist* head, int pos, int num);
Slist* deletelist(Slist* head, int pos);
Slist* revise(Slist* head, int pos, int num);
int search(Slist* head, int num);