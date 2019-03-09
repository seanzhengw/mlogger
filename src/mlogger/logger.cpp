#include <mlogger/logger.h>

#include <mbed.h>

using namespace mlogger;
using mlogger::Logger;

#if ((LOGLEVEL+0) < MLOGGER_LOGLEVEL_N)
Logger::Logger(mbed::Stream *stream) : mStream(stream)
{
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_V)
int Logger::V(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_V_PREFIX
    int r = mStream->puts(MLOGGER_V_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_D)
int Logger::D(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_D_PREFIX
    int r = mStream->puts(MLOGGER_D_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_I)
int Logger::I(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_I_PREFIX
    int r = mStream->puts(MLOGGER_I_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_W)
int Logger::W(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_W_PREFIX
    int r = mStream->puts(MLOGGER_W_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_E)
int Logger::E(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_E_PREFIX
    int r = mStream->puts(MLOGGER_E_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_C)
int Logger::C(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_C_PREFIX
    int r = mStream->puts(MLOGGER_C_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif

#if !((LOGLEVEL+0) > MLOGGER_LOGLEVEL_F)
int Logger::F(const char *format, ...)
{
    mMutex.lock();
    std::va_list arg;
    va_start(arg, format);
#ifdef MLOGGER_F_PREFIX
    int r = mStream->puts(MLOGGER_F_PREFIX);
#else
    int r = 0;
#endif
    r += mStream->vprintf(format, arg);
#ifdef MLOGGER_SUFFIX
    r += mStream->puts(MLOGGER_SUFFIX);
#endif
    fflush(*mStream);
    va_end(arg);
    mMutex.unlock();
    return r;
}
#endif
