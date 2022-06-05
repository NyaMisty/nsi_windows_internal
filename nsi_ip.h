typedef struct _NL_INTERFACE_KEY {  
    IF_LUID Luid;  
} NL_INTERFACE_KEY, *PNL_INTERFACE_KEY;  

typedef enum _NL_TYPE_OF_INTERFACE {  
    InterfaceAllowAll = 0,  
    InterfaceDisallowUnicast,  
    InterfaceDisallowMulticast,  
    InterfaceDisallowAll,  
    InterfaceUnchanged = -1  
} NL_TYPE_OF_INTERFACE;  
  
typedef enum _NL_DOMAIN_NETWORK_LOCATION {  
    DomainNetworkLocationRemote = 0,   // connect to a domain network remotely via DA i.e. outside corp network.  
    DomainNetworkCategoryLink = 1,     // connect to a domain network directly i.e. inside corp network.  
    DomainNetworkUnchanged = -1  
} NL_DOMAIN_NETWORK_LOCATION;  
  
typedef enum _NL_DOMAIN_TYPE {  
    DomainTypeNonDomainNetwork = 0,    // connected to non-domain network.  
    DomainTypeDomainNetwork = 1,       // connected to a network that has active directory.  
    DomainTypeDomainAuthenticated = 2, // connected to AD network and machine is authenticated against it.  
    DomainTypeUnchanged = -1  
} NL_DOMAIN_TYPE;  
  
typedef enum _NL_INTERFACE_ECN_CAPABILITY {  
    NlInterfaceEcnUnchanged = -1,  
    NlInterfaceEcnDisabled = 0,  
    NlInterfaceEcnUseEct1 = 1,  
    NlInterfaceEcnUseEct0 = 2,  
    NlInterfaceEcnAppDecide = 3  
} NL_INTERFACE_ECN_CAPABILITY, *PNL_INTERFACE_ECN_CAPABILITY;  
  
typedef enum _NL_INTERNET_CONNECTIVITY_STATUS {  
    NlNoInternetConnectivity,  
    NlNoInternetDnsResolutionSucceeded,  
    NlInternetConnectivityDetected,  
    NlInternetConnectivityUnknown = -1  
} NL_INTERNET_CONNECTIVITY_STATUS, *PNL_INTERNET_CONNECTIVITY_STATUS;  

typedef union _IP_ADDRESS_STORAGE {  
    IN_ADDR Ipv4;  
    IN6_ADDR Ipv6;  
    UCHAR Buffer[sizeof(IN6_ADDR)];  
} IP_ADDRESS_STORAGE, *PIP_ADDRESS_STORAGE;  

typedef struct _NL_INTERFACE_RW {  
    BOOLEAN AdvertisingEnabled;  
    BOOLEAN ForwardingEnabled;  
    BOOLEAN MulticastForwardingEnabled;  
    BOOLEAN WeakHostSend;  
    BOOLEAN WeakHostReceive;  
    BOOLEAN UseNeighborUnreachabilityDetection;  
    BOOLEAN UseAutomaticMetric;
    BOOLEAN UseZeroBroadcastAddress;  
    BOOLEAN UseBroadcastForRouterDiscovery;  
    BOOLEAN DhcpRouterDiscoveryEnabled;  
    BOOLEAN ManagedAddressConfigurationSupported;  
    BOOLEAN OtherStatefulConfigurationSupported;  
    BOOLEAN AdvertiseDefaultRoute;  
    NL_NETWORK_CATEGORY NetworkCategory;  
    NL_ROUTER_DISCOVERY_BEHAVIOR RouterDiscoveryBehavior;  
    NL_TYPE_OF_INTERFACE TypeOfInterface;  
    ULONG Metric;  
    ULONG BaseReachableTime;    // Base for random ReachableTime (in ms).  
    ULONG RetransmitTime;       // Neighbor Solicitation timeout (in ms).  
    ULONG PathMtuDiscoveryTimeout; // Path MTU discovery timeout (in ms).  
    ULONG DadTransmits;         // DupAddrDetectTransmits in RFC 2462.  
    NL_LINK_LOCAL_ADDRESS_BEHAVIOR LinkLocalAddressBehavior;  
    ULONG LinkLocalAddressTimeout; // In ms.  
    ULONG ZoneIndices[ScopeLevelCount]; // Zone part of a SCOPE_ID.  
    ULONG NlMtu;  
    ULONG SitePrefixLength;  
    ULONG MulticastForwardingHopLimit;  
    ULONG CurrentHopLimit; 
    IP_ADDRESS_STORAGE LinkLocalAddress;  
    BOOLEAN DisableDefaultRoutes;  
    ULONG AdvertisedRouterLifetime;  
    BOOLEAN SendUnsolicitedNeighborAdvertisementOnDad;  
    BOOLEAN LimitedLinkConnectivity;  
    BOOLEAN ForceARPNDPattern;  
    BOOLEAN EnableDirectMACPattern;  
    BOOLEAN EnableWol;  
    BOOLEAN ForceTunneling;  
    NL_DOMAIN_NETWORK_LOCATION DomainNetworkLocation;  
    ULONGLONG RandomizedEpoch;  
    NL_INTERFACE_ECN_CAPABILITY EcnCapability;  
    NL_DOMAIN_TYPE DomainType;  
    GUID NetworkSignature;  
    NL_INTERNET_CONNECTIVITY_STATUS InternetConnectivityDetected;  
    BOOLEAN ProxyDetected;  
    ULONG DadRetransmitTime;  
    BOOLEAN PrefixSharing;  
    BOOLEAN DisableUnconstrainedRouteLookup;  
    ULONG NetworkContext;  
    BOOLEAN ResetAutoconfigurationOnOperStatusDown;   
    BOOLEAN ClampMssEnabled;  
  
} NL_INTERFACE_RW, *PNL_INTERFACE_RW;  

