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
		if (tag == 1) {
			ListInitiate(&Clist);
			chargelist* rear = Clist;
			printf("					输入计费标准：\n");
			while (1) {
				chargelist* p = (chargelist*)malloc(sizeof(chargelist));
				printf("					输入某个时间段的计费标准：\n");
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
		/*_sleep(1500);
		system("cls");
		cardManagement();*/
}
void enquirychargingStandardPage() {
	char time[10];
	printf("					输入上机时间：\n");
	scanf("%s", time);
	chargelist* p = Clist->next;
	while (p != NULL) {
		if (strcmp(p->time1, time) < 0) {
			printf("					计费标准为：%.2f\n",p->money);
		}
	}
}
void deletechargingStandardPage() {

}
void changechargingStandardPage() {

}