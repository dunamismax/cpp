#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    std::string api_key = std::getenv("OPENWEATHERMAP_API_KEY");
    if (api_key.empty()) {
        std::cerr << "OPENWEATHERMAP_API_KEY must be set." << std::endl;
        return 1;
    }

    std::cout << "Please enter your zip code: ";
    std::string zip_code;
    std::cin >> zip_code;

    std::string url = "http://api.openweathermap.org/data/2.5/weather?zip=" + zip_code + "&appid=" + api_key + "&units=metric";

    cpr::Response r = cpr::Get(cpr::Url{url});

    if (r.status_code == 200) {
        json j = json::parse(r.text);
        std::cout << "\nWeather in " << j["name"] << ":" << std::endl;
        std::cout << "  Description: " << j["weather"][0]["description"] << std::endl;
        std::cout << "  Temperature: " << j["main"]["temp"] << "°C" << std::endl;
        std::cout << "  Humidity: " << j["main"]["humidity"] << "%" << std::endl;
        std::cout << "  Wind Speed: " << j["wind"]["speed"] << " m/s" << std::endl;
    } else {
        std::cerr << "\nError: Unable to fetch weather data. Status: " << r.status_code << std::endl;
    }

    return 0;
}