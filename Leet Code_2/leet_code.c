#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
int getLength(struct ListNode *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
struct ListNode *advanceList(struct ListNode *head, int steps) {
    while (steps > 0) {
        head = head->next;
        steps--;
    }
    return head;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = getLength(headA);
    int lengthB = getLength(headB);
    if (lengthA > lengthB) {
        headA = advanceList(headA, lengthA - lengthB);
    } else {
        headB = advanceList(headB, lengthB - lengthA);
    }
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}
struct ListNode *createNode(int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void freeLinkedList(struct ListNode *head) {
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode *listA = createNode(4);
    listA->next = createNode(1);
    listA->next->next = createNode(8);

    struct ListNode *listB = createNode(5);
    listB->next = createNode(6);
    listB->next->next = createNode(1);
    listB->next->next->next = listA->next->next; 
    struct ListNode *intersectionNode = getIntersectionNode(listA, listB);
    if (intersectionNode != NULL) {
        printf("Intersected at '%d'\n", intersectionNode->val);
    } else {
        printf("No intersection\n");
    }
    freeLinkedList(listA);
    freeLinkedList(listB);

    return 0;
}