#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define CONST const
#define IN
#define OUT
#define EFIAPI
#define OPTIONAL

typedef uint8_t BOOLEAN;
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;
typedef char CHAR8;
typedef struct {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} GUID;

struct EFI_DEVICE_PATH_PROTOCOL;
struct EFI_TIME;
struct EFI_BOOT_SERVICES;
struct EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;
struct EFI_MEMORY_DESCRIPTOR;
struct EFI_CAPSULE_HEADER;
struct EFI_CONFIGURATION_TABLE;
struct EFI_TIME_CAPABILITIES;
struct EFI_RUNTIME_SERVICES;
typedef UINT64 UINTN;
typedef short CHAR16;
typedef UINTN RETURN_STATUS;
typedef RETURN_STATUS EFI_STATUS;
typedef void* EFI_HANDLE;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;
typedef void* EFI_EVENT;
typedef UINTN EFI_TPL;

/* 8 */
typedef unsigned int uint;

/* 2025 */
struct EFI_TABLE_HEADER __packed {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
};

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;
struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

/* 4451 */
struct EFI_SYSTEM_TABLE {
    struct EFI_TABLE_HEADER Hdr;
    CHAR16* FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;
    struct EFI_RUNTIME_SERVICES* RuntimeServices;
    struct EFI_BOOT_SERVICES* BootServices;
    UINTN NumberOfTableEntries;
    struct EFI_CONFIGURATION_TABLE* ConfigurationTable;
};

/* 4377 */
typedef EFI_STATUS(__fastcall* EFI_GET_TIME)(struct EFI_TIME*, struct EFI_TIME_CAPABILITIES*);

/* 4378 */
typedef EFI_STATUS(__fastcall* EFI_SET_TIME)(struct EFI_TIME*);

/* 4379 */
typedef EFI_STATUS(__fastcall* EFI_GET_WAKEUP_TIME)(BOOLEAN*, BOOLEAN*, struct EFI_TIME*);

/* 4380 */
typedef EFI_STATUS(__fastcall* EFI_SET_WAKEUP_TIME)(BOOLEAN, struct EFI_TIME*);

/* 4382 */
typedef EFI_STATUS(__fastcall* EFI_SET_VIRTUAL_ADDRESS_MAP)(UINTN, UINTN, UINT32, struct EFI_MEMORY_DESCRIPTOR*);

/* 4383 */
typedef EFI_STATUS(__fastcall* EFI_CONVERT_POINTER)(UINTN, void**);

/* 1710 */
typedef GUID EFI_GUID;

/* 4384 */
typedef EFI_STATUS(__fastcall* EFI_GET_VARIABLE)(CHAR16*, EFI_GUID*, UINT32*, UINTN*, void*);

/* 4385 */
typedef EFI_STATUS(__fastcall* EFI_GET_NEXT_VARIABLE_NAME)(UINTN*, CHAR16*, EFI_GUID*);

/* 4386 */
typedef EFI_STATUS(__fastcall* EFI_SET_VARIABLE)(CHAR16*, EFI_GUID*, UINT32, UINTN, void*);

/* 4387 */
typedef EFI_STATUS(__fastcall* EFI_GET_NEXT_HIGH_MONO_COUNT)(UINT32*);

/* 1993 */
enum enum_17 {
    EfiResetCold = 0x0,
    EfiResetShutdown = 0x2,
    EfiResetWarm = 0x1,
    EfiResetPlatformSpecific = 0x3,
};

/* 1994 */
typedef enum enum_17 EFI_RESET_TYPE;

/* 4388 */
typedef void(__fastcall* EFI_RESET_SYSTEM)(EFI_RESET_TYPE, EFI_STATUS, UINTN, void*);

/* 4390 */
typedef EFI_STATUS(__fastcall* EFI_UPDATE_CAPSULE)(struct EFI_CAPSULE_HEADER**, UINTN, EFI_PHYSICAL_ADDRESS);

/* 4391 */
typedef EFI_STATUS(__fastcall* EFI_QUERY_CAPSULE_CAPABILITIES)(struct EFI_CAPSULE_HEADER**, UINTN, UINT64*, EFI_RESET_TYPE*);

/* 4392 */
typedef EFI_STATUS(__fastcall* EFI_QUERY_VARIABLE_INFO)(UINT32, UINT64*, UINT64*, UINT64*);

/* 4450 */
struct EFI_RUNTIME_SERVICES {
    struct EFI_TABLE_HEADER Hdr;
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
};

/* 4393 */
typedef EFI_TPL(__fastcall* EFI_RAISE_TPL)(EFI_TPL);

