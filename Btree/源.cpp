#include <iostream>
#include "Btree.h"
#include "stack.h"
using namespace std;
struct T_stack{
	int n_child;
	BT tree;
};
BT Build_recu(BT pre[], BT mid[], int &ptr, int n);//��������Ϊ�������У��������У����������еı���ָ�룬�Լ����й�ģ��
BT Build_iter(BT pre[], BT mid, int n);//
bool Find(BT T, BT arr[], int n);//
bool Find(BT T, BT arr[], int &ptr, int n)
{
	for (int i = 0; i < n;i++)
		if (arr[i] == T)
		{
			ptr = i;
			return true;
		}
	return false;
}

BT Build_recu(BT pre[], BT mid[], int &ptr, int n)
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
		root->LT = Build_recu(pre, LTlst, ptr, size_l);//�ݹ鴴��������
		root->RT = Build_recu(pre, RTlst, ptr, size_r);//�ݹ鴴��������
		return root;
	}
}

BT Build_iter(BT pre[], BT mid[], int n)
{
	T_stack s1Top, s2Top,  lchild, rchild,root_stack;
	BT root;
	stack <T_stack> s1, s2;
	int ptr2 = 0, ptr = 0 ;
	int tag[100];/*����һ����־���飬������¼������ʽ�и���Ԫ�ص�״̬�����ȱ�mid��2��tag�ĵڶ�λ��mid��һλ����*/
	for (int i = 0; i < n; i++)
		tag[i + 1] = 0;
	tag[0] = tag[n] = 1;

	while (ptr<n)
	{
		root = pre[ptr];
		root_stack.tree = root;
		root_stack.n_child = 0;
		if (!s1.IsEmpty())
			s1Top = s1.Top();
		if (s1Top.n_child == 2)
		{
			s2.Pop(rchild);
			s2.Pop(lchild);
			s1Top.tree->LT = lchild.tree;
			s1Top.tree->RT = rchild.tree;
			s1.Pop();
			s2.Push(s1Top);
		}
		else
		{
			Find(root, mid, ptr2, n);
			if (tag[ptr2 - 1] && tag[ptr2 + 1])//�����ǰɨ��λ��ǰһλ�ͺ�һλ�������������ǰɨ��λ��Ҷ�ڵ㡣
			{
				s1Top.n_child++;
				s2.Push(root_stack);
			}
			else
				s1.Push(root_stack);
		}
	}
	return pre[0];
}

int main()
{
	char inp[] = "abdcefgh", inp2[100] = "bcdeagfh";
	int a=strlen(inp);
	BT pre[100], mid[100];
	BT tmp;
	Empty(tmp);
	int n, ptr=0;
	n = 8;  
	for (int i = 0; i < n; i++)
	{
		Empty( pre[i]);
		pre[i]->data = inp[i];
		Empty(mid[i]);
		mid[i]->data = inp2[i];
	}
	//tmp = Build_recu(pre, mid, ptr, n);
	tmp = Build_iter(pre, mid, n);
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