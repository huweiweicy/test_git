#include <stdio.h>
#include <string.h>


int isCommand(const char* cmd1,const char* cmd2,const char* cmd3);
int isFind(const char* pSrc,int len,const char* pDst);
int isMapFile(const char* pfile);

/*
function:判断输入的命令是否正确 
*/
int isCommand(const char* cmd1,const char* cmd2,const char* cmd3)    
{
	int ret = 0;
	if(cmd1 != NULL && cmd2 != NULL && cmd3 != NULL)
	{
		if(!strcmp("-f",cmd1) && !strcmp("-o",cmd2) && !strcmp("-c",cmd3))
		{
			ret = 1;
		}	
	}	
	return ret;
}


/*
function:寻找子字符串 
pSrc: 需要查找的源字符串
len:  需要查找的源字符串长度
pDst: 需要查找的字符串 
*/
int isFind(const char* pSrc,int len,const char* pDst)
{
	int ret = 0;
	int i=0,j=0;
	if(pSrc != NULL && len > 0 && pDst != NULL)
	{
		for(i=0; i < len; ++i)
		{
			if(pSrc[i] != pDst[0])
			continue;
			j=0;
			while(pDst[j]!='\0' && i+j < len)  
        	{  
            	j++;  
            	if(pDst[j]!=pSrc[i+j])  
           	 	break;  
        	}  
        	if(pDst[j]=='\0')
			{
			   ret = 1; 	
			}   
		}
	}
	return ret;
}

/*
funtion: 判断输入文件名是否带.map后缀 
*/
int isMapFile(const char* pfile) //判断文件后缀名是否存在 .map 
{
	int len = strlen(pfile) + 1; 
	return isFind(pfile,len,".map");
}

/*
funtion: 为不带后缀.map的文件添加 .map后缀 
*/
int nameAddMap(const char* pSrc,const char* map, char* pDst) 
{
	int ret  = 0;
	if(pSrc != NULL && map != NULL && pDst != NULL)
	{
		strcpy(pDst,pSrc);
		strcat(pDst,map);
		ret = 1;
	}
	return ret;
}

/*
function: 文件处理函数
pName1:  读取的.map文件名 
pName2:  输出的文件名 （.html） 
str:  需要查找的字符串
*/
int fileHandler(char* pName1,char* pName2,char* str)
{
	int ret = 0;
	char strLine[1024];
	FILE* rfd = NULL;
	FILE* wfd = NULL;
	
	if(pName1 != NULL && pName2 != NULL && str != NULL)
	{
		if(isMapFile(pName1))   //输入的是带.map的后缀文件名 
		{
			rfd = fopen(pName1, "r");
		}
		else
		{
			char p[20];
			if(nameAddMap(pName1,".map",p))//不是.map的后缀文件名 就为其添加.map 
			{	
				printf("%s\n",p);
				rfd = fopen(p, "r");
			}		
		}
		
		if(rfd != NULL)
		{
			wfd = fopen(pName2,"w");
			
			if(wfd == NULL)
			{
				fclose(rfd);
				printf("写html文件失败");
				return 0;	
			}
			int line = 0;
			while (!feof(rfd))
			{	
				fgets(strLine,1024,rfd);
				line++; 
				if(isFind(strLine,1024,str))
				{
					fprintf(wfd,"%s\n",strLine);
					printf("fond in %d line\n",line);
				}
				else
				{
				//	printf("not fond in %d line\n",i++);	
				}	
			} 
			fclose(wfd);
		}
		else
		{
			printf("打开文件失败");
		}
		fclose(rfd); 
	}
}


int main(int argc, char** argv)
{
	if(argc > 6)
	{
		if( !isCommand(argv[1],argv[3],argv[5]) )//判断命令是否正确 
		{
			printf("输入命令不正确！");
			exit(0);
		}
		else
		{
			fileHandler(argv[2],argv[4],argv[6]); //处理文件 
		}		 
	}
	else
	{
		printf("请按照:xxx.exe -f xxx.map -o xxx.html -c xxx 格式输入");
	}
	
	return 0;
}
