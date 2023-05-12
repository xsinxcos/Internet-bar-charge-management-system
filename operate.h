#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cardnode {
	char cardID[30];
	char cardPassword[30];
	float cardMoney;
	bool state;
	struct cardnode* next;
}cardnode;

typedef struct Administrator {
	char AdminID[30];
	char AdminPassword[30];
	bool cardManagementKey;			//卡管理权限
	bool costManagementKey;			//计费管理权限
	bool BillingManagementKey;		//费用管理权限
	bool BillingStanderManaagementKey;		//计费标准管理权限
	bool queryStatisicsKey;				//查询统计权限
	bool rightsManagementKey;				//权限管理权限
	struct Administrator* next;
}Administrator;

typedef struct head {
	cardnode* head;
}cardlist;

typedef struct Adminhead {
	Administrator* head;
}Adminlist;

typedef struct charge {
	char time1[10],time2[10];
	double money;
	struct charge* next;
}chargelist;

void initRights(void);
void beginPage(void);						//一开始进入时的页面的调用
void cardManagement(void);					//卡管理函数
void billingStandardManagement(void);		//计费标准管理(未实现)
void billingManagement(void);				//计费管理(未实现）
void costManagement(void);					//费用管理(未实现）
void queryStatistics(void)	;				//查询统计(未实现）
void rightsManagement(void);				//权限管理
void System(void);							//系统(未实现)
void Exit(void);							//退出
bool rightJudgement(bool rightKey);			//权限判断
void returnOnepage();

void addCardPage();								//添加卡页面
void enquiryCardPage();							//查询卡页面
void deleteCardPage();							//删除卡页面
void newchargingStandardPage();					//新增计费标准页面
void enquirychargingStandardPage();				//查询计费标准页面
void deletechargingStandardPage();				//删除计费标准页面
void changechargingStandardPage();				//修改计费标准页面
void computerOperatePage();						//上机页面
void computerShutPage();						//下机页面
void RechargePage();							//充值页面
void returnChargePage();						//退费页面
void queryconsumptionRecordPage();				//查询消费记录页面
void statisticaltotalTurnoverPage();			//统计总营业额页面
void statisticalmonthlyTurnoverPage();			//统计月营业额页面
void addAdministratorPage();					//添加管理员页面
void deleteAdministratorPage();					//删除管理员页面
void configuepermissionPage();					//配置权限页面
void LoginPage();								//登录页面
void ExitLoginPage();							//退出登录页面

void initCardList(cardlist* Alist);										//创建储存卡的链表
bool addCard(cardlist* Alist, char* ID, char* password, float money);	//添加卡
cardnode* enquiryCard(cardlist* Alist, char* checkID);					//查询卡
bool deleteCard(cardlist* Alist, char* checkID, char* checkpassword);	//注销卡
void saveListdata(cardlist* Alist);										//数据保存（卡）
void loadingListdata(cardlist* Alist);									//数据读取（卡）

void ListInitiate(chargelist** Clist);
void newchargingStandardPage();

bool Recharge(char* ID, char* password, float rechargeMoney);			//充值
bool returnCharge(char* ID, char* password);							//退费

void initAdminList(Adminlist* Alist);									//初始化管理员名单
bool addAdmin(Adminlist* Alist, char* ID, char* password);				//添加管理员
bool deleteAdmin(Adminlist* Alist,char* checkID);						//删除管理员
Administrator* seekAdministrator(Adminlist* Alist, char* ID);			//查找对应ID的管理员结点并返回对应结点
void configuePermission(Administrator* temp, char operate);				//进行对管理员权限的添加
void addAdminNode(Adminlist* Alist, Administrator temp);				//用于数据读取提高读取效率
void saveAdmindata(Adminlist* Alist);									//数据保存(管理员账号)
void loadingAdmindata(Adminlist* Alist);								//数据读取（管理员账号）


bool Login(Adminlist* Alist, char* ID, char* password);				//登录操作(超级管理员账号不用链表储存直接在代码中
																	//进行判断，以此保证超级管理员账号与密码的不可修改性)
void exitLogin();													//退出登录操作