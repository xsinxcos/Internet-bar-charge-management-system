#include"operate.h"

extern Adminlist AList;

void initAdminList(Adminlist* Alist) {
	Alist->head = (Administrator*)malloc(sizeof(Administrator));
	Alist->head->next = NULL;
}

void addAdministratorPage() {
	char ID[30];
	char password[30];
	printf("					输入新添加管理员信息：\n");
	printf("					ID：\n					");
	scanf("%s", ID);
	printf("\n");
	printf("					密码：\n					");
	scanf("%s", password);
	printf("\n");
	if (addAdmin(&AList, ID, password)) {
		printf("						管理员添加成功,即将返回上一页\n");
		saveAdmindata(&AList);
	}
	else printf("					添加失败\n");
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
		printf("					输入需要进行删除的管理员ID\n");
		printf("					ID：\n					");
		scanf("%s", checkID);
		bool flag = deleteAdmin(&AList, checkID);				//使用flag来接收是否注销成功
		if (flag == false) {
			printf("					删除失败，请重新确认管理员账号ID是否错误\n");
		}
		else {
			printf("					注销成功\n");
			saveAdmindata(&AList);
		}
		printf("					输入数字1后，继续进行删除\n					输入数字0，退出删除\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("输入错误，请重新输入\n");
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
	printf("					输入需要进行配置权限的管理员ID\n");
	printf("					ID：\n					");
	scanf("%s", checkID);
	Administrator* temp = seekAdministrator(&AList, checkID);
	if (temp == NULL) {
		printf("					查找失败，请重新确认管理员账号ID是否错误，即将返回\n");
		_sleep(1500);
		system("cls");
		//rightsManagement();
		return;
	}
	else {
		system("cls");
		printf("					查找成功\n");
	}
	printf("				输出对应序号添加权限\n");
	printf("\n");
	printf("				1.卡管理\t2.计费标准管理\t3.计费管理\t\n");
	printf("\n");
	printf("				4.费用管理\t5.查询统计\t6.权限管理\t\n");
	printf("\n");
	printf("				7.返回上一页\t\n");
	while (true)
	{
		char operate = 0;	//operate为进行操作的指令
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' > 8) {
			printf("输入错误，请重新输入\n");
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
		printf("添加成功\n");
		break;
	case '2':
		temp->BillingStanderManaagementKey = true;
		printf("添加成功\n");
		break;
	case '3':
		temp->BillingManagementKey = true;
		printf("添加成功\n");
		break;
	case '4':
		temp->costManagementKey = true;
		printf("添加成功\n");
		break;
	case '5':
		temp->queryStatisicsKey = true;
		printf("添加成功\n");
		break;
	case '6':
		temp->rightsManagementKey = true;
		printf("添加成功\n");
		break;
	default:
		printf("error：输入的字符不符合要求，请重新输入\n\n");
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
		printf("文件打开失败\n");
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
		printf("文件打开失败\n");
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