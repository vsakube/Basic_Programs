#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <concepts>

using namespace std;

auto f(auto p){

return p;

};

struct st{
 int value=2;
 friend std::ostream& operator<<(std::ostream& os, const st& obj);
};

std::ostream& operator<<(std::ostream& os, const st& obj) {
    os << "Value: " << obj.value;
    return os;
}

auto descendingComp = [](auto a, auto b) {
    return a > b;
};

template <typename T>
concept CONCEPT = std::is_integral<T>;



template<class A, class B>
auto tDescendingComp = [](A a, B b) {
    return a > b;
};

int main(){

cout << f(3) << endl;

st s; s.value = 100;

cout << f(s) << endl;

cout << "templatized output " << tDescendingComp<float, float>(2.5, 3.5) << endl;
cout << "without template  output " << descendingComp(4.5, 3.5) << endl;


}

