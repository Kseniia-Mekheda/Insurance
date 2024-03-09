#pragma once
#include "insurance.h"

class FamilyInsurance : public Insurance {
private:
	size_t membersQuantity;

public:
	static const char FAMILY_INSURANCE_TYPE = 'F';
	FamilyInsurance();
	FamilyInsurance(double basePrice, size_t quantity);
	FamilyInsurance(const FamilyInsurance& C);
	virtual ~FamilyInsurance();

	virtual void print() const override;
	virtual void readFrom(std::istream& in) override;
	virtual double fullPrice() const override;
};