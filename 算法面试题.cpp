#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
//不用数据结构   用递归实现逆序栈 
/*
int getStackBottom(stack<int> &s)
{
	int ret = -1;
	int val;
	if( !s.empty())
	{
		if( s.size() != 1)
		{
			val = s.top();
			s.pop();
			ret = getStackBottom(s);
			s.push(val);
		}
		else
		{
			ret = s.top();
			s.pop();
		}
	}
	return ret;
}
void reverseSatck(stack<int>& s)
{
	int val;
	if(!s.empty())
	{
		val = getStackBottom(s);
		reverseSatck(s);
		s.push(val);	
	}

}
int main()
{
	stack<int> stk;
	int i = 0;
	stk.push(0);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	printf("size:%d\n",stk.size());
	reverseSatck(stk);
	while(!stk.empty())
	{
		printf("%d\n",stk.top());
		stk.pop();
	}
	return 0;
}
*/

//寻找数组中 连续最大和序列 

/*
int findMax(int a[], int len, int* left, int* right)
{
	int ret = (a != NULL && left != NULL && right != NULL && len > 0);
	if( ret )
	{
		int cur = 0;
		int max = 0;
		int i;
		for(i=0; i < len; ++i)
		{
			cur += a[i];
			
			if(cur < 0 )
			{
				cur = 0;
				*left = i;
			}

			if(max <= cur)
			{
				*right = i;
				max = cur;
			}
		}
		ret = max;
	}
	return ret;
}

int main()
{
	int a[] = {4,3,2,1,0,-1,-2,-3,-1};
	int l=0,r=0;
	int sum = findMax(a,9,&l,&r);
	printf("sum:%d   l:%d   r:%d\n",sum,l,r);
	
	return 0;
}*/

//链表逆序 
/* 
typedef struct _tag_node Node;
typedef struct _tag_node
{
	Node* next;
	int val;
}Node;

void list_insert(Node** head,int index,Node* node)
{
	if(head != NULL && node != NULL && index >=0)
	{
		if(*head != NULL)
		{
			if( index == 0)
			{
				node->next = *head;
				*head = node;
			}
			else
			{
				Node* cur = *head;
				while( cur != NULL && --index > 0 )
				{
					cur = cur->next;
				}
				node->next = cur->next;
				cur->next  = node;	
			}
			
		}
		else
		{
			node->next = NULL;
			*head = node;	
		}
	}
}
void list_reverse(Node** head)
{
	if(head != NULL && *head != NULL)
	{
		Node* pre  = *head;
		Node* cur  = pre->next;
		Node* next = cur->next;
		
		pre->next = NULL;
		while(next != NULL)
		{
			cur->next = pre;
			pre = cur;
			cur = next;
			next = next->next;	
		}
		cur->next = pre;
		*head = cur;
	}
}

Node* reverse_list(Node* list)
{
	if(list == NULL || list->next == NULL)
	{
		return list;
	}
	else
	{
		Node* guard = list->next;
		Node* ret = reverse_list(list->next);
		guard->next = list;
		list->next = NULL;
		return ret;
	}
}



void print(Node* head)
{
	if( head != NULL)
	{
		while(head != NULL)
		{
			//printf("%d\n",head->val);
			cout<<head->val<<"->";
			head = head->next;
		}
	}
	cout<<"NULL"<<endl;

}
int main()
{
	Node a = {NULL,1};
	Node b = {NULL,2};
	Node c = {NULL,3};
	Node d = {NULL,4};
	Node e = {NULL,5};
	Node f = {NULL,6};
	Node* head = NULL;
	list_insert(&head,0,&a);
	list_insert(&head,0,&b);
	list_insert(&head,0,&c);
	list_insert(&head,0,&d);
	list_insert(&head,0,&e);
	list_insert(&head,0,&f);
	print(head);
	head = reverse_list(head);
	print(head);
	
	return 0;
}
*/

//输入一段字符串 仅包含R G B Y四种字符  随机输入后 字符串长度大于1 小于10  
//若想相邻字符串不相等  则最少需要调换多少次
/*
string s;
int main() {
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i - 1] == s[i]) {
            cnt++;
            i++;
        }
    }
    cout << cnt << endl;
    return 0;
}*/

/*
int isSynbol(char c)
{
	if(c == 'A' || c == 'T'||c == 'C' || c == 'G')
		return 1;
	else
		return 0;	
}
int maxLen(string a)
{
	int ret=0;
	if(a.size() > 0)
	{ 
	    int sum = 0;
	    int max = 0;
		for(int i=0; i < a.size(); ++i)
		{
			if(isSynbol(a[i]) == 1)
			{
				sum += 1;
				max = max > sum ? max : sum;
			}
			else
			{
				sum = 0;
			}
		}
		ret = max;
	}
	return ret;
}
int main()
{
	string s;
	cin>>s;
	cout<<maxLen(s)<<endl;
}*/

