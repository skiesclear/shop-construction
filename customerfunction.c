#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdbool.h>
#include<windows.h>
#include"shopconstruction.h"


extern struct goods;
typedef struct goods note;
note *head, *tear;
extern struct get_Num;
typedef struct get_Num node;
node* head1, *rear1;

double Consume;


void customerbuyago() {
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ������Ʒ����ϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	printf("������Ҫ�������Ʒ������:\t___________\b\b\b\b\b\b\b\b\b\b\b");
	char name[20];
	scanf("%s", &name);
	customerbuy(name);
}

void customerbuy( char name[]) {
	int k[4] = {0};
	note* p=head, *p0=p;
	int num=0;
	node* q = head1;
	while (q != NULL) {
		if (strcmp(q->name, name) == 0)
			num=q->count;
		q = q->next;
	}
	if (num == 1||num==0) {
		while (p != NULL && strcmp(p->name, name) != 0) {
			p0 = p;
			p = p->next;
		}
	}
	else {
		printf("������Ҫ����Ʒ�ɶ��ֵȼ����������£�\n");
		printf("��Ʒ       �ȼ�   �۸�(Ԫ\\��)   ������(��)   ����(��)\n");
		while (p != NULL) {
			if (strcmp(p->name, name) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      ��");
				}
				else if (p->level == 2)
					printf("      ��");
				else
					printf("      �ϲ�");
				printf("%8.3lf", p->price);
				printf("%16d", p->Exp);
				printf("%11.3lf\n", p->count);
				k[p->level]++;
			}
			p0 = p;
			p = p->next;
		}
		int analyze;
		printf("��ѡ����Ҫ����ĵȼ���\n____\b\b\b\b");
		printf("1,");
		if (k[1] != 0) {
			printf("��  ");
			k[1] = 0;
		}
		else if(k[2] != 0) {
			printf("��   ");
			k[2] = 0;
		}
		printf("2,");
		if (k[2] != 0) {
			printf("��\n  ");
			k[2] = 0;
		}
		else if (k[3] != 0) {
			printf("�ϲ�\n   ");
			k[3] = 0;
		}
		if (k[3] != 0) {
			printf("3,�ϲ�\n");
		}
		scanf("%d", &analyze);
		p = head;
		while (strcmp(p->name, name) != 0 || analyze != (p->level)&&p!=NULL)
		{
			p = p->next;
		}
	}
	if (p == NULL||p->count==0){
		printf("û����Ҫ�������Ʒ,������Ʒ��Դ���㡣\n");
		goto loop5;
	}
	printf("����%.3lf��������Ҫ����Ʒ%s\n", p->count, p->name);
	printf("������Ҫ���������(��)��\n____\b\b\b\b");
	double count1;
	scanf("%lf", &count1);
	if (count1 > p->count) {
		printf("�Բ��𣬿�治��,����ֻ��%lf��\n",p->count);
		goto loop5;
   	}
	else {
		printf("��ѡ���װ��ʽ:\n\t");
		printf("�����룺1����װ  2����װ  3��ɢװ\n____\b\b\b\b");
		getchar(); getchar();
		p->count -= count1;
		printf("\n����ɹ�,����%lf\n", count1 * p->price);

	}
	printf("�����Ƿ��������\n");
	printf("����ǣ�������1����������0\n____\b\b\b\b");
	int nn;
	scanf("%d", &nn);
	if (nn)
		customerbuyago();
loop5: ;

}



void linksearch(int k) {                          //��Ʒ��Ѱ
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ������Ʒ��ѯϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	note* p=head;
	int analyze1 = 0;
	int analyze2=0;
	int analyze3 = 0;
	char name1[25];
	loop1:printf("��������Ҫ��ѯ����Ʒ����\n\t__________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", name1);
	p = head;
	while (p != NULL) {
		if (strcmp(name1, p->name) == 0) {
			if(analyze1==0)
			printf(" ��Ʒ��       ����     �۸�(Ԫ\\��)     �ȼ�     �����ڣ�\\�죩     ����(��)\n");
			printf("%-14s", p->name);
			if (p->category == 1)
				printf("ˮ��");
			else
				printf("�߲�");
			printf("%13.3lf", p->price);
			if (p->level == 1) {
				printf("%11s","��");
			}
			else if (p->level == 2)
				printf("%11s","��");
			else 
				printf("%11s","�ϲ�");
			printf("%11d", p->Exp);
			printf("%20.3lf\n", p->count);
			analyze2 = 1;
			analyze1++;
		}
		p = p->next;
	}
	if (analyze2==0){
		printf("�Բ���������ѯ����Ʒ��ʱȱ�������´�����\n");
		goto loop9;
	}
	analyze2 = 0;
	analyze1 = 0;
	if (k == 1) {
		printf("�Ƿ�Ҫ����������Ʒ��\n");
		printf("����ǣ�������1���������� 0\n____\b\b\b\b");
		int analyze4;
		scanf("%d", &analyze4);
		if (analyze4)
			customerbuy(name1);
	}
	loop9:
	printf("�Ƿ���Ҫ��ѯ������Ʒ������ǣ�������1������˳�,������0\n____\b\b\b\b");
	scanf("%d", &analyze3);
	if (analyze3 == 1)
		goto loop1;
}


