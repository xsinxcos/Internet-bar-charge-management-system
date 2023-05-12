#include"operate.h"

extern chargelist *Clist;

void ListInitiate(chargelist **Clist) {
	*Clist = (chargelist*)malloc(sizeof(chargelist));
	(*Clist)->next = NULL;
}
void newchargingStandardPage() {
		int tag;                                                                      //�ж��Ƿ���Ҫ�����Ʒѱ�׼
		printf("					��ȷ���Ƿ���Ҫ�����Ʒѱ�׼��1Ϊ��Ҫ��0Ϊ����Ҫ����\n");
		scanf("%d", &tag);
		if (tag != 1 && tag != 0) {
			printf("					����������������룺\n");
			scanf("%d", &tag);
		}
		if (tag == 1) {
			ListInitiate(&Clist);
			chargelist* rear = Clist;
			printf("					����Ʒѱ�׼��\n");
			while (1) {
				chargelist* p = (chargelist*)malloc(sizeof(chargelist));
				printf("					����ĳ��ʱ��εļƷѱ�׼(����0��00)��\n");
				printf("					������timeʱ����\n");
				scanf("%s%s", p->time1,p->time2);
				if ( strcmp(p->time1,"time") ==0 ) break;
				printf("\n");
				printf("					�����ʱ��εļƷѱ�׼��Ԫ/Сʱ����\n");
				scanf("%lf", &p->money);
				printf("\n");
				rear->next = p;
				rear = p;
				p->next = NULL;
			}
			printf("					�����ɹ�������������һҳ\n");
		}
		else printf("					��������������������һҳ\n");
		_sleep(1500);
		
}
int my_strcmp(char* s1, char* s2) {
	int i;
	if (strlen(s1) < strlen(s2)) return -1;
	else if (strlen(s1) > strlen(s2)) return 1;
	else {
		for (i = 0; s1[i] == s2[i] && s1[i] != 0; i++);
		if (s1[i] == s2[i]) return 0;
		if (s1[i] < s2[i]) return -1;
		return 1;
	}
}
void enquirychargingStandardPage() {
	char time[10];
	printf("					�����ϻ�ʱ�䣺\n");
	scanf("%s", time);
	chargelist* p = Clist->next;

	while (p != NULL) {
		if (my_strcmp(p->time1, time) <= 0&&my_strcmp(p->time2,time)>0) {
			printf("					�Ʒѱ�׼Ϊ��%.2f��Ԫ/Сʱ��\n",p->money);
			printf("					��ѯ�ɹ�������������һҳ\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("					��ѯʧ��\n");
		printf("					��������1�󣬼������в�ѯ\n					��������0���˳���ѯ\n");
		char operate=0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					�����������������\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			enquirychargingStandardPage();
		}
		else if (operate == '0') {
			printf("					����������һҳ\n");
		}
	}
	_sleep(1500);
}
void deletechargingStandardPage() {
	char time1[10],time2[10];
	printf("					������Ҫɾ���ļƷѱ�׼��ĳ��ʱ��Σ���\n");
	scanf("%s%s", time1, time2);
	chargelist* q=Clist,*p=q->next;
	while (p != NULL) {
		if (strcmp(p->time1, time1) == 0 && strcmp(p->time2, time2) == 0) {
			q->next = p->next;
			free(p);
			printf("					ɾ���ɹ�������������һҳ\n");
			break;
		}
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("					��ѯ������ʱ��Σ�ɾ��ʧ��\n");
		printf("					��������1�����½���ɾ��\n					��������0���˳�ɾ��\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					�����������������\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			deletechargingStandardPage();
		}
		else if (operate == '0') {
			printf("					����������һҳ\n");
		}
	}
	_sleep(1500);
}
void changechargingStandardPage() {
	char time1[10], time2[10];
	printf("					������Ҫ�޸ĵļƷѱ�׼��ĳ��ʱ��Σ���\n");
	scanf("%s%s", time1, time2);
	chargelist* p = Clist->next;
	while (p != NULL) {
		if (strcmp(p->time1, time1) == 0 && strcmp(p->time2, time2) == 0) {
			printf("					�����޸ĺ�ļƷѱ�׼��Ԫ/Сʱ����\n");
			scanf("%lf", &p->money);
			printf("					�޸ĳɹ�������������һҳ\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("					��ѯ������ʱ��Σ��޸�ʧ��\n");
		printf("					��������1�����½����޸�\n					��������0���˳��޸�\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					�����������������\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			changechargingStandardPage();
		}
		else if (operate == '0') {
			printf("					����������һҳ\n");
		}
	}
	_sleep(1500);
}