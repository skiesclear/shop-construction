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
	printf("\n|\t\t    欢迎来到商品购买系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	printf("请输入要购买的商品的名称:\t___________\b\b\b\b\b\b\b\b\b\b\b");
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
		printf("您所需要的商品由多种等级。详情如下：\n");
		printf("商品       等级   价格(元\\斤)   保质期(天)   数量(斤)\n");
		while (p != NULL) {
			if (strcmp(p->name, name) == 0) {
				printf("%-6s", p->name);
				if (p->level == 1) {
					printf("      优");
				}
				else if (p->level == 2)
					printf("      良");
				else
					printf("      较差");
				printf("%8.3lf", p->price);
				printf("%16d", p->Exp);
				printf("%11.3lf\n", p->count);
				k[p->level]++;
			}
			p0 = p;
			p = p->next;
		}
		int analyze;
		printf("请选择你要购买的等级：\n____\b\b\b\b");
		printf("1,");
		if (k[1] != 0) {
			printf("优  ");
			k[1] = 0;
		}
		else if(k[2] != 0) {
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
		while (strcmp(p->name, name) != 0 || analyze != (p->level)&&p!=NULL)
		{
			p = p->next;
		}
	}
	if (p == NULL||p->count==0){
		printf("没有您要购买的商品,或者商品货源不足。\n");
		goto loop5;
	}
	printf("现有%.3lf斤您所需要的商品%s\n", p->count, p->name);
	printf("请输入要购买的数量(斤)：\n____\b\b\b\b");
	double count1;
	scanf("%lf", &count1);
	if (count1 > p->count) {
		printf("对不起，库存不足,这里只有%lf。\n",p->count);
		goto loop5;
   	}
	else {
		printf("请选择包装方式:\n\t");
		printf("请输入：1，箱装  2，盒装  3，散装\n____\b\b\b\b");
		getchar(); getchar();
		p->count -= count1;
		printf("\n购买成功,花费%lf\n", count1 * p->price);

	}
	printf("请问是否继续购买？\n");
	printf("如果是，请输入1，否则输入0\n____\b\b\b\b");
	int nn;
	scanf("%d", &nn);
	if (nn)
		customerbuyago();
loop5: ;

}



void linksearch(int k) {                          //商品搜寻
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    欢迎来到商品查询系统    \t\t|\n");
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
	loop1:printf("请输入你要查询的商品名称\n\t__________\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", name1);
	p = head;
	while (p != NULL) {
		if (strcmp(name1, p->name) == 0) {
			if(analyze1==0)
			printf(" 商品名       种类     价格(元\\斤)     等级     保质期（\\天）     数量(斤)\n");
			printf("%-14s", p->name);
			if (p->category == 1)
				printf("水果");
			else
				printf("蔬菜");
			printf("%13.3lf", p->price);
			if (p->level == 1) {
				printf("%11s","优");
			}
			else if (p->level == 2)
				printf("%11s","良");
			else 
				printf("%11s","较差");
			printf("%11d", p->Exp);
			printf("%20.3lf\n", p->count);
			analyze2 = 1;
			analyze1++;
		}
		p = p->next;
	}
	if (analyze2==0){
		printf("对不起，您所查询的商品暂时缺货，请下次再来\n");
		goto loop9;
	}
	analyze2 = 0;
	analyze1 = 0;
	if (k == 1) {
		printf("是否要购买这种商品？\n");
		printf("如果是，请输入1，否则输入 0\n____\b\b\b\b");
		int analyze4;
		scanf("%d", &analyze4);
		if (analyze4)
			customerbuy(name1);
	}
	loop9:
	printf("是否仍要查询其他商品，如果是，请输入1，如果退出,请输入0\n____\b\b\b\b");
	scanf("%d", &analyze3);
	if (analyze3 == 1)
		goto loop1;
}


void linkstatistics(int k) {                            //商品所有信息进行显示
	system("cls");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|\t\t    欢迎来到商品展示系统    \t\t|\n");
	for (int i = 1; i <= 57; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n");
	printf("详情如下：\n");
	printf("  商品名       种类      价格(元\\斤)    等级    保质期(天)    数量(斤)\n");
	note* p=head;
	while (p!=NULL)
	{
		//printf("%s     %d    %d     %d     %d              \n",p->name,p->category,p->price,p->level,p->Exp);
		printf("  %-6s", p->name);
		if (p->category == 1)
			printf("%11s","水果");
		else
			printf("%11s","蔬菜");
		printf("%13.3lf", p->price);
		if (p->level == 1)
			printf("%11s","优");
		else if (p->level == 2)
			printf("%11s","良");
		else
			printf("%11s","较差");
		printf("%10d", p->Exp);
		printf("%16.3lf\n", p->count);
		p = p->next;
	}
	int analyze=0;
	if (k == 1) {
		printf("请问要购买某种商品吗?\n");
		printf("如果购买请输入1,否则输入0\n____\b\b\b\b");
		scanf("%d", &analyze);
		if (analyze) {
			customerbuyago();
		}
	}
}
void linkbuild(FILE* fp) {    //链表建立
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
		//对q进行一个遍历
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
void IN_putfile() {                    //将文件中的商品信息进行链表的建立
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

	printf("\n|                 欢迎进入顾客查询系统！                |\n");
	printf("|********************系统功能菜单***********************|\n");
	printf("|                ___1:商品信息展示___                   |\n");
	printf("|                ___2:商品信息查询___                   |\n");
	printf("|                ___3:进行商品购买___                   |\n");
	printf("|                ___0:退出顾客系统___                   |\n");
	for (int i = 1; i <= 57; i++)
	{
		printf("*");
		Sleep(3);
	}
	printf("\n");
	printf("\t____\b\b\b\b");
}
//显示商品信息，商品信息查询，购买商品，退出管理系统
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
		default:printf("对不起，你所输入的数字并不在序列之中");
			break;
		}
		system("pause");
		system("cls");
		menu_customer();

	}
}


