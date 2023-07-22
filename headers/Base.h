/** @file
  Defines data types and constants introduced in UEFI.

Copyright (c) 2006 - 2021, Intel Corporation. All rights reserved.<BR>
Portions copyright (c) 2011 - 2016, ARM Ltd. All rights reserved.<BR>
Copyright (c) 2020, Hewlett Packard Enterprise Development LP. All rights reserved.<BR>
Copyright (c) 2022, Loongson Technology Corporation Limited. All rights reserved.<BR>

SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __UEFI_BASETYPE_H__
#define __UEFI_BASETYPE_H__

//
// Modifiers to abstract standard types to aid in debug of problems
//

///
/// Datum is read-only.
///
#define CONST const

///
/// Datum is scoped to the current file or function.
///
#define STATIC static

///
/// Undeclared type.
///
#define VOID void

//
// Modifiers for Data Types used to self document code.
// This concept is borrowed for UEFI specification.
//

///
/// Datum is passed to the function.
///
#define IN

///
/// Datum is returned from the function.
///
#define OUT

///
/// Passing the datum to the function is optional, and a NULL
/// is passed if the value is not supplied.
///
#define OPTIONAL

#define EFIAPI

///
/// 8-byte unsigned value
///
typedef unsigned long long UINT64;
///
/// 8-byte signed value
///
typedef long long INT64;
///
/// 4-byte unsigned value
///
typedef unsigned int UINT32;
///
/// 4-byte signed value
///
typedef int INT32;
///
/// 2-byte unsigned value
///
typedef unsigned short UINT16;
///
/// 2-byte Character.  Unless otherwise specified all strings are stored in the
/// UTF-16 encoding format as defined by Unicode 2.1 and ISO/IEC 10646 standards.
///
typedef unsigned short CHAR16;
///
/// 2-byte signed value
///
typedef short INT16;
///
/// Logical Boolean.  1-byte value containing 0 for FALSE or a 1 for TRUE.  Other
/// values are undefined.
///
typedef unsigned char BOOLEAN;
///
/// 1-byte unsigned value
///
typedef unsigned char UINT8;
///
/// 1-byte Character
///
typedef char CHAR8;
///
/// 1-byte signed value
///
typedef signed char INT8;
///
/// Unsigned value of native width.  (4 bytes on supported 32-bit processor instructions,
/// 8 bytes on supported 64-bit processor instructions)
///
typedef UINT64 UINTN;
///
/// Signed value of native width.  (4 bytes on supported 32-bit processor instructions,
/// 8 bytes on supported 64-bit processor instructions)
///
typedef INT64 INTN;

typedef UINTN RETURN_STATUS;

///
/// 128 bit buffer containing a unique identifier value.
/// Unless otherwise specified, aligned on a 64 bit boundary.
///
typedef struct {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} GUID;

//
// Basic data type definitions introduced in UEFI.
//

///
/// 128-bit buffer containing a unique identifier value.
///
typedef GUID EFI_GUID;
///
/// Function return status for EFI API.
///
typedef RETURN_STATUS EFI_STATUS;
///
/// A collection of related interfaces.
///
typedef VOID* EFI_HANDLE;

typedef VOID* EFI_HII_HANDLE;

typedef CHAR16* EFI_STRING;

/**
  This protocol can be used on any device handle to obtain generic path/location
  information concerning the physical device or logical device. If the handle does
  not logically map to a physical device, the handle may not necessarily support
  the device path protocol. The device path describes the location of the device
  the handle is for. The size of the Device Path can be determined from the structures
  that make up the Device Path.
**/
typedef struct {
    UINT8 Type; ///< 0x01 Hardware Device Path.
                ///< 0x02 ACPI Device Path.
                ///< 0x03 Messaging Device Path.
                ///< 0x04 Media Device Path.
                ///< 0x05 BIOS Boot Specification Device Path.
                ///< 0x7F End of Hardware Device Path.

    UINT8 SubType; ///< Varies by Type
                   ///< 0xFF End Entire Device Path, or
                   ///< 0x01 End This Instance of a Device Path and start a new
                   ///< Device Path.

    UINT8 Length[2]; ///< Specific Device Path data. Type and Sub-Type define
                     ///< type of data. Size of data is included in Length.
} EFI_DEVICE_PATH_PROTOCOL;

#endif
