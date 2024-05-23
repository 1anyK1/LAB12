#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* nextList;
    int data;              
    struct Node* nextNode;
} Node;

Node* addNode(Node* head, int data, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {
        (*tail)->nextNode = newNode;
        *tail = newNode; 
        return head;
    }
}
Node* addNodeS(Node* head, int data, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {
        //newNode->nextList=(*tail);
        newNode->nextList=*tail;
        *tail = newNode; 
        return head;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->nextNode;
        free(temp);
    }
}

int main() {
    Node* firstList = NULL; 
    Node* secondList = NULL; 
    Node *firstTail = NULL, *secondTail = NULL;
    Node* S = NULL;
    int data, count = 0;

    printf("Введите последовательность чисел (0 для окончания ввода)\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;

        count++;
        if (count % 2 == 1) {
            firstList = addNode(firstList, data, &firstTail);
            if (S == NULL) {S = firstList;firstTail->nextList=NULL;}
        } else {
            secondList = addNodeS(secondList, data, &secondTail);
            if (count==2) secondTail->nextList=firstList;
            else firstTail->nextList=secondTail;
            //secondTail->nextNode=NULL;
        }
    }

    printf("Первый список:\n");
    printList(firstList);
    
    printf("Второй список:\n");
    printList(secondList);

    printf("Press 'a' to go left and 'd' to go right. Any other key to exit\n");
    Node *lst_ptr = firstList;
    Node* Snd_ptr = secondList;
    char c;
    getchar();
    while(1) {
        char key = 'f';

        printf("Value: %d; Addr prev: %p next: %p\n", lst_ptr->data, lst_ptr->nextList, lst_ptr->nextNode);
        scanf("%c%*c", &key);
        

        printf("Key entered: '%c'\n", key);
        if (key == 'a') {
            if (lst_ptr->nextList)
                lst_ptr = lst_ptr->nextList;
            else 
                printf("Can't go here: prev is NULL\n");
            
        } else if(key == 'd') {
            if (lst_ptr->nextNode)
                lst_ptr = lst_ptr->nextNode;
            else
                printf("Can't go here: next is NULL\n");

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    freeList(firstList);
    freeList(secondList);

    return 0;
}