__inline  
VOID  
NlInitializeInterfaceRw(  
    IN OUT PNL_INTERFACE_RW Rw  
    )  
{  
    //  
    // Initialize all fields to values that indicate "no change".  
    //  
    memset(Rw, 0xff, sizeof(*Rw));  
    Rw->BaseReachableTime = 0;  
    Rw->RetransmitTime = 0;  
    Rw->PathMtuDiscoveryTimeout = 0;  
    Rw->NlMtu = 0;  
    Rw->DadRetransmitTime = 0;  
}  

typedef enum {
  NlBestRouteObject = 0x0,
  NlCompartmentForwardingObject = 0x1,
  NlCompartmentObject = 0x2,                    // #define NSI_IP_COMPARTMENT_TABLE           2
  NlControlProtocolObject = 0x3,                // #define NSI_IP_ICMPSTATS_TABLE             3
  NlEchoRequestObject = 0x4,
  NlEchoSequenceRequestObject = 0x5,
  NlGlobalObject = 0x6,                         // #define NSI_IP_IPSTATS_TABLE               6
  NlInterfaceObject = 0x7,
  NlLocalAnycastAddressObject = 0x8,
  NlLocalMulticastAddressObject = 0x9,
  NlLocalUnicastAddressObject = 0xA,            // #define NSI_IP_UNICAST_TABLE              10
  NlNeighborObject = 0xB,                       // #define NSI_IP_NEIGHBOUR_TABLE            11
  NlPathObject = 0xC,
  NlPotentialRouterObject = 0xD,
  NlPrefixPolicyObject = 0xE,
  NlProxyNeighborObject = 0xF,
  NlRouteObject = 0x10,                         // #define NSI_IP_FORWARD_TABLE              16
  NlSitePrefixObject = 0x11,
  NlSubInterfaceObject = 0x12,
  NlWakeUpPatternObject = 0x13,
  NlResolveNeighborObject = 0x14,
  NlSortAddressesObject = 0x15,
  NlMfeObject = 0x16,
  NlMfeNotifyObject = 0x17,
  NlInterfaceHopObject = 0x18,
  NlInterfaceUnprivilegedObject = 0x19,
  NlTunnelPhysicalInterfaceObject = 0x1A,
  NlLocalityObject = 0x1B,
  NlLocalityDataObject = 0x1C,
  NlLocalityPrivateObject = 0x1D,
  NlLocalBottleneckObject = 0x1E,
  NlTimerObject = 0x1F,
  NlDisconnectInterface = 0x20,
  NlMaximumObject = 0x21,
} NL_OBJECT_TYPE, *PNL_OBJECT_TYPE;  

