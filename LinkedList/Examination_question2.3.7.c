//
// Created by 倪先生 on 2022/4/3.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

/*---------------------------------不带头节点单链表---------------------------------*/
typedef struct Node1 {
    int data;
    struct Node1 *next;
} Node1, LinkListNoHead;

bool InitSListNH(LinkListNoHead *L) {
    L = NULL;
    return true;
}

//创建不带头节点的单链表
LinkListNoHead *CreateSListNH() {
    LinkListNoHead *p;
    p = (LinkListNoHead *) malloc(sizeof(LinkListNoHead));
    LinkListNoHead *tmp = p;
    int i;
    //生成链表
    for (i = 1; i < 10; i++) {
        LinkListNoHead *a = (LinkListNoHead *) malloc(sizeof(LinkListNoHead));
        a->data = i;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
    }
    return p;
}

//输出链表
void PrintList_NoHead(LinkListNoHead *L) {
    printf("开始输出链表数据-不带头结点\n");//不带头结点的单链表L即为单链表第一位
    Node1 *node = L;
    while (node != NULL) {
        printf("\n%d", node->data);
        node = node->next;
    }
    printf("\n输出链表结束\n");
}
/*---------------------------------不带头节点单链表---------------------------------*/


/*---------------------------------带头节点单链表---------------------------------*/
// 带头节点单链表结构定义
typedef struct Node2 {
    ElemType data;
    struct Node2 *next;
} Node2, *LinkListWithHead;

//初始化
LinkListWithHead InitSLinkWH() {
    LinkListWithHead L;
    L = (Node2 *) malloc(sizeof(Node2));
    if (L == NULL) return NULL;
    L->next = NULL;
    return L;
}

//尾插
LinkListWithHead ListInsert_Tail_WH(LinkListWithHead L) {
    int x;
    L = (Node2 *) malloc(sizeof(Node2));
    Node2 *s, *r = L;
    L->next = NULL;
    scanf("%d", &x);
    while (x != 99) {
        s = (Node2 *) malloc(sizeof(Node2));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//输出链表
void Print_List_WH(LinkListWithHead L) {
    printf("\n");
    Node2 *p;
    p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkListWithHead Struct_List() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("List Insert Success\n");
    return L;
}

//获取单链表表长
int GetLengthWithHead(LinkListWithHead L) {
    Node2 *p;
    int count = 0;
    p = L->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
/*---------------------------------带头节点单链表---------------------------------*/



/*-----------------题目--------------------*/
/*
 *@Title:第一题
 *@Description: 设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点
 *@Operation:
 *@author: NSS
 *@date:2022/4/3
 **/
void Del_All_X(LinkListNoHead *L, int x) {
    Node1 *p;
    if (L->next == NULL)return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_All_X(L, x);
    }
    if (L->next->data == x) {
        p = L->next;
        L->next = L->next->next;
        free(p);
        Del_All_X(L, x);
    } else {
        Del_All_X(L->next, x);
    }
}

/*
 *@Title:第二题
 *@Description:在带头节点的单链表中删除所有值为x的节点，并释放其空间，假设x值不唯一
 *@Operation:
 *@author: NSS
 *@date:2022/4/4
 **/
void Del_All_X_WH(LinkListWithHead L, int i) {
    Node2 *p;
    if (L->next == NULL)return;
    if (L->next->data == i) {
        p = L->next;
        L->next = L->next->next;
        free(p);
        Del_All_X_WH(L, i);
    } else {
        Del_All_X_WH(L->next, i);
    }
}

/*
 *@Title:第三题
 *@Description:设L为带头节点的单链表，编写算法实现从尾到头反向输出每个节点的值
 *@Operation:
 *@author: NSS
 *@date:2022/4/4
 **/
void R_Print(LinkListWithHead L) {
    if (L->next != NULL) {
        R_Print(L->next);//递归调用，方法被压入递归栈，调用结束后返回该方法并执行后面的相关语句
    }
    if (L != NULL)printf("data:%d", L->data);
}

void ReverseData(LinkListWithHead pNode2) {
    printf("\n");
    if (pNode2->next != NULL) {
        R_Print(pNode2->next);
    }
}

/*
 *@Title:第四题
 *@Description:编写在带头结点的单链表中删除一个最小值的高效算法（假设最小值结点唯一）
 *@Operation:用p从头到尾遍历链表，pre指向p的前驱，minp保存值最小的节点指针，minpre指向minp的前驱，一边扫描一边比较
 *           若p->data小于minp->data，则将p，pre分别赋值给minp，minpre，当p扫描完是minp指向最小值节点
 *@author: NSS
 *@date:2022/4/5
 **/
void fun4() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");


    Node2 *pre = L;
    Node2 *p = pre->next;
    Node2 *minp = p;
    Node2 *minpre = pre;

    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;     //找到当前的最小值结点，并赋值
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }//循环结束，minp指向的即为最小值节点
    minpre->next = minp->next;
    free(minp);
    Print_List_WH(L);
    printf("Delete Min Finish");
}

