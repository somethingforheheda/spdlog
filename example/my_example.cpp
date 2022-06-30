//
// Created by 汪宁 on 2022/6/30.
//
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"  // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types
#include "spdlog/sinks/stdout_color_sinks.h"

void test_console(){
    //Console logger with color
    auto console = spdlog::stdout_color_mt("console");
    console->info("Welcome to spdlog!");
    console->error("Some error message with arg{}..", 1);

    // Formatting examples
    console->warn("Easy padding in numbers like {:08d}", 12);
    console->critical("Support for int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}", 42);
    console->info("Support for floats {:03.2f}", 1.23456);
    console->info("Positional args are {1} {0}..", "too", "supported");
    console->info("{:<30}", "left aligned");

    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name) function");
}

int main(){
    test_console();
}