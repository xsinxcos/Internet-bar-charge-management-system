#pragma once
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


typedef struct Adminhead {
	Administrator* head;
}Adminlist;

void addAdministratorPage();					//添加管理员页面
void deleteAdministratorPage();					//删除管理员页面
void configuepermissionPage();					//配置权限页面

void initAdminList(Adminlist* Alist);									//初始化管理员名单
bool addAdmin(Adminlist* Alist, char* ID, char* password);				//添加管理员
bool deleteAdmin(Adminlist* Alist, char* checkID);						//删除管理员
Administrator* seekAdministrator(Adminlist* Alist, char* ID);			//查找对应ID的管理员结点并返回对应结点
void configuePermission(Administrator* temp, char operate);				//进行对管理员权限的添加
void addAdminNode(Adminlist* Alist, Administrator temp);				//用于数据读取提高读取效率
void saveAdmindata(Adminlist* Alist);									//数据保存(管理员账号)
void loadingAdmindata(Adminlist* Alist);								//数据读取（管理员账号）
