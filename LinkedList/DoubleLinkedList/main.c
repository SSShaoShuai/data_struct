//
// Created by 47244 on 2022/2/15.
//
#include "DoubleLinkedList.c"

void main(){
    printf("DoubleLinkedList --Start\n");
    ElemType e;
    DLinkList L;//带头结点双链表
    int firstChoice,i,secondChoice;//firstchoice 为第一层选择，0：带头结点双链表 1：不带头结点双链表 -1：退出
    DListInit_WithHead(&L);
    DList_TailInsert(&L);
    printf("\n表长为：%d", DList_Length(L));
    InsertDNode_Order(L,3,3);
    print_DList(L);
    printf("\n表长为：%d", DList_Length(L));



    /*scanf("%d",&firstChoice);
    if(firstChoice==0){
        do{
            printf("1.ListInit(初始化)\t2.List_HeadInsert(头插法)\t3.List_TailInsert(尾插法)\n4.PrintList(输出表)\t5.GetLength(求表长)\t6.ListEmpty(表判空)\n7.Getelem(按位查)\t8.LocateElem(按值查)\t9.ListInsert(插入)\t0.ListDelete(删除元素)\n");

        } while (secondChoice!=-1)
    } else if(firstChoice==1){

    } else{
        printf("...")
    }*/
}
