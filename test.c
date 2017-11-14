#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//#include <stdarg.h>
/*#pragma pack(2)
struct AA{
    char a;
	int c;
    char b;
}aa;
#pragma pack()
int main()
{  
	printf("%d\n",sizeof(aa));
}*/

/*
int main()
{
	char *src= "hello,world";
	int len = strlen(src);
	char *dest = (char*)malloc((len+1));//要为分配一个空间 　　　char* d = dest;
	char* a= dest;
	char *s = &src[len-1];          //指向最后一个字符
	while( len-- != 0 )
	*dest++ = *s--;
	*dest = '\0';           //尾部要加'\0'
	printf("%s\n",a);
	free(dest);            // 使用完，应当释放空间，以免造成内存汇泄露
	dest = NULL;           //防止产生野指针

	return 0;
}*/



/*
int inc(int a)
{ 
    return(++a); 
}
	
int multi(int*a,int*b,int*c)
{ 
  return(*c=(*a)*(*b));
}

typedef int(*FUNC1)(int in);

typedef int(*FUNC2) (int*,int*,int*);

void show(FUNC2 fun,int arg1, int*arg2)
{
	FUNC1 p=inc;
	int temp =p(arg1);
	fun(&temp,&arg1, arg2);
	printf("%dn",*arg2);
}
main()
{
	int a;
	show(multi,10,&a);
	return 0;
}*/ 

/*int main()
{
	
	char $p[]  = "huweiwei"; //美元符号开头也可以 
	char *ptr = "huweiwei";
	printf("%d\n",sizeof($p));
	printf("%d\n",sizeof(*ptr));
}*/
/*
int main()
{
	char i = 0x01;
	char j=0;
	j = i<<9;
	printf("%d",j);
}*/

/*
//柔性数组
typedef struct
{
	int i;
	char p[];
}solftArray;
int main()
{
    solftArray* array  = (solftArray*)malloc(sizeof(solftArray) + sizeof(char)*8);
 
    array->p[0] = 'a';
	array->i = 8;
	//printf("%d\n",sizeof(solftArray)); 
	//printf("%c\n",array->p[0]);
	printf("%d\n", array);
	printf("%d\n", &array->i);
	printf("%d\n", &array->p[0]);
	printf("%d\n", &array->p[1]);
	//free(a);
}
*/


/*
typedef struct 
{

    unsigned char a;

    unsigned char b;

    unsigned char c;

} bs1; 

typedef struct 
{

    unsigned char a:1;

    unsigned char b:3;

    unsigned char :4;

	//unsigned char d:1;

} bs2; 
int main()
{   bs2 bit;
	bit.a = 1;
	bit.b = 8;
//	bit.c = 3;
	printf("%d\n",sizeof(bit));
  //  printf("%d\n%d\n%d\n",&(bit.a),&(bit.b),&(bit.c));	  
	return 0;
} */


 /*
typedef struct aa
{
    char  a:1;
    char  b:1;
	char   :0;  
    short d:2;
    char  c:1;
} bb;


int main()
{  
    printf("%d\n",sizeof(bb));	  

	return 0;
} */



/* 
//内存对其 
typedef struct
{
	char a;
	int  b;
	double i;
	char k[5];
	char c;
}uiondat;

struct data
{
	char i;
//	uiondat cow;
	int dog;
}__attribute__((packed))too;

int main()
{   uiondat max; 
	printf("%d\n",sizeof(too));
	return 0;
}
 */

/*逆序输出字符串 
char* revert(char* Dest)
{	
    assert(Dest !=NULL);
	int len = strlen(Dest);
    int i = 0;
    char* ret = Dest;
    char c;
	for(i=0; i < len/2; i++)
	{
		c = Dest[len-i-1];
		Dest[len-i-1] = Dest[i];
		Dest[i] = c;
	}
	ret[len] = '\0';
	return ret;
}

int main()
{
	char* s = NULL;
	char a[]="1234567";
	s = revert(a);
	printf("%s",s);
 } 
*/ 


