#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SLTest()
{
	SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	
	SLDestroy(&sl);

}


int main()
{
	SLTest();
	return 0;
}