/* Undocumented NSI IP tables */



struct nsi_ip_cmpt_rw
{
    UINT not_forwarding;
    UINT unk;
    UINT default_ttl;
    UINT unk2;
};

struct nsi_ip_cmpt_dynamic
{
    UINT num_ifs;
    UINT num_routes;
    UINT unk;
    UINT num_addrs;
};

struct nsi_ip_icmpstats_dynamic
{
    UINT in_msgs;
    UINT in_errors;
    UINT in_type_counts[256];
    UINT out_msgs;
    UINT out_errors;
    UINT out_type_counts[256];
};

struct nsi_ip_ipstats_dynamic
{
    UINT unk[4];
    ULONGLONG in_recv;
    ULONGLONG in_octets;
    ULONGLONG fwd_dgrams;
    ULONGLONG in_delivers;
    ULONGLONG out_reqs;
    ULONGLONG unk2;
    ULONGLONG unk3;
    ULONGLONG out_octets;
    ULONGLONG unk4[6];
    ULONGLONG in_hdr_errs;
    UINT in_addr_errs;
    UINT in_unk_protos;
    UINT unk5;
    UINT reasm_reqds;
    UINT reasm_oks;
    UINT reasm_fails;
    UINT in_discards;
    UINT out_no_routes;
    UINT out_discards;
    UINT routing_discards;
    UINT frag_oks;
    UINT frag_fails;
    UINT frag_creates;
    UINT unk6[7];
};

struct nsi_ip_ipstats_static
{
    UINT reasm_timeout;
};

struct nsi_ipv4_unicast_key
{
    NET_LUID luid;
    IN_ADDR addr;
    UINT pad;
};

struct nsi_ipv6_unicast_key
{
    NET_LUID luid;
    IN6_ADDR addr;
};

struct nsi_ip_unicast_rw
{
    UINT preferred_lifetime;
    UINT valid_lifetime;
    UINT prefix_origin;
    UINT suffix_origin;
    UINT on_link_prefix;
    UINT unk[2];
};

struct nsi_ip_unicast_dynamic
{
    UINT scope_id;
    UINT dad_state;
};

struct nsi_ip_unicast_static
{
    ULONG64 creation_time;
};

struct nsi_ipv4_neighbour_key
{
    NET_LUID luid;
    NET_LUID luid2;
    IN_ADDR addr;
    UINT pad;
};

struct nsi_ipv6_neighbour_key
{
    NET_LUID luid;
    NET_LUID luid2;
    IN6_ADDR addr;
};

struct nsi_ip_neighbour_rw
{
    BYTE phys_addr[IF_MAX_PHYS_ADDRESS_LENGTH];
};

struct nsi_ip_neighbour_dynamic
{
    UINT state;
    UINT time;
    struct
    {
        BOOLEAN is_router;
        BOOLEAN is_unreachable;
    } flags;
    USHORT phys_addr_len;
    UINT unk;
};

struct nsi_ipv4_forward_key
{
    UINT unk;
    IN_ADDR prefix;
    BYTE prefix_len;
    BYTE unk2[3];
    UINT unk3[3];
    NET_LUID luid;
    NET_LUID luid2;
    IN_ADDR next_hop;
    UINT pad;
};

struct nsi_ipv6_forward_key
{
    UINT unk;
    IN6_ADDR prefix;
    BYTE prefix_len;
    BYTE unk2[3];
    UINT unk3[3];
    UINT pad;
    NET_LUID luid;
    NET_LUID luid2;
    IN6_ADDR next_hop;
};

struct nsi_ip_forward_rw
{
    UINT site_prefix_len;
    UINT valid_lifetime;
    UINT preferred_lifetime;
    UINT metric;
    UINT protocol;
    BYTE loopback;
    BYTE autoconf;
    BYTE publish;
    BYTE immortal;
    BYTE unk[4];
    UINT unk2;
};

struct nsi_ipv4_forward_dynamic
{
    UINT age;
    UINT unk[3];
    IN_ADDR addr2; /* often a repeat of prefix */
};

struct nsi_ipv6_forward_dynamic
{
    UINT age;
    UINT unk[3];
    IN6_ADDR addr2; /* often a repeat of prefix */
};

struct nsi_ip_forward_static
{
    UINT origin;
    UINT if_index;
};
