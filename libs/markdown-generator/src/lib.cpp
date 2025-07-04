#include "lib.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string create_post(const Post& post) {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d");
    std::string date = ss.str();

    std::stringstream markdown;
    markdown << "---" << std::endl;
    markdown << "title: " << post.title << std::endl;
    markdown << "author: " << post.author << std::endl;
    markdown << "date: " << date << std::endl;
    markdown << "---" << std::endl;
    markdown << std::endl;
    markdown << post.content << std::endl;

    return markdown.str();
}
