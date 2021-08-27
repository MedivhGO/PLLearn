#include <iostream>

using namespace std;

template <typename T> class Pal;
class C {
    friend class Pal<C>;
    template <typename T> friend class Pal2;    
};
template <typename T> class C2 {
    friend class Pal<T>;
    template<typename X> friend class Pal2;
    
    friend class Pal3;
        
};

template <typename T> using twin = pair<T,T>;
twin<string> authors;

int main(int argc, char *argv[]) {
    
}