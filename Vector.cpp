//
// Created by Caden Atack on 3/18/25.
//

#include "Vector.h"
#include <stdexcept>
#include <iostream>

Vector::Vector()
    : data_ptr(new int[CHUNK]), capacity(CHUNK), n_elems(0) {}

Vector::Vector(const Vector& v)
: data_ptr(new int[v.capacity]), capacity(v.capacity), n_elems(v.n_elems) {
    for (size_t i = 0; i < n_elems; ++i) {
        data_ptr[i] = v.data_ptr[i];
    }
}

Vector& Vector::operator=(const Vector& v) {
    if (this != &v) {  // Check for self-assignment.
        delete [] data_ptr; // Free the current memory.
        capacity = v.capacity;
        n_elems = v.n_elems;
        data_ptr = new int[capacity]; // Allocate new memory.
        for (size_t i = 0; i < n_elems; ++i) {
            data_ptr[i] = v.data_ptr[i]; // Copy each element.
        }
    }
    return *this;
}

Vector::~Vector() {
    delete [] data_ptr;
}

int Vector::front() const {
    if (empty())
        throw std::range_error("front() called on empty vector");
    return data_ptr[0];
}

int Vector::back() const {
    if (empty())
        throw std::range_error("back() called on empty vector");
    return data_ptr[n_elems - 1];
}

int Vector::at(size_t pos) const {
    if (pos >= n_elems)
        throw std::range_error("at() index out of range");
    return data_ptr[pos];
}

size_t Vector::size() const {
    return n_elems;
}

bool Vector::empty() const {
    return n_elems == 0;
}

int& Vector::operator[](size_t pos) {
    // No bounds checking here
    return data_ptr[pos];
}

void Vector::push_back(int item) {
    if (n_elems == capacity)
        grow();  // Increase capacity if full.
    data_ptr[n_elems++] = item;  // Insert the new item and increment the element count.
}

void Vector::pop_back() {
    if (empty())
        throw std::range_error("pop_back() called on empty vector");
    --n_elems;  // Simply decrement n_elems to remove the last element.
}

void Vector::erase(size_t pos) {
    if (pos >= n_elems)
        throw std::range_error("erase() index out of range");
    // Shift elements to the left to fill the gap.
    for (size_t i = pos; i < n_elems - 1; ++i) {
        data_ptr[i] = data_ptr[i+1];
    }
    --n_elems;
}

void Vector::insert(size_t pos, int item) {
    if (pos > n_elems) // pos must be <= n_elems (insertion at the end is allowed)
        throw std::range_error("insert() index out of range");
    if (n_elems == capacity)
        grow();  // Grow the array if no room.
    // Shift elements right from the end to create space.
    for (size_t i = n_elems; i > pos; --i) {
        data_ptr[i] = data_ptr[i-1];
    }
    data_ptr[pos] = item; // Insert the new element.
    ++n_elems;
}

void Vector::clear() {
    n_elems = 0;
}

int* Vector::begin() {
    return (n_elems > 0) ? data_ptr : nullptr;
}

int* Vector::end() {
    return (n_elems > 0) ? (data_ptr + n_elems) : nullptr;
}

bool Vector::operator==(const Vector& v) const {
    if (n_elems != v.n_elems)
        return false;
    for (size_t i = 0; i < n_elems; ++i) {
        if (data_ptr[i] != v.data_ptr[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& v) const {
    return !(*this == v);
}

void Vector::grow() {
    std::cout << "grow" << std::endl; // Debug trace to indicate growth.
    size_t new_capacity = static_cast<size_t>(capacity * 1.6);
    if (new_capacity == capacity) {
        // Ensure that capacity actually increases, even if the multiplication rounds down.
        new_capacity++;
    }
    int* new_data = new int[new_capacity]; // Allocate a new array with the new capacity.
    // Copy current elements into the new array.
    for (size_t i = 0; i < n_elems; ++i) {
        new_data[i] = data_ptr[i];
    }
    delete [] data_ptr;  // Free the old array.
    data_ptr = new_data; // Update the data pointer to the new array.
    capacity = new_capacity;  // Update the capacity.
}

///void Vector::grow() {
///    std::cout << "grow" << std::endl; // Debug trace to indicate growth.
///    size_t new_capacity = static_cast<size_t>(capacity * 1.6);
///    if (new_capacity == capacity) {
///        // Ensure that capacity actually increases, even if the multiplication rounds down.
///        new_capacity++;
///    }
///    int* new_data = new int[new_capacity]; // Allocate a new array with the new capacity.
///    // Copy current elements into the new array.
///    for (size_t i = 0; i < n_elems; ++i) {
///        new_data[i] = data_ptr[i];
///    }
///    delete [] data_ptr;  // Free the old array.
///    data_ptr = new_data; // Update the data pointer to the new array.
///    capacity = new_capacity;  // Update the capacity.
///}