/*
 *@Title:第五题
 *@Description:编写算法将带头节点的单链表就地逆置，所谓"就地"是指辅助空间复杂度为O(1)
 *@Operation:将头结点摘下，然后从第一个节点开始，一次插入到头结点的后面（头插法建立单链表）直至最后一个节点
 *@author: NSS
 *@date:2022/4/5
 **/
void fun_5() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");

    Node2 *p, *r;//工作指针，r为p的后继，以防断链
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    Print_List_WH(L);
    printf("Reverse Finish");
}

fun_5_2() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");

    Node2 *pre, *p = L->next, *r = p->next;
    p->next = NULL;    //将第一个节点的后继置空
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre; //指针反转
    }
    L->next = p;
    Print_List_WH(L);
    printf("Reverse Finish");
}

/*
 *@Title:第六题
 *@Description:有一个带头节点的单链表L，设计一个算法使其递增有序
 *@Operation:
 *@author: NSS
 *@date:2022/4/28
 **/
void func_6() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("List Insert success");

    //构建一个只包含一个数据节点的有序单链表
    Node2 *p = L->next, *pre;  //p为工作指针，pre为p的前驱节点
    Node2 *r = p->next;   //保存p之后的链表数据，保证有数据可取
    p->next = NULL;       //使当前链表只有一个数据节点；构建包含p节点的有序链表
    p = r;    //让p指向r后面的节点（初始为第三个节点）

    while (p != NULL) {
        r = p->next;  //保存p后面的链表数据，使需要排序的链表不断
        pre = L;
        //p为较大的节点，pre是较小的节点
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;  //pre是较小的节点
        }
        //p节点较大，放在pre的后面
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    printf("Sort Finish\n");
    Print_List_WH(L);
    free(L);
}


/*
 *@Title:
 *@Description: 一个带头节点的单链表中，所有元素节点无序，设计算法，删除表中所有介于给定的两个值之间的元素
 *@Operation:   从头遍历单链表所有元素，判断后进行删除操作
 *@author: NSS
 *@date:2022/4/29
 **/
void func_7(int min, int max) {
    LinkListWithHead L;
    L = Struct_List();

    Node2 *p = L->next;
    Node2 *pre = L;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
    printf("Execute Finish\n");
    Print_List_WH(L);
    printf("finish\n");
}

/*
 *@Title:第八题
 *@Description: 给定两个单链表，设计算法找出两个链表的公共节点
 *@Operation:       因为是两个单链表，所以公共节点之后的所有节点应该是相同的，即他们的最后一个节点是重合的
 *                  因此只要找到第一个重合的节点后面的节点就都是重合节点了
 *                  但两个链表的长度不一定一样，假设长链表比短链表长k个节点，设计算法先让长链表遍历k个节点
 *                  之后在同步遍历，即可保证遍历的同步，所以找到的第一个相同节点就是公共节点
 *@author: NSS
 *@date:2022/4/29
 **/
