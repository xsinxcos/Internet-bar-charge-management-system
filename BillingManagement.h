//#include"operate.h"
#include <stdio.h>
#include <time.h>
typedef struct Consumernode{
	char cardID[30];
	char upTime[20];			//��ʽ��0000-00-00 00:00
	char downTime[20];
	double consumpAmount;
	struct Consumernode* next;
}Consumernode;

typedef struct head{
	Consumernode* head;
}Consumerlist;

void computerOperatePage();						//�ϻ�ҳ��
void computerShutPage();						//�»�ҳ��

bool isActivate(char* checkID, char* checkPassword);//�ж��Ƿ���Ч
void initConsumerlist();						//��ʼ������

void getDate(char* nowTime);					//��ȡʱ�䲢�洢����Ӧ��������
void addConsuming(char* ID);					//��ʼ����
bool completeConsuming(char* ID);				//��������
void saveConsuming();							//�����������ѵĽ���
void loadConsuming();							//�����������ѵĽ���

void saveRecordsConsume(Consumernode* saveData);						//������ɵ����Ѽ�¼���ĵ�����ͳ��
double settleConsuming(char* upTime, char* downTime);					//����ʱ���ֵ