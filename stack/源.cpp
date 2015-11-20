/*主要是三个头文件，原本想要做一个栈的类模板，没忍住把队列和二叉树也做了。。。*/
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "Btree.h"
using namespace std;

/*BT Build(BT pre[], BT mid[], int &ptr, int n)
{

	if (n == 0)//如果先序序列中左右子树都是叶节点则可以建立一个树
	{
		return NULL;
	}
	else//否则分别处理左子树序列和右子树序列
	{
		BT LTlst[100], RTlst[100];
		int size_l = 0, size_r = 0;
		int shift = 0;
		BT root = pre[ptr];//获取根节点
		for (int i = 0; i < n; i++)//通过遍历从根节点将先序表达式分为左子树节点和右子树节点
		{
			if (mid[i]->data == root->data)
				shift = 1;
			else if (shift)
				RTlst[size_r++] = mid[i];
			else
				LTlst[size_l++] = mid[i];
		}
		ptr++;// 移动先序表达式指针
		root->LT = Build(pre, LTlst, ptr, size_l);//递归创建左子树
		root->RT = Build(pre, RTlst, ptr, size_r);//递归创建右子树
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