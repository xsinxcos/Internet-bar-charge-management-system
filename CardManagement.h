#pragma once
typedef struct cardnode {
	char cardID[30];
	char cardPassword[30];
	float cardMoney;
	bool state;
	struct cardnode* next;
}cardnode;

typedef struct {
	cardnode* head;
}cardlist;

void addCardPage();								//��ӿ�ҳ��
void enquiryCardPage();							//��ѯ��ҳ��
void deleteCardPage();							//ɾ����ҳ��

void initCardList(cardlist* Alist);										//�������濨������
bool addCard(cardlist* Alist, char* ID, char* password, float money);	//��ӿ�
cardnode* enquiryCard(cardlist* Alist, char* checkID);					//��ѯ��
bool deleteCard(cardlist* Alist, char* checkID, char* checkpassword);	//ע����
void saveListdata(cardlist* Alist);										//���ݱ��棨����
void loadingListdata(cardlist* Alist);									//���ݶ�ȡ������
