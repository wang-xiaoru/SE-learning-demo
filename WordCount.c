#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;			//�ļ� 
	char fname[50];		//�ļ���
	char str;
	int cn=0;				//ͳ�Ƶ��ַ���
	int wn=0;				//ͳ�Ƶĵ�����
	int kn=0;
	int flag=0;			//����ǵı��� 
	int i;
	//����Ϊʹ�ÿ⺯�����������в����Ĺ��� 
	int opt=0;
	int c=0;
	int w=0;
	while((opt=getopt(argc,argv,"c:w:"))!=-1)
	{
		switch(opt)
		{
			case 'c':
				c=1;
				strcpy(fname,optarg);
				flag=1;
				break;
			case 'w':
				w=1;
				strcpy(fname,optarg);
				flag=2;
				break;
		}
	}
	//���̽���
	fp=fopen(fname, "r");		//���ļ�����ʽΪֻ��
	if(!fp)		//�ж��ļ��ܷ�� 
	{
		printf("error 1!\n");		//���޷��򿪣���ʾ 
		exit(0);					//ֹͣ���� 
	}
	switch(flag)
	{
		case 1:
			while(!feof(fp))
			{
				fgetc(fp);
				cn++;
			}
			printf("�ַ�����%d",cn);
			break;
			
		case 2:
			//���㵥�����Ĵ��� 
			str=fgetc(fp);
			while(str!=EOF)
			{
				if((str>='a'&&str<='z')||(str>='A'&&str<='Z')||(str>='0'&&str<='9'))
				{
					while((str>='a'&&str<='z')||(str>='A'&&str<='Z')||(str>='0'&&str<='9'))
					{
						str=fgetc(fp);
					}
					wn++;
					str=fgetc(fp);
				}
				else
				{
					str=fgetc(fp);
				}
			}
			wn=wn+kn;
			printf("��������%d",wn);
			break;
	}
	return 0; 
}