void linkstatistics(int k) {                            //��Ʒ������Ϣ������ʾ
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ������Ʒչʾϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	printf("�������£�\n");
	printf("  ��Ʒ��       ����      �۸�(Ԫ\\��)    �ȼ�    ������(��)    ����(��)\n");
	note* p=head;
	while (p!=NULL)
	{
		//printf("%s     %d    %d     %d     %d              \n",p->name,p->category,p->price,p->level,p->Exp);
		printf("  %-6s", p->name);
		if (p->category == 1)
			printf("%11s","ˮ��");
		else
			printf("%11s","�߲�");
		printf("%13.3lf", p->price);
		if (p->level == 1)
			printf("%11s","��");
		else if (p->level == 2)
			printf("%11s","��");
		else
			printf("%11s","�ϲ�");
		printf("%10d", p->Exp);
		printf("%16.3lf\n", p->count);
		p = p->next;
	}
	int analyze=0;
	if (k == 1) {
		printf("����Ҫ����ĳ����Ʒ��?\n");
		printf("�������������1,��������0\n____\b\b\b\b");
		scanf("%d", &analyze);
		if (analyze) {
			customerbuyago();
		}
	}
}
void linkbuild(FILE* fp) {    //������
	Consume = 0;
	note *p;
	p = (note*)malloc(sizeof(note));
	fscanf(fp, "%s%d%lf%d%d%lf", p->name, &p->category, &p->price, &p->Exp,&p->level,&p->count);
	p->next = NULL;
	head = tear = p;
	node* q,*k;
	q = (node*)malloc(sizeof(node));
	strcpy(q->name, p->name);
	q->count = 0;
	Consume += p->count * p->price;
	q->count++;
	q->next = NULL;
	head1 = rear1 = q;
	p = (note*)malloc(sizeof(note));
	while (fscanf(fp, "%s%d%lf%d%d%lf", p->name, &p->category, &p->price, &p->Exp, &p->level, &p->count) !=EOF) {
		p->next = NULL;
		tear->next = p;
		tear = p;
		Consume += p->count * p->price;
		//��q����һ������
		k = head1;
		while (k != NULL && strcmp(k->name, p->name)!=0) {
			k=k->next;
		}
		if (k == NULL) {
			q = (node*)malloc(sizeof(node));
			strcpy(q->name, p->name);
			q->count = 0;
			q->count++;
			q->next = NULL;
			rear1->next = q;
				rear1 = q;
		}
		else {
			k->count++;
		}
		p = (note*)malloc(sizeof(note));
	}
}
void IN_putfile() {                    //���ļ��е���Ʒ��Ϣ��������Ľ���
	FILE* fp;
	fp = fopen("resources.txt", "a+");
	linkbuild(fp);
	fclose(fp);
}
void menu_customer() {
	system("cls");
	for (int i = 1; i <= 57; i++)
	{
		printf("*");
		Sleep(3);
	}

	printf("\n|                 ��ӭ����˿Ͳ�ѯϵͳ��                |\n");
	printf("|********************ϵͳ���ܲ˵�***********************|\n");
	printf("|                ___1:��Ʒ��Ϣչʾ___                   |\n");
	printf("|                ___2:��Ʒ��Ϣ��ѯ___                   |\n");
	printf("|                ___3:������Ʒ����___                   |\n");
	printf("|                ___0:�˳��˿�ϵͳ___                   |\n");
	for (int i = 1; i <= 57; i++)
	{
		printf("*");
		Sleep(3);
	}
	printf("\n");
	printf("\t____\b\b\b\b");
}
//��ʾ��Ʒ��Ϣ����Ʒ��Ϣ��ѯ��������Ʒ���˳�����ϵͳ
void system_customer() {
	menu_customer();
	int i;
	while (scanf("%d", &i)==1){
		//menu_customer();
		switch (i)
		{
		case 1:linkstatistics(1); break;
		case 2:linksearch(1); break;
		case 3:customerbuyago(); break;
		case 0:return; break;
		default:printf("�Բ���������������ֲ���������֮��");
			break;
		}
		system("pause");
		system("cls");
		menu_customer();

	}
}


