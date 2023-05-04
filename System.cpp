#include"operate.h"

extern bool cardManagementKey;					//卡管理权限
extern bool costManagementKey;					//计费管理权限
extern bool BillingManagementKey;				//费用管理权限
extern bool BillingStanderManaagementKey;		//计费标准管理权限
extern bool queryStatisicsKey;					//查询统计权限
extern bool rightsManagementKey;				//权限管理权限
extern Adminlist AList;							//全局变量，储存管理员信息

void LoginPage() {
	char ID[30];
	char password[30];
	printf("					输入登录的管理员信息：\n");
	printf("					ID：\n					");
	scanf("%s", ID);
	printf("\n");
	printf("					密码：\n					");
	scanf("%s", password);
	printf("\n");
	if (Login(&AList, ID, password) == false) {
		printf("					登录失败，账号不存在或者密码错误\n");
	}
	else
	{
		printf("					登录成功，即将返回首页\n");
	}
	_sleep(1500);
	system("cls");
	//beginPage();
}		

bool Login(Adminlist *Alist, char* ID ,char* password) {
	Administrator* temp = seekAdministrator(Alist, ID);
	if (strcmp(ID, "admin") == 0 && strcmp(password, "admin") == 0) {
		cardManagementKey = true;
		costManagementKey = true;
		BillingManagementKey = true;
		BillingStanderManaagementKey = true;
		queryStatisicsKey = true;
		rightsManagementKey = true;
		printf("					现处于超级管理员模式\n");
		printf("\n");
		return true;
	}
	if (!temp || strcmp(password, temp->AdminPassword) != 0) return false;
	else {
		cardManagementKey = temp->cardManagementKey;
		costManagementKey = temp->costManagementKey;
		BillingManagementKey = temp->BillingManagementKey;
		BillingStanderManaagementKey = temp->BillingStanderManaagementKey;
		queryStatisicsKey = temp->queryStatisicsKey;
		rightsManagementKey = temp->rightsManagementKey;
		return true;
	}
	return false;
}

void ExitLoginPage() {
	printf("						退出登录成功,即将回到上一页\n");
	exitLogin();
	_sleep(1500);
	system("cls");
	//beginPage();
}

void exitLogin() {
	cardManagementKey = false;
	costManagementKey = false;
	BillingManagementKey = false;
	BillingStanderManaagementKey = false;
	queryStatisicsKey = false;
	rightsManagementKey = false;
}