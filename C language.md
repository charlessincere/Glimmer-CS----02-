## 函数
这里特别提一下，函数不要返回内部变量的指针。

``` c
int* f(void) {
  int i;
  // ...
  return &i;
}
```

上面示例中，函数返回内部变量`i`的指针，这种写法是错的。因为当函数结束运行时，内部变量就消失了，这时指向内部变量`i`的内存地址就是无效的，再去使用这个地址是非常危险的。

自增自减
![[Pasted image 20241017204152.png]]

优先级
![[Pasted image 20241017205241.png]]
## continue语句
![[Pasted image 20241018113544.png]]
## 数组
![[Pasted image 20241018121729.png]]
## 字符串

输入字符串
strcpy
同时需要调用头文件
``` c
#include<string.h>
char *s;
s = (char*)malloc(10);
strcpy(s, "Hello");
//`strcpy` 函数将字符串 `"Hello"` 复制到 `s` 指向的内存位置，并且返回 `s` 的指针。由于 `s` 已经指向了分配的内存，所以不需要再次赋值，直接使用 `s` 即可。`printf("%s\n", s);` 这行代码会输出复制后的字符串 `"Hello"`。
```
## 编写循环数组
``` c
int a = {1,1,1,2,2};
for (int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++)
 {
     printf ("%d\n", a[i]);

/*遍历数组*/
 }
```
## 指针
  ==对指针加一个整数，实际上是加上这个整数*4（也就是乘上对应字节数）==
``` c
int a = 5 ;
int *p = & a; //申明变量用到的*
printf("%d\n", *p"); // 解引用指针，对指针指向的位置进行操作，这里时最指向位置的读取
	   *p = 100; //将100赋值到p指针指向的位置
	   
```
 **除了在申明变量时用到的’*‘号   其他都是解引用指针 
 ####   ==指针与数组==
``` c
int a[]={1, 2, 3,4};
int *p ;
p = a  //把数组地址赋值给指针时可以不写&，取的是首地址
```
## 结构体

==结构体的初始化和调用==
``` c
struct point{
    int = x;
    int = y;
};//声明point结构的变量p


struct  结构体 变量名；
struct  point p; //声明point结构的变量p

p.x= 10;
p.y= 20;//为point结构变量p中的x， y赋值
```
==编写一个赋值point结构体的函数==
``` c
struct point {
    int x;
    int y;
}
struct point creatpoint(int a , int b){
   struct point p;
   p.x = a;
   p.y = b;
   return p
}
```
==编写了结构体要带struct==
==日常在使用结构体时时常是指针==
struct point *p

``` c
struct point *p
   (*p).x = 1;/ 也可以写成 p->x =1;
   都代表p指针指向的结构体中的x   ```
## typedf 类型定义 
数据结构中常用类型，申明之后在用自己的结构体变量中不用写struct

``` c
typedef 数据类型 别名
typedef struct {
  数据类型 变量名；
  数据类型 变量名；
}别名； /反正也要起别名，所以没必要起原名
```
## 动态内存分配
==分类==
1. 静态内存
2. 栈内存
3. 堆内存
==堆内存分配==
1. 使用malloc函数分配内存
    void * malloc(size_t)
   成功分配返回内存，失败返回空指针
2. 使用分配的内存
3. 使用free释放内存
``` c
#include<stdio.h>
#include<stdlib.h>
int main(){
   int *p;
   p = (int*)malloc(sizeof(int));//这里用int类型是为了兼容32位和64位操作系统，不同操作系统的位数不一样
   *p = 15;
   printf("%d\n", *p);
   free(p);
   return 0; 
}
```
==写大代码一定要记得想什么时候释放内存==
## 线性表
==线性表是由n个相同类型元素组成的有限序列==

