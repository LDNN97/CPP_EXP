#include <iostream>
#include <flags.h>

int main(int argc, char** argv) {
    const flags::args args(argc, argv);
    const auto mode = args.get<std::string>("mode");
    const auto exp_id = args.get<int>("id");
    const auto seed = args.get<int>("seed");
    const auto indi = args.get<int>("indi");
    if (!seed && !mode) {
        std::cerr << "No seed or mode supplied. :(\n";
        return 1;
    }
    if (mode == "train") {
        if (!seed)
            std::cout << 0 << std::endl;
        else
            std::cout << *seed << std::endl;

        return 0;
    }

    if (mode == "display") {
        if (!indi)
            std::cout << "ensemble" << std::endl;
        else
            std::cout << *indi << std::endl;
        return 0;
    }
    return 0;
}
