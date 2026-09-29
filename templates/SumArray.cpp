#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T>
T sumArray(const T* arr, int size){
    T sum = T();
    int i = 0;
    while(i < size){
        sum += arr[i];
        i++;
    }
    return sum;
}
 void testForInt(){
    int arr1[] = {10, 20, 30, 3, 4};
    assert(sumArray(arr1, 5) == 67);

    int arr2[] = {67};
    assert(sumArray(arr2, 1) == 67);

    int arr3[] = {};
    assert(sumArray(arr3, 0) == 0);

    int arr4[] = {-10, -20, -30, -4, -3};
    assert(sumArray(arr4, 5) == -67);

    int arr5[] = {13, -6, -7};
    assert(sumArray(arr5, 3) == 0);
 }

void testForDouble(){
    double arr1[] = {1.1, 2.2, 3.3, 0.1, 0.0};
    assert(std::abs(sumArray(arr1, 5) - 6.7) < 1e-9);

    double arr2[] = {6.7};
    assert(std::abs(sumArray(arr2, 1) - 6.7) < 1e-9);

    double arr3[] = {};
    assert(sumArray(arr3, 0) == 0);

    double arr4[] = {-10.5, -20.5, -30.5, -4.5, -3.5};
    assert(std::abs(sumArray(arr4, 5) - (-69.5)) < 1e-9);

    double arr5[] = {13.7, -6.7, -7.0};
    assert(std::abs(sumArray(arr5, 3) - 0.0) < 1e-9);
}

void testForString(){
    std::string arr1[] = {"Hello", " ", "World", "!", ""};
    assert(sumArray(arr1, 5) == "Hello World!");

    std::string arr2[] = {"Baylus dzez"};
    assert(sumArray(arr2, 1) == "Baylus dzez");

    std::string arr3[] = {};
    assert(sumArray(arr3, 0) == "");

    std::string arr4[] = {"вечер", " ", "в", " ", "хату"};
    assert(sumArray(arr4, 5) == "вечер в хату");
}

int main(){
    testForInt();
    testForDouble();
    testForString();
    std::cout << "All tests passed!" << '\n';
    return 0;
}