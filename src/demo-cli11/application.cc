#include <cassert>

#include "application.h"

namespace demoapp {

application::application()
{
    app.description("Demo git command to show the usage of CLI11 library");
    app.name("git");

    auto init_subcmd = app.add_subcommand("init", "Create an empty Git repository or reinitialize an existing one");
    init_subcmd->add_option("-b,--initial-branch",
                            "Use the specified name for the initial branch in the newly created repository");
    init_subcmd->add_flag("-q,--quiet", "Only print warning and error messages.");
    init_subcmd->allow_extras();

    app.require_subcommand(1);
}

application::~application() {}

int application::run(int argc, char **argv)
{
    CLI11_PARSE(app, argc, argv);

    auto tmp = app.get_subcommands();
    assert(tmp.size() == 1 && "the command line only requires one subcommand");

    CLI::App *subcmd = tmp[0];
    switch (get_subcmd(subcmd->get_name())) {
    case SUBCMD_INIT:
        return init(subcmd).run();
        break;
    default:
        std::cerr << "unknown subcommand\n";
        return 1;
    }
    return 0;
}

int init::run()
{
    int ret = check_args();
    if (ret)
        return ret;

    std::cout << "Init a Git repository under " << dir << ".\n";
    std::cout << "Initial branch is " << branch << ".\n";
    std::cout << "Quiet option is set? " << quiet << "\n";

    return 0;
}

int init::check_args()
{
    if (app->remaining_size() > 1) {
        std::cerr << "wrong usage.\n";
        return 1;
    }
    else if (app->remaining_size() == 1) {
        dir = app->remaining()[0];
    }

    const CLI::Option *option = app->get_option("--initial-branch");
    option->results(branch);

    option = app->get_option("--quiet");
    option->results(quiet);

    return 0;
}
}; // namespace demoapp
