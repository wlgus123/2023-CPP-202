#pragma once

#include "all.h"

class Cat : public Animal {
public:
	void bark(void);
private:
	int claw_;
};