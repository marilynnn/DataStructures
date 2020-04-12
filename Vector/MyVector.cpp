#include "MyVector.h"
#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

MyVector::MyVector(size_t size, ResizeStrategy strategy, float coef)
	:_size (size), _strategy (strategy), _coef (coef)
{
	switch (_strategy) {

	case (ResizeStrategy::Multiplicative):
		if (size == 0) {
			_capacity = 1;
			_data = nullptr;
		}
		else{
			_capacity = ceil(_coef * _size);
			_data = new ValueType[_capacity];
		}
	break;

	case (ResizeStrategy::Additive) :
		_capacity = ceil(_size + _coef);
		_data = new ValueType[_capacity];
	break;

	default:
		cout<< "incorrect strategy"<<endl;
		break;
	}
}

MyVector::MyVector(size_t size, ValueType value, ResizeStrategy strategy, float coef) 
	:_size(size), _strategy(strategy), _coef(coef)
	{
		switch (_strategy) {

		case (ResizeStrategy::Multiplicative):
			if (size == 0) {
				_capacity = 1;
			}
			else {
				_capacity = ceil(_coef * _size);
			}
			break;

		case (ResizeStrategy::Additive):
			_capacity = ceil(_size + _coef);
			break;

		default:
			cout<< "incorrect strategy"<<endl;
			break;
		}
		

		for (size_t index = 0; index < size; index++) {
			_data[index] = value;
		}
}

MyVector::MyVector(const MyVector& copy) 
	: _size(copy._size), _capacity(copy._capacity),_strategy(copy._strategy),_coef(copy._coef)
{ 
	_data = new ValueType[_capacity];
	for (size_t index = 0; index < _size; index++) {
		_data[index] = copy._data[index];
	}
}

MyVector& MyVector::operator=(const MyVector& copy) {
	if (this == &copy) {
		return *this;
	}

	delete[] _data;

	_size = copy._size;
	_capacity = copy._capacity;
	_strategy = copy._strategy;
	_coef = copy._coef;

	for (size_t index = 0; index < _size; index++) {
		_data[index] = copy._data[index];
	}
	return *this;
}

MyVector::~MyVector() {
	if (_data!= nullptr) {
		delete[] _data;
		_data = nullptr;
	}
	_size = 0;
	_capacity = 0;
}

size_t MyVector::capacity() const {
	return _capacity;
}

size_t MyVector::size() const {
	return _size;
}

float MyVector::loadFactor() {
	return (float)_size / _capacity;
}

ValueType& MyVector::operator[](const size_t i) const {
	if (i > 0 && i < _size) {
		return _data[i];
	}
	else {
		cout<< "incorrect index"<<endl;
			return;
	}
}

void MyVector::pushBack(const ValueType& value) {
	if (loadFactor() < 1) {
		_data[_size] = value;
		++_size;
	}
	else {
		resize();
		_data[_size] = value;
		++_size;

	}
}

void MyVector::insert(const size_t i, const ValueType& value) {
	if (i < 0 || i > _capacity)
	{
		cout<< "incorrect index"<<endl;
		return;
	}

	if (loadFactor() == 1) {
		resize();
	}
	for (int index = _size; index < i; index--) {
		_data[index] = _data[index - 1];
	}
	_data[i] = value;
	_size++;

}

void MyVector::insert(const size_t i, const MyVector& value) {
	if (i < 0 || i > _capacity)
	{
		cout<< "incorrect index"<<endl;
		return;
	}

	if ((value._size + _size) / _capacity >= 1) {
		reserve((value._size + _size)*_coef);
	}
	for (size_t index = value._size + _size - 1; index < i + value._size - 1; index--) {
		_data[index] = _data[index - value._size];
	} 

	for (size_t index = i; index < i + value._size; ++index) {
		_data[index] = value._data[index - i];
	}

}

void MyVector::popBack() {
	_size--;
	resize();
};

