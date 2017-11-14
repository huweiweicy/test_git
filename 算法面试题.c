#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cstring>
#include <cstdlib>
#include <stack>
//不用数据结构   用递归实现逆序栈 

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
		
		s.push(val);
reverseSatck(s);		
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
 
typedef struct _tag_node Node;
typedef struct _tag_node
{
	Node* next;
	int val;
}Node;

void list_insert(Node** head, int index, Node* node)
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
				while( (cur->next != NULL) && (--index > 0) )
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
//O(1)时间复杂度删除链表中节点
int list_remove(Node** head, Node* toDel)
{
	int ret = (head != NULL)&&(*head != NULL)&&(toDel != NULL);
	
	if( ret )
	{
		if(toDel->next != NULL)
		{
			Node* next = toDel->next;
			toDel->val = next->val;
			toDel->next= next->next;
			
			//free(next);
		}
		else if(toDel == *head)
		{
			//free(toDel);
			*head = NULL;
		}
		else
		{
			Node* cur = *head;
			while((cur->next != NULL) && (cur->next != toDel))
			{
				cur = cur->next;
			}

			//free(toDel);
			cur->next = NULL;
		}
			
	}
	return ret;
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

Node* list_mid(Node* head)
{
	Node* ret = NULL;
	if( head != NULL && head->next != NULL )
	{
		Node* p1 = head->next;
		Node* p2 = head->next->next;
		while( p2 != NULL && p2->next != NULL && p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
		ret = p1;
	}
	return ret;
}

//寻找倒数第k个节点
Node* find_node(Node* head, int k)
{
	Node* ret = NULL;
	if( head != NULL && 0 <= k )
	{
		Node* p1 = head;
		Node* p2 = head;
		int i = 0;
		
		while( p2->next != NULL && i < k )
		{
			p2 = p2->next;
			i++;
		}
		
		if( i==k )
		{
			while( p2->next != NULL )
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			ret = p1;
		}
	}
	return ret;
}

//非递归版本 合并两个有序链表
Node* merge_list(Node* head1, Node* head2)
{
	if(head1 == NULL ) return head2;
	if(head2 == NULL ) return head1;
	
	Node* p1 = head1;
	Node* p2 = head2;
	Node* newHead = NULL;
	Node* ret = NULL;
	
	if(head1->val > head2->val)
	{
		ret = head1;
		p1 = head1->next;
	}
	else
	{
		ret = head2;
		p2 = head2->next;
	}
	newHead = ret;
	while( p1 != NULL && p2 != NULL )
	{
		if( p1->val > p2->val )
		{
			newHead->next = p1;
			p1 = p1->next;
		}
		else
		{
			newHead->next = p2;
			p2 = p2->next;
		}	
		printf("----%d---\n",newHead->val);
		newHead = newHead->next;
	}
	
	if(p1 != NULL)
	{
		newHead->next = p1;
	}
	
    if(p2 != NULL)
	{
		newHead->next = p2;
	}
	
	return ret;
}

//递归的方式 合并两个有序链表
Node* Merge_list(Node* head1, Node* head2)
{
	if(head1 == NULL ) return head2;
	if(head2 == NULL ) return head1;
	Node* newHead = NULL;
	
	if( head1->val > head2->val )
	{
		newHead = head1;
		newHead->next = Merge_list(head1->next, head2);
	}
	else
	{
		newHead = head2;
		newHead->next = Merge_list(head1, head2->next);
	}
	return newHead;
}
void print(Node* head)
{
	if( head != NULL)
	{
		while(head != NULL)
		{
			printf("%d\n",head->val);
			head = head->next;
		}
	}
	printf("\n");

}
int main()
{
	Node a = {NULL,1};
	Node b = {NULL,2};
	Node c = {NULL,3};
	Node d = {NULL,4};
	Node e = {NULL,5};
	Node f = {NULL,6};
	Node g = {NULL,7};
	Node h = {NULL,8};
	Node* head1 = NULL;
	Node* head2 = NULL;
	list_insert(&head2,0,&a);
	list_insert(&head2,0,&b);
	list_insert(&head2,0,&c);
	list_insert(&head2,0,&d);
	list_insert(&head1,0,&e);
	list_insert(&head2,0,&f);
	list_insert(&head1,0,&g);
	list_insert(&head2,0,&h);
	print(head1);
	print(head2);
	//printf("%x",merge_list(head1,head2));
 
	print(merge_list(head1,head2));
	//list_remove(&head, &f);
	//list_reverse(&head);
	//print(head);
	//printf("%d\n", list_mid(head)->val);
	//printf("%d\n", find_node(head,3)->val);
	return 0;
}




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
int maxLen(char* a)
{
	if(a != NULL)
	{
		int len = strlen(a);
		
	}

}
int main()
{
	
}
*/
/*
在一个字符串中寻找没有重复字母的最长子串
如：“abcabcbb“，结果为”abc“
如："bbbbb"，结果为"b"
如："kwwkep",结果为"wke"
*/
/*
int main()
{
	char str[]= "kwwkep";
	char hash[256] = {0};
	int i,j;
	int start=0;
	int maxLen=1;
	for(i=0; str[i] != '\0'; ++i )
	{
		memset(hash,0,sizeof(hash));

		for(j=i; str[j] != '\0'; ++j)
		{
			if(hash[str[j]] == 0)
			{
				hash[str[j]] = 1;
			}
			else
			{
				break;
			}	
		}
		if(j - i > maxLen)
		{
			maxLen = j-i;
			start = i;
		}
	}
	for(i=start; i <= maxLen; i++)
	printf("%c",str[i]);
	printf("\n");
	return 0;
}*/



/*
/////KMP算法

int* make_pmt(const char* s)
{
	int* ret = NULL;
	if(s != NULL)
	{
		int ll = 0;
		int len = strlen(s);
	    ret = (int*)( malloc( sizeof(int) * len) );
		
		if( ret != NULL )
		{
			ret[0] = 0;
			for(int i=1; i<len; ++i)
			{
				while( (ll>0) && (s[i] != s[ll]))
				{
					ll = ret[ll-1];
				}
				if( s[i] == s[ll] )
				{
					ll++;
				}
				ret[i] = ll;
			}
		}
	}
	return ret;
}
int kmp(const char* d, const char* s)
{
	int ret = -1;
	if( d != NULL && s != NULL)
	{
		int slen = strlen(s);
		int dlen = strlen(d);
		int* next = make_pmt(s);
		
		if( (next != NULL) && (dlen >0) && (dlen >= slen) )
		{
			for(int i=0,j=0; i<dlen; ++i)
			{
				while( j>0 && (d[i] != s[j]) )
				{
					j = next[j-1];
				}
				
				if(d[i] == s[j])
				{
					j++;
				}
				if(j == slen)
				{
					ret = i + 1 - slen;
					break;
				}
			}
			
		}
		free(next);
	}
	return ret;
}
int main()
{
	int i = kmp("1234345","3");
	printf("%d\n", i);
	return 0;
}

*/