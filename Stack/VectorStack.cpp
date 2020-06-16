#include "VectorStack.h"

VectorStack::VectorStack() {};

VectorStack::VectorStack(const VectorStack& copyVector) : MyVector(copyVector) {};

void VectorStack::push(const ValueType& value) {

	pushBack(value);
};

void VectorStack::pop() {

	popBack();

};

const ValueType& VectorStack::top() const {

	return (*this) [size() - 1];
};

bool VectorStack::isEmpty() const {

	return (MyVector::size() == 0 ? true : false);
};


size_t VectorStack::size() const {

	return MyVector::size();
};