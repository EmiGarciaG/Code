#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

#include "splaytree.hpp"

std::istream&
operator>>(std::istream& in, std::vector<int>& v)
{
    size_t size;
    in >> size;
    if (in)
    {
        v.resize(size);
        for (size_t i=0;i<size && in; ++i)
            in >> v[i];
    }
    return in;
}

int
main(int argc, const char* argv[])
{
    int exit_code = EXIT_SUCCESS;
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
            return EXIT_FAILURE;
        }
        std::ifstream input_file (argv[1]);
        if (!input_file)
        {
            std::cerr << "Error: could not open input filename '" << argv[1] << "'." << std::endl;
            std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
            return EXIT_FAILURE;
        }
        std::vector<int> values;
        std::string command;
        SplayTree<int> tree;
        while (input_file >> command )
        {
            if (command == "insert")
            {
                input_file >> values;
                for(size_t i=0; i<values.size(); ++i)
                    tree.insert(values[i]);
            }
            else if (command == "remove")
            {
                input_file >> values;
                for(size_t i=0; i<values.size(); ++i)
                    tree.remove(values[i]);
            }
            else if (command == "search")
            {
                int v;
                input_file >> v;
                std::cout << "Search for " << v
                          << " return "
                          << (tree.search(v) ? "True." : "False.") << std::endl;
            }
            else if (command == "show")
            {
                std::cout << tree << std::endl;
            }
        }
    }
    catch(std::runtime_error &e)
    {
        std::cerr << "Run time exception: " << e.what() << std::endl;
        exit_code = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Catched unknown exception!." << std::endl;
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}

