#ifndef SHOPCONSTRUCTION
#define SHOPCONSTRUCTION
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
struct goods {
	char name[20];                 //��Ʒ����
	int category;                  //��Ʒ��ͬ����->��ͬƷ��   ƻ��->����  �츻ʿ   ���㽶
	int pack;                     //��Ʒ��װ��  ɢװ   ��װ  ��������
	double price;                    //���ۼ۸�           ���ۼ�  ������   �Żݼ�
	int Exp;                      //��Ʒ������
	int level;                    //��Ʒ�ȼ�
	double count;                    //��Ʒ����
	//struct PD Pd;                      //��Ʒ��������
	struct goods* next;				 /*���ڹ���Ա��˵�����н����۸�........*/                  //�Ƽ���һ��ö������

};
struct get_Num {
	char name[20];
	double count;
	struct get_Num* next;
};

//extern struct goods;
//typedef struct goods note;
//extern struct goods* head, tear;
extern double Consume;

void system_customer();  //����˿�ϵͳ
void system_manger();      //�������Աϵͳ
void menu_customer();               //�˿�ϵͳ��ҳ�溯��
void menu_manger();                 //����Աϵͳ������ҳ��
void IN_putfile();                   //������Ʒ��Ϣ����
void linkincrease();                 //������Ʒ��Ϣ
void linkbuild();                  //����������
void linkchange();               //�ı���Ʒ��Ϣ
void linkdelete();              // ����ɾ��   ɾ����Ʒ��Ϣ
void linksearch(int);                    //������������ĳһ����Ʒ
void linkstatistics(int);               //����ͳ��  �������е���Ʒ��Ϣ�������
void linkoutput();                  //�������   �����е���Ʒ��Ϣ������һ���ļ���
void  passwordchange();           //�����޸�
bool passwordcheck();              //����������
void customerbuyago();
void customerbuy(char name[20]);              //�˿Ͷ���Ʒ���й���
void informationback();                       //����Ʒ��Ϣ���µ�����Դ�ļ���
void linksort();
#endif
