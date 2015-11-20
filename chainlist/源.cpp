/*链表维护，没什么意思*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

struct Data
{
	string name;
	string brand;
	double price;
	int count;
};
struct Node{
	Data data;
	Node* next;
};

class ChainList
{
public:
	Node* head;
	int length;
	ChainList();
	~ChainList()
	{
		Node* node;
		while (head != NULL)
		{
			node = head;
			head = node->next;
			delete(node);
		}
	};
	void Insert(Data data);
	//void Insert(int pos, Data data);
	int Locate(Data data);
	//int Locate(int pos, Data data);
	//Data Retrieve(int pos);
	void Update(int pos, Data data);
	Data Pop(int pos);
	//void MakeNull();
	//void First();
	//void ExternFunc();
};


ChainList::ChainList()// 构造函数
{
	head = new Node;
	head->next = NULL;
}

void ChainList::Insert(Data data)//析构函数
{
	Node* p = new Node;
	p->data = data;
	p->next = head->next;
	head->next = p;
}
void ChainList::Update(int pos, Data data)//更新数据
{
	int p = 0;
	Node* node=head->next;
	while (p < pos)
	{
		node = node->next;
		p++;
	}
	node->data = data;
}

Data ChainList::Pop(int pos)//删除并返回pos位置的元素
{
	int p = 0;
	Data tmp;
	Node* node = head->next,*node2;
	if (pos == 0)
	{
		node = head;
		tmp = node->data;
		head = head->next;
		delete node;
		return tmp;
	}
	while (p < pos-1)
	{
		node = node->next;
		p++;
	}
	node2 = node->next;
	tmp = node2->data;
	node->next = node2->next;
	delete node2;
	return tmp;
}

void save_data(ChainList &ch)//将数据存储到文件夹
{
	ofstream out;
	out.open("file.txt");
	Node* node;
	node = ch.head->next;
	if (out.fail())
	{
		cerr << "Open error!" << endl;
		return;
	}
	while (node != NULL)
	{
		out << node->data.name <<" "<< node->data.brand << " " <<node->data.price <<" "<< node->data.count << endl;
		node = node->next;
	}
	out.close();
}

void read_data(ChainList &ch)//从文件夹中读取数据
{
	ifstream in;
	Data tmp;
	int count = 0;
	char c;
	in.open("file.txt");
	if (in.fail())
	{
		cerr << "Open error!" << endl;
		return;
	}
	while (!in.eof())
	{
		in >> tmp.name >> tmp.brand >> tmp.price >> tmp.count;
		count++;
		ch.Insert(tmp);
		in.get(c);
	}
	ch.Pop(0);
}

int main()
{
	Data d1,tmp_data;
	Node* node;
	int op,op2;
	string tmp_name;
	ChainList ch;
	int find;
	int pos;
	do
	{
		cout << "Wellcome to the Product Menagement System! Please input your choise:" << endl;
		cout << "1.Read data" << endl;
		cout << "2.Insert the Product" << endl;
		cout << "3.Index the Product(include update & delete)" << endl;
		cout << "4.Show All Product" << endl;
		cout << "5.Exit the system and save data" << endl;
		cin>>op;
		switch (op)
		{
		case 1:
			read_data(ch);
			cout << "Load successfully!"<<endl;
			break;
		case 2:
			cout << "Please input the name of the Product:";
			cin >> tmp_data.name;
			getchar();
			cout << "Please input the brand of the Product:";
			cin >> tmp_data.brand;
			getchar();
			cout << "Please input the price of the Product:";
			cin >> tmp_data.price;
			cout << "Please input the count of the Product:";
			cin >> tmp_data.count;
			ch.Insert(tmp_data);
			cout << endl;
			cout << "Insert successfully!" << endl;
			break;
		case 3:
			find = 0;
			cout << "Please input the name you want to index:";
			pos = 0;
			cin >> tmp_name;
			node = ch.head->next;
			while (node != NULL)
			{
				if (node->data.name == tmp_name)
				{
					tmp_data = node->data;
					find = 1;
					break;
				}
				node = node->next;
				pos++;
			}
			if (!find)
				cout << "Not found!" << endl;
			else
			{
				cout << "Name" << "\t" << "Brand" << "\t" << "Price" << "\t" << "Count" << endl;
				cout << tmp_data.name << "\t" << tmp_data.brand << "\t" << tmp_data.price << "\t" << tmp_data.count << endl;
				cout << "Do you  want to update or delete it?" << endl;
				cout << "1.Update" << endl;
				cout << "2.delete" << endl;
				cin >> op2;
				if (op2 == 1)
				{
					cout << "Please input the name of the Product:";
					cin >> tmp_data.name;
					getchar();
					cout << "Please input the brand of the Product:";
					cin >> tmp_data.brand;
					getchar();
					cout << "Please input the price of the Product:";
					cin >> tmp_data.price;
					cout << "Please input the count of the Product:";
					cin >> tmp_data.count;
					ch.Update(pos, tmp_data);
					cout << "Update successfully!" << endl;
				}
				else if (op2 == 2)
				{
					ch.Pop(pos);
					cout << "Delete successfully!" << endl;
				}

			}
			break;
		case 4:
			node = ch.head->next;
			while (node != NULL)
			{
				tmp_data = node->data;
				cout << "Name" << "\t" << "Brand" << "\t" << "Price" << "\t" << "Count" << endl;
				cout << tmp_data.name << "\t" << tmp_data.brand << "\t" << tmp_data.price << "\t" << tmp_data.count << endl;
				node = node->next;
			}
			break;
		case 5:
			save_data(ch);
			cout << "Save successfully!" << endl;
			getchar();
			getchar();
			return 0;
			break;
		default:
			cout << "Input error!" << endl;
			break;
		}
	} while (1);
	
	getchar();
	return 0;
}
