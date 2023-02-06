//
// Created by Gao on 2022/12/26.
//

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <linux/if_tun.h>
#include <stdlib.h>
#include <stdio.h>



int tun_alloc(int flag)
{
    struct ifreq ifr;
    int fd,err;
    char *clonedev = "/dev/net/tun";

    if ((fd = open(clonedev,O_RDWR)) < 0){
        return fd;
    }

    memset(&ifr,0, sizeof(ifr));
    ifr.ifr_ifru.ifru_flags = flag;

    if ((err = ioctl(fd, TUNSETIFF, (void *) &ifr) ) < 0)
    {
        close(fd);
        return err;
    }
    printf("Open tun/tap device: %s for reading...\n",ifr.ifr_name);
    return fd;
}

int main()
{
    int tun_fd, nread;
    char buffer[1500];
    /*Flag: IFF_TUN     - TUN device (no Ethernet headers)
     *      IFF_TAP     - TAP device
     *      IFF_NO_PI   - Do not privode packet information
     */
    tun_fd = tun_alloc(IFF_TUN | IFF_NO_PI);

    if (tun_fd <0 ){
        perror("Allocating Interface");
        exit(1);
    }

    while (1){
        nread = read(tun_fd,buffer, sizeof(buffer));
        if (nread < 0){
            perror("Reading from interface");
            close(tun_fd);
            exit(1);
        }

        printf("Read %d bytes from tun/tap device\n",nread);
    }
    return 0;

}
