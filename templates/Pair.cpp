#include <iostream>

template <typename T1, typename T2>

class Pair{
    private:
        T1 a;
        T2 b;
    public:
        Pair(T1 a, T2 b): a(a), b(b){}
        void print() const;
};

    template <typename T1, typename T2>
    void Pair<T1, T2>::print() const{
        std::cout << "(" << a << ", " << b << ")" << '\n';
    }

    void print_test(){
        Pair<int, double> p1(67, 6.7);
        Pair<int, double> p2(-67, -6.7);
        Pair<int, std::string> p3(67, "sixseven");
        Pair<char, double> p4('s', 6.7);
        Pair<char, std::string> p5('s', "sixseven");
        std::cout << "All tests passed!" << '\n';
    }

    int main(){
        print_test();
        return 0;
    }