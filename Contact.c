#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "SeqList.h"
#include <string.h>
//初始化顺序表-》也就是通讯录
void ContactInit(contact* con)
{
	SLInit(con);
}
//通讯录的销毁
void ContactDestroy(contact* con)
{
	SLDestroy(&con);
}

//通讯录的添加
void ContactAdd(contact* con)
{
	PersnalInfo info;
	//姓名 性别 年龄 电话 地址
	printf("请输入要添加联系人的姓名\n");
	scanf("%s", info.name);

	printf("请输入要添加联系人的性别\n");
	scanf("%s", info.gender);

	printf("请输入要添加联系人的年龄\n");
	scanf("%d", &info.age);

	printf("请输入要添加联系人的电话\n");
	scanf("%s", info.phone);

	printf("请输入要添加联系人的地址\n");
	scanf("%s", info.addr);

	SLPushBack(con, info);
}

int FindByName(contact* con,char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i].name, name))
		{
			//找到了
			return i;
		}
	}
	//没找到
	return -1;
}

//通讯录的销毁
void ContactDel(contact* con)
{
	//查找
	char name[NAME_MAX];
	printf("请输入要删除联系人的姓名\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		//没找到
		printf("没找到\n");
		return;
	}
	else
	{
		//找到了
		printf("找到了\n");
		SLErase(con, find);
		printf("删除成功\n");
	}
}

//通讯录的展示
void ContactShow(contact* con)
{
	for (int i = 0; i < con->size; i++)
	{
		printf("%s ", con->arr[i].name);
		printf("%s ", con->arr[i].gender);
		printf("%d ", con->arr[i].age);
		printf("%s ", con->arr[i].phone);
		printf("%s ", con->arr[i].addr);
		printf("\n");
	}
}

//通讯录的修改
void ContactModify(contact* con)
{
	//assert(con != NULL);
	char name[NAME_MAX];
	printf("请输入要修改人的姓名");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)//没找到
	{
		printf("没找到");
		return;
	}
	//找到了
	printf("请输入要修改的姓名\n");
	scanf("%s", con->arr[find].name);
	printf("请输入要修改的性别\n");
	scanf("%s", con->arr[find].gender);
	printf("请输入要修改的年龄\n");
	scanf("%d", &con->arr[find].age);////////取地址
	printf("请输入要修改的电话\n");
	scanf("%s", con->arr[find].phone);
	printf("请输入要修改的地址\n");
	scanf("%s", con->arr[find].addr);
}

//通讯录的查找
void ContactFind(contact* con)
{
	printf("请输入要查找人的姓名\n");
	char name[NAME_MAX];
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("没找到\n");
		return;
	}
	//找到了
	printf("找到了\n");
	printf("%s ", con->arr[find].name);
	printf("%s ", con->arr[find].gender);
	printf("%d ", con->arr[find].age);
	printf("%s ", con->arr[find].phone);
	printf("%s ", con->arr[find].addr);
	printf("\n");
}