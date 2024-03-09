#pragma once
#include <iostream>

class Insurance {
protected: 
	double basePrice;

public:
	Insurance();
	Insurance(double price);
	Insurance(const Insurance& C);
	virtual ~Insurance();

	virtual void print() const abstract; 
	virtual void readFrom(std::istream& in);
	virtual double fullPrice() const abstract;

	bool operator<(const Insurance& I); 
	bool operator>(const Insurance& I);
};

std::istream& operator>>(std::istream& in, Insurance& I); 
Insurance** createArr(const std::string& fileName, size_t& size, size_t& capacity);
void printInsurances(Insurance** arr, size_t size);
double findSumPrice(Insurance** arr, size_t size);
void findCheapest(Insurance** arr, size_t size);
void findMostExpencive(Insurance** arr, size_t size);