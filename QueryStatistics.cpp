#include"operate.h"

extern cardlist List;		//ȫ�ֱ��������濨����Ϣ
extern Consumerlist BList;	//ȫ�ֱ�������������������Ϣ
extern chargelist* Clist;       //ȫ�ֱ���������Ʒѱ�׼
extern statisticallist SList;   //ȫ�ֱ����������ϻ�������Ӫҵ��

void queryconsumptionRecordPage() {
	char ID[30];
	char Date1[20] = { 0 }, Date2[20] = { 0 };
	printf("					���뿨��\n");
	printf("					���ţ�\n					");
	scanf("%s", ID);
	printf("					����Ҫ��ѯ��ʱ���(�ꡢ�¡���)��\n");
	scanf("%s%s", Date1, Date2);                                                 //��ʽ��0000-00-00
    printf("					���Ѽ�¼��\n");
	if (!CardExist(ID,Date1,Date2)) {
		printf("					�����Ѽ�¼����ѯʧ��\n");
	}
	_sleep(1000);
}
int CardExist(char *ID,char Date1[],char Date2[]) {
	int i,flag=0;
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	if (fgetc(CARD_LIST) == EOF) {
		fclose(CARD_LIST);
		return -1;
	}
	rewind(CARD_LIST);
	Consumernode* temp=(Consumernode*)malloc(sizeof(Consumernode));
	while (fread(temp, sizeof(Consumernode), 1, CARD_LIST) != 0)
	{
		if(strcmp(temp->cardID, ID) == 0) {
			ConsumePrint(temp,Date1, Date2);
			flag = 1;
		}
	}
	fclose(CARD_LIST);
	return flag;
}

void ConsumePrint(Consumernode* temp,char Date1[],char Date2[]) {
	if (strcmp(Date1, temp->upTime) <= 0 && strcmp(Date2, temp->downTime) >= 0) {
		printf("%s %s %s %f\n", temp->cardID, temp->upTime, temp->downTime, temp->consumpAmount);
	}
}

void statisticaltotalTurnoverPage() {
	char Date1[20], Date2[20];
	double ConsumeSum;
	printf("					����Ҫ��ѯ��һ��ʱ��(�ꡢ�¡���)��\n");
	scanf("%s%s",Date1,Date2 );
	ConsumeSum=statisticaltotal(Date1, Date2);
	if (ConsumeSum == 0) printf("					��ѯ������ʱ��ε���Ӫҵ��\n");
	else {
		printf("					��ʱ���Ӫҵ��Ϊ%f\n", ConsumeSum);
		printf("					��ѯ�ɹ�������������һҳ\n");
	}

	_sleep(1000);
}
double statisticaltotal(char Date1[],char Date2[]) {
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	Consumernode* temp = (Consumernode*)malloc(sizeof(Consumernode));
	double ConsumeSum = 0;
	while (fread(temp, sizeof(Consumernode), 1, CARD_LIST) != 0)
	{
		if (strcmp(Date1, temp->upTime) <= 0 && strcmp(Date2, temp->downTime) >= 0) {
			ConsumeSum = ConsumeSum + temp->consumpAmount;
		}
	}
	fclose(CARD_LIST);
	return ConsumeSum;
}

void statisticalmonthlyTurnoverPage() {
	char* year = (char*)calloc(20, sizeof(char));
	char* Date = (char*)calloc(20, sizeof(char));
	int i = 1,leap;
	printf("					����Ҫ��ѯ����ݣ�\n");
	scanf("%s", year);
	for (i = 1; i < 13; i++) {
		strcpy(Date, year);
		strcat(Date, "-");
		char ch[2] = { '0'};
		if (i < 10) {
			ch[1] = (char)(i + '0');
			strcat(Date, ch);
		}
		else
		{
			ch[0] = '1';
			ch[1] = (char)(i % 10 + '0');
			strcat(Date, ch);
		}
		Date[7] = '\0';
		statisticalmonthly(Date);
	}
	printf("					��ѯ�ɹ�������������һҳ\n");
	_sleep(1000);
}


void statisticalmonthly(char Date[]) {
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	Consumernode* temp = (Consumernode*)malloc(sizeof(Consumernode));
	statisticallist* p = (statisticallist*)malloc(sizeof(statisticallist));
	int UpCount = 0;
	double ConsumeSum = 0;
	while (fread(temp, sizeof(Consumernode), 1, CARD_LIST) != 0)
	{
		if ( down_strcmp(Date, temp->downTime) >0) {
			UpCount++;
			ConsumeSum = ConsumeSum + temp->consumpAmount;
		}
	}
	strcpy(p->Date, Date);
	p->UpCount = UpCount;
	p->ConsumeSum = ConsumeSum;
	printf(" 				%s���ϻ�����Ϊ%d,��Ӫҵ��Ϊ%f\n",Date, UpCount, ConsumeSum);
	SaveMonthlyConsume(p);
	fclose(CARD_LIST);
}

void SaveMonthlyConsume(statisticallist* p) {
	FILE* CARD_LIST = fopen("SaveMonthlyConsume.txt", "a");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fprintf(CARD_LIST, "%s   %d   %lf",p->Date, p->UpCount, p->ConsumeSum);
	fclose(CARD_LIST);
}

void Initiatestatisticallist(statisticallist **head) {
	*head = (statisticallist*)malloc(sizeof(statisticallist));
	strcpy((*head)->Date, "0");
	(*head)->UpCount = 0;
	(*head)->ConsumeSum = 0;
	(*head)->next = NULL;
}

int down_strcmp(char *time1,char *time2) {
	int i;
	for (i = 0; i <= 6; i++) {
		if (time1[i] != time2[i])
			return 0;
	}
	return 1;
}