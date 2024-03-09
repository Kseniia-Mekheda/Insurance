#include <iostream>
#include <fstream>
#include <string>

#include "insurance.h"
#include "carInsurance.h"
#include "familyInsurance.h"

using namespace std;

int main() {
	ifstream fin("insurances.txt");
	size_t size;
	fin >> size;
	Insurance** insurances = new Insurance * [size];
	int count = 0; // на випадок, якщо в файлі будуть не лише потрібні нам значення

	for (size_t i = 0; i < size; ++i) {
		char type;
		fin >> type;
		if (type == CarInsurance::CAR_INSURANCE_TYPE) {
			insurances[count] = new CarInsurance();
			fin >> *insurances[count];
			++count;
		}
		else if (type == FamilyInsurance::FAMILY_INSURANCE_TYPE) {
			insurances[count] = new FamilyInsurance();
			fin >> *insurances[count];
			++count;
		}
		else {
			string line;
			getline(fin, line);
		}
	}

	fin.close();
	printInsurances(insurances, count);

	cout << "The sum of the prices of all insurances is: " << findSumPrice(insurances, count) << endl;
	cout << endl;

	findCheapest(insurances, count);
	cout << endl;
	findMostExpencive(insurances, count);

	return 0; 
}