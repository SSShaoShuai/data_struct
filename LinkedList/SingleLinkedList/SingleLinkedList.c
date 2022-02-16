//
// Created by 47244 on 2022/1/19.
// 不带头结点的单链表
//
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
LinkListHead List_TailInsert_NoHead(LinkListHead *L){
    printf("开始尾插法建立单链表\n");
    Node *s;//要插入的节点
    Node *r;//尾结点
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
}

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
void PrintList_Head(LinkListHead L){
    printf("开始输出链表数据-不带头结点\n");//不带头结点的单链表L即为单链表第一位
    while (L!=NULL){
        printf("%d ",L->data);
        L=L->next;
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

//按值查找元素
Node *LocalElem_NoHead(LinkListHead L,ElemType e){
    Node *p=L;
    while (p!=NULL && p->data!=e)
        p=p->next;
    return p;
}

//插入元素
bool ListInsert_NoHead(LinkListHead *L,int i,ElemType e){
    if(i<1 || i>GetLength_NLinkList(L)){
        return false;
    }
    Node *p,*s;//s为新节点
    int j=1;
    s=(Node *) malloc(sizeof (Node));
    s->next=NULL;
    s->data=e;
    p=L;
    if(i==1){
        s->next=L;
        L=s;
        return true;
    }
    while (p!=NULL &&j<i-1){//找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    s->next=p->next;
    p->next=s;
    return true;
}

//按位序删除-不带头结点
/*
 * 第一位特殊处理：将L赋值给p，将链表的指针指向原第二个结点，释放p，及实现删除第一个结点
 * 后续删除思想：找到第i-1位的结点，将该节点的后继指向第i位的后继，释放第i位的空间即实现删除操作
 * */
bool ListDel_NoHead(LinkListHead *L,int i,ElemType *e){
    if(i<1 ){
        return false;
    }
    Node *p;
    if(i==1){//删除第一位，特殊处理
        p=*L;
        *L= (*L)->next;
        free(p);
        return true;
    }
    int j=0;
    p=L;
    while (p!=NULL && j<i-1){//找到位序为i的前置节点，将前置节点的后继指向i结点的后继
        p=p->next;
        j++;
    }//循环结束已找到第i-1个结点
    if(p==NULL){//p值为空则第i个结点无数据
        return false;//i值不合法
    }
    if(p->next==NULL){
        return false;//第i-1个值后已无其他节点
    }
    Node *q=p->next;//q指向要删除的结点
    e=q->data;//将删除的值赋给e
    p->next=q->next;//将p的后继设为q的后继，即实现删除操作
    free(q);//释放q结点的空间
    return true;
}