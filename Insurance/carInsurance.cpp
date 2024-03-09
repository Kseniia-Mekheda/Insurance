#include "insurance.h"
#include "carInsurance.h" 

using namespace std;

CarInsurance::CarInsurance()
	:Insurance(),
	engineVolume(0)
{}

CarInsurance::CarInsurance(double price, double volume)
	:Insurance(price),
	engineVolume(volume)
{}

CarInsurance::CarInsurance(const CarInsurance& C)
	:Insurance(C),
	engineVolume(C.engineVolume)
{}

CarInsurance::~CarInsurance() {}

void CarInsurance::print() const {
	cout << "Insurance type: Car Insurance; Engine Volume: " << engineVolume
		<< "; Full price: " << fullPrice() << endl;
}
void CarInsurance::readFrom(std::istream& in) {
	Insurance::readFrom(in);
	in >> engineVolume;
}
double CarInsurance::fullPrice() const {
	if (engineVolume > 2.0) {
		return basePrice + (basePrice * 0.15); 
	}

	if (engineVolume > 3.0) {
		return basePrice + (basePrice * 0.25);
	}
}