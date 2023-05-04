#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operate.h"

cardlist List;		//全局变量，储存卡的信息
Adminlist AList;	//全局变量，储存管理员信息

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
			if (cardManagementKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			while (1)			//这是第二层循环，循环的卡管理页面(使用switch case实现子功能)
			{
				
				cardManagement();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 6) {
					printf("输入错误，请重新输入\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					addCardPage();
					_sleep(1500);
					system("cls");
					break;
				case '2':
					while (1)				//这是第三层循环，循环的查询卡页面
					{
						enquiryCardPage();
						operate = 0;
						scanf(" %c", &operate);
						getchar();
						while (operate - '0' < 0 || operate - '0' >= 2) {
							printf("输入错误，请重新输入\n");
							scanf(" %c", &operate);
						}
						system("cls");
						if (operate == '0') {
							break;
						}
					}
					break;
				case '3':
					while (1)				//这是第三层循环，循环的注销卡页面
					{
						deleteCardPage();
						operate = 0;
						scanf(" %c", &operate);
						while (operate - '0' < 0 || operate - '0' >= 2) {
							printf("输入错误，请重新输入\n");
							scanf(" %c", &operate);
						}
						system("cls");
						if (operate == '0') {
							break;
						}
					}
					break;
				case '4':
					//returnOnepage();
					break;
				case '5':
					Exit();
					break;
				default:
					printf("error：输入的字符不符合要求，请重新输入\n\n");
					break;
				}
				if (operate == '4') {
					system("cls");
					break;
				}
			}
			break;
		case '2':
			if (BillingStanderManaagementKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			billingStandardManagement();
			break;
		case '3':
			if (BillingManagementKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			billingManagement();
			break;
		case '4':
			if (costManagementKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			costManagement();
			break;
		case '5':
			if (queryStatisicsKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			queryStatistics();
			break;
		case '6':
			if (rightsManagementKey == false) {
				printf("						无权限，即将返回上一页\n");
				_sleep(1500);
				system("cls");
				break;
			}
			while (1)					//第二层循环，循环的是权限管理系统
			{
				rightsManagement();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 6) {
					printf("输入错误，请重新输入\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					addAdministratorPage();
					break;
				case '2':
					while (1)					//这是第三行循环，循环的是删除管理员页面
					{
						deleteAdministratorPage();
						operate = 0;
						scanf(" %c", &operate);
						while (operate - '0' < 0 || operate - '0' >= 2) {
							printf("输入错误，请重新输入\n");
							scanf(" %c", &operate);
						}
						system("cls");
						if (operate == '0') {
							break;
						}
					}
					break;
				case '3':
					configuepermissionPage();
					system("cls");
					break;
				case '4':
					break;
				case '5':
					Exit();
					break;
				default:
					printf("error：输入的字符不符合要求，请重新输入\n\n");
					break;
				}
				if (operate == '4') {
					system("cls");
					break;
				}
			}
			break;
		case '7':
			while (1)					//这是第二层循环，循环的是系统页面（用于管理员登录）
			{
				System();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 4) {
					printf("输入错误，请重新输入\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					LoginPage();
					break;
				case '2':
					ExitLoginPage();
					break;
				case '3':
					//returnOnepage();
					break;
				default:
					printf("error：输入的字符不符合要求，请重新输入\n\n");
					break;
				}
				if (operate == '3') {
					system("cls");
					break;
				}
			}
			break;
		case '8':
			Exit();
			break;
		default:
			printf("error：输入的字符不符合要求，请重新输入\n\n");
			break;
		}
	}
	return 0;
}