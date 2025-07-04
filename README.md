<p align="center">
  <img src="https://github.com/dunamismax/cpp/blob/90921f413d8f01dfdb70f7d5bb78ae81f121468c/LLVMWyvernSmall.png" alt="C++ Monorepo logo" width="250"/>
</p>

Welcome to my C++ Monorepo. This repository centralizes diverse C++ applications and libraries, designed for efficient, scalable, and maintainable project management using CMake.

[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/dunamismax/cpp/blob/main/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](https://github.com/dunamismax/cpp/pulls)
[![GitHub Stars](https://img.shields.io/github/stars/dunamismax/cpp)](https://github.com/dunamismax/cpp/stargazers)

---

## Overview

This monorepo serves as a centralized hub for various C++ projects. It leverages CMake to manage multiple projects within a single repository, ensuring consistent dependency management and simplified build processes.

### Target Architectures

All code in this repository primarily targets **macOS (Clang, ARM64/AArch64 - M4 Pro)** for development, testing, and execution. **Linux (x86_64)** is a secondary target.

---

## Repository Structure

```sh
cpp/
├── apps/
│   ├── blog-cli/
│   │   ├── CMakeLists.txt
│   │   └── src/main.cpp
│   ├── http-server/
│   │   ├── CMakeLists.txt
│   │   └── src/main.cpp
│   └── weather-cli/
│       ├── CMakeLists.txt
│       └── src/main.cpp
│
├── libs/
│   └── markdown-generator/
│       ├── CMakeLists.txt
│       └── src/
│           ├── lib.cpp
│           └── lib.h
│
├── tools/
│   └── link-checker/
│       ├── CMakeLists.txt
│       └── src/main.cpp
│
├── .gitignore
├── CMakeLists.txt          # Root workspace configuration
├── LICENSE
└── README.md
```

---

## Projects Overview

This monorepo hosts several applications, libraries, and tools.

### Applications

- **[HTTP Server](https://github.com/dunamismax/cpp/blob/main/apps/http-server/src/main.cpp)**: A lightweight, asynchronous HTTP server built with **cpp-httplib**. It demonstrates handling basic GET and POST requests, serving a simple HTML landing page and a JSON API endpoint.
- **[Weather CLI](https://github.com/dunamismax/cpp/blob/main/apps/weather-cli/src/main.cpp)**: A command-line weather application that fetches and displays the current weather for a specified city. It uses the OpenWeatherMap API and requires an API key to be set as an environment variable.
- **[Blog Post Generator](https://github.com/dunamismax/cpp/blob/main/apps/blog-cli/src/main.cpp)**: A command-line application for generating simple markdown blog posts from a template. It leverages the `markdown-generator` library to create the post content.

### Libraries

- **[Markdown Generator](https://github.com/dunamismax/cpp/blob/main/libs/markdown-generator/src/lib.h)**: A reusable library for creating markdown content. It provides a `Post` struct and a function to generate a formatted markdown string from post data.

### Tools

- **[Link Checker](https://github.com/dunamismax/cpp/blob/main/tools/link-checker/src/main.cpp)**: A developer tool that scans markdown files and checks for broken or invalid URLs, helping to ensure the quality of documentation and blog posts.

---

## How to Compile and Run

This project uses **CMake** to compile and run all projects in the workspace.

### Build All Crates

To build all applications and libraries, run the `cmake` and `make` commands from the project root, after creating and navigating into the `build` directory.

```bash
# Configure and build for development
mkdir build
cd build
cmake ..
make

# Configure and build for production
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### Run Applications

Once built, you can run the applications from the `cpp/build` directory.

```bash
# Run the HTTP server
# It will be available at http://localhost:3000
./apps/http-server/http-server

# Run the weather CLI
# First, set the OPENWEATHERMAP_API_KEY environment variable
export OPENWEATHERMAP_API_KEY="your_api_key"
./apps/weather-cli/weather-cli

# Generate a new blog post
./apps/blog-cli/blog-cli --title "My First Post" --author "dunamismax"

# Check for broken links in a markdown file
./tools/link-checker/link-checker "path/to/your/post.md"
```

### Clean Build Artifacts

To remove all compiled files and build artifacts, run:

```bash
cd cpp/build
make clean
```

---

## Contributing

Contributions are welcome! Please feel free to fork the repository, create a feature branch, and open a pull request.

---

## Connect

Connect with the author, **dunamismax**, on:

- **Twitter:** [@dunamismax](https://twitter.com/dunamismax)
- **Bluesky:** [@dunamismax.bsky.social](https://bsky.app/profile/dunamismax.bsky.social)
- **Reddit:** [u/dunamismax](https://www.reddit.com/user/dunamismax)
- **Discord:** `dunamismax`
- **Signal:** `dunamismax.66`

---

## License

This repository is licensed under the **MIT License**. See the `LICENSE` file for more details.
