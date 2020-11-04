
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ofstream out("/Users/lijingqi/abc.txt",ios::out);
    if(!out) {
        cerr << "error" <<endl;
    }
    else {
    cout << "dasdsd"<<endl;
    out << "aaa" <<endl;

    out.close();
    }

}