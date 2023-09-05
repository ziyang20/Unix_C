//基于udp的客户端
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>

int main(void){
    printf("客户端:创建套接字\n");
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd == -1){
        perror("socket");
        return -1;
    }
    printf("客户端:准备服务器地址结构\n");
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(8989);
    ser.sin_addr.s_addr = inet_addr("192.168.19.128");
    printf("客户端:业务处理\n");
    for(;;){
        //通过键盘获取小写的串
        char buf[64] = {};
        fgets(buf,sizeof(buf),stdin);
        // ! 退出
        if(strcmp(buf,"!\n") == 0){
            break;
        }
        //发送给服务器
        if(sendto(sockfd,buf,strlen(buf),0,
            (struct sockaddr*)&ser,sizeof(ser)) == -1){
            perror("sendto");
            return -1;
        }
        //接收回传的串
        if(recv(sockfd,buf,sizeof(buf)-1,0) == -1){
            perror("recv");
            return -1;
        }
        //显示
        printf("%s",buf);
    }
    printf("客户端:关闭套接字\n");
    close(sockfd);
    return 0;
}






