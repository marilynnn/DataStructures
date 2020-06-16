#pragma once
#include "StackImplementation.h"
#include "MyVector.h"
#include <cstddef>

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class VectorStack : public StackImplementation, public MyVector
{
public:
	VectorStack();

	VectorStack(const VectorStack& copyVector);

	~VectorStack() override {};

	// добавление в хвост
	void push(const ValueType& value) override;

	// удаление с хвоста
	void pop() override;

	// посмотреть элемент в хвосте
	const ValueType& top() const override;

	// проверка на пустоту
	bool isEmpty() const override;

	// размер 
	size_t size() const override;
};

