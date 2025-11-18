#include <cstddef>

// reference: https://en.cppreference.com/w/cpp/container/vector.html

template<typename T>
class MyVector{
public:
    MyVector();
    MyVector(size_t allocate_size);
    ~MyVector();

    //  Rule of 5 stuffs cause I modified destructor.
    MyVector(const MyVector& other) = default; // Copy constructor
    MyVector& operator=(const MyVector& other) = default; // Copy Assignment constructor
    MyVector(MyVector&& other) noexcept = default; // Move constructor
    MyVector& operator=(MyVector&& other) noexcept = default;  // Move Assigment constructor
    
    // element access
    T const& at(size_t index) const;
    T const& operator[](size_t index) const;
    T const& front() const;
    T const& back() const;
    T const* data() const; //directly access to underlying container;

    // capacity stuffs
    bool empty() const; // return if element is empty
    size_t size() const; // return the current size of elements
    size_t max_size() const; // return the current max size of elements
    size_t capacity() const; // number of element that can still be stored in currently allocated storage.
    bool reserve(size_t new_cap); // reserve 
    bool shrink_to_fit(); // reduce memory by freeing unused memory;

    // modifiers
    void clear(); // clear all the contents;
    void push_back(T target); // add after last element;
    T pop_back();

    class MyVectorIterator{
    public:
        MyVectorIterator(size_t index);
        MyVectorIterator& operator++();
        MyVectorIterator operator++(int);
        MyVectorIterator& operator--();
        MyVectorIterator operator--(int);
        bool operator==(MyVectorIterator const& rhs) const;
        bool operator!=(MyVectorIterator const& rhs) const;
        T operator*() const;
    private:
        size_t index = 0;
    };

    MyVectorIterator begin();
    MyVectorIterator end();
private:
    // check for current size, and grow if exceed half of the allocated memory;
    bool grow();

    size_t size_;
    size_t max_size_;
    T* data_;
};