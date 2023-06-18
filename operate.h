#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"BillingManagement.h"
#include"BillingStandardManagement.h"
#include"CardManagement.h"
#include"System.h"
#include"RightsManagement.h"
#include"CostManagement.h"
#include"QueryStatistics.h"

void initRights(void);
void beginPage(void);						//һ��ʼ����ʱ��ҳ��ĵ���
void cardManagement(void);					//��������
void billingStandardManagement(void);		//�Ʒѱ�׼����
void billingManagement(void);				//�Ʒѹ���(δʵ�֣�
void costManagement(void);					//���ù���
void queryStatistics(void)	;				//��ѯͳ��(δʵ�֣�
void rightsManagement(void);				//Ȩ�޹���
void System(void);							//ϵͳ
void Exit(void);							//�˳�
bool rightJudgement(bool rightKey);			//Ȩ���ж�
void returnOnepage();


void queryconsumptionRecordPage();				//��ѯ���Ѽ�¼ҳ��
void statisticaltotalTurnoverPage();			//ͳ����Ӫҵ��ҳ��
void statisticalmonthlyTurnoverPage();			//ͳ����Ӫҵ��ҳ��


void safe_flush(FILE* fp);					//���scanf������







