#include "insurance.h"
#include "carInsurance.h"
#include "familyInsurance.h"
#include <string>
#include <fstream>
using namespace std;

Insurance::Insurance()
	:basePrice(0)
{}

Insurance::Insurance(double price)
	:basePrice(price)
{}

Insurance::Insurance(const Insurance& C)
	:basePrice(C.basePrice)
{}

Insurance::~Insurance() {}

void Insurance::readFrom(istream& in) {
	in >> basePrice;
}

bool Insurance::operator<(const Insurance& I) {
	return this->fullPrice() < I.fullPrice();
}

istream& operator>>(istream& in, Insurance& I) {
	I.readFrom(in);
	return in;
}

Insurance** createArr(const std::string& filename, size_t& n, size_t& count)
{
	ifstream fin(filename);
	fin >> n;
	Insurance** arr = new Insurance * [n];
	count = 0; // на випадок, якщо в файлі будуть не лише потрібні нам значення

	for (size_t i = 0; i < n; ++i)
	{
		char type;
		fin >> type;
		if (type == CarInsurance::CAR_INSURANCE_TYPE) {
			arr[count] = new CarInsurance();
			fin >> *arr[count];
			++count;
		}
		else if (type == FamilyInsurance::FAMILY_INSURANCE_TYPE) {
			arr[count] = new FamilyInsurance();
			fin >> *arr[count];
			++count;
		}
		else
		{
			string line;
			getline(fin, line);
		}
	}
	return arr;
}

void printInsurances(Insurance** arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		arr[i]->print();
	}
	cout << endl;
}

double findSumPrice(Insurance** arr, size_t size) {
	double sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += arr[i]->fullPrice();
	}
	return sum;
}

void findCheapest(Insurance** arr, size_t size) {
	size_t cheapestIndex = 0;
	for (size_t i = 1; i < size; ++i) {
		if (arr[i] < arr[cheapestIndex]) {
			cheapestIndex = i;
		}
	}
	cout << "The cheapest insurance: " << endl;
	arr[cheapestIndex]->print();
}

void findMostExpencive(Insurance** arr, size_t size) {
	size_t mostExpenciveIndex = 0;
	for (size_t i = 1; i < size; ++i) {
		if (arr[i] > arr[mostExpenciveIndex]) {
			mostExpenciveIndex = i;
		}
	}
	cout << "The most expencive insurance: " << endl;
	arr[mostExpenciveIndex]->print();
}