LinkListWithHead func_8(LinkListWithHead L1, LinkListWithHead L2) {
    //本算法实现在线性时间内找到两个单链表的第一个公共节点
    int len1 = GetLengthWithHead(L1), len2 = GetLengthWithHead(L2);//将两个链表的长度分别求出
    LinkListWithHead longList, shortList;
    int dist;
    if (len1 > len2) {//判断两个链表那个更长，赋值并求出长度之差
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {//先将长链表指针后移两链表长度之差个位置
        longList = longList->next;
    }
    while (longList != NULL) {//判断当前节点是否是公共节点
        if(longList==shortList){
            return longList;//是公共节点，返回
        } else{//不是将两链表指针分别后移
            longList=longList->next;
            shortList=shortList->next;
        }
    }
    return NULL;
}

/*
 *@Title:第九题
 *@Description:按递增次序输出单链表中各节点的数据元素，并释放节点所占的存储空间
 *@Operation:   对链表进行遍历，每次遍历找出最小值并释放，一直循环，直至链表为空
 *@author: NSS
 *@date:2022/4/29
 **/
void func_9(){
    LinkListWithHead L;
    L = Struct_List();

    while (L->next!=NULL){
        Node2 *pre=L;//pre为元素最小值节点的前驱节点
        Node2 *p=pre->next;//p为工作指针
        while (p->next!=NULL){
            if(p->next->data<pre->next->data){
                pre=p;//将当前最小值节点的前驱节点进行赋值
            }
            p=p->next;
        }
        printf("%d ",pre->next->data);//输出节点数据
        Node2 *u;
        u=pre->next;
        pre->next=u->next;
        free(u);//释放节点
    }
    free(L);//释放头指针
}

/*
 *@Title:第十题
 *@Description:将一个带有头节点的单链表A分解为两个带头节点的单链表A和B，使A表中含有原表中序号为奇数的元素，B表中含有原表中序号为偶数的元素，保持相对顺序不变
 *@Operation:   设计访问序号变量，每访问一个节点序号自动加一，然后根据序号的奇偶性将节点插入到A表或B表中。重复操作直到表尾
 *@author: NSS
 *@date:2022/4/29
 **/
void func_10(){
    LinkListWithHead A;
    A = Struct_List();

    int i=0;//i为访问序号变量
    LinkListWithHead B=(LinkListWithHead) malloc(sizeof (Node2));//创建B表表头
    B->next=NULL;//B表初始化
    Node2 *ra=A,*rb=B,*p; //ra和rb分别指向将创建的A表和B表的尾节点

    p=A->next;//p为链表工作指针，指向待分解的节点
    A->next=NULL;//将A表置空
    while (p!=NULL){
        i++;
        if(i%2==0){//位序为偶数的链表节点
            rb->next=p;//在b表尾插入新节点
            rb=p;//将rb指向新的尾节点
        } else{
            ra->next=p;//在A表尾插入新节点
            ra=p;
        }
        p=p->next;  //将p恢复为指向新的待处理节点
    }
    ra->next=NULL;
    rb->next=NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:第十一题
 *@Description:设C={a1,b1,a2,b2,……,an,bn}为线性表，采用带头节点的hc单链表进行存放，设计一个就地算法，将其拆分为两个线性表，使得A=={a1,a2,……,an},B=={bn,……,b2,b1}
 *@Operation:采用第十题的思路，区别是不需要设序号变量。B表的建立不采用尾插法
 *@author: NSS
 *@date:2022/4/29
 **/
void func_11(){
    LinkListWithHead A;
    A = Struct_List();

    LinkListWithHead B=(LinkListWithHead) malloc(sizeof (Node2));//创建B表表头
    B->next=NULL;
    Node2 *p=A->next,*q;
    Node2 *ra=A;
    while (p!=NULL){
        ra->next=p;
        ra=p;
        p=p->next;
        if(p!=NULL){
            q=p->next;
            p->next=B->next;
            B->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

int main() {

/*--------------------不带头节点的单链表相关题目--------------------*/
    /*LinkListNoHead *L;
    InitSListNH(L);
    L=CreateSListNH();
    PrintList_NoHead(L);
    Del_All_X(L,2);//第一题
    printf("删除后：");
    PrintList_NoHead(L);*/

/*--------------------带头节点的单链表相关题目--------------------*/
//    LinkListWithHead L;
//    L = ListInsert_Tail_WH(L);
//    Print_List_WH(L);
//    ReverseData(L);//第三题
//    Del_All_X_WH(L,2);第二题
//    fun4();//第四题
//    fun_5_2();
//    func_6();
//    func_7(3, 9);
//    func_9();
//    func_10();
    func_11();
    return 0;
}


