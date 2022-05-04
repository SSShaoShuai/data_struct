//
// Created by 倪先生 on 2022/4/3.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
/*---------------------------------不带头节点单链表---------------------------------*/
typedef struct Node1 {
    int data;
    struct Node1 *next;
} Node1, *LinkListNoHead;

bool InitSListNH(LinkListNoHead L) {
    L = NULL;
    return true;
}

//创建不带头节点的单链表
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

//输出链表
void PrintList_NoHead(LinkListNoHead L) {
    printf("开始输出链表数据-不带头结点\n");//不带头结点的单链表L即为单链表第一位
    Node1 *node = L;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n输出链表结束\n");
}

//构建不带头节点单链表
LinkListNoHead Struct_List_NH(){
    printf("Start Create\n");
    LinkListNoHead L;
    L=CreateSListNH(L);
    printf("Print List: ");
    PrintList_NoHead(L);
}
/*---------------------------------不带头节点单链表---------------------------------*/


/*---------------------------------带头节点单链表---------------------------------*/
// 带头节点单链表结构定义
typedef struct Node2 {
    ElemType data;
    struct Node2 *next;
} Node2, *LinkListWithHead;

//初始化
LinkListWithHead InitSLinkWH() {
    LinkListWithHead L;
    L = (Node2 *) malloc(sizeof(Node2));
    if (L == NULL) return NULL;
    L->next = NULL;
    return L;
}

//尾插
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

//输出链表
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

//获取单链表表长
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
/*---------------------------------带头节点单链表---------------------------------*/

/*---------------------------------双循环链表---------------------------------*/
//双循环链表结构
typedef struct DNode1 {
    ElemType data;
    struct DNode1 *prior, *next;
} DNode1, *DoubleLinkList;

/*---------------------------------双循环链表---------------------------------*/



/*---------------------------------单循环链表---------------------------------*/
//单循环链表结构
typedef struct LNode1{
    int data;
    struct LNode1 *next;
}LNode1,* CLinkList1;

/*---------------------------------单循环链表---------------------------------*/

/*---------------------------------双向不循环链表---------------------------------*/
typedef struct DNode2{
    int data;
    struct DNode2 *pred;
    struct DNode2 *next;
    int freq;
}DNode2,* DLinkList2;
/*---------------------------------双向不循环链表---------------------------------*/




/*-----------------题目--------------------*/
/*
 *@Title:第一题
 *@Description: 设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点
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
 *@Title:第二题
 *@Description:在带头节点的单链表中删除所有值为x的节点，并释放其空间，假设x值不唯一
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
 *@Title:第三题
 *@Description:设L为带头节点的单链表，编写算法实现从尾到头反向输出每个节点的值
 *@Operation:
 *@author: NSS
 *@date:2022/4/4
 **/
void R_Print(LinkListWithHead L) {
    if (L->next != NULL) {
        R_Print(L->next);//递归调用，方法被压入递归栈，调用结束后返回该方法并执行后面的相关语句
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
 *@Title:第四题
 *@Description:编写在带头结点的单链表中删除一个最小值的高效算法（假设最小值结点唯一）
 *@Operation:用p从头到尾遍历链表，pre指向p的前驱，minp保存值最小的节点指针，minpre指向minp的前驱，一边扫描一边比较
 *           若p->data小于minp->data，则将p，pre分别赋值给minp，minpre，当p扫描完是minp指向最小值节点
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
            minp = p;     //找到当前的最小值结点，并赋值
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }//循环结束，minp指向的即为最小值节点
    minpre->next = minp->next;
    free(minp);
    Print_List_WH(L);
    printf("Delete Min Finish");
}

