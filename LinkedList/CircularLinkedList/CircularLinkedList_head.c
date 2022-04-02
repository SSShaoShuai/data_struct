//
// Created by 47244 on 2022/2/16.
// ѭ�������� Lָ���ͷ
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,* LinkList;

//struct LNode* �ȼ� LinkList
//ǿ���ڵ� LNode
//ǿ������ LinkList

//��ʼ������
bool InitList(LinkList *L){
    *L=(LNode *)malloc(sizeof (LNode));
    if (*L==NULL) return false;
    (*L)->next=L;
    return true;
}

//��λ���ң����ص�i��Ԫ�أ���ͷ�ڵ㣩
LNode * GetELem(LinkList L,int i){
    if(i<0) return NULL;
    if (i==0) return L;
    int j=1;
    LNode *p=L->next;   //��ͷ�ڵ㣬��һ��Ԫ��û�����ݣ�����
    while (p!=L && j<i){
        p=p->next;
        j++;
    }
    return p;
}

//��ֵ���ң��ҵ����������e�ڽڵ�
LNode * LocateElem(LinkList L,int e){
    LNode *p=L->next;
    while (p != L && p->data!=e){
        p=p->next;
    }
    if(p->data==e) return p;
    return NULL;
}

//��������
int Length(LinkList L){
    int len=0;
    LNode *p=L;
    while (p!=L){
        len ++;
        p=p->next;
    }
    return len;
}

//���������ڽڵ�p֮�����Ԫ��e
bool InsertNextNode(LNode *p,int e){
    if(!p)return false;
    LNode *s=(LNode *) malloc(sizeof (LNode));
    if(!s)return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//  ��ͷ�ڵ�Ĳ���������ڵ�i��λ�ò���Ԫ��e
bool ListInsert(LinkList *L,int i,int e){
    if(i<1) return false;
    LNode *p=GetELem(L,i-1);//�ҵ���i��λ�õ�ǰ�ýڵ�
    if(!p)return false;
    return InsertNextNode(p,e);//���غ������ķ���ֵ
}

//ǰ���������p�ڵ�֮ǰ����Ԫ��e   ǰ��Ԫ��
bool InsertPriorData(LNode *p,int e){
    if(!p)return  false;
    LNode *s=(LNode*) malloc(sizeof(LNode));
    if(!s) return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//  ǰ���������p�ڵ�֮ǰ����ڵ�s  ǰ��ڵ�
bool InsertPriorNode(LNode *p,LNode *s){
    if (!p || !s)return false;
    int i=s->data;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=i;
    return true;
}

//ɾ��λ��i�Ľڵ㣬e�ǽڵ��ֵ  ��λ��ɾ���ڵ�
bool ListDelete(LinkList *L,int i,int *e){
    if(i<1)return false;
    LNode *p= GetELem(L,i-1);//iΪλ����Ϊ�ǵ���������Ӧ�ö�λ��ɾ���ڵ��ǰ���ڵ㣬�Ա����
    if(p==NULL || p->next==NULL) return false;  //pΪNULL��ʾ����Ϊ�գ���Ϊ��ѭ����������p�ĺ�̽ڵ�Ϊ�գ�����ҲΪ��
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;

}

//ɾ��ָ���ڵ�p  --ɾ���ڵ�
bool DeleteNode(LinkList*L,LNode *p){
    LNode *q=p->next;
    p->data=q->data;
    p->next=q->next;
    if(L==q){
        L=p;
    }
    free(q);
    return true;
}

//β�巨����ͷ�ڵ�
LinkList List_TailInsert(LinkList *L){
    printf("\n��ʼβ�巨����ѭ��������\n");
    InitList(*L);
    int e;
    LNode *s, *r=L;  //r��ʾβָ��
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode*) malloc(sizeof(LNode));
        s->data=e;
        r->next=s;
        r=s;
    }
    r->next=L;
    return L;
}

//ͷ�巨����ͷ�ڵ�
LinkList List_HeadInsert(LinkList *L){
    printf("%d","\n��ʼͷ�巨����ѭ��������\n");
    InitList(*L);
    int e;
    LNode *s,*r=L;   //r��ʾβָ��
    bool isFirst=true;
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode *) malloc(sizeof(LNode));
        s->data=s;
        s->next=(*L)->next;
        (*L)->next=s;
        if (isFirst){
            r=s;//��һ����������ݼ�Ϊβ�ڵ㣬��β�ڵ㸳ֵ��r֮��isFirst��ֵ��Ϊfalse
            isFirst=false;
        }
    }
    r->next=L;  //��Ϊ��ѭ���������Խ�r�ĺ��ָ��ֻ��L
    return L;
}

//�ж��Ƿ��ǿձ�
bool Empty(LinkList L){
    if (L->next==NULL){
        return true;
    }
    return false;
}

//�ж��Ƿ�Ϊ��β�ڵ�
bool isTail(LinkList L,LNode *p){
    if (p->next==L){
        return true;
    }
    return false;
}


//��ӡ����������
void printList(LinkList L){
    LNode *s=L->next;
    while (s->next!=L){
        printf("%d",s->data);
        s=s->next;
    }
    printf("�����������");
}

int main(){
    printf("ѭ��������--��ͷ�ڵ�--��ʼ");
    return 0;
}







