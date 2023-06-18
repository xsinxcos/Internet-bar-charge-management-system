#pragma once
#include <stdio.h>

typedef struct Node{
	char Date[20];
	int UpCount;
	double ConsumeSum;
	struct Node * next;
}statisticallist;

void queryconsumptionRecordPage();                             //��ѯ���Ѽ�¼ҳ��
void statisticaltotalTurnoverPage();                           //ͳ����Ӫҵ��ҳ��
void statisticalmonthlyTurnoverPage();                         //ͳ����Ӫҵ��ҳ��

int CardExist(char* ID,char Date1[],char Date2[]);                                              //�жϿ����Ƿ����
void ConsumePrint(Consumernode* temp,char Date1[],char Date2[]);                                //���Ѽ�¼��ӡ
double statisticaltotal(char Date1[], char Date2[]);                                            //��ѯ��Ӫҵ��
void SaveMonthlyConsume(statisticallist* p);                                                    //����ÿ�µļ�¼д���ļ�
int down_strcmp(char* time1, char* time2);                                                      //�жϼ�¼�����ĸ���
void statisticalmonthly(char Date[]);                                                           //��ѯ���ϻ�������Ӫҵ��