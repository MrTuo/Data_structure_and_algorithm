#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack(int = 10);
	~stack();
	bool Pop(T& data_iteam);
	bool Pop();
	bool Push(T& data_iteam);
	T Top();
	bool IsEmpty();//判断栈内元素是否为空
	inline int number_stacked();//返回当前站内元素个数
	inline int stack_size();//返回栈大小
private:
	int max_size;
	int top;
	T* data;
};

template <class T>
stack<T>::stack(int n)
{
	max_size = n;
	top = -1;
	data = new T[n];
}
template<class T>
stack<T>::~stack()
{
	delete[] data;
}
template<class T>
bool stack<T>::Pop(T& data_iteam)
{
	if (top > -1)
	{
		data_iteam = data[top--];
		return true;
	}
	else
		return false;
}

template<class T>
bool stack<T>::Pop()
{
	if (top > -1)
	{
		top--;
	}
	else
		return false;
}

template<class T>
T stack<T>::Top()
{
		return data[top];
}

template <class T>
bool stack<T>::Push(T& data_iteam)
{
	if (top < max_size)
	{
		data[++top] = data_iteam;
		return true;
	}
	else
		return false;
}
template <class T>
int stack<T>::number_stacked()
{
	return top - 1;
}

template <class T>
int stack<T>::stack_size()
{
	return max_size;
}

template <class T>
bool stack<T>::IsEmpty()
{
	if (number_stacked())
		return 0;
	return 1;
}