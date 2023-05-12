#include"operate.h"

extern chargelist *Clist;

void ListInitiate(chargelist **Clist) {
	*Clist = (chargelist*)malloc(sizeof(chargelist));
	(*Clist)->next = NULL;
}
void newchargingStandardPage() {
		int tag;                                                                      //判断是否需要新增计费标准
		printf("					请确定是否需要新增计费标准（1为需要，0为不需要）：\n");
		scanf("%d", &tag);
		if (tag != 1 && tag != 0) {
			printf("					输入错误，请重新输入：\n");
			scanf("%d", &tag);
		}
		if (tag == 1) {
			ListInitiate(&Clist);
			chargelist* rear = Clist;
			printf("					输入计费标准：\n");
			while (1) {
				chargelist* p = (chargelist*)malloc(sizeof(chargelist));
				printf("					输入某个时间段的计费标准(例如0：00)：\n");
				printf("					当输入time时结束\n");
				scanf("%s%s", p->time1,p->time2);
				if ( strcmp(p->time1,"time") ==0 ) break;
				printf("\n");
				printf("					输入该时间段的计费标准（元/小时）：\n");
				scanf("%lf", &p->money);
				printf("\n");
				rear->next = p;
				rear = p;
				p->next = NULL;
			}
			printf("					新增成功，即将返回上一页\n");
		}
		else printf("					无需新增，即将返回上一页\n");
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
	printf("					输入上机时间：\n");
	scanf("%s", time);
	chargelist* p = Clist->next;

	while (p != NULL) {
		if (my_strcmp(p->time1, time) <= 0&&my_strcmp(p->time2,time)>0) {
			printf("					计费标准为：%.2f（元/小时）\n",p->money);
			printf("					查询成功，即将返回上一页\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("					查询失败\n");
		printf("					输入数字1后，继续进行查询\n					输入数字0，退出查询\n");
		char operate=0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			enquirychargingStandardPage();
		}
		else if (operate == '0') {
			printf("					即将返回上一页\n");
		}
	}
	_sleep(1500);
}
void deletechargingStandardPage() {
	char time1[10],time2[10];
	printf("					输入想要删除的计费标准（某个时间段）：\n");
	scanf("%s%s", time1, time2);
	chargelist* q=Clist,*p=q->next;
	while (p != NULL) {
		if (strcmp(p->time1, time1) == 0 && strcmp(p->time2, time2) == 0) {
			q->next = p->next;
			free(p);
			printf("					删除成功，即将返回上一页\n");
			break;
		}
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("					查询不到该时间段，删除失败\n");
		printf("					输入数字1后，重新进行删除\n					输入数字0，退出删除\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			deletechargingStandardPage();
		}
		else if (operate == '0') {
			printf("					即将返回上一页\n");
		}
	}
	_sleep(1500);
}
void changechargingStandardPage() {
	char time1[10], time2[10];
	printf("					输入想要修改的计费标准（某个时间段）：\n");
	scanf("%s%s", time1, time2);
	chargelist* p = Clist->next;
	while (p != NULL) {
		if (strcmp(p->time1, time1) == 0 && strcmp(p->time2, time2) == 0) {
			printf("					输入修改后的计费标准（元/小时）：\n");
			scanf("%lf", &p->money);
			printf("					修改成功，即将返回上一页\n");
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("					查询不到该时间段，修改失败\n");
		printf("					输入数字1后，重新进行修改\n					输入数字0，退出修改\n");
		char operate = 0;
		scanf(" %c", &operate);
		while (operate - '0' < 0 || operate - '0' >= 2) {
			printf("					输入错误，请重新输入\n");
			scanf(" %c", &operate);
		}
		system("cls");
		if (operate == '1') {
			changechargingStandardPage();
		}
		else if (operate == '0') {
			printf("					即将返回上一页\n");
		}
	}
	_sleep(1500);
}