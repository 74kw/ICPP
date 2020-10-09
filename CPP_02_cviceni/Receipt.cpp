#include "Receipt.h"

Receipt::Receipt()
{
}

Receipt::Receipt(int id, double amount, double dph)
{
	this->idReceipt = id;
	this->amount = amount;
	this->dph = dph;
}

Receipt::~Receipt()
{
}

void Receipt::SetId(int id)
{
	this->idReceipt = id;
}

int Receipt::GetId() const
{
	return idReceipt;
}

void Receipt::SetAmount(double amount)
{
	this->amount = amount;
}

double Receipt::GetAmount() const
{
	return this->amount;
}

void Receipt::SetDPH(double dph)
{
	this->dph = dph;
}

double Receipt::GetDPH() const
{
	return this->dph;
}
