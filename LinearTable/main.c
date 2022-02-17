//
// Created by 47244 on 2022/2/16.
//
#include "LinearTable.c"
#include "examination_question.c"

void main()
{
    SqList list1;
    printf("初始化线性表list1 start");
    if (InitList(&list1)) printf("初始化成功");
    else printf("初始化失败");

    InPut(&list1, 5);
    //for (int i = 0; i <= 20; i++) if(ListInstert(&list1, i, (int)(rand()%100+1))) printf("插入成功\n");//插入随机数据
    for (int i = 0; i <= 20; i++) if(ListInstert(&list1, i, i)) printf("插入成功\n");//插入有序数据
    ElemType update = 16;
    UpdateElem(&list1, 15,&update);
    ElemType s = 30;
    ElemType t = 50;
    Del_same(&list1);
    printf("表长：%d", Length(&list1));
    OutPut(&list1);
    //printf("经过删除后的数据为：");
    //Del_s_t2(&list1,s,t); //2.2.3 线性表试题应用题 第四题
    //Del_s_t(&list1, s, t);//2.2.3 线性表试题应用题 第五题
    //OutPut(&list1);
}