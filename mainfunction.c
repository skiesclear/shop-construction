#define _CRT_SECURE_NO_WARNINGS
#include"shopconstruction.h"
#include<Windows.h>
#include<stdio.h>
#include<stdbool.h>
int switchnum;            //���ڶദ�õ�ѡ��������ȫ�ֱ���
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
	printf("\n|                     ��ӭ����ˮ���߲˹���ϵͳ                        |\n");
	printf("|******************��ѡ��������ݣ�1.�˿� 2.����Ա********************|\n");
	printf("|*********************�⽫���������������ܵķ���**********************|\n");
	printf("|\t\t����Ҫ�˳��߲�ˮ��������ϵͳ��������0\t\t      |\n");
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
			printf("��Ϣ�������������룺");
			break;
		}
		system("cls");
		goto loop6;
	}
loop10:;
	informationback();

	return 0;
}