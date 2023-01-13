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
#include <vector>
using namespace std;

//获取文件目录下所有的文件名
int scanFiles(vector<string>& fileList, string inputDirectory) {
    inputDirectory = inputDirectory.append("/");

    DIR* p_dir;
    const char* str = inputDirectory.c_str();

    p_dir = opendir(str);
    if (p_dir == NULL) {
        printf("can't open: %s\n", inputDirectory.c_str());
    }

    struct dirent* p_dirent;

    while (p_dirent = readdir(p_dir)) {
        string tmpFileName = p_dirent->d_name;
        if (tmpFileName == "." || tmpFileName == "..") {
            continue;
        } else {
            fileList.push_back(tmpFileName);
        }
    }
    closedir(p_dir);
    return fileList.size();
}

// 获取物理网卡的名字
char* get_real_name(char* real_name) {
    // 获取所有虚拟网卡mac名
    vector<string> vMac;
    string path = "/sys/devices/virtual/net";
    int num = scanFiles(vMac, path);

    // 获取所有网卡的信息
    int sock, if_count, i;
    struct ifconf ifc;
    struct ifreq ifr[10];
    unsigned char mac[6];
    memset(&ifc, 0, sizeof(struct ifconf));

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    ifc.ifc_len = 10 * sizeof(struct ifreq);
    ifc.ifc_buf = (char*)ifr;
    ioctl(sock, SIOCGIFCONF, (char*)&ifc);

    if_count = ifc.ifc_len / (sizeof(struct ifreq));

    // 过滤出realMac
    for (i = 0; i < if_count; i++) {
        if (ioctl(sock, SIOCGIFHWADDR, &ifr[i]) == 0) {
            int label = 0;
            for (int j = 0; j < num; j++) {
                if (vMac[j].compare(string(ifr[i].ifr_name)) == 0) {
                    label = 1;  // 有相等label=1,是虚拟
                }
            }
            if (label == 0) {
                real_name = ifr[i].ifr_name;
                memcpy(real_name, ifr[i].ifr_name, strlen(ifr[i].ifr_name));
                memcpy(mac, ifr[i].ifr_hwaddr.sa_data, 6);
                // printf("eth: %s, mac: %02x:%02x:%02x:%02x:%02x:%02x\n", ifr[i].ifr_name, mac[0], mac[1], mac[2],
                // mac[3], mac[4], mac[5]);
                break;
            }
        }
    }
    return real_name;
}

//获取ip地址
int get_local_ip(char* ifname, char* ip) {
    char* temp = NULL;
    int inet_sock;
    struct ifreq ifr;

    inet_sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(ifr.ifr_name, 0, sizeof(ifr.ifr_name));
    memcpy(ifr.ifr_name, ifname, strlen(ifname));
    // printf("get ip: %s\n", ifname);

    if (0 != ioctl(inet_sock, SIOCGIFADDR, &ifr)) {
        perror("ioctl error");
        return -1;
    }

    temp = inet_ntoa(((struct sockaddr_in*)&(ifr.ifr_addr))->sin_addr);
    memcpy(ip, temp, strlen(temp));

    return 0;
}

//获取mac地址
int get_mac(char* eth_name, char* mac_a) {
    int sockfd;
    struct ifreq ifr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket error");
        return -1;
    }
    strcpy(ifr.ifr_name, eth_name);
    // printf("get mac: %s\n", eth_name);

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == 0) {  // SIOCGIFHWADDR 获取hardware address
        memcpy(mac_a, ifr.ifr_hwaddr.sa_data, 6);
    }

    return 0;
}

void run(char* ip, char* this_mac) {
    //物理网卡名
    char* real_macname = get_real_name(real_macname);
    printf("real macname: %s\n", real_macname);

    // mac
    get_mac(real_macname, this_mac);
    // printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n", this_mac[0]&0xff, this_mac[1]&0xff, this_mac[2]&0xff,
    // this_mac[3]&0xff, this_mac[4]&0xff, this_mac[5]&0xff);

    // ip
    get_local_ip(real_macname, ip);
}

int main(void) {
    char ip[32] = {0};
    char mac[6] = {0};
    run(ip, mac);

    printf("ip: %s\n", ip);
    printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n", mac[0] & 0xff, mac[1] & 0xff, mac[2] & 0xff, mac[3] & 0xff,
           mac[4] & 0xff, mac[5] & 0xff);

    return 0;
}