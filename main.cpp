#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operate.h"

cardlist List;		//ȫ�ֱ��������濨����Ϣ
Adminlist AList;	//ȫ�ֱ������������Ա��Ϣ

bool cardManagementKey;					//������Ȩ��
bool costManagementKey;					//�Ʒѹ���Ȩ��
bool BillingManagementKey;				//���ù���Ȩ��
bool BillingStanderManaagementKey;		//�Ʒѱ�׼����Ȩ��
bool queryStatisicsKey;					//��ѯͳ��Ȩ��
bool rightsManagementKey;				//Ȩ�޹���Ȩ��

int main(void) 
{
	initRights();
	initCardList(&List);
	initAdminList(&AList);
	loadingListdata(&List);
	loadingAdmindata(&AList);
	while (1)								//��һ��ѭ��Ϊbeginҳ(ʹ��switch caseʵ���ӹ���)
	{
		system("cls");
		beginPage();
		char operate = 0;					//operateΪ���в�����ָ��
		scanf(" %c", &operate);
		while (operate - '0' <= 0 || operate - '0' > 8) {
			printf("�����������������\n");
			scanf(" %c", &operate);
		}
		system("cls");
		switch (operate)					
		{
		case '1':
			if(rightJudgement(cardManagementKey)){
				cardManagement();
			}
			break;
		case '2':
			if (rightJudgement(BillingStanderManaagementKey)) {
				billingStandardManagement();
			}
			break;
		case '3':
			if (rightJudgement(BillingManagementKey)) {
				billingManagement();
			}
			break;
		case '4':
			if (rightJudgement(costManagementKey)) {
				costManagement();
			}
			break;
		case '5':
			if (rightJudgement(queryStatisicsKey)) {
				queryStatistics();
			}
			break;
		case '6':
			if (rightJudgement(rightsManagementKey)) {
				rightsManagement();
			}
			break;
		case '7':
			System();
			break;
		}
	}
	return 0;
}