/*函数递归逆序打印 
void revert_Print(char* src)
{ 
    if(*src!='\0')
    {
      revert_Print(src+1);
	  printf("%c",*src);	
	}
}
int main()
{
	char* s = NULL;
	char a[]="1234567";
	revert_Print(a);
 } 
 
 */ 
 
/* 
void revert_Print(char* src)
{ 
    if(src != NULL)
	{
		int len = strlen( src );
		char* dest = (char*)malloc(len +1);
		char* dest_temp = dest;
		char* scr_end = &src[len - 1];
		while( len-- != 0)
		*dest_temp++ = *scr_end--;
		*dest_temp = '\0';
		printf("%s", dest);
		free(dest);
	}
}
int main()
{
	char* s = "123456";
	revert_Print(s);
 } 
*/
/*
 //越界访问内存 
int main()
{
char a;
char *str=(char*)&a;
strcpy(str,"123");
printf("%s",str);
return 0;
}
*/

/*
void showBits(short val)
{
	int i = 0;
	for(;i<sizeof(val)*8;i++)
	{
		printf("%d ",((val&(1<<i))>>i));
	}
	printf("\n");
}

int main()
{
    int i = 0;
	char val = -2;
	for(;i<sizeof(val)*8;i++)
	{
		printf("%d ",(val & (1 << ((sizeof(val)*8-1)-i))) >> ( (sizeof(val)*8-1) - i));
	}
	printf("\n");
  return 0;
}*/



/*
//统计一个数中1的个数
int count1(int val)
{
	int ret = 0;
	while(val)
	{
		ret++;
		val &= val-1;
	}
	return ret;
}
int main()
{
	printf("%d\n", count1( -2 ) );
}
*/




/*
typedef void* (fun)(char* ptr);
fun* print(char* ptr)
{   
	printf("%s\n",ptr);
	return (fun*)print;
} 

int main()
{
	******(print("hello word"));
}*/




/*
#include <math.h>
#define PI 3.1415926f
int main()
{
	int i = 0;
	double val;
	int jingdu = 255; 
	printf("sin()输出点数：");
	scanf("%d",&jingdu);
	for(i=0; i<jingdu; i++)
	{
		val = ((sin(i*((2*PI)/jingdu))+1.0)/2.0);
		printf("0x%02x\n", (int)(val*jingdu));
	}
}
*/

/* 
////////////////linux中判断大小端处理器的程序//////////// 
static union 
{
	char a[4];
	long b;
}endian={'L','?','?','B'};
#define ENDIAN ((char)(endian.b))
int main()
{
	printf("%c",ENDIAN);
}
*/
/*
int main()
{
	int i;int a[10];
	for(i=0;i<10;i++)
	{
	 	a[i] = 0;
		printf("ok\n");
	}
 } 
*/


/*
int main()
{
	int ch[3][4]={1,2,3,4,5,6,7,8,9};
	//printf("%d\n",*(*(ch+2)));
	printf("%d\n",*(ch+1)[1]);
	getchar();
	return 0;
}
*/
/*
int main()
{
	char a[]="\\\\\\\\\n\0";
	printf("size:%d\n",sizeof(a));
	printf("len:%d\n",strlen(a));
	printf("str:%s\n",a);
	return 0;
}*/

/*
char * a[10][10];
typedef struct Rec
{
	long a;
	short b[3];
	char c;

}rec;
rec r;
int main()
{
	printf("size:%d\n",sizeof(a));
	printf("size:%d\n",sizeof(r));
	return 0;
}*/



/*
typedef struct BBB
{
	long a;
	char* b;
	short c;
	char d[3];
	short e[6];

}bbb;
bbb b;
int main()
{
	printf("size:%d\n",sizeof(b));
	return 0;
}*/


/*
int main()
{
	char arry[10];
	strncpy(arry,"hello word!",12);
	printf("string:%s\n",arry);
	return 0;
}*/


/*
int main()
{
	unsigned int a=5;
    int b=-20;
	printf("%d\n",a+b);
	(a+b)>0?puts(">0"):puts("<=0"); 
	return 0;
}*/


