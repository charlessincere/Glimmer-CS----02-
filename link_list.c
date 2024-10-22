#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int elem; //将整数定义elem，方便以后更改数据类型

//构建结构
typedef struct  Node
{    elem  data;
     struct Node  *next;
}Node;

//初始化头节点的函数 initHead
Node* initHead (){
    Node*head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    printf("头节点创建成功 ");

    return head;
}

//头插法函数  insertHead
void  insertHead(Node *L , elem n){
     Node *p = (Node*)malloc(sizeof(Node));
     if ( p == NULL){
     printf("分配内存失败\n");
     }
     p->data = n;
     p->next = L->next;
     L->next = p;
     
}
//遍历链表
void scanList(Node *L) {
    // 检查头节点是否为空
    if (L == NULL) {
        printf("链表头节点为空\n");
        return;
    }
    
    // 检查链表是否为空（即头节点的下一个节点是否为空）
    if (L->next == NULL) {
        printf("该链表为空链表，请先插入数据\n");
        return;
    }

    Node *p = L->next; // 从头节点的下一个节点开始遍历
    while (p != NULL) {
        printf("%d ", p->data); // 打印当前节点的数据
        p = p->next; // 移动到下一个节点
    }
    printf("\n"); // 在遍历结束后换行
}

//尾插法
void insertTail(Node*L, elem n){
     Node *q = (Node*)malloc(sizeof(Node));     // 创建一个节点q来存储新数据
     if ( q == NULL){
     printf("分配内存失败\n");
     }
     q->data = n;
     q->next = NULL;

     Node *p = L;
     while(p->next !=  NULL ){                //找到尾节点//这里改进了一下，就算第一个节点为null也能插 
          p = p->next;
     }
     p->next = q;
     
}
// 中间插入
void insertMiddle(Node *L, int pos, elem n){   //pos 代表插入在哪个节点的后面
     Node *q = (Node*)malloc(sizeof(Node));   // 创建一个节点q来存储新数据
     if ( q == NULL){
     printf("分配内存失败\n");
     }

     Node *p = L->next;
     for(int i=1; i < pos ;i++ ){            //找到要插入的节点
         p = p->next;
     }
     q->data = n;
     q->next = p->next;
     p->next = q;
     

}
//删除数据
Node* deleteList(Node *L, elem pos) {
    if (L == NULL || pos < 1) {
        printf("无效的位置\n");
        return L;
    }
    Node *p = L;
    if (pos == 1) { // 如果要删除的是头节点
        Node *q = L->next;
        L = q;
        free(p);
        return L;
    }

    for (int i = 1; i < pos - 1; i++) { // 找到要删除的节点的上一个节点
        if (p->next == NULL) {
            printf("位置超出链表长度\n");
            return L;
        }
        p = p->next;
    }

    Node *q = p->next; // q 是要删除的节点
    if (q == NULL) {
        printf("位置超出链表长度\n");
        return L;
    }

    p->next = q->next; // 从链表中移除 q
   
    free(q); // 释放 q 的内存

    return L; // 返回头节点
}
//下面是题目的做答

int main(){
    Node*q = initHead (); //初始化一个头节点
//T 1 1 1
    insertTail(q, 1);  //插入data1
    insertTail(q, 1);  //插入data2
    insertTail(q, 1);  //插入data3
//H 3 2 1
    insertHead(q, 3);  //插入data1
    insertHead(q, 1);  //插入data2
    insertHead(q, 1);  //插入data3
//T 1 3 1
    insertTail(q, 1);  //插入data1
    insertTail(q, 3);  //插入data2
    insertTail(q, 1);  //插入data3
//D 9
    deleteList(q,9);   //删除第9个节点
//H 1 2 1
    insertHead(q, 1);  //插入data1
    insertHead(q, 2);  //插入data2
    insertHead(q, 1);  //插入data3
//T 2 2 2
    insertTail(q, 2);  //插入data1
    insertTail(q, 2);  //插入data2
    insertTail(q, 2);  //插入data3
//H 2 1 2
    insertHead(q, 2);  //插入data1
    insertHead(q, 1);  //插入data2
    insertHead(q, 2);  //插入data3
//D 1
    Node *s = deleteList(q,1);   //删除第1个节点
//H 2 2 1
    insertHead(s, 2);  //插入data1
    insertHead(s, 2);  //插入data2
    insertHead(s, 1);  //插入data3
//T 1 2 2
    insertTail(s, 1);  //插入data1
    insertTail(s, 2);  //插入data2
    insertTail(s, 2);  //插入data3
//D 23
    deleteList(s,23);   //删除第23个节点
//T 2 1 1
    insertTail(s, 2);  //插入data1
    insertTail(s, 1);  //插入data2
    insertTail(s, 1);  //插入data3
//T 2 2 2
    insertTail(s, 2);  //插入data1
    insertTail(s, 2);  //插入data2
    insertTail(s, 2);  //插入data3
//H 1 2 1
    insertHead(s, 1);  //插入data1
    insertHead(s, 2);  //插入data2
    insertHead(s, 1);  //插入data3
//H 1 1 1
    insertHead(s, 1);  //插入data1
    insertHead(s, 1);  //插入data2
    insertHead(s, 1);  //插入data3
    
    
    scanList(s);

    return 0;
}    
// H操作 H DATA1 DATA2 DATA3

/*
int main(){
    Node*q = initHead (); //初始化一个头节点
    insertHead(q, 3);  //插入data1
    insertHead(q, 1);  //插入data2
    insertHead(q, 1);  //插入data3

    scanList(q);
} */

//T操作：T DATA1 DATA2 DATA3

/*
int main(){
    Node*q = initHead (); //初始化一个头节点
   
    insertTail(q, 3);  //插入data1
    insertTail(q, 1);  //插入data2
    insertTail(q, 1);  //插入data3

    scanList(q);
}
*/

//D操作：D LOCATION

/*
int main(){
    Node*q = initHead (); //初始化一个头节点
    insertHead(q, 1);  //插入data1
    insertHead(q, 2);  //插入data2
    insertHead(q, 3);  //插入data3
    
    insertTail(q, 5);  //插入data1
    insertTail(q, 6);  //插入data2
    insertTail(q, 7);  //插入data3

    deleteList(q,3);  //删除第三个

    scanList(q);
}*/





