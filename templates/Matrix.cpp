#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T, int N, int M>
class Matrix{
private:
    T arr[N][M];
public:
    void set(int row, int col, const T& value);
    T get(int row, int col) const;
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const;
};

template <typename T, int N, int M>
void Matrix<T, N, M>::set(int row, int col, const T& value){
    if(row >= 0 && row < N && col >= 0 && col < M){
        arr[row][col] = value;
    } else{
        std::cout << "za predelami matrici:(" << '\n' << '\n';
    }
}

template <typename T, int N, int M>
T Matrix<T, N, M>::get(int row, int col) const{
    if(row >= 0 && row < N && col >= 0 && col < M){
        return arr[row][col];
    } else{
        std::cout << "za predelami matrici:(" << '\n' << '\n';
        return {};
    }
}

template <typename T, int N, int M>
Matrix<T, N, M> Matrix<T, N, M>::operator+(const Matrix<T, N, M>& other) const{
    Matrix<T, N, M> result;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            result.arr[i][j] = this->arr[i][j] + other.arr[i][j];
        }
    }
    return result;
}

void testMatrix(){
    //normal test cases
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5);
    m2.set(0, 1, -2);
    m2.set(1, 0, 7);
    m2.set(1, 1, -5);

    Matrix<int, 2, 2> sum = m1 + m2;
    assert(sum.get(0, 0) == 6);
    assert(sum.get(0, 1) == 0);
    assert(sum.get(1, 0) == 10);
    assert(sum.get(1, 1) == -1);    

    std::cout << "int tests passed" << '\n';
    
    Matrix<std::string, 2, 2> s1;
    s1.set(0, 0, "six");
    s1.set(0, 1, "seven");
    s1.set(1, 0, "sixseven");
    s1.set(1, 1, "sevensix");
    
    Matrix<std::string, 2, 2> s2;
    s2.set(0, 0, "one");
    s2.set(0, 1, "two");
    s2.set(1, 0, "three");
    s2.set(1, 1, "four");   

    Matrix<std::string, 2, 2> sum2 = s1 + s2;
    assert(sum2.get(0, 0) == "sixone");
    assert(sum2.get(0, 1) == "seventwo");
    assert(sum2.get(1, 0) == "sixseventhree");
    assert(sum2.get(1, 1) == "sevensixfour");

    std::cout << "string tests passed!" << std::endl;

    Matrix<double, 2, 2> d1;
    d1.set(0, 0, 6.0);
    d1.set(0, 1, 5.5);
    d1.set(1, 0, 4.8);
    d1.set(1, 1, 3.4);

    Matrix<double, 2, 2> d2;
    d2.set(0, 0, 0.7);
    d2.set(0, 1, 1.3);
    d2.set(1, 0, 2.1);
    d2.set(1, 1, 3.6);

    Matrix<double, 2, 2> sum3 = d1 + d2;
    assert(std::abs(sum3.get(0, 0)) - 6.7 < 1e-9);
    assert(std::abs(sum3.get(0, 1)) - 6.8 < 1e-9);
    assert(std::abs(sum3.get(1, 0)) - 6.9 < 1e-9);
    assert(std::abs(sum3.get(1, 1)) - 7.0 < 1e-9);
    
    std::cout << "double tests passed" << '\n';

    Matrix<char, 2, 2> c;
    c.set(0, 0, 'a');
    c.set(0, 1, 'b');
    c.set(1, 0, 'c');
    c.set(1, 1, 'd');
    c.set(-1, 0, 'e'); // za predelami matrici:(
    c.set(0, 2, 'f');  // za predelami matrici:(
    c.set(2, -1, 'g'); // za predelami matrici:(
    c.get(-1, 0);      // za predelami matrici:(
    c.get(0, 2);       // za predelami matrici:(
    c.get(2, -1);      // za predelami matrici:(

    std::cout << "za prdeli ne vixodit:)" << '\n';
}

int main(){
    testMatrix();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
