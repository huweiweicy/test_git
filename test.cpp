#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*int main()
{
	char *a= "name";
	char *p1=NULL;
	p1=(char*)malloc(20);
	memset(p1, 0, 20);
	while(*p1++ = *a++);
//	p1-=5;
	printf("%s\n",p1);
	return 0;
}*/


/* //交换函数以及传值操作 
int swap2(int a, int b)
{
int temp;
temp=a;
a=b;
b=temp;
return 0;
}
#define swap(a,b) a=a+b;b=a-b;a=a-b;
void main()
{
int x=5, y=10;

swap (x,y);
printf("%d %d\n",x,y);

swap2(x,y);
printf("%d %d\n",x,y);
} */
/*
int main()
{
	char *ptr = "Cisco Systems";
	*ptr++; printf("%s\n",ptr);
	ptr++;
	printf("%s\n",ptr);
	return 0;
}
*/


/*  //测试局部变量和全局变量作用域 
int x;
int modifyvalue();
void main()
{
	int x = 10;
	x++;
    modifyvalue();
	printf("%d\n",x);
}
int modifyvalue()
{ 
	return(x+=15);
}*/ 


/*//字符串数组和字符串指针的区别 
int main()
{
	char str1[] = "abc";
	char str2[] = "abc";
	const char str3[] = "abc";
	const char str4[] = "abc";
	const char* str5 = "abc";
	const char* str6 = "abc";
	cout << boolalpha << ( str1==str2 ) << endl; // 输出什么？
	cout << boolalpha << ( str3==str4 ) << endl; // 输出什么？
	cout << boolalpha << ( str5==str6 ) << endl; // 输出什么？
	return 0;
}*/

 
/*//数组传参 只传递地址 不传递数组大小 
int size_fun(char str[])//等价于 int size_fun(char* str)
{
	return (sizeof(str)/sizeof(str[0]));
}
int main()
{
	char str1[] = "abcefgfgregter";
	int size = 0;
	size = size_fun(str1);
	printf("size:%d\n",size);
	printf("size:%d\n",sizeof(str1)/sizeof(str1[0]));
	return 0;
}*/ 


/*
void char2Hex( char c ) // 将字符以16进制表示
{
	char ch = c/0x10 + '0'; if( ch > '9' ) ch += ('A'-'9'-1);
	char cl = c%0x10 + '0'; if( cl > '9' ) cl += ('A'-'9'-1);
	cout << ch << cl << ' ';
}
int main()
{
	char str[] = "I love 中国";
	for( int i=0; i<strlen(str); ++i )
	char2Hex( str[i] );
	cout << endl;
//	printf("%0x\n",str[i]);
	return 0;
}*/

/*   
struct Test
{
		Test( int i ) {}
		Test() {}
		void fun(){};
};
int main()
{
	Test a(1);	
	a.fun();
    Test b;
	b.fun();
//	cout << (true?1:"1") << endl;   能否编译通过？ 

	unsigned int const size1 = 2;
	char str1[ size1 ];
	unsigned int temp = 1;
	cin >> temp;
	cout<<temp<<endl;
	unsigned int const size2 = temp;
	char str2[ size2 ];
	return 0 ;
}
*/

/*
int main()
{
	struct CLS
	{
		int m_i;
		CLS( int i ) : m_i(i) {}
		CLS()
		{
			CLS(0);
		}
	};
	CLS obj;
	cout << obj.m_i << endl; //输出为0吗？ 
}
*/
  //分别输出什么 
/*
int main()
{
	
	float a = 1.0f;
	cout << (int)a << endl;
	cout << (int&)a << endl;
	cout << boolalpha << ( (int)a == (int&)a ) << endl; // 输出什么？
	float b = 0.0f;
	cout << (int)b << endl;
	cout << (int&)b << endl;
}*/