/* 4394 */
typedef void(__fastcall* EFI_RESTORE_TPL)(EFI_TPL);

/* 2323 */
enum enum_494 {
    MaxAllocateType = 0x3,
    AllocateAnyPages = 0x0,
    AllocateAddress = 0x2,
    AllocateMaxAddress = 0x1,
};

/* 2324 */
typedef enum enum_494 EFI_ALLOCATE_TYPE;

/* 1973 */
enum enum_16 {
    EfiBootServicesCode = 0x3,
    EfiRuntimeServicesData = 0x6,
    EfiMemoryMappedIOPortSpace = 0xC,
    EfiLoaderData = 0x2,
    EfiBootServicesData = 0x4,
    EfiLoaderCode = 0x1,
    EfiReservedMemoryType = 0x0,
    EfiRuntimeServicesCode = 0x5,
    EfiACPIReclaimMemory = 0x9,
    EfiMaxMemoryType = 0xF,
    EfiConventionalMemory = 0x7,
    EfiMemoryMappedIO = 0xB,
    EfiPalCode = 0xD,
    EfiPersistentMemory = 0xE,
    EfiACPIMemoryNVS = 0xA,
    EfiUnusableMemory = 0x8,
};

/* 1974 */
typedef enum enum_16 EFI_MEMORY_TYPE;

/* 4395 */
typedef EFI_STATUS(__fastcall* EFI_ALLOCATE_PAGES)(EFI_ALLOCATE_TYPE, EFI_MEMORY_TYPE, UINTN, EFI_PHYSICAL_ADDRESS*);

/* 4396 */
typedef EFI_STATUS(__fastcall* EFI_FREE_PAGES)(EFI_PHYSICAL_ADDRESS, UINTN);

/* 4397 */
typedef EFI_STATUS(__fastcall* EFI_GET_MEMORY_MAP)(UINTN*, struct EFI_MEMORY_DESCRIPTOR*, UINTN*, UINTN*, UINT32*);

/* 4398 */
typedef EFI_STATUS(__fastcall* EFI_ALLOCATE_POOL)(EFI_MEMORY_TYPE, UINTN, void**);

/* 4399 */
typedef EFI_STATUS(__fastcall* EFI_FREE_POOL)(void*);

/* 4400 */
typedef void(__fastcall* EFI_EVENT_NOTIFY)(EFI_EVENT, void*);

/* 4401 */
typedef EFI_STATUS(__fastcall* EFI_CREATE_EVENT)(UINT32, EFI_TPL, EFI_EVENT_NOTIFY, void*, EFI_EVENT*);

/* 4402 */
enum enum_496 {
    TimerPeriodic = 0x1,
    TimerCancel = 0x0,
    TimerRelative = 0x2,
};

/* 4403 */
typedef enum enum_496 EFI_TIMER_DELAY;

/* 4404 */
typedef EFI_STATUS(__fastcall* EFI_SET_TIMER)(EFI_EVENT, EFI_TIMER_DELAY, UINT64);

/* 4405 */
typedef EFI_STATUS(__fastcall* EFI_WAIT_FOR_EVENT)(UINTN, EFI_EVENT*, UINTN*);

/* 4406 */
typedef EFI_STATUS(__fastcall* EFI_SIGNAL_EVENT)(EFI_EVENT);

/* 4407 */
typedef EFI_STATUS(__fastcall* EFI_CLOSE_EVENT)(EFI_EVENT);

/* 4408 */
typedef EFI_STATUS(__fastcall* EFI_CHECK_EVENT)(EFI_EVENT);

/* 4409 */
enum enum_498 {
    EFI_NATIVE_INTERFACE = 0x0,
};

/* 4410 */
typedef enum enum_498 EFI_INTERFACE_TYPE;

/* 4411 */
typedef EFI_STATUS(__fastcall* EFI_INSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE*, EFI_GUID*, EFI_INTERFACE_TYPE, void*);

/* 4412 */
typedef EFI_STATUS(__fastcall* EFI_REINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE, EFI_GUID*, void*, void*);

/* 4413 */
typedef EFI_STATUS(__fastcall* EFI_UNINSTALL_PROTOCOL_INTERFACE)(EFI_HANDLE, EFI_GUID*, void*);

/* 4414 */
typedef EFI_STATUS(__fastcall* EFI_HANDLE_PROTOCOL)(EFI_HANDLE, EFI_GUID*, void**);

/* 4415 */
typedef EFI_STATUS(__fastcall* EFI_REGISTER_PROTOCOL_NOTIFY)(EFI_GUID*, EFI_EVENT, void**);