/*
 *@Title:第五题
 *@Description:编写算法将带头节点的单链表就地逆置，所谓"就地"是指辅助空间复杂度为O(1)
 *@Operation:将头结点摘下，然后从第一个节点开始，一次插入到头结点的后面（头插法建立单链表）直至最后一个节点
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

    Node2 *p, *r;//工作指针，r为p的后继，以防断链
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
    p->next = NULL;    //将第一个节点的后继置空
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre; //指针反转
    }
    L->next = p;
    Print_List_WH(L);
    printf("Reverse Finish");
}

/*
 *@Title:第六题
 *@Description:有一个带头节点的单链表L，设计一个算法使其递增有序
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

    //构建一个只包含一个数据节点的有序单链表
    Node2 *p = L->next, *pre;  //p为工作指针，pre为p的前驱节点
    Node2 *r = p->next;   //保存p之后的链表数据，保证有数据可取
    p->next = NULL;       //使当前链表只有一个数据节点；构建包含p节点的有序链表
    p = r;    //让p指向r后面的节点（初始为第三个节点）

    while (p != NULL) {
        r = p->next;  //保存p后面的链表数据，使需要排序的链表不断
        pre = L;
        //p为较大的节点，pre是较小的节点
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;  //pre是较小的节点
        }
        //p节点较大，放在pre的后面
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
 *@Description: 一个带头节点的单链表中，所有元素节点无序，设计算法，删除表中所有介于给定的两个值之间的元素
 *@Operation:   从头遍历单链表所有元素，判断后进行删除操作
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
 *@Title:第八题
 *@Description: 给定两个单链表，设计算法找出两个链表的公共节点
 *@Operation:       因为是两个单链表，所以公共节点之后的所有节点应该是相同的，即他们的最后一个节点是重合的
 *                  因此只要找到第一个重合的节点后面的节点就都是重合节点了
 *                  但两个链表的长度不一定一样，假设长链表比短链表长k个节点，设计算法先让长链表遍历k个节点
 *                  之后在同步遍历，即可保证遍历的同步，所以找到的第一个相同节点就是公共节点
 *@author: NSS
 *@date:2022/4/29
 **/