/*void GetMemory2(char **p, int num)
{
*p = (char *)malloc(num);
}
void Test(void)
{
char *str = NULL;
GetMemory2(&str, 100);
strcpy(str, "hello");
printf(str);
free(str); 
}
int main()
{
Test();
}*/
/*
#define SQUARE(a)((a)*(a))
inline int squart(int a)
{
	return (a * a);
}

int main()
{
	int i = 2;
	int j = 2;
	printf("%d\n",squart(++i)); 
	printf("%d\n",SQUARE(j++)); //在VC下编译结果是  4  
	printf("%d\n",j);
}*/
/*
int main()
{
   {
        short c=-1;
        unsigned short i=3;
        cout <<i*c <<endl; // 提升为有符号整型
    }
 
    {
        char c=-3;
        unsigned char i=1;
        cout <<i+c <<endl; // 转换为无符号整型
    }
 
    return 0;
}
*/

/*
int main()
{
  int a=10;
  const int &ra = a;
  int *p = &a;
  cout << ra << " " << a << endl;

  *p = 20;
  cout << ra << " " << a << endl;


return 0;
}*/
//const引用 分配内存副本问题（产生无名内存空间）
/*
int main()
{
    double a = 2.12;
	const int& b=a;                //若为const double& 就不会产生a的内存副本（产生无名内存空间）
	cout<<a<<" "<<b<<endl;
	int* p=(int*)&b;
	*p = 30;                          
    cout<<a<<" "<<b<<" "<<*p<<endl;
	return 0;
}*/


/*
//C++规定修改const double a的值属于未定义行为 不同的编译器效果不一样
int main()
{
	const volatile int a=5;    //在VC++里不会改变 在有些编译器中会改变 http://blog.csdn.net/heyabo/article/details/8745942/
	int *p=(int *)&a;
	*p=20;
	cout<<a<<" "<<*p<<endl;
}*/
/*
class A
{
public:
    const int a;
	A()
		:a(4)
	{
	}
	static const int b=0;
};
//const int A::a=8;
int main()
{
	A a;
	//cout<<A::a<<endl;
}*/

//typedef int(ptr)[5];
/*
void fun1(int (&a)[10])//若声明为&a[10]  则编译通不过  
{  
    for(int i = 0; i < 5; i++)  
    cout<<a[i]<<endl;  
}  
int main()  
{  
    int a[10]={0,1,2,3,4,5,6,7,8,9};  
    fun1(a);  
    getchar();  
    return 0;  
} */
/*
void function(int *&ref)//指针的引用  
{   
 *ref=100;  
} 
int main()  
{  
 int x = 300;  
 function(&x);  
 printf("x=%d\n",x);  
  
 return 0;  
} */
/*
int main()
{
	int* a;
	const int*  b=a;// int*  const b=a;
	int* c = b;
	*c=6;
	cout<<a<<b<<c<<endl;
	
}*/

