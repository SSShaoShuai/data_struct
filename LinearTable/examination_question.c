//
// Created by 47244 on 2022/2/17.
//
#include "LinearTable.c"


/*
 *@Title:2.2.3.二综合应用题.1：
 *@Description:从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值，空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
 *@Operation:判断顺序表是否为空，遍历线性表找出最小值，将线性表最后一位赋值给当前位置
 *@author: NSS
 *@date:2022/2/17
 **/
bool Del_Min(SqList *L,ElemType *value){
    if(L->length==0){                       //判断表是否为空
        return false;
    }
    value=L->elem[0];
    int pos=0;                              //从表头开始查询将表头元素取出做比较
    for(int i=0;i<L->length;i++){           //遍历整个线性表
        if(L->elem[i]<value){               //将value置为当前最小的元素
            value=L->elem[i];
            pos=i;
        }
    }
    L->elem[pos]=L->elem[L->length-1];      //将表尾元素赋值到最小元素的位置
    L->length--;                            //表长减一
    return true;
}

/*
 *@Title:2.2.3.二综合应用题.2：
 *@Description:设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O（1）
 *@Operation:扫描线性表L的前半部分元素，对于元素L.data[i](0<=i<L.length/2),
 *           将其与后半部分元素L.data[L.lenght-i-1]进行交换
 *@author: NSS
 *@date:2022/2/17
 **/
void Reverse(SqList *L){
    ElemType temp;
    for(int i=0;i<L->length/2;i++){

        //利用两个元素加减实现交换数值
//        L->elem[i]=L->elem[i]+L->elem[L->length-1-i];
//        L->elem[L->length-1-i]=L->elem[i]-L->elem[L->length-1-i];
//        L->elem[i]=L->elem[i]-L->elem[L->length-1-i];

        //利用中间元素实现交换数值
        temp=L->elem[i];
        L->elem[i]=L->elem[L->length-1-i];
        L->elem[L->length-1-i]=L->elem[i];
    }
}

/*
 *@Title:2.2.3.二综合应用题.3：
 *@Description:对长度为n的顺序表L，编写一个事件复杂度为O（n）、空间复杂度为O(1)的算法，
 *             该算法删除线性表中所有值为x的数据元素
 *@Operation:解法一：用k记录顺序表中不等于x的元素个数，边扫描边统计k，并将不等于x的元素向前移动k个位置
 *           最后修改L的长度
 *@author: NSS
 *@date:2022/2/17
 **/
void Del_x_1(SqList *L,ElemType *x){
    int k=0;
    for (int i=0;i<L->length;i++){
        if(L->elem[i]!=x){
            L->elem[k]=L->elem[i];          //将不等于x的元素前移至下标为k的位置
            k++;                            //不等于x的元素个数加一
        }
    }
    L->length=k;                            //顺序表L的长度等于k
}

/*
 *@Title:2.2.3.二综合应用题.3：
 *@Description:对长度为n的顺序表L，编写一个事件复杂度为O（n）、空间复杂度为O(1)的算法，
 *             该算法删除线性表中所有值为x的数据元素
 *@Operation:解法二：用k记录顺序表中等于x的元素个数，边扫描边统计k并将不等于x的元素前移k个位置
 *                  最后修改L的长度
 *@author: NSS
 *@date: 2022/2/17
 **/
void Del_x_2(SqList *L,ElemType *x){
    int k=0,i=0;                        //k记录等于x的元素个数，i为顺序表下标
    while (i<L->length){
        if(L->elem[i]==x){
            k++;
        } else{
            L->elem[i-k]=L->elem[i];    //当前元素前移k个位置
        }
        i++;
    }
    L->length=L->length-k;              //顺序表L的长度递减
}

/*
 *@Title:2.2.3.二综合应用题.4：
 *@Description:从有序顺序表中删除气质在给定值s与t之间（要求s<t）的所有元素，
 *              若s或t不合理或顺序表为空，则显示出错信息并退出运行
 *@Operation:先寻找值大于等于s的第一个元素，然后寻找值大于t的第一个元素（最后一个被删除的元素的下一个元素）
 *              要将这段元素删除，只需直接将后面的元素前移，并重置表长
 *@author: NSS
 *@date:2022/2/17
 **/
bool del_s_t(SqList *L,ElemType s,ElemType t){
    int i,j;
    if(s>=t||L->length==0){
        return false;
    }
    for (i=0;i<L->length &&L->elem[i]<s;i++);       //寻找值大于等于s的第一个元素
    if(i>=L->length)return false;                   //所有值均小于s，返回
    for (j=i;j<L->length&&L->elem[j]<=t;j++);        //寻找值大于t的第一个元素
    for (;j<L->length;i++,j++){
        L->elem[i]=L->elem[j];                      //前移填补被删除元素
    }
    L->length=i;
    return true;
}

/*
 *@Title:2.2.3.二综合应用题.5：
 *@Description:从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素
 *              若s或t不合理或顺序表为空，则显示出错信息并退出运行
 *@Operation:遍历顺序表L，用k记录下元素值在s到t之间元素的个数（初始值k=0）。对于当前扫描的元素
 *              若其值不在s到t之间，则前移k个位置，否则k++。由于这样每个不在s到t之间的元素
 *              仅移动一次，因此算法效率高
 *@author: NSS
 *@date:2022/2/17
 **/
bool Del_s_t2(SqList *L,ElemType s,ElemType t){
    int i,k=0;
    if(L->length==0 ||s>=t) return false;
    for(i=0;i<L->length;i++){
        if(L->elem[i]>=s&&L->elem[i]<=s){
            k++;
        } else{
            L->elem[i-k]=L->elem[i];                //当前元素前移k个位置
        }

    }
    L->length-=k;                                   //重置顺序表长度
    return true;
}



