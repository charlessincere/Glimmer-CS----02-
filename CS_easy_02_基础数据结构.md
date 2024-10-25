### 知识积累  [摘自]([1.3   小结 - Hello 算法 (hello-algo.com)](https://www.hello-algo.com/chapter_introduction/summary/))hello,算法
- 链表相较于数组，在数据添加和删除操作上更加便捷，但牺牲了数据访问速度。
- 图相较于链表，提供了更丰富的逻辑信息，但需要占用更大的内存空间
- 算法是在有限时间内解决特定问题的一组指令或操作步骤，而数据结构是计算机中组织和存储数据的方式。
-  数据结构与算法紧密相连。数据结构是算法的基石，而算法是数据结构发挥作用的舞台。
  - 我们可以将数据结构与算法类比为拼装积木，积木代表数据，积木的形状和连接方式等代表数据结构，拼装积木的步骤则对应算法。
  - 复杂度分析能够体现算法运行所需的时间和空间资源与输入数据大小之间的关系。**它描述了随着输入数据大小的增加，算法执行所需时间和空间的增长趋势**
     ** 迭代 **
     （iteration）是一种重复执行某个任务的控制结构。在迭代中，程序会在满足一定的条件下重复执行某段代码，直到这个条件不再满足。
``` c
/* for 循环 */
int forLoop(int n) {
    int res = 0;
    // 循环求和 1, 2, ..., n-1, n
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}
```

-  `for` 循环是最常见的迭代形式之一，**适合在预先知道迭代次数时使用**
 ** 递归（recursion）**
  是一种算法策略，通过函数调用自身来解决问题。它主要包含两个阶段
  1. **递**：程序不断深入地调用自身，通常传入更小或更简化的参数，直到达到“终止条件”。
2. **归**：触发“终止条件”后，程序从最深层的递归函数开始逐层返回，汇聚每一层的结果。

而从实现的角度看，递归代码主要包含三个要素。

1. **终止条件**：用于决定什么时候由“递”转“归”。
2. **递归调用**：对应“递”，函数调用自身，通常输入更小或更简化的参数。
3. **返回结果**：对应“归”，将当前递归层级的结果返回至上一层。
#  **指针**
 - 为了防止读写未初始化的指针变量，可以养成习惯，将未初始化的指针变量设为`NULL`。

``` c
int* p = NULL;
```

`NULL`在 C 语言中是一个常量，表示地址为`0`的内存空间，这个地址是无法使用的，读写该地址会报错。
# **数组**
- 注意，如果引用不存在的数组成员（即越界访问数组），并不会报错，所以必须非常小心。

``` c
int scores[100];

scores[100] = 51;
```

上面示例中，数组`scores`只有100个成员，因此`scores[100]`这个位置是不存在的。但是，引用这个位置并不会报错，会正常运行，使得紧跟在`scores`后面的那块内存区域被赋值，而那实际上是其他变量的区域，因此不知不觉就更改了其他变量的值。这很容易引发错误，而且难以发现。


#   问题回答 
 ==问题解答==
1. 什么是随机存取？这个性质属于哪种线性表的特征？

  随机取存  生成一个随机序列，根据索引进行访问元素，可以遍历任何元素
  **数组**
   
3. 什么是**指针**？如何在C语言中定义指针变量？指针变量的大小是固定的吗？

**回答1** ：指针用于储存另一个变量内存地址的特殊变量 

**回答2** ：定义指针变量
 ```c
 int *ip;
```
**回答3** ：指针变量大小的值是不固定的，它取决于操作系统和编译器的实现，架构不同指针大小也不同，数值大小可能因为读取的地址不同而不同，但是对于同一个架构，指针变量的内存大小是固定的，（*学长出题指代不明！！！*）
3.  你能为不同的数据结构设想出适用的具体情况吗？

** 数组** 、
**随机访问**  **排序和搜索**  **查找表**  **机器学习**   **数据结构实现**
** 链表 **
如果数据量非常大、动态性很高、栈的预期大小难以估计，那么基于链表实现的栈更加合适。链表能够将大量数据分散存储于内存的不同部分，并且避免了数组扩容产生的额外开销。
- 单向链表
**栈与队列**  **哈希表**  **图**
- 环状链表
**时间片轮转调度算法**  **数据缓冲区**
- 双向链表
**高级数据结构**  **浏览器历史**  **LRU 算法**


**栈**
**浏览器中的后退与前进、软件中的撤销与反撤销**
**程序内存管理**
** 队列**
**淘宝订单**  **各类待办事项**
**图**
现实生活中常见的图

||顶点|边|图计算问题|
|---|---|---|---|
|社交网络|用户|好友关系|潜在好友推荐|
|地铁线路|站点|站点间的连通性|最短路线推荐|
|太阳系|星体|星体间的万有引力作用|行星轨道计算|
4. 如何使用C语言保存一张图的信息？（开始理解错了，我还以为是保存图片信息，我说怎么突然整这么难，然后今天才理解到图·是一种数据结构类型）

图的基本组成包括顶点和边，常见的表示方式有邻接矩阵和邻接表 
[具体实现方式](https://chatgpt.com/c/6710f44c-9bfc-8011-8a25-0b6296dec8c0)

1. 在这一小节，你将实现一个**环形链表**，它的具体实现方式可以粗略地理解为**在单链表的基础上，将链表尾节点的后继指向该链表的头节点**。因此，你可以对单链表进行操作，并在最后完成环形链表的构建。要求如下：

> 1. 对于每一个链表节点，仅存储一个正整数作为data信息
> 2. 起始状态下，链表仅包含一个data等于1的节点作为头节点
> 3. 你需要实现该链表的如下操作：
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


