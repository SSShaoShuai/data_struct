//
// Created by ������ on 2022/3/30.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;


//��ʼ��˫����
bool InitDLinkList(DLinkList *L) {
    (*L) = (DNode *) malloc(sizeof(DNode));
    if ((*L) == NULL) return false;
    (*L)->prior = L;
    (*L)->next = L;
    return true;
}

//˫�����п�
bool Empty(DLinkList L) {
    if (L->next = L)return true;
    return false;
}

//�жϽڵ��Ƿ��Ǳ�β
bool isTail(DLinkList L, DNode *p) {
    if (p->next == L)return true;
    return false;
}

//��λ���ң����ص�i���ڵ�
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

//��ֵ���ң����ص�һ��������Ϊe�Ľڵ�
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

//��p�ڵ�֮�����s�ڵ�
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

//��p�ڵ�֮�����ֵΪe�Ľڵ�
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

//ǰ�壬��p�ڵ�֮ǰ����ڵ�s
bool InsertPriorDNode(DNode *p,DNode *s){
    return InsertNextDNode(p->prior,s);
}

//��λ���룬�ڵ�i��λ�ò���ֵΪe�Ľڵ� ��λ��i��
bool InsertDLinkList(DLinkList *L,int i,ElemType e){
    if (i<=0)return false;
    DNode *p= GetElem(L,i-1);
    return InsertNextData(p,e);
}

//ɾ��p�ڵ�ĺ�̽ڵ�
bool  DeleteNextNode(DNode *p){
    if(p==NULL)return false;
    DNode *q=p->next;
    p->next=q->next;
    q->next->prior=p;
    free(q);
    return true;
}

//����˫����
bool DestoryList(DLinkList *L){
    while ((*L)->next!=L){
        DeleteNextNode(L);
    }
    free(L);
    L=NULL;
    return true;
}

//β�巨
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

//ͷ�巨
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

//ɾ��ָ���ڵ�s
bool DeleteNode(DNode *s){
    DNode *p;
    p=s->prior;
    p->next=s->next;
    s->next->prior=p;
    free(s);
    return true;
}

//ɾ��λ��i�Ľڵ㣬e�ǽڵ��ֵ
bool  ListDelete(DLinkList *L,int i,ElemType *e){
    if(i<=0 ||i> length(L))return false;
    DNode *s;
    s= GetElem(L,i);
    if(s==NULL) return NULL;
    e=s->data;
    return DeleteNode(s);
}

//�����������
void printLinkList(DLinkList L){
    DNode *p=L->next;
    while (p!=L){
        printf("%d",p->data);
        p=p->next;
    }
    printf("�������");
}


int main() {
    printf("˫ѭ������ --��ʼ");
}