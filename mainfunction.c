#define _CRT_SECURE_NO_WARNINGS
#include"shopconstruction.h"
#include<Windows.h>
#include<stdio.h>
#include<stdbool.h>
int switchnum;            //由于多处用到选择，声明成全局变量
extern struct goods;
int main() {
	system("color f0");
	IN_putfile();
	linksort();
loop6:
	for (int i = 1; i <= 71; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n|                     欢迎来到水果蔬菜管理系统                        |\n");
	printf("|******************请选择您的身份：1.顾客 2.管理员********************|\n");
	printf("|*********************这将决定您接下来接受的服务**********************|\n");
	printf("|\t\t若您要退出蔬菜水果管理超市系统，请输入0\t\t      |\n");
	for (int i = 1; i <= 71; i++) {
		printf("-");
		Sleep(3);
	}
	printf("\n\t_____\b\b\b\b\b");
	while (true) {
		scanf_s("%d", &switchnum);
		switch (switchnum)
		{
		case 1:system_customer(); break;
		case 2:system_manger(); break;
		case 0:goto loop10; break;
		default:
			printf("信息错误，请重新输入：");
			break;
		}
		system("cls");
		goto loop6;
	}
loop10:;
	informationback();

	return 0;
}