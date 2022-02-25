//
// Created by 47244 on 2022/2/17.
//


typedef int DataType;

void reverse_data(DataType *pInt, int i, int i1, int size);

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
void Reverse_2(SqList *L){
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

/*
 *@Title:2.2.3.二综合应用题.6
 *@Description:从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
 *@Operation:注意是有序顺序表，值相同的元素一定在连续的位置上，用类似于直接插入排序的思想，
 *           初始时将第一个元素视为非重复的有序表。之后一次判断后面的元素是否与前面非重复
 *           有序表的最后一个元素相同，若相同，则继续向后判断，若不同，则插入前面的非重复
 *           有序表的最后，直至判断到表尾为止
 *@author: NSS
 *@date:2022/2/24
 **/
bool Delete_same(SqList *L){
    if(L->length==0) return false;              //判断表是否合法
    int i,j;
    for (int i = 0,j=1; j<L->length ; j++) {
        if(L->elem[i]!=L->elem[j]){             //判断第i和第j位是否相等
            L->elem[++i]=L->elem[j];            //不相等，则将第j位前移至i+1位
        }
        L->length=i+1;                          //重置表长
        return true;
    }
}


/*
 *@Title:2.2.3.二综合应用题.7
 *@Description:将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 *@Operation:按顺序不断取两个顺序表表头较小的节点存入新的顺序表中。然后，看哪个表还有剩余，
 *           将剩下的部分加到新的顺序表后面
 *@author: NSS
 *@date:2022/2/24
 **/
bool Merge(SqList A,SqList B,SqList *C){
    if(A.length+B.length>C->listsize) return false;//判断C是否可以容纳A表和B表之和
    int i=0,j=0,k=0;
    while (i<A.length&&j<B.length){
        if(A.elem[i]<B.elem[j]){
            C->elem[k++]=A.elem[i++];
        } else{
            C->elem[k++]=B.elem[j++];
        }
    }
    while (i<A.length){
        C->elem[k++]=A.elem[i++];
    }
    while (j<B.length){
        C->elem[k++]=B.elem[j++];
    }
    C->length=k;
    return true;
}

/*
 *@Title:2.2.3.2.8
 *@Description:已知在一维数组中A[m+n]中依次存放两个线性表(a1,a2,a3,…,am)和(b1,b2,b3,…,bn)
 *             试编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,b3,…,bn)放在
 *             (a1,a2,a3,…,am)的前面
 *@Operation:先将整个数组逆置，此时b在a前面，再将前n个元素与后m个元素分别逆置
 *@author: NSS
 *@date:2022/2/24
 **/
void Exchange(DataType A[],int m,int n,int arraySize){
    reverse_data(A,0,m+n-1,arraySize);
    reverse_data(A,0,n-1,arraySize);
    reverse_data(A,n,m+n-1,arraySize);
}
void reverse_data(DataType *a, int left, int right, int arraySize) {
    if(left>=right||right>=arraySize) return;
    int mid=(left+right)/2;
    for (int i=0;i<mid-left;i++){
        DataType temp=a[left+i];
        a[left+i]=a[right-i];
        a[right-i]=temp;
    }
    return;
}

/*
 *@Title:2.2.3.2.9
 *@Description:线性表中（a1,a2,a3,…,an）中的元素递增有序且按顺序存储与计算机内。要求设计一个
 *             算法，完成用最少时间在表中查找数值位x的元素，若找到，则将其与后继元素位置相交换
 *             若找不到，则将其插入表中并使表中元素仍递增有序
 *@Operation:顺序存储的线性表递增有序，可以用顺序查找，也可以折半查找。题目要求最少时间
 *           这里使用折半查找
 *@author: NSS
 *@date:2022/2/24
 **/
void SearchExchangeInsert(SqList *L,ElemType x,int n){
    int low=0,high=n-1,mid;         //low和high指向顺序表下界和上界的下标
    while (low<=high){
        mid=(low+high)/2;           //找中间位置
        if(L->elem[mid]==x) break;  //找到x退出循环
        else if(L->elem[mid]<x) low=mid+1; //找中点mid的右半部去查
        else high=mid-1;                    //找中点mid的左半部去查
    }
    //下面两个if语句之会执行一个
    if(L->elem[mid]==x&&mid!=n-1){      //若最后一个元素与x相等，则不存在与其后继交换的操作
        ElemType t=L->elem[mid];
        L->elem[mid]=L->elem[mid+1];
        L->elem[mid+1]=t;
    }
    int i=n-1;
    if(low>high){                       //查找失败，插入数据元素x
        for(;i>high;i--){
            L->elem[i+1]=L->elem[i];    //后移元素
        }
        L->elem[i+1]=x;                 //插入x
    }
}

/*
 *@Title:2.2.3.2.10
 *@Description:设将n(n>1)个整数存放到以为数组R中。设计一个在时间和空间两方面都尽可能高效的算法
 *             将R中保存的序列循环左移p(0<p<n)个位置，即将R中的数据由(X0,X1,…,Xn-1)变换位
 *             (Xp,Xp+1,…,Xn-1,X0,X1,……,Xp-1)要求
 *             1）给出算法的基本设计思想
 *             2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
 *             3）说明你所设计算法的时间复杂度和空间复杂度
 *@Operation:设计思想：可将这个问题视为把数组ab转换成数组ba，先将a逆置得到a-1b,再将b逆置得到a-1b-1
 *                  最后将整个a-1b-1逆置得到（a-1b-1）-1=ba
 *                  对abcdefgh向左循环移动s个位置的过程如下：
 *                  Reverse_10(0,p-1)得到cbadefgh;
 *                  Reverse_10(p,n-1)得到cbahgfed;
 *                  Reverse_10(0,n-1)得到defghabc;
 *                  
 *                  三个算法的时间复杂度分别为O(p/2)、O((n-p)/2)、和O(n/2)
 *                  故算法的时间复杂度为O(n),空间复杂度为O(1)
 *                  
 *                  另解：借助辅助数组来实现。算法思想：创建大小为p的辅助数组S，将R中前p个整数
 *                  依次暂存在S中，同事将R中后n-p个整数左移，然后将S中暂存的p个数依次放回到R
 *                  中的后续单元时间复杂度为O(n)，空间复杂度为O(p)
 *@author: NSS
 *@date:2022/2/24
 **/
void Reverse_10(int R[],int from ,int to){
    int i,temp;
    for(i=0;i<(to-from+1)/2;i++){
        temp=R[from+1];
        R[from+1]=R[to-1];
        R[to-1]=temp;
    }
}
void Converse_10(int R[],int n,int p){
    Reverse_10(R,0,p-1);
    Reverse_10(R,p,n-1);
    Reverse_10(R,0,n-1);
}

/*
 *@Title:2.2.3.2.11
 *@Description:一个长度为L（L>=1)的升序序列S，处在第[L/2]个位置的书称为S的中位数。两个序列的中位数
 *             使含它们所有元素的升序序列的中位数。现在由两个等长升序序列A和B，使设计一个在时间和空间
 *             两方面都尽可能高效的算法，找出两个序列A和B的中位数。要求：
 *             1）给出算法的基本设计思想
 *             2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
 *             3）说明你所设计算法的时间复杂度和空间复杂度
 *@Operation:算法设计思想：
 *             分别求两个升序序列A,B的中位数，设为a和b，求序列A，B的中位数过程如下：
 *             1）若a=b则a或b几位所求中位数，算法结束。
 *             2）若a<b则舍弃序列A中较小的一半，同事舍弃序列B中较大的一般，要求两次舍弃的长度相等
 *             3）若a>b则舍弃序列A中较大的一半，同时何其序列B中较小的一半，要求两次舍弃的长度相等
 *             在保留的两个升序序列中，重复过程1）2）3）直到两个序列中均只含一个元素使位置，
 *             较小者几位所求中位数
 *
 *             算法时间复杂度为O(log2n),空间复杂度为O(1)
 *@author: NSS
 *@date:2022/2/24
 **/
int M_Search_11(int A[],int B[],int n){
    int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;      //分别表示两个序列的首位数、末位数和中位数
    while (s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2]) return A[m1];      //满足条件1
        if(A[m1]==B[m2]){                   //满足条件2
            if((s1+d1)%2==0){               //若元素个数为奇数  n为奇数，n-1为偶数
                s1=m1;                      //舍弃A中间点即中间点以前的部分
                d2=m2;                      //舍弃B中间点即以后的部分且保留中间点
            } else{                         //元素个数为偶数
                s1=m1+1;                    //舍弃A中间点即中间点以前部分
                d2=m2;                      //舍弃B中间点以后部分且保留中间点
            }
        }else{                              //满足条件3
            if((s2+d2)%2==0){               //若元素个数为奇数
                d1=m1;                      //舍弃A中间点以后的部分且保留中间点
                s2=m2;                      //舍弃B中间点以前的部分且保留中间点
            } else{                         //元素个数为偶数
                d1=m1;                      //舍弃A中间点以后部分且保留中间点
                s2=m2+1;                    //舍弃B中间点及中间点以前部分
            }
        }
    }
    return A[s1]<B[s2] ? A[s1]:B[s2];
}


