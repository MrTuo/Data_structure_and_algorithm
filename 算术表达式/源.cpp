/*功能实现：一个简单的中缀转后缀，再进行计算的算术表达式求值。支持个浮点数运算，输入表达式合法性没有检测。
算法：详见：http://blog.csdn.net/liuhuiyi/article/details/8433203 */

#include <iostream>
#include <string>
#include <math.h>
#include <Limits.h>
using namespace std;
struct Node{
	string data;
	Node *next;
};
typedef Node * Stack;

void MakeNull(Stack s)
{
	s = new Node;
	s->next = NULL;
	s->data = "";
}
int Pop(Stack s)
{
	Stack stk;
	if (s->next != NULL)
	{
		stk = s->next;
		s->next = stk->next;
		delete stk;
		return 1;
	}
	else
		return 0;
}

void Push(Stack s, string c)
{
	Stack node;
	node = new Node;
	node->data = c;
	node->next = s->next;
	s->next = node;
}

string Top(Stack s)
{
	if (s->next == NULL)
		return " ";
	else
		return s->next->data;
}

int Empty(Stack s)
{
	if (s->next == NULL)
		return 1;
	return 0;
}

int cmp_op(char a, char b)
{
	char op[][4] = { "()", "*/%", "+-", };
	int la, lb;
	int len;
	for (int i = 0; i < 3; i++)
	{
		len = strlen(op[i]);
		for (int j = 0; j < len; j++)
		{
			if (op[i][j] == a)
				la = i;
			if (op[i][j] == b)
				lb = i;
		}
	}
	if (la == lb)
		return 0;
	else if (la>lb)
		return -1;
	return 1;
}



float c_to_n(string s)
{
	int sym = 1;
	float ans = 0;
	int pos;
	if (s[0] == '!' || s[0] == '-')
	{
		sym = -1;
		s.erase(0, 1);
	}
	pos = s.find('.');
	if (pos == -1)
		pos = s.length();
	else
		s.erase(pos, 1);
	for (int i = 0; i < s.length(); i++)
		ans += (s[i] - '0')*pow(10, pos - 1 - i);
	return ans * sym;
}
string n_to_c(float a)
{
	char str[20];
	string str1;
	_gcvt_s(str, 20, a, 4);
	str1.assign(str);
	return str1;
}

int is_int(float a)
{
	if ((int)a - a == 0)
		return 1;
	return 0;
}

void calculate(string str)
{
	int len;
	int count_n = 0, count_p = 0;
	int has_num;
	float reslt;
	float a1, a2;
	Stack s = new Node;
	s->next = NULL;
	s->data = "";
	string num_s;
	string op2;
	string p_exp[100];
	char op;

	if (str[0] == '-')
	{
		str[0] = '!';
		if (str[1] == '(')
			str.insert(1, "1*");
	}

	len = str.length();
	for (int i = 1; i < len; i++)
	{
		if (str[i] == '-'&&str[i - 1] == '(')
			str[i] = '!';
	}
	for (int i = 0; i < len; i++)
	{
		op2 = "";
		op = Top(s)[0];
		has_num = 0;
		while (isdigit(str[i]) || str[i] == '.' || str[i] == '!')
		{
			p_exp[count_p] += str[i++];
			has_num = 1;
		}
		if (has_num)
			count_p++;
		if (i < len)
		{
			if (str[i] == ')')
			{
				while (Top(s) != "(")
				{
					p_exp[count_p++] = Top(s);
					Pop(s);
				}
				Pop(s);
			}
			else  if (Empty(s) || Top(s) == "(")
			{
				op2 += str[i];
				Push(s, op2);
			}
			else if (cmp_op(op, str[i]) != -1)
			{
				while (cmp_op(Top(s)[0], str[i]) != -1&& Top(s)!="("&& !Empty(s))
				{
					p_exp[count_p++] = Top(s);
					Pop(s);
				}
				op2 += str[i];
				Push(s, op2);
			}
			else
			{
				op2 += str[i];
				Push(s, op2);
			}
		}
	}
	while (!Empty(s))
	{
		p_exp[count_p++] = Top(s);
		Pop(s);
	}
	cout << "后缀表达式为：";
	for (int i = 0; i < count_p; i++)
		cout << p_exp[i] << " ";
	cout << "" << endl;
	cout << endl;
	for (int i = 0; i < count_p; i++)
	{
		if (isdigit(p_exp[i][0]) || p_exp[i][0] == '!')
			Push(s, p_exp[i]);
		else
		{
			a1 = c_to_n(Top(s));
			Pop(s);
			a2 = c_to_n(Top(s));
			Pop(s);
			switch (p_exp[i][0])
			{
			case '+':
				reslt = a2 + a1;
				break;
			case '-':
				reslt = a2 - a1;
				break;
			case '*':
				reslt = a2*a1;
				break;
			case '/':
				if (fabs(a1) <= 1e-6)
				{
					cout << "ERROR！运算式中有除数为零！" << endl;
					return;
				}
				reslt = a2 / a1;
				break;
			case '%':
				if (!is_int(a1) || !is_int(a2))
				{
					cout << "ERROR!求余运算操作数中出现小数！" << endl;
					return;
				}
				else
				{
					reslt = (int)a2 % (int)a1;
				}
			}
			Push(s, n_to_c(reslt));
		}
	}
	reslt = c_to_n(Top(s));
	cout << "计算结果为：" << reslt << endl;
}

int main()
{
	string exp;
	cin >> exp;
	calculate(exp);
	getchar();
	getchar();
	return 0;
}