//如果一个字符串由两个相同字符串连接而成,就称这个字符串是偶串。例如"xyzxyz"和"aaaaaa"是偶串,但是"ababab"和"xyzxy"却不是。
//牛牛现在给你一个只包含小写字母的偶串s,你可以从字符串s的末尾删除1和或者多个字符,保证删除之后的字符串还是一个偶串,牛牛想知道删除之后得到最长偶串长度是多少。 
/*
int main() 
{
	string s;
    cin >> s;
   for (int slen = (s.size() - 1) / 2; slen >= 1; slen--) 
	{
        bool is_even_str = true;
        for (int i = 0; i < slen; i++) 
		{
            if (s[i] != s[slen + i]) 
			{ 
                is_even_str = false;
                break;
            }
        }
        if (is_even_str)
	    {
            cout << (slen * 2) << endl;
            break;
        }
    }
    return 0;
}*/
/*
//统计一个整数中 1的个数
int numOf1(int val)
{
	int cnt=0;
	while(val != 0)
	{
		val &= val - 1;
		cnt++;
	}
	return cnt;
} 
//判断一个数是不是2的次方  (二进制中有且只有一位为 1 )
int isOf2(int val)
{
	return !(val &= val - 1);
} 
//两个整数m，n  若要使得m n相等 ，需要改动其二进制位多少位次 
int numOfmov(int m,int n)
{
	int cnt = 0;
	int tmp = m ^ n;
	while(tmp != 0)
	{
		tmp &= tmp -1;
		cnt++;
	}
	return cnt;
} 
int main()
{
//	printf("%d\n",numOf1(0x80000000));
//	printf("%d\n",isOf2(0x80000000));
	printf("%d\n",numOfmov(0x11110,0x11));
}

 */
 
 /*
	给定一个链表，对于每二个相邻的节点，交换其位置。
	如链表为：1->2->3->4->NULL
	返回：2->1->4->3->NULL
	只能够对节点操作，不能修改节点的值。
*/
/*
struct Node
{
	Node* next;
	int data;
};
void list_insert(Node** head,int index,Node* node)
{
	if(head != NULL && node != NULL && index >=0)
	{
		if(*head != NULL)
		{
			if( index == 0)
			{
				node->next = *head;
				*head = node;
			}
			else
			{
				Node* cur = *head;
				while( cur != NULL && --index > 0 )
				{
					cur = cur->next;
				}
				node->next = cur->next;
				cur->next  = node;	
			}
			
		}
		else
		{
			node->next = NULL;
			*head = node;	
		}
	}
}
void printList(Node* p)
{
	while(p != NULL)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<"NULL"<<endl;
}
void changePosition(Node** head)
{
	Node* p1,*p2,*p3;
	p1 = *head;
	p2 = p1->next;
	p3 = p2->next;
	*head = p2;
	while(p3 != NULL)
	{
		p2->next = p1;
		p1->next = p3->next;
		
		p1 = p3;
		p2 = p3->next;
		p3 = p2->next;
	}
	p2->next = p1;
	p1->next = NULL;
}
int main()
{
	Node a = {NULL,1};
	Node b = {NULL,2};
	Node c = {NULL,3};
	Node d = {NULL,4};

	Node* head = NULL;
	list_insert(&head,0,&a);
	list_insert(&head,1,&b);
	list_insert(&head,2,&c);
	list_insert(&head,3,&d);

	printList(head);
    changePosition(&head);
	printList(head);
}
*/

/*

int isCh(char c)
{
	return c <= '9' && c >= '0';
}
int isOperator(char c)
{
	if( c=='+' || c=='-' )
	{
		return 1;
	}else	if( c== '*' || c== '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}	
}
//中缀表达式转后缀表达式
void transform(char s[], char d[])
{
	stack<char> stck;
	//int len = strlen(s);
	int i=0,j=0;
	while( s[i] != '\0')
	{
		if( isCh(s[i]) )
		{
			d[j++] = s[i];	
		} 
		else if( isOperator(s[i]) )
		{
			while( !stck.empty() && ( isOperator(s[i]) <= isOperator(stck.top()) ))
			{
				d[j++] = stck.top();
				stck.pop();
			}
			stck.push(s[i]);
		}
		else if( s[i] == '(' )
		{
			stck.push(s[i]);
		}
		else if(s[i] == ')')
		{
			while(  !stck.empty() && stck.top() != '(')
			{
				d[j++] = stck.top();
				stck.pop();
			}
			stck.pop();
		}
       ++i;	
	}
	while( !stck.empty() )
	{
		d[j++] = stck.top();
		stck.pop();
	}
	d[j] = '\0';
}

int value(char c)
{
	return c - '0';
}

int express(int l, int r, char opt)
{
	int ret = 0;
 
	switch( opt )
	{
		case '+': ret = l + r;break;
		case '-': ret = l - r;break;
		case '*': ret = l * r;break;
		case '/': ret = l / r;break;
		default: break;
	}
	return ret;
}

int calculate(const char* exp)
{	
	int left = 0;
	int right = 0;
	int res = 0, i;
	stack<int> tmp;
	
	for(i=0; exp[i] != '\0'; i++)
	{
		if( isCh(exp[i]) )
		{
			tmp.push( value(exp[i]));
		}
		else if( isOperator(exp[i]) )
		{
			if( tmp.size() > 1)
			{   
		        char op = exp[i];
				right = tmp.top();
				tmp.pop();
				left = tmp.top();
				tmp.pop();
				res = express(left, right, op);
				tmp.push(res);
			}
		}
		else
		{
			cout<<"error!"<<endl;
		}
	}
	if((tmp.size() == 1) && (exp[i] == '\0'))
	{
		res = tmp.top();
		tmp.pop();
		cout<<"success!"<<endl;
	}
	return res;
}
int main()
{
	char exp[] = "1+3*4+(5*6+7)*8";
	char d[100] = {0};
	transform(exp, d);
	printf("%s\n", d);
	printf("%d\n", calculate(d));
	
}
*/