/*
int main() 
{ 
unsigned char a=6; 
char b=-20; 
(a+b)>0? puts(">0"):puts("<=0"); 
return 0; 
}*/



/*
int main(void)
{
    unsigned int a=1;
    if(a<-1)
    {
        printf("1<-1\n");
    }
   return 0;
} */


/*
//不同类型之间的计算
int main()
{
    char  ca;
    unsigned char ucb;
    unsigned short usc;
 
    ca = 128;
    ucb =128;

    usc = ca + ucb;

    printf("%d\n", usc);
   
    usc = ca + (short)ucb;
    printf("%d\n", usc);
 
    usc = (unsigned char)ca + ucb;
    printf("%d\n", usc);
 
    usc = ca + (char)ucb;
    printf("%d\n", usc);
    getchar();
    return 0;
}
*/





/*
int myStrlen(char *str)
{
    if (str == NULL)
        return 0;
    if (*str != '\0')
        return (myStrlen(++str) + 1);
    else
        return 0;
}
int main()
{
	char* a = "123456";
	printf("%d",myStrlen(a));
	return 0;
}
*/

/*int main()
{
	char* p, a[16][8];
	char b[8];
	p = a;
	a[2][2]=1;
	printf("%d",p[18]);
	return 0;
}*/
/*
int main()
{
	char* p, a[16][8] = {0};
	char b[8];
	p = a;
	a[2][2]=1;
	printf("%d",p[18]);
	return 0;
}*/

/*
int main()
{
	printf("%d",sizeof(double(*)[2]));
	return 0;
}*/



/*
int** matrix2d(int row, int col)
{
	int i = 0;
	int** ret = (int**)malloc(sizeof(int*)*row);
	int*   p  = (int*)malloc(sizeof(int)*col*row);
	if(ret==NULL && p==NULL)
	{
		free(*ret);
		free(p);
	}
	for(;i < row; i++)
	{
		ret[i] = p + i * col ;
	}
	return ret;
}
void freeMatrix(int** p)
{
	assert(p);
	free(p[0]);
	free(p);
}

int main()
{
	int** a = matrix2d(3,3);
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{		
		   a[i][j] = i*j;
		   printf("****:%d\n",i*j);
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		   a[i][j] = i*j;
		   printf(":::::%d\n",i*j);
		}
	}
	freeMatrix(a);
	return 0;
}
*/



/*
int main()
{
	char **p, a[4][4];
	int *pa;
	char b[4] = {100, 101, 102, 103};

	p = (char **)a;
    pa = (int *)&a[0][4];
    *pa = (int)b;

	printf("*(p + 1) = %p\n", *(p + 1));
	printf("&b = %p\n", &b);
	printf("p[1][2] = %d\n", p[1][2]);

	return 0;
}*/



/*
typedef char (*P)[4];
int main()
{
	char **p, a[3][4] ={0,1,2,3,4,5,6,7,8,9,10,11};
 
	char b[4] = {100, 101, 102, 103};

	p = (char **)a;
 
    *(p+1) = (char*)b;

	printf("p[1][2] = %d\n", p[1][3]);

	return 0;
}*/

/*
int main()
{
	int a[3][4] ={0,1,2,3,4,5,6,7,8,9,10,11};
 
	printf("a        addr = %d\n",&a);
	printf("a        addr = %d\n",&a +1);
	printf("a[0]     addr = %d\n",a[0] +1);
	printf("&a[0]    addr = %d\n",&a[0]+1);
	printf("&a[0][0] addr = %d\n",&a[0][0]+1); 

	
	return 0;
}
*/


/*
//不同数据类型比较问题
int main()  
{  
    unsigned short a = 1;  
    unsigned short b = 0;  
	short i = -1;
	
	
	int x = -1;
	//unsigned int y = -1;
	unsigned char y = -1;
	
	if(x == y)                     //整型提升比较
        printf(" true\n"); 
    else
        printf(" false\n");
	
	
	if(i < a)
        printf(" true\n"); 
    else
        printf(" false\n");
   
    if (a < (b-1))                                       //a和b-1的结果-1都被转换为int类型进行比较，1<-1，显然false  
    {  
        printf(" true\n");  
    } 
	else
	{
		printf(" false\n");  
	} 
  
    return 0;  
      
}  
*/


