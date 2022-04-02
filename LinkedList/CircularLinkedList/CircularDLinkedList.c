//
// Created by 倪先生 on 2022/3/30.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


//初始化双链表
bool InitDLinkList(DLinkList *L) {
    (*L) = (DNode *) malloc(sizeof(DNode));
    if ((*L) == NULL) return false;
    (*L)->prior = L;
    (*L)->next = L;
    return true;
}

//双链表判空
bool Empty(DLinkList L) {
    if (L->next = L)return true;
    return false;
}

//判断节点是否是表尾
bool isTail(DLinkList L, DNode *p) {
    if (p->next == L)return true;
    return false;
}

//按位查找，返回第i个节点
DNode *GetElem(DLinkList L, int i) {
    if (i < 0) return NULL;
    if (i == 0) return L;
    int j = 1;
    DNode *p = L->next;
    while (p != L && j < i) {
        p = p->next;
        j++;
    }
    if (p == L) return NULL;
    return p;
}

//按值查找，返回第一个数据域为e的节点
DNode *LocateElem(DLinkList L, ElemType e) {
    DNode *p = L;
    if (p == NULL) return NULL;
    p = p->next;
    while (p != L && p->data != e) {
        p = p->next;
    }
    if (p == L) return NULL;
    return p;
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s){
    if(p==NULL||s==NULL){
        return false;
    }
    s->next=p->next;
    p->next->prior=s;
    s->prior=p;
    p->next=s;
    return true;
}

//在p节点之后插入值为e的节点
bool InsertNextData(DNode *p,ElemType e){
    if (p==NULL)return false;
    DNode *q=(DNode *) malloc(sizeof(DNode));
    if(q==NULL)return false;
    q->data=e;
    q->prior=p;
    p->next->prior=q;
    q->next=p->next;
    p->next=q;
    return true;
}

//前插，在p节点之前插入节点s
bool InsertPriorDNode(DNode *p,DNode *s){
    return InsertNextDNode(p->prior,s);
}

//按位插入，在第i个位置插入值为e的节点 （位序i）
bool InsertDLinkList(DLinkList *L,int i,ElemType e){
    if (i<=0)return false;
    DNode *p= GetElem(L,i-1);
    return InsertNextData(p,e);
}

//删除p节点的后继节点
bool  DeleteNextNode(DNode *p){
    if(p==NULL)return false;
    DNode *q=p->next;
    p->next=q->next;
    q->next->prior=p;
    free(q);
    return true;
}

//销毁双链表
bool DestoryList(DLinkList *L){
    while ((*L)->next!=L){
        DeleteNextNode(L);
    }
    free(L);
    L=NULL;
    return true;
}

//尾插法
DLinkList List_TailInsert(DLinkList *L){
    InitDLinkList(*L);
    DNode *p=L;
    ElemType x;
    scanf("%d",&x);
    while (x!=9999){
        InsertNextData(p,x);
        p=p->next;
    }
    return L;
}

//头插法
DLinkList List_HeadInsert(DLinkList *L){
    InitDLinkList(*L);
    ElemType x;
    scanf("%d",&x);
    while (x!=9999){
        InsertNextData(L,x);
    }
    return L;
}

int length(DLinkList L){
    DNode *p=L;
    int len=0;
    while (p->next!=L){
        len++;
        p=p->next;
    }
    return len;
}

//删除指定节点s
bool DeleteNode(DNode *s){
    DNode *p;
    p=s->prior;
    p->next=s->next;
    s->next->prior=p;
    free(s);
    return true;
}

//删除位序i的节点，e是节点的值
bool  ListDelete(DLinkList *L,int i,ElemType *e){
    if(i<=0 ||i> length(L))return false;
    DNode *s;
    s= GetElem(L,i);
    if(s==NULL) return NULL;
    e=s->data;
    return DeleteNode(s);
}

//输出链表内容
void printLinkList(DLinkList L){
    DNode *p=L->next;
    while (p!=L){
        printf("%d",p->data);
        p=p->next;
    }
    printf("输出结束");
}


int main() {
    printf("双循环链表 --开始");
}