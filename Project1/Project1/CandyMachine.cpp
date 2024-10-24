#define _CRT_SECURE_NO_WARNINGS 1

#include "CandyMachine.h"

bool CandyMachine::AddCandy() {
    string name;
    double price;
    int count;

    cout << "请输入糖果名称: ";
    cin >> name;
    cout << "请输入糖果价格: ";
    cin >> price;
    cout << "请输入糖果数量: ";
    cin >> count;

    if (_AddCandy(name, price, count)) {
        cout << "成功加入糖果！\n";
        return true;
    }
    else {
        cout << "添加糖果失败，可能容量已满或者输入无效。\n";
        return false;
    }
}

bool CandyMachine::_AddCandy(const string& name, double price, int num) {
    if (_amount + price * num > _capacity || num <= 0 || price <= 0) {
        return false; // 容量不够或输入无效  
    }

    // 添加糖果到列表和索引  
    _CandiesList.emplace_back(name, price, num);
    _index[name] = _CandiesList.size() - 1; // 记录索引  

    _amount += price * num; // 更新总价值  
    return true;
}

bool CandyMachine::SellCandy() {
    string name;
    int num;

    cout << "请输入要售卖的糖果名称: ";
    cin >> name;
    cout << "请输入售卖数量: ";
    cin >> num;

    if (_SellCandy(name, num)) {
        cout << "售卖成功！\n";
        return true;
    }
    else {
        cout << "售卖失败，可能糖果无效或数量不足。\n";
        return false;
    }
}

bool CandyMachine::_SellCandy(const string& name, int num) {
    if (_index.find(name) == _index.end() || num <= 0) {
        return false; // 糖果不存在或输入无效  
    }

    int index = _index[name];
    Candy& candy = _CandiesList[index];

    // 检查糖果的数量  
    if (candy._count < num) { // 这里需要一个方法来获取糖果数量，可能需要提供一个 access 方法  
        return false;
    }

    // 处理售卖  
    candy._count -= num; // 减少数量  
    _sale += candy._price * num; // 更新销售额  
    return true;
}

void CandyMachine::InfoCandy() {
    string name;
    cout << "请输入糖果名称以查看信息: ";
    cin >> name;
    _InfoCandy(name);
}

void CandyMachine::_InfoCandy(const string& name) {
    if (_index.find(name) != _index.end()) {
        int index = _index[name];
        Candy& candy = _CandiesList[index];

        // 假设在 Candy 类中增加了获取信息的方法  
        cout << "名称: " << candy._name << ", 价格: " << candy._price << ", 数量: " << candy._count << endl;
    }
    else {
        cout << "糖果不存在！\n";
    }
}

void CandyMachine::InfoCandies() {
    sort(_CandiesList.begin(), _CandiesList.end(), [](const Candy& a, const Candy& b) {
        return a._price < b._price; // 按价格升序  
        });
    _InfoCandies(_CandiesList);
}

void CandyMachine::_InfoCandies(const vector<Candy>& goodslist) {
    cout << fixed << setprecision(2); // 保留两位小数  
    cout << "糖果信息:\n";
    for (const auto& candy : goodslist) {
        cout << "名称: " << candy._name << ", 价格: " << candy._price << ", 数量: " << candy._count << endl;
    }
}

void CandyMachine::Run() {
    int choice;
    while (true) {
        PrintMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            AddCandy();
            break;
        case 2:
            SellCandy();
            break;
        case 3:
            InfoCandy();
            break;
        case 4:
            InfoCandies();
            break;
        case 0:
            cout << "退出程序。\n";
            return;
        default:
            cout << "无效的选择，请重新输入。\n";
        }
    }
}

void CandyMachine::PrintMenu() {
    cout << "\n欢迎使用自动糖果售卖机！\n";
    cout << "1. 增加糖果\n";
    cout << "2. 售卖糖果\n";
    cout << "3. 显示糖果信息\n";
    cout << "4. 显示所有糖果信息\n";
    cout << "0. 退出\n";
    cout << "请输入您的选择: ";
}
