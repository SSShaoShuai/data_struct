//
// Created by 47244 on 2022/1/19.
// 双向链表--带头结点
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//初始化双链表--带头结点
bool DListInit_WithHead(DLinkList *L) {
    *L = (DNode *) malloc(sizeof(DNode));
    if (!(*L)) return false;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return true;
}


//头插法建立双链表--带头结点
DLinkList DList_HeadInsert(DLinkList *L) {
    DListInit_WithHead(*L);
    ElemType x;
    DNode *s;
    scanf("%d", &x);
    while (x != 9999) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = x;
        s->prior = *L;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插法建立双链表--带头结点
DLinkList DList_TailInsert(DLinkList *L) {
    printf("\n开始尾插法建立双链表\n");
    DListInit_WithHead(*L);
    ElemType x;
    DNode *s, *r = *L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = x;
        r->next = s;
        s->prior = r;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}


//双链表求表长--带头结点
int DList_Length(DLinkList L) {
    int len = 0;
    DNode *p = L;
    while (p->next != NULL && p->data != NULL) {
        len++;
        printf("%d ,", p->data);
        p = p->next;
    }
    printf("%d", p->data);
    return len;
}


//双链表输出--带头结点
void print_DList(DLinkList L) {
    printf("\n开始输出链表\n");
    DNode *p = L->next;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n输出链表结束\n");
}

//判断双链表是否为空
bool empty_DList(DLinkList L) {
    if (L->next == NULL) {
        return true;
    }
    return false;
}


//按位查找：返回第i个结点
DNode *GetELem_DList(DLinkList L, int i) {
    if (i < 0) return NULL;
    int j = 0;
    DNode *p = L;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找： 返回第一个数据域为e的结点
DNode *LocateELem_DList(DLinkList L, ElemType e) {
    DNode *p = L;
    if (p == NULL) return NULL;
    p = p->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

//后插结点--带头结点  p为位序结点，s为插入的结点---将s插入到p的后一位
//操作顺序 s的后继指向p的后继--p的后继结点的前驱结点指向s--s的前驱指向p--p的后继指向s
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p->next;      //
    if (p->next != NULL) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

//后插指定值的结点  p为位序结点，e为要插入的值--在p结点后面插入值是e的结点
//操作顺序： 申请一个结点的内存空间 将新节点的值置为e，新节点的前驱指向p，新节点的后继指向p的后继，
//          p的后继结点的前驱指向新节点，p结点的后继指向新节点
//注意有判空操作--如果p为表尾结点需要特殊处理
bool insertNextDNode_data(DNode *p, ElemType e) {
    if (p == NULL) return false;
    DNode *q = (DNode *) malloc(sizeof(DNode));
    if (q == NULL) return false;
    q->data = e;
    //默认p为表尾结点
    q->next = NULL;
    q->prior = p;
    if (p->next != NULL) {//若p不为表尾结点则重新修改q的前驱和后继指向
        p->next->prior = q;
        q->next = p->next;
    }
    p->next = q;
    return true;
}


//按位插入--在第i个位置插入值为e的节点（位序i）
bool InsertDNode_Order(DLinkList *L, int i, ElemType e) {
    if (i <= 0) return false;
    int j = 0;
    DNode *p = L;
    DNode *q = (DNode *) malloc(sizeof(DNode));
    if (q == NULL) return false;
    q->data = e;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
        if (p->next == NULL && j == i - 1) {
            printf("\n表尾");
            q->prior = p;
            q->next = NULL;
            p->next = q;
            return true;
        }
    }
    p = p->prior;
    q->next = NULL;
    q->prior = p;
    if (p->next != NULL) {
        p->next->prior = q;
        q->next = p->next;
    }
    p->next = q;
    return true;
}

//前插，在p节点前面插入节点s
bool InsertDNodeBeforeNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) return false;
    s->next = p;
    s->prior = p->prior;
    p->prior = s;
    p->prior->next = s;
    return true;
}

/*销毁双链表
 *从表头开始依次删除每个节点
 * */
bool DestoryList(DLinkList *L){
    while((*L)->next!=NULL){
        DNode *p=*L,*q=p->next;
        p->next=q->next;
        if(q->next!=NULL)q->next->prior=p;
        free(q);
    }
    free(L);
    L=NULL;
    return true;
}

//删除p节点的后继节点
//操作： 判断p节点是否为空，判断p节点是否有后继节点
//      p节点的后继节点改为q的后继节点，q的后继节点的前驱节点指向p 释放q节点
bool DeleteNextNode(DNode *p) {
    if (p == NULL) return false;
    DNode *q = p->next;
    if (q == NULL) return false;
    p->next=q->next;
    if (q->next!=NULL)q->next->prior=p;
    free(q);
    return true;
}

/*
 *@Description:删除指定节点s
 *@Operation:定义新节点p将s的前驱赋值给p，修改p的next为s的next，判断s的next是否为空，不为空则将s的next的前驱指向p 即完成删除
 *@author: NSS
 *@date:2022/2/16
 **/
bool DeleteDNode(DNode *s){
    DNode  *p;
    p=s->prior;
    p->next=s->next;
    if(s->next!=NULL){
        s->next->prior=p;
    }
    free(s);
    return true;
}

/*
 *@Description:删除位序i的节点，e为i节点的值
 *@Operation: 找到需要删除的节点的值，将其前驱节点的后继指向其后继节点，将其后继节点的前驱指向其前驱，释放该节点的内存空间
 *@author: NSS
 *@date:2022/2/16
 **/
bool DeleteByOrder(DLinkList *L,int i,ElemType *e){
    if(i<=0 || i> DList_Length(L))return false;
    DNode *s,*p;
    int j=0;
    s=L;
    if(s->next!=NULL&&j<i){
        s=s->next;
        j++;
    }
    if(s==NULL)return false;
    e=s->data;
    p=s->prior;
    p->next=s->next;
    if(s->next!=NULL){
        s->next->prior=p;
    }
    free(s);
    return true;
}