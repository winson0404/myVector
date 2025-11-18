#include <iostream>
#include <stdexcept> // For std::runtime_error
#include <string>
#include "custom_vector.cpp"

void Assert(bool condition, std::string msg_if_fail){
 if (!condition){throw std::runtime_error(msg_if_fail);}
}

// testcase: Iterator - full iteration
void MyVector_FullIteration(){
    MyVector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(3);
    myVector.push_back(5);
    myVector.push_back(7);
    myVector.push_back(9);
    
    for (auto const& item : myVector){
        std::cout << "item: " << item << std::endl;
    }
    
}

// testcase: Iterator - Increment
void MyVector_Increment(){
    MyVector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(3);
    myVector.push_back(5);

    auto iter = myVector.begin();

    // verify if current item of iter is 1
    Assert(*iter == 1, "ERROR: Iterator dereference incorrectly!");

    // ++ rhs
    iter++;
    Assert(*iter == 3, "ERROR: Iterator incrementing incorrectly!");

    // ++ lhs
    auto const temp = ++iter;
    Assert(*temp == 5, "ERROR: Iterator incrementing (++i) incorrectly!");

}

// testcase: Iterator - Decrement
void MyVector_Decrement(){
    MyVector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(3);
    myVector.push_back(5);

    auto iter = myVector.begin();

    // verify if current item of iter is 1
    Assert(*iter == 1, "ERROR: Iterator dereference incorrectly!");

    // ++ rhs
    iter++;
    Assert(*iter == 3, "ERROR: Iterator incrementing incorrectly!");

    // ++ lhs
    auto const temp = ++iter;
    Assert(*temp == 5, "ERROR: Iterator incrementing (++i) incorrectly!");

    // -- rhs
    iter--;
    Assert(*iter == 3, "ERROR: Iterator decrementing incorrectly!");

    // -- lhs
    auto const temp2 = --iter;
    Assert(*temp2 == 1, "ERROR: Iterator decrementing (--i) incorrectly!");

}

// testcase: MyVector - access by index
void MyVector_AccessElement(){
    // create vector with
    MyVector<int> myVector;
    myVector.push_back(2);
    myVector.push_back(4);
    myVector.push_back(6);

    Assert(myVector[0] == 2, "ERROR: MyVector index 0 not 2!");
    Assert(myVector.at(1) == 4, "ERROR: MyVector index 0 not 4!");
    Assert(myVector[2] == 6, "ERROR: MyVector index 0 not 6!");

    Assert(myVector.front() == 2, "ERROR: MyVector front not 2!");
    Assert(myVector.back() == 6, "ERROR: MyVector back not 6!");
}

// testcase: MyVector - push_back() and grow()
void MyVector_PushBackAndGrow(){
    // create vector with
    MyVector<int> myVector;
    myVector.push_back(1);

    // after pushing one, max size should be 2, size should be 1.
    Assert(myVector.size() == 1, "ERROR: MyVector size not equal 1!");
    Assert(myVector.max_size() == 2, "ERROR: MyVector size not equal 1!");

    myVector.push_back(2);
    Assert(myVector.size() == 2, "ERROR: MyVector size not equal 2!");
    Assert(myVector.max_size() == 4, "ERROR: MyVector size not equal 4!");

    myVector.push_back(3);
    Assert(myVector.size() == 3, "ERROR: MyVector size not equal 3!");
    Assert(myVector.max_size() == 8, "ERROR: MyVector size not equal 8!");
}

// testcase: MyVector - default constructor
void MyVector_DefaultConstructor(){
    MyVector<int> myVector;

    auto dataPtr = myVector.data();

    Assert(dataPtr, "ERROR: MyVector empty data nullptr!");
    Assert(myVector.max_size() == 1, "ERROR: MyVector empty max_size not 1!");
    Assert(!myVector.size(), "ERROR: MyVector empty size not 0!");
}

// testcase: MyVector - overloading constructor
void MyVector_CustomConstructor(){
    MyVector<int> myVector(5);

    auto dataPtr = myVector.data();
    
    Assert(dataPtr, "ERROR: MyVector data is nullptr!");
    Assert(myVector.max_size() == 5, "ERROR: MyVector max_size not 5!");
    Assert(!myVector.size(), "ERROR: MyVector empty size not 0!");
}


int main(){
    // IteratorTest1();
    MyVector_DefaultConstructor();
    MyVector_CustomConstructor();
    MyVector_PushBackAndGrow();
    MyVector_AccessElement();

    MyVector_Increment();
    MyVector_Decrement();
    MyVector_FullIteration();


    std::cout << "\n\nUnit test completed!\n";
}