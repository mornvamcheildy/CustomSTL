#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class VectorIterator {
public:
    using PointerType = T*;
    using ReferenceType = T&;

    VectorIterator(PointerType ptr) : m_ptr(ptr) {}

    VectorIterator& operator++() { m_ptr++; return *this; }
    VectorIterator operator++(int) { VectorIterator temp = *this; m_ptr++; return temp; }
    VectorIterator& operator--() { m_ptr--; return *this; }
    VectorIterator operator--(int) { VectorIterator temp = *this; m_ptr--; return temp; }

    ReferenceType operator[](int index) { return *(m_ptr + index); }
    PointerType operator->() { return m_ptr; }
    ReferenceType operator*() { return *m_ptr; }

    bool operator==(const VectorIterator& other) const { return m_ptr == other.m_ptr; }
    bool operator!=(const VectorIterator& other) const { return m_ptr != other.m_ptr; }

private:
    PointerType m_ptr;
};

#endif
