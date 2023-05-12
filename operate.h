#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cardnode {
	char cardID[30];
	char cardPassword[30];
	float cardMoney;
	bool state;
	struct cardnode* next;
}cardnode;

typedef struct Administrator {
	char AdminID[30];
	char AdminPassword[30];
	bool cardManagementKey;			//������Ȩ��
	bool costManagementKey;			//�Ʒѹ���Ȩ��
	bool BillingManagementKey;		//���ù���Ȩ��
	bool BillingStanderManaagementKey;		//�Ʒѱ�׼����Ȩ��
	bool queryStatisicsKey;				//��ѯͳ��Ȩ��
	bool rightsManagementKey;				//Ȩ�޹���Ȩ��
	struct Administrator* next;
}Administrator;

typedef struct head {
	cardnode* head;
}cardlist;

typedef struct Adminhead {
	Administrator* head;
}Adminlist;

typedef struct charge {
	char time1[10],time2[10];
	double money;
	struct charge* next;
}chargelist;

void initRights(void);
void beginPage(void);						//һ��ʼ����ʱ��ҳ��ĵ���
void cardManagement(void);					//��������
void billingStandardManagement(void);		//�Ʒѱ�׼����(δʵ��)
void billingManagement(void);				//�Ʒѹ���(δʵ�֣�
void costManagement(void);					//���ù���(δʵ�֣�
void queryStatistics(void)	;				//��ѯͳ��(δʵ�֣�
void rightsManagement(void);				//Ȩ�޹���
void System(void);							//ϵͳ(δʵ��)
void Exit(void);							//�˳�
bool rightJudgement(bool rightKey);			//Ȩ���ж�
void returnOnepage();

void addCardPage();								//��ӿ�ҳ��
void enquiryCardPage();							//��ѯ��ҳ��
void deleteCardPage();							//ɾ����ҳ��
void newchargingStandardPage();					//�����Ʒѱ�׼ҳ��
void enquirychargingStandardPage();				//��ѯ�Ʒѱ�׼ҳ��
void deletechargingStandardPage();				//ɾ���Ʒѱ�׼ҳ��
void changechargingStandardPage();				//�޸ļƷѱ�׼ҳ��
void computerOperatePage();						//�ϻ�ҳ��
void computerShutPage();						//�»�ҳ��
void RechargePage();							//��ֵҳ��
void returnChargePage();						//�˷�ҳ��
void queryconsumptionRecordPage();				//��ѯ���Ѽ�¼ҳ��
void statisticaltotalTurnoverPage();			//ͳ����Ӫҵ��ҳ��
void statisticalmonthlyTurnoverPage();			//ͳ����Ӫҵ��ҳ��
void addAdministratorPage();					//��ӹ���Աҳ��
void deleteAdministratorPage();					//ɾ������Աҳ��
void configuepermissionPage();					//����Ȩ��ҳ��
void LoginPage();								//��¼ҳ��
void ExitLoginPage();							//�˳���¼ҳ��

void initCardList(cardlist* Alist);										//�������濨������
bool addCard(cardlist* Alist, char* ID, char* password, float money);	//��ӿ�
cardnode* enquiryCard(cardlist* Alist, char* checkID);					//��ѯ��
bool deleteCard(cardlist* Alist, char* checkID, char* checkpassword);	//ע����
void saveListdata(cardlist* Alist);										//���ݱ��棨����
void loadingListdata(cardlist* Alist);									//���ݶ�ȡ������

void ListInitiate(chargelist** Clist);
void newchargingStandardPage();

bool Recharge(char* ID, char* password, float rechargeMoney);			//��ֵ
bool returnCharge(char* ID, char* password);							//�˷�

void initAdminList(Adminlist* Alist);									//��ʼ������Ա����
bool addAdmin(Adminlist* Alist, char* ID, char* password);				//��ӹ���Ա
bool deleteAdmin(Adminlist* Alist,char* checkID);						//ɾ������Ա
Administrator* seekAdministrator(Adminlist* Alist, char* ID);			//���Ҷ�ӦID�Ĺ���Ա��㲢���ض�Ӧ���
void configuePermission(Administrator* temp, char operate);				//���жԹ���ԱȨ�޵����
void addAdminNode(Adminlist* Alist, Administrator temp);				//�������ݶ�ȡ��߶�ȡЧ��
void saveAdmindata(Adminlist* Alist);									//���ݱ���(����Ա�˺�)
void loadingAdmindata(Adminlist* Alist);								//���ݶ�ȡ������Ա�˺ţ�


bool Login(Adminlist* Alist, char* ID, char* password);				//��¼����(��������Ա�˺Ų���������ֱ���ڴ�����
																	//�����жϣ��Դ˱�֤��������Ա�˺�������Ĳ����޸���)
void exitLogin();													//�˳���¼����