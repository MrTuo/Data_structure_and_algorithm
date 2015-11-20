#include <iostream>
#include "Btree.h"
using namespace std;
BT Build(BT pre[], BT mid[], int &ptr, int n);//��������Ϊ�������У��������У����������еı���ָ�룬�Լ����й�ģ��

BT Build(BT pre[], BT mid[], int &ptr, int n)
{

	if (n == 0)//�������������������������Ҷ�ڵ�����Խ���һ����
	{
		return NULL;
	}
	else//����ֱ������������к�����������
	{
		BT LTlst[100], RTlst[100];
		int size_l = 0, size_r = 0;
		int shift = 0;
		BT root = pre[ptr];//��ȡ���ڵ�
		for (int i = 0; i < n; i++)//ͨ�������Ӹ��ڵ㽫������ʽ��Ϊ�������ڵ���������ڵ�
		{
			if (mid[i]->data == root->data)
				shift = 1;
			else if (shift)
				RTlst[size_r++] = mid[i];
			else
				LTlst[size_l++] = mid[i];
		}
		ptr++;// �ƶ�������ʽָ��
		root->LT = Build(pre, LTlst, ptr, size_l);//�ݹ鴴��������
		root->RT = Build(pre, RTlst, ptr, size_r);//�ݹ鴴��������
		return root;
	}
}


int main()
{
	char inp[] = "abdecf", inp2[100] = "dbeacf";
	int a=strlen(inp);
	BT pre[100], mid[100];
	BT tmp;
	Empty(tmp);
	int n, ptr=0;
	n = 6;  
	for (int i = 0; i < n; i++)
	{
		Empty( pre[i]);
		pre[i]->data = inp[i];
		Empty(mid[i]);
		mid[i]->data = inp2[i];
	}
	tmp = Build(pre, mid, ptr, n);
	cout << "���������";
	PreOrder(tmp);
	cout << endl;
	cout << "���������";
	InOrder(tmp);
	cout << endl;
	cout << "���������";
	PostOrder(tmp);

	getchar();
	return 0;
}