###顺序表的实现
``` c
#define MAXSIZE 100 //定义为maxsize方便以后更改最大值，因为这个函数可能会被调用很多次
typedef int elemtype; 
/定义为elemtype方便以后改变函数变量类型/
typedef struct{
   elemtype  data[MAXSIZE];
   int length;
}seqList;
```
## 链表
``` c
#include<stdio.h>

#include<string.h>

#include<stdlib.h>

  

typedef int elem; //将整数定义elem，方便以后更改数据类型

  

//构建结构

typedef struct  Node

{    elem  data;

     struct Node  *next;

}Node;

  

//初始化头节点的函数 initHead

Node* initHead (){

    Node*head = (Node*)malloc(sizeof(Node));

    head->data = 1;

    head->next = NULL;

    printf("头节点创建成功 ");

  

    return head;

}

  

//头插法函数  insertHead

void  insertHead(Node *L , elem n){

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

     Node *q = (Node*)malloc(sizeof(Node));     // 创建一个节点q来存储新数据

     if ( q == NULL){

     printf("分配内存失败\n");

     }

     q->data = n;

     q->next = NULL;

  

     Node *p = L;

     while(p->next !=  NULL ){                //找到尾节点//这里改进了一下，就算第一个节点为null也能插

          p = p->next;

     }

     p->next = q;

}

// 中间插入

void insertMiddle(Node *L, int pos, elem n){   //pos 代表插入在哪个节点的后面

     Node *q = (Node*)malloc(sizeof(Node));   // 创建一个节点q来存储新数据

     if ( q == NULL){

     printf("分配内存失败\n");

     }

  

     Node *p = L->next;

     for(int i=1; i < pos ;i++ ){            //找到要插入的节点

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

    insertTail(q, 1);  //插入data1

    insertTail(q, 1);  //插入data2

    insertTail(q, 1);  //插入data3

//H 3 2 1

    insertHead(q, 3);  //插入data1

    insertHead(q, 1);  //插入data2

    insertHead(q, 1);  //插入data3

//T 1 3 1

    insertTail(q, 1);  //插入data1

    insertTail(q, 3);  //插入data2

    insertTail(q, 1);  //插入data3

//D 9

    deleteList(q,9);   //删除第9个节点

//H 1 2 1

    insertHead(q, 1);  //插入data1

    insertHead(q, 2);  //插入data2

    insertHead(q, 1);  //插入data3

//T 2 2 2

    insertTail(q, 2);  //插入data1

    insertTail(q, 2);  //插入data2

    insertTail(q, 2);  //插入data3

//H 2 1 2

    insertHead(q, 2);  //插入data1

    insertHead(q, 1);  //插入data2

    insertHead(q, 2);  //插入data3

//D 1

    Node *s = deleteList(q,1);   //删除第1个节点

//H 2 2 1

    insertHead(s, 2);  //插入data1

    insertHead(s, 2);  //插入data2

    insertHead(s, 1);  //插入data3

//T 1 2 2

    insertTail(s, 1);  //插入data1

    insertTail(s, 2);  //插入data2

    insertTail(s, 2);  //插入data3

//D 23

    deleteList(s,23);   //删除第23个节点

//T 2 1 1

    insertTail(s, 2);  //插入data1

    insertTail(s, 1);  //插入data2

    insertTail(s, 1);  //插入data3

//T 2 2 2

    insertTail(s, 2);  //插入data1

    insertTail(s, 2);  //插入data2

    insertTail(s, 2);  //插入data3

//H 1 2 1

    insertHead(s, 1);  //插入data1

    insertHead(s, 2);  //插入data2

    insertHead(s, 1);  //插入data3

//H 1 1 1

    insertHead(s, 1);  //插入data1

    insertHead(s, 1);  //插入data2

    insertHead(s, 1);  //插入data3

    scanList(s);

  

    return 0;

}    

// H操作 H DATA1 DATA2 DATA3

  

/*

int main(){

    Node*q = initHead (); //初始化一个头节点

    insertHead(q, 3);  //插入data1

    insertHead(q, 1);  //插入data2

    insertHead(q, 1);  //插入data3

  

    scanList(q);

} */

  

//T操作：T DATA1 DATA2 DATA3

  

/*

int main(){

    Node*q = initHead (); //初始化一个头节点

    insertTail(q, 3);  //插入data1

    insertTail(q, 1);  //插入data2

    insertTail(q, 1);  //插入data3

  

    scanList(q);

}

*/

  

//D操作：D LOCATION

  

/*

int main(){

    Node*q = initHead (); //初始化一个头节点

    insertHead(q, 1);  //插入data1

    insertHead(q, 2);  //插入data2

    insertHead(q, 3);  //插入data3

    insertTail(q, 5);  //插入data1

    insertTail(q, 6);  //插入data2

    insertTail(q, 7);  //插入data3

  

    deleteList(q,3);  //删除第三个

  

    scanList(q);

}*/

  

//  c操作 环形链表的实现
```