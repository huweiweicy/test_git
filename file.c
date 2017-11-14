#include <stdio.h>
#include <string.h>


int isCommand(const char* cmd1,const char* cmd2,const char* cmd3);
int isFind(const char* pSrc,int len,const char* pDst);
int isMapFile(const char* pfile);

/*
function:�ж�����������Ƿ���ȷ 
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
function:Ѱ�����ַ��� 
pSrc: ��Ҫ���ҵ�Դ�ַ���
len:  ��Ҫ���ҵ�Դ�ַ�������
pDst: ��Ҫ���ҵ��ַ��� 
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
funtion: �ж������ļ����Ƿ��.map��׺ 
*/
int isMapFile(const char* pfile) //�ж��ļ���׺���Ƿ���� .map 
{
	int len = strlen(pfile) + 1; 
	return isFind(pfile,len,".map");
}

/*
funtion: Ϊ������׺.map���ļ���� .map��׺ 
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
function: �ļ�������
pName1:  ��ȡ��.map�ļ��� 
pName2:  ������ļ��� ��.html�� 
str:  ��Ҫ���ҵ��ַ���
*/
int fileHandler(char* pName1,char* pName2,char* str)
{
	int ret = 0;
	char strLine[1024];
	FILE* rfd = NULL;
	FILE* wfd = NULL;
	
	if(pName1 != NULL && pName2 != NULL && str != NULL)
	{
		if(isMapFile(pName1))   //������Ǵ�.map�ĺ�׺�ļ��� 
		{
			rfd = fopen(pName1, "r");
		}
		else
		{
			char p[20];
			if(nameAddMap(pName1,".map",p))//����.map�ĺ�׺�ļ��� ��Ϊ�����.map 
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
				printf("дhtml�ļ�ʧ��");
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
			printf("���ļ�ʧ��");
		}
		fclose(rfd); 
	}
}


int main(int argc, char** argv)
{
	if(argc > 6)
	{
		if( !isCommand(argv[1],argv[3],argv[5]) )//�ж������Ƿ���ȷ 
		{
			printf("���������ȷ��");
			exit(0);
		}
		else
		{
			fileHandler(argv[2],argv[4],argv[6]); //�����ļ� 
		}		 
	}
	else
	{
		printf("�밴��:xxx.exe -f xxx.map -o xxx.html -c xxx ��ʽ����");
	}
	
	return 0;
}
