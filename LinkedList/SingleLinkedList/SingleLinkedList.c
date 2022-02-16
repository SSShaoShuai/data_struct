//
// Created by 47244 on 2022/1/19.
// ����ͷ���ĵ�����
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
LinkListHead List_TailInsert_NoHead(LinkListHead *L){
    printf("��ʼβ�巨����������\n");
    Node *s;//Ҫ����Ľڵ�
    Node *r;//β���
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
}

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
void PrintList_Head(LinkListHead L){
    printf("��ʼ�����������-����ͷ���\n");//����ͷ���ĵ�����L��Ϊ�������һλ
    while (L!=NULL){
        printf("%d ",L->data);
        L=L->next;
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

//��ֵ����Ԫ��
Node *LocalElem_NoHead(LinkListHead L,ElemType e){
    Node *p=L;
    while (p!=NULL && p->data!=e)
        p=p->next;
    return p;
}

//����Ԫ��
bool ListInsert_NoHead(LinkListHead *L,int i,ElemType e){
    if(i<1 || i>GetLength_NLinkList(L)){
        return false;
    }
    Node *p,*s;//sΪ�½ڵ�
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
    while (p!=NULL &&j<i-1){//�ҵ���i-1���ڵ�
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

//��λ��ɾ��-����ͷ���
/*
 * ��һλ���⴦����L��ֵ��p���������ָ��ָ��ԭ�ڶ�����㣬�ͷ�p����ʵ��ɾ����һ�����
 * ����ɾ��˼�룺�ҵ���i-1λ�Ľ�㣬���ýڵ�ĺ��ָ���iλ�ĺ�̣��ͷŵ�iλ�Ŀռ伴ʵ��ɾ������
 * */
bool ListDel_NoHead(LinkListHead *L,int i,ElemType *e){
    if(i<1 ){
        return false;
    }
    Node *p;
    if(i==1){//ɾ����һλ�����⴦��
        p=*L;
        *L= (*L)->next;
        free(p);
        return true;
    }
    int j=0;
    p=L;
    while (p!=NULL && j<i-1){//�ҵ�λ��Ϊi��ǰ�ýڵ㣬��ǰ�ýڵ�ĺ��ָ��i���ĺ��
        p=p->next;
        j++;
    }//ѭ���������ҵ���i-1�����
    if(p==NULL){//pֵΪ�����i�����������
        return false;//iֵ���Ϸ�
    }
    if(p->next==NULL){
        return false;//��i-1��ֵ�����������ڵ�
    }
    Node *q=p->next;//qָ��Ҫɾ���Ľ��
    e=q->data;//��ɾ����ֵ����e
    p->next=q->next;//��p�ĺ����Ϊq�ĺ�̣���ʵ��ɾ������
    free(q);//�ͷ�q���Ŀռ�
    return true;
}