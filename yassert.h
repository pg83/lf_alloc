#pragma once

#include "defaults.h"

#if defined(_MSC_VER)
#include <new>
#if defined(_DEBUG)
#if defined(_CRTDBG_MAP_ALLOC)
#include <cstdlib>  /* definitions for malloc/calloc */
#include <malloc.h> /* must be before their redefinitions as _*_dbg() */
#endif
#include <crtdbg.h>
#else
#endif
#include <cassert>
#elif defined(__GNUC__)
#ifdef _sun_
#include <alloca.h>
#endif
#include <cassert>
#endif

#if !defined(_MSC_VER)

#if defined(__x86_64__) || defined(__i386__)
#define __debugbreak ydebugbreak
inline void ydebugbreak() {
    __asm__ volatile("int $3\n");
}
#else
inline void __debugbreak() {
    assert(0);
}
#endif

inline bool YaIsDebuggerPresent() {
    return false;
}

#else
// __debugbreak is intrinsic in MSVC

extern "C" {
__declspec(dllimport) int __stdcall IsDebuggerPresent();
}

inline bool YaIsDebuggerPresent() {
    return IsDebuggerPresent() != 0;
}
#endif

#undef Y_ASSERT

#define Y_ASSERT assert
