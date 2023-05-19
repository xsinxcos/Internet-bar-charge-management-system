#include"operate.h"

extern cardlist List;		//全局变量，储存卡的信息
extern Consumerlist* BList;	//全局变量，储存消费信息
extern chargelist* Clist;       //全局变量，储存计费标准

void computerOperatePage() {
	while (1) {
		system("cls");
		char ID[30];
		char password[30];
		float money;
		printf("					输入卡号，密码\n");
		printf("					卡号：\n					");
		scanf("%s", ID);
		printf("\n");
		printf("					密码：\n					");
		scanf("%s", password);
		if (isActivate(ID, password)) {
			printf("					已上机\n");
			_sleep(1000);
			break;
		}
		else
		{
			printf("					上机失败，卡不存在或者已注销\n");
		}
		printf("\n");
		_sleep(1000);
	}
}

bool isActivate(char* checkID, char* checkPassword) {
	cardnode* temp = enquiryCard(&List, checkID);				//用于判断卡是否存在
	if (temp == NULL && temp->state == false) return false;
	return true;
}

void initConsumerlist() {
	BList->head = (Consumernode*)malloc(sizeof(Consumernode));
	BList->head->next = NULL;
}

void recordsConsumer() {

}
void computerShutPage() {

}