//
// Created by ������ on 2022/3/30.
//
/*
 * ѭ��������--Lָ���β
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>


/*��������ṹ*/
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;

//struct LNode* �ȼ� LinkList
//ǿ���ڵ� LNode
//ǿ������ LinkList

//��ʼ������
bool InitList(LinkList *L){
    *L=(LNode *) malloc(sizeof(LNode));
    if(*L==NULL) return false;
    (*L)->next=L;
    return true;
}

/*��λ���ң����ص�i��Ԫ�أ���ͷ�ڵ㣩*/
LNode * GetElem(LinkList L,int i){
    if (i<0) return false;
    if(i==0) return L->next;
    int j=1;
    LNode *p=L->next->next;
    while (p!=L->next && j<i){
        p=p->next;
        j++;
    }
    if(p==L->next) return NULL;  //�ж��Ƿ��Ǳ�ͷ
    return p;
}

//��ֵ���ң��ҵ����������e�Ľڵ�
LNode * LocateElem(LinkList L,int e){
    LNode *p=L->next->next;
    while (p!=L->next && p->data!=e){
        p=p->next;
    }
    if(p->data==e){
        return p;
    }
    return NULL;
}

//�������
int Length(LinkList L){
    int len=0;
    LNode *p=L;
    while (p->next!=L){
        len++;
        p=p->next;
    }
    return len;
}

//���������ڽڵ�p֮�����Ԫ��e
bool InsertNextNode(LinkList *L,LNode *p,int e){
    if(!p) return false;
    LNode *s=(LNode*) malloc(sizeof(LNode));
    if(!s) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    if(p==L) L=s;   //�жϲ����λ���Ƿ��Ǳ�β֮������Lָ��ǰ��β�ڵ�
    return true;
}

//��ͷ�ڵ�Ĳ���������ڵ�i��λ�ò���Ԫ��e
bool ListInsert(LinkList *L,int i,int e){
    if(i<1)return false;
    LNode *p= GetElem(L,i-1);//�ҵ���i��λ�õ�ǰ�ýڵ�
    if(!p)return false;
    return InsertNextNode(L,p,e);
}

//ǰ���������p�ڵ�֮ǰ����Ԫ��e   ǰ��Ԫ��
bool InsertPriorData(LNode *p,int e){
    if(!p) return false;
    LNode *s=(LNode *) malloc(sizeof(LNode));
    if(!s) return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//ǰ���������p�ڵ�֮ǰ����ڵ�s  ǰ��ڵ�
bool InsertPriorNode(LNode *p,LNode *s){
    if(!p || !s){
        return false;
    }
    int i=s->data;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=i;
    return true;
}

//ɾ��λ��i�Ľڵ㣬e�ǽڵ��ֵ   --��λ��ɾ���ڵ�
bool ListDelete(LinkList *L,int i,int *e){
    if(i<1)return false;
    LNode *p= GetElem(L,i-1);//�ҵ���Ҫɾ���Ľڵ��ǰ�ýڵ�
    if(p==NULL || p==L)return false;
    if(p->next==L) L=p;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

//ɾ��ָ���ڵ�p  --ɾ���ڵ�
bool DeleteNode(LinkList *L,LNode *p){
    LNode *q=p->next;
    p->data=q->data;
    p->next=q->next;
    /*����ǰɾ���Ľڵ�Ϊ��β���������渳ֵ��p��ǰΪ��ͷ
     *��Ҫ��Lָ��p��ǰ�ýڵ㣬���µ�ǰ��β��ָ��
     * */
    if(L==p){       //β�ڵ㵥������
        q=p;
        while (q->next!=p){
            q=q->next;
        }
        L=q;
    }
    //free(q);   ��ʱ����ִ�иò�������Ϊ��ǰq�ͱ�βָ�����ͬһ���ڴ�ռ䣬��ִ��������Ͷ���
    return true;
}

//β�巨����ͷ�ڵ�
LinkList List_TailInsert(LinkList *L){
    printf("\n��ʼβ�巨����ѭ��������\n");
    InitList(L);
    int e;
    LNode *s,*r=L;
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode *) malloc(sizeof(LNode));
        s->data=e;
        r->next=s;
        r=s;  //��r��ֵ����ǰ��β
    }
    r->next=L;
    L=r;            //���µ�ǰ��βָ��
    return L;
}

//ͷ�巨����ͷ�ڵ�
LinkList List_HeadInsert(LinkList *L){
    printf("\n��ʼͷ�巨����ѭ��������\n");
    InitList(L);
    int e;
    LNode *s,*r=L;
    bool isFirst=true;
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=e;
        s->next=(*L)->next;
        (*L)->next=s;
        if(isFirst){
            r=s;
            isFirst=false;
        }
    }
    r->next=L;
    L=r;
    return r;
}

//�ж��Ƿ��ǿձ�
bool Empty(LinkList L){
    if(L->next==L){
        return true;
    }
    return false;
}

//�ж��Ƿ��Ǳ�β�ڵ�
bool isTail(LinkList L,LNode *p){
    if(p==L){
        return true;
    }
    return false;
}

//��������е�����
void printList(LinkList L){
    LNode *s=L->next->next;
    while (s!=L->next){
        printf("%d",s->data);
        s=s->next;
    }
    printf("�����������");
}


int main(){
    printf("ѭ��������--��ͷ�ڵ�--Lָ���β--��ʼ");
    return 0;
}

