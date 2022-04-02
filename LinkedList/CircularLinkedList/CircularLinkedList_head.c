//
// Created by 47244 on 2022/2/16.
// 循环单链表 L指向表头
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,* LinkList;

//struct LNode* 等价 LinkList
//强调节点 LNode
//强调链表 LinkList

//初始化链表
bool InitList(LinkList *L){
    *L=(LNode *)malloc(sizeof (LNode));
    if (*L==NULL) return false;
    (*L)->next=L;
    return true;
}

//按位查找，返回第i个元素（带头节点）
LNode * GetELem(LinkList L,int i){
    if(i<0) return NULL;
    if (i==0) return L;
    int j=1;
    LNode *p=L->next;   //有头节点，第一个元素没有数据，跳过
    while (p!=L && j<i){
        p=p->next;
        j++;
    }
    return p;
}

//按值查找，找到数据域等于e第节点
LNode * LocateElem(LinkList L,int e){
    LNode *p=L->next;
    while (p != L && p->data!=e){
        p=p->next;
    }
    if(p->data==e) return p;
    return NULL;
}

//求链表长度
int Length(LinkList L){
    int len=0;
    LNode *p=L;
    while (p!=L){
        len ++;
        p=p->next;
    }
    return len;
}

//后插操作，在节点p之后插入元素e
bool InsertNextNode(LNode *p,int e){
    if(!p)return false;
    LNode *s=(LNode *) malloc(sizeof (LNode));
    if(!s)return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//  带头节点的插入操作，在第i个位置插入元素e
bool ListInsert(LinkList *L,int i,int e){
    if(i<1) return false;
    LNode *p=GetELem(L,i-1);//找到第i个位置的前置节点
    if(!p)return false;
    return InsertNextNode(p,e);//返回后插操作的返回值
}

//前插操作，在p节点之前插入元素e   前插元素
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

//  前插操作，在p节点之前插入节点s  前插节点
bool InsertPriorNode(LNode *p,LNode *s){
    if (!p || !s)return false;
    int i=s->data;
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=i;
    return true;
}

//删除位序i的节点，e是节点的值  按位序删除节点
bool ListDelete(LinkList *L,int i,int *e){
    if(i<1)return false;
    LNode *p= GetELem(L,i-1);//i为位序，因为是单链表，所以应该定位到删除节点的前驱节点，以便操作
    if(p==NULL || p->next==NULL) return false;  //p为NULL表示链表为空，因为是循环链表，所以p的后继节点为空，链表也为空
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;

}

//删除指定节点p  --删除节点
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

//尾插法，带头节点
LinkList List_TailInsert(LinkList *L){
    printf("\n开始尾插法建立循环单链表\n");
    InitList(*L);
    int e;
    LNode *s, *r=L;  //r表示尾指针
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

//头插法，带头节点
LinkList List_HeadInsert(LinkList *L){
    printf("%d","\n开始头插法建立循环单链表\n");
    InitList(*L);
    int e;
    LNode *s,*r=L;   //r表示尾指针
    bool isFirst=true;
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode *) malloc(sizeof(LNode));
        s->data=s;
        s->next=(*L)->next;
        (*L)->next=s;
        if (isFirst){
            r=s;//第一个插入的数据即为尾节点，将尾节点赋值给r之后将isFirst的值改为false
            isFirst=false;
        }
    }
    r->next=L;  //因为是循环链表，所以将r的后继指针只想L
    return L;
}

//判断是否是空表
bool Empty(LinkList L){
    if (L->next==NULL){
        return true;
    }
    return false;
}

//判断是否为表尾节点
bool isTail(LinkList L,LNode *p){
    if (p->next==L){
        return true;
    }
    return false;
}


//打印链表中数据
void printList(LinkList L){
    LNode *s=L->next;
    while (s->next!=L){
        printf("%d",s->data);
        s=s->next;
    }
    printf("链表输出结束");
}

int main(){
    printf("循环单链表--带头节点--开始");
    return 0;
}