/* 
class base
{
	
};
int main()
{
	const base &rf = base();  //const base &rf = base();  //非常引用不能对临时变量取引用 
	base *p1 = &base(); //不能对临时变量区地址 
}*/
/*
class Test{
	public:
		Test(int i){
			cout<<"Test()"<<endl;
		};
		Test(const Test& rf)//explicit  Test(const Test& rf)
		{
			cout<<"Test(Test& t)"<<endl;
		}
		~Test()
		{
			cout<<"~Test()"<<endl;
		} 
};
Test fun()
{
	Test t(1);
	return t;
};
void fun(Test temp)
{
	
} ;
int main()                //可参考 http://www.cnblogs.com/wangguchangqing/p/6141743.html 
{
//	Test tt(1);
//	Test ttt = Test(5); //隐士调用拷贝构造  编译器优化掉 
//	Test ttt(tt);       //显示调用拷贝构造  
//	Test tttt = fun(); //隐士调用拷贝构造（两次）  编译器优化掉 
//	fun(tt);           //函数传参值拷贝  调用拷贝构造
//	Test t=5;
}
*/
/*
int main(int argc , char * argv[])  
{  
    char ch1='a';  
    char ch2='b';  
    char ch;  
    cout <<"sizeof('a') = " << sizeof('a') << endl;  
    cout <<"sizeof(ch1) = " << sizeof(ch1) << endl;   
    cout <<"sizeof(ch = ch1 + ch2) = " << sizeof(ch=(ch1+ch2)) << endl;  
    cout <<"sizeof(ch1 + ch2) = " << sizeof( ch1 + ch2) << endl; 
	cout << "********************* " <<endl;   
	cout << "++ch1 = " << ++ch1 << endl;   
    cout << "ch1+1 = "<< ch1 + 1  << endl;  
    return 0;  
}  */
/*
class A{
	public :
	virtual void fun1(void)
	{
		cout<<"A::fun1()"<<endl;
	}
	virtual void fun2(void)
	{
		cout<<"A::fun2()"<<endl;
	}
};
class B:A{
	public :
	void fun1(void)
	{
		cout<<"B::fun1()"<<endl;
	}
	void fun2(void)
	{
		cout<<"B::fun2()"<<endl;
	}
};

typedef void (*PTR)(void);
int main()
{
	B* a = new B();
	PTR ptr  = (PTR)(*((int*)(*(int *)a)));
	ptr();
	return 0;
}
 */
/*
int main()
{
//	const char*  s = (char*)"123456";
  //  char*  str = s;

//	int * a = 1;
//	const int* b = a;

	int a =1;
	const int *b = &a;
	int *c = const_cast<int*>(b);
	*c =2; 
	printf("%d %d %d\n",a,*b,*c);
}*/
/*
class A{
public:
    void test()
    { printf("test A"); }
};
int main(){
    A* pA = NULL;
    pA->test();
    return 0;
}*/
/*
int main()
{
//	const int *x;
    //int const *x
	//	const int  * x;
//	int * const x;
}*/
/*
class A
{
	public:
	int i;
	void fun(int*) const;
};
void A::fun(int* a) const
{
	//this.i=1;
	a =&i;
	a =const_cast<int*>(&i);
}

int main()
{
	int i;
	A a;
	a.fun(&i);
}
*/

/*
class CText
{
	public:
	CText(char* p):pText(p)
	{
 
	}
	public:
		char & operator[](std::size_t pos) const
		{
			return pText[pos];
		}
	private:
		char* pText;
};
int main()
{
	char p[] = "hello"; 
	const CText txt = CText(p);
	char* pc =  &txt[0];
 
	*pc = 'J';
	cout<<pc;
	return 0;
}*/
/*
typedef enum flag
{
	a = 0x01,
	b = 0x01,
	c = 0x003,
}EumType;
void fun(EumType flg)
{
	cout<<flg;
}
int main()
{
	fun(b);
}
*/
/*
void fun()
{
	static int e = 0;
	int f = 0;
	printf("%x, %x", &e, &f);
}
class A
{
	public:
		static int a;
};
int A::a = 1;
static int b = 2;
int c = 3;
int main()
{
	static int d =4;
	int dd;
	printf("%x, %x, %x, %x, %x\n",&A::a, &b, &c, &d, &dd);
	fun();
}
*/
/*
int main()
{
	int n;
	vector<int> v;
	cin>>n;
	
	for(int i=0;i < n; i++)
	{
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	
	int max1=v[0],max2 = 0,max3 = 0;
	for(int i=0; i < v.size(); i++)
	{
		if(v[i] > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = v[i];
		}
		
	}
	cout<<max1*max2*max3<<endl;
	
}*/

/*
struct Test
 {
     Test(int) {}
     Test() {}
     void fun() {}
 };
 int main()
 {
     Test a(1);
     a.fun();
     Test b();
     b.fun();
 }
 
 */

