#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operate.h"

cardlist List;		//全局变量，储存卡的信息
Adminlist AList;	//全局变量，储存管理员信息
chargelist *Clist;       //全局变量，储存计费标准

bool cardManagementKey;					//卡管理权限
bool costManagementKey;					//计费管理权限
bool BillingManagementKey;				//费用管理权限
bool BillingStanderManaagementKey;		//计费标准管理权限
bool queryStatisicsKey;					//查询统计权限
bool rightsManagementKey;				//权限管理权限

int main(void) 
{
	initRights();
	initCardList(&List);
	initAdminList(&AList);
	loadingListdata(&List);
	loadingAdmindata(&AList);
	cardManagementKey = true;					//卡管理权限
	costManagementKey=true;					//计费管理权限
	BillingManagementKey=true;				//费用管理权限
	BillingStanderManaagementKey=true;		//计费标准管理权限
	queryStatisicsKey=true;					//查询统计权限
	rightsManagementKey=true;				//权限管理权限
	while (1)								//第一层循环为begin页(使用switch case实现子功能)
	{
		system("cls");
		beginPage();
		char operate = 0;					//operate为进行操作的指令
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' > 8) {
			printf("输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		switch (operate)					
		{
		case '1':
			if(rightJudgement(cardManagementKey)){
				cardManagement();
			}
			break;
		case '2':
			if (rightJudgement(BillingStanderManaagementKey)) {
				billingStandardManagement();
			}
			break;
		case '3':
			if (rightJudgement(BillingManagementKey)) {
				billingManagement();
			}
			break;
		case '4':
			if (rightJudgement(costManagementKey)) {
				costManagement();
			}
			break;
		case '5':
			if (rightJudgement(queryStatisicsKey)) {
				queryStatistics();
			}
			break;
		case '6':
			if (rightJudgement(rightsManagementKey)) {
				rightsManagement();
			}
			break;
		case '7':
			System();
			break;
		case'8':
			Exit();
			break;
		}
	}
	return 0;
}