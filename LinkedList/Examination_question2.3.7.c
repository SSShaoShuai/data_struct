//
// Created by ������ on 2022/4/3.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

/*---------------------------------����ͷ�ڵ㵥����---------------------------------*/
typedef struct Node1 {
    int data;
    struct Node1 *next;
} Node1, LinkListNoHead;

bool InitSListNH(LinkListNoHead *L) {
    L = NULL;
    return true;
}

//��������ͷ�ڵ�ĵ�����
LinkListNoHead *CreateSListNH() {
    LinkListNoHead *p;
    p = (LinkListNoHead *) malloc(sizeof(LinkListNoHead));
    LinkListNoHead *tmp = p;
    int i;
    //��������
    for (i = 1; i < 10; i++) {
        LinkListNoHead *a = (LinkListNoHead *) malloc(sizeof(LinkListNoHead));
        a->data = i;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
    }
    return p;
}

//�������
void PrintList_NoHead(LinkListNoHead *L) {
    printf("��ʼ�����������-����ͷ���\n");//����ͷ���ĵ�����L��Ϊ�������һλ
    Node1 *node = L;
    while (node != NULL) {
        printf("\n%d", node->data);
        node = node->next;
    }
    printf("\n����������\n");
}
/*---------------------------------����ͷ�ڵ㵥����---------------------------------*/


/*---------------------------------��ͷ�ڵ㵥����---------------------------------*/
// ��ͷ�ڵ㵥����ṹ����
typedef struct Node2 {
    ElemType data;
    struct Node2 *next;
} Node2, *LinkListWithHead;

//��ʼ��
LinkListWithHead InitSLinkWH() {
    LinkListWithHead L;
    L = (Node2 *) malloc(sizeof(Node2));
    if (L == NULL) return NULL;
    L->next = NULL;
    return L;
}

//β��
LinkListWithHead ListInsert_Tail_WH(LinkListWithHead L) {
    int x;
    L = (Node2 *) malloc(sizeof(Node2));
    Node2 *s, *r = L;
    L->next = NULL;
    scanf("%d", &x);
    while (x != 99) {
        s = (Node2 *) malloc(sizeof(Node2));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//�������
void Print_List_WH(LinkListWithHead L) {
    printf("\n");
    Node2 *p;
    p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkListWithHead Struct_List() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("List Insert Success\n");
    return L;
}

//��ȡ�������
int GetLengthWithHead(LinkListWithHead L) {
    Node2 *p;
    int count = 0;
    p = L->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
/*---------------------------------��ͷ�ڵ㵥����---------------------------------*/



/*-----------------��Ŀ--------------------*/
/*
 *@Title:��һ��
 *@Description: ���һ���ݹ��㷨��ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
 *@Operation:
 *@author: NSS
 *@date:2022/4/3
 **/
void Del_All_X(LinkListNoHead *L, int x) {
    Node1 *p;
    if (L->next == NULL)return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_All_X(L, x);
    }
    if (L->next->data == x) {
        p = L->next;
        L->next = L->next->next;
        free(p);
        Del_All_X(L, x);
    } else {
        Del_All_X(L->next, x);
    }
}

/*
 *@Title:�ڶ���
 *@Description:�ڴ�ͷ�ڵ�ĵ�������ɾ������ֵΪx�Ľڵ㣬���ͷ���ռ䣬����xֵ��Ψһ
 *@Operation:
 *@author: NSS
 *@date:2022/4/4
 **/
void Del_All_X_WH(LinkListWithHead L, int i) {
    Node2 *p;
    if (L->next == NULL)return;
    if (L->next->data == i) {
        p = L->next;
        L->next = L->next->next;
        free(p);
        Del_All_X_WH(L, i);
    } else {
        Del_All_X_WH(L->next, i);
    }
}

/*
 *@Title:������
 *@Description:��LΪ��ͷ�ڵ�ĵ�������д�㷨ʵ�ִ�β��ͷ�������ÿ���ڵ��ֵ
 *@Operation:
 *@author: NSS
 *@date:2022/4/4
 **/
void R_Print(LinkListWithHead L) {
    if (L->next != NULL) {
        R_Print(L->next);//�ݹ���ã�������ѹ��ݹ�ջ�����ý����󷵻ظ÷�����ִ�к����������
    }
    if (L != NULL)printf("data:%d", L->data);
}

void ReverseData(LinkListWithHead pNode2) {
    printf("\n");
    if (pNode2->next != NULL) {
        R_Print(pNode2->next);
    }
}

/*
 *@Title:������
 *@Description:��д�ڴ�ͷ���ĵ�������ɾ��һ����Сֵ�ĸ�Ч�㷨��������Сֵ���Ψһ��
 *@Operation:��p��ͷ��β��������preָ��p��ǰ����minp����ֵ��С�Ľڵ�ָ�룬minpreָ��minp��ǰ����һ��ɨ��һ�߱Ƚ�
 *           ��p->dataС��minp->data����p��pre�ֱ�ֵ��minp��minpre����pɨ������minpָ����Сֵ�ڵ�
 *@author: NSS
 *@date:2022/4/5
 **/
void fun4() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");


    Node2 *pre = L;
    Node2 *p = pre->next;
    Node2 *minp = p;
    Node2 *minpre = pre;

    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;     //�ҵ���ǰ����Сֵ��㣬����ֵ
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }//ѭ��������minpָ��ļ�Ϊ��Сֵ�ڵ�
    minpre->next = minp->next;
    free(minp);
    Print_List_WH(L);
    printf("Delete Min Finish");
}

