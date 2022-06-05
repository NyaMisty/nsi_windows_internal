typedef enum _NDIS_NSI_OBJECT_INDEX
{
  NdisNsiObjectInterfaceInformation = 0x0,              // #define NSI_NDIS_IFINFO_TABLE              0
  NdisNsiObjectInterfaceEnum = 0x1,
  NdisNsiObjectInterfaceLookUp = 0x2,                   // #define NSI_NDIS_INDEX_LUID_TABLE          2
  NdisNsiObjectIfRcvAddress = 0x3,
  NdisNsiObjectStackIfEntry = 0x4,
  NdisNsiObjectInvertedIfStackEntry = 0x5,
  NdisNsiObjectNetwork = 0x6,
  NdisNsiObjectCompartment = 0x7,
  NdisNsiObjectThread = 0x8,
  NdisNsiObjectSession = 0x9,
  NdisNsiObjectInterfacePersist = 0xA,
  NdisNsiObjectCompartmentLookup = 0xB,
  NdisNsiObjectInterfaceInformationRaw = 0xC,
  NdisNsiObjectInterfaceEnumRaw = 0xD,
  NdisNsiObjectStackIfEnum = 0xE,
  NdisNsiObjectInterfaceIsolationInfo = 0xF,
  NdisNsiObjectJob = 0x10,
  NdisNsiObjectMaximum = 0x11,
} NDIS_NSI_OBJECT_INDEX, *PNDIS_NSI_OBJECT_INDEX;


typedef struct _NDIS_NSI_INTERFACE_INFORMATION_RW
{
    // rw fields
    GUID                        NetworkGuid;
    NET_IF_ADMIN_STATUS         ifAdminStatus;
    NDIS_IF_COUNTED_STRING      ifAlias;
    NDIS_IF_PHYSICAL_ADDRESS    ifPhysAddress;
    NDIS_IF_COUNTED_STRING      ifL2NetworkInfo;
}NDIS_NSI_INTERFACE_INFORMATION_RW, *PNDIS_NSI_INTERFACE_INFORMATION_RW;

#define NDIS_SIZEOF_NSI_INTERFACE_INFORMATION_RW_REVISION_1      \
        RTL_SIZEOF_THROUGH_FIELD(NDIS_NSI_INTERFACE_INFORMATION_RW, ifPhysAddress)

typedef NDIS_INTERFACE_INFORMATION NDIS_NSI_INTERFACE_INFORMATION_ROD, *PNDIS_NSI_INTERFACE_INFORMATION_ROD;

/* Undocumented NSI NDIS tables */

struct nsi_ndis_ifinfo_rw
{
    GUID network_guid;
    DWORD admin_status;
    IF_COUNTED_STRING alias; /* .Length in bytes not including '\0' */
    IF_PHYSICAL_ADDRESS phys_addr;
    USHORT pad;
    IF_COUNTED_STRING name2;
    DWORD unk;
};

struct nsi_ndis_ifinfo_dynamic
{
    DWORD oper_status;
    struct
    {
        DWORD unk : 1;
        DWORD not_media_conn : 1;
        DWORD unk2 : 30;
    } flags;
    DWORD media_conn_state;
    DWORD unk;
    DWORD mtu;
    ULONG64 xmit_speed;
    ULONG64 rcv_speed;
    ULONG64 in_errors;
    ULONG64 in_discards;
    ULONG64 out_errors;
    ULONG64 out_discards;
    ULONG64 unk2;
    ULONG64 in_octets;
    ULONG64 in_ucast_pkts;
    ULONG64 in_mcast_pkts;
    ULONG64 in_bcast_pkts;
    ULONG64 out_octets;
    ULONG64 out_ucast_pkts;
    ULONG64 out_mcast_pkts;
    ULONG64 out_bcast_pkts;
    ULONG64 unk3[2];
    ULONG64 in_ucast_octs;
    ULONG64 in_mcast_octs;
    ULONG64 in_bcast_octs;
    ULONG64 out_ucast_octs;
    ULONG64 out_mcast_octs;
    ULONG64 out_bcast_octs;
    ULONG64 unk4;
};

struct nsi_ndis_ifinfo_static
{
    DWORD if_index;
    IF_COUNTED_STRING descr;
    DWORD type;
    DWORD access_type;
    DWORD unk;
    DWORD conn_type;
    GUID if_guid;
    USHORT conn_present;
    IF_PHYSICAL_ADDRESS perm_phys_addr;
    struct
    {
        DWORD hw : 1;
        DWORD filter : 1;
        DWORD unk : 30;
    } flags;
    DWORD media_type;
    DWORD phys_medium_type;
};