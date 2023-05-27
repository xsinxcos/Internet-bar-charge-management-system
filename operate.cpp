#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "operate.h"

extern bool cardManagementKey;			//卡管理权限
extern bool costManagementKey;			//计费管理权限
extern bool BillingManagementKey;		//费用管理权限
extern bool BillingStanderManaagementKey;		//计费标准管理权限
extern bool queryStatisicsKey;				//查询统计权限
extern bool rightsManagementKey;				//权限管理权限


void beginPage(void)
{
	printf("			  （￣へ￣）-----------------------------------------\n");
	printf("					欢迎使用网吧收费管理系统\n");
	printf("				 请输入以下命令所对应的数字进行相关操作\n");
	printf("\n");
	printf("				1.卡管理\t2.计费标准管理\t3.计费管理\t\n");
	printf("\n");
	printf("				4.费用管理\t5.查询统计\t6.权限管理\t\n");
	printf("\n");
	printf("				7.系统\t	8.退出程序\t\n");
	printf("			  ---------------------------------------------------\n");
	//char operate = 0;	//operate为进行操作的指令
	//scanf(" %c", &operate);
	//while (operate - '0' <= 0 || operate - '0' > 8) {
	//	printf("输入错误，请重新输入\n");
	//	scanf(" %c", &operate);
	//}
	//system("cls");
	//switch (operate)
	//{
	//case '1':
	//	cardManagement();
	//	break;
	//case '2':
	//	billingStandardManagement();
	//	break;
	//case '3':
	//	billingManagement();
	//	break;
	//case '4':
	//	costManagement();
	//	break;
	//case '5':
	//	queryStatistics();
	//	break;
	//case '6':
	//	rightsManagement();
	//	break;
	//case '7':
	//	System();
	//	break;
	//case '8':
	//	Exit();
	//	break;
	//default:
	//	printf("error：输入的字符不符合要求，请重新输入\n\n");
	//	break;
	//}
	//exit(0);
}

void cardManagement() {
	while (1) {
		system("cls");
		printf("			  （￣へ￣）-----------------------------------------\n");
		printf("					欢迎使用网吧收费管理系统\n");
		printf("				 请输入以下命令所对应的数字进行相关操作\n");
		printf("\n");
		printf("\n");
		printf("				1.添加卡\t2.查询卡\t3.注销卡\t\n");
		printf("\n");
		printf("				4.返回上一页\t5.退出程序\t\n");
		printf("\n");
		printf("			  ---------------------------------------------------\n");
		char operate = 0;
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
			break;
		case '2':
			enquiryCardPage();
			break;
		case '3':
			deleteCardPage();
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
		if (operate == '4')
			break;
	}
};

void billingStandardManagement(void) {
	while (1) {
		system("cls");
	    printf("			  （￣へ￣）-----------------------------------------\n");
	    printf("					欢迎使用网吧收费管理系统\n");
	    printf("				 请输入以下命令所对应的数字进行相关操作\n");
	    printf("\n");
	    printf("\n");
	    printf("				1.新增计费标准\t2.查询计费标准\t3.删除计费标准\t\n");
	    printf("\n");
	    printf("				4.修改计费标准\t5.返回上一页\t6.退出程序\t\n");
	    printf("\n");
	    printf("			  ---------------------------------------------------\n");
	    char operate = 0;
	    scanf(" %c", &operate);
	    while (operate - '0' <= 0 || operate - '0' >= 7) {
		    printf("输入错误，请重新输入\n");
		    scanf(" %c", &operate);
	     }
	     system("cls");
	     switch (operate)
	     {
	     case '1':
		       newchargingStandardPage();
		       break;
	     case '2':
		       enquirychargingStandardPage();
		       break;
	     case '3':
		       deletechargingStandardPage();
		       break;
	     case '4':
		       changechargingStandardPage();
		       break;
	     case '5':
		       break;
	     case '6':
		       Exit();
		       break;
	     default:
		       printf("error：输入的字符不符合要求，请重新输入\n\n");
		       break;
	     }
		 if (operate == '5') break;
	}
};

