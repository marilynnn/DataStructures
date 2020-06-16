#pragma once

#include "StackImplementation.h"
#include "LinkedList.h" 
#include <cstddef>
// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListStack : public StackImplementation, public LinkedList
{
public:

	ListStack();

	ListStack(const ListStack& copyList);

	~ListStack() override {};

	void push(const ValueType& value) override;// добавление в хвост

	void pop() override;// удаление с хвоста

	const ValueType& top() const override;// посмотреть элемент в хвосте

	bool isEmpty() const override;// проверка на пустоту

	std::size_t size() const override;// размер

};

