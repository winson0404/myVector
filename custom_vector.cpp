#include "custom_vector.hpp"

//================================MyVector members================================

// Constructor
template<typename T>
MyVector<T>::MyVector() : size_(0), max_size_(0), data_(nullptr){
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
    if (index > size_) {throw 404}; //random throw error right now, should throw std::out_of_range instead.

    return data_[index];
}

template<typename T>
inline T const* MyVector<T>::data() const{
    return data_;
}

// capacity stuffs
template<typename T>
inline size_t MyVector<T>::size() const{
    return size_;
}

template<typename T>
inline size_t MyVector<T>::max_size() const{
    return max_size_;
}

// modifiers
template<typename T>
inline void MyVector<T>::push_back(T target){

}

// modifiers
template<typename T>
inline bool MyVector<T>::grow(){

}

