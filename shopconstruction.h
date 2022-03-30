#ifndef SHOPCONSTRUCTION
#define SHOPCONSTRUCTION
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
struct goods {
	char name[20];                 //商品名称
	int category;                  //商品不同类型->不同品种   苹果->嘎啦  红富士   黄香蕉
	int pack;                     //商品包装，  散装   盒装  整箱批发
	double price;                    //销售价格           零售价  批发价   优惠价
	int Exp;                      //商品保质期
	int level;                    //商品等级
	double count;                    //商品数量
	//struct PD Pd;                      //商品生产日期
	struct goods* next;				 /*对于管理员来说或许还有进货价格........*/                  //推荐看一看枚举类型

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

void system_customer();  //进入顾客系统
void system_manger();      //进入管理员系统
void menu_customer();               //顾客系统主页面函数
void menu_manger();                 //管理员系统主函数页面
void IN_putfile();                   //导入商品信息函数
void linkincrease();                 //增加商品信息
void linkbuild();                  //链表建立函数
void linkchange();               //改变商品信息
void linkdelete();              // 链表删除   删除商品信息
void linksearch(int);                    //可以用于搜索某一个商品
void linkstatistics(int);               //链表统计  即将所有的商品信息进行输出
void linkoutput();                  //链表输出   将所有的商品信息导出到一个文件中
void  passwordchange();           //密码修改
bool passwordcheck();              //进行密码检查
void customerbuyago();
void customerbuy(char name[20]);              //顾客对商品进行购买
void informationback();                       //将商品信息重新导入资源文件中
void linksort();
#endif
