#include <argparse/argparse.hpp>
#include <iostream>
#include <string>

#include "abstract_visitor/abstract_visitor.hpp"
#include "static_visitor/static_visitor.hpp"

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("program_name");

    program.add_argument("leftHand").help("left hand of the expression").scan<'i', int>();
    program.add_argument("operator")
        .help("operator allowed are [+,-,/,*] note as your shell can treat them as special charactes so its "
              "recommended to use '*' or \\* ");
    program.add_argument("rightHand").help("rightHand").scan<'i', int>();

    try
    {
        program.parse_args(argc, argv);
    }
    catch(const std::runtime_error& err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    auto leftHand = program.get<int>("leftHand");
    std::string op = program.get("operator");
    auto rightHand = program.get<int>("rightHand");

    std::map<std::string, sv::operation> operations{{"+", sv::add{leftHand, rightHand}},
                                                    {"-", sv::sub{leftHand, rightHand}},
                                                    {"*", sv::mul{leftHand, rightHand}},
                                                    {"/", sv::div{leftHand, rightHand}}};
    auto operation_it = operations.find(op);
    if(operation_it != operations.end())
    {
        std::cout << operation_it->second.visit(sv::static_visitor{}) << "\n";
    }
    else
    {
        std::cout << "provided not supported operation"
                  << "\n";
    }

    return 0;
}