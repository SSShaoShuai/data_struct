//
// Created by 倪先生 on 2022/3/30.
//
/*
 * 循环单链表--L指向表尾
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>


/*定义链表结构*/
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode ,*LinkList;

//struct LNode* 等价 LinkList
//强调节点 LNode
//强调链表 LinkList

//初始化链表
bool InitList(LinkList *L){
    *L=(LNode *) malloc(sizeof(LNode));
    if(*L==NULL) return false;
    (*L)->next=L;
    return true;
}

/*按位查找，返回第i个元素（带头节点）*/
LNode * GetElem(LinkList L,int i){
    if (i<0) return false;
    if(i==0) return L->next;
    int j=1;
    LNode *p=L->next->next;
    while (p!=L->next && j<i){
        p=p->next;
        j++;
    }
    if(p==L->next) return NULL;  //判断是否是表头
    return p;
}

//按值查找，找到数据域等于e的节点
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

//求链表表长
int Length(LinkList L){
    int len=0;
    LNode *p=L;
    while (p->next!=L){
        len++;
        p=p->next;
    }
    return len;
}

//后插操作，在节点p之后插入元素e
bool InsertNextNode(LinkList *L,LNode *p,int e){
    if(!p) return false;
    LNode *s=(LNode*) malloc(sizeof(LNode));
    if(!s) return false;
    s->data=e;
    s->next=p->next;
    p->next=s;
    if(p==L) L=s;   //判断插入的位置是否是表尾之后，是则将L指向当前表尾节点
    return true;
}

//带头节点的插入操作，在第i个位置插入元素e
bool ListInsert(LinkList *L,int i,int e){
    if(i<1)return false;
    LNode *p= GetElem(L,i-1);//找到第i个位置第前置节点
    if(!p)return false;
    return InsertNextNode(L,p,e);
}

//前插操作，在p节点之前插入元素e   前插元素
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

//前插操作，在p节点之前插入节点s  前插节点
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

//删除位序i的节点，e是节点的值   --按位序删除节点
bool ListDelete(LinkList *L,int i,int *e){
    if(i<1)return false;
    LNode *p= GetElem(L,i-1);//找到需要删除的节点的前置节点
    if(p==NULL || p==L)return false;
    if(p->next==L) L=p;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

//删除指定节点p  --删除节点
bool DeleteNode(LinkList *L,LNode *p){
    LNode *q=p->next;
    p->data=q->data;
    p->next=q->next;
    /*若当前删除的节点为表尾，经过上面赋值后p当前为表头
     *需要将L指向p的前置节点，更新当前表尾的指向
     * */
    if(L==p){       //尾节点单独处理
        q=p;
        while (q->next!=p){
            q=q->next;
        }
        L=q;
    }
    //free(q);   此时不能执行该操作，因为当前q和表尾指向的是同一个内存空间，若执行则链表就断了
    return true;
}

//尾插法，带头节点
LinkList List_TailInsert(LinkList *L){
    printf("\n开始尾插法建立循环单链表\n");
    InitList(L);
    int e;
    LNode *s,*r=L;
    scanf("%d",&e);
    while (e!=9999){
        s=(LNode *) malloc(sizeof(LNode));
        s->data=e;
        r->next=s;
        r=s;  //将r赋值给当前表尾
    }
    r->next=L;
    L=r;            //更新当前表尾指向
    return L;
}

//头插法，带头节点
LinkList List_HeadInsert(LinkList *L){
    printf("\n开始头插法建立循环单链表\n");
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

//判断是否是空表
bool Empty(LinkList L){
    if(L->next==L){
        return true;
    }
    return false;
}

//判断是否是表尾节点
bool isTail(LinkList L,LNode *p){
    if(p==L){
        return true;
    }
    return false;
}

//输出链表中的数据
void printList(LinkList L){
    LNode *s=L->next->next;
    while (s!=L->next){
        printf("%d",s->data);
        s=s->next;
    }
    printf("链表输出结束");
}


int main(){
    printf("循环单链表--带头节点--L指向表尾--开始");
    return 0;
}

