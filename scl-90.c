/*

Ҫ��
1.����Ȩ��           2.�û�������Ϣ        3.����ɼ�       
4.�������뷽�� '1~5' 5.�������            6.����ģ�黯
7.�ļ��������ȡ     
�����ṹ��
1.�����û���Ϣ��
2.���Գɼ���Ϣ
��������
*/
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "malloc.h"
#include "time.h"
typedef struct UserScore
{
	int QES[90];
	int SumScore;
	int Female_Num;
	int Male_Num;
	double Somatization;//���廯1��4��12��27��40��42��48��49��52��53��56��58
	double Obsessive_Compulsive;//3��9��10��28��38��45��46��51��55��65
	double Interpersonal_Sensitivity;//6��21��34��36��37��41��61��69��73
	double Depression;//5��14��15��20��22��26��29��30��3l��32��54��7l��79
	double Anxiety;//2��17��23��33��39��57��72��78��80��86
	double Hostility;//11��24��63��67��74��8l
	double Photic_Anxiety;//13��25��47��50��70��75��82
	double Paranoididefition;//8��18��43��68��76��83
	double Psychotieism;//7��16��35��62��77��84��85��87��88��90
	double Others;//19��44��59��60��64��66��89
	double Male_Average;//(�ܷ�-������Ŀ��)/������Ŀ��
	char Severity_YN;
}UserScore;
typedef struct TestUser
{
	char name[40];
	char sex;
	int age;
	UserScore *score;
	struct TestUser *next;
}TestUser;

char *Question[90]={
"ͷʹ",
"�񾭹��������в�̤ʵ",
"ͷ�����в���Ҫ���뷨���־�����",
"ͷ�λ��ε�",
"�����Ե���Ȥ����",
"����������ȫ",
"�е������ܿ�������˼��",
"��ֱ��������鷳",
"���Դ�",
"�����Լ����������뼰��̬�Ķ���",
"���׷��պͼ���",
"��ʹ",
"���¿տ��ĳ�����ֵ�",
"�е��Լ��ľ����½��������",
"������Լ�������",
"��������������������",
"����",
"�е�������˶���������",
"θ�ڲ���",
"���׿���",
"ͬ�����ദʱ�е����߲�����",
"�е���ƭ������Ȧ�׻�������ץס��",
"��Ե�޹ʵ�ͻȻ�е�����",
"�Լ����ܿ��Ƶش�Ƣ��",
"�µ�������",
"��������Լ�",
"��ʹ",
"�е������������",
"�е��¶�",
"�е�����",
"���ֵ���",
"�����ﲻ����Ȥ",
"�е�����",
"���ĸ��������ܵ��˺�",
"������֪������˽���뷨",
"�е����˲����������ͬ����",
"�е����Ƕ������Ѻã���ϲ����",
"���±������ú����Ա�֤������ȷ",
"�����ú�����",
"���Ļ�θ�������",
"�е��Ȳ�������",
"������ʹ",
"�е������ڼ�������̸����",
"������˯",
"���±��뷴�����",
"������������",
"�³˵糵�������������������",
"����������",
"һ���������",
"��Ϊ�е����¶��ܿ�ĳЩ���������ϻ�",
"���ӱ����",
"���巢����ʹ",
"�����й�����",
"�е�ǰ;û��ϣ��",
"���ܼ���ע����",
"�е������ĳһ������������",
"�е����Ż����׽���",
"�е��ֻ�ŷ���",
"�뵽��������",
"�Ե�̫��",
"�����˿�������̸����ʱ�е�������",
"��һЩ���������Լ����뷨",
"������˻��˺����˵ĳ嶯",
"�ѵ�̫��",
"���뷴��ϴ�֡�����",
"˯�ò��Ȳ���",
"����ˤ�����ƻ��������뷨",
"��һЩ����û�е��뷨",
"�е��Ա����񾭹���",
"���̵���ӰԺ���˶�ĵط��е�������",
"�е��κ����鶼������",
"һ����־�򾪿�",
"�е��������ϳԶ����ܲ����",
"������������",
"����һ��ʱ�񾭺ܽ���",
"���˶����ĳɼ�û������ǡ��������",
"��ʹ�ͱ�����һ��Ҳ�е��µ�",
"�е������������񲻶�",
"�е��Լ�û��ʲô��ֵ",
"�е���Ϥ�Ķ������İ�����������",
"��л�ˤ����",
"���»��ڹ��������ε�",
"�е�������ռ���ı���",
"ΪһЩ�й��Ե��뷨���ܿ���",
"����ΪӦ����Ϊ�Լ��Ĺ�����ܵ��ͷ�",
"�е�Ҫ�ܿ����������",
"�е��Լ�����������������",
"��δ�е��������˺��׽�",
"�е��Լ�����",
"�е��Լ���������ë��"
};
//Questions
int InterfacialOutput();//�����������
int MainIndex(char e,TestUser *ListHead);//����������
int TestUserCreate();//�����û��������� 
int QuestionAnswer(UserScore *sco);//�ش����⺯��
char TestUserLogin();//���û�ע����Ѳ����û���¼����
int AUserLogin();
int TestedUserLogin();//�Ѳ����û���������
int NumTestResultOutput(TestUser *,int);//���ҳ���ָ���û��ɼ����
int TestUserListOutput(TestUser *);//����Ա�û��б�
int FirstFileRead(TestUser *);//�ļ���
int FinishFileWrite(TestUser *);//�ļ�д
int TestResultOutput(TestUser *);//�û��ɼ����
int QESOutPut(TestUser *);//������Ŀ�ɼ����
int GResultOutput(TestUser *);
int AResultOutput(TestUser *);
int DataDelete(TestUser*,int);//ָ���û�����ɾ��

int InterfacialOutput(TestUser *ListHead)
{
	fflush(stdin);
	system("cls");
	printf("------------------------------------------\n");
	printf("��ӭʹ��SCL-90�������ϵͳ\n\n\n");
	printf("�����û���¼����� ��1��\n");
	printf("--����Ա��¼����� ��2��\n");
	printf("----�˳�ϵͳ����� ��e��\n\n");
	char Index;
	int re;
	Index=getch();//Index�洢����������������Index
	re=MainIndex(Index,ListHead);
	while(!re)//��reΪ0��ʱ�򣬴���Index���벻��ȷ��
	{
		Index=getch();	
		re=MainIndex(Index,ListHead);	
	}
	if(re==1)return 0;//��reΪ1��ʱ�򣬴���һ��ʹ����ϣ����������档
	if(re==2)return 1;//��reΪ2��ʱ�򣬴������ʹ������˳�ϵͳ��
}

int MainIndex(char e,TestUser *ListHead)
{
	char logselect;//�����ڲ����û���¼����洢ѡ��
	int select;//���ڴ洢���������ѡ��
	switch(e)
	{
		case '1':
		{
			logselect=TestUserLogin();//��������û�ע���¼����
			switch(logselect)//�����û���¼���������֧ѡ��
			{
				case 's'://�Ѳ����û������Լ��ɼ�
				{
					select=TestedUserLogin(ListHead);//�����ɹ�������ţ�ʧ�ܻ�ȡ������0
					if(select)NumTestResultOutput(ListHead,select);
					else return 1;
				}
				case 'o':return 1;//������һ��
				case 'n'://���û���¼����ʼ����
				{
					TestUserCreate(ListHead);
					QuestionAnswer(ListHead->next->score);
					while(!GResultOutput(ListHead->next))
						//���û�ѡ�񷵻����˵�ǰ�������
						GResultOutput(ListHead->next);
					return 1;
				}
			}
			break;
		}
		case '2'://����Աѡ��
		{
			if(AUserLogin())
				select=TestUserListOutput(ListHead);//�ɼ��б���������ز�������
			//���selectΪ�㣬���������һ�㣬���������Ӧ����
			else return 1;
			if(select)
				while(select&&(!NumTestResultOutput(ListHead,select)))
					select=TestUserListOutput(ListHead);
			return 1;
			break;
		}
		case 'e':return 2;break;//�˳�����ѡ�񣬷���2
		default ://����������
			printf("������������¼���\n");
			return 0;
	}
	return 1;
}
int QuestionAnswer(UserScore *sco)
{
	system("cls");
	sco->SumScore=0;
	sco->Female_Num=0;
	sco->Male_Num=0;
	sco->Severity_YN=0;
	int i;
	for (i = 0; i < 90; ++i)
	{
		fflush(stdin);
		system("cls");
		printf("����%d��%s\n",i+1,Question[i]);
		printf("�������������������֣�1-û�� 2-���� 3-�е� 4-ƫ�� 5-����\n");
		int grade;
		while(fflush(stdin), scanf("%d", &grade) != 1)
		    printf("���������밴��ʽ�������� 1~5!\n");
		while(!(grade>=1&&grade<=5))
		{
			printf("���������밴��ʽ�������� 1~5\n");
			while(fflush(stdin), scanf("%d", &grade) != 1)
		   		printf("���������밴��ʽ�������� 1~5!\n");
		}
		sco->QES[i]=grade;
		sco->SumScore+=grade;
		if(grade==1)//������Ŀ
			sco->Female_Num++;
		else if(grade==2)//������Ŀ
			sco->Male_Num++;
		else //������Ŀ�����洢�Ƿ����صı�����ֵy����yes
		{
			sco->Male_Num++;
			sco->Severity_YN='y';
		}
	}
	sco->Somatization=(double)(	sco->QES[1-1]+sco->QES[4-1]+sco->QES[12-1]+
						sco->QES[27-1]+sco->QES[40-1]+sco->QES[42-1]+
						sco->QES[48-1]+sco->QES[49-1]+sco->QES[52-1]+
						sco->QES[53-1]+sco->QES[56-1]+sco->QES[58-1])/12;
	sco->Obsessive_Compulsive=(double)(	sco->QES[3-1]+sco->QES[9-1]+sco->QES[10-1]+
								sco->QES[28-1]+sco->QES[38-1]+sco->QES[45-1]+
								sco->QES[46-1]+sco->QES[51-1]+sco->QES[55-1]+sco->QES[65-1])/10;
	sco->Interpersonal_Sensitivity=(double)(sco->QES[6-1]+sco->QES[21-1]+sco->QES[34-1]+
									sco->QES[36-1]+sco->QES[37-1]+sco->QES[41-1]+
									sco->QES[61-1]+sco->QES[69-1]+sco->QES[73-1])/9;
	sco->Depression=(double)(	sco->QES[5-1]+sco->QES[14-1]+sco->QES[15-1]+
						sco->QES[20-1]+sco->QES[22-1]+sco->QES[26-1]+
						sco->QES[29-1]+sco->QES[30-1]+sco->QES[3l-1]+
						sco->QES[32-1]+sco->QES[54-1]+sco->QES[7l-1]+sco->QES[79-1])/13;
	sco->Anxiety=(double)(	sco->QES[2-1]+sco->QES[17-1]+sco->QES[23-1]+
					sco->QES[33-1]+sco->QES[39-1]+sco->QES[57-1]+
					sco->QES[72-1]+sco->QES[78-1]+sco->QES[80-1]+sco->QES[86-1])/10;

	sco->Hostility=(double)(	sco->QES[11-1]+sco->QES[24-1]+sco->QES[63-1]+
						sco->QES[67-1]+sco->QES[74-1]+sco->QES[8l-1])/6;
	sco->Photic_Anxiety=(double)(	sco->QES[13-1]+sco->QES[25-1]+sco->QES[47-1]+
							sco->QES[50-1]+sco->QES[70-1]+sco->QES[75-1]+sco->QES[82-1])/7;
	sco->Paranoididefition=(double)(sco->QES[8-1]+sco->QES[18-1]+sco->QES[43-1]+
							sco->QES[68-1]+sco->QES[76-1]+sco->QES[83-1])/6;
	sco->Psychotieism=(double)(	sco->QES[7-1]+sco->QES[16-1]+sco->QES[35-1]+
						sco->QES[62-1]+sco->QES[77-1]+sco->QES[84-1]+
						sco->QES[85-1]+sco->QES[87-1]+sco->QES[88-1]+sco->QES[90-1])/10;
	sco->Others=(double)(	sco->QES[19-1]+sco->QES[44-1]+sco->QES[59-1]+
					sco->QES[60-1]+sco->QES[64-1]+sco->QES[66-1]+sco->QES[89-1])/7;
	sco->Male_Average=(double)(sco->SumScore-sco->Female_Num)/sco->Male_Num;//����ƽ��
	if(sco->Severity_YN=='n')//�Ƿ�����������������ж�
	{
		if(sco->SumScore>160)sco->Severity_YN='y';
		else if(sco->Male_Num>43)sco->Severity_YN='y';
	}
}

