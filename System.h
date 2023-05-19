#pragma once
#include"RightsManagement.h"

void LoginPage();								//登录页面
void ExitLoginPage();							//退出登录页面

bool Login(Adminlist* Alist, char* ID, char* password);				//登录操作(超级管理员账号不用链表储存直接在代码中
//进行判断，以此保证超级管理员账号与密码的不可修改性)
void exitLogin();													//退出登录操作