/*
 *@Title:������
 *@Description:��д�㷨����ͷ�ڵ�ĵ�����͵����ã���ν"�͵�"��ָ�����ռ临�Ӷ�ΪO(1)
 *@Operation:��ͷ���ժ�£�Ȼ��ӵ�һ���ڵ㿪ʼ��һ�β��뵽ͷ���ĺ��棨ͷ�巨����������ֱ�����һ���ڵ�
 *@author: NSS
 *@date:2022/4/5
 **/
void fun_5() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");

    Node2 *p, *r;//����ָ�룬rΪp�ĺ�̣��Է�����
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    Print_List_WH(L);
    printf("Reverse Finish");
}

fun_5_2() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("\n");

    Node2 *pre, *p = L->next, *r = p->next;
    p->next = NULL;    //����һ���ڵ�ĺ���ÿ�
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre; //ָ�뷴ת
    }
    L->next = p;
    Print_List_WH(L);
    printf("Reverse Finish");
}

/*
 *@Title:������
 *@Description:��һ����ͷ�ڵ�ĵ�����L�����һ���㷨ʹ���������
 *@Operation:
 *@author: NSS
 *@date:2022/4/28
 **/
void func_6() {
    LinkListWithHead L;
    L = InitSLinkWH();
    printf("\nList Insert\n");
    L = ListInsert_Tail_WH(L);
    Print_List_WH(L);
    printf("List Insert success");

    //����һ��ֻ����һ�����ݽڵ����������
    Node2 *p = L->next, *pre;  //pΪ����ָ�룬preΪp��ǰ���ڵ�
    Node2 *r = p->next;   //����p֮����������ݣ���֤�����ݿ�ȡ
    p->next = NULL;       //ʹ��ǰ����ֻ��һ�����ݽڵ㣻��������p�ڵ����������
    p = r;    //��pָ��r����Ľڵ㣨��ʼΪ�������ڵ㣩

    while (p != NULL) {
        r = p->next;  //����p������������ݣ�ʹ��Ҫ�����������
        pre = L;
        //pΪ�ϴ�Ľڵ㣬pre�ǽ�С�Ľڵ�
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;  //pre�ǽ�С�Ľڵ�
        }
        //p�ڵ�ϴ󣬷���pre�ĺ���
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    printf("Sort Finish\n");
    Print_List_WH(L);
    free(L);
}


/*
 *@Title:
 *@Description: һ����ͷ�ڵ�ĵ������У�����Ԫ�ؽڵ���������㷨��ɾ���������н��ڸ���������ֵ֮���Ԫ��
 *@Operation:   ��ͷ��������������Ԫ�أ��жϺ����ɾ������
 *@author: NSS
 *@date:2022/4/29
 **/
void func_7(int min, int max) {
    LinkListWithHead L;
    L = Struct_List();

    Node2 *p = L->next;
    Node2 *pre = L;
    while (p != NULL) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
    printf("Execute Finish\n");
    Print_List_WH(L);
    printf("finish\n");
}

/*
 *@Title:�ڰ���
 *@Description: ������������������㷨�ҳ���������Ĺ����ڵ�
 *@Operation:       ��Ϊ���������������Թ����ڵ�֮������нڵ�Ӧ������ͬ�ģ������ǵ����һ���ڵ����غϵ�
 *                  ���ֻҪ�ҵ���һ���غϵĽڵ����Ľڵ�Ͷ����غϽڵ���
 *                  ����������ĳ��Ȳ�һ��һ�������賤����ȶ�����k���ڵ㣬����㷨���ó��������k���ڵ�
 *                  ֮����ͬ�����������ɱ�֤������ͬ���������ҵ��ĵ�һ����ͬ�ڵ���ǹ����ڵ�
 *@author: NSS
 *@date:2022/4/29
 **/
