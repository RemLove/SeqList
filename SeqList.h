#pragma once
#include<stdio.h>
#include<stdlib.h>
#define SLData int
typedef struct SeqList
{
	SLData* arr;
	int size;//有效数据大小
	int capacity;//数据容量

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