void billingManagement(void) {
	while (1)
	{
		system("cls");
		printf("			  （￣へ￣）-----------------------------------------\n");
		printf("					欢迎使用网吧收费管理系统\n");
		printf("				 请输入以下命令所对应的数字进行相关操作\n");
		printf("\n");
		printf("\n");
		printf("				1.上机\t      2.下机\t   3.返回上一页\t\n");
		printf("\n");
		printf("				4.退出程序\t\n");
		printf("\n");
		printf("			  ---------------------------------------------------\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' >= 5) {
			printf("输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		switch (operate)
		{
		case '1':
			computerOperatePage();
			break;
		case '2':
			computerShutPage();
			break;
		case '3':
			//returnOnepage();
			break;
		case '4':
			Exit();
			break;
		default:
			printf("error：输入的字符不符合要求，请重新输入\n\n");
			break;
		}
		if (operate == '3') break;
	}
};

void costManagement(void) {
	while (1) {
		system("cls");
		printf("			  （￣へ￣）-----------------------------------------\n");
		printf("					欢迎使用网吧收费管理系统\n");
		printf("				 请输入以下命令所对应的数字进行相关操作\n");
		printf("\n");
		printf("\n");
		printf("				1.充值\t      2.退费\t   3.返回上一页\t\n");
		printf("\n");
		printf("				4.退出程序\t\n");
		printf("\n");
		printf("			  ---------------------------------------------------\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' >= 5) {
			printf("输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		switch (operate)
		{
		case '1':
			RechargePage();
			break;
		case '2':
			returnChargePage();
			break;
		case '3':
			break;
		case '4':
			Exit();
			break;
		default:
			printf("error：输入的字符不符合要求，请重新输入\n\n");
			break;
		}
		if (operate == '3')
			break;
	}
};

void queryStatistics(void) {
	printf("			  （￣へ￣）-----------------------------------------\n");
	printf("					欢迎使用网吧收费管理系统\n");
	printf("				 请输入以下命令所对应的数字进行相关操作\n");
	printf("\n");
	printf("\n");
	printf("				1.查询消费记录\t2.统计总营业额\t3.统计月营业额\t\n");
	printf("\n");
	printf("				4.返回上一页\t5.退出程序\t\n");
	printf("\n");
	printf("			  ---------------------------------------------------\n");
	char operate = 0;
	scanf(" %c", &operate);
	while (operate - '0' <= 0 || operate - '0' >= 6) {
		printf("输入错误，请重新输入\n");
		scanf(" %c", &operate);
	}
	system("cls");
	switch (operate)
	{
	case '1':
		queryconsumptionRecordPage();
		break;
	case '2':
		statisticaltotalTurnoverPage();
		break;
	case '3':
		statisticalmonthlyTurnoverPage();
		break;
	case '4':
		returnOnepage();
		break;
	case '5':
		Exit();
		break;
	default:
		printf("error：输入的字符不符合要求，请重新输入\n\n");
		break;
	}
	exit(0);

};

void rightsManagement(void) {
	while (1) {
		printf("			  （￣へ￣）-----------------------------------------\n");
		printf("					欢迎使用网吧收费管理系统\n");
		printf("				 请输入以下命令所对应的数字进行相关操作\n");
		printf("\n");
		printf("\n");
		printf("				1.添加管理员\t2.删除管理员\t3.配置权限\t\n");
		printf("\n");
		printf("				4.返回上一页\t5.退出程序\t\n");
		printf("\n");
		printf("			  ---------------------------------------------------\n");
		char operate = 0;
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
			deleteAdministratorPage();
			break;
		case '3':
			configuepermissionPage();
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
		if (operate == '4')
			break;
	}
};

void System(void) {
	while (1) {
		printf("			  （￣へ￣）-----------------------------------------\n");
		printf("					欢迎使用网吧收费管理系统\n");
		printf("				 请输入以下命令所对应的数字进行相关操作\n");
		printf("\n");
		printf("\n");
		printf("				1.登录\t   2.退出登录\t   3.返回上一页\t\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("			  ---------------------------------------------------\n");
		char operate = 0;
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
			break;
		default:
			printf("error：输入的字符不符合要求，请重新输入\n\n");
			break;
		}
		if (operate == '3')
			break;
	}
};

void Exit(void) {
	exit(0);
};
void returnOnepage() {
	beginPage();
}

void initRights(void) {
	cardManagementKey = false;
	costManagementKey = false;
	BillingManagementKey = false;
	BillingStanderManaagementKey = false;
	queryStatisicsKey = false;
	rightsManagementKey = false;
}

bool rightJudgement(bool rightKey) {
	if (rightKey == false) {
		printf("						无权限，即将返回上一页\n");
		_sleep(1500);
		system("cls");
		return false;
	}
	return true;
}