void MyVector::erase(const size_t i) {
	if (i < 0 || i > _size-1)
	{
		cout<< "incorrect index"<<endl;
		return;
	}
	for (size_t index = i; index < _size; index++) {
		_data[i] = _data[i + 1];
	}
	_size--;
	resize();
}

void MyVector::erase(const size_t i, const size_t len) {
	if (i < 0 || i > _size - 1)
	{
		cout<< "incorrect index"<<endl;
		return;
	}
	if (i + len > _size-1 )
	{
		cout<< "incorrect lenght"<<endl;
		return;
	}
	for (size_t index = i; index < _size; index++) {
		_data[i] = _data[i + len];
	}
	_size -= len;
	resize();
}

long long int MyVector::find(const ValueType& value, bool isBegin) const {
	if (isBegin) {
		for (size_t index = 0; index < _size; ++index)
			if (_data[index] == value) {
				return index;      
			}
	}
	else {
		for (size_t index = _size - 1; index > 0; --index)
			if (_data[index] == value) {
				return index;      
			}

	}
	return -1; 
}

void MyVector::reserve(const size_t capacity) {
	MyVector bufVector (*this);
	delete[] _data; 
	this->_data = new ValueType[capacity];

	for (size_t index = 0; index < _size; index++) {
		this->_data[index] = bufVector._data[index];
	}
	this->_capacity = capacity;

}

void MyVector::resize(const size_t size, const ValueType value) {
	if (_size == size) {
		cout<< "old size is equal to new size" <<endl;
		return;
	}
	size_t oldSize = _size;
	_size = size;

	if (oldSize < _size) {
		if (loadFactor() > 1) {
			resize();
		}
		for (size_t index = oldSize; index = _size - 1; index++) {
			_data[index] = value;
		}
	}
	else {
		resize();
	}
}
	
void MyVector::resize() {
	if (size == 0) {
		_capacity = 1;
	}
	switch (_strategy) {
		case (ResizeStrategy::Multiplicative):

			if (loadFactor() <= 1 / (_coef * _coef)) {
				_capacity = ceil(1 / _coef  * _capacity);
			}
			else {
				_capacity = ceil(_coef * _size);
			}
			break;

		case (ResizeStrategy::Additive):
			_capacity = ceil(_size + _coef);
			break;

		default:
			cout<< "incorrect strategy"<<endl;
			break;
	}

	MyVector bufVector(*this);
	delete[] _data;
	this->_data = new ValueType[_capacity];

	for (size_t index = 0; index < _size; index++) {
		this->_data[index] = bufVector._data[index];
	}
	

}

void MyVector::clear() {
	delete[] _data;
	_data = nullptr;
	_size = 0;
}

MyVector MyVector::sortedSquares(const MyVector& vec, SortedStrategy strategy) {

	MyVector sorted(vec);

	int leftEnd = 0;
	int rightEnd = vec._size - 1;

	int leftValue = vec._data[leftEnd]* vec._data[leftEnd];
	int rightValue = vec._data[rightEnd] * vec._data[rightEnd];

	switch (strategy) {
	case(SortedStrategy::Descedign):
		for (size_t i = 0; i < vec._size; i++) {
			if (leftValue > rightValue) {
				sorted._data[i] = leftValue;
				leftEnd++;
				leftValue = vec._data[leftEnd] * vec._data[leftEnd];
			}
			else {
				sorted._data[i] = rightValue;
				rightEnd--;
				rightValue = vec._data[rightEnd] * vec._data[rightEnd];
			}
		}
		break;

	case(SortedStrategy::Ascending):
		for (size_t i = vec._size; i > 0; i--) {
			if (leftValue > rightValue) {
				sorted._data[i] = leftValue;
				leftEnd++;
				leftValue = vec._data[leftEnd] * vec._data[leftEnd];
			}
			else {
				sorted._data[i] = rightValue;
				rightEnd--;
				rightValue = vec._data[rightEnd] * vec._data[rightEnd];
			}
		}
		break;
	default:
		cout << "incorrect strategy" <<endl;
		break;

	}
	return sorted;
}