#include "custom_vector.hpp"
#include <algorithm>
#include <iostream>

//================================MyVector members================================

// Constructor
template<typename T>
MyVector<T>::MyVector() : size_(0), max_size_(1){
    // by default allocate max_size_ of 1;
    data_ = new T[max_size_];
}

// Overloaded Constructor
template<typename T>
MyVector<T>::MyVector(size_t allocate_size) : size_(0), max_size_(allocate_size){
    data_ = new T[max_size_];
}

// Destructor
template<typename T>
MyVector<T>::~MyVector(){
    delete[] data_;
    data_ = nullptr;
}


// element access
template<typename T>
inline T const& MyVector<T>::at(size_t index) const{
    if (index > size_) {throw 404;} //random throw error right now, should throw std::out_of_range instead.

    return data_[index];
}

template<typename T>
inline T const& MyVector<T>::operator[](size_t index) const{
    return at(index);
}

template<typename T>
inline T const& MyVector<T>::front() const{
    return at(0);
}

template<typename T>
inline T const& MyVector<T>::back() const{
    return at(size_-1);
}

template<typename T>
inline T const* MyVector<T>::data() const{
    return data_;
}

// capacity stuffs
template<typename T>
inline bool MyVector<T>::empty() const{
    return size == 0;
}

template<typename T>
inline size_t MyVector<T>::size() const{
    return size_;
}

template<typename T>
inline size_t MyVector<T>::max_size() const{
    return max_size_;
}

template<typename T>
inline size_t MyVector<T>::capacity() const{
    return max_size_ - size_;
}

// modifiers
template<typename T>
inline void MyVector<T>::push_back(T target){
    data_[size_] = target;
    size_++;

    grow();
}

// iterator accessors
template<typename T>
inline MyVectorIterator<T> MyVector<T>::begin(){
    return MyVectorIterator<T>(data_);
}

template<typename T>
inline MyVectorIterator<T> MyVector<T>::end(){
    return MyVectorIterator<T>(data_+size_);
}

template<typename T>
inline MyVectorIterator<T> MyVector<T>::iter(size_t index){
    return MyVectorIterator<T>(data_+index);
}

// private methods
template<typename T>
inline bool MyVector<T>::grow(){
    // Currently grow when size_ = max_size_*0.5 (one of the other way is max_size_ - 1)
    // am thinking this can decrease the chance of accessing illegal memory.
    
    if (size_ < (max_size_*0.5)){ return false; }

    // create new data buffer;
    max_size_ *= 2;
    T* temp_buffer = new T[max_size_];

    // copy to new data buffer;
    // using std::copy() instead of memcopy() because more std::copy() is more likely to get optimized by compiler.
    std::copy(data_, data_+size_, temp_buffer);

    // am skeptical about this, will change to smart pointer later.
    delete[] data_;
    data_ = temp_buffer;
    
    return true;
}

//================================MyVectorIterator members================================
template<typename T>
MyVectorIterator<T>::MyVectorIterator(T* dataPtr) : dataPtr_(dataPtr){

}

template<typename T>
MyVectorIterator<T>& MyVectorIterator<T>::operator++() {
    ++dataPtr_;
    return *this;
}

template<typename T>
MyVectorIterator<T> MyVectorIterator<T>::MyVectorIterator::operator++(int) {
    auto temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
MyVectorIterator<T>& MyVectorIterator<T>::operator--() {
    --dataPtr_;
    return *this;
}

template<typename T>
MyVectorIterator<T> MyVectorIterator<T>::MyVectorIterator::operator--(int) {
    auto temp = *this;
    --(*this);
    return temp;
}
template<typename T>
bool MyVectorIterator<T>::operator==(MyVectorIterator const& rhs) const{
    return *dataPtr_ == *rhs;
}

template<typename T>
bool MyVectorIterator<T>::operator!=(MyVectorIterator const& rhs) const{
    return !(*this == rhs);
}

template<typename T>
T& MyVectorIterator<T>::operator*() const {
    return *dataPtr_;
}




