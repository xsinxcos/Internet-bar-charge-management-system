#pragma once
typedef struct charge {
	char time1[10], time2[10];
	double money;
	struct charge* next;
}chargelist;

void newchargingStandardPage();					//�����Ʒѱ�׼ҳ��
void enquirychargingStandardPage();				//��ѯ�Ʒѱ�׼ҳ��
void deletechargingStandardPage();				//ɾ���Ʒѱ�׼ҳ��
void changechargingStandardPage();				//�޸ļƷѱ�׼ҳ��

void ListInitiate(chargelist** Clist);                                  //�����Ʒѱ�׼������
void newchargingStandard();                                             //�����Ʒѱ�׼
chargelist* enquirychargingStandard(char* time);                        //��ѯ�Ʒѱ�׼
bool deletechargingStandard(char* time1, char* time2);                  //ɾ���Ʒѱ�׼
bool changechargingStandard(char* time1, char* time2, double money);    //�޸ļƷѱ�׼
void saveChargeListdata();                                              //���ݱ��棨�Ʒѱ�׼��
void loadingChargeListdata();                                           //���ݶ�ȡ���Ʒѱ�׼��
