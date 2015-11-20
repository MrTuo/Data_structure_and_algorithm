/*功能：输入一个比赛图的n阶关系矩阵，得出一条哈密顿路。
算法思想：主要利用了任意比赛图具有一条哈密顿路这条定理的证明方法。详见：http://blog.csdn.net/yihuikang/article/details/7859335 */

#include <iostream>
using namespace std;
int get_hyrode(int data[][100], int n, int road[])
{
	int count = 1;
	int sum=0;
	int find = 0;
	int point;
	int node;
	int node2;
	int head;

	for (int i = 0; i < n; i++)
		road[i] = -2;

	for (int i = 0; i < n; i++)
	{
		if (!sum)
		{
			for (int j = 0; j < n; j++)
			if (data[i][j] == 1)
			{
				head = i;
				road[i] = j;
				road[j] = -1;
				sum = 2;
				break;
			}
		}
		else
			break;
	}

	while (sum < n)
	{
		for (int i = 0; i < n;i++)
			if (road[i] == -2)
			{
				point = i;
				break;
			}
		node = head;
		find = 0;
		if (data[point][head] == 1)
		{
			road[point] = head;
			head = point;
			find = 1;
		}
		else
		{
			node2 = road[node];
			while (road[node2] != -1)
			{
				node2 = road[node];
				if (data[point][node2]==1)
				{
					road[point] = node2;
					road[node] = point;
					find = 1;
					break;
				}
				node = road[node];
			}
		}
		if (!find)
		{
			road[node2] = point;
			road[point] = -1;
		}
		count++;
		sum++;
	}
	return head;
	
}
int main()
{
	int data[][100] = { { 0, 1, 0, 0, 1 }, { 0, 0, 1, 1, 0 }, { 1, 0, 0, 0, 1 }, { 1, 0, 1, 0, 1 }, { 0, 1, 0, 0, 0 } };
	int n = 5;
	int reslt[5];
	int head;
	int node;
	head = get_hyrode(data, n, reslt);
	node = head;
	cout << node << " << ";
	while (reslt[node]!=-1)
	{
		cout << reslt[node] << " << ";
		node = reslt[node];
	}
	getchar();
}