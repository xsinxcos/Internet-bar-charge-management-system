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

void computerOperatePage();						//上机页面
void computerShutPage();						//下机页面

bool isActivate(char* checkID, char* checkPassword);//判断是否有效
void initConsumerlist();