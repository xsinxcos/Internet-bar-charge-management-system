#include"operate.h"
extern cardlist List;

void RechargePage() {
	float rechargeMoney = 0;			//充值的金额
	char checkID[30];
	char checkpassword[30];
	printf("					输入充值的账号信息：\n");
	printf("					ID：\n					");
	scanf("%s", checkID);
	printf("\n");
	printf("					密码：\n					");
	scanf("%s", checkpassword);
	printf("					充值金额：\n					");
	scanf("%f", &rechargeMoney);
	printf("\n");
	if (Recharge(checkID , checkpassword , rechargeMoney)) {
		printf("						充值成功,即将返回上一页\n");
		saveListdata(&List);
	}
	else printf("					充值添加失败，卡号不存在或者已注销\n");
	_sleep(1500);
}					

bool Recharge(char *ID , char *password ,float rechargeMoney) {
	cardnode* p = List.head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(p->cardID, ID) == 0 && strcmp(p->cardPassword, password) == 0 && p->state == true) {
			p->cardMoney += rechargeMoney;
			return true;
		}
	}
	return false;
}

void returnChargePage() {
	char checkID[30];
	char checkpassword[30];
	printf("					输入退费的账号信息：\n");
	printf("					ID：\n					");
	scanf("%s", checkID);
	printf("\n");
	printf("					密码：\n					");
	scanf("%s", checkpassword);
	printf("\n");
	if (returnCharge(checkID , checkpassword)) {
		printf("						退费成功,即将返回上一页\n");
		saveListdata(&List);
	}
	else printf("					退费失败，卡号不存在或者已注销\n");
	_sleep(1500);
}

bool returnCharge(char* ID, char* password) {
	cardnode* p = List.head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(p->cardID, ID) == 0 && strcmp(p->cardPassword, password) == 0 && p->state == true) {
			printf("					退费的金额为：%f\n",p->cardMoney);
			p->cardMoney = 0;
			return true;
		}
	}
	return false;
}