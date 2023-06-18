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
void beginPage(void);						//一开始进入时的页面的调用
void cardManagement(void);					//卡管理函数
void billingStandardManagement(void);		//计费标准管理
void billingManagement(void);				//计费管理(未实现）
void costManagement(void);					//费用管理
void queryStatistics(void)	;				//查询统计(未实现）
void rightsManagement(void);				//权限管理
void System(void);							//系统
void Exit(void);							//退出
bool rightJudgement(bool rightKey);			//权限判断
void returnOnepage();


void queryconsumptionRecordPage();				//查询消费记录页面
void statisticaltotalTurnoverPage();			//统计总营业额页面
void statisticalmonthlyTurnoverPage();			//统计月营业额页面


void safe_flush(FILE* fp);					//清除scanf缓冲区