/*
int main()
{
	char a=1;
	short b=2;
	printf("%d\n",sizeof(a+b) );
	printf("%d\n",sizeof(a>b) );
}*/




/*
int main()
{
	float i = 123456789;
	double j= 123456789123456789;
	printf("float:%0.10f\tdouble:%0.10f",i,j);	

}*/


/*
int main()
{
	char* b = "123456"+1;
	printf("%s",b);	

}*/



/*
 struct S
 {
    int n;
    char c[10];
 } *p;
 main()
 { 
    struct S a[3]={{3,"abc"},{5,"def"},{7,"ghi"}};
    p=a;
    printf("%d,",(*p).n);
    printf("%d\n",(++p)->n);
    ///printf("%d\n",(a+1)->n);
 } 
 */
 
/*
 main()
 { 
   int a =1,b =32 ;
   printf("%d,%d\n",a<<b,1<<32);
   printf("%d\n",-2147483648<<1);   //符号位移出
 } 
 */  
   
   
   
/*
int main(){
  int m=0123, n = 123;
  printf("%o %o\n", m, n);
  return 0;
}
*/
/*
void main()
{
    short *p,*q;
    short arr[15]={0};
    p=q=arr;
    p++;
    printf("%d,",p-q);
    printf("%d,",(char*)p-(char*)q);
    printf("%d",sizeof(arr)/sizeof(*arr));
}
*/
/*
void main()
{  

    char a = -1;

    unsigned char b = -1;

    printf("%u\n",a);

    printf("%u\n",b);

    printf("%d\n",a>b); 

    printf("%d\n",a>(unsigned int)b);

    printf("%d\n",(unsigned int)a>b);

}
*/
/*
int main(int argc , char * argv[])  
{  
    char ch1='a';  
    char ch2='b';  
    char ch;  
    printf("%d\n",sizeof('a')); //C++ 中为1 
    return 0;  
} */
/*
int main(){
   //int i=-1;
   int i = -2147483648;
   return printf("%d,%d,%d,%d",~i,-i,1-i,-1-i);
} 
*/

/*
#define a 10
void foo();
void prin();
 
int main()
{
    prin();
    printf("%d ", a);
    foo();
    printf("%d ", a);
     
}
void foo()
{
#undef a
#define a 50
}
void prin()
{
    printf("%d ", a);
}*/
/*
int** matrix2d(int row,int col)
{
	int** ret = (int **)malloc(sizeof(int*) * row);
	int*  p   = (int* )malloc(sizeof(int) * row * col);
	
	if(ret != NULL && p != NULL)
	{
		int i=0;
		for(i=0; i < row; ++i)
		{
			ret[i] = p + i*col;
		}
	}
	return ret;
}
void DestroyMatrix2d(int** mat)
{
	free(*mat);
	free(mat);
}
int main()
{
	int i=0,j=0;
	int** mat = matrix2d(3,3);
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		mat[i][j] = i+j;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\n",mat[i][j]);
	}
	return 0;
}*/


/*int StrComp(const char*s1,const char* s2)
{
	int ret = -1;
	assert(s1 != NULL);
	assert(s2 != NULL);
	while( *s1 != '\0' && *s2 != '\0')
	{
		if(*s1 > *s2)
		{
			ret = -1;
			break;
		}
		else if(*s1 < *s2)
		{
			ret = 1;
			break;
		}
		else
		{
			ret = 0;
		}
		s1++;s2++;
	}
	if(*s1 == *s2) 
		ret=0;
	else 
		ret =-1;
	return ret;
} 
int StrComp(const char*s1,const char* s2)
{
	int ret = -1;
	assert(s1 != NULL);
	assert(s2 != NULL);
	while( *s1 != '\0' && *s2 != '\0' && (*s1++ == *s2++));

	return (*(s1) - *(s2));
} 
int main()
{
	char a[] = "12346";
	char b[] = "12346";
	printf("%d\n",strcmp(a,b));
	printf("%d\n",StrComp(a,b));
	return 0; 
} */


