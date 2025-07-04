#pragma once

#include <string>

struct Post {
    std::string title;
    std::string author;
    std::string content;
};

std::string create_post(const Post& post);
