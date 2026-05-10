#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include "assert.h"

//判断空间是否够
void SLCheckCapacity(SL* ps)
{
	//插入数据之前先看看capacity是否够
	if (ps->capacity == ps->size)
	{
		//申请空间
		int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLData* temp = (SLData*)realloc(ps->arr, NewCapacity * sizeof(SLData));//用temp临时保存，否则申请内存失败会改变原先的数组
		//判断是否申请成功
		if (temp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = temp;
		ps->capacity = NewCapacity;
	}
}
/*//打印顺序表
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}*/

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;

}
//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

//尾插
void SLPushBack(SL* ps, SLData x)
{
	assert(ps!=NULL);
	SLCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}
//头插
void SLPushFront(SL* ps, SLData x)//一个是结构体的地址，一个是插入的数
{
	SLCheckCapacity(ps);
	int temp = ps->size;
	for (int i = 0; i < ps->size; i++)
	{
		
		ps->arr[temp] = ps->arr[temp-1];
		temp--;
	}
	ps->arr[0] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != NULL);
	//ps->arr[ps->size - 1] = 0;
	ps->size--;
}
//头删
void SLPopFront(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != NULL);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//指定位置插入
void SLInsert(SL* sl, int pos, SLData x)
{
	assert(sl != NULL);
	assert(pos >= 0 && pos <= sl->size);
	SLCheckCapacity(sl);
	for (int i = sl->size; i > pos; i--)
	{
		sl->arr[i] = sl->arr[i - 1];
	}
	sl->arr[pos] = x;
	sl->size++;
}

//删除指定位置数据
void SLErase(SL* sl, int pos)
{
	assert(sl != NULL);
	assert(pos >= 0 && pos < sl->size);
	SLCheckCapacity(sl);
	for (int i = pos; i < sl->size-1; i++)
	{
		sl->arr[i] = sl->arr[i + 1];

	}
	sl->size--;
}

/*//查找
void SLFind(SL* sl, SLData x)
{
	assert(sl != NULL);
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->arr[i] == x)
		{
			printf("找到了，下标为%d", i);
			return 0;
		}
	}
	printf("不存在");
}
*/