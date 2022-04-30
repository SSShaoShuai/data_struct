//
// Created by 47244 on 2022/1/19.
// 不带头结点的单链表
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkListHead;


//初始化
bool ListInit_Head(LinkListHead *L) {
    *L = NULL;
    return true;
}


//头插法建立单链表
LinkListHead List_HeadInsert_NOHead(LinkListHead *L) {
    printf("\n开始头插法建立单链表-不带头结点\n");
    Node *s;
    int x;
    scanf("%d", &x);
    while (x!=9999) {
        s = (Node *) malloc(sizeof(Node));
        s->data=x;
        s->next=NULL;
        if(*L==NULL){
            *L=s;
        } else{
//            s->next = (*L)->next;
//            (*L)->next = s; //这两步操作会把新值插入到逻辑上第二位
            s->next = *L;
            *L = s;
        }
        scanf("%d", &x);
    }
    printf("1111");
    return L;
}

//尾插法建立单链表--不带头结点
LinkListHead *List_TailInsert_NoHead(LinkListHead *L){
    int x;
    L=(LinkListHead *) malloc(sizeof(Node));
    Node *s,*r=L;
    scanf("%d",&x);
    while (x!=9999){
        s=(Node *) malloc(sizeof (Node));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }

    r->next=NULL;
    return L;
}
/*LinkListHead List_TailInsert_NoHead(LinkListHead *L){
    printf("\n开始尾插法建立单链表\n");
    L=(LinkListHead) malloc(sizeof (Node));
    Node *s;//要插入的节点
    Node *r=L;//尾结点
    int x;
    scanf("%d",&x);
    while (x!=9999){
        s=(Node *) malloc(sizeof (Node));
        s->data=x;
        s->next=NULL;
        if(*L==NULL){
            *L=s;//链表为空则将s职位链表第一个结点
            r=*L;//将链表第一个节点赋值给r方便后续在尾部插入
        } else{
            r->next=s;//链表不为空将链表尾结点的后继节点指向s
            r=s;//将r指向s
        }
        scanf("%d",&x);
    }
    return L;
}*/

//求表长
int GetLength_NLinkList(LinkListHead L){
    int count=0;
    while (L!=NULL){
        count++;
        L=L->next;
    }
    return count;
}

//判空
bool List_HeadEmpty(LinkListHead L){
    if(L==NULL){
        return true;
    } else{
        return false;
    }
}
//输出链表
void PrintList_Head(LinkListHead *L){
    printf("开始输出链表数据-不带头结点\n");//不带头结点的单链表L即为单链表第一位
    Node *node=L;
    while (node!=NULL){
        printf("\n%d",node->data);
        node=node->next;
    }
    printf("\n输出链表结束\n");
}

//按位查找元素
Node  *GetElem_NoHead(LinkListHead L,int i){
    if(i<1){
        return NULL;
    }
    int j=1;
    Node *P=L;
    if(i==1){
        return P;
    }
    while (P&&j<i){
        P=P->next;
        j++;
    }
    return P;
}