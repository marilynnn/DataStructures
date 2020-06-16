#pragma once

#include "QueueImplementation.h"
#include "SinglyLinkedList.h" 
#include <cstddef>
// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListQueue : public QueueImplementation, public SinglyLinkedList
{
public:

	ListQueue();

	ListQueue(const ListQueue& copyList);

	~ListQueue() override {};

	void enqueue(const ValueType& value) override;// добавление в очередь

	void dequeue() override;// удаление из очереди

	const ValueType& front() const override;// посмотреть элемент в "голове"

	bool isEmpty() const override;// проверка на пустоту

	std::size_t size() const override;// размер

};
