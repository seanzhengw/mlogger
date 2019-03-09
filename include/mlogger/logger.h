#ifndef MLOGGER_LOGGER_H_
#define MLOGGER_LOGGER_H_

#define MLOGGER_LOGLEVEL_V 0
#define MLOGGER_LOGLEVEL_D 1
#define MLOGGER_LOGLEVEL_I 2
#define MLOGGER_LOGLEVEL_W 3
#define MLOGGER_LOGLEVEL_E 4
#define MLOGGER_LOGLEVEL_C 5
#define MLOGGER_LOGLEVEL_F 6
#define MLOGGER_LOGLEVEL_N 7

// uncomment to set LOGLEVEL
// #define LOGLEVEL MLOGGER_LOGLEVEL_V

// set verbose prefix, or comment this line to remove verbose prefix
#define MLOGGER_V_PREFIX ";V: "
// set debug prefix, or comment this line to remove debug prefix
#define MLOGGER_D_PREFIX ";D: "
// set information prefix, or comment this line to remove information prefix
#define MLOGGER_I_PREFIX ";I: "
// set warning prefix, or comment this line to remove warning prefix
#define MLOGGER_W_PREFIX ";W: "
// set error prefix, or comment this line to remove error prefix
#define MLOGGER_E_PREFIX ";E: "
// set critical prefix, or comment this line to remove critical prefix
#define MLOGGER_C_PREFIX ";C: "
// set fatal prefix, or comment this line to remove fatal prefix
#define MLOGGER_F_PREFIX ";F: "
// set log suffix, comment this line to remove newline
#define MLOGGER_SUFFIX "\n"

#include <platform/PlatformMutex.h>

namespace mlogger
{

class Logger
{
public:
    // logs to file descriptor
    Logger(void *fd = nullptr);
    // V: Verbose
    // Logs everything including system secrets messages, never for production use.
    // e.g., at file xxx/xxx.cpp line 100
    int V(const char *format, ...);
    // D: Debug
    // Logs debug messages.
    // e.g., k=10
    int D(const char *format, ...);
    // I: Information
    // Logs runtime information and work flows messages.
    // e.g., battery 80%
    int I(const char *format, ...);
    // W: Warning
    // Logs something unusual,
    // the system has good handle and will keeps running, the warnings should be taken care of.
    // e.g., system high loads, high temperature...
    int W(const char *format, ...);
    // E: Error
    // Logs something wrong,
    // the system may stop running by programed conditions, the errors should be fixed.
    // e.g., over temperature, low voltage, sensor status loss ...
    int E(const char *format, ...);
    // C: Critical
    // Logs critical exceptions,
    // the system has not programed to handle the exceptions,
    // the system should stop after critical messages.
    // e.g., firmware exception crash.
    int C(const char *format, ...);
    // F: Fatal
    // Logs fatal exceptions,
    // the system may be unusable after this crash.
    // e.g., hardware crash, data crash and unrecoverable...
    int F(const char *format, ...);

    static constexpr bool LevelV();
    static constexpr bool LevelD();
    static constexpr bool LevelI();
    static constexpr bool LevelW();
    static constexpr bool LevelE();
    static constexpr bool LevelC();
    static constexpr bool LevelF();

private:
#ifndef LOGLEVEL
#define LOGLEVEL
#endif
#if ((LOGLEVEL + 0) < MLOGGER_LOGLEVEL_N)
    void *mFile;
    PlatformMutex mMutex;
#endif
};

#if !((LOGLEVEL + 0) < MLOGGER_LOGLEVEL_N)
inline Logger::Logger(void *fd)
{
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_V)
inline int Logger::V(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_D)
inline int Logger::D(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_I)
inline int Logger::I(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_W)
inline int Logger::W(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_E)
inline int Logger::E(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_C)
inline int Logger::C(const char *format, ...)
{
    return 0;
}
#endif
#if ((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_F)
inline int Logger::F(const char *format, ...)
{
    return 0;
}
#endif

inline constexpr bool Logger::LevelV()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_V);
}

inline constexpr bool Logger::LevelD()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_D);
}

inline constexpr bool Logger::LevelI()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_I);
}

inline constexpr bool Logger::LevelW()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_W);
}

inline constexpr bool Logger::LevelE()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_E);
}

inline constexpr bool Logger::LevelC()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_C);
}

inline constexpr bool Logger::LevelF()
{
    return !((LOGLEVEL + 0) > MLOGGER_LOGLEVEL_F);
}

} // namespace mlogger

#endif