int TestResultOutput(TestUser *tester)
{
	fflush(stdin);
	system("cls");
	printf("------------------------------------------------\n");	
	printf("������Ϣ\n");
	printf("����:%s\n",tester->name);
	printf("�Ա�:%c\n",tester->sex);
	printf("����:%d\n\n",tester->age);
	printf("--------�ɼ�------------------------------------\n");
	printf("----�ܷ���:%-8d\n",tester->score->SumScore);
	printf("������Ŀ��:%-8d\n",tester->score->Female_Num);
	printf("������Ŀ��:%-8d\n",tester->score->Male_Num);
	printf("����ƽ����:%1.2f\n",tester->score->Male_Average);
	if(tester->score->Severity_YN=='y')//�ж��Ƿ�����
		printf("ĳһ���Ϊ���ػ����н϶���������ԣ�Ӧ����һ������ɸ��\n\n\n");
	printf("--------�����Ǹ������ӷ���----------------------\n");
	printf("���廯(Somatization):                   %5.2f\n",tester->score->Somatization);
	printf("ǿ��֢״(Obsessive  Compulsive:         %5.2f\n",tester->score->Obsessive_Compulsive);
	printf("�˼ʹ�ϵ����(interpersonal sensitivity):%5.2f\n",tester->score->Interpersonal_Sensitivity);
	printf("����(depression):                       %5.2f\n",tester->score->Depression);
	printf("����(anxiety):                          %5.2f\n",tester->score->Anxiety);
	printf("�ж�(hostility):                        %5.2f\n",tester->score->Hostility);
	printf("�ֲ�(Photic anxiety):                   %5.2f\n",tester->score->Photic_Anxiety);
	printf("ƫִ(Paranoididefition):                %5.2f\n",tester->score->Paranoididefition);
	printf("������(psychotieism):                 %5.2f\n",tester->score->Psychotieism);
	printf("������Ŀ(additionalitems):              %5.2f\n",tester->score->Others);
	printf("----------------------------------------\n");
	return 1;
}
int GResultOutput(TestUser *tester)//�����û��ɼ���������������
{
	if(TestResultOutput(tester))
	{
		printf("�� ��e���������˵�������s���鿴������Ŀ�ɼ�\n");
		char out=getch();
		while(out!='e'&&out!='s')
			out=getch();
		if(out=='s')
		{
			QESOutPut(tester);
			return 0;
		}
		return 1;
	}
}
int QESOutPut(TestUser *tester)//������Ŀ�ɼ����
{
	system("cls");
	int i;
	for ( i = 0; i < 90; ++i)
	{
		printf("����%d��%s\n",i+1,Question[i]);
		printf("������%d\n",tester->score->QES[i]);
	}
	printf("����e��������һ��\n");
	char out=getch();
	while(out!='e')
		out=getch();
	return 1;
}

