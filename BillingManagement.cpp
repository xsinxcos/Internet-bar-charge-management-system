#include"operate.h"

extern cardlist List;		//ȫ�ֱ��������濨����Ϣ
extern Consumerlist* BList;	//ȫ�ֱ���������������Ϣ
extern chargelist* Clist;       //ȫ�ֱ���������Ʒѱ�׼

void computerOperatePage() {
	while (1) {
		system("cls");
		char ID[30];
		char password[30];
		float money;
		printf("					���뿨�ţ�����\n");
		printf("					���ţ�\n					");
		scanf("%s", ID);
		printf("\n");
		printf("					���룺\n					");
		scanf("%s", password);
		if (isActivate(ID, password)) {
			printf("					���ϻ�\n");
			_sleep(1000);
			break;
		}
		else
		{
			printf("					�ϻ�ʧ�ܣ��������ڻ�����ע��\n");
		}
		printf("\n");
		_sleep(1000);
	}
}

bool isActivate(char* checkID, char* checkPassword) {
	cardnode* temp = enquiryCard(&List, checkID);				//�����жϿ��Ƿ����
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