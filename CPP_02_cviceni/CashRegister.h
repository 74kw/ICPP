#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister {
private:
	Receipt* receipts;
	static int idCounter;
	int receiptCount;

public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double, double);
	Receipt& GetReceipt(int id);
	double GetAmount() const;
	double GetAmountWithDPH() const;

};

#endif // !CASH_REGISTER_H
