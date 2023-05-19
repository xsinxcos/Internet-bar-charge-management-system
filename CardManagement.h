#pragma once
typedef struct cardnode {
	char cardID[30];
	char cardPassword[30];
	float cardMoney;
	bool state;
	struct cardnode* next;
}cardnode;

typedef struct {
	cardnode* head;
}cardlist;

void addCardPage();								//添加卡页面
void enquiryCardPage();							//查询卡页面
void deleteCardPage();							//删除卡页面

void initCardList(cardlist* Alist);										//创建储存卡的链表
bool addCard(cardlist* Alist, char* ID, char* password, float money);	//添加卡
cardnode* enquiryCard(cardlist* Alist, char* checkID);					//查询卡
bool deleteCard(cardlist* Alist, char* checkID, char* checkpassword);	//注销卡
void saveListdata(cardlist* Alist);										//数据保存（卡）
void loadingListdata(cardlist* Alist);									//数据读取（卡）
