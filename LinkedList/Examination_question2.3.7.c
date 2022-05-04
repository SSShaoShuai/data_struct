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
} Node1, *LinkListNoHead;

bool InitSListNH(LinkListNoHead L) {
    L = NULL;
    return true;
}

//��������ͷ�ڵ�ĵ�����
LinkListNoHead CreateSListNH(LinkListNoHead p) {
    p = (Node1 *) malloc(sizeof(Node1));
    Node1 *tmp = p;
    int x;
    scanf("%d", &x);
    while (x != 99) {
        Node1 *a = (Node1 *) malloc(sizeof(Node1));
        a->data = x;
        a->next = NULL;
        tmp->next = a;
        tmp = tmp->next;
        scanf("%d", &x);
    }
    return p;
}

//�������
void PrintList_NoHead(LinkListNoHead L) {
    printf("��ʼ�����������-����ͷ���\n");//����ͷ���ĵ�����L��Ϊ�������һλ
    Node1 *node = L;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n����������\n");
}

//��������ͷ�ڵ㵥����
LinkListNoHead Struct_List_NH(){
    printf("Start Create\n");
    LinkListNoHead L;
    L=CreateSListNH(L);
    printf("Print List: ");
    PrintList_NoHead(L);
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

/*---------------------------------˫ѭ������---------------------------------*/
//˫ѭ������ṹ
typedef struct DNode1 {
    ElemType data;
    struct DNode1 *prior, *next;
} DNode1, *DoubleLinkList;

/*---------------------------------˫ѭ������---------------------------------*/



/*---------------------------------��ѭ������---------------------------------*/
//��ѭ������ṹ
typedef struct LNode1{
    int data;
    struct LNode1 *next;
}LNode1,* CLinkList1;

/*---------------------------------��ѭ������---------------------------------*/

/*---------------------------------˫��ѭ������---------------------------------*/
typedef struct DNode2{
    int data;
    struct DNode2 *pred;
    struct DNode2 *next;
    int freq;
}DNode2,* DLinkList2;
/*---------------------------------˫��ѭ������---------------------------------*/




/*-----------------��Ŀ--------------------*/
/*
 *@Title:��һ��
 *@Description: ���һ���ݹ��㷨��ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
 *@Operation:
 *@author: NSS
 *@date:2022/4/3
 **/
void Del_All_X(LinkListNoHead L, int x) {
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

void fun_5_2() {
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
        if (longList == shortList) {
            return longList;//�ǹ����ڵ㣬����
        } else {//���ǽ�������ָ��ֱ����
            longList = longList->next;
            shortList = shortList->next;
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
void func_9() {
    LinkListWithHead L;
    L = Struct_List();

    while (L->next != NULL) {
        Node2 *pre = L;//preΪԪ����Сֵ�ڵ��ǰ���ڵ�
        Node2 *p = pre->next;//pΪ����ָ��
        while (p->next != NULL) {
            if (p->next->data < pre->next->data) {
                pre = p;//����ǰ��Сֵ�ڵ��ǰ���ڵ���и�ֵ
            }
            p = p->next;
        }
        printf("%d ", pre->next->data);//����ڵ�����
        Node2 *u;
        u = pre->next;
        pre->next = u->next;
        free(u);//�ͷŽڵ�
    }
    free(L);//�ͷ�ͷָ��
}

/*
 *@Title:��ʮ��
 *@Description:��һ������ͷ�ڵ�ĵ�����A�ֽ�Ϊ������ͷ�ڵ�ĵ�����A��B��ʹA���к���ԭ�������Ϊ������Ԫ�أ�
 *             B���к���ԭ�������Ϊż����Ԫ�أ��������˳�򲻱�
 *@Operation:   ��Ʒ�����ű�����ÿ����һ���ڵ�����Զ���һ��Ȼ�������ŵ���ż�Խ��ڵ���뵽A���B���С��ظ�����ֱ����β
 *@author: NSS
 *@date:2022/4/29
 **/
void func_10() {
    LinkListWithHead A;
    A = Struct_List();

    int i = 0;//iΪ������ű���
    LinkListWithHead B = (LinkListWithHead) malloc(sizeof(Node2));//����B���ͷ
    B->next = NULL;//B���ʼ��
    Node2 *ra = A, *rb = B, *p; //ra��rb�ֱ�ָ�򽫴�����A���B���β�ڵ�

    p = A->next;//pΪ������ָ�룬ָ����ֽ�Ľڵ�
    A->next = NULL;//��A���ÿ�
    while (p != NULL) {
        i++;
        if (i % 2 == 0) {//λ��Ϊż��������ڵ�
            rb->next = p;//��b��β�����½ڵ�
            rb = p;//��rbָ���µ�β�ڵ�
        } else {
            ra->next = p;//��A��β�����½ڵ�
            ra = p;
        }
        p = p->next;  //��p�ָ�Ϊָ���µĴ�����ڵ�
    }
    ra->next = NULL;
    rb->next = NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:��ʮһ��
 *@Description:��C={a1,b1,a2,b2,����,an,bn}Ϊ���Ա����ô�ͷ�ڵ��hc��������д�ţ����һ���͵��㷨��������Ϊ�������Ա�
 *             ʹ��A=={a1,a2,����,an},B=={bn,����,b2,b1}
 *@Operation:���õ�ʮ���˼·�������ǲ���Ҫ����ű�����B��Ľ���������β�巨
 *@author: NSS
 *@date:2022/4/29
 **/
void func_11() {
    LinkListWithHead A;
    A = Struct_List();

    LinkListWithHead B = (LinkListWithHead) malloc(sizeof(Node2));//����B���ͷ
    B->next = NULL;   //��ʼ��B��
    Node2 *p = A->next, *q;  //pΪ����ָ��
    Node2 *ra = A;    //raʼ��ָ��A��β�ڵ�
    while (p != NULL) {
        ra->next = p;     //��p���ӵ�A�ı�β
        ra = p;
        p = p->next;
        if (p != NULL) {
            q = p->next;  //ͷ���p�������������q����p�ĺ�̣���֤������������
            p->next = B->next;    //��p���뵽B��ǰ��
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;      //Aβ�ڵ�ĺ���ÿ�
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:��ʮ����
 *@Description: ��һ��������������Ա�������ֵ��ͬ��Ԫ�ش��ڡ��洢��ʽΪ����������㷨ȥ����ֵ��ͬ��Ԫ��
 *@Operation:   ��Ϊ������������ظ�������Ϊ���ڽڵ㣬�������Ա������ڽڵ���ֵ�ظ���ɾ�����ߣ�����pָ�����һ����λ
 *@author: NSS
 *@date:2022/4/30
 **/
void func_12() {
    LinkListWithHead L;
    L = Struct_List();

    Node2 *p = L->next, *q;//pΪ����ָ�룬qΪp�ĺ�̣������ж��Ƿ��ظ�
    if (p == NULL) {
        return;
    }
    while (p->next != NULL) {
        q = p->next;//qָ��p�ĺ��
        if (p->data == q->data) {//�ж�p��q�Ƿ��ظ�
            p->next = q->next;//�ظ�����p�ĺ��ָ��p�ĺ�̵ĺ��
            free(q);//�ͷ�q
        } else {
            p = p->next;//����ͬpָ�����һ����λ
        }
    }
    printf("Execute Finish\n");
    Print_List_WH(L);
    printf("finish\n");
}

/*
 *@Title:��ʮ����
 *@Description:��������������������㷨������������鲢Ϊһ���ݼ���������Ҫ������ԭ���������Ա�Ľڵ���
 *@Operation:   ��Ϊ������������������ֻ��Ҫ��ͷ����������������Ƚϣ������ݽ�С�Ľڵ��ţ�ֱ��һ�����Ա������ɣ�
 *              ����һ�����Ա��Ԫ����ͷ�巨���β�����������
 *@author: NSS
 *@date:2022/4/30
 **/
void func_13() {
    printf("Init LA");
    LinkListWithHead LA;
    LA = Struct_List();
    printf("Init LB");
    LinkListWithHead LB;
    LB = Struct_List();

    Node2 *r, *pa = LA->next, *pb = LB->next;//pa��pb�ֱ���LA��LB�Ĺ���ָ��
    LA->next = NULL;  //��LA��ʼ��

    while (pa && pb) {     //������������Ϊ��ʱ����ѭ��
        if (pa->data < pb->data) {
            r = pa->next;     //r�ݴ�pa�ĺ�̽ڵ��ָ��
            pa->next = LA->next;
            LA->next = pa;    //��pa�ڵ����ӵ�������У�ͬʱ���ã�ʹ��ͷ�巨
            pa = r;           //�ָ�paΪ��ǰ���ȽϽڵ�
        } else {
            r = pb->next;     //r�ݴ�pb�ĺ�̽ڵ�ָ��
            pb->next = LA->next;
            LA->next = pb;    //��pb�ڵ����ӵ�������У�ͬʱ���ã�ʹ��ͷ�巨
            pb = r;           //�ָ�pbΪ��ǰ���ȽϽڵ�
        }
    }
    if (pa) {                //ѭ���������ж��Ƿ�������Ϊ�գ�����ʣ�µĲ���
        pb = pa;
    }
    while (pb) {
        r = pb->next;         //���β��뵽LA�У�ͷ�巨��
        pb->next = LA->next;
        LA->next = pb;
        pb = r;
    }
    free(LB);
    printf("print LA: ");
    Print_List_WH(LA);
}

/*
 *@Title:��ʮ����
 *@Description:A��B��������ͷ�ڵ�ĵ���������������㷨����A��B�еĹ���Ԫ�ز�������C��Ҫ���ƻ�AB�Ľڵ�
 *@Operation:   ��Ϊ�ǵ����������������ֱ��ͷ�������Ƚϣ���Ԫ��ֵ���ȣ���Ԫ�ؽ�С�Ľڵ����һ����λ��
 *              ����ȣ�������C�ڵ㲢��A��B��ָ�������
 *@author: NSS
 *@date:2022/4/30
 **/
void func_14() {
    printf("Init A");
    LinkListWithHead A;
    A = Struct_List();
    printf("Init B");
    LinkListWithHead B;
    B = Struct_List();

    Node2 *p = A->next, *q = B->next, *r, *s;
    LinkListWithHead C = (LinkListWithHead) malloc(sizeof(Node2));
    r = C;            //rָ��C�ı�β
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;      //��A�ĵ�ǰԪ�ؽ�С�������
        } else if (p->data > q->data) {
            q = q->next;      //��B�ĵ�ǰԪ�ؽ�С�������
        } else {             //�ҵ������ڵ�
            s = (Node2 *) malloc(sizeof(Node2));
            s->data = p->data;//���Ʋ����ڵ�*s
//          C������ȥ�أ�
            /*r->next=s;      //��s���ӵ�C�ϣ�β�巨��
            r=s;*/
            //C����ȥ�أ�
            if (s->data != r->data) {
                r->next = s;
                r = s;
            }
            p = p->next;      //��a��B��������
            q = q->next;

        }
    }
    r->next = NULL;
    Print_List_WH(C);
}

/*
 *@Title:��ʮ����
 *@Description:��֪��������A��B�ֱ��ʾ�������ϣ�Ԫ�ص���.����㷨����A��B�Ĳ������������A����
 *@Operation:������������ָ�룬�������������ɨ��ֻ��ͬʱ�����������ϵ�Ԫ�ز����ӵ�������У���ֻ����һ����������ȫ���ͷ�
 *           ��һ������������֮���ͷ���һ�����е�ȫ���ڵ�
 *@author: NSS
 *@date:2022/5/1
 **/
void func_15() {
    printf("Init A");
    LinkListWithHead la;
    la = Struct_List();
    printf("Init B");
    LinkListWithHead lb;
    lb = Struct_List();

    Node2 *pa = la->next, *pb = lb->next;    //pa��pb��Ϊ����ָ��
    Node2 *pc = la, *u;                    //������е�ǰ�ϲ��ڵ��ǰ��ָ��
    while (pa && pb) {
        if (pa->data == pb->data) {         //����������������
            if (pc->data != pa->data) {     //ȥ��
                pc->next = pa;            //A�нڵ����ӵ������
                pc = pa;
            }
            pa = pa->next;
            u = pb;                       //B�нڵ��ͷ�
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {    //��A�е�ǰ�ڵ�ֵС��B�е�ǰ�ڵ�ֵ
            u = pa;
            pa = pa->next;                //����ָ��
            free(u);                    //���ͷŵ�ǰ�ڵ�
        } else {                         //��B�е�ǰ�ڵ�ֵС��B�е�ǰ�ڵ�ֵ
            u = pb;
            pb = pb->next;                //����ָ��
            free(u);                    //�ͷ�B�е�ǰ�ڵ�
        }
    }
    while (pa) {                         //��A��δ������
        u = pa;
        pa = pa->next;
        free(u);                        //�ͷŽڵ�
    }
    while (pb) {                         //��B��δ������
        u = pb;
        pb = pb->next;
        free(u);                        //�ͷŽڵ�
    }
    pc->next = NULL;                      //�ý������βָ��ΪNULL
    free(lb);                           //�ͷ�B���ͷ�ڵ�
    printf("Print Result:\n");
    Print_List_WH(la);
}

/*
 *@Title: ��ʮ����
 *@Description:������������A��B�����Ѿ����������������У�����㷨���ж�����B�Ƿ�������A������������
 *@Operation:��Ϊ���������Ѿ��������������У����Էֱ����������ĵ�һ���ڵ㿪ʼ������Ӧָ����ȣ������ָ�룬������ȣ�A������ϴο�ʼ�ȽϵĽڵ�ĺ�̿�ʼ
 *           B����ӵ�һ���ڵ㿪ʼ�Ƚϣ�֪��B����ƥ����ɡ�A����β��B����δ��β����ʾʧ�ܣ�������סÿ��A����Ŀ�ʼ�ڵ㣬�Ա��´�ƥ��
 *@author: NSS
 *@date:2022/5/2
 **/
void func_16() {
    printf("Init A");
    LinkListNoHead A;
    A = Struct_List_NH();
    printf("Init B");
    LinkListNoHead B;
    B = Struct_List_NH();

    Node1 *p = A;
    Node1 *pre = p;
    Node1 *q = B;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = pre->next;
            p = pre;
            q = B;
        }
    }
    if (q->next == NULL) {
        printf("��������");
        return;
    } else {
        printf("����������");
        return;
    }
}

/*
 *@Title:��ʮ����
 *@Description: ����㷨�жϴ�ͷ�ڵ��ѭ��˫�����Ƿ�Գ�
 *@Operation:��p��������ɨ�裬q��������ɨ�裬֪��p==q����p->next=q��������������ָ�ڵ���ͬ�������ɨ�裬���򷵻�false�������󷵻�true
 *@author: NSS
 *@date:2022/5/3
 **/
bool func_17(DoubleLinkList L){
    DNode1 *p=L->next,*q=L->prior;
    while (p!=q&&p->next!=q){
        if(p->data==q->data){
            p=p->next;
            q=q->prior;
        } else{
            return false;
        }
    }
    return true;
}

/*
 *@Title:��ʮ����
 *@Description:������ѭ������������ͷָ��ֱ�Ϊh1��h2������㷨����h2���ӵ�h1֮��Ҫ�����Ӻ��Ա���ѭ��������ʽ
 *@Operation:���ҵ����������βָ�룬����һ�������βָ����ڶ��������ͷ�ڵ�������������ʹ֮��Ϊѭ��
 *@author: NSS
 *@date:2022/5/3
 **/
CLinkList1 func_18(CLinkList1 h1,CLinkList1 h2){
    LNode1 *q,*p;
    p=h1;
    while (p->next!=h1){
        p=p->next;
    }
    q=h2;
    while (q->next!=h2){
        q=q->next;
    }
    p->next=h2;
    q->next=h1;
    return h1;
}

/*
 *@Title:��ʮ����
 *@Description:����һ����ͷ�ڵ��ѭ���������ڵ�ֵΪ������������㷨�����ҳ���Сֵ���������Ȼ��ɾ���ýڵ㣬���ɾ����ͷ�ڵ�
 *@Operation:����ѭ���������ڲ���ʱѭ����ÿѭ��һ�β���һ����С�ڵ㲢ɾ��������ͷ�ͷ�ڵ㡣
 *@author: NSS
 *@date:2022/5/3
 **/
void func_19(CLinkList1 L){
    LNode1 *p,*pre,*minp,*minpre;
    while (L->next!=L){                 //���գ�ѭ��
        p=L->next,pre=L;                //pΪ����ָ�룬preָ��ǰ��
        minp=p,minpre=pre;              //minpָ����С�ڵ�
        while (p!=L){
            if(p->data<minp->data){
                minp=p;                 //�ҵ�ֵ��С�Ľڵ�
                minpre=pre;
            }
            pre=p;                      //������һ���ڵ�
            p=p->next;
        }
        printf("%d",minp->data);        //���
        minpre->next=minp->next;        //ɾ���ڵ�
        free(minp);                     //�ͷſռ�
    }
    free(L);                            //�ͷ�ͷ�ڵ�
}

/*
 *@Title:�ڶ�ʮ��
 *@Description:��˫���ѭ������ÿ���ڵ����pred��data��next֮�⣬����һ������Ƶ��freq������������ǰ����ֵ����ʼ��Ϊ0��ÿ���������
 *             Locate��L��x������ʱ����Ԫ��ֵΪx�Ľڵ���freq���ֵ��һ����ʹ�������нڵ㱣�ְ�����Ƶ�ȵݼ����У�ͬʱ������ʵĽڵ�����Ƶ��
 *             ��ͬ�Ľڵ�ǰ�棬�Ա�ʹƵ�����ʵĽڵ����ǿ�����ͷ���Ա�дLocate�㷨���ú���Ϊ�������̷����ҵ��Ľڵ��ַ������Ϊָ����
 *@Operation:������˫�������в�������ֵΪx�Ľڵ㣬�鵽�󽫽ڵ��������ժ�£�Ȼ��˳�Žڵ��ǰ�������Ҹýڵ�Ĳ���λ�ã�Ƶ�ȵݼ���������ͬƵ��
 *           �ĵ�һ��������ǰ�ҵ���һ������Ƶ�ȴ�Ľڵ㣬����λ��Ϊ�ýڵ�֮�󣩣������뵽��λ��
 *@author: NSS
 *@date:2022/5/4
 **/
DLinkList2 Locate(DLinkList2 L,ElemType x){
    DNode2 *p=L->next,*q;                           //pΪ����ָ�룬qΪp��ǰ�������Բ���p�Ĳ���λ��
    while (p&&p->data!=x){
        p=p->next;                                  //����ֵΪx�Ľڵ�
    }
    if(!p)
        exit(0);                                    //������ֵΪx�Ľڵ㣬�Ƴ�
    else{
        p->freq++;                                  //��Ԫ��ֵΪx��freq��ֵ��һ
        if(p->pred==L ||p->pred->freq>p->freq){
            return p;                               //��pΪ�����׽ڵ㣬��freq��ֵС��ǰ�����������������p
        }
        if(p->next!=NULL) p->next->pred=p->pred;    //��p��Ϊβ�ڵ㣬��ʼ��p��������ժ��������p�ĺ�̵�ǰ����Ϊp��ǰ��
        p->pred->next=p->next;                      //p��ǰ���ĺ����Ϊp�ĺ�̣���p��������ժ��
        q=p->pred;                                  //q��Ϊp��ǰ������ʼ����p�Ĳ���λ��
        while (q!=L&&q->freq<=p->freq){             //��ʼ��ǰ���ҵ�һ��freq��ֵ��p��freqֵ��Ľڵ�
            q=q->pred;
        }
        p->next=q->next;                            //ѭ���������ҵ�����㣬��ʼ��p��������
        if(q->next!=NULL) q->next->pred=p;          //��p����ͬƵ�ʵĵ�һ��
        p->pred=q;
        q->next=p;
    }
    return p;                                       //����
}


/*
 *@Title:�ڶ�ʮһ��
 *@Description:�������л�����ָ����������һ���ڵ��ָ��ָ���������е�ĳ���ڵ㣨ͨ������������һ���ڵ��ָ����Ϊ�գ�������㷨�жϵ�������
 *              ���л�
 *@Operation:���ÿ�������ָ��ֱ�Ϊfast��slow ��ʼ��ָ��head��slowÿ����һ����fastÿ��������������fast��slow�ߵĿ飬����л�����ôfast
 *          һ�����뻷����slow���뻷��������ָ�붼���뻷�󾭹����ɲ���������ָ�붨���ڻ����������������ж�һ�������Ƿ��л��������fastΪNULL
 *          ��fast�ĺ��ΪNULL�Ļ���ʾ������û��
 *@author: NSS
 *@date:2022/5/4
 **/
Node1 func_21(){

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
//    func_11();
//    func_12();
//    func_13();
//    func_14();
//    func_15();
    func_16();
    return 0;
}


