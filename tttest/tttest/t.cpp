#include <iostream>
#include <sstream>
#include <iomanip>

std::string intToFixedHexString(int num, int width) {
    std::ostringstream oss;
    oss << std::hex << std::uppercase << std::setw(width) << std::setfill('0') << num;
    return oss.str();
}

int main() {
    int num = 255;
    int width = 8; // 固定长度为8
    std::string hexString = intToFixedHexString(num, width);
    std::cout << "Fixed length hexadecimal string: " << hexString << std::endl;
    return 0;
}
