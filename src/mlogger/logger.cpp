// BSD 2-Clause License
//
// Copyright (c) 2019, Sean Zheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <mlogger/logger.h>

#include <cstdio>
#include <cstdarg>

using namespace mlogger;
using mlogger::Logger;

#if ((LOGLEVEL + 0) < MLOGGER_LOGLEVEL_N)
Logger::Logger(void *fd) : mFile(fd)
{
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_V)
int Logger::V(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_V_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_V_PREFIX) : printf(MLOGGER_V_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_D)
int Logger::D(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_D_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_D_PREFIX) : printf(MLOGGER_D_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_I)
int Logger::I(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_I_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_I_PREFIX) : printf(MLOGGER_I_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_W)
int Logger::W(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_W_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_W_PREFIX) : printf(MLOGGER_W_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_E)
int Logger::E(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_E_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_E_PREFIX) : printf(MLOGGER_E_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_C)
int Logger::C(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_C_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_C_PREFIX) : printf(MLOGGER_C_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r = mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_F)
int Logger::F(const char *format, ...)
{
    mMutex.lock();
    fflush((FILE*)mFile);
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_F_PREFIX
    int r = mFile ? fprintf((FILE*)mFile, MLOGGER_F_PREFIX) : printf(MLOGGER_F_PREFIX);
#else
    int r = 0;
#endif
    r += mFile ? vfprintf((FILE*)mFile, format, arg) : vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mFile ? fprintf((FILE*)mFile, MLOGGER_SUFFIX) : printf(MLOGGER_SUFFIX);
#endif
    fflush((FILE*)mFile);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif
