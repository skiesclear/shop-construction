#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>
#include<windows.h>
#include"shopconstruction.h"
extern double Consume;
extern struct goods;
typedef struct goods note;
extern struct goods* head, * tear;
extern struct get_Num;
typedef struct get_Num node;
extern node* head1, * rear1;


double Nconsumer = 0;



void passwordchange() {
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ���������޸�ϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	FILE* fp;
	fp = fopen("password.txt", "w");
	char passwords[30];
	printf("����������Ҫ���õ����룺\n__________\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", passwords);
	fprintf(fp, "%s", passwords);
	printf("�����޸ĳɹ�\n");
	fclose(fp);
	printf("�����˳�ϵͳ���½���\n");
	system("pause");
	exit(0);
}
void linkoutput() {
	FILE* fp;
	note* p = head;
	fp = fopen("��Ʒ��Ϣ����.txt", "w");
	fprintf(fp, "%s %s  %s   %s  %s   %s\n", "��Ʒ����", "�۸�(Ԫ\\��)", "������(\\��)", "����", "�ȼ�" ,"����(��)");
		while (p != NULL) {
			fprintf(fp, "%-10s   %10lf        %d", p->name, p->price,p->Exp);
			if (p->category == 1)
				fprintf(fp, "             %s  ", "ˮ��");
			else  
				fprintf(fp, "             %s  ", "�߲�");
			if (p->level == 1)
				fprintf(fp, "     %s", "��");
			else if (p->level == 2)
				fprintf(fp, "     %s", "��");
			else
				fprintf(fp, "     %s", "�ϲ�");
			fprintf(fp, "%6lf\n", p->count);
			p = p->next;
		}
		fclose(fp);
		fp = fopen("customer.txt", "r");
		double mn;
		fscanf(fp, "%lf", &mn);
		fprintf(fp, "%s  %lf ", "һ������(Ԫ)��",mn);
		fclose(fp);
		printf("�����ɹ���\n");
}

void linkchange() {
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ������Ʒ�޸�ϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	int analyze;
	note* p=NULL;
	loop7:
	int k[4] = { 0 };
	printf("��������Ҫ�ı����Ʒ�����ƣ�\n");
	char name1[20];
	scanf("%s", name1);
	p = head;
	int num = 0;
	node* q = head1;
	while (q != NULL) {
		if (strcmp(q->name, name1) == 0)
			num = q->count;
		q = q->next;
	}
	if (num == 1 || num == 0) {
		while (p != NULL && strcmp(p->name, name1) != 0) {
			p = p->next;
		}
		printf("������Ҫ����Ʒ�������£�\n");
		printf("��Ʒ       �ȼ�   �۸�(Ԫ\\��)   ������(��)   ����(��)\n");
		printf("%-6s", p->name);
		if (p->level == 1) {
			printf("      ��");
		}
		else if (p->level == 2)
			printf("      ��");
		else
			printf("      �ϲ�");
		printf("%8lf", p->price);
		printf("%16d", p->Exp);
		printf("%11lf\n", p->count);
	}
	else {
		printf("������Ҫ����Ʒ�ɶ��ֵȼ����������£�\n");
		printf("��Ʒ       �ȼ�   �۸�(Ԫ\\��)   ������(��)   ����(��)\n");
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      ��");
				}
				else if (p->level == 2)
					printf("      ��");
				else
					printf("      �ϲ�");
				printf("%8lf", p->price);
				printf("%16d", p->Exp);
				printf("%11lf\n", p->count);
				k[p->level]++;
			}
			p = p->next;
		}
		int analyze;
		printf("��ѡ����Ҫ�޸ĵĵȼ���\n_\b");
		printf("1,");
		if (k[1] != 0) {
			printf("��  ");
			k[1] = 0;
		}
		else if (k[2] != 0) {
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
		while (strcmp(p->name, name1) != 0 || analyze != (p->level) && p != NULL)
		{
			p = p->next;
		}
	}
	while (p != NULL) {
		if (strcmp(name1, p->name) == 0) {
			while (1) {
				printf("��ѡ����Ҫ�޸ĵ����ݣ�\n_\b");
				printf("1,����  2������  3��������(��)   4���ȼ�   5���۸�(Ԫ\\��)   6,����(��)\n");
				int i;
				scanf("%d", &i);
				switch (i) {
				case 1:printf("������ı�����Ʒ����: \n");
					scanf("%s", p->name);
					break;
				case 2:printf("��ѡ����Ʒ�ı�������: \n__________\b\b\b\b\b\b\b\b\b\b");
					printf("1,ˮ�� 2���߲�\n");
					scanf("%d", &p->category);
					break;
				case 3:printf("������ı�����Ʒ�ı�����(��): \n___\b\b\b");
					scanf("%d", &p->Exp);
					break;
				case 4:printf("������ı�����Ʒ�ȼ�: \n__\b\b");
					scanf("%d", &p->level);
					break;
				case 5:printf("������ı�����Ʒ�۸�(Ԫ\\��): \n___\b\b");
					scanf("%lf", &p->price);
					break;
				case 6:printf("������ı�����Ʒ����(��)\n___\b\b\b");
					scanf("%lf", &p->count);
					break;
				}
				printf("�����ɹ�\n�����Ƿ�����޸ı���Ʒ�������ݣ�\n_\b");
				printf("1,��   2,��\n");
				scanf("%d", &analyze);
				if (analyze == 1)
					analyze = 0;
				else {
					analyze = 0;
					break;
				}
			}
		}
		else {
			p = p->next;
		}
		break;
	}
	printf("�Ƿ�Ҫ�����޸�������Ʒ?\n");
	printf("�����������1����������2\n_\b");
	scanf("%d", &analyze);
	if (analyze == 1) {
		analyze = 0;
		goto loop7;
	}

}