/*
 *@Title:2.2.3.2.12
 *@Description:已知一个整数序列A=(a0,a1,a2,...,an-1)，其中0<=ai<n(0<=i<n).若存在ap1=
 *             ap2=ap3=...=apm=x且m>n/2(0<=pk<n,1<=k<=m)，则称x为A的主元素。
 *             例如A=(0,5,5,3,5,7,5,5),则5为主元素；又如A=(0,5,5,3,5,1,5,7)则A中没有主元素
 *             假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。
 *             若存在主元素，则输出主元素，否则输出-1，要求
 *             1）给出算法的基本设计思想
 *             2）根据设计思想，采用C或C++或Java语言描述算法，关键之处给出注释。
 *             3）说明你所设计算法的时间复杂度和空间复杂度
 *             
 *@Operation:算法思想：从前向后扫描数组元素，标记处一个可能成为主元素的元素num。然后重新计数，
 *                   确认num是否是主元素
 *                   算法可分为两步：
 *                   1）选取候选的主元素，依次扫描数组中每个整数，将遇到的第一个整数num保存到c中
 *                      记录num出现的次数为1；若遇到的下一个整数仍等于Num，则计数加一，否则计数
 *                      减一；当计数减到0时，将遇到的下一个元素保存到c中，计数重新记为1，开始新一轮
 *                      计数，即从当前位置开始重复上述过程，知道扫描玩全部数组元素。
 *                   2）判断c中元素是否时真正的主元素。再次扫描该数组，统计c中元素出现的次数，若大于n/2
 *                      则为主元素；否则序列中不存在主元素
 *
 *
 *                   程序的时间复杂度为O(n),空间复杂度为O(1)
 *@author: NSS
 *@date:2022/2/25
 **/
int Majority(int A[],int n){
    int i,c,count=1;                        //c用来保存候选主元素，count用来计数
    c=A[0];                                 //设置初始候选主元素
    for(i=1;i<n;i++){                       //开始查找主元素
        if(A[i]=c)
            count++;                        //对当前候选主元素计数
        else
            if(count>0)                     //处理不是候选主元素的情况
                count--;
            else{
                c=A[i];                     //更换候选主元素，重新计数
                count=1;
            }
        if(count>0){
            for (i=count = 0;i  < n; i++) { //统计当前候选主元素的实际出现次数
                if(A[i]==c){
                    count++;
                }
            }
        }
        if(count>n/2){
            return c;                       //确认候选主元素
        } else{
            return -1;                      //不存在主元素
        }
    }
}

/*
 *@Title:2.2.3.2.13
 *@Description:
 *@Operation:
 *@author: NSS
 *@date:2022/2/25
 **/