LinkListWithHead func_8(LinkListWithHead L1, LinkListWithHead L2) {
    //本算法实现在线性时间内找到两个单链表的第一个公共节点
    int len1 = GetLengthWithHead(L1), len2 = GetLengthWithHead(L2);//将两个链表的长度分别求出
    LinkListWithHead longList, shortList;
    int dist;
    if (len1 > len2) {//判断两个链表那个更长，赋值并求出长度之差
        longList = L1->next;
        shortList = L2->next;
        dist = len1 - len2;
    } else {
        longList = L2->next;
        shortList = L1->next;
        dist = len2 - len1;
    }
    while (dist--) {//先将长链表指针后移两链表长度之差个位置
        longList = longList->next;
    }
    while (longList != NULL) {//判断当前节点是否是公共节点
        if (longList == shortList) {
            return longList;//是公共节点，返回
        } else {//不是将两链表指针分别后移
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

/*
 *@Title:第九题
 *@Description:按递增次序输出单链表中各节点的数据元素，并释放节点所占的存储空间
 *@Operation:   对链表进行遍历，每次遍历找出最小值并释放，一直循环，直至链表为空
 *@author: NSS
 *@date:2022/4/29
 **/
void func_9() {
    LinkListWithHead L;
    L = Struct_List();

    while (L->next != NULL) {
        Node2 *pre = L;//pre为元素最小值节点的前驱节点
        Node2 *p = pre->next;//p为工作指针
        while (p->next != NULL) {
            if (p->next->data < pre->next->data) {
                pre = p;//将当前最小值节点的前驱节点进行赋值
            }
            p = p->next;
        }
        printf("%d ", pre->next->data);//输出节点数据
        Node2 *u;
        u = pre->next;
        pre->next = u->next;
        free(u);//释放节点
    }
    free(L);//释放头指针
}

/*
 *@Title:第十题
 *@Description:将一个带有头节点的单链表A分解为两个带头节点的单链表A和B，使A表中含有原表中序号为奇数的元素，
 *             B表中含有原表中序号为偶数的元素，保持相对顺序不变
 *@Operation:   设计访问序号变量，每访问一个节点序号自动加一，然后根据序号的奇偶性将节点插入到A表或B表中。重复操作直到表尾
 *@author: NSS
 *@date:2022/4/29
 **/
void func_10() {
    LinkListWithHead A;
    A = Struct_List();

    int i = 0;//i为访问序号变量
    LinkListWithHead B = (LinkListWithHead) malloc(sizeof(Node2));//创建B表表头
    B->next = NULL;//B表初始化
    Node2 *ra = A, *rb = B, *p; //ra和rb分别指向将创建的A表和B表的尾节点

    p = A->next;//p为链表工作指针，指向待分解的节点
    A->next = NULL;//将A表置空
    while (p != NULL) {
        i++;
        if (i % 2 == 0) {//位序为偶数的链表节点
            rb->next = p;//在b表尾插入新节点
            rb = p;//将rb指向新的尾节点
        } else {
            ra->next = p;//在A表尾插入新节点
            ra = p;
        }
        p = p->next;  //将p恢复为指向新的待处理节点
    }
    ra->next = NULL;
    rb->next = NULL;
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:第十一题
 *@Description:设C={a1,b1,a2,b2,……,an,bn}为线性表，采用带头节点的hc单链表进行存放，设计一个就地算法，将其拆分为两个线性表，
 *             使得A=={a1,a2,……,an},B=={bn,……,b2,b1}
 *@Operation:采用第十题的思路，区别是不需要设序号变量。B表的建立不采用尾插法
 *@author: NSS
 *@date:2022/4/29
 **/
void func_11() {
    LinkListWithHead A;
    A = Struct_List();

    LinkListWithHead B = (LinkListWithHead) malloc(sizeof(Node2));//创建B表表头
    B->next = NULL;   //初始化B表
    Node2 *p = A->next, *q;  //p为工作指针
    Node2 *ra = A;    //ra始终指向A的尾节点
    while (p != NULL) {
        ra->next = p;     //将p链接到A的表尾
        ra = p;
        p = p->next;
        if (p != NULL) {
            q = p->next;  //头插后，p将断链，因此用q记忆p的后继，保证程序正常运行
            p->next = B->next;    //将p插入到B的前端
            B->next = p;
            p = q;
        }
    }
    ra->next = NULL;      //A尾节点的后继置空
    printf("a:");
    Print_List_WH(A);
    printf("b:");
    Print_List_WH(B);
}

/*
 *@Title:第十二题
 *@Description: 在一个递增有序的线性表中有数值相同的元素存在。存储方式为单链表，设计算法去掉数值相同的元素
 *@Operation:   因为是有序表，所以重复的数据为相邻节点，遍历线性表，若相邻节点数值重复则删除后者，否则p指针后移一个单位
 *@author: NSS
 *@date:2022/4/30
 **/
void func_12() {
    LinkListWithHead L;
    L = Struct_List();

    Node2 *p = L->next, *q;//p为工作指针，q为p的后继，用以判断是否重复
    if (p == NULL) {
        return;
    }
    while (p->next != NULL) {
        q = p->next;//q指向p的后继
        if (p->data == q->data) {//判断p和q是否重复
            p->next = q->next;//重复，将p的后继指向p的后继的后继
            free(q);//释放q
        } else {
            p = p->next;//不相同p指针后移一个单位
        }
    }
    printf("Execute Finish\n");
    Print_List_WH(L);
    printf("finish\n");
}

/*
 *@Title:第十三题
 *@Description:两个递增有序单链表，设计算法将两个单链表归并为一个递减单链表，并要求利用原来两个线性表的节点存放
 *@Operation:   因为是两个有序链表，所以只需要从头遍历两个表，按次序比较，将数据较小的节点存放，直至一个线性表遍历完成，
 *              将另一个线性表的元素以头插法依次插入新链表中
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

    Node2 *r, *pa = LA->next, *pb = LB->next;//pa和pb分别是LA和LB的工作指针
    LA->next = NULL;  //将LA初始化

    while (pa && pb) {     //当两个链表都不为空时进行循环
        if (pa->data < pb->data) {
            r = pa->next;     //r暂存pa的后继节点的指针
            pa->next = LA->next;
            LA->next = pa;    //将pa节点链接到结果表中，同时逆置，使用头插法
            pa = r;           //恢复pa为当前待比较节点
        } else {
            r = pb->next;     //r暂存pb的后继节点指针
            pb->next = LA->next;
            LA->next = pb;    //将pb节点链接到结果表中，同时逆置，使用头插法
            pb = r;           //恢复pb为当前待比较节点
        }
    }
    if (pa) {                //循环结束后判断是否有链表为空，处理剩下的部分
        pb = pa;
    }
    while (pb) {
        r = pb->next;         //依次插入到LA中（头插法）
        pb->next = LA->next;
        LA->next = pb;
        pb = r;
    }
    free(LB);
    printf("print LA: ");
    Print_List_WH(LA);
}

/*
 *@Title:第十四题
 *@Description:A和B是两个带头节点的递增有序链表，设计算法，从A和B中的公共元素产生链表C，要求不破坏AB的节点
 *@Operation:   因为是递增的两个单链表，分别从头遍历并比较，若元素值不等，将元素较小的节点后移一个单位，
 *              若相等，则生成C节点并将A和B的指针均后移
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
    r = C;            //r指向C的表尾
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;      //若A的当前元素较小，则后移
        } else if (p->data > q->data) {
            q = q->next;      //若B的当前元素较小，则后移
        } else {             //找到公共节点
            s = (Node2 *) malloc(sizeof(Node2));
            s->data = p->data;//复制产生节点*s
//          C表不考虑去重：
            /*r->next=s;      //将s连接到C上（尾插法）
            r=s;*/
            //C表考虑去重：
            if (s->data != r->data) {
                r->next = s;
                r = s;
            }
            p = p->next;      //表a表B继续后移
            q = q->next;

        }
    }
    r->next = NULL;
    Print_List_WH(C);
}

/*
 *@Title:第十五题
 *@Description:已知两个链表A和B分别表示两个集合，元素递增.设计算法，求A和B的并集，并存放于A表中
 *@Operation:设置两个工作指针，对两个链表进行扫描只有同时出现在两集合的元素才链接到结果表中，且只保留一个，其他的全部释放
 *           当一个链表遍历完毕之后，释放另一个表中的全部节点
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

    Node2 *pa = la->next, *pb = lb->next;    //pa，pb，为工作指针
    Node2 *pc = la, *u;                    //结果表中当前合并节点的前驱指针
    while (pa && pb) {
        if (pa->data == pb->data) {         //交集，并入结果表中
            if (pc->data != pa->data) {     //去重
                pc->next = pa;            //A中节点链接到结果表
                pc = pa;
            }
            pa = pa->next;
            u = pb;                       //B中节点释放
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {    //若A中当前节点值小于B中当前节点值
            u = pa;
            pa = pa->next;                //后移指针
            free(u);                    //并释放当前节点
        } else {                         //若B中当前节点值小于B中当前节点值
            u = pb;
            pb = pb->next;                //后移指针
            free(u);                    //释放B中当前节点
        }
    }
    while (pa) {                         //若A表未遍历完
        u = pa;
        pa = pa->next;
        free(u);                        //释放节点
    }
    while (pb) {                         //若B表未遍历完
        u = pb;
        pb = pb->next;
        free(u);                        //释放节点
    }
    pc->next = NULL;                      //置结果链表尾指针为NULL
    free(lb);                           //释放B表的头节点
    printf("Print Result:\n");
    Print_List_WH(la);
}

/*
 *@Title: 第十六题
 *@Description:两个整数序列A，B，，已经存入两个单链表中，设计算法，判断序列B是否是序列A的连续子序列
 *@Operation:因为两个序列已经存入两个链表中，所以分别从两个链表的第一个节点开始，若对应指针相等，则后移指针，若不相等，A链表从上次开始比较的节点的后继开始
 *           B链表从第一个节点开始比较，知道B链表匹配完成。A链表到尾而B链表未到尾部表示失败，操作记住每次A链表的开始节点，以便下次匹配
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
        printf("是子序列");
        return;
    } else {
        printf("不是子序列");
        return;
    }
}

/*
 *@Title:第十七题
 *@Description: 设计算法判断带头节点的循环双链表是否对称
 *@Operation:让p从左向右扫描，q从右向左扫描，知道p==q或者p->next=q结束，若他们所指节点相同，则继续扫描，否则返回false，结束后返回true
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
 *@Title:第十八题
 *@Description:有两个循环单链表，链表头指针分别为h1和h2，设计算法，将h2链接到h1之后，要求链接后仍保持循环链表形式
 *@Operation:先找到两个链表的尾指针，将第一个链表的尾指针与第二个链表的头节点链接起来，在使之成为循环
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
 *@Title:第十九题
 *@Description:设有一个带头节点的循环单链表，节点值为正整数。设计算法反复找出最小值，并输出，然后删除该节点，最后删除表头节点
 *@Operation:对于循环单链表，在不空时循环，每循环一次查找一个最小节点并删除。最后释放头节点。
 *@author: NSS
 *@date:2022/5/3
 **/
void func_19(CLinkList1 L){
    LNode1 *p,*pre,*minp,*minpre;
    while (L->next!=L){                 //表不空，循环
        p=L->next,pre=L;                //p为工作指针，pre指向前驱
        minp=p,minpre=pre;              //minp指向最小节点
        while (p!=L){
            if(p->data<minp->data){
                minp=p;                 //找到值更小的节点
                minpre=pre;
            }
            pre=p;                      //查找下一个节点
            p=p->next;
        }
        printf("%d",minp->data);        //输出
        minpre->next=minp->next;        //删除节点
        free(minp);                     //释放空间
    }
    free(L);                            //释放头节点
}

/*
 *@Title:第二十题
 *@Description:有双向非循环链表，每个节点除有pred，data，next之外，还有一个访问频度freq。在链表被启用前，其值均初始化为0，每当链表进行
 *             Locate（L，x）运算时，令元素值为x的节点中freq域的值增一，并使此链表中节点保持按访问频度递减排列，同时最近访问的节点排在频度
 *             相同的节点前面，以便使频繁访问的节点总是靠近表头。试编写Locate算法，该函数为函数过程返回找到的节点地址，类型为指针型
 *@Operation:首先在双向链表中查找数据值为x的节点，查到后将节点从链表上摘下，然后顺着节点的前驱链查找该节点的插入位置（频度递减，切排在同频度
 *           的第一个，即向前找到第一个比它频度大的节点，插入位置为该节点之后），并插入到该位置
 *@author: NSS
 *@date:2022/5/4
 **/
DLinkList2 Locate(DLinkList2 L,ElemType x){
    DNode2 *p=L->next,*q;                           //p为工作指针，q为p的前驱，用以查找p的插入位置
    while (p&&p->data!=x){
        p=p->next;                                  //查找值为x的节点
    }
    if(!p)
        exit(0);                                    //不存在值为x的节点，推出
    else{
        p->freq++;                                  //令元素值为x的freq域值加一
        if(p->pred==L ||p->pred->freq>p->freq){
            return p;                               //若p为链表首节点，或freq的值小于前驱，程序结束，返回p
        }
        if(p->next!=NULL) p->next->pred=p->pred;    //若p不为尾节点，开始将p从链表中摘出来，将p的后继的前驱置为p的前驱
        p->pred->next=p->next;                      //p的前驱的后继置为p的后继，将p从链表上摘下
        q=p->pred;                                  //q置为p的前驱，开始查找p的插入位置
        while (q!=L&&q->freq<=p->freq){             //开始向前查找第一个freq域值比p的freq值大的节点
            q=q->pred;
        }
        p->next=q->next;                            //循环结束已找到插入点，开始将p插入链表
        if(q->next!=NULL) q->next->pred=p;          //将p排在同频率的第一个
        p->pred=q;
        q->next=p;
    }
    return p;                                       //返回
}


/*
 *@Title:第二十一题
 *@Description:单链表有环，是指单链表的最后一个节点的指针指向了链表中的某个节点（通常单链表的最后一个节点的指针域为空）。设计算法判断单链表是
 *              否有环
 *@Operation:设置快满两个指针分别为fast和slow 初始都指向head。slow每次走一步，fast每次走两步，由于fast比slow走的块，如果有环，那么fast
 *          一定先入环，而slow后入环。当两个指针都进入环后经过若干操作后两个指针定能在环上相遇。这样就判断一个链表是否有环，如果当fast为NULL
 *          或fast的后继为NULL的话表示该链表没环
 *@author: NSS
 *@date:2022/5/4
 **/
Node1 func_21(){

}

int main() {

/*--------------------不带头节点的单链表相关题目--------------------*/
    /*LinkListNoHead *L;
    InitSListNH(L);
    L=CreateSListNH();
    PrintList_NoHead(L);
    Del_All_X(L,2);//第一题
    printf("删除后：");
    PrintList_NoHead(L);*/

/*--------------------带头节点的单链表相关题目--------------------*/
//    LinkListWithHead L;
//    L = ListInsert_Tail_WH(L);
//    Print_List_WH(L);
//    ReverseData(L);//第三题
//    Del_All_X_WH(L,2);第二题
//    fun4();//第四题
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


