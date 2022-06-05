/* Undocumented NSI TCP tables */
#define NSI_TCP_STATS_TABLE                0
#define NSI_TCP_ALL_TABLE                  3
#define NSI_TCP_ESTAB_TABLE                4
#define NSI_TCP_LISTEN_TABLE               5

struct nsi_tcp_stats_dynamic
{
    UINT active_opens;
    UINT passive_opens;
    UINT attempt_fails;
    UINT est_rsts;
    UINT cur_est;
    UINT pad; /* ? */
    ULONGLONG in_segs;
    ULONGLONG out_segs;
    UINT retrans_segs;
    UINT out_rsts;
    UINT in_errs;
    UINT num_conns;
    UINT unk[12];
};

struct nsi_tcp_stats_static
{
    UINT rto_algo;
    UINT rto_min;
    UINT rto_max;
    UINT max_conns;
    UINT unk;
};

struct nsi_tcp_conn_key
{
    SOCKADDR_INET local;
    SOCKADDR_INET remote;
};

struct nsi_tcp_conn_dynamic
{
    UINT state;
    UINT unk[3];
};

struct nsi_tcp_conn_static
{
    UINT unk[3];
    UINT pid;
    ULONGLONG create_time;
    ULONGLONG mod_info;
};

