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
