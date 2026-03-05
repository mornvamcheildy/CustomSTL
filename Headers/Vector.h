#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <algorithm>
#include "Iterator.h"

template <typename T>
class Vector {
public:
    using Iterator = VectorIterator<T>;

    // Constructor
    Vector() { Reallocate(2); }

    // Destructor
    ~Vector() { delete[] m_data; }

    // Copy Constructor
    Vector(const Vector<T>& other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; i++) m_data[i] = other.m_data[i];
    }

    // Copy Assignment
    Vector& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++) m_data[i] = other.m_data[i];
        }
        return *this;
    }

    // Move Constructor
    Vector(Vector<T>&& other) noexcept {
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    // Move Assignment
    Vector& operator=(Vector<T>&& other) noexcept {
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            other.m_data = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    void PushBack(const T& value) {
        if (m_size >= m_capacity) Reallocate(m_capacity + m_capacity / 2);
        m_data[m_size++] = value;
    }

    void PopBack() { if (m_size > 0) m_size--; }

    size_t Size() const { return m_size; }
    T& operator[](size_t index) { return m_data[index]; }

    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data + m_size); }

private:
    void Reallocate(size_t newCapacity) {
        T* newBlock = new T[newCapacity];
        for (size_t i = 0; i < m_size; i++) newBlock[i] = std::move(m_data[i]);
        delete[] m_data;
        m_data = newBlock;
        m_capacity = newCapacity;
    }

    T* m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;
};

#endif