/* 4416 */
enum enum_500 {
    ByProtocol = 0x2,
    AllHandles = 0x0,
    ByRegisterNotify = 0x1,
};

/* 4417 */
typedef enum enum_500 EFI_LOCATE_SEARCH_TYPE;

/* 4418 */
typedef EFI_STATUS(__fastcall* EFI_LOCATE_HANDLE)(EFI_LOCATE_SEARCH_TYPE, EFI_GUID*, void*, UINTN*, EFI_HANDLE*);

/* 4419 */
typedef EFI_STATUS(__fastcall* EFI_LOCATE_DEVICE_PATH)(EFI_GUID*, struct EFI_DEVICE_PATH_PROTOCOL**, EFI_HANDLE*);

/* 4420 */
typedef EFI_STATUS(__fastcall* EFI_INSTALL_CONFIGURATION_TABLE)(EFI_GUID*, void*);

/* 4421 */
typedef EFI_STATUS(__fastcall* EFI_IMAGE_LOAD)(BOOLEAN, EFI_HANDLE, struct EFI_DEVICE_PATH_PROTOCOL*, void*, UINTN, EFI_HANDLE*);

/* 4422 */
typedef EFI_STATUS(__fastcall* EFI_IMAGE_START)(EFI_HANDLE, UINTN*, CHAR16**);

/* 4423 */
typedef EFI_STATUS(__fastcall* EFI_EXIT)(EFI_HANDLE, EFI_STATUS, UINTN, CHAR16*);

/* 4357 */
typedef EFI_STATUS(__fastcall* EFI_IMAGE_UNLOAD)(EFI_HANDLE);

/* 4424 */
typedef EFI_STATUS(__fastcall* EFI_EXIT_BOOT_SERVICES)(EFI_HANDLE, UINTN);

/* 4425 */
typedef EFI_STATUS(__fastcall* EFI_GET_NEXT_MONOTONIC_COUNT)(UINT64*);

/* 4426 */
typedef EFI_STATUS(__fastcall* EFI_STALL)(UINTN);

/* 4427 */
typedef EFI_STATUS(__fastcall* EFI_SET_WATCHDOG_TIMER)(UINTN, UINT64, UINTN, CHAR16*);

/* 4428 */
typedef EFI_STATUS(__fastcall* EFI_CONNECT_CONTROLLER)(EFI_HANDLE, EFI_HANDLE*, struct EFI_DEVICE_PATH_PROTOCOL*, BOOLEAN);

/* 4429 */
typedef EFI_STATUS(__fastcall* EFI_DISCONNECT_CONTROLLER)(EFI_HANDLE, EFI_HANDLE, EFI_HANDLE);

/* 4430 */
typedef EFI_STATUS(__fastcall* EFI_OPEN_PROTOCOL)(EFI_HANDLE, EFI_GUID*, void**, EFI_HANDLE, EFI_HANDLE, UINT32);

/* 4431 */
typedef EFI_STATUS(__fastcall* EFI_CLOSE_PROTOCOL)(EFI_HANDLE, EFI_GUID*, EFI_HANDLE, EFI_HANDLE);

/* 4433 */
typedef EFI_STATUS(__fastcall* EFI_OPEN_PROTOCOL_INFORMATION)(EFI_HANDLE, EFI_GUID*, struct EFI_OPEN_PROTOCOL_INFORMATION_ENTRY**, UINTN*);

/* 4434 */
typedef EFI_STATUS(__fastcall* EFI_PROTOCOLS_PER_HANDLE)(EFI_HANDLE, EFI_GUID***, UINTN*);

/* 4435 */
typedef EFI_STATUS(__fastcall* EFI_LOCATE_HANDLE_BUFFER)(EFI_LOCATE_SEARCH_TYPE, EFI_GUID*, void*, UINTN*, EFI_HANDLE**);

/* 4436 */
typedef EFI_STATUS(__fastcall* EFI_LOCATE_PROTOCOL)(EFI_GUID*, void*, void**);

/* 4437 */
typedef EFI_STATUS(__fastcall* EFI_CALCULATE_CRC32)(void*, UINTN, UINT32*);

/* 4438 */
typedef void(__fastcall* EFI_COPY_MEM)(void*, void*, UINTN);

/* 4439 */
typedef void(__fastcall* EFI_SET_MEM)(void*, UINTN, UINT8);

/* 4440 */
typedef EFI_STATUS(__fastcall* EFI_CREATE_EVENT_EX)(UINT32, EFI_TPL, EFI_EVENT_NOTIFY, void*, EFI_GUID*, EFI_EVENT*);

