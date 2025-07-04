#include <iostream>
#include <fstream>
#include <string>
#include "cxxopts.hpp"
#include "lib.h"

// A simple slugify function
std::string slugify(const std::string& str) {
    std::string slug;
    for (char c : str) {
        if (std::isalnum(c)) {
            slug += std::tolower(c);
        } else if (c == ' ') {
            slug += '-';
        }
    }
    return slug;
}

int main(int argc, char** argv) {
    cxxopts::Options options("blog-cli", "A simple blog post generator");

    options.add_options()
        ("t,title", "Post title", cxxopts::value<std::string>())
        ("a,author", "Post author", cxxopts::value<std::string>())
        ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    Post post;
    post.title = result["title"].as<std::string>();
    post.author = result["author"].as<std::string>();
    post.content = "This is a placeholder for the blog post content.";

    std::string markdown = create_post(post);
    std::string file_name = slugify(post.title) + ".md";

    std::ofstream out_file(file_name);
    out_file << markdown;
    out_file.close();

    std::cout << "Successfully generated blog post: " << file_name << std::endl;

    return 0;
}