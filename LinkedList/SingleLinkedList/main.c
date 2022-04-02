//
// Created by 47244 on 2022/1/22.
//
#ifndef _TEST_H_
#define _TEST_H_

#include "SingleLinkedList.c"
#include "SingleLinkedList_head.c"

#endif

typedef int ElemType;

/*
void LinkedList_noHead_operation(){
    printf("\nLinkedList start\n");
    LinkListHead LH;
    ElemType e;
    int choice;
    int i;
    do {
        printf("1.ListInit(初始化)\t2.List_HeadInsert(头插法)\t3.List_TailInsert(尾插法)\n4.PrintList(输出表)\t5.GetLength(求表长)\t6.ListEmpty(表判空)\n7.Getelem(按位查)\t8.LocateElem(按值查)\t9.ListInsert(插入)\t0.ListDelete(删除元素)\n");
        printf("\n请输入你的选择：\n");
        scanf("%d",&choice);
        switch (choice) {
            system("cls");
            case -1:
                printf("感谢使用本系统，再见\n");
                break;
            case 1:
                if(ListInit_Head(&LH))
                    printf("Success\n");
                else{
                    printf("failed\n");
                }
                break;
            case 2:
                List_HeadInsert_NOHead(&LH);
                break;
            case 3:
                List_TailInsert_NoHead(&LH);
                break;
            case 4:
                PrintList_Head(LH);
                break;
            case 5:
                printf("链表长度为：%d\n", GetLength_NLinkList(LH));
                break;
            case 6:
                if(List_HeadEmpty(LH)){
                    printf("空表\n");
                } else{
                    printf("表不为空\n");
                }
                break;
            case 7:
                printf("请输入需要查询的位数：");
                scanf("%d",&i);
                printf("第%d位数据为：%d",i, GetElem_NoHead(LH,i)->data);
                printf("\n");
                break;
            case 8:
                printf("请输入需要查询的值：");
                scanf("%d",&e);
                Node *node=LocalElem_NoHead(LH,e);
                printf("值为%d，指针为%d",node->data,node->next);
                break;
            case 9:
                printf("\n请输入需要插入的位数：");
                scanf("%d",&i);
                printf("\n请输入需要插入的数据：");
                scanf("%d",&e);
                if(ListInsert_NoHead(&LH,i,e)){
                    printf("插入成功");
                } else{
                    printf("插入失败,请检查输入");
                }
                break;
            case 0:
                printf("请输入需要删除的位序：");
                scanf("%d",&i);
                if(ListDel_NoHead(&LH,i,&e)){
                    printf("删除成功\n");
                } else{
                    printf("删除失败\n");
                }
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
                system("pause");
        }
    } while (choice!=-1);
}
*/


void SingleLinkList_head_operation(){
    printf("LinkedList_head start\n");
    LinkList L;
    int choice;
    LNode *p;
    int i;
    ElemType e;
    do {
        printf("1.ListInit(初始化)\t2.List_HeadInsert(头插法)\t3.List_TailInsert(尾插法)\n4.PrintList(输出表)\t5.GetLength(求表长)\t6.ListEmpty(表判空)\n7.Getelem(按位查)\t8.LocateElem(按值查)\t9.ListInsert(插入)\t0.ListDelete(删除元素)\n");
        printf("\n请输入你的选择:\n");
        scanf("%d",&choice);
        switch (choice) {
            case -1:
                printf("感谢使用本系统，再见\n");
                break;
            case 1:
                if(ListInit(&L))
                    printf("Success\n");
                else
                    printf("failed\n");
                break;
            case 2:
                List_HeadInsert(&L);//采用头插法创建链表
                break;
            case 3:
                List_TailInsert(&L);
                printf("\n");
                break;
            case 4:
                PrintList(L);//输出链表
                printf("\n");
                break;
            case 5:
                printf("链表表长位：%d\n", GetLength(L));
                break;
            case 6:
                if(ListEmpty(L)){
                    printf("空表\n");
                } else{
                    printf("表不为空\n");
                }
                break;
            case 7:
                printf("请输入需要查询的位数：");
                scanf("%d",&i);
                p=GetElem(L,i);
                printf("结果为：%d\n",p->data);
                break;
            case 8:
                printf("请输入需要查询的值：");
                scanf("%d",&e);
                p=LocateElem(L,e);
                printf("44");
                printf("p的值位%d",p->next);
                break;
            case 9:
                scanf("请输入需要插入的位置%d\n",&i);
                scanf("请输入插入的数据%d\n",&e);
                if(ListInsert(&L,i,e)){
                    printf("插入成功\n");
                } else{
                    printf("插入失败，请检查插入的数据或位置是否合法\n");
                }
                break;
            case 0:
                scanf("请输入需要删除的节点位序：%d",&i);
                if(ListDelete(&L,i,&e)){
                    printf("\n删除成功\n");
                } else{
                    printf("\n删除失败\n");
                }
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (choice!=-1);
}

void  main(){
    int mainChoice;
    do {
        printf("\n欢迎使用本系统，请选择需要进行的操作\n0：带头结点单链表操作\t1：不带头结点单链表操作\n");
        printf("\n请输入你的选择\n");
        scanf("%d",&mainChoice);
        switch (mainChoice) {
            system("cls");
            case -1:
                printf("感谢使用本系统，再见\n");
                break;
            case 0:
                SingleLinkList_head_operation();
                break;
            case 1:
//                LinkedList_noHead_operation();
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
                system("pause");
        }
    } while (mainChoice!=-1);
}
