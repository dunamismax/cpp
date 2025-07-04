#include <iostream>
#include <httplib.h>

int main() {
    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("<h1>Welcome to the C++ HTTP Server!</h1><p>This is a simple landing page.</p>", "text/html");
    });

    svr.Post("/api", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"message\": \"This is a POST request to /api\"}", "application/json");
    });

    std::cout << "Server started at http://localhost:3000" << std::endl;
    svr.listen("localhost", 3000);

    return 0;
}
