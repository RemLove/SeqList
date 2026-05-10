#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
/*void ContactTest()
{
	contact con;
	SLInit(&con);
	ContactAdd(&con);
	ContactAdd(&con);
	ContactShow(&con);
	ContactFind(&con);
	//ContactShow(&con);
	SLDestroy(&con);
}*/


int main()
{
	contact con;
	ContactInit(&con);
	int select;
	printf("*********菜单*********\n");
	printf("1.添加 2.删除 3.修改 4.展示 5.查找 0.退出\n");
	printf("请输入你的选项\n");
	scanf("%d", &select);
	while (select != 0)
	{
		
		 if (select == 1)
		{
			ContactAdd(&con);
		}
		else if (select == 2)
		{
			ContactDel(&con);
		}
		else if (select == 3)
		{
			ContactModify(&con);
		}
		else if (select == 4)
		{
			ContactShow(&con);
		}
		else if (select == 5)
		{
			ContactFind(&con);
		}
		else
		 {
			 printf("请选择正确的选项\n");
		 }
		printf("*********菜单*********\n");
		printf("1.添加 2.删除 3.修改 4.展示 5.查找 0.退出\n");
		printf("请输入你的选项\n");
		scanf("%d", &select);
	}
	return 0;
}