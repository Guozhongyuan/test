#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

void GetCommdResult(const std::string &cmd, char* res) {
    FILE *fp = nullptr;

    if ((fp = popen(cmd.c_str(), "r")) == nullptr) {
    }

    while (fgets(res, 32, fp)) {
        pclose(fp);
        break;
    }
    
}

int main(int argc, char *argv[]) {
    std::string cmd("ifconfig wlp0s20f3 | grep inet");
    char res[32] = "";
    GetCommdResult(cmd, res);

    int idx_start = 0, idx_end = 0;
    for (int i = 0; i < 32; ++i) {
        if (res[i] == ' ') {
            continue;
        }
        if (idx_start == 0) {
            idx_start = i;
        }
    }

    std::string tmp(res);
    std::string addr(tmp, 13, )

    std::cout << res << std::endl;
    return 0;
}
// TODO: 每个机器人只能发布到docker的口，订阅别人需要开多个线程
// 如果输出是 eth0: ... 说明失败了，无法获取
// 如果
