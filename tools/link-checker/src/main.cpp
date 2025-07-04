#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cpr/cpr.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file.md>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::regex url_regex("[^]]+\)");
    std::smatch match;
    std::vector<std::string> broken_links;

    auto words_begin = std::sregex_iterator(content.begin(), content.end(), url_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string url = match.str(2);
        cpr::Response r = cpr::Get(cpr::Url{url});
        if (r.status_code >= 400) {
            std::cout << "Broken link found: " << url << std::endl;
            broken_links.push_back(url);
        }
    }

    if (broken_links.empty()) {
        std::cout << "No broken links found." << std::endl;
    } else {
        std::cout << "\nFound " << broken_links.size() << " broken links:" << std::endl;
        for (const auto& link : broken_links) {
            std::cout << "- " << link << std::endl;
        }
    }

    return 0;
}