#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 获取所有网卡的名字
std::vector<std::string> get_names() {
    std::vector<std::string> names;
    int sock, if_count;
    struct ifconf ifc;
    struct ifreq ifr[10];
    memset(&ifc, 0, sizeof(ifconf));
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    ifc.ifc_len = 10 * sizeof(ifreq);
    ifc.ifc_buf = (char*)ifr;
    ioctl(sock, SIOCGIFCONF, (char*)&ifc);
    if_count = ifc.ifc_len / (sizeof(ifreq));
    for (int i = 0; i < if_count; i++) {
        if (ioctl(sock, SIOCGIFHWADDR, &ifr[i]) == 0) {
            std::string name = ifr[i].ifr_name;
            names.push_back(name);
        }
    }
    return names;
}

//获取ip地址
bool get_local_ip(const std::string name, std::string& ip) {
    const char* ifname = name.c_str();
    int inet_sock;
    struct ifreq ifr;
    inet_sock = socket(AF_INET, SOCK_DGRAM, 0);
    memset(ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    memcpy(ifr.ifr_name, ifname, strlen(ifname));
    if (0 != ioctl(inet_sock, SIOCGIFADDR, &ifr)) {
        perror("ioctl error");
        return false;
    }
    ip = inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr);
    return true;
}

//获取mac地址
bool get_mac(const std::string name, std::string& mac) {
    const char* eth_name = name.c_str();
    int sockfd;
    struct ifreq ifr;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket error");
        return false;
    }
    strcpy(ifr.ifr_name, eth_name);
    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == 0) {  // SIOCGIFHWADDR 获取hardware address
        mac = ifr.ifr_hwaddr.sa_data;
    }
    return true;
}

void run() {
    //物理网卡名
    auto names = get_names();
    std::unordered_map<std::string, std::string> name_ip_map;

    for (const auto& name : names) {
        // mac
        std::string mac;
        get_mac(name, mac);

        // ip
        std::string ip;
        get_local_ip(name, ip);

        // save
        name_ip_map[name] = ip;
        std::cout << name << " " << ip << std::endl;
    }
}

int main(void) {
    run();
    return 0;
}