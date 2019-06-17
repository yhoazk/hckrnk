#include <bits/stdc++.h>
#include <net/if.h>
#include <linux/if_link.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
//)#include <sys/socket.h>
#include <netdb.h>


void fill(){
    struct ifaddrs *ifaddr, *ifa;
    int family, n;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
    }

    /* Walk through linked list, maintaining head pointer so we
       can free list later */

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;
        /* Display interface name and family (including symbolic
            form of the latter for the common families) */
        #if 0
        printf("%-8s %s (%d)\n",
                ifa->ifa_name,
                (family == AF_PACKET) ? "AF_PACKET" :
                (family == AF_INET) ? "AF_INET" :
                (family == AF_INET6) ? "AF_INET6" : "???",
                family);
        #endif

        /* For an AF_INET* interface address, display the address */

        if (family == AF_PACKET && ifa->ifa_data != NULL) {
            struct rtnl_link_stats *stats =   static_cast<rtnl_link_stats*>(ifa->ifa_data);
            printf( "\t\ttx_packets = %10u; rx_packets = %10u\n"
                    "\t\ttx_bytes   = %10u; rx_bytes   = %10u\n",
                    stats->tx_packets, stats->rx_packets,
                    stats->tx_bytes, stats->rx_bytes);
        }
    }

    freeifaddrs(ifaddr);

}

using namespace std;
int32_t calculate(uint32_t n, uint32_t d){
    double dd, nn;
    return static_cast<int32_t>(n/d);
}


int main(int argc, char const *argv[])
{
   struct if_nameindex *if_nidxs, *intf;
    if ( (if_nidxs = if_nameindex()) != NULL ){
        for (intf = if_nidxs; (intf->if_index != 0) || (intf->if_name != NULL); intf++)
        {
            std::cout <<  intf->if_name << "\n";
        }
        std::cout << std::endl;
        if_freenameindex(if_nidxs);
    }

    fill();
    int32_t n;
    int32_t d;

    //cin >> n >> d;
    cout << calculate(n,d);
    return 0;
}
