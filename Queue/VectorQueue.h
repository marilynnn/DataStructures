#pragma once
#include "QueueImplementation.h"
#include "Vector.h"
#include <cstddef>

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию

class VectorQueue : public QueueImplementation, public Vector
{
public:
	VectorQueue();

	VectorQueue(const VectorQueue& copyQueue);

	~VectorQueue() override {};

	// добавление в хвост
	void enqueue(const ValueType& value) override;

	// удаление с хвоста
	void dequeue() override;

	// посмотреть элемент в хвосте
	const ValueType& front() const override;

	// проверка на пустоту
	bool isEmpty() const override;

	// размер 
	size_t size() const override;
};
