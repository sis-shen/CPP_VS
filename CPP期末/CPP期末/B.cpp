//// 请把下面的所有代码复制到你的开发环境中，按照上面的要求填充所需要的代码，然后提交代码进行测试。（注意：main函数中的内容是不能修改的，违者0分）
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//// 下面的main函数代码【不能修改；一旦改动，本题0分】。
//
//class Vehicle
//{
//public:
//    Vehicle() {}
//    virtual ~Vehicle() {};
//    virtual void setMaxSpeed(int speed)
//    {
//        maxSpeed = speed;
//    }
//
//    virtual int getMaxSpeed()
//    {
//        return maxSpeed;
//    }
//
//    virtual std::string getType() = 0;
//protected:
//    int maxSpeed;
//};
//
//class Car:public Vehicle
//{
//public:
//    Car() {};
//    virtual string getType()
//    {
//        return "Car";
//    }
//};
//
//
//class Airplane :public Vehicle
//{
//public:
//    Airplane() {};
//    virtual string getType()
//    {
//        return "Airplane";
//    }
//};
//
//class Bike :public Vehicle
//{
//public:
//    Bike() {};
//    virtual string getType()
//    {
//        return "Bike";
//    }
//};
//
//
//// 测试函数
//int main() {
//    // 创建一个指针数组来存储 Vehicle 的指针
//    Vehicle* vehicles[3];
//    int car_speed, bike_speed, airplane_speed;
//
//    // 创建交通工具对象
//    vehicles[0] = new Car();
//    vehicles[1] = new Bike();
//    vehicles[2] = new Airplane();
//
//    cin >> car_speed >> bike_speed >> airplane_speed;
//    vehicles[0]->setMaxSpeed(car_speed);
//    vehicles[1]->setMaxSpeed(bike_speed);
//    vehicles[2]->setMaxSpeed(airplane_speed);
//    for (int j = 0; j < 3; j++) {
//        cout << "Vehicle Type: " << vehicles[j]->getType()
//            << ", Max Speed: " << vehicles[j]->getMaxSpeed() << " km/h" << endl;
//    }
//
//
//    // 释放分配的内存
//    for (int i = 0; i < 3; ++i) {
//        delete vehicles[i];
//    }
//
//    return 0;
//}