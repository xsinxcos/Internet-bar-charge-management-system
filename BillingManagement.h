//#include"operate.h"
#include <stdio.h>
#include <time.h>
typedef struct Consumernode{
	char cardID[30];
	char upTime[20];			//格式：0000-00-00 00:00
	char downTime[20];
	double consumpAmount;
	struct Consumernode* next;
}Consumernode;

typedef struct head{
	Consumernode* head;
}Consumerlist;

void computerOperatePage();						//上机页面
void computerShutPage();						//下机页面

bool isActivate(char* checkID, char* checkPassword);//判断是否有效
void initConsumerlist();						//初始化链表

void getDate(char* nowTime);					//获取时间并存储在相应的数组中
void addConsuming(char* ID);					//开始消费
bool completeConsuming(char* ID);				//结束消费
void saveConsuming();							//保存正在消费的进程
void loadConsuming();							//加载正在消费的进程

void saveRecordsConsume(Consumernode* saveData);						//将已完成的消费记录到文档方便统计
double settleConsuming(char* upTime, char* downTime);					//返回时间差值