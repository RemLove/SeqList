#pragma once
#define NAME_MAX 20
#define GENDER_MAX 10
#define PHONE_MAX 20
#define ADDR_MAX 100
//姓名 性别 年龄 电话 地址
typedef struct PersnalInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char phone[PHONE_MAX];
	char addr[ADDR_MAX];
}PersnalInfo;

//不能互相包含头文件
//把顺序表改成通讯录
typedef struct SeqList  contact;
//初始化顺序表-》也就是通讯录
void ContactInit(contact* con);
//通讯录的销毁
void ContactDestroy(contact* con);
//通讯录的添加
void ContactAdd(contact* con);
//通讯录的删除
void ContactDel(contact* con);
//通讯录的修改
void ContactModify(contact* con);
//通讯录的查找
void ContactFind(contact* con);
//通讯录的展示
void ContactShow(contact* con);