void linkdelete() {
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    ��ӭ������Ʒɾ��ϵͳ    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	note* p=NULL, *p0 = NULL;
	int no=0;
	p = p0 = head;
	loop1:
	printf("�����뽫Ҫɾ������Ʒ�����֣�\n__________\b\b\b\b\b\b\b\b\b\b");
	char name1[20] = { 0 };
	scanf("%s", name1);
	int k[4] = { 0 };
	int num = 0;
	node *q = head1;
	while (q != NULL) {
		if (strcmp(q->name, name1) == 0)
			num = q->count;
		q = q->next;
	}
	if (num == 1 || num == 0) {
		while (p != NULL && strcmp(p->name, name1) != 0) {
			p = p->next;
		}
	}
	else {
		printf("������Ҫ����Ʒ�ɶ��ֵȼ����������£�\n");
		printf("��Ʒ       �ȼ�   �۸�(Ԫ\\��)   ������(��)   ����(��)\n");
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      ��");
				}
				else if (p->level == 2)
					printf("      ��");
				else
					printf("      �ϲ�");
				printf("%8lf", p->price);
				printf("%16d", p->Exp);
				printf("%11lf\n", p->count);
				k[p->level]++;
			}
			p = p->next;
		}
		int analyze;
		printf("��ѡ����Ҫɾ���ĵȼ���\n_\b");
		printf("1,");
		if (k[1] != 0) {
			printf("��  ");
			k[1] = 0;
		}
		else if (k[2] != 0) {
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
		p0=p = head;
		while (strcmp(p->name, name1) != 0 || analyze != p->level)
		{
			p0 = p;
			p = p->next;
		}
	}
	if (p!=NULL) {
		if (p == head) {
			head = p->next;
		}
		else {
			p0->next = p->next;
		}
		no = 1;
	}
	if (no ==1) {
		printf("��Ʒɾ���ɹ�\n");
		system("pause");
		no = 0;
	}
	else {
		printf("�Բ��𣬲�û���ҵ����������Ʒ\n");
	}
	printf("����Ҫ����ɾ��������Ʒ��?\n");
	printf("��ѡ��1����  2����\n");
	int analyze;
	scanf("%d", &analyze);
	if (analyze == 1)
	goto loop1;
	printf("\n��Ʒɾ���������\n");
}

