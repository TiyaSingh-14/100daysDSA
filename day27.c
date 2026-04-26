#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection node
struct Node* findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    struct Node *p1 = h1, *p2 = h2;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            p1 = p1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            p2 = p2->next;
    }

    // Traverse together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2)
            return p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *list1 = NULL, *list2 = NULL;

    // Input list1
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insert(list1, x);
    }

    // Input list2
    scanf("%d", &m);
    int arr[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);

    // Create list2 up to intersection point
    struct Node* temp1 = list1;
    struct Node* intersectionNode = NULL;

    // Find first matching value and mark intersection node
    for (int i = 0; i < m; i++) {
        temp1 = list1;
        while (temp1 != NULL) {
            if (temp1->data == arr[i]) {
                intersectionNode = temp1;
                break;
            }
            temp1 = temp1->next;
        }
        if (intersectionNode != NULL) {
            list2 = insert(list2, arr[0]);
            struct Node* temp2 = list2;
            for (int j = 1; j < i; j++) {
                temp2->next = insert(NULL, arr[j]);
                temp2 = temp2->next;
            }
            temp2->next = intersectionNode; // link to list1
            break;
        }
    }

    // If no intersection found, build normally
    if (intersectionNode == NULL) {
        for (int i = 0; i < m; i++)
            list2 = insert(list2, arr[i]);
    }

    // Find intersection
    struct Node* result = findIntersection(list1, list2);

    if (result)
        printf("%d", result->data);
    else
        printf("No Intersection");

    return 0;
}