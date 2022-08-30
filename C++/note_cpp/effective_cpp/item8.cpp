//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//class DestructorDemo
//{
//public:
//    DestructorDemo();
//    void Erase();
//    ~DestructorDemo();
//
//private:
//    int *a;
//};
//DestructorDemo::DestructorDemo() : a(0){
//    a = (int*)malloc(sizeof(int));
//}
//void DestructorDemo::Erase()
//{
//    free(a);
//    a = 0;
//}
//DestructorDemo::~DestructorDemo()
//{
//    if (a) {
//      cout << "Throwing an exception" << endl;
//      throw  10;
//    }
//}
///*
// * 在两个异常存在的情况下，程序若不是结束执行就是导致不明确的行为
// *
// * 只要析构函数吐出异常，即使并非使用容器或者arrays，程序也可能过早结束或出现不明确的行为。
// *
// * */
//class DBConn
//{
//public:
//    ~DBConn()
//    {
//        db.close(); //此处可能会抛出异常
//    }
//private:
//    DBConnection db;
//};
//class DBConn1
//{
//public:
//    ~DBConn1()
//    {
//        try {
//            db.close(); //此处可能会抛出异常
//        } catch (...) {
//            //制作运转记录，记下对close的调用失败；
//            std::abort(); // 结束程序
//        }
//
//    }
//private:
//    DBConnection db;
//};
//class DBConn2
//{
//public:
//    ~DBConn1()
//    {
//        try {
//            db.close(); //此处可能会抛出异常
//        } catch (...) {
//            //制作运转记录，记下对close的调用失败；
//            std::abort(); // 结束程序
//        }
//
//    }
//private:
//    DBConnection db;
//};
//
//class DBConn2
//{
//public:
//    void close()
//    {
//        db.close();
//        closed = true;
//    }
//    ~DBConn1()
//    {
//        try {
//            db.close(); //此处可能会抛出异常
//        } catch (...) {
//            //制作运转记录，记下对close的调用失败；
//           //吞下这个异常， 因为这样可能比草率结束更好。
//
//           //两者都无法对"导致close抛出异常"的情况做出反应。引入一个新的接口close()
//        }
//
//    }
//private:
//    DBConnection db;
//    bool closed;
//};
//class DBConn3
//{
//public:
//    void close() //让用户自己调用close，出现问题可在用户的代码区中进行处理。
//    {
//        db.close();
//        closed = true;
//    }
//    ~DBConn3()
//    {
//       if (!closed) {
//           try{
//               db.close();
//           } catch (...) {
//               //制作运转记录，记下对close的调用失败
//           }
//       }
//    }
//private:
//    DBConnection db;
//    bool closed;
//};
//
//int main1()
//{
//    DestructorDemo dd;
//}