LinkListWithHead func_8(LinkListWithHead L1, LinkListWithHead L2) {
    //���㷨ʵ��������ʱ�����ҵ�����������ĵ�һ�������ڵ�
    int len1 = GetLengthWithHead(L1), len2 = GetLengthWithHead(L2);//����������ĳ��ȷֱ����
    LinkListWithHead longList, shortList;
    int dist;
    if (len1 > len2) {//�ж����������Ǹ���������ֵ���������֮��
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {//�Ƚ�������ָ�������������֮���λ��
        longList = longList->next;
    }
    while (longList != NULL) {//�жϵ�ǰ�ڵ��Ƿ��ǹ����ڵ�
        if(longList==shortList){
            return longList;//�ǹ����ڵ㣬����
        } else{//���ǽ�������ָ��ֱ����
            longList=longList->next;
            shortList=shortList->next;
        }
    }
    return NULL;
}

/*
 *@Title:�ھ���
 *@Description:��������������������и��ڵ������Ԫ�أ����ͷŽڵ���ռ�Ĵ洢�ռ�
 *@Operation:   ��������б�����ÿ�α����ҳ���Сֵ���ͷţ�һֱѭ����ֱ������Ϊ��
 *@author: NSS
 *@date:2022/4/29
 **/
void func_9(){
    LinkListWithHead L;
    L = Struct_List();

    while (L->next!=NULL){
        Node2 *pre=L;//preΪԪ����Сֵ�ڵ��ǰ���ڵ�
        Node2 *p=pre->next;//pΪ����ָ��
        while (p->next!=NULL){
            if(p->next->data<pre->next->data){
                pre=p;//����ǰ��Сֵ�ڵ��ǰ���ڵ���и�ֵ
            }
            p=p->next;
        }
        printf("%d ",pre->next->data);//����ڵ�����
        Node2 *u;
        u=pre->next;
        pre->next=u->next;
        free(u);//�ͷŽڵ�
    }
    free(L);//�ͷ�ͷָ��
}

/*
 *@Title:��ʮ��
 *@Description:��һ������ͷ�ڵ�ĵ�����A�ֽ�Ϊ������ͷ�ڵ�ĵ�����A��B��ʹA���к���ԭ�������Ϊ������Ԫ�أ�B���к���ԭ�������Ϊż����Ԫ�أ��������˳�򲻱�
 *@Operation:   ��Ʒ�����ű�����ÿ����һ���ڵ�����Զ���һ��Ȼ�������ŵ���ż�Խ��ڵ���뵽A���B���С��ظ�����ֱ����β
 *@author: NSS
 *@date:2022/4/29
 **/
void func_10(){
    LinkListWithHead A;
    A = Struct_List();

    int i=0;//iΪ������ű���
    LinkListWithHead B=(LinkListWithHead) malloc(sizeof (Node2));//����B���ͷ
    B->next=NULL;//B���ʼ��
    Node2 *ra=A,*rb=B,*p; //ra��rb�ֱ�ָ�򽫴�����A���B���β�ڵ�

    p=A->next;//pΪ������ָ�룬ָ����ֽ�Ľڵ�
    A->next=NULL;//��A���ÿ�
    while (p!=NULL){
        i++;
        if(i%2==0){//λ��Ϊż��������ڵ�
            rb->next=p;//��b��β�����½ڵ�
            rb=p;//��rbָ���µ�β�ڵ�
        } else{
            ra->next=p;//��A��β�����½ڵ�
            ra=p;
        }
        p=p->next;  //��p�ָ�Ϊָ���µĴ�����ڵ�
    }
    ra->next=NULL;
    rb->next=NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:��ʮһ��
 *@Description:��C={a1,b1,a2,b2,����,an,bn}Ϊ���Ա����ô�ͷ�ڵ��hc��������д�ţ����һ���͵��㷨��������Ϊ�������Ա�ʹ��A=={a1,a2,����,an},B=={bn,����,b2,b1}
 *@Operation:���õ�ʮ���˼·�������ǲ���Ҫ����ű�����B��Ľ���������β�巨
 *@author: NSS
 *@date:2022/4/29
 **/
void func_11(){
    LinkListWithHead A;
    A = Struct_List();

    LinkListWithHead B=(LinkListWithHead) malloc(sizeof (Node2));//����B���ͷ
    B->next=NULL;
    Node2 *p=A->next,*q;
    Node2 *ra=A;
    while (p!=NULL){
        ra->next=p;
        ra=p;
        p=p->next;
        if(p!=NULL){
            q=p->next;
            p->next=B->next;
            B->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

int main() {

/*--------------------����ͷ�ڵ�ĵ����������Ŀ--------------------*/
    /*LinkListNoHead *L;
    InitSListNH(L);
    L=CreateSListNH();
    PrintList_NoHead(L);
    Del_All_X(L,2);//��һ��
    printf("ɾ����");
    PrintList_NoHead(L);*/

/*--------------------��ͷ�ڵ�ĵ����������Ŀ--------------------*/
//    LinkListWithHead L;
//    L = ListInsert_Tail_WH(L);
//    Print_List_WH(L);
//    ReverseData(L);//������
//    Del_All_X_WH(L,2);�ڶ���
//    fun4();//������
//    fun_5_2();
//    func_6();
//    func_7(3, 9);
//    func_9();
//    func_10();
    func_11();
    return 0;
}


