//
// Created by 47244 on 2022/2/16.
//
#include "LinearTable.c"
#include "examination_question.c"

void main()
{
    SqList list1;
    printf("��ʼ�����Ա�list1 start");
    if (InitList(&list1)) printf("��ʼ���ɹ�");
    else printf("��ʼ��ʧ��");

    InPut(&list1, 5);
    //for (int i = 0; i <= 20; i++) if(ListInstert(&list1, i, (int)(rand()%100+1))) printf("����ɹ�\n");//�����������
    for (int i = 0; i <= 20; i++) if(ListInstert(&list1, i, i)) printf("����ɹ�\n");//������������
    ElemType update = 16;
    UpdateElem(&list1, 15,&update);
    ElemType s = 30;
    ElemType t = 50;
    Del_same(&list1);
    printf("����%d", Length(&list1));
    OutPut(&list1);
    //printf("����ɾ���������Ϊ��");
    //Del_s_t2(&list1,s,t); //2.2.3 ���Ա�����Ӧ���� ������
    //Del_s_t(&list1, s, t);//2.2.3 ���Ա�����Ӧ���� ������
    //OutPut(&list1);
}