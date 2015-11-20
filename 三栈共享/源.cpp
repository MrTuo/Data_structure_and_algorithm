/*功能：实现固定空间内的三栈共享空间，主要实现各栈空间分配，以及出栈后，剩余空间的回收
算法：各栈元素通过静态链表的右边表示方式连接起来。剩余空间也通过这种方式进行连接*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	int next;
};

class ShareRoomStack
{
public:
	Node* arr;//指定空间的起始指针
	int len;//储存指定空间的长度
	int rest;//储存剩余空间静态链表的头
	int count;//储存元素个数；

	ShareRoomStack(Node *room,int n);
	int MakeNull(int n);//参数n表示在n号栈下执行操作，下同
	int top(int n);
	int pop(int n);
	int push(int x, int n);
	int empty(int n);
	void show();
};
ShareRoomStack::ShareRoomStack(Node *room,int n)
{
	arr = room;
	len = n;
	//以下为建立剩余空间的静态链表
	for (int i = 0; i < 3; i++)//空间中前三个站内next赋值为0
	{
		arr[i].next = 0;
	}
	for (int i = 3; i < len - 1; i++)//空间中第四个元素开始往后至倒数第二个元素的next赋值为元素所在位置加一
	{
		arr[i].next = i + 1;
	}
	arr[len - 1].next = -1;//最后一个值赋值为-1；表示静态链表的尾部；
	rest = 3;
}
int ShareRoomStack::MakeNull(int n)
{
	int node;//指向被清空站得栈顶元素
	int node_m;//保存node值
	node = arr[n].next;
	while (arr[node].next != 0)//循环到栈底
	{
		node_m = node;
		node = arr[node].next;
		arr[node_m].next = arr[rest].next;//头插法向剩余空间链表中插入node；
		arr[rest].next = node_m;
	}
	arr[node].next = arr[rest].next;//头插法向剩余空间链表中插入node；
	arr[rest].next = node;
	arr[n].next = 0;
	return 1;
}

int ShareRoomStack::pop(int n)
{
	if (arr[n].next == 0)
		return 0xfff;

	int node = arr[n].next;
	int data = arr[node].data;

	arr[n].next = arr[node].next;//删除栈顶元素

	arr[node].next = arr[rest].next;//回收空间
	arr[rest].next = node;

	return data;
}

int ShareRoomStack::push(int x, int n)
{
	if (arr[rest].next == -1)
		return 0;//栈满
	int node = rest;
	rest = arr[rest].next;//申请空间
	arr[node].data = x;
	arr[node].next = arr[n].next;
	arr[n].next = node;
	return 1;
}

int ShareRoomStack::empty(int n)
{
	for (int i = 0; i < len; i++)
		cout << arr[i].next <<"；"<< endl;
	if (arr[n].next == 0)
		return 1;
	return 0;
}

void ShareRoomStack::show()
{
	int node;
	for (int i = 0; i < len; i++)
	{
		cout << i <<"    "<<arr[i].data << "|" << arr[i].next << ","<<endl;
	}
	for (int i = 0; i < 3; i++)
	{
		node = arr[i].next;
		cout << i << "栈内元素为：";
		while (node != 0)
		{
			cout << arr[node].data << ",";
			node = arr[node].next;
		}
		cout << endl;
	}
	cout << "剩余空间位置为：";
	node = rest;
	while (node != -1)
	{
		cout << node<<"；";
		node = arr[node].next;
	}
	return;
}
int main()
{
	int a[] = {8,1,5,6,7,2,-1,-3};
	int node;
	Node arr1[13];
	ShareRoomStack s(arr1,13);
	cout << "例：将如下元素依次入栈：8，1，5，6，7，2，-1，-3" << endl;
	cout << "入栈规则为：0栈（x<=0）；1栈（0<x<=5）;二栈（x>5）" << endl;
	for (int i = 0; i < 8; i++)
	{
		if (a[i] < 0)
		{
			s.push(a[i], 0);
		}
		else if (a[i]>0&&a[i]<=5)
		{
			s.push(a[i], 1);
		}
		else
		{
			s.push(a[i], 2);
		}
	}
	s.show();
	cout << "按任意键清除1栈元素。。。";
	getchar();
	s.MakeNull(1);
	s.show();
	getchar();
	return 0;
}