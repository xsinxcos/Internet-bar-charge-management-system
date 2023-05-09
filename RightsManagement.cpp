#include"operate.h"

extern Adminlist AList;

void initAdminList(Adminlist* Alist) {
	Alist->head = (Administrator*)malloc(sizeof(Administrator));
	Alist->head->next = NULL;
}

void addAdministratorPage() {
	char ID[30];
	char password[30];
	printf("					��������ӹ���Ա��Ϣ��\n");
	printf("					ID��\n					");
	scanf("%s", ID);
	printf("\n");
	printf("					���룺\n					");
	scanf("%s", password);
	printf("\n");
	if (addAdmin(&AList, ID, password)) {
		printf("						����Ա��ӳɹ�,����������һҳ\n");
		saveAdmindata(&AList);
	}
	else printf("					���ʧ��\n");
	_sleep(1500);
	system("cls");
}

bool addAdmin(Adminlist *Alist,char* ID, char* password) {
	Administrator* p = (Administrator*)calloc(1,sizeof(Administrator));
	strcpy(p->AdminID, ID);
	strcpy(p->AdminPassword, password);
	p->next = NULL;
	Administrator* temp = Alist->head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = p;
	return true;
}

void deleteAdministratorPage() {
	while (1) {
		char checkID[30];
		printf("					������Ҫ����ɾ���Ĺ���ԱID\n");
		printf("					ID��\n					");
		scanf("%s", checkID);
		bool flag = deleteAdmin(&AList, checkID);				//ʹ��flag�������Ƿ�ע���ɹ�
		if (flag == false) {
			printf("					ɾ��ʧ�ܣ�������ȷ�Ϲ���Ա�˺�ID�Ƿ����\n");
		}
		else {
			printf("					ע���ɹ�\n");
			saveAdmindata(&AList);
		}
		printf("					��������1�󣬼�������ɾ��\n					��������0���˳�ɾ��\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("�����������������\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '0') {
			break;
		}
	}
}

bool deleteAdmin(Adminlist* Alist, char* checkID) {
	Administrator* p = Alist->head;
	if (p->next == NULL) return false;
	while (p->next)
	{
		if (strcmp(p->next->AdminID, checkID) == 0) {
			Administrator* temp = p->next;
			if (temp->next) {
				p->next = temp->next;
			}
			else
			{
				p->next = NULL;
			}
			free(temp);
			return true;
		}
		p = p->next;
	}
	return false;
}
void configuepermissionPage() {
	char checkID[30];
	printf("					������Ҫ��������Ȩ�޵Ĺ���ԱID\n");
	printf("					ID��\n					");
	scanf("%s", checkID);
	Administrator* temp = seekAdministrator(&AList, checkID);
	if (temp == NULL) {
		printf("					����ʧ�ܣ�������ȷ�Ϲ���Ա�˺�ID�Ƿ���󣬼�������\n");
		_sleep(1500);
		system("cls");
		//rightsManagement();
		return;
	}
	else {
		system("cls");
		printf("					���ҳɹ�\n");
	}
	printf("				�����Ӧ������Ȩ��\n");
	printf("\n");
	printf("				1.������\t2.�Ʒѱ�׼����\t3.�Ʒѹ���\t\n");
	printf("\n");
	printf("				4.���ù���\t5.��ѯͳ��\t6.Ȩ�޹���\t\n");
	printf("\n");
	printf("				7.������һҳ\t\n");
	while (true)
	{
		char operate = 0;	//operateΪ���в�����ָ��
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' > 8) {
			printf("�����������������\n");
			scanf(" %c", &operate);
		}
		if (operate == '7') break;
		configuePermission(temp ,operate);
		saveAdmindata(&AList);
	}
}

void configuePermission(Administrator *temp , char operate) {
	
	/*system("cls");*/
	switch (operate)
	{
	case '1':
		temp->cardManagementKey = true;
		printf("��ӳɹ�\n");
		break;
	case '2':
		temp->BillingStanderManaagementKey = true;
		printf("��ӳɹ�\n");
		break;
	case '3':
		temp->BillingManagementKey = true;
		printf("��ӳɹ�\n");
		break;
	case '4':
		temp->costManagementKey = true;
		printf("��ӳɹ�\n");
		break;
	case '5':
		temp->queryStatisicsKey = true;
		printf("��ӳɹ�\n");
		break;
	case '6':
		temp->rightsManagementKey = true;
		printf("��ӳɹ�\n");
		break;
	default:
		printf("error��������ַ�������Ҫ������������\n\n");
		break;
	}
}

Administrator* seekAdministrator(Adminlist* Alist, char* ID) {
	Administrator* p = Alist->head;
	while (p->next)
	{
		p = p->next;
		if (strcmp(p->AdminID, ID) == 0)
			return p;
	}
	return NULL;
}

void saveAdmindata(Adminlist* Alist) {
	FILE* CARD_LIST = fopen("admin.txt", "w");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	Administrator* p = Alist->head;
	while (p->next)
	{
		p = p->next;
		fwrite(p, sizeof(Administrator), 1, CARD_LIST);
	}
	fclose(CARD_LIST);
	return;
}

void loadingAdmindata(Adminlist* Alist) {
	FILE* CARD_LIST = fopen("admin.txt", "r");
	if (CARD_LIST == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	if (fgetc(CARD_LIST) == EOF) {
		fclose(CARD_LIST);
		return;
	}
	rewind(CARD_LIST);
	Administrator* p = Alist->head;
	Administrator temp;
	while (!feof(CARD_LIST))
	{
		fread(&temp, sizeof(cardnode), 1, CARD_LIST);
		addAdminNode(&AList, temp);
	}
	fclose(CARD_LIST);
	return;
}

void addAdminNode(Adminlist* Alist, Administrator temp) {
	Administrator* p = Alist->head;
	Administrator* Add = (Administrator*)calloc(1, sizeof(Administrator));
	strcpy(Add->AdminID, temp.AdminID);
	strcpy(Add->AdminPassword, temp.AdminPassword);
	Add->BillingManagementKey = temp.BillingManagementKey;
	Add->BillingStanderManaagementKey = temp.BillingStanderManaagementKey;
	Add->cardManagementKey = temp.cardManagementKey;
	Add->costManagementKey = temp.costManagementKey;
	Add->queryStatisicsKey = temp.queryStatisicsKey;
	Add->rightsManagementKey = temp.rightsManagementKey;
	Add->next = NULL;
	while (p->next)
	{
		p = p->next;
	}
	p->next = Add;
}