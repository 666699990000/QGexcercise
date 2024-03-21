#pragma once
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

#endif
