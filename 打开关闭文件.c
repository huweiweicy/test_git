#include<stdio.h>
void main()
 {
  FILE *fp;
  float m=36,temp;
  int i=0,j=0;
  if((fp=fopen("����.txt","w"))==NULL)
	{
		printf("open file failed\n");
		exit(0);
	}
  for(i=0;i<4096;i++)
  { 
    m+=0.03125;
	temp=(m-100)*(m-100);
	fprintf(fp,"0x%04x,\t",(int)((m-100)*(m-100)));
   }
   fclose(fp);
   printf("�������ɳɹ�\n");
  }