/////////////////////////////////////////////////////////递归系列问题解析专题////////////////////////////////////////////////////
/*
//从原点出发 每次走一步 到（5，8）点最少距离有多少种走法
int minStep(int i, int j)
{

    if( i==0 ) return 1;
	if( j==0 ) return 1;
	
	return minStep(i-1, j) + minStep(i, j-1);
}

int main()
{
	cout<<minStep(5,8)<<endl;
}
*/


/*
//汉诺塔问题
void hanoi(int n, char a, char b, char c)
{
	if( n>0 )
	{
		if( n==1 )
		{
			printf("%c->%c\n", a, c);
		}
		else
		{
			hanoi(n-1, a, c, b); //在a通过c移动到b
			printf("%c->%c\n", a, c);  
			hanoi(n-1, b, a, c); //在b通过b移动到c			
		}
	}
}

//全排列问题

void permutation(char p[], int s, int e)
{
	if( (p!=NULL) && (0<=s) && (s<=e) )
	{
		if( s==e )
		{
			printf("%s\n",p);
		}
		else
		{
			for(int i=s; i<=e; i++)
			{
				char tmp = p[s];   //交换
				p[s] = p[i];
				p[i] = tmp;
				
				permutation(p, s+1, e);
				
				tmp = p[i];       //交换回来
				p[i] = p[s];
				p[s] = tmp;
			}
		}
	}
}
int main()
{
	//hanoi(3, 'a', 'b', 'c');
	char a[] = "abc";
	permutation(a,0,2);
	return 0;
}
*/

/*
//八皇后 问题

#define N 8

char board[N+2][N+2];           //棋盘
struct pos
{
	int ios;
	int jos;
};
struct pos os[3] = {{-1,-1},{-1,0},{-1,1}};


void init()
{
	for(int i=0; i<N+2; i++)
	{
		board[0][i]   = '#';
		board[N+1][i] = '#';
		board[i][0]   = '#';
	    board[i][N+1] = '#';
	}
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<N; j++)
		{
		    board[i][j] = ' ';
		}
	}
}


void display()
{
	for(int i=0; i<N+2; i++)
	{
		for(int j=0; j<N+2; j++)
		{
		    printf("%c",board[i][j]);
		}
		printf("\n");
	}
}

int check(int i, int j)
{
	int ret = 1;
	int ni, nj;
	for(int m=0; m<3; m++)
	{
		ni = i; 
		nj = j;
		
		while(ret && board[ni][nj] != '#')
		{
			ni += os[m].ios;
			nj += os[m].jos;
			ret = ret && board[ni][nj] != '*';
		}
			
	}
	return ret;
}

void find(int i)
{
	static int count = 0;
	if(i > N)
	{
		printf("solution:%d\n",++count);
		display();
		getchar();
	}
	else
	{
		for(int j=1; j<N+1; j++)
		{
			if( check(i,j)==1 )
			{
				board[i][j] = '*';
				find(i+1);
				board[i][j] = ' ';
			}
		}
	}
}
int main()
{
	init();
	find(1);
}
*/


void revert(char* str, int start, int end)
{	
    int i = 0;
    char c;
	for(i=start; i < end/2; i++)
	{
		c = str[end-i-1];
		str[end-i-1] = str[i];
		str[i] = c;
	}
}

int main()
{
	char a[1000]={0};
	int k=0;
	int i=0;
	cin>>a>>k;
	int len = strlen(a);
	
	while(i < len)
	{
	    revert(a, i, i+k);
		i += 2*k;
	}
	if(i > len)
	{
		i -= 2*k;
	    revert(a, i, len);
	}

	
	cout<<a<<endl;

}