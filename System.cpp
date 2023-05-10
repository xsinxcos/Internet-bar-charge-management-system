#include"operate.h"

extern bool cardManagementKey;					//������Ȩ��
extern bool costManagementKey;					//�Ʒѹ���Ȩ��
extern bool BillingManagementKey;				//���ù���Ȩ��
extern bool BillingStanderManaagementKey;		//�Ʒѱ�׼����Ȩ��
extern bool queryStatisicsKey;					//��ѯͳ��Ȩ��
extern bool rightsManagementKey;				//Ȩ�޹���Ȩ��
extern Adminlist AList;							//ȫ�ֱ������������Ա��Ϣ

void LoginPage() {
	while (1) {
		char ID[30];
		char password[30];
		printf("					�����¼�Ĺ���Ա��Ϣ��\n");
		printf("					ID��\n					");
		scanf("%s", ID);
		printf("\n");
		printf("					���룺\n					");
		scanf("%s", password);
		printf("\n");
		if (Login(&AList, ID, password) == false) {
			printf("					��¼ʧ�ܣ��˺Ų����ڻ����������\n");
		}
		else
		{
			printf("					��¼�ɹ�������������һҳ\n");
			_sleep(1500);
			system("cls");
			return;
		}
		_sleep(1500);
		system("cls");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' >= 4) {
			printf("�����������������\n");
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
			printf("error��������ַ�������Ҫ������������\n\n");
			break;
		}
		if (operate == '3') {
			break;
		}
	}
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
		printf("					�ִ��ڳ�������Աģʽ\n");
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
	printf("						�˳���¼�ɹ�,�����ص���һҳ\n");
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