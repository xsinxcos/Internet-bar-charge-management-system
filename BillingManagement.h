//#include"operate.h"
#include <stdio.h>
#include <time.h>
typedef struct Consumernode{
	char cardID[30];
	char upTime[10];
	char downTime[10];
	struct Consumernode* next;
}Consumernode;

typedef struct head{
	Consumernode* head;
}Consumerlist;

void computerOperatePage();						//�ϻ�ҳ��
void computerShutPage();						//�»�ҳ��

bool isActivate(char* checkID, char* checkPassword);//�ж��Ƿ���Ч
void initConsumerlist();