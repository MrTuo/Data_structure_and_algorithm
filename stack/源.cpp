/*��Ҫ������ͷ�ļ���ԭ����Ҫ��һ��ջ����ģ�壬û��ס�Ѷ��кͶ�����Ҳ���ˡ�����*/
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "Btree.h"
using namespace std;

/*BT Build(BT pre[], BT mid[], int &ptr, int n)
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
}*/

int main()
{
	/*stack<int> s(10);
	queue<int> q;
	Btree<int> t(0),t1(1),t2(2),t3(3),t4(4);
	t.SetL(t1);
	t.SetR(t2);
	t2.SetL(t3);
	t2.SetR(t4);
	t.PreOrder();
	t.InOrder();
	t.PostOrder();*/

	/*int a = 1, b;
	int a2[] = { 1, 2, 3, 4, 6, 4 };
	for (int i = 0; i < 6; i++)
	{
		b = a2[i];
		s.Push(b);
		q.Push(b);
	}
	for (int i = 0; i < 6; i++)
	{
		q.Pop(b);
	}*/
	char inp[] = "abdecf", inp2[100] = "dbeacf";
	int a = strlen(inp);
	Btree<char> pre[100], mid[100];
	for (int i = 0; i < a; i++)
	{
		pre[i].SetI(inp[i]);
		pre[i].SetI(inp2[i]);
	}

	getchar();
	return 0;
}