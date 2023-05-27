#include"operate.h"

extern cardlist List;		//ȫ�ֱ��������濨����Ϣ
extern Consumerlist BList;	//ȫ�ֱ���������������Ϣ
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
			addConsuming(ID);
			saveConsuming();
			_sleep(1000);
			break;
		}
		else
		{
			printf("					�ϻ�ʧ�ܣ��������ڻ������ϻ�\n");
			_sleep(1000);
			break;
		}
		printf("\n");
		_sleep(1000);
	}
}

bool isActivate(char* checkID, char* checkPassword) {
	cardnode* temp = enquiryCard(&List, checkID);				//�����жϿ��Ƿ����
	if (temp == NULL || temp->state == false) return false;
	Consumernode* p = BList.head;
	while (p->next) {
		if (strcmp(p->next->cardID, checkID) == 0) return false;
		p = p->next;
	}
	return true;
}

void initConsumerlist() {
	(BList).head = (Consumernode*)calloc(1,sizeof(Consumernode));
	(BList).head->next = NULL;
}

void addConsuming(char* ID) {
	Consumernode* temp = (Consumernode*)calloc(1, sizeof(Consumernode));
	getDate(temp->upTime);
	temp->next = NULL;
	strcpy(temp->cardID, ID);

	Consumernode* p = BList.head;
	while (p->next) {
		p = p->next;
	}
	p->next = temp;
	return;
}

void computerShutPage() {
	while (1) {
		system("cls");
		char ID[30];
		char password[30];
		float money;
		printf("					���뿨��\n");
		printf("					���ţ�\n					");
		scanf("%s", ID);
		if (completeConsuming(ID)) {
			saveConsuming();
			printf("					���»�\n");
			_sleep(1000);
			break;
		}
		else
		{
			printf("					�»�ʧ�ܣ��������ڻ�����ע��\n");
			_sleep(1000);
			break;
		}
		printf("\n");
		_sleep(1000);
	}
}

bool completeConsuming(char* ID) {
	Consumernode* p = BList.head;
	bool isExit = false;		//�����ж�ID�Ƿ���������
	while (p->next)
	{
		if (strcmp(p->next->cardID, ID) == 0) {
			isExit = true;
			Consumernode* temp = p->next;
			getDate(temp->downTime);
			saveRecordsConsume(temp);
			p->next = temp->next;
			free(temp);
			break;
		}
		p = p->next;
	}
	return isExit;
}

void saveConsuming() {
	FILE* CARD_LIST = fopen("consuming.txt", "w");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	Consumernode* p = BList.head;
	while (p->next)
	{
		p = p->next;
		fwrite(p, sizeof(Consumernode), 1, CARD_LIST);
	}
	fclose(CARD_LIST);
	return;
}

void loadConsuming() {
	FILE* CARD_LIST = fopen("consuming.txt", "r");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	if (fgetc(CARD_LIST) == EOF) {
		fclose(CARD_LIST);
		return;
	}
	rewind(CARD_LIST);
	Consumernode* p = BList.head;
	while (!feof(CARD_LIST))
	{
		Consumernode* temp = (Consumernode*)calloc(1,sizeof(Consumernode));
		fread(temp, sizeof(Consumernode), 1, CARD_LIST);
		temp->next = NULL;
		p->next = temp;
		p = p->next;
	}
	fclose(CARD_LIST);
	return;
}

void saveRecordsConsume(Consumernode *saveData) {
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "a");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	saveData->consumpAmount = settleConsuming(saveData->upTime, saveData->downTime);
	printf("%lf", saveData->consumpAmount);
	fwrite(saveData, sizeof(Consumernode), 1, CARD_LIST);
	fclose(CARD_LIST);
	return;
}

double settleConsuming(char *upTime ,char* downTime) {
	char* time = (char*)calloc(10, sizeof(char));
	for (int i = 11; i < 16; i++) {
		time[i - 11] = upTime[i];
	}
	chargelist* p = enquirychargingStandard(time);
	if (p == NULL) {
		printf("							��ǰʱ������շѱ�׼,�շѱ�׼��ʼ��Ϊ��\n");
		return 0;
	}
	double money = p->money;

	double D_MIN = 0;
	for (int i = 0; i < 16; i++) {
		int up = upTime[i] - '0';
		int down = downTime[i] - '0';
		if (up == down) continue;

		//����ʱ�������
		switch (i)
		{
		case 0 :
			D_MIN += (down - up) * (1000 * 365 * 24 * 60);
		case 1 :
			D_MIN += (down - up) * (100 * 365 * 24 * 60);
		case 2 :
			D_MIN += (down - up) * (10 * 365 * 24 * 60);
		case 3:
			D_MIN += (down - up) * (365 * 24 * 60);
		case 5:
			D_MIN += (down - up) * (10 * 30 * 24 * 60);
		case 6 :
			D_MIN += (down - up) * (30 * 24 * 60);
		case 8:
			D_MIN += (down - up) * (10 * 24 * 60);
		case 9:
			D_MIN += (down - up) * (24 * 60);
		case 11:
			D_MIN += (down - up) * 10 * 60;
		case 12:
			D_MIN += (down - up) * 60;
		case 14:
			D_MIN += (down - up) * 10;
		case 15:
			D_MIN += (down - up);
		default:
			break;
		}
	}
	return (double)(p->money * (D_MIN / 60));
}

void getDate(char* nowTime) {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int year = timeinfo->tm_year + 1900; // ����Ǵ�1900�꿪ʼ��ģ���Ҫ����1900
	int month = timeinfo->tm_mon + 1;    // �·ݴ�0��ʼ�㣬��Ҫ��1
	int day = timeinfo->tm_mday;
	int hour = timeinfo->tm_hour;
	int min = timeinfo->tm_min;

	//�����intת��Ϊchar��������
	for (int i = 3; i >= 0; i--) {
		int temp = year % 10;
		nowTime[i] = temp + '0';
		year /= 10;
	}
	nowTime[4] = '-';

	//���´�intת��Ϊchar��������
	for (int i = 6; i >= 5; i--) {
		int temp = month % 10;
		nowTime[i] = temp + '0';
		month /= 10;
	}
	nowTime[7] = '-';

	//���մ�intת��Ϊchar��������
	for (int i = 9; i >= 8; i--) {
		int temp = day % 10;
		nowTime[i] = temp + '0';
		day /= 10;
	}
	nowTime[10] = ' ';

	//��Сʱ��intת��Ϊchar��������
	for (int i = 12; i >= 11; i--) {
		int temp = hour % 10;
		nowTime[i] = temp + '0';
		hour /= 10;
	}
	nowTime[13] = ':';

	//�����Ӵ�intת��Ϊchar��������
	for (int i = 15; i >= 14; i--) {
		int temp = min % 10;
		nowTime[i] = temp + '0';
		min /= 10;
	}
}