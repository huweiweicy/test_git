#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
////////////////////////////
/* 
int fun(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x = x & (x-1); 
	}
	return cnt;
}
int main()
{
    cout<<fun(999)<<endl;
	return 0;
}
*/
 /*
/////����������ȼ� �� for���ִ��ѭ��/// 
int main()
{
	int x,a;
//	for(x=0,a=0; a<=1 && !x++; a++)a++;

	for(x=0,a=0; a<=1 && !x++;)a++;

    cout<<x<<a<<endl;
	return 0;
}
*/
/*
int main()
{
	float a = 1.0;
	cout<<(int)a<<endl;
	cout<<&a<<endl;
	cout<<(int&)a<<endl;
	cout<<((int)a == (int&)a)<<endl;
	cout<<endl;
	float b=0.0;
	cout<<(int)b<<endl;
	cout<<&b<<endl;
	cout<<(int&)b<<endl;
	cout<<((int)b == (int&)b)<<endl;
}*/

/*
int main()
{
	unsigned int a = 0xfffffff7;
	unsigned char i = (unsigned char)a;
    char* p = (char*)&a;
	printf("%08x\n%08x",i,*p);
}
*/
/*
/////////��������ȼ���������ʾ��ʽ///////// 
int main()
{
	unsigned char a = 0xa5;
	char b = ~a>>4+1;
	printf("%d\n",b);
} 
*/

/*
////�ж�һ�����Ƿ�Ϊ2�Ĵη�//////
int main()
{
	int a;
	cout<<"//// �ж�һ�����Ƿ�Ϊ 2 �� n �Ĵη�////"<<endl;
	cout<<"����һ������"; 
	cin>>a;
	cout<<!(a & (a -1))<<endl;
} 
*/
/*
/////��λ����������������ƽ��ֵ//////
int main()
{
	int x=10,y=20;
	cout<<( (x & y) + ((x^y)>>1) )<<endl; 
} 
*/ 


/* 
/////λ�������������ļӷ�����//////////
int addMenthod(int x, int y)
{
	int sum1,sum2;
 	if(!y) return x;
	sum1 = x ^ y;   //����λ�� 
	sum2 = (x & y)<<1;//��λ��־ 
	return addMenthod(sum1,sum2);  //�ݹ���� 
}
int  main()
{
	cout<<addMenthod(5,6)<<endl;
	return 0;
} 
*/

/*
//////////////
int main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8};
	int *p=a,*q =&a[2];
	
	cout<<(q-p)<<endl;
	cout<<((char*)q-(char*)p)<<endl;
	cout<<a[(char*)q-(char*)p]<<endl;
	
}
*/
///////////////////////////////////
/*class A
{
	public:
	explicit A(int a)
			{
				cout<<a<<endl;
			}
 } ;
int main()
{
	A a(12);
//	A a =12;
	return 0;
}
*/ 
/*
///////////////��̬��////////////
class A  
{  
public:  
    void foo()  
    {  
        printf("1\n");  
    }  
    virtual void fun()  
    {  
        printf("2\n");  
    }  
};  
class B : public A  
{  
public:  
    void foo()  
    {  
        printf("3\n");  
    }  
    void fun()  
    {  
        printf("4\n");  
    }  
};  
int main(void)  
{  
    A a;  
    B b;  
    A *p = &a;  
    p->foo();  
    p->fun();  
    p = &b;  
    p->foo();  
    p->fun();
	
	B *ptr = (B *)&a;  ptr->foo();  ptr->fun();  
    return 0;  
} 
*/ 

/*
////�麯����ָ�� 
class base
{
public: 
	virtual void f(void)
	{
		cout<<"base::f";
	};
	virtual void g(void)
	{
		cout<<"base::g";
	};
	virtual void h(void)
	{
		cout<<"base::h";
	}
};
class driver:public base
{
	virtual void f(void)
	{
		cout<<"driver::f";
	}
};
typedef void(*Fun)(void);
int main()
{
	base b;
	Fun pFun =NULL;
	cout<<"�麯�����ַ��"<<(int*)(&b)<<endl;
	cout<<"��һ���麯����ַ��"<<(int*)(*(int*)(&b))<<endl;
	pFun = (Fun)(*((int*)(*(int*)(&b))));
	pFun();
	return 0; 
}*/

/* 
/////////////// �����౻�̳�  �麯�����Բ�ʵ��  �̳�����Ȼ�ǳ����� 
class base
{
public:
	virtual void fun() = 0;	
	//virtual void fun1() = 0;
};
class driver1:public base
{
public:
	int i;
	void fun(int x)
	{
		cout<<"void fun(int x)"<<endl;
	}
};
class driver2:public driver1
{
public:
	int i;
	void fun()
	{
		cout<<"void fun()"<<endl; 
	}
};
void dis(base* b)
{
	b->fun();
}
int main()
{
	driver2 d;
	dis(&d);
	return 0;
} 
*/

/*
////////����//////// 
int  a=4;
int  &f(int  x)
{    a=a+x;
      return  a;
}
int main(void)
{   
	 int   t=5;
     cout<<f(t)<<endl;   //a = 9
     f(t)=20;           // a = 20
     cout<<f(t)<<endl;   // t = 5,a = 20  a = 25
     t=f(t);            //   a = 30 t = 30
     cout<<f(t)<<endl;    //  a = 60
     return 0;
}
*/

/*
typedef int (fun)(int);
typedef int (*funptr)(int x);
int (*(*(*fp3)())[10])();
int(*(*a)(int))[10];
int f(int x)
{
	int i;
	int j;
	x=j;
}

int main()
{
	cout<<sizeof(fp3)<<" "<<sizeof(funptr)<<endl;
} 
*/
