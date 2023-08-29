#pragma once

#include "animal.h"

class Cat : public Animal {
public:
	void bark(void);
private:
	int claw;
};