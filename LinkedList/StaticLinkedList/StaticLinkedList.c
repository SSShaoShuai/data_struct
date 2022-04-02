//
// Created by ������ on 2022/3/30.
//

/*��̬����*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct {
    ElemType data;
    int next;
}SLinkList[MaxSize];

//��ʼ����̬����
void  InitSLinkList(SLinkList L){
    for (int i=0;i<MaxSize;i++){
        L[i].next=-2;   //-2��ʾ�������λ���ǿյ�
    }
    L[0].next=-1;
}

//�жϾ�̬�����Ƿ�Ϊ��
bool Empty(SLinkList L){
    if(L[0].next=-1){
        return true;
    }
    return false;
}

//�õ���i��Ԫ�ص��±�
int Get_Index(SLinkList L,int i){
    int j=0;  //ģ��ָ��
    int cnt=0;   //����
    while (j!=-1 && cnt<i){
        cnt++;
        j=L[j].next;
    }
    if(cnt!=i) return -1;  //������
    return j;
}

//�õ���һ����Ԫ��
int Get_First_Empty_Node(SLinkList L){
    for (int i = 1; i <MaxSize ; i++) {
        if(L[i].next==-2) return i;
    }
}

//����L�ĵ�i��Ԫ�ص�ֵ
ElemType GetElem(SLinkList L,int i){
    int j= Get_Index(L,i);
    return L[j].data;
}

//�ڵ�i���ڵ�������ֵ��e�ڽڵ�
bool InsertNextSNode(SLinkList L,int i,ElemType e){
    int j= Get_Index(L,i);
    int k=0;
    for (int i=1;i<MaxSize;i++){
        if(L[i].next==-2){
            k=i;
            break;
        }
    }
    L[k].next=L[j].next;
    L[j].next=k;
    L[k].data=e;
    return true;
}

//ɾ����i���ڵ� e��ɾ��Ԫ�ص�ֵ
/*���ɾ�����һ���ڵ㣬�򽫸ýڵ��nextֵ��Ϊ-2�����ýڵ��ǰ�ýڵ��nextֵ��Ϊ-1*/
/*������м�ڵ㣬����Ҫɾ���Ľڵ��ֵ��ֵΪ�ýڵ�ĺ�̽ڵ��ֵ�������ú��ýڵ��next��ֵ��Ϊ-2*/
bool DeleteNode(SLinkList L,int i,ElemType *e){
    int j= Get_Index(L,i);
    if(L[j].next==-1){      //���һ�����⴦��
        int k= Get_Index(L,i-1);
        L[j].next=-2;
        e=L[j].data;
        L[k].next=-1;
        return true;
    }
    //�൱�ڽ�������
    e=L[j].data;
    int tmp=L[L[j].next].data;
    L[j].data=L[L[j].next].next;
    L[tmp].next=-2;
    return true;
}

//����(Ĭ�Ͽ�ʼ�ǿյ�)
bool List_Insert(SLinkList L){
    int tot=1,pre=0;
    ElemType x;
    scanf("%d",&x);
    while (x!=9999){
        L[tot].data=x;
        L[tot].next=-1;
        L[pre].next=tot;
        pre=tot++;
    }
    return true;
}

void Print_List(SLinkList L){
    int i=L[0].next;
    while (i>0){
        printf("%d",L[i].data);
        i=L[i].next;
    }
    printf("����������");
}

void testSLinkList(){

}
