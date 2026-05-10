#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Contact.h"

#define SLData PersnalInfo

typedef struct SeqList
{
	SLData* arr;//指针arr指向结构体联系人persnalinfo
	int size;//有效数据大小->一个联系人还是几个联系人
	int capacity;//数据容量-》能放几个联系人

}SL;
//判断空间是否够
void SLCheckCapacity(SL* ps);
//打印顺序表
void SLPrint(SL* ps);
//初始化
void SLInit(SL* ps);
//销毁
void SLDestroy(SL* ps);
//尾插
void SLPushBack(SL* ps, SLData x);
//头插
void SLPushFront(SL* ps, SLData x);//一个是结构体的地址，一个是插入的数
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//指定位置插入
void SLInsert(SL* sl, int pos, SLData x);
//删除指定位置数据
void SLErase(SL* sl, int pos);
//查找
void SLFind(SL* sl, SLData x);

