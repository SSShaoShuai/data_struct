#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

#define Size 50

typedef int ElemType;
typedef int status;

typedef struct {
    ElemType* elem;
    int length;//线性表当前长度
    int listsize;//线性表当前最大长度
}SqList;

//初始化线性表
bool InitList(SqList* L) {
    L->elem = (ElemType*)malloc(sizeof(ElemType) * Size);
    L->length = 0;
    L->listsize = Size;
    return true;
}

//销毁线性表，并释放线性表L所占的内存空间
void DestoryList(SqList* L) {
    free(L->elem);
}

//求线性表表长
status Length(SqList* L) {
    return L->length;
}

//给线性表赋值
bool InPut(SqList* L,int n) {
    for (int i = 0; i < n; i++) {
        L->elem[i]=1;
    };
    return true;
}

//线性表判空，若L为空表返回true，否则返回false
bool Empty(SqList* L) {
    if (L->length>0)
    {
        return false;
    }
    return true;
}

//线性表输出
void OutPut(SqList* L) {
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n", L->elem[i]);
    }
}

//插入操作
bool ListInstert(SqList* L, int i, ElemType e) {
    ElemType* p, *p1, *p2;//p1指向要插入的位置，p2指向最后一个位置
    if (i<1 || i>L->length + 1) return false;
    if (L->length>=L->listsize)
    {
        p = realloc(L->elem, sizeof(ElemType) * (L->listsize + 10));
        if (!p)
        {
            return false;
        }
        L->elem = p;
        L->listsize += 10;
    }//若空间不足则扩充容量

    p1 = &L->elem[i - 1];//将p1指向要插入的位置
    for (p2 = &L->elem[L->length - 1]; p2 > p1; p2--) *(p2 + 1) = *p2;
    //for (int j = L->length - 1; j >= i - 1; j--) L->elem[j + 1] = L->elem[j];//使用数组移动
    L->elem[i - 1] = e;
    L->length++;
    return true;
}

//删除线性表中的元素
bool ListDelete(SqList* L,int i,ElemType* a) {
    int j;
    if (i<1 || i>L->length)//判断删除的位置是否合法
    {
        return false;
    }
    if (L->length==0)//判断是否是空表
    {
        return false;
    }

    *a = L->elem[i - 1];//将被删除的元素赋值给a
    for (j= i ; j<L->length; ++j)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;
    return true;
}

//按位查找，在表L中查找第i个位置的元素的值
void GetElem(SqList* L,int i,ElemType* e) {

    *e = L->elem[i - 1];
}

//修改线性表指定位置的元素值，i为需要修改的位置，e修改的元素
bool UpdateElem(SqList* L, int i, ElemType* e) {
    if (i<1 || i>L->length + 1) {
        printf("修改的位置不合法，请检查");
        return false;
    }
    if (L->length==0)
    {
        printf("该表为空表，请先输入数据");
        return false;
    }
    L->elem[i - 1] = *e;
    return true;
}

//2.2.3 线性表试题应用题 第四题：
//从有序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行
bool Del_s_t2(SqList* L, ElemType s, ElemType t) {
    int i, j;
    if (s >= t ||L->length==0) return false;
    for (i = 0; i < L->length && L->elem[i] < s; i++);//寻找值大于等于s的第一个元素
    if (i >= L->length) return false;//所有值均小于s，返回
    for (j = i; j < L->length && L->elem[j] <= t; j++);//寻找值大于t的第一个元素
    for (; j < L->length; i++, j++) L->elem[i] = L->elem[j];
    L->length = i;
    return true;
}

//2.2.3 线性表试题应用题 第五题：
//从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行
bool Del_s_t(SqList* L, ElemType s, ElemType t) {
    int i, k = 0;
    if (L->length == 0 || s >= t) return false;
    for (i = 0; i < L->length; i++) {
        if (L->elem[i]>=s&&L->elem[i]<=t)
        {
            k++;
        }
        else {
            L->elem[i - k] = L->elem[i];
        }
    }
    L->length -= k;
    return true;
}

//从有序顺序表中删除所有其值重复的元素，使表中所有元素均不相同
bool Del_same(SqList* L) {
    if (L->length == 0) return false;
    int i,j;
    for ( i = 0,j=1; j<L->length; j++){
        if (L->elem[i]!=L->elem[j]){
            L->elem[++i] = L->elem[j];
        }
    }
    L->length = i + 1;
    return true;
}