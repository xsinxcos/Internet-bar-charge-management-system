#pragma once

void RechargePage();							//充值页面
void returnChargePage();						//退费页面

bool Recharge(char* ID, char* password, float rechargeMoney);			//充值
bool returnCharge(char* ID, char* password);							//退费
