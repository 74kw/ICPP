#include "Person.h"
#include <fstream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


static void WriteString(std::ofstream& output, const std::string& obj) {
	int stringLength = obj.length();

	output.write((const char*)&stringLength, sizeof(stringLength));
	output.write(obj.c_str(), stringLength);
}
static std::string ReadString(std::ifstream& input) {
	int stringLength = 0;
	input.read((char*)&stringLength, sizeof(int));
	char* temp = new char[stringLength + 1];
	temp[stringLength] = '\0';
	input.read(temp, stringLength);
	std::string string = temp;
	delete [] temp;
	return string;
}

static void SaveText() {
	Person os1 = Person("Adam","Novak",Address("Moravcova","Praha",28002),Date(20,10,2000));
	Person os2 = Person("Josef", "Trnka", Address("Hlodavcova", "Brno", 38000), Date(11, 3, 2002));
	Person os3 = Person("Ondrej", "Novotny", Address("Rudova", "Pardubice", 48000), Date(8, 12, 1995));

	int const pocet = 3;
	Person pole[pocet];
	pole[0] = os1;
	pole[1] = os2;
	pole[2] = os3;

	std::ofstream output{ "output.txt" };
	if (!output)
		throw std::runtime_error("Bad file path");
	//output.open("output.txt", std::ios_base::out);
	output << pocet << std::endl;
	for (int i = 0; i < pocet; i++)
	{
		output << pole[i];
	}
	output.close();

}

static void SaveBinary() {
	Person os1 = Person("Adam","Novak",Address("Moravcova","Praha",28002),Date(20,10,2000));
	Person os2 = Person("Josef", "Trnka", Address("Hlodavcova", "Brno", 38000), Date(11, 3, 2002));
	Person os3 = Person("Ondrej", "Novotny", Address("Rudova", "Pardubice", 48000), Date(8, 12, 1995));

	int const pocet = 3;
	Person pole[pocet];
	pole[0] = os1;
	pole[1] = os2;
	pole[2] = os3;
	
	//open stream
	std::ofstream outputBinary{ "binary.dat", std::ios_base::out | std::ios_base::binary };
	if (!outputBinary)
		throw std::runtime_error("Bad file path");
	// write size of array
	outputBinary.write((const char*)&pocet, sizeof(pocet));
	for (int i = 0; i < pocet; i++)
	{
		//WriteString(outputBinary, pole[i].GetFirstName());
		//WriteString(outputBinary, pole[i].GetLastName());
		//outputBinary.write((const char*)&pole[i].GetDate(), sizeof(pole[i].GetDate()));
		//WriteString(outputBinary, pole[i].GetAddress().GetStreet());
		//WriteString(outputBinary, pole[i].GetAddress().GetCity());
		//int zip = pole[i].GetAddress().GetZipCode();
		//outputBinary.write((const char*)&zip, sizeof(zip));
		pole[i].ToBinary(outputBinary);
	}
	outputBinary.close();

}
static void LoadText() {

	std::ifstream input{ "output.txt" };
	if (!input)
		throw std::runtime_error("Bad file path");
	int pocet = 0;
	input >> pocet;
	Person* pole = new Person[pocet];

	for (int i = 0; i < pocet; i++)
	{
		pole[i] = Person{};
		input >> pole[i];
		std::cout << pole[i];
	}

	delete[] pole;

}
static void LoadBinary() {

	//open stream
	std::ifstream inputBinary{ "binary.dat", std::ios_base::in | std::ios_base::binary };
	if (!inputBinary)
		throw std::runtime_error("Bad file path");
	int pocet = 0;
	// read size of array
	inputBinary.read((char*)&pocet, sizeof(int));

	Person* pole = new Person[pocet];
	for (int i = 0; i < pocet; i++)
	{
		//pole[i] = Person();
		//pole[i].SetFirstName(ReadString(inputBinary));
		//pole[i].SetLastName(ReadString(inputBinary));
		//Date datum;
		//inputBinary.read((char*)&datum, sizeof(datum));
		//pole[i].SetDate(datum);
		//Address adresa;
		//adresa.SetStreet(ReadString(inputBinary));
		//adresa.SetCity(ReadString(inputBinary));
		//int zip;
		//inputBinary.read((char*)&zip, sizeof(zip));
		//adresa.SetZipCode(zip);
		//pole[i].SetAddress(adresa);
		pole[i].LoadBinary(inputBinary);
		std::cout << pole[i];
	}


	delete[] pole;
}

int main() {
	
	SaveBinary();
	LoadBinary();


	//Memory LEAK Check start
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	//Memory Leak Check end
}
