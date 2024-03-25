#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 在链表末尾插入节点
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 打印链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 合并两个有序链表
Node* merge(Node* a, Node* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    
    Node* result = NULL;
    
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    
    return result;
}

// 使用归并排序对链表进行排序
void mergeSort(Node** head) {
    Node* current = *head;
    Node* a;
    Node* b;
    
    if (current == NULL || current->next == NULL) {
        return;
    }
    
    split(current, &a, &b);
    
    mergeSort(&a);
    mergeSort(&b);
    
    *head = merge(a, b);
}

// 分割链表
void split(Node* source, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    
    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
    } else {
        slow = source;
        fast = source->next;
        
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

int main() {
    Node* head = NULL;
    
    // 插入节点
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 8);
    insert(&head, 1);
    insert(&head, 6);
    
    printf("原始链表：");
    printList(head);
    
    // 对链表进行排序
    mergeSort(&head);
    
    printf("排序后链表：");
    printList(head);
    
    return 0;
}