////不错的指针题 
/*int main(void)
{ 
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" }; 
	char **cp[] = { c+3, c+2, c+1, c }; 
	char ***cpp = cp; 
	
    printf("%s", **++cpp); 
    printf("%s", *--*++cpp+3); 
    printf("%s", *cpp[-2]+3); 

    printf("%s\n", cpp[-1][-1]+1); 
    return 0;
}*/
/*
int main()
{
	switch(1)
	{
		default:printf("%s\n", "default");
		case 1:printf("%d\n", 1);
		case 2:printf("%d\n", 2); 
		case 3:printf("%d\n", 3); 
		case 4:printf("%d\n", 4);break;
		case 5:printf("%d\n", 5); 
	}
	return;
}*/
/*
int main()
{
	char a[] = "\02";
	char b[] = "\xab\023abc\019\\\b\0";
	printf("%d\n",sizeof(a));
	printf("%d\n",strlen(a));
	printf("%s\n",a);
	printf("%d\n",sizeof(b));
	printf("%d\n",strlen(b));
	printf("%s\n",b);
	return 0;
}*/

/*
int fun(char* str)
{
    int ret = 0,i=0;
    int cnt_1=0,cnt_2=0;
    int len = strlen(str);
    
    if(str != NULL && len >= 3 && len <= 50)
    {
		
            for(i=0; i < len; i++)
            {
            	if(i%2 ==0 && str[i] == 'B')
            	{
            	  cnt_1++;
				}
				else if(i%2 !=0 && str[i] == 'W')
				{
				  cnt_1++;
				}
            }
            for(i=0; i < len; i++)
            {
            	if(i%2 ==0 && str[i] == 'W')
            	{
            	  cnt_2++;
				}
				else if(i%2 !=0 && str[i] == 'B')
				{
				  cnt_2++;
				}
            }
    }
    return ret = cnt_1 < cnt_2 ? cnt_1 : cnt_2;
}
int main()
{
    char a[50];
   // char b[] = "BBWBWWBWBWWBBBWBWBWBBWBBW";
    scanf("%s",a);
    printf("%d\n",fun(a));
}*/

/*int main()
{
  long long a = 1, b = 2, c = 3; 
  printf("%d %d %d\n", a, b, c);  
  return 0;
}*/
/*
int main()
{
	int i,j;
	for(i=10, j=1; i=j=0; i++, j--)
	printf("%d\n",i=j=0);
}
*/
/*
int main() {
    int a, b;
    for (a = 1, b = 1; a <= 100; a++) { if (b >= 20)
            break;
        if (b % 3 == 1) {
            b += 3;
            continue;
        }
        b -= 5;
    }
    printf("%d\n", a);
    return 0;
}*/
/*
void mergeArry(int d[],int s[],int dLen,int sLen,int Max)
{
	int p = dLen + sLen -1;
	int p1 = dLen -1;
	int p2 = sLen - 1;
	if(p < Max)
	{
		while(d != NULL && s != NULL && p2 >=0 && p1 >=0)
		{
			if(d[p1] > s[p2])
			{
				d[p--] = d[p1--];
			}
			else
			{
				d[p--] = s[p2--];
			}
		}
		while(p2 >= 0)
		{
			d[p--] = s[p2--];
		}
	}
	
}
int main()
{
	int i=0;
	int a[16] = {2,3,5,7,8,9};
	int b[5]  = {4,4,5,6,10};
	mergeArry(a,b,6,5,16);
	for(i=0; i < 16; i++)
	printf("%d\n",a[i]);
}
*/
/*
//二分查找
int b_search(int a[],int low,int high,int key)
{
	int ret = -1;
	if(a != NULL && low >=0)
	{
		if(low <= high)
		{
			int mid = (low + high)/2;
			if(a[mid] == key)
			{
				ret = mid;
			}
			else if(a[mid] > key)
			{
				ret = b_search(a, low, mid-1, key);
			}
			else if(a[mid] < key)
			{
				ret = b_search(a, mid+1, high, key);
			}
		}	
	}
	return ret;
} 
int b_search_ex(int a[],int low,int high,int key)
{
	int ret = -1;
	if(a != NULL && low >=0)
	{
		while(low <= high)
		{
			int mid = (low + high)/2;
			if(a[mid] == key)
			{
				ret = mid;
				break;
			}
			else if(a[mid] > key)
			{
				high--;
			}
			else if(a[mid] < key)
			{
				low++;
			}
		}
		
	}
	return ret;
} 
int main()
{
	int arry[13] = {0,2,5,11,22,23,40,52,61,76,88,97,100};
	int key = 100;
	int index = b_search(arry,0,12,key);
	//int index = b_search_ex(arry,0,12,key);
	if(index >0)
	{
		printf("arry[%d]=%d",index,key);	
	}
	else
	{
		printf("not find:%d in arry",key);
	}
	return 0;
}
*/



