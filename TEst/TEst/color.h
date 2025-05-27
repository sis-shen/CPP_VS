#pragma once
#ifndef COLORCONFIG_H
#define COLORCONFIG_H

#include <iostream>
#include <string>
using namespace std;
class ColorConfig
{
private:
    //实现单例模式
    ColorConfig() =default;
    ColorConfig(const ColorConfig&) = delete;
    ColorConfig operator=(const ColorConfig&) = delete;
    static ColorConfig* _ins;
public:
    static ColorConfig* getInstance()
    {
        if (_ins == nullptr)
        {
            _ins = new ColorConfig;
        }
        return _ins;
    }

    static void print()
    {
        cout << "print";
    }

    ~ColorConfig()
    {
        if (_ins)delete _ins;
    }

    const string main_color = "#FB7299";
    const string light_grey = "#F6F7F8";
private:
};

ColorConfig* ColorConfig::_ins = nullptr;
#endif // COLORCONFIG_H



//#pragma once
//#ifndef COLORCONFIG_H
//#define COLORCONFIG_H
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class ColorConfig
//{
//private:
//    // 私有构造函数，防止外部创建实例
//    ColorConfig() {}
//
//    // 删除拷贝构造函数和赋值操作符，保证单例
//    ColorConfig(const ColorConfig&) = delete;
//    ColorConfig& operator=(const ColorConfig&) = delete;
//
//    static ColorConfig* _ins;  // 静态成员变量，存储单例对象
//
//public:
//    // 获取单例实例
//    static ColorConfig* getInstance()
//    {
//        if (_ins == nullptr)
//        {
//            _ins = new ColorConfig();  // 创建单例对象
//        }
//        return _ins;
//    }
//
//    // 静态方法用于打印
//    static void print()
//    {
//        cout << "print" << endl;
//    }
//
//    // 析构函数
//    ~ColorConfig()
//    {
//        // 删除 _ins 对象时，通常会在程序结束时由操作系统进行清理
//    }
//
//    // 配置颜色常量
//    const string main_color = "#FB7299";
//    const string light_grey = "#F6F7F8";
//
//};
//
//// 在类外部初始化静态成员变量
//ColorConfig* ColorConfig::_ins = nullptr;
//#endif // COLORCONFIG_H