void linkincrease() {              //����һ����Ʒ��Ϣ
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
	struct goods* p = (note*)malloc(sizeof(note));
	printf("�����뽫Ҫ��ӵ���Ʒ�����ƣ�\n__________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", p->name);
	printf("��ѡ����Ʒ�����ࣺ\n_\b");
	printf("1,ˮ��  2���߲�\n");
	scanf("%d", &p->category);
	printf("�����뽫Ҫ��ӵ���Ʒ�ı�����(��):\n__\b\b");
	scanf("%d", &p->Exp);
	printf("�����뽫Ҫ��ӵ���Ʒ�ĵȼ�:\n_\b");
	printf("1,��   2����  3����\n");
	scanf("%d", &p->level);
	printf("�����뽫Ҫ��ӵ���Ʒ�ļ۸�(Ԫ\\��):\n__\b\b");
	scanf("%lf", &p->price);
	printf("�����뽫Ҫ��ӵ���Ʒ������(��):\n__\b\b");
	scanf("%lf", &p->count);
	p->next = NULL;
	tear->next = p;
	tear = p;
	printf("��Ʒ�ѽ���ӳɹ�\n");

}
void menu_manger(){
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("*");
		Sleep(15);
	}
	printf("\n|               ������Ʒ��Ϣ����Աϵͳ                  |\n");
	printf("|********************ϵͳ���ܲ˵�***********************|\n");
	printf("|-------------------------------------------------------|\n");
	printf("|                ___1:��Ʒ��Ϣ��ʾ___                   |\n");
	printf("|                ___2:��Ʒ��Ϣ���___                   |\n");
	printf("|                ___3:��Ʒ��Ϣɾ��___                   |\n");
	printf("|                ___4:��Ʒ��Ϣ�޸�___                   |\n");
	printf("|                ___5:��Ʒ��Ϣ��ѯ___                   |\n");
	printf("|                ___6:��Ʒ��Ϣ����___                   |\n");
	printf("|                ___7:���������޸�___                   |\n");
	printf("|                ___0:�˳�����ϵͳ___                   |\n");
	for (int i = 1; i <= 57; i++) {
		printf("*");
		Sleep(15);
	}
	printf("\n");
}
void system_manger() {
	int i;
	int count = 3;
	int analyze = 0;
	while (1) {
		if (passwordcheck()) {
			i = 1;
			printf("������ȷ");
			system("pause");
			system("cls");
			analyze = 1;
			break;
		}
		else
		{
			i = 0;
			printf("�������\n");
			if (count == 0)
				break;
			printf("����%d�λ���", count);

		}
		count--;
	}
	if (analyze == 0)
		goto loop2;
	menu_manger();
	while (scanf("%d", &i)&&i != 0 ) {
		//menu_customer();
		switch (i)
		{
		case 1:linkstatistics(2); //��ʾ������Ʒ��Ϣ   ***
			break;     
		case 2:  linkincrease();    //������Ϣ���
			break; 
		case 3:linkdelete();      //��ĳ����Ʒ���й���Ϣȫ������ɾ��
			break;
		case 4:   linkchange();    //�޸�ĳ����Ʒ�Ĳ�����Ϣ
			break;
		case 5:linksearch(2);                  //��Ѱ����ʾĳ����Ʒ����Ϣ   ***
			break;
		case 6:linkoutput();   //����Ʒ��Ϣ���뵽�ļ���
			break;
		case 7:passwordchange();
			break;
		case 0:return;
			break;
		default:printf("�Բ���������������ֲ���������֮��");
			break;
		}
		system("pause");
		system("cls");
		menu_manger();
		//printf("\n������Ҫ�˳�ϵͳ�밴0\n");
	}
    loop2: ;
}