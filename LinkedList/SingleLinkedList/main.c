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
        printf("1.ListInit(��ʼ��)\t2.List_HeadInsert(ͷ�巨)\t3.List_TailInsert(β�巨)\n4.PrintList(�����)\t5.GetLength(���)\t6.ListEmpty(���п�)\n7.Getelem(��λ��)\t8.LocateElem(��ֵ��)\t9.ListInsert(����)\t0.ListDelete(ɾ��Ԫ��)\n");
        printf("\n���������ѡ��\n");
        scanf("%d",&choice);
        switch (choice) {
            system("cls");
            case -1:
                printf("��лʹ�ñ�ϵͳ���ټ�\n");
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
                printf("������Ϊ��%d\n", GetLength_NLinkList(LH));
                break;
            case 6:
                if(List_HeadEmpty(LH)){
                    printf("�ձ�\n");
                } else{
                    printf("��Ϊ��\n");
                }
                break;
            case 7:
                printf("��������Ҫ��ѯ��λ����");
                scanf("%d",&i);
                printf("��%dλ����Ϊ��%d",i, GetElem_NoHead(LH,i)->data);
                printf("\n");
                break;
            case 8:
                printf("��������Ҫ��ѯ��ֵ��");
                scanf("%d",&e);
                Node *node=LocalElem_NoHead(LH,e);
                printf("ֵΪ%d��ָ��Ϊ%d",node->data,node->next);
                break;
            case 9:
                printf("\n��������Ҫ�����λ����");
                scanf("%d",&i);
                printf("\n��������Ҫ��������ݣ�");
                scanf("%d",&e);
                if(ListInsert_NoHead(&LH,i,e)){
                    printf("����ɹ�");
                } else{
                    printf("����ʧ��,��������");
                }
                break;
            case 0:
                printf("��������Ҫɾ����λ��");
                scanf("%d",&i);
                if(ListDel_NoHead(&LH,i,&e)){
                    printf("ɾ���ɹ�\n");
                } else{
                    printf("ɾ��ʧ��\n");
                }
                break;
            default:
                printf("�����������������\n");
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
        printf("1.ListInit(��ʼ��)\t2.List_HeadInsert(ͷ�巨)\t3.List_TailInsert(β�巨)\n4.PrintList(�����)\t5.GetLength(���)\t6.ListEmpty(���п�)\n7.Getelem(��λ��)\t8.LocateElem(��ֵ��)\t9.ListInsert(����)\t0.ListDelete(ɾ��Ԫ��)\n");
        printf("\n���������ѡ��:\n");
        scanf("%d",&choice);
        switch (choice) {
            case -1:
                printf("��лʹ�ñ�ϵͳ���ټ�\n");
                break;
            case 1:
                if(ListInit(&L))
                    printf("Success\n");
                else
                    printf("failed\n");
                break;
            case 2:
                List_HeadInsert(&L);//����ͷ�巨��������
                break;
            case 3:
                List_TailInsert(&L);
                printf("\n");
                break;
            case 4:
                PrintList(L);//�������
                printf("\n");
                break;
            case 5:
                printf("�����λ��%d\n", GetLength(L));
                break;
            case 6:
                if(ListEmpty(L)){
                    printf("�ձ�\n");
                } else{
                    printf("��Ϊ��\n");
                }
                break;
            case 7:
                printf("��������Ҫ��ѯ��λ����");
                scanf("%d",&i);
                p=GetElem(L,i);
                printf("���Ϊ��%d\n",p->data);
                break;
            case 8:
                printf("��������Ҫ��ѯ��ֵ��");
                scanf("%d",&e);
                p=LocateElem(L,e);
                printf("44");
                printf("p��ֵλ%d",p->next);
                break;
            case 9:
                scanf("��������Ҫ�����λ��%d\n",&i);
                scanf("��������������%d\n",&e);
                if(ListInsert(&L,i,e)){
                    printf("����ɹ�\n");
                } else{
                    printf("����ʧ�ܣ������������ݻ�λ���Ƿ�Ϸ�\n");
                }
                break;
            case 0:
                scanf("��������Ҫɾ���Ľڵ�λ��%d",&i);
                if(ListDelete(&L,i,&e)){
                    printf("\nɾ���ɹ�\n");
                } else{
                    printf("\nɾ��ʧ��\n");
                }
                break;
            default:
                printf("�����������������\n");
                break;
        }
    } while (choice!=-1);
}

void  main(){
    int mainChoice;
    do {
        printf("\n��ӭʹ�ñ�ϵͳ����ѡ����Ҫ���еĲ���\n0����ͷ��㵥�������\t1������ͷ��㵥�������\n");
        printf("\n���������ѡ��\n");
        scanf("%d",&mainChoice);
        switch (mainChoice) {
            system("cls");
            case -1:
                printf("��лʹ�ñ�ϵͳ���ټ�\n");
                break;
            case 0:
                SingleLinkList_head_operation();
                break;
            case 1:
//                LinkedList_noHead_operation();
                break;
            default:
                printf("�����������������\n");
                break;
                system("pause");
        }
    } while (mainChoice!=-1);
}