/*
int main()
{
	int a=5,b; b=( a>3&&0, a++);
	printf("%d\n",b);
}*/
/*
main()
{
	int a=2, c=5;
	printf( "%  1  %\n");
 
	printf( "a=%%d,b=%%d\n", a,c );
 
}*/ 
/*
int main()
{
	char b = '\821';
	char* a = "\821";
	printf("%c ",b);
	printf("%d %d",strlen(a),sizeof("\82"));
}*/
/*
int main()
{
	int MB = 0;
	while(malloc(1<<20)) ++MB;
	printf("Allocated %d MB total", MB);
}*/
/*
int main(int arg,char** p)
{
	int a;
	printf("%x %x %x \n",&arg, &p, &a);
}*/
/*
#define va_list           char*
#define va_start(ap,v)    (ap = (va_list)&v + sizeof(v))
#define va_arg(list,index,type) (*((type*)list + index))
#define va_end(ap)	      (ap = NULL)


int fun(int num,...)
{
	int i = 0,sum=0;
	va_list start;
	va_start(start,num);
	
	for(i=0;i<num;++i)
	{
		sum += va_arg(start,i,char);
	}
	va_end(start);
	
	return sum/num;
}
int fun1(int num, ...)
{
	int i=0,sum=0;
	char* start = (char*)(&num) + sizeof(num);
	
	for(i=0; i<num; ++i)
	{
		sum+= *(typeof(num)*)(start + sizeof(int)*i);
	}
	start = NULL;
	return sum/num;
}

int main()
{
	
	int res = fun(3,1,2,3);
	printf("%d\n",res);
}
*/

/*
void merge(int a[],int tmp[],int left,int right,int mid)
{
	int i = left;
	int j = mid+1;
	int m = left;
	int k;
	while(i <= mid && j <= right)
	{
		if(a[i] < a[j])
		{
			tmp[m++] = a[i++];
		}
		else
		{
			tmp[m++] = a[j++];
		}
	}
	while(i <= mid)
	tmp[m++] = a[i++];
	while(j <= right)
	tmp[m++] = a[j++];

	for(k = left; k <= right; k++)
	{
		a[k] = tmp[k];
	}
}
void merge_sort(int a[], int tmp[],int left,int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(a,tmp,left,mid);
		merge_sort(a,tmp,mid+1,right);
		merge(a,tmp,left,right,mid);
	}
}
void mergeSort(int a[],int len)
{
	if(a != NULL)
	{
		int *tmp = (int*)(malloc(sizeof(int)*len));
		if(tmp != NULL)
		{
			merge_sort(a,tmp,0,len-1);
		}
		free(tmp);
	}
}*/
/*void quick_sort(int a[],int left, int right)
{
	int pivot = a[left];
	int i = left;
	int j = right;
	if(left < right)
	{
		while(i < j)
		{
			while(i < j && a[j] >= pivot)
			{
				j--;
			}
			a[i++] = a[j];
			
			while(i < j && a[i] <= pivot)
			{
				i++;
			}
			a[j--] = a[i];
		}
		
		a[i] = pivot;
		quick_sort(a,i+1, right);
		quick_sort(a,left, i-1);
		
	}
	
}*/

