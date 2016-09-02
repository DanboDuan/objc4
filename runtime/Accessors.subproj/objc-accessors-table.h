/*
 * Copyright (c) 2006 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/* Support for optimized accessor methods. Currently optimized accessor methods are provided for ivar offsets from 0 to 64. */

#define ALWAYS_USE_C_ACCESSOR_METHODS 0

// set of property getters for specific offsets.
#define GETPROPERTY_OFFSET(offset) _objc_getProperty_offset_ ## offset
#define DECLARE_GETPROPERTY_OFFSET(offset) extern id GETPROPERTY_OFFSET(offset)(id self, SEL _cmd)
#define IMPLEMENT_GETPROPERTY_OFFSET(offset) static id GETPROPERTY_OFFSET(offset)(id self, SEL _cmd) { return *(id*)((char*)self + offset); }

#if ALWAYS_USE_C_ACCESSOR_METHODS || defined(__ppc__) || defined(__ppc64__) || defined(__x86_64__)
// C versions with hard-coded offsets. may be good enough in most cases.
IMPLEMENT_GETPROPERTY_OFFSET(0)
IMPLEMENT_GETPROPERTY_OFFSET(4)
IMPLEMENT_GETPROPERTY_OFFSET(8)
IMPLEMENT_GETPROPERTY_OFFSET(12)
IMPLEMENT_GETPROPERTY_OFFSET(16)
IMPLEMENT_GETPROPERTY_OFFSET(20)
IMPLEMENT_GETPROPERTY_OFFSET(24)
IMPLEMENT_GETPROPERTY_OFFSET(28)
IMPLEMENT_GETPROPERTY_OFFSET(32)
IMPLEMENT_GETPROPERTY_OFFSET(36)
IMPLEMENT_GETPROPERTY_OFFSET(40)
IMPLEMENT_GETPROPERTY_OFFSET(44)
IMPLEMENT_GETPROPERTY_OFFSET(48)
IMPLEMENT_GETPROPERTY_OFFSET(52)
IMPLEMENT_GETPROPERTY_OFFSET(56)
IMPLEMENT_GETPROPERTY_OFFSET(60)
IMPLEMENT_GETPROPERTY_OFFSET(64)
#else
// forward delcarations to assembly versions. only on i386 right now.
DECLARE_GETPROPERTY_OFFSET(0);
DECLARE_GETPROPERTY_OFFSET(4);
DECLARE_GETPROPERTY_OFFSET(8);
DECLARE_GETPROPERTY_OFFSET(12);
DECLARE_GETPROPERTY_OFFSET(16);
DECLARE_GETPROPERTY_OFFSET(20);
DECLARE_GETPROPERTY_OFFSET(24);
DECLARE_GETPROPERTY_OFFSET(28);
DECLARE_GETPROPERTY_OFFSET(32);
DECLARE_GETPROPERTY_OFFSET(36);
DECLARE_GETPROPERTY_OFFSET(40);
DECLARE_GETPROPERTY_OFFSET(44);
DECLARE_GETPROPERTY_OFFSET(48);
DECLARE_GETPROPERTY_OFFSET(52);
DECLARE_GETPROPERTY_OFFSET(56);
DECLARE_GETPROPERTY_OFFSET(60);
DECLARE_GETPROPERTY_OFFSET(64);
#endif

static void* _getProperty_offset_table[] = {
    GETPROPERTY_OFFSET(0),
    GETPROPERTY_OFFSET(4),
    GETPROPERTY_OFFSET(8),
    GETPROPERTY_OFFSET(12),
    GETPROPERTY_OFFSET(16),
    GETPROPERTY_OFFSET(20),
    GETPROPERTY_OFFSET(24),
    GETPROPERTY_OFFSET(28),
    GETPROPERTY_OFFSET(32),
    GETPROPERTY_OFFSET(36),
    GETPROPERTY_OFFSET(40),
    GETPROPERTY_OFFSET(44),
    GETPROPERTY_OFFSET(48),
    GETPROPERTY_OFFSET(52),
    GETPROPERTY_OFFSET(56),
    GETPROPERTY_OFFSET(60),
    GETPROPERTY_OFFSET(64),
};

