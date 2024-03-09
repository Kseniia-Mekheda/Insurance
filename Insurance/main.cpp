#include <iostream>
#include <fstream>
#include <string>

#include "insurance.h"
#include "carInsurance.h"
#include "familyInsurance.h"

using namespace std;

int main() {
	size_t size; 
	size_t count; 
	Insurance** insurances = createArr("insurances.txt", size, count);
	printInsurances(insurances, count);

	cout << "The sum of the prices of all insurances is: " << findSumPrice(insurances, count) << endl;
	cout << endl;

	findCheapest(insurances, count);
	cout << endl;
	findMostExpencive(insurances, count);

	return 0; 
}