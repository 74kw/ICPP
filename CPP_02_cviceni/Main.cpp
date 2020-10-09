#include "CashRegister.h"
#include "Receipt.h"
#include <iostream>

int main() {

	std::cout << "Zacatek programu" << std::endl;

	CashRegister pokladna = CashRegister();
	//Receipt hledana = pokladna.GetReceipt(1002);
	/*for (int i = 0; i < 10; i++)
	{
		pokladna.CreateReceipt(200, 15);

	}*/
	Receipt rc1 = pokladna.CreateReceipt(100, 21);
	Receipt rc2 = pokladna.CreateReceipt(200, 21);
	Receipt rc3 = pokladna.CreateReceipt(400, 21);

	std::cout << rc1.GetId() << "-" << rc1.GetAmount() << "-" << rc1.GetDPH() << std::endl;
	std::cout << rc2.GetId() << "-" << rc2.GetAmount() << "-" << rc2.GetDPH() << std::endl;
	std::cout << rc3.GetId() << "-" << rc3.GetAmount() << "-" << rc3.GetDPH() << std::endl;
	
	//Receipt hledana = pokladna.GetReceipt(1005);
	Receipt hledana = pokladna.GetReceipt(1002);
	std::cout << hledana.GetId() << "-" << hledana.GetAmount() << "-" << hledana.GetDPH() << std::endl;
	std::cout << pokladna.GetAmount() << std::endl;
	std::cout << pokladna.GetAmountWithDPH() << std::endl;


	std::cout << "Konec programu" << std::endl;
	
	return 0;
}