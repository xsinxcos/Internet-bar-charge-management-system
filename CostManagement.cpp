#include"operate.h"
extern cardlist List;

void RechargePage() {
	float rechargeMoney = 0;			//��ֵ�Ľ��
	char checkID[30];
	char checkpassword[30];
	printf("					�����ֵ���˺���Ϣ��\n");
	printf("					ID��\n					");
	scanf("%s", checkID);
	printf("\n");
	printf("					���룺\n					");
	scanf("%s", checkpassword);
	printf("					��ֵ��\n					");
	scanf("%f", &rechargeMoney);
	printf("\n");
	if (Recharge(checkID , checkpassword , rechargeMoney)) {
		printf("						��ֵ�ɹ�,����������һҳ\n");
		saveListdata(&List);
	}
	else printf("					��ֵ���ʧ�ܣ����Ų����ڻ�����ע��\n");
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
	printf("					�����˷ѵ��˺���Ϣ��\n");
	printf("					ID��\n					");
	scanf("%s", checkID);
	printf("\n");
	printf("					���룺\n					");
	scanf("%s", checkpassword);
	printf("\n");
	if (returnCharge(checkID , checkpassword)) {
		printf("						�˷ѳɹ�,����������һҳ\n");
		saveListdata(&List);
	}
	else printf("					�˷�ʧ�ܣ����Ų����ڻ�����ע��\n");
	_sleep(1500);
}

bool returnCharge(char* ID, char* password) {
	cardnode* p = List.head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(p->cardID, ID) == 0 && strcmp(p->cardPassword, password) == 0 && p->state == true) {
			printf("					�˷ѵĽ��Ϊ��%f\n",p->cardMoney);
			p->cardMoney = 0;
			return true;
		}
	}
	return false;
}