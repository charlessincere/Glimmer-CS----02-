#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在头部插入节点
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // 如果链表为空，新节点既是头节点也是尾节点
        *head = newNode;
        newNode->next = *head; // 形成环
    } else {
        // 新节点的 next 指向原来的头节点
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}
// 在尾部插入节点
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // 形成环
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
// 在指定位置 pos 插入节点
void insertAtPosition(Node** head, int data, int pos) {
    if (*head == NULL) {
        printf("List is empty. Cannot insert at position.\n");
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;

    // 如果插入位置是 1，即头部插入
    if (pos == 1) {
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }

    int currentPos = 1;
    // 寻找要插入位置的前一个节点
    while (currentPos < pos - 1 && temp->next != *head) {
        temp = temp->next;
        currentPos++;
    }

    // 如果 pos 大于链表长度 + 1，则将新节点插入到尾部
    if (currentPos == pos - 1 && temp->next != *head) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        // 否则，插入到中间某个位置
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}
// 删除具有特定值的节点
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node *temp = *head, *prev = NULL;
    if (temp->data == key) {
        // 如果头节点就是要删除的节点
        while (temp->next != *head) {
            temp = temp->next;
        }
        // 让尾节点指向新的头节点
        temp->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }

    while (temp->data != key && temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    // 没找到 key
    if (temp->data != key) return;

    prev->next = temp->next;
    if (temp->next == *head) {
        // 如果删除的是尾节点
        while ((*head)->next != temp) {
            (*head) = (*head)->next;
        }
        (*head)->next = temp->next;
    }
    free(temp);
}

// 遍历链表
void scanList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node *current = head->next; // 从头节点的下一个节点开始遍历
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head->next);
    printf("\n");
}

// 释放链表内存
void freeList(Node* head) {
    if (head == NULL) return;
    Node *temp;
    do {
        temp = head->next;
        if (temp == head) {
            free(head);
            head = NULL;
            break;
        }
        head->next = temp->next;
        free(temp);
        head = head->next;
    } while (temp != head);
}

// 主函数，用于测试环状链表
int main() {
    Node *head = NULL; // 初始化为空链表

    // 在头部插入数据
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    // 遍历链表
    printf("Linked list: ");
    scanList(head);

    // 删除节点
    deleteNode(&head, 20);

    // 再次遍历链表
    printf("Linked list after deletion: ");
    scanList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}