/*
void quick_sort(vector<int>& vec,int left,int right)
{
    int tmp = vec[left];
    int low = left;
    int high = right;
    if(left < right)
	{
	    while( low < high )
	    {
	        while(low < high && vec[high] >= tmp)
	        {
	            high--;
	        }
	        vec[low] = vec[high];
	        while(low < high && vec[low] <= tmp)
	        {
	            low++;
	        }
	        vec[high] = vec[low];
	    }
	    vec[low] = tmp;
	    quick_sort(vec,low + 1,right);
	    quick_sort(vec,left,low -1);
 	}
}

int main()
{
    int N;
    vector<int> v;
    cin>>N;
    for(int i=0; i < N; i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    //cout<<"ok1";
    quick_sort(v,0,N-1);
   // cout<<"ok2";
    int j = 0;
    for(int i = 0; i < N; ++i)
    {
        if(v[i] != v[i+1])
        {
            j++;
            if(j == 2)break;
        }
    }
    cout<<v[j]<<endl;
}*/
/*
class ClassA
{
public:
	virtual ~ ClassA(){};
	virtual void FunctionA(){};
};
class ClassB
{
	public:

	virtual void FunctionB(){};
};
class ClassC : public ClassA,public ClassB
{

	public:
};
int main()
{
	ClassC aObject;
	ClassA* pA=&aObject;
	ClassB* pB=&aObject;
	ClassC* pC=&aObject;
	printf("%x %x %x\n",pA,pB,pC);
	return 0;
}*/

/*
stack<int> reverseSatck(stack<int>& s)
{
	stack<int> ret;
	while(!s.empty())
	{
 		ret.push(s.top());
		s.pop();	
	}
	return ret;
}
int main()
{
	int num;
	cin>>num;
	vector<int> v;
	stack<int> s;
	for(int i=0; i<num; i++)
	{
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	
	for(int i=0; i<num; i++)
	{
		s.push(v[i]);
		s = reverseSatck(s);
	}
	s = reverseSatck(s);
	do
	{
		cout<<s.top();
		s.pop();
	}
	while(!s.empty() && cout<<" ");
		
}*/

/*
class base
{
	public:
	virtual void  fun()
	{
		cout<<"base"<<endl;
	}
	static void f()
	{
		cout<<"static void f()"<<endl;
	}
	virtual ~base() = 0;
};
base::~base(){cout<<"base"<<endl;} //析构函数为纯虚函数 必须实现 
class driver:public base
{
	public:
	 void fun()
	{
		cout<<"driver"<<endl;
	}
	
	~driver();
};*/
/*driver::~driver(){cout<<"driver"<<endl;}
class car:public driver
{
	public:
	void fun()
	{
		cout<<"car"<<endl;
	}
	~car();
};
car::~car(){cout<<"car"<<endl;}
int main()
{
	base b;
	driver * p = (driver*)(&b);
	p->fun();
	base* d = NULL;
	d->fun();
	//delete d;
	return 0;
}*/
/*
class base
{
	public:
	bool operator == (const base& obj)
	{
		cout<<"ok"<<endl;
		return true;
	}
};
class A: public base
{
	public:
	int a;
};
int main()
{
	A a1;
	A a2;
	if(a1 == a2)
	{
		
	}
return 0;
}
*/
/*
int main()
{
	   unsigned int i=1,j=2,k,m=-1;
	   k=i-j;
	   std::cout<<m<<std::endl;
	   std::cout<<k<<std::endl;
	   //printf("%d\n",i-j);
}*/


/*
#include <string>

int isArgument(string str)
{		
    int i = 0,ret = -1;
    while(i < str.length() -1)
    {
    	if(str[i] =='R' && str[i+1] == 'L')
    	{
    		ret = i;
    		break;
		} 
		i++; 
	}
	
	return ret;
}

string newString(string rs)
{
    string tmp1 = rs;
    string tmp2 = rs;
    int b = isArgument(rs);
	if( b != -1)
	{
	   tmp.erase(b);
	   if(isArgument(tmp))
	   newString(rs);
	}
	else
	{
		return rs;
	}
} 


int main()
{
	int a;
	string s;

    cin>>s;
    
	cout<<newString(s);
}

*/
