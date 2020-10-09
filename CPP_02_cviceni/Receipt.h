#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {
public:
	Receipt();
	Receipt(int id, double amount, double dph);
	~Receipt();
	void SetId(int id);
	int GetId() const;
	void SetAmount(double amount);
	double GetAmount() const;
	void SetDPH(double dph);
	double GetDPH() const;
private:
	int idReceipt;
	double amount;
	double dph;
};

#endif // !RECEIPT_H


 
