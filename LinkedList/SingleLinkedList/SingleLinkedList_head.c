//
// Created by 47244 on 2022/2/16.
//
/*
 * 单链表带头结点
 * */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef int ElemType;

//定义单链表结构
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化单链表
bool ListInit(LinkList *L){
    *L=(LNode *) malloc(sizeof (LNode));
    (*L)->next=NULL;
    return  true;
}

//头插法建立单链表------从单链表表头依次插入数据
LinkList List_HeadInsert(LinkList *L) {
    printf("开始头插法建立单链表");
    LNode *s; int x;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        s->next=(*L)->next;
        (*L)->next=s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法建立单链表------从单链表表尾依次插入数据
LinkList List_TailInsert(LinkList *L){
    printf("开始尾插法建立单链表");
    int x;
    *L= (LinkList)malloc(sizeof (LNode));
    (*L)->next=NULL;
    LNode  *s,*r=*L;
    scanf("%d",&x);
    while (x!=9999){
        s=(LNode *) malloc(sizeof (LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}


//获取单链表表长
int GetLength(LinkList L){
    LNode *p;
    int count=0;
    p=L->next;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

//单链表判空
bool ListEmpty(LinkList L){
    LNode *p;
    p=L->next;
    if(p!=NULL){
        return false;
    } else{
        return true;
    }
}

//输出链表
void PrintList(LinkList L){
    printf("开始输出链表数据\n");
    LinkList p;
    p=L->next;
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n输出链表数据结束\n");
}

//按位查找元素
LNode *GetElem(LinkList L,int i){
    int j=1;
    LNode *p=L->next;
    if(i==0)
        return L;
    if(i<1)
        return NULL;
    while (p&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

//按值查找元素
LNode *LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while (p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

//插入元素
bool ListInsert(LinkList *L,int i,ElemType e){
    LNode *p,*s;
    int j=0;
    p=*L;
    while (p!=NULL&&j<i-1){
        //找到i-1个节点
        p=p->next;
        j++;
    }
    if(j!=i-1){
        return false;//未找到插入位置，报错
    }
    s=(LinkList) malloc(sizeof (LNode));//生成新节点
    s->data=e;//将值赋给s
    s->next=p->next;//将s的后继指针指向原p的后继指针
    p->next=s;//将p的后继指针指向s
    return true;
}

//删除元素
bool ListDelete(LinkList *L,int i,ElemType *e){
    LNode *p,*r;
    int j=0;
    p=*L;
    while (p->next!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(j!=i-1){
        return false;//删除的节点不合法，返回false
    }
    r=p->next;
    *e=r->data;
    p->next=p->next->next;
    free(r);
    return true;
}

//单链表指定节点删除
/*
 * 找到该节点的后继节点，将该后继节点的值赋给当前节点，
 * 该后继节点的后继赋值给当前结点，释放后继节点，即实现根据结点删除
 * */
bool ListDel_LNode(LNode *L){
    if(L==NULL){
        return false;
    }
    LNode *q=L->next;
    L->data=L->next->data;//将L的后继节点的值赋给L
    L->next=q->next;//L的next位q的next
    free(q);
    return true;
}

