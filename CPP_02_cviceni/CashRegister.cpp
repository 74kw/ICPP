#include "CashRegister.h"
#include "Receipt.h"
#include <exception>
#define COUNTER__INIT_VALUE 1000

int CashRegister::idCounter = COUNTER__INIT_VALUE;

Receipt& CashRegister::CreateReceipt(double amount, double dph)
{
    
    if (receiptCount == 10)
        throw new std::exception("CashRegister is full");
    receipts[receiptCount] = Receipt(idCounter + receiptCount, amount, dph);
    receiptCount++;
    return receipts[receiptCount - 1];
        
}

Receipt& CashRegister::GetReceipt(int id)
{
    for (int i = 0; i < receiptCount; i++)
    {
        if (receipts[i].GetId() == id)
        {
            return receipts[i];
        }
    }
    return receipts[0];
}

double CashRegister::GetAmount() const
{
    double amount = 0;
    for (int i = 0; i < receiptCount; i++)
    {
        amount += receipts[i].GetAmount();
    }
    return amount;
}

double CashRegister::GetAmountWithDPH() const
{
    double amount = 0;
    for (int i = 0; i < receiptCount; i++)
    {
        amount += receipts[i].GetAmount() * (1+ receipts[i].GetDPH()/100);
    }
    return amount;
}

CashRegister::CashRegister()
{
    receipts = new Receipt[10];
    receiptCount = 0;
}

CashRegister::~CashRegister()
{
    delete[] receipts;
}
