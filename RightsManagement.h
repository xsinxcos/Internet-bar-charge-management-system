#pragma once
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


typedef struct Adminhead {
	Administrator* head;
}Adminlist;

void addAdministratorPage();					//��ӹ���Աҳ��
void deleteAdministratorPage();					//ɾ������Աҳ��
void configuepermissionPage();					//����Ȩ��ҳ��

void initAdminList(Adminlist* Alist);									//��ʼ������Ա����
bool addAdmin(Adminlist* Alist, char* ID, char* password);				//��ӹ���Ա
bool deleteAdmin(Adminlist* Alist, char* checkID);						//ɾ������Ա
Administrator* seekAdministrator(Adminlist* Alist, char* ID);			//���Ҷ�ӦID�Ĺ���Ա��㲢���ض�Ӧ���
void configuePermission(Administrator* temp, char operate);				//���жԹ���ԱȨ�޵����
void addAdminNode(Adminlist* Alist, Administrator temp);				//�������ݶ�ȡ��߶�ȡЧ��
void saveAdmindata(Adminlist* Alist);									//���ݱ���(����Ա�˺�)
void loadingAdmindata(Adminlist* Alist);								//���ݶ�ȡ������Ա�˺ţ�
