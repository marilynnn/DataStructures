#pragma once

#include <cstddef>

// ��������� ��������� capacity
enum class ResizeStrategy {
    Additive,
    Multiplicative
};

enum class SortedStrategy {
    Ascending,
    Descending
};


// ��� �������� � �������
// ����� ����� ������� �� ������
using ValueType = double;

class MyVector
{
public:

/*	class Iterator
	{
	public:
		Iterator():ptr(nullptr) {};
		Iterator(ValueType* pointer) : ptr(pointer) {};
		ValueType* begin() { return Iterator(_data); }
		ValueType* end() {return Iterator(_data + _size); }
	private:
		ValueType* ptr;
	};*/

    MyVector(size_t size = 0, ResizeStrategy strategy = ResizeStrategy::Multiplicative, float coef = 1.5f);
    MyVector(size_t size, ValueType value, ResizeStrategy strategy = ResizeStrategy::Multiplicative, float coef = 1.5f);

    MyVector(const MyVector& copy);
    MyVector& operator=(const MyVector& copy);

    ~MyVector();

    // ��� ��������� � ����������� ����������� � �������� ��� �����������

    size_t capacity() const;
    size_t size() const;
    float loadFactor();

    // ������ � ��������,
    // ������ �������� �� O(1)
    ValueType& operator[](const size_t i) const;

    // �������� � �����,
    // ������ �������� �� amort(O(1))
    void pushBack(const ValueType& value);
    // ��������,
    // ������ �������� �� O(n)
    void insert(const size_t i, const ValueType& value);	// ������ ��� ������ ��������
    void insert(const size_t i, const MyVector& value);		// ������ ��� �������

    // ������� � �����,
    // ������ �������� �� amort(O(1))
    void popBack();
    // �������
    // ������ �������� �� O(n)
    void erase(const size_t i);
    void erase(const size_t i, const size_t len);			// ������� len ��������� ������� � i

    // ����� �������,
    // ������ �������� �� O(n)
    // ���� isBegin == true, ����� ������ ������� ��������, ������� value, ����� ����������
    // ���� �������� �������� ���, ������� -1
    long long int find(const ValueType& value, bool isBegin = true) const;

    // ��������������� ������ (������������� ������ capacity)
    void reserve(const size_t capacity);

    // �������� ������
    // ���� ����� ������ ������ ��������, �� ����� �������� ���������� ���������� ����������
    // ���� ������ - �������� ������
    void resize(const size_t size, const ValueType value = 0.0);

    //��������� capacity � ����������� �� ���������
    void resize();

    // ������� �������, ��� ��������� capacity
    void clear();

    ValueType* begin() { return _data; }
    ValueType* end() { return (_data + _size); }

    //���������� ������ sortedSquares
    static MyVector sortedSquares(const MyVector& vec, SortedStrategy strategy);

private:
    ValueType* _data;
    size_t _size;
    size_t _capacity;
    ResizeStrategy _strategy;
    float _coef;
};