# mlogger

logger for mbed os.

# Usage

    #include <mbed.h>
    #include <mlogger/logger.h>

    Serial serial(TX, RX);
    mlogger::Logger log(&serial);

    int main()
    {
        log.V("log level %s", "Verbose");
        log.D("log level %d, level code %d", "Debug", MLOGGER_LOGLEVEL_D);
        log.D("To close debug level, \"#define LOGLEVEL MLOGGER_LOGLEVEL_I\" in \"mlogger/logger.h\" or \"-D LOGLEVEL=2\" at compile", "Debug", MLOGGER_LOGLEVEL_D);
        log.I("log level Information");
        log.W("log level Warning");
        log.E("log level Error");
        log.C("log level Critical");
        log.F("log level Fatal");
        log.I("To close all log messages, \"#define LOGLEVEL MLOGGER_LOGLEVEL_N\" in \"mlogger/logger.h\" or \"-D LOGLEVEL=7\" at compile");
        log.D("Only use debug level during development");

        for(;;) {}
    }

# Configs

change log level, log prefix, suffix in mlogger/logger.h
