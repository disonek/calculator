#include <argparse/argparse.hpp>
#include <iostream>
#include <string>

#include "abstract_visitor/abstract_visitor.hpp"
#include "static_visitor/static_visitor.hpp"

void calculate_by_abstract_visitor(int leftHand, std::string op, int rightHand)
{
    std::map<std::string, std::unique_ptr<av::expression>> operations{};
    operations.insert({"+", std::make_unique<av::add>()});
    operations.insert({"-", std::make_unique<av::sub>()});
    operations.insert({"*", std::make_unique<av::mul>()});
    operations.insert({"/", std::make_unique<av::div>()});

    std::unique_ptr<av::visitor> visitor = std::make_unique<av::visitor_concrete>(leftHand, rightHand);

    auto operation_it = operations.find(op);
    if(operation_it != operations.end())
    {
        std::cout << "calculated by abstract visitor: " << operation_it->second->accept(visitor) << "\n";
    }
    else
    {
        std::cout << "provided not supported operation"
                  << "\n";
    }
}

void calculate_by_static_visitor(int leftHand, std::string op, int rightHand)
{
    std::map<std::string, sv::operation> operations{
        {"+", sv::add{}}, {"-", sv::sub{}}, {"*", sv::mul{}}, {"/", sv::div{}}};

    auto visitor = sv::static_visitor{leftHand, rightHand};
    auto operation_it = operations.find(op);
    if(operation_it != operations.end())
    {
        std::cout << "calculated by static visitor: " << operation_it->second.visit(visitor) << "\n";
    }
    else
    {
        std::cout << "provided not supported operation"
                  << "\n";
    }
}

void run_in_interactive_mode()
{
    while(true)
    {
        std::string symbols{};
        std::getline(std::cin, symbols);
        std::istringstream iss(symbols);
        std::vector<std::string> vec_of_symbols{};
        std::string striped_symbol{};

        while(std::getline(iss, striped_symbol, ' '))
        {
            vec_of_symbols.push_back(striped_symbol);
        }

        if(vec_of_symbols.size() > 0 && vec_of_symbols.at(0) == "q")
        {
            break;
        }

        if(vec_of_symbols.size() != 3)
        {
            std::cerr << "Invalid number of arguments" << std::endl;
            break;
        }

        try
        {
            int leftHand = std::stoi(vec_of_symbols.at(0));
            std::string op = vec_of_symbols.at(1);
            int rightHand = std::stoi(vec_of_symbols.at(2));
            calculate_by_static_visitor(leftHand, op, rightHand);
            calculate_by_abstract_visitor(leftHand, op, rightHand);
        }
        catch(const std::exception& err)
        {
            std::cerr << err.what() << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("calculator");

    program.add_argument("leftHand").help("left hand of the expression").scan<'i', int>().default_value(0);
    program.add_argument("operator")
        .help("operator allowed are [+,-,/,*], note as your shell can treat them as special charactes so its "
              "recommended to use '*' or \\*")
        .default_value("");
    program.add_argument("rightHand").help("right hand of the expression").scan<'i', int>().default_value(0);

    program.add_description("Example of interactive mode:\n./calculator -i\n./calculator --interactive\n"
                            "Example of one time usage  :\n./calculator 3 '*' 5\n./calculator 3 + 5 \n");

    program.add_argument("-i", "--interactive")
        .help("added flag will run program in interactive mode, to quit type 'q'")
        .default_value(false)
        .implicit_value(true);

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

    if(program.get<bool>("--interactive") == true)
    {
        run_in_interactive_mode();
    }
    else
    {
        auto leftHand = program.get<int>("leftHand");
        std::string op = program.get("operator");
        auto rightHand = program.get<int>("rightHand");
        calculate_by_static_visitor(leftHand, op, rightHand);
        calculate_by_abstract_visitor(leftHand, op, rightHand);
    }
}