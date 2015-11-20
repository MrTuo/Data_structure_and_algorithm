#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack(int = 10);
	~stack();
	bool Pop(T& data_iteam);
	bool Push(T& data_iteam);
	inline int number_stacked();
	inline int stack_size();
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