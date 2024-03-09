#include "insurance.h"
#include "familyInsurance.h"

using namespace std; 

FamilyInsurance::FamilyInsurance()
	:Insurance(),
	membersQuantity(0)
{}

FamilyInsurance::FamilyInsurance(double basePrice, size_t quantity)
	:Insurance(basePrice),
	membersQuantity(quantity)
{}

FamilyInsurance::FamilyInsurance(const FamilyInsurance& C)
	:Insurance(C),
	membersQuantity(C.membersQuantity)
{}

FamilyInsurance::~FamilyInsurance() {}

void FamilyInsurance::print() const {
	cout << "Insurance type: Family; Family members quantity: " << membersQuantity 
		<< "; Full price: " << fullPrice() << endl;
}
void FamilyInsurance::readFrom(std::istream& in) {
	Insurance::readFrom(in);
	in >> membersQuantity;
}
double FamilyInsurance::fullPrice() const {
	return basePrice * membersQuantity;
}