#include <iostream>
#include <memory>
class Widget
{
    public:
        int GetA() {
            return a;
        }
        void SetA(int a) {
            this->a = a;
        }
    private:
        int a;
};

std::unique_ptr<const Widget> loadWidget(WidgetID id);
std::shared_ptr<const Widget> fastLoadWidget(WidgetID id)
{
    static std::unodered_map<
            WidgetID,
            std::weak_ptr<const Widget>> cache;
    auto objPtr = cache[id].lock(); //objPtr is std::shared_ptr
                                    //to cached object (or null if object's not in cache)
                                    //if not in cache
                                    //load it 
                                    //cache it
    if (!objPtr) {
        objPtr = loadWidget(id);
        cache[id] = objPtr;
    }
    return objPtr;
}

using namespace std;
int main(int argc, char *argv[]) {
    std::cout << "hello world!";
}