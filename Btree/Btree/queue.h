#include <iostream>
using namespace std;

template <class T>
class queueItem
{
public:
	queueItem(const T& t) :item(t), next(0){};
	T item;
	queueItem *next;
};

template <class T>
class queue
{
public:
	queue() :head(0), tail(0), size(0){}
	~queue(){ destroy(); }
	T& Front(){ return head->item; }
	int queue_size(){ return size }
	bool Pop(T&);
	void Push(const T&);
	bool Empty(){ return size == 0; };
private:
	queueItem<T> *head;
	queueItem<T> *tail;
	int size;
	void destroy();
};

template <class T>
void queue<T>::Push(const T& data)
{
	queueItem<T>* pt = new queueItem<T>(data);
	if (Empty())
		head = tail = pt;
	else
	{
		tail->next = pt;
		tail = pt;
	}
	size++;
}

template <class T>
bool queue<T>::Pop(T& output)
{
	queueItem<T>* node = head;
	if (!Empty())
	{
		output = head->item;
		head = head->next;
		size--;
		delete node;
		return true;
	}
	else
		return false;
}

template <class T>
void queue<T>::destroy()
{
	int tmp;
	while (!Empty())
		Pop(tmp);
}

