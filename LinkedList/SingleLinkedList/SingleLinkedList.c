//
// Created by 47244 on 2022/1/19.
// ����ͷ���ĵ�����
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


//��ʼ��
bool ListInit_Head(LinkListHead *L) {
    *L = NULL;
    return true;
}


//ͷ�巨����������
LinkListHead List_HeadInsert_NOHead(LinkListHead *L) {
    printf("\n��ʼͷ�巨����������-����ͷ���\n");
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
//            (*L)->next = s; //���������������ֵ���뵽�߼��ϵڶ�λ
            s->next = *L;
            *L = s;
        }
        scanf("%d", &x);
    }
    printf("1111");
    return L;
}

//β�巨����������--����ͷ���
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
    printf("\n��ʼβ�巨����������\n");
    L=(LinkListHead) malloc(sizeof (Node));
    Node *s;//Ҫ����Ľڵ�
    Node *r=L;//β���
    int x;
    scanf("%d",&x);
    while (x!=9999){
        s=(Node *) malloc(sizeof (Node));
        s->data=x;
        s->next=NULL;
        if(*L==NULL){
            *L=s;//����Ϊ����sְλ�����һ�����
            r=*L;//�������һ���ڵ㸳ֵ��r���������β������
        } else{
            r->next=s;//����Ϊ�ս�����β���ĺ�̽ڵ�ָ��s
            r=s;//��rָ��s
        }
        scanf("%d",&x);
    }
    return L;
}*/

//���
int GetLength_NLinkList(LinkListHead L){
    int count=0;
    while (L!=NULL){
        count++;
        L=L->next;
    }
    return count;
}

//�п�
bool List_HeadEmpty(LinkListHead L){
    if(L==NULL){
        return true;
    } else{
        return false;
    }
}
//�������
void PrintList_Head(LinkListHead *L){
    printf("��ʼ�����������-����ͷ���\n");//����ͷ���ĵ�����L��Ϊ�������һλ
    Node *node=L;
    while (node!=NULL){
        printf("\n%d",node->data);
        node=node->next;
    }
    printf("\n����������\n");
}

//��λ����Ԫ��
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