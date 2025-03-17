//
// Created by Caden Atack on 3/17/25.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
using std::size_t;
class Vector {
    enum {CHUNK = 10};
    int* data_ptr;
    // Pointer to the heap array
    size_t capacity;
    // Size of the current array allocation (total number of ints)
    size_t n_elems;
    // Number of int spaces currently in use, starting from pos 0
    void grow();
public:
    // Object Mgt.
    Vector();
    Vector(const Vector& v);
    // Copy constructor
    Vector& operator=(const Vector& v);
    // Copy assignment operator
    ~Vector();
    // Accessors
    int front() const;
    // Return the int in position 0, if any
    int back() const;
    // Return last element (position n_elems-1)
    int at(size_t pos) const;
    // Return element in position "pos" (0-based)
    size_t size() const;
    // Return n_elems
    bool empty() const;
    // Return n_elems == 0
    // Mutators
    int& operator[](size_t pos);
    // Same as at but no bounds checking
    void push_back(int item);
    // Append a new element at the end
    void pop_back();
    // --n_elems (nothing else to do)
    void erase(size_t pos);
    // Remove item in position pos by shuffling left
    void insert(size_t pos, int item);
    // Shuffle items right to make room for new element
    void clear();
    // n_elems = 0 (keep the current capacity)
    // Iterators
    int* begin();
    // Return a pointer to 1st element, or nullptr if n_elems == 0
    int* end();
    // Return a pointer to 1 past last element, or nullptr if n_elems == 0
    // Comparators
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;
};

#endif //VECTOR_H
