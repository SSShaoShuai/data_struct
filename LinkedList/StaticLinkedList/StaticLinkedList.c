//
// Created by 倪先生 on 2022/3/30.
//

/*静态链表*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct {
    ElemType data;
    int next;
}SLinkList[MaxSize];

//初始化静态链表
void  InitSLinkList(SLinkList L){
    for (int i=0;i<MaxSize;i++){
        L[i].next=-2;   //-2表示链表这个位置是空的
    }
    L[0].next=-1;
}

//判断静态链表是否为空
bool Empty(SLinkList L){
    if(L[0].next=-1){
        return true;
    }
    return false;
}

//得到第i个元素第下标
int Get_Index(SLinkList L,int i){
    int j=0;  //模拟指针
    int cnt=0;   //计数
    while (j!=-1 && cnt<i){
        cnt++;
        j=L[j].next;
    }
    if(cnt!=i) return -1;  //不存在
    return j;
}

//得到第一个空元素
int Get_First_Empty_Node(SLinkList L){
    for (int i = 1; i <MaxSize ; i++) {
        if(L[i].next==-2) return i;
    }
}

//返回L的第i个元素的值
ElemType GetElem(SLinkList L,int i){
    int j= Get_Index(L,i);
    return L[j].data;
}

//在第i个节点后面插入值是e第节点
bool InsertNextSNode(SLinkList L,int i,ElemType e){
    int j= Get_Index(L,i);
    int k=0;
    for (int i=1;i<MaxSize;i++){
        if(L[i].next==-2){
            k=i;
            break;
        }
    }
    L[k].next=L[j].next;
    L[j].next=k;
    L[k].data=e;
    return true;
}

//删除第i个节点 e是删除元素的值
/*如果删除最后一个节点，则将该节点的next值设为-2，将该节点的前置节点的next值设为-1*/
/*如果是中间节点，则将需要删除的节点的值赋值为该节点的后继节点的值，并将该后置节点的next域值设为-2*/
bool DeleteNode(SLinkList L,int i,ElemType *e){
    int j= Get_Index(L,i);
    if(L[j].next==-1){      //最后一个特殊处理
        int k= Get_Index(L,i-1);
        L[j].next=-2;
        e=L[j].data;
        L[k].next=-1;
        return true;
    }
    //相当于交换次序
    e=L[j].data;
    int tmp=L[L[j].next].data;
    L[j].data=L[L[j].next].next;
    L[tmp].next=-2;
    return true;
}

//插入(默认开始是空的)
bool List_Insert(SLinkList L){
    int tot=1,pre=0;
    ElemType x;
    scanf("%d",&x);
    while (x!=9999){
        L[tot].data=x;
        L[tot].next=-1;
        L[pre].next=tot;
        pre=tot++;
    }
    return true;
}

void Print_List(SLinkList L){
    int i=L[0].next;
    while (i>0){
        printf("%d",L[i].data);
        i=L[i].next;
    }
    printf("输出链表结束");
}

void testSLinkList(){

}
