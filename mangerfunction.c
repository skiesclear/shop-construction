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
	printf("\n|\t\t    欢迎来到密码修改系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	FILE* fp;
	fp = fopen("password.txt", "w");
	char passwords[30];
	printf("请输入您将要设置的密码：\n__________\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", passwords);
	fprintf(fp, "%s", passwords);
	printf("密码修改成功\n");
	fclose(fp);
	printf("您将退出系统重新进入\n");
	system("pause");
	exit(0);
}
void linkoutput() {
	FILE* fp;
	note* p = head;
	fp = fopen("商品信息汇总.txt", "w");
	fprintf(fp, "%s %s  %s   %s  %s   %s\n", "商品名称", "价格(元\\斤)", "保质期(\\天)", "种类", "等级" ,"数量(斤)");
		while (p != NULL) {
			fprintf(fp, "%-10s   %10lf        %d", p->name, p->price,p->Exp);
			if (p->category == 1)
				fprintf(fp, "             %s  ", "水果");
			else  
				fprintf(fp, "             %s  ", "蔬菜");
			if (p->level == 1)
				fprintf(fp, "     %s", "优");
			else if (p->level == 2)
				fprintf(fp, "     %s", "良");
			else
				fprintf(fp, "     %s", "较差");
			fprintf(fp, "%6lf\n", p->count);
			p = p->next;
		}
		fclose(fp);
		fp = fopen("customer.txt", "r");
		double mn;
		fscanf(fp, "%lf", &mn);
		fprintf(fp, "%s  %lf ", "一天卖出(元)：",mn);
		fclose(fp);
		printf("导出成功。\n");
}

void linkchange() {
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    欢迎来到商品修改系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	int analyze;
	note* p=NULL;
	loop7:
	int k[4] = { 0 };
	printf("请输入你要改变的商品的名称：\n");
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
		printf("您所需要的商品详情如下：\n");
		printf("商品       等级   价格(元\\斤)   保质期(天)   数量(斤)\n");
		printf("%-6s", p->name);
		if (p->level == 1) {
			printf("      优");
		}
		else if (p->level == 2)
			printf("      良");
		else
			printf("      较差");
		printf("%8lf", p->price);
		printf("%16d", p->Exp);
		printf("%11lf\n", p->count);
	}
	else {
		printf("您所需要的商品由多种等级。详情如下：\n");
		printf("商品       等级   价格(元\\斤)   保质期(天)   数量(斤)\n");
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      优");
				}
				else if (p->level == 2)
					printf("      良");
				else
					printf("      较差");
				printf("%8lf", p->price);
				printf("%16d", p->Exp);
				printf("%11lf\n", p->count);
				k[p->level]++;
			}
			p = p->next;
		}
		int analyze;
		printf("请选择你要修改的等级：\n_\b");
		printf("1,");
		if (k[1] != 0) {
			printf("优  ");
			k[1] = 0;
		}
		else if (k[2] != 0) {
			printf("良   ");
			k[2] = 0;
		}
		printf("2,");
		if (k[2] != 0) {
			printf("良\n  ");
			k[2] = 0;
		}
		else if (k[3] != 0) {
			printf("较差\n   ");
			k[3] = 0;
		}
		if (k[3] != 0) {
			printf("3,较差\n");
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
				printf("请选择你要修改的内容：\n_\b");
				printf("1,名称  2，种类  3，保质期(天)   4，等级   5，价格(元\\斤)   6,数量(斤)\n");
				int i;
				scanf("%d", &i);
				switch (i) {
				case 1:printf("请输入改变后的商品名称: \n");
					scanf("%s", p->name);
					break;
				case 2:printf("请选择商品改变后的名称: \n__________\b\b\b\b\b\b\b\b\b\b");
					printf("1,水果 2，蔬菜\n");
					scanf("%d", &p->category);
					break;
				case 3:printf("请输入改变后的商品的保质期(天): \n___\b\b\b");
					scanf("%d", &p->Exp);
					break;
				case 4:printf("请输入改变后的商品等级: \n__\b\b");
					scanf("%d", &p->level);
					break;
				case 5:printf("请输入改变后的商品价格(元\\斤): \n___\b\b");
					scanf("%lf", &p->price);
					break;
				case 6:printf("请输入改变后的商品数量(斤)\n___\b\b\b");
					scanf("%lf", &p->count);
					break;
				}
				printf("操作成功\n请问是否继续修改本商品其他内容？\n_\b");
				printf("1,是   2,否\n");
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
	printf("是否要继续修改其他商品?\n");
	printf("如果是请输入1，否则输入2\n_\b");
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
	printf("\n|\t\t    欢迎来到商品删除系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	note* p=NULL, *p0 = NULL;
	int no=0;
	p = p0 = head;
	loop1:
	printf("请输入将要删除的商品的名字：\n__________\b\b\b\b\b\b\b\b\b\b");
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
		printf("您所需要的商品由多种等级。详情如下：\n");
		printf("商品       等级   价格(元\\斤)   保质期(天)   数量(斤)\n");
		while (p != NULL) {
			if (strcmp(p->name, name1) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      优");
				}
				else if (p->level == 2)
					printf("      良");
				else
					printf("      较差");
				printf("%8lf", p->price);
				printf("%16d", p->Exp);
				printf("%11lf\n", p->count);
				k[p->level]++;
			}
			p = p->next;
		}
		int analyze;
		printf("请选择你要删除的等级：\n_\b");
		printf("1,");
		if (k[1] != 0) {
			printf("优  ");
			k[1] = 0;
		}
		else if (k[2] != 0) {
			printf("良   ");
			k[2] = 0;
		}
		printf("2,");
		if (k[2] != 0) {
			printf("良\n  ");
			k[2] = 0;
		}
		else if (k[3] != 0) {
			printf("较差\n   ");
			k[3] = 0;
		}
		if (k[3] != 0) {
			printf("3,较差\n");
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
		printf("商品删除成功\n");
		system("pause");
		no = 0;
	}
	else {
		printf("对不起，并没有找到您输入的商品\n");
	}
	printf("您还要继续删除其他商品吗?\n");
	printf("请选择：1，是  2，否\n");
	int analyze;
	scanf("%d", &analyze);
	if (analyze == 1)
	goto loop1;
	printf("\n商品删除操作完成\n");
}

