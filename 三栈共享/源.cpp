/*���ܣ�ʵ�̶ֹ��ռ��ڵ���ջ����ռ䣬��Ҫʵ�ָ�ջ�ռ���䣬�Լ���ջ��ʣ��ռ�Ļ���
�㷨����ջԪ��ͨ����̬������ұ߱�ʾ��ʽ����������ʣ��ռ�Ҳͨ�����ַ�ʽ��������*/

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
	Node* arr;//ָ���ռ����ʼָ��
	int len;//����ָ���ռ�ĳ���
	int rest;//����ʣ��ռ侲̬�����ͷ
	int count;//����Ԫ�ظ�����

	ShareRoomStack(Node *room,int n);
	int MakeNull(int n);//����n��ʾ��n��ջ��ִ�в�������ͬ
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
	//����Ϊ����ʣ��ռ�ľ�̬����
	for (int i = 0; i < 3; i++)//�ռ���ǰ����վ��next��ֵΪ0
	{
		arr[i].next = 0;
	}
	for (int i = 3; i < len - 1; i++)//�ռ��е��ĸ�Ԫ�ؿ�ʼ�����������ڶ���Ԫ�ص�next��ֵΪԪ������λ�ü�һ
	{
		arr[i].next = i + 1;
	}
	arr[len - 1].next = -1;//���һ��ֵ��ֵΪ-1����ʾ��̬�����β����
	rest = 3;
}
int ShareRoomStack::MakeNull(int n)
{
	int node;//ָ�����վ��ջ��Ԫ��
	int node_m;//����nodeֵ
	node = arr[n].next;
	while (arr[node].next != 0)//ѭ����ջ��
	{
		node_m = node;
		node = arr[node].next;
		arr[node_m].next = arr[rest].next;//ͷ�巨��ʣ��ռ������в���node��
		arr[rest].next = node_m;
	}
	arr[node].next = arr[rest].next;//ͷ�巨��ʣ��ռ������в���node��
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

	arr[n].next = arr[node].next;//ɾ��ջ��Ԫ��

	arr[node].next = arr[rest].next;//���տռ�
	arr[rest].next = node;

	return data;
}

int ShareRoomStack::push(int x, int n)
{
	if (arr[rest].next == -1)
		return 0;//ջ��
	int node = rest;
	rest = arr[rest].next;//����ռ�
	arr[node].data = x;
	arr[node].next = arr[n].next;
	arr[n].next = node;
	return 1;
}

int ShareRoomStack::empty(int n)
{
	for (int i = 0; i < len; i++)
		cout << arr[i].next <<"��"<< endl;
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
		cout << i << "ջ��Ԫ��Ϊ��";
		while (node != 0)
		{
			cout << arr[node].data << ",";
			node = arr[node].next;
		}
		cout << endl;
	}
	cout << "ʣ��ռ�λ��Ϊ��";
	node = rest;
	while (node != -1)
	{
		cout << node<<"��";
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
	cout << "����������Ԫ��������ջ��8��1��5��6��7��2��-1��-3" << endl;
	cout << "��ջ����Ϊ��0ջ��x<=0����1ջ��0<x<=5��;��ջ��x>5��" << endl;
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
	cout << "����������1ջԪ�ء�����";
	getchar();
	s.MakeNull(1);
	s.show();
	getchar();
	return 0;
}