typedef EFI_STATUS (*EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE*, ...);
typedef EFI_STATUS (*EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(EFI_HANDLE, ...);

/* 4442 */
struct EFI_BOOT_SERVICES {
    struct EFI_TABLE_HEADER Hdr;
    EFI_RAISE_TPL RaiseTPL;
    EFI_RESTORE_TPL RestoreTPL;
    EFI_ALLOCATE_PAGES AllocatePages;
    EFI_FREE_PAGES FreePages;
    EFI_GET_MEMORY_MAP GetMemoryMap;
    EFI_ALLOCATE_POOL AllocatePool;
    EFI_FREE_POOL FreePool;
    EFI_CREATE_EVENT CreateEvent;
    EFI_SET_TIMER SetTimer;
    EFI_WAIT_FOR_EVENT WaitForEvent;
    EFI_SIGNAL_EVENT SignalEvent;
    EFI_CLOSE_EVENT CloseEvent;
    EFI_CHECK_EVENT CheckEvent;
    EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL HandleProtocol;
    void* Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
    EFI_LOCATE_HANDLE LocateHandle;
    EFI_LOCATE_DEVICE_PATH LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
    EFI_IMAGE_LOAD LoadImage;
    EFI_IMAGE_START StartImage;
    EFI_EXIT Exit;
    EFI_IMAGE_UNLOAD UnloadImage;
    EFI_EXIT_BOOT_SERVICES ExitBootServices;
    EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
    EFI_STALL Stall;
    EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
    EFI_CONNECT_CONTROLLER ConnectController;
    EFI_DISCONNECT_CONTROLLER DisconnectController;
    EFI_OPEN_PROTOCOL OpenProtocol;
    EFI_CLOSE_PROTOCOL CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
    EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
    EFI_CALCULATE_CRC32 CalculateCrc32;
    EFI_COPY_MEM CopyMem;
    EFI_SET_MEM SetMem;
    EFI_CREATE_EVENT_EX CreateEventEx;
};

/* 4447 */
struct EFI_CONFIGURATION_TABLE {
    EFI_GUID VendorGuid;
    void* VendorTable;
};

/* 2796 */
struct EFI_TIME {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
};

/* 4449 */
struct EFI_TIME_CAPABILITIES {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
};

/* 4444 */
struct EFI_MEMORY_DESCRIPTOR {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
};

/* 4446 */
struct EFI_CAPSULE_HEADER {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
};

/* 1773 */
struct EFI_DEVICE_PATH_PROTOCOL {
    UINT8 Type;
    UINT8 SubType;
    UINT8 Length[2];
};

/* 4443 */
struct EFI_OPEN_PROTOCOL_INFORMATION_ENTRY __packed {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
};

typedef void* EFI_HII_HANDLE;
typedef struct {
    EFI_GUID PackageListGuid;
    UINT32 PackageLength;
} EFI_HII_PACKAGE_LIST_HEADER;
typedef UINTN EFI_HII_DATABASE_NOTIFY_TYPE;
typedef struct {
    UINT32 Length;
    UINT32 Type;
    // UINT8  Data[...];
} EFI_HII_PACKAGE_HEADER;
typedef struct {
    UINT16 LayoutLength;
    EFI_GUID Guid;
    UINT32 LayoutDescriptorStringOffset;
    UINT8 DescriptorCount;
    // EFI_KEY_DESCRIPTOR    Descriptors[];
} EFI_HII_KEYBOARD_LAYOUT;

typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_NOTIFY)(
    UINT8,
    CONST EFI_GUID*,
    CONST EFI_HII_PACKAGE_HEADER*,
    EFI_HII_HANDLE,
    EFI_HII_DATABASE_NOTIFY_TYPE);

typedef struct _EFI_HII_DATABASE_PROTOCOL EFI_HII_DATABASE_PROTOCOL;
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_NEW_PACK)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    CONST EFI_HII_PACKAGE_LIST_HEADER*,
    EFI_HANDLE,
    EFI_HII_HANDLE*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_REMOVE_PACK)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    EFI_HII_HANDLE);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_UPDATE_PACK)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    EFI_HII_HANDLE,
    CONST EFI_HII_PACKAGE_LIST_HEADER*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_LIST_PACKS)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    UINT8,
    CONST EFI_GUID*,
    UINTN*,
    EFI_HII_HANDLE*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_EXPORT_PACKS)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    EFI_HII_HANDLE,
    UINTN*,
    CONST EFI_HII_PACKAGE_LIST_HEADER*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_REGISTER_NOTIFY)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    UINT8,
    CONST EFI_GUID*,
    EFI_HII_DATABASE_NOTIFY,
    EFI_HII_DATABASE_NOTIFY_TYPE,
    EFI_HANDLE*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_UNREGISTER_NOTIFY)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    EFI_HANDLE*);
typedef EFI_STATUS(__fastcall* EFI_HII_FIND_KEYBOARD_LAYOUTS)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    UINT16*,
    EFI_GUID*);
typedef EFI_STATUS(__fastcall* EFI_HII_GET_KEYBOARD_LAYOUT)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    CONST EFI_GUID*,
    UINT16*,
    EFI_HII_KEYBOARD_LAYOUT*);
typedef EFI_STATUS(__fastcall* EFI_HII_SET_KEYBOARD_LAYOUT)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    CONST EFI_GUID*);
typedef EFI_STATUS(__fastcall* EFI_HII_DATABASE_GET_PACK_HANDLE)(
    CONST EFI_HII_DATABASE_PROTOCOL*,
    EFI_HII_HANDLE,
    EFI_HANDLE*);

struct _EFI_HII_DATABASE_PROTOCOL {
    EFI_HII_DATABASE_NEW_PACK NewPackageList;
    EFI_HII_DATABASE_REMOVE_PACK RemovePackageList;
    EFI_HII_DATABASE_UPDATE_PACK UpdatePackageList;
    EFI_HII_DATABASE_LIST_PACKS ListPackageLists;
    EFI_HII_DATABASE_EXPORT_PACKS ExportPackageLists;
    EFI_HII_DATABASE_REGISTER_NOTIFY RegisterPackageNotify;
    EFI_HII_DATABASE_UNREGISTER_NOTIFY UnregisterPackageNotify;
    EFI_HII_FIND_KEYBOARD_LAYOUTS FindKeyboardLayouts;
    EFI_HII_GET_KEYBOARD_LAYOUT GetKeyboardLayout;
    EFI_HII_SET_KEYBOARD_LAYOUT SetKeyboardLayout;
    EFI_HII_DATABASE_GET_PACK_HANDLE GetPackageListHandle;
};

typedef UINT16 EFI_STRING_ID;
typedef CHAR16* EFI_STRING;
typedef UINT32 EFI_HII_FONT_STYLE;
typedef struct {
    EFI_HII_FONT_STYLE FontStyle;
    UINT16 FontSize; ///< character cell height in pixels
    CHAR16 FontName[1];
} EFI_FONT_INFO;

typedef struct _EFI_HII_STRING_PROTOCOL EFI_HII_STRING_PROTOCOL;
typedef EFI_STATUS(EFIAPI* EFI_HII_NEW_STRING)(
    IN CONST EFI_HII_STRING_PROTOCOL* This,
    IN EFI_HII_HANDLE PackageList,
    OUT EFI_STRING_ID* StringId,
    IN CONST CHAR8* Language,
    IN CONST CHAR16* LanguageName OPTIONAL,
    IN CONST EFI_STRING String,
    IN CONST EFI_FONT_INFO* StringFontInfo OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_HII_GET_STRING)(
    IN CONST EFI_HII_STRING_PROTOCOL* This,
    IN CONST CHAR8* Language,
    IN EFI_HII_HANDLE PackageList,
    IN EFI_STRING_ID StringId,
    OUT EFI_STRING String,
    IN OUT UINTN* StringSize,
    OUT EFI_FONT_INFO** StringFontInfo OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_HII_SET_STRING)(
    IN CONST EFI_HII_STRING_PROTOCOL* This,
    IN EFI_HII_HANDLE PackageList,
    IN EFI_STRING_ID StringId,
    IN CONST CHAR8* Language,
    IN EFI_STRING String,
    IN CONST EFI_FONT_INFO* StringFontInfo OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_HII_GET_LANGUAGES)(
    IN CONST EFI_HII_STRING_PROTOCOL* This,
    IN EFI_HII_HANDLE PackageList,
    IN OUT CHAR8* Languages,
    IN OUT UINTN* LanguagesSize);
typedef EFI_STATUS(EFIAPI* EFI_HII_GET_2ND_LANGUAGES)(
    IN CONST EFI_HII_STRING_PROTOCOL* This,
    IN EFI_HII_HANDLE PackageList,
    IN CONST CHAR8* PrimaryLanguage,
    IN OUT CHAR8* SecondaryLanguages,
    IN OUT UINTN* SecondaryLanguagesSize);

struct _EFI_HII_STRING_PROTOCOL {
    EFI_HII_NEW_STRING NewString;
    EFI_HII_GET_STRING GetString;
    EFI_HII_SET_STRING SetString;
    EFI_HII_GET_LANGUAGES GetLanguages;
    EFI_HII_GET_2ND_LANGUAGES GetSecondaryLanguages;
};