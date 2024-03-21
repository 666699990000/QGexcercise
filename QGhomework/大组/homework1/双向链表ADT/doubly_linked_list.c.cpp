#include"doubly_linked_list.h"

DoublyLinkedList* createDoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroyDoublyLinkedList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void addNode(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
    list->size++;
}

void deleteNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            if (current == list->head && current == list->tail) {
                list->head = NULL;
                list->tail = NULL;
            }
            else if (current == list->head) {
                list->head = current->next;
                list->head->prev = NULL;
            }
            else if (current == list->tail) {
                list->tail = current->prev;
                list->tail->next = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
}

void updateNode(DoublyLinkedList* list, int oldData, int newData) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
}

Node* findNode(DoublyLinkedList* list, int data) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printDoublyLinkedList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printMenu() {
    printf("1. Add Node\n");
    printf("2. Delete Node\n");
    printf("3. Update Node\n");
    printf("4. Find Node\n");
    printf("5. Print List\n");
    printf("6. Exit\n");
}

int main() {
    DoublyLinkedList* list = createDoublyLinkedList();
    int choice;
    int data, oldData, newData;
    Node* node; // ÒÆµ½ÍâÃæ

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to add: ");
            scanf_s("%d", &data);
            addNode(list, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf_s("%d", &data);
            deleteNode(list, data);
            break;
        case 3:
            printf("Enter data to update: ");
            scanf_s("%d", &oldData);
            printf("Enter new data: ");
            scanf_s("%d", &newData);
            updateNode(list, oldData, newData);
            break;
        case 4:
            printf("Enter data to find: ");
            scanf_s("%d", &data);
            node = findNode(list, data);
            if (node != NULL) {
                printf("Node found: %d\n", node->data);
            }
            else {
                printf("Node not found.\n");
            }
            break;
        case 5:
            printf("Current list: ");
            printDoublyLinkedList(list);
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 6);

    destroyDoublyLinkedList(list);
    return 0;

}