void linkincrease() {              //增加一种商品信息
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    欢迎来到商品增加系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	struct goods* p = (note*)malloc(sizeof(note));
	printf("请输入将要添加的商品的名称：\n__________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", p->name);
	printf("请选择商品的种类：\n_\b");
	printf("1,水果  2，蔬菜\n");
	scanf("%d", &p->category);
	printf("请输入将要添加的商品的保质期(天):\n__\b\b");
	scanf("%d", &p->Exp);
	printf("请输入将要添加的商品的等级:\n_\b");
	printf("1,优   2，良  3，差\n");
	scanf("%d", &p->level);
	printf("请输入将要添加的商品的价格(元\\斤):\n__\b\b");
	scanf("%lf", &p->price);
	printf("请输入将要添加的商品的数量(斤):\n__\b\b");
	scanf("%lf", &p->count);
	p->next = NULL;
	tear->next = p;
	tear = p;
	printf("商品已将添加成功\n");

}
void menu_manger(){
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("*");
		Sleep(15);
	}
	printf("\n|               超市商品信息管理员系统                  |\n");
	printf("|********************系统功能菜单***********************|\n");
	printf("|-------------------------------------------------------|\n");
	printf("|                ___1:商品信息显示___                   |\n");
	printf("|                ___2:商品信息添加___                   |\n");
	printf("|                ___3:商品信息删除___                   |\n");
	printf("|                ___4:商品信息修改___                   |\n");
	printf("|                ___5:商品信息查询___                   |\n");
	printf("|                ___6:商品信息导出___                   |\n");
	printf("|                ___7:管理密码修改___                   |\n");
	printf("|                ___0:退出管理系统___                   |\n");
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
			printf("密码正确");
			system("pause");
			system("cls");
			analyze = 1;
			break;
		}
		else
		{
			i = 0;
			printf("密码错误\n");
			if (count == 0)
				break;
			printf("还有%d次机会", count);

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
		case 1:linkstatistics(2); //显示所有商品信息   ***
			break;     
		case 2:  linkincrease();    //链表信息添加
			break; 
		case 3:linkdelete();      //将某个商品的有关信息全部进行删除
			break;
		case 4:   linkchange();    //修改某个商品的部分信息
			break;
		case 5:linksearch(2);                  //搜寻并显示某个商品的信息   ***
			break;
		case 6:linkoutput();   //将商品信息导入到文件中
			break;
		case 7:passwordchange();
			break;
		case 0:return;
			break;
		default:printf("对不起，你所输入的数字并不在序列之中");
			break;
		}
		system("pause");
		system("cls");
		menu_manger();
		//printf("\n若你想要退出系统请按0\n");
	}
    loop2: ;
}