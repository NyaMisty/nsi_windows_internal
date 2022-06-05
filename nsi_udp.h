/* Undocumented NSI UDP tables */
#define NSI_UDP_STATS_TABLE                0
#define NSI_UDP_ENDPOINT_TABLE             1

struct nsi_udp_stats_dynamic
{
    ULONGLONG in_dgrams;
    UINT no_ports;
    UINT in_errs;
    ULONGLONG out_dgrams;
    UINT num_addrs;
    UINT unk[5];
};

struct nsi_udp_endpoint_key
{
    SOCKADDR_INET local;
};

struct nsi_udp_endpoint_static
{
    UINT pid;
    UINT unk;
    ULONGLONG create_time;
    UINT flags;
    UINT unk2;
    ULONGLONG mod_info;
};
