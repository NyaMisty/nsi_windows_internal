typedef enum _NSI_STORE {
    NsiPersistent,
    // Persists as long as module exists.
    NsiActive,
    NsiBoth,
    NsiCurrent,
    NsiBootFirmwareTable
} NSI_STORE;

typedef enum _NSI_SET_ACTION {  
    NsiSetDefault = 0,
    NsiSetCreateOnly = 1,
    NsiSetCreateOrSet = 2,
    NsiSetDelete = 3,
    NsiSetReset = 4,
    NsiSetClear,
    NsiSetCreateOrSetWithReference,
    NsiSetDeleteWithReference,
} NSI_SET_ACTION;  

typedef enum _NSI_STRUCT_TYPE {
    NsiStructRw,
    NsiStructRoDynamic,
    NsiStructRoStatic,
    NsiMaximumStructType
} NSI_STRUCT_TYPE;

/* Undocumented Nsi api */

#define NSI_PARAM_TYPE_RW      0
#define NSI_PARAM_TYPE_DYNAMIC 1
#define NSI_PARAM_TYPE_STATIC  2

struct nsi_enumerate_all_ex
{
    void *unknown[2];
    PNPI_MODULEID ModuleId;
    ULONG ObjectIndex;
    UINT first_arg;
    UINT second_arg;
    void *key_data;
    UINT key_size;
    void *rw_data;
    UINT rw_size;
    void *dynamic_data;
    UINT dynamic_size;
    void *static_data;
    UINT static_size;
    UINT_PTR count;
};

struct nsi_get_all_parameters_ex
{
    void *unknown[2];
    PNPI_MODULEID ModuleId;
    ULONG ObjectIndex;
    UINT first_arg;
    UINT unknown2;
    const void *key;
    UINT key_size;
    void *rw_data;
    UINT rw_size;
    void *dynamic_data;
    UINT dynamic_size;
    void *static_data;
    UINT static_size;
};

struct nsi_get_parameter_ex
{
    void *unknown[2];
    PNPI_MODULEID ModuleId;
    ULONG ObjectIndex;
    UINT first_arg;
    UINT unknown2;
    const void *key;
    UINT key_size;
    UINT_PTR param_type;
    PVOID Parameter;
    ULONG ParameterLen;
    ULONG ParameterOffset;
};


NSISTATUS
NsiGetParameter(
    __in NSI_STORE Store,
    __in PNPI_MODULEID ModuleId,
    __in ULONG ObjectIndex,
    __in_bcount_opt(KeyStructLength) PVOID KeyStruct,
    __in ULONG KeyStructLength,
    __in NSI_STRUCT_TYPE StructType,
    __out_bcount(ParameterLen) PVOID Parameter,
    __in ULONG ParameterLen,
    __in ULONG ParameterOffset
);


NSISTATUS NsiGetAllParameters(
    __in NSI_STORE Store,
    __in PNPI_MODULEID ModuleId,
    __in ULONG ObjectIndex,
    __in_bcount_opt(KeyStructLength) PVOID KeyStruct,
    __in ULONG          KeyStructLength,
    __in_bcount_opt(RwParameterStructLength) PVOID RwParameterStruct,
    __in ULONG          RwParameterStructLength,
    void *dynamic_data,
    DWORD dynamic_size,
    void *static_data,
    DWORD static_size
);

NSISTATUS NsiGetAllParametersEx(
    struct nsi_get_all_parameters_ex *params
);

NSISTATUS NsiGetParameterEx(
    struct nsi_get_parameter_ex *params
);

NSISTATUS  
NsiSetAllParameters(  
    __in NSI_STORE      Store,
    __in NSI_SET_ACTION Action,
    __in PNPI_MODULEID  ModuleId,
    __in ULONG          ObjectIndex,
    __in_bcount_opt(KeyStructLength) PVOID KeyStruct,
    __in ULONG          KeyStructLength,
    __in_bcount_opt(RwParameterStructLength) PVOID RwParameterStruct,
    __in ULONG          RwParameterStructLength  
);  


NSISTATUS NsiAllocateAndGetTable(
    __in NSI_STORE Store,
    __in PNPI_MODULEID ModuleId,
    __in ULONG          ObjectIndex,
    __in_bcount_opt(KeyStructsLength) PVOID *KeyStruct,
    __in ULONG          KeyStructsLength,
    __in_bcount_opt(RwParameterStructsLength) PVOID *RwParameterStructs,
    __in ULONG          RwParameterStructsLength,
    void **dynamic_data,
    DWORD dynamic_size,
    void **static_data,
    DWORD static_size,
    DWORD *count,
    DWORD unk2
);

NSISTATUS NsiEnumerateObjectsAllParameters(
    __in NSI_STORE Store,
    DWORD unk2,
    __in PNPI_MODULEID ModuleId,
    __in ULONG ObjectIndex,
    __in_bcount_opt(KeyStructLength) PVOID KeyStruct,
    __in ULONG          KeyStructLength,
    __in_bcount_opt(RwParameterStructLength) PVOID RwParameterStruct,
    __in ULONG          RwParameterStructLength,
    void *dynamic_data,
    DWORD dynamic_size,
    void *static_data,
    DWORD static_size,
    DWORD *count
);

NSISTATUS NsiEnumerateObjectsAllParametersEx(
    struct nsi_enumerate_all_ex *params
);

void NsiFreeTable(
    __in_bcount_opt(KeyStructLength) PVOID KeyStruct,
    __in_bcount_opt(RwParameterStructLength) PVOID RwParameterStruct,
    void *dynamic_data,
    void *static_data
);

#ifdef __WINE_INIT_NPI_MODULEID
#ifdef __cplusplus
#define DEFINE_NPI_GUID_MODULEID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    EXTERN_C const NPI_MODULEID name DECLSPEC_HIDDEN;                   \
    EXTERN_C const NPI_MODULEID name =                                  \
    { sizeof(NPI_MODULEID), MIT_GUID, { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } } } }
#else
#define DEFINE_NPI_GUID_MODULEID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    const NPI_MODULEID name DECLSPEC_HIDDEN;                            \
    const NPI_MODULEID name =                                           \
    { sizeof(NPI_MODULEID), MIT_GUID, { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } } } }
#endif
#else /* __WINE_INIT_MODULEID */
#define DEFINE_NPI_GUID_MODULEID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
    EXTERN_C const NPI_MODULEID name DECLSPEC_HIDDEN
#endif /* __WINE_INIT_MODULEID */

#define DEFINE_NPI_MS_MODULEID(name, n) DEFINE_NPI_GUID_MODULEID(name, 0xeb004a00 + (n), 0x9b1a, 0x11d4, \
                                                                 0x91, 0x23, 0x00, 0x50, 0x04, 0x77, 0x59, 0xbc)

DEFINE_NPI_MS_MODULEID( NPI_MS_IPV4_MODULEID,        0x00 );
DEFINE_NPI_MS_MODULEID( NPI_MS_IPV6_MODULEID,        0x01 );
DEFINE_NPI_MS_MODULEID( NPI_MS_UDP_MODULEID,         0x02 );
DEFINE_NPI_MS_MODULEID( NPI_MS_TCP_MODULEID,         0x03 );
DEFINE_NPI_MS_MODULEID( NPI_MS_NDIS_MODULEID,        0x11 );
DEFINE_NPI_MS_MODULEID( NPI_MS_WINNAT_MODULEID,        0x20 );