char TestUserLogin()//�����û���¼���棬����
{
	printf("-------------�û���¼--------\n");
	printf("���û�ע�Ტ��ʼ��������� ��1��\n");
	printf("--�Ѳ����û��ɼ��鿴����� ��2��\n");
	printf("----------������һ������� ��e��\n");
	char select;
	select=getch();
	while(!(select=='1'||select=='2'||select=='e'))
	{
		printf("ѡ������������ѡ��\n");
		select=getch();
	}
	if(select=='1')
		select='n';
	else if (select=='2')
		select='s';
	else if(select=='e')
		select='o';
	return select;
}

int TestUserCreate(TestUser * ListHead)
{
	TestUser *new=(TestUser *)malloc(sizeof(TestUser));
	new->score=(UserScore *)malloc(sizeof(UserScore));
	printf("-------�����������Ϣ-------\n\n\n");
	printf("������");
	gets(new->name);
	printf("�Ա�,��������� ��m�� Ů������롮f��\n");
	new->sex=getch();
	while(!(new->sex=='f'||new->sex=='m'))
	{
		printf("������������ѡ��\n");
		new->sex=getch();
	}
	printf("%c\n",new->sex);
	printf("���䣺");
	while(fflush(stdin), scanf("%d", &new->age)!= 1)
		printf("����������������������ʵ���䣡\n");
	while(new->age>100||new->age<1)
	{
		printf("����������������������ʵ����\n");
		while(fflush(stdin), scanf("%d", &new->age) != 1)
			printf("����������������������ʵ���䣡\n");
	}
	new->next=ListHead->next;
	ListHead->next=new;
	printf("��¼��ɣ����������ʼʵ��\n");
	getch();
	return 1;
}//�����û���������
int TestedUserLogin(TestUser *ListHead)//�Ѳ����û���������
{
	system("cls");
	printf("-------------------------------------\n");
	if(ListHead->next)
	{		
		char name[50];
		int num=0,i=1;
		printf("����������������");
		gets(name);
		fflush(stdin);
		TestUser *p=ListHead->next;
		for(;p;p=p->next,i++)
			if(!strcmp(name,p->name))num=i;//�������������
		if(!num)
		{
			printf("�޴��û����ݣ��������룬�������������һ��\n");
			getch();
		}
		return num;//�������
	}
	else 
	{
		printf("����Ϊ�գ���������������˵�\n");
		getch();
		return 0;//����ʧ�ܷ�����
	}
}
int AUserLogin()
{
	system("cls");
	printf("-----------------------------\n");
	printf("���������Ա���룺\n");
	int code;
	scanf("%d",&code);
	if (code!=123)
	{
		printf("����������󣡰����������������\n");
		getch();
		return 0;
	}
	else return 1;
}
int TestUserListOutput(TestUser *ListHead)//�б�����û���Ϣ
{
	system("cls");
	TestUser *p;
	int i=1,select;
	if(ListHead->next)
	{
		for(p=ListHead->next,i=1;p;p=p->next,i++)
		{
			printf("%d.%s  ����:%d",i,p->name,p->age);
			(p->sex=='m')?printf("�Ա�:��\n"):printf("�Ա�:Ů\n");
		}
		i--;
		printf("--------------------------------------------\n");
		printf("������Ҫ�鿴�ɼ����û���� 1~%d\n,������һ�������롮0��\n",i);
		for (;;)  //��֤������Ч���ж�
		{
			fflush(stdin);
			if((scanf("%d",&select)!=1)||(!(select>=0&&select<=i)))
			{
				printf("���������밴��ʽ����������� 1~%d\n",i);
				continue;
			}
			else break;
		fflush(stdin);
		return select;
		}
	}
	else
	{
		printf("���ݿ��������ݣ���������������˵�\n");
		getch();
		return 0;
	}
}
int NumTestResultOutput(TestUser *ListHead,int num)
{
	TestUser *p=ListHead;
	int i,select;
	for(i=0;i!=num;i++)p=p->next;
	select=AResultOutput(p);//����Ա������������ز�������
	while(!select)select=AResultOutput(p);//Ϊ��������˳�
	if(select==2)
	{
		DataDelete(ListHead,num);//Ϊ2��ִ��ɾ������
		return 0;
	}
	return 1;
}
int AResultOutput(TestUser *tester)
{
	if(TestResultOutput(tester))
	{
		printf("�� ��e���������˵�������s���鿴������Ŀ�ɼ�,����d��ɾ����������\n"); 
		char select=getch();
		while(select!='e'&&select!='s'&&select!='d')
			select=getch();
		if(select=='s')
		{
			QESOutPut(tester);
			return 0;
		}
		if(select=='d')return 2;
		return 1;
	}
}
int DataDelete(TestUser* ListHead,int num)
{
	TestUser *p=ListHead,*q;
	int i;
	for(i=0;i!=num-1;i++)p=p->next;
	q=p->next;
	p->next=q->next;
	free(q->score);
	free(q);
	printf("ɾ���ɹ����������������һ��\n");
	getch();
	return 1;
}

