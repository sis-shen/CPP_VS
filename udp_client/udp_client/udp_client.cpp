#include <iostream>
#include <WinSock2.h>//必须比下面的Windows.h先包含，否则报错
#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <string>

#pragma warning(disable:4996)

#pragma comment(lib,"ws2_32.lib")

std::string serverip = "47.99.48.121";
uint16_t serverport = 25565;

int main()
{
    WSADATA wsd;
    WSAStartup(MAKEWORD(2, 2), &wsd);


    struct sockaddr_in server;
    memset(&server,0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0)
    {
        std::cout << "socket err\n" << std::endl;
    }

    

    char buffer[1024] = { 0 };
    while (true)
    {
        std::string msg;
        std::cout << "Please Enter@";
        std::getline(std::cin, msg);
        //send msg
        sendto(sockfd, msg.c_str(), msg.size(), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in temp;
        int len = sizeof(temp);
        int s = recvfrom(sockfd, buffer, 1023, 0, (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
        }
    }

    closesocket(sockfd);
    WSACleanup();
	return 0;
}