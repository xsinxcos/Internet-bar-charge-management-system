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
			if (cardManagementKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			while (1)			//���ǵڶ���ѭ����ѭ���Ŀ�����ҳ��(ʹ��switch caseʵ���ӹ���)
			{
				
				cardManagement();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 6) {
					printf("�����������������\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					addCardPage();
					_sleep(1500);
					system("cls");
					break;
				case '2':
					while (1)				//���ǵ�����ѭ����ѭ���Ĳ�ѯ��ҳ��
					{
						enquiryCardPage();
						operate = 0;
						scanf(" %c", &operate);
						getchar();
						while (operate - '0' < 0 || operate - '0' >= 2) {
							printf("�����������������\n");
							scanf(" %c", &operate);
						}
						system("cls");
						if (operate == '0') {
							break;
						}
					}
					break;
				case '3':
					while (1)				//���ǵ�����ѭ����ѭ����ע����ҳ��
					{
						deleteCardPage();
						operate = 0;
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
					break;
				case '4':
					//returnOnepage();
					break;
				case '5':
					Exit();
					break;
				default:
					printf("error��������ַ�������Ҫ������������\n\n");
					break;
				}
				if (operate == '4') {
					system("cls");
					break;
				}
			}
			break;
		case '2':
			if (BillingStanderManaagementKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			billingStandardManagement();
			break;
		case '3':
			if (BillingManagementKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			billingManagement();
			break;
		case '4':
			if (costManagementKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			costManagement();
			break;
		case '5':
			if (queryStatisicsKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			queryStatistics();
			break;
		case '6':
			if (rightsManagementKey == false) {
				printf("						��Ȩ�ޣ�����������һҳ\n");
				_sleep(1500);
				system("cls");
				break;
			}
			while (1)					//�ڶ���ѭ����ѭ������Ȩ�޹���ϵͳ
			{
				rightsManagement();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 6) {
					printf("�����������������\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					addAdministratorPage();
					break;
				case '2':
					while (1)					//���ǵ�����ѭ����ѭ������ɾ������Աҳ��
					{
						deleteAdministratorPage();
						operate = 0;
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
					break;
				case '3':
					configuepermissionPage();
					system("cls");
					break;
				case '4':
					break;
				case '5':
					Exit();
					break;
				default:
					printf("error��������ַ�������Ҫ������������\n\n");
					break;
				}
				if (operate == '4') {
					system("cls");
					break;
				}
			}
			break;
		case '7':
			while (1)					//���ǵڶ���ѭ����ѭ������ϵͳҳ�棨���ڹ���Ա��¼��
			{
				System();
				operate = 0;
				scanf(" %c", &operate);
				while (operate - '0' <= 0 || operate - '0' >= 4) {
					printf("�����������������\n");
					scanf(" %c", &operate);
				}
				system("cls");
				switch (operate)
				{
				case '1':
					LoginPage();
					break;
				case '2':
					ExitLoginPage();
					break;
				case '3':
					//returnOnepage();
					break;
				default:
					printf("error��������ַ�������Ҫ������������\n\n");
					break;
				}
				if (operate == '3') {
					system("cls");
					break;
				}
			}
			break;
		case '8':
			Exit();
			break;
		default:
			printf("error��������ַ�������Ҫ������������\n\n");
			break;
		}
	}
	return 0;
}