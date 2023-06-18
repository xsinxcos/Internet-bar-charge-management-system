#pragma once
#include <stdio.h>

typedef struct Node{
	char Date[20];
	int UpCount;
	double ConsumeSum;
	struct Node * next;
}statisticallist;

void queryconsumptionRecordPage();                             //查询消费记录页面
void statisticaltotalTurnoverPage();                           //统计总营业额页面
void statisticalmonthlyTurnoverPage();                         //统计月营业额页面

int CardExist(char* ID,char Date1[],char Date2[]);                                              //判断卡号是否存在
void ConsumePrint(Consumernode* temp,char Date1[],char Date2[]);                                //消费记录打印
double statisticaltotal(char Date1[], char Date2[]);                                            //查询总营业额
void SaveMonthlyConsume(statisticallist* p);                                                    //将年每月的记录写入文件
int down_strcmp(char* time1, char* time2);                                                      //判断记录属于哪个月
void statisticalmonthly(char Date[]);                                                           //查询月上机次数和营业额