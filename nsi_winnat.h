typedef enum _WINNAT_NSI_OBJECT_INDEX {  
    WinNatNsiObjectWinNatInstance = 0,
    WinNatNsiObjectWinNatPacketFilter,  
    WinNatNsiObjectWinNatAddressPool, 
    WinNatNsiObjectWinNatBindingEntry,  
    WinNatNsiObjectWinNatSessionEntry,  
    WinNatNsiObjectWinNatStaticBinding,  
    WinNatNsiObjectSlbNatInstance,  
    WinNatNsiObjectSlbNatExternalAddress,  
    WinNatNsiObjectSlbNatStaticMapping,  
    WinNatNsiObjectSlbNatSession,  
    WinNatNsiObjectSlbNatGlobal,  
    WinNatNsiObjectIPxlatInstance,  
} WINNAT_NSI_OBJECT_INDEX, *PWINNAT_NSI_OBJECT_INDEX;  

struct WINNAT_SLBNAT_KEY
{
  wchar_t natName[40];
};

struct __unaligned __declspec(align(4)) WINNAT_SLBNAT_RW
{
  _DWORD type;
  GUID rdId;
  _WORD externalFamily;
  _WORD externalPrefix;
  _BYTE externalAddr[6];
  _BYTE gap_1E[2];
  _DWORD field_20;
  _BYTE gap_24[4];
  _DWORD field_28;
  _BYTE gap2C[4];
  _DWORD field_30;
  _DWORD field_34;
  _DWORD field_38;
  _DWORD field_3C;
  _DWORD field_40;
  _WORD addrFamily;
  unsigned __int16 internalSubnetPrefix;
  _DWORD internalSubnetIPAddress;
  _BYTE gap_4C[4];
  _QWORD field_50;
  _DWORD ExternalInterfaceConstraint;
};

// WinNatNsiObjectWinNatInstance
struct WINNAT_SLBNAT_INSTANCE_KEY
{
  wchar_t natName[40];
};


// For WinNatNsiObjectSlbNatExternalAddress
struct WINNAT_SLBNAT_EXTERNAL_ADDRESS_KEY
{
  wchar_t natName[40];
  int externalAddrID;
};
