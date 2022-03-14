#include <stdio.h>
#include <malloc/malloc.h>
#include <stdbool.h>
#include <stdlib.h>

#define Size 50

typedef int ElemType;
typedef int status;

typedef struct {
	ElemType* elem;
	int length;//���Ա�ǰ����
	int listsize;//���Ա�ǰ��󳤶�
}SqList;

//��ʼ�����Ա�
bool InitList(SqList* L) {
	L->elem = (ElemType*)malloc(sizeof(ElemType) * Size);
	L->length = 0;
	L->listsize = Size;
	return true;
}

//�������Ա����ͷ����Ա�L��ռ���ڴ�ռ�
void DestoryList(SqList* L) {
	free(L->elem);
}

//�����Ա��
status Length(SqList* L) {
	return L->length;
}

//�����Ա�ֵ
bool InPut(SqList* L,int n) {
	for (int i = 0; i < n; i++) {
		L->elem[i]=1;
	};
	return true;
}

//���Ա��пգ���LΪ�ձ���true�����򷵻�false
bool Empty(SqList* L) {
	if (L->length>0)
	{
		return false;
	}
	return true;
}

//���Ա����
void OutPut(SqList* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d\n", L->elem[i]);
	}
}

//�������
bool ListInstert(SqList* L, int i, ElemType e) {
	ElemType* p, *p1, *p2;//p1ָ��Ҫ�����λ�ã�p2ָ�����һ��λ��
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
	}//���ռ䲻������������

	p1 = &L->elem[i - 1];//��p1ָ��Ҫ�����λ��
	for (p2 = &L->elem[L->length - 1]; p2 > p1; p2--) *(p2 + 1) = *p2;
	//for (int j = L->length - 1; j >= i - 1; j--) L->elem[j + 1] = L->elem[j];//ʹ�������ƶ�
	L->elem[i - 1] = e;
	L->length++;
	return true;
}

//ɾ�����Ա��е�Ԫ��
bool ListDelete(SqList* L,int i,ElemType* a) {
	int j;
	if (i<1 || i>L->length)//�ж�ɾ����λ���Ƿ�Ϸ�
	{
		return false;
	}
	if (L->length==0)//�ж��Ƿ��ǿձ�
	{
		return false;
	}

	*a = L->elem[i - 1];//����ɾ����Ԫ�ظ�ֵ��a
	for (j= i ; j<L->length; ++j)
	{
		L->elem[j - 1] = L->elem[j];
	}
	L->length--;
	return true;
}

//��λ���ң��ڱ�L�в��ҵ�i��λ�õ�Ԫ�ص�ֵ
void GetElem(SqList* L,int i,ElemType* e) {

	*e = L->elem[i - 1];
}

//�޸����Ա�ָ��λ�õ�Ԫ��ֵ��iΪ��Ҫ�޸ĵ�λ�ã�e�޸ĵ�Ԫ��
bool UpdateElem(SqList* L, int i, ElemType* e) {
	if (i<1 || i>L->length + 1) {
		printf("�޸ĵ�λ�ò��Ϸ�������");
			return false;
	}
	if (L->length==0)
	{
		printf("�ñ�Ϊ�ձ�������������");
		return false;
	}
	L->elem[i - 1] = *e;
	return true;
}

//2.2.3 ���Ա�����Ӧ���� �����⣺
//���������ɾ����ֵ�ڸ���ֵs��t֮�䣨Ҫ��s<t��������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
bool Del_s_t2(SqList* L, ElemType s, ElemType t) {
	int i, j;
	if (s >= t ||L->length==0) return false;
	for (i = 0; i < L->length && L->elem[i] < s; i++);//Ѱ��ֵ���ڵ���s�ĵ�һ��Ԫ��
	if (i >= L->length) return false;//����ֵ��С��s������
	for (j = i; j < L->length && L->elem[j] <= t; j++);//Ѱ��ֵ����t�ĵ�һ��Ԫ��
	for (; j < L->length; i++, j++) L->elem[i] = L->elem[j];
	L->length = i;
	return true;
}

//2.2.3 ���Ա�����Ӧ���� �����⣺
//��˳�����ɾ����ֵ�ڸ���ֵs��t֮�䣨����s��t��Ҫ��s<t��������Ԫ�أ���s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳�����
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

//������˳�����ɾ��������ֵ�ظ���Ԫ�أ�ʹ��������Ԫ�ؾ�����ͬ
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

