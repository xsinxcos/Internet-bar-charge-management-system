#pragma once
#include"RightsManagement.h"

void LoginPage();								//��¼ҳ��
void ExitLoginPage();							//�˳���¼ҳ��

bool Login(Adminlist* Alist, char* ID, char* password);				//��¼����(��������Ա�˺Ų���������ֱ���ڴ�����
//�����жϣ��Դ˱�֤��������Ա�˺�������Ĳ����޸���)
void exitLogin();													//�˳���¼����
