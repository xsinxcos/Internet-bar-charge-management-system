#include"operate.h"

extern cardlist List;		//全局变量，储存卡的信息
extern Consumerlist BList;	//全局变量，储存正在消费信息
extern chargelist* Clist;       //全局变量，储存计费标准
extern statisticallist SList;   //全局变量，储存上机次数和营业额

void queryconsumptionRecordPage() {
	char ID[30];
	char Date1[20] = { 0 }, Date2[20] = { 0 };
	printf("					输入卡号\n");
	printf("					卡号：\n					");
	scanf("%s", ID);
	printf("					输入要查询的时间段(年、月、日)：\n");
	scanf("%s%s", Date1, Date2);                                                 //格式：0000-00-00
    printf("					消费记录：\n");
	if (!CardExist(ID,Date1,Date2)) {
		printf("					无消费记录，查询失败\n");
	}
	_sleep(1000);
}
int CardExist(char *ID,char Date1[],char Date2[]) {
	int i,flag=0;
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
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
	printf("					输入要查询的一段时间(年、月、日)：\n");
	scanf("%s%s",Date1,Date2 );
	ConsumeSum=statisticaltotal(Date1, Date2);
	if (ConsumeSum == 0) printf("					查询不到该时间段的总营业额\n");
	else {
		printf("					该时间段营业额为%f\n", ConsumeSum);
		printf("					查询成功，即将返回上一页\n");
	}

	_sleep(1000);
}
double statisticaltotal(char Date1[],char Date2[]) {
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
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
	printf("					输入要查询的年份：\n");
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
	printf("					查询成功，即将返回上一页\n");
	_sleep(1000);
}


void statisticalmonthly(char Date[]) {
	FILE* CARD_LIST = fopen("ConsumptionRecords.txt", "r");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
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
	printf(" 				%s的上机次数为%d,总营业额为%f\n",Date, UpCount, ConsumeSum);
	SaveMonthlyConsume(p);
	fclose(CARD_LIST);
}

void SaveMonthlyConsume(statisticallist* p) {
	FILE* CARD_LIST = fopen("SaveMonthlyConsume.txt", "a");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
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