#undef GETPROPERTY_OFFSET
#undef DECLARE_GETPROPERTY_OFFSET
#undef IMPLEMENT_GETPROPERTY_OFFSET
#define GETPROPERTY_IMP(offset) ((offset <= 64) ? (IMP)_getProperty_offset_table[offset >> 2] : NULL)

// set of property setters for specific offsets.
#define SETPROPERTY_OFFSET(offset) _objc_setProperty_offset_ ## offset
#define DECLARE_SETPROPERTY_OFFSET(offset) extern id SETPROPERTY_OFFSET(offset)(id self, SEL _cmd, ...)
#define IMPLEMENT_SETPROPERTY_OFFSET(offset) __private_extern__ void SETPROPERTY_OFFSET(offset)(id self, SEL _cmd, id value) { objc_assign_ivar_gc(value, self, offset); }

#if ALWAYS_USE_C_ACCESSOR_METHODS || !defined(__i386__)
// C versions with hard-coded offsets. may be good enough in most cases.
IMPLEMENT_SETPROPERTY_OFFSET(0)
IMPLEMENT_SETPROPERTY_OFFSET(4)
IMPLEMENT_SETPROPERTY_OFFSET(8)
IMPLEMENT_SETPROPERTY_OFFSET(12)
IMPLEMENT_SETPROPERTY_OFFSET(16)
IMPLEMENT_SETPROPERTY_OFFSET(20)
IMPLEMENT_SETPROPERTY_OFFSET(24)
IMPLEMENT_SETPROPERTY_OFFSET(28)
IMPLEMENT_SETPROPERTY_OFFSET(32)
IMPLEMENT_SETPROPERTY_OFFSET(36)
IMPLEMENT_SETPROPERTY_OFFSET(40)
IMPLEMENT_SETPROPERTY_OFFSET(44)
IMPLEMENT_SETPROPERTY_OFFSET(48)
IMPLEMENT_SETPROPERTY_OFFSET(52)
IMPLEMENT_SETPROPERTY_OFFSET(56)
IMPLEMENT_SETPROPERTY_OFFSET(60)
IMPLEMENT_SETPROPERTY_OFFSET(64)
#else
// forward delcarations to assembly versions. only on i386 right now.
DECLARE_SETPROPERTY_OFFSET(0);
DECLARE_SETPROPERTY_OFFSET(4);
DECLARE_SETPROPERTY_OFFSET(8);
DECLARE_SETPROPERTY_OFFSET(12);
DECLARE_SETPROPERTY_OFFSET(16);
DECLARE_SETPROPERTY_OFFSET(20);
DECLARE_SETPROPERTY_OFFSET(24);
DECLARE_SETPROPERTY_OFFSET(28);
DECLARE_SETPROPERTY_OFFSET(32);
DECLARE_SETPROPERTY_OFFSET(36);
DECLARE_SETPROPERTY_OFFSET(40);
DECLARE_SETPROPERTY_OFFSET(44);
DECLARE_SETPROPERTY_OFFSET(48);
DECLARE_SETPROPERTY_OFFSET(52);
DECLARE_SETPROPERTY_OFFSET(56);
DECLARE_SETPROPERTY_OFFSET(60);
DECLARE_SETPROPERTY_OFFSET(64);
#endif

static void* _setProperty_offset_table[] = {
    SETPROPERTY_OFFSET(0),
    SETPROPERTY_OFFSET(4),
    SETPROPERTY_OFFSET(8),
    SETPROPERTY_OFFSET(12),
    SETPROPERTY_OFFSET(16),
    SETPROPERTY_OFFSET(20),
    SETPROPERTY_OFFSET(24),
    SETPROPERTY_OFFSET(28),
    SETPROPERTY_OFFSET(32),
    SETPROPERTY_OFFSET(36),
    SETPROPERTY_OFFSET(40),
    SETPROPERTY_OFFSET(44),
    SETPROPERTY_OFFSET(48),
    SETPROPERTY_OFFSET(52),
    SETPROPERTY_OFFSET(56),
    SETPROPERTY_OFFSET(60),
    SETPROPERTY_OFFSET(64),
};

#undef SETPROPERTY_OFFSET
#undef DECLARE_SETPROPERTY_OFFSET
#undef IMPLEMENT_SETPROPERTY_OFFSET
#define SETPROPERTY_IMP(offset) ((offset <= 64) ? (IMP)_setProperty_offset_table[offset >> 2] : NULL)