/*
void quick_sort(int* a,int left, int right)
{

	int i = left, j = right;
	int pivot = a[left];
		
	if(left < right)
	{
		while(i < j)
		{
			while(i<j && a[j] >= pivot)
			{
				j--;
			}
			a[i] = a[j];
		
			while(i<j && a[i] <= pivot)
			{
				i++;
			}
			a[j] = a[i];			
		}
		a[i] = pivot;
		quick_sort(a,i+1, right);
		quick_sort(a,left,i-1);
	}

}
void quickSort(int* s, int len)
{
	quick_sort(s,0, len-1);
}

int quick_find(int* a,int left, int right,int index)
{

	int i = left, j = right;
	int pivot = a[left];
		
	if(left < right)
	{
		while(i < j)
		{
			while(i<j && a[j] >= pivot)
			{
				j--;
			}
			a[i] = a[j];
		
			while(i<j && a[i] <= pivot)
			{
				i++;
			}
			a[j] = a[i];			
		}
		a[i] = pivot;
	//	printf("%d\n",i);
		//if(i == index) return pivot;
		quick_find(a,i+1, right,index);
		quick_find(a,left,i-1,index);
	}
	return -1;
}
int select_find(int a[],int len,int index)
{
	int i,j;	
 	int k;
 	
	for(i=0; i < len; i++)
	{
		k = i;
		for(j=i;j < len;j++)
		{
			if(a[j] < a[k])
			k = j;
		}
		if(k != i)
		{
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
		if(index == i) return a[i];
	}
	return -1;
}
int main()
{
	int i;
	int a[10] = {10,40,50,20,70,80,30,90,60};
//	mergeSort(a,10);
//	quickSort(a,10);
//	for(i = 0; i < 10; i++)
//	printf("%d  ",a[i]);
//	printf("%d  ",select_find(a,9,4));
//	int tmp1 = select_find(a,10,0); 
//	int tmp2 = select_find(a,10,1);
	int tmp3 = select_find(a,10,1);
//	for(i = 0; i < 10; i++)
	printf("%d ",tmp3);
}*/

 /*
int main()
{   
    unsigned char i=7;
    int j=0;
    for(;i>0;i-=3)
    {
       ++j;
     }
     printf("%d\n",j);
     return 0;
}
*/

/*void encoding(char s[])
{
	int len = strlen(s);
	char* ret = (char*)malloc(len);
	int i = 0;
	int index = 0;
	if(ret != NULL)
	{
		ret[0] = 0;
		while(i<len)
		{
			if(s[index] == s[i])
			{
				i++;
			}
			else
			{
				sprintf(ret, "%s%c%d", ret, s[index], i-index);
				index  = i; 
			}
		}
		sprintf(s, "%s", ret);
	}
	free(ret);
}*/

/*
char* encoding(char s[])
{
	char tab[256] = {0};
	int len = strlen(s);
	int i=0,j=0;
	int flg = 0;
	
	for(i=0; i<len; ++i)
	{
		if(++tab[s[i]] > 1)
		{
			flg = 1;
		}
			
	}
	
	if(flg)
	{
		for(i=0; i<len; ++i)
		{
			if(tab[s[i]] != 0)
			{
				s[j++] = s[i];
				s[j++]   = '0' + tab[s[i]];
				tab[s[i]] = 0;
			}			
		}
		s[j] = '\0';
	}
    
	return s;
}
int main()
{
	char s[] = "aabc";
	printf("%s",encoding(s));
}

*/
/*
int isIncreaseArray(int *a, int len)
{
	if(len == 2) return a[0] < a[1] ? 1:0; 
	if(isIncreaseArray(a+1,len-1))
	{
		return a[0] < a[1] ? 1:0; 
	}
	else
	{
		return 0;
	}
}*/
int isIncreaseArray(int arr[],int len)
{
    if (len == 1)
        return 1;

    return (arr[len - 2] <= arr[len - 1]) && isIncreaseArray(arr, len-1);

}

int main()
{
	char a;
	float b;
	int array[10] = {1,2,3,4,5,6,7,8,2,10};
	printf("%d\n",isIncreaseArray(array,10));
}




