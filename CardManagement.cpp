#include"operate.h"

extern  cardlist List;

void initCardList(cardlist* Alist) {
	Alist->head = (cardnode*)malloc(sizeof(cardnode));
	Alist->head->next = NULL;
}

bool addCard(cardlist *Alist ,char *ID ,char *password ,float money) {
	cardnode* p = (cardnode*)malloc(sizeof(cardnode));
	strcpy(p->cardID, ID);
	strcpy(p->cardPassword, password);
	p->cardMoney = money;
	p->state = true;
	p->next = NULL;
	cardnode* temp = Alist->head;
	/*if (!temp->next) {
		temp->next = p;
		return true;
	}*/
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = p;
	return true;
}

void addCardPage() {
	char ID[30];
	char password[30];
	float money;
	printf("					输入卡号，密码和开卡金额\n");
	printf("					卡号：\n					");
	scanf("%s", ID);
	printf("\n");
	printf("					密码：\n					");
	scanf("%s", password);
	printf("\n");
	printf("					开卡金额：\n					");
	scanf("%f", &money);
	printf("\n");
	if (addCard(&List, ID, password, money)) {
		printf("						卡添加成功,即将返回上一页\n");
		saveListdata(&List);
	}
	else printf("					添加失败\n");
	_sleep(1500);
	system("cls");
}
cardnode* enquiryCard(cardlist *Alist ,char *checkID) {
	cardnode* p = Alist->head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(p->cardID, checkID) == 0)
			return p;
	}
	return NULL;
}

void enquiryCardPage() {
	while (1) {
		system("cls");
		char checkID[30];
		printf("					输入需要进行查询的卡号\n");
		printf("					卡号：\n					");
		scanf("%s", checkID);
		cardnode* temp = enquiryCard(&List, checkID);
		if (temp != NULL) {
			printf("			  --------------------------------------------------\n");
			printf("					查询成功，卡号相关信息如下：\n");
			printf("					卡号：%s\n\n", temp->cardID);
			printf("					密码：%s\n\n", temp->cardPassword);
			printf("					剩余金额：%f\n\n", temp->cardMoney);
			if (temp->state)
				printf("					卡的状态：已激活\n\n");
			else
				printf("					卡的状态：已注销\n\n");
			printf("			  --------------------------------------------------\n");
		}
		else printf("					查询失败，卡号不存在\n");
		printf("					输入数字1后，继续进行查询\n					输入数字0，退出查询\n");
		char operate = 0;
		scanf(" %c", &operate);
		getchar();
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		if (operate == '0') {
			break;
		}
	}
}

bool deleteCard(cardlist* Alist, char* checkID ,char *checkpassword) {
	cardnode* p = Alist->head;
	/*if (p == NULL) return false;*/
	while (p->next)
	{
		if (strcmp(p->cardID, checkID) == 0 && strcmp(p->cardPassword, checkpassword) == 0) {
			p->state = false;
			return true;
		}
		p = p->next;
	}
	if (strcmp(p->cardID, checkID) == 0 && strcmp(p->cardPassword, checkpassword) == 0) {
		p->state = false;
		return true;
	}
	return false;
}

void deleteCardPage() {
	while (1) {
		char checkID[30];
		char checkpassword[30];
		printf("					输入需要进行注销的卡号\n");
		printf("					卡号：\n					");
		scanf("%s", checkID);
		printf("					输入需要进行注销的卡号的密码\n");
		printf("					密码：\n					");
		scanf("%s", checkpassword);
		bool flag = deleteCard(&List, checkID, checkpassword);				//使用flag来接收是否注销成功
		if (flag == false) {
			printf("					注销失败，请重新确认账号ID或者密码是否错误\n");
		}
		else {
			printf("					注销成功\n");
			saveListdata(&List);
		}
		printf("					输入数字1后，继续进行注销\n					输入数字0，退出注销\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		if (operate == '0') {
			break;
		}
	}
}

void saveListdata(cardlist *Alist) {
	FILE* CARD_LIST = fopen("card.txt", "wb");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	cardnode* p = Alist->head;
	while (p->next)
	{
		p = p->next;
		fwrite(p ,sizeof(cardnode),1,CARD_LIST);
	}
	fclose(CARD_LIST);
	return;
}

void loadingListdata(cardlist* Alist) {
	FILE* CARD_LIST = fopen("card.txt", "rb");
	if (CARD_LIST == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
	if (fgetc(CARD_LIST) == EOF) {
		fclose(CARD_LIST);
		return ;
	}
	rewind(CARD_LIST);
	cardnode* p = Alist->head;
	cardnode temp;
	while (!feof(CARD_LIST))
	{
		fread(&temp, sizeof(cardnode), 1, CARD_LIST);
		addCard(&List, temp.cardID, temp.cardPassword, temp.cardMoney);
		if (temp.state == false) deleteCard(&List, temp.cardID, temp.cardPassword);
	}
	fclose(CARD_LIST);
	return;
}
