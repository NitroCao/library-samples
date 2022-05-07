#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <vector>

namespace demoapp {
class application {
public:
    application();
    ~application();
    int run(int argc, char **argv);

private:
    enum {
        SUBCMD_INIT,
    };
    CLI::App app;

    inline int get_subcmd(std::string const &name) const
    {
        if (name == "init")
            return SUBCMD_INIT;
        else
            return -1;
    }
};

class init {
public:
    init(const CLI::App *app) { this->app = app; }
    ~init() {}
    int run();

private:
    const CLI::App *app;
    bool quiet;
    std::string dir{"."};
    std::string branch;

    int check_args();
};
}; // namespace demoapp

#endif // _APPLICATION_H_
