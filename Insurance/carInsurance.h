#pragma once
#include "insurance.h"

class CarInsurance : public Insurance {
private: 
	double engineVolume; 

public:
	static const char CAR_INSURANCE_TYPE = 'C';
	CarInsurance();
	CarInsurance(double price, double volume);
	CarInsurance(const CarInsurance& C);
	virtual ~CarInsurance();

	virtual void print() const override;
	virtual void readFrom(std::istream& in) override;
	virtual double fullPrice() const override;
};