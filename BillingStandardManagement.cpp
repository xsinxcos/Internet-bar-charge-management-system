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
		if (tag == 1) {
			ListInitiate(&Clist);
			chargelist* rear = Clist;
			printf("					����Ʒѱ�׼��\n");
			while (1) {
				chargelist* p = (chargelist*)malloc(sizeof(chargelist));
				printf("					����ĳ��ʱ��εļƷѱ�׼��\n");
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
		/*_sleep(1500);
		system("cls");
		cardManagement();*/
}
void enquirychargingStandardPage() {
	char time[10];
	printf("					�����ϻ�ʱ�䣺\n");
	scanf("%s", time);
	chargelist* p = Clist->next;
	while (p != NULL) {
		if (strcmp(p->time1, time) < 0) {
			printf("					�Ʒѱ�׼Ϊ��%.2f\n",p->money);
		}
	}
}
void deletechargingStandardPage() {

}
void changechargingStandardPage() {

}