add_executable(weather-cli src/main.cpp)

target_link_libraries(weather-cli PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