int FirstFileRead(TestUser *ListHead)
{
	printf("-----------------------------------\n");
	printf("���ڶ�ȡ�ļ�\n\n");
	FILE *data=fopen("data","rb");
	if(data==NULL)
	{
		data=fopen("data","wb");
		if(!fclose(data))
			printf("��⵽�����ݼ�¼�ļ�,�������ļ��ɹ�\n");
	}
	else
	{
		printf("��⵽���ݼ�¼�ļ���\n");
		int result=0;
		do
		{
			TestUser *p=(TestUser *)malloc(sizeof(TestUser));
			result=fread(p,sizeof(TestUser),1,data);
			if(result==1)
			{
				p->score=(UserScore *)malloc(sizeof(UserScore));
				if(fread(p->score,sizeof(UserScore),1,data)!=1)
				{
					printf("��ȡ����\n");
					getch();
					exit(0);
				}
				p->next=ListHead->next;
				ListHead->next=p;
			}
			else free(p);
		}while(result==1);
		if(ListHead->next)printf("��ȡ���ݳɹ�\n");
		else printf("�����ļ���û���û�����\n");
	}
	printf("-----------------------------------\n");
	printf("��������������\n");
	getch();
	return 1;
}
int FinishFileWrite(TestUser *ListHead)
{
	FILE *data=fopen("data","wb");
	if(ListHead->next)
	{
		TestUser *p=ListHead->next;
		for(;p;p=p->next)
		{
			if(fwrite(p,sizeof(TestUser),1,data)!=1)
				{printf("��������г���\n");break;}
			if(fwrite(p->score,sizeof(UserScore),1,data)!=1)
				{printf("��������г���\n");break;}
		}
	printf("-----------------------------------\n");
	printf("�������ݳɹ�,���������������\n");
	}
	else printf("�����ݿɴ��棬�����������\n");
	fclose(data);
	getch();
	return 1;
}
int main()
{
	TestUser *ListHead=(TestUser *)malloc(sizeof(TestUser));
	ListHead->next=NULL;
	FirstFileRead(ListHead);
	while(!(InterfacialOutput(ListHead)))
		InterfacialOutput(ListHead);
	FinishFileWrite(ListHead);
	return 0;
}

