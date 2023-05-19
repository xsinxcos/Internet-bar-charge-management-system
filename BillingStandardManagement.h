#pragma once
typedef struct charge {
	char time1[10], time2[10];
	double money;
	struct charge* next;
}chargelist;

void newchargingStandardPage();					//新增计费标准页面
void enquirychargingStandardPage();				//查询计费标准页面
void deletechargingStandardPage();				//删除计费标准页面
void changechargingStandardPage();				//修改计费标准页面

void ListInitiate(chargelist** Clist);                                  //创建计费标准的链表
void newchargingStandard();                                             //新增计费标准
chargelist* enquirychargingStandard(char* time);                        //查询计费标准
bool deletechargingStandard(char* time1, char* time2);                  //删除计费标准
bool changechargingStandard(char* time1, char* time2, double money);    //修改计费标准
void saveChargeListdata();                                              //数据保存（计费标准）
void loadingChargeListdata();                                           //数据读取（计费标准）
