#include <iostream>
#include <memory>
using namespace std;
class Parquet
{
public:
    struct Type
    {
        enum type{
            a1 = 0,
            a2 = 1,
            a3,
            a4,
            a5
        };
    };
};


class Parquet2
{
public:
    struct Type
    {
         enum type{
            a1 = 0,
            a2 = 1,
            a3,
            a4,
            a5
        };
    };
};

int main()
{
    std::shared_ptr<Parquet> sp(make_shared<Parquet>());
    std::cout << Parquet::Type::a2 << std::endl;

    std::cout << Parquet2::Type::a4 << std::endl;
}