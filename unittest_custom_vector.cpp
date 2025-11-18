#include <iostream>
#include <stdexcept> // For std::runtime_error
#include "custom_vector.cpp"

// testcase: Iterator-basic operations
// void IteratorTest1(){
//     MyVector<int> myVector;
//     myVector.push_back(1);
//     myVector.push_back(3);
//     myVector.push_back(5);

//     auto iter = myVector.begin();

//     // verify if current item of iter is 1
//     if (*iter != 1){ throw std::runtime_error("ERROR: Iterator dereference incorrectly!"); }

//     // ++ rhs
//     iter++;
//     if (*iter != 3){ throw std::runtime_error("ERROR: Iterator incrementing incorrectly!"); }

//     // ++ lhs
//     auto const temp = ++iter;
//     if (temp != 5){ throw std::runtime_error("ERROR: Iterator incrementing (++i) incorrectly!"); }

//     // -- rhs
//     iter--;
//     if (*iter != 3){ throw std::runtime_error("ERROR: Iterator decrementing incorrectly!"); }

//     // -- lhs
//     auto const temp2 = ++iter;
//     if (temp != 1){ throw std::runtime_error("ERROR: Iterator decrementing (++i) incorrectly!"); }

// }

// testcase 1: normal iteration
// void Vector_Case1(){
//     // create vector with
//     MyVector<int> myVector;
//     myVector.push_back(1);
//     myVector.push_back(2);
//     myVector.push_back(3);
//     myVector.push_back(4);
//     myVector.push_back(5);

//     for (auto const& item : myVector){
//         std::cout << item <<std::endl;
//     } 
// }

// test if instantialize with default constructor
void MyVector_DefaultConstructor(){
    MyVector<int> myVector;

    auto dataPtr = myVector.data();

    if (dataPtr) {throw std::runtime_error("ERROR: MyVector empty data not nullptr!");}
    if (myVector.max_size()){throw std::runtime_error("ERROR: MyVector empty max_size not 0!");}
    if (myVector.size()){throw std::runtime_error("ERROR: MyVector empty size not 0!");}
}

// test if instantialize with default constructor
void MyVector_CustomConstructor(){
    MyVector<int> myVector(5);

    auto dataPtr = myVector.data();

    if (!dataPtr) {throw std::runtime_error("ERROR: MyVector data is nullptr!");}
    if (myVector.max_size() != 5){throw std::runtime_error("ERROR: MyVector max_size not 5!");}
    if (myVector.size()){throw std::runtime_error("ERROR: MyVector empty size not 0!");}
}


int main(){
    // IteratorTest1();
    MyVector_DefaultConstructor();
    MyVector_CustomConstructor();


    std::cout << "Unit test completed!\n\n";
}