#pragma once

#include <iostream>
#include <memory>
#include <mutex>

namespace suplog {
    class LogSink
    {
    public:
        using ptr = std::shared_ptr<LogSink>;
        LogSink() {}
        virtual ~LogSink()=default;
        virtual void log(const char* data, size_t len) = 0;
    };

    class StdoutSink :public LogSink
    {
    public:
        using ptr = std::shared_ptr<StdoutSink>;
        StdoutSink() = default;

        void log(const char* data, size_t len) {
            std::cout.write(data, len);
        }
    };

}