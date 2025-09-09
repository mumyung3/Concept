# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

```bash
# Build from the same directory where the .cpp file is located
# Always creates executables in ./executables/ relative to the source file location

# Navigate to the source directory first
cd 2025-09-09

# Ensure executables directory exists in source file directory
mkdir -p executables

# Compile C++ program (basic)
g++ -o executables/main main.cpp

# Compile with warnings (recommended)
g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -o executables/main main.cpp

# Compile specific example files (replace FILENAME with actual file name without .cpp extension)
g++ -std=c++11 -pthread -o executables/FILENAME FILENAME.cpp

# Run the program (from source directory)
./executables/main

# Run specific example
./executables/FILENAME
```

## Project Structure

```
/mnt/d/CodingTest/Concept/
├── 2025-09-09/                    # Date-organized folder for example files
│   ├── executables/               # Compiled executable files
│   └── *.cpp                     # C++ source files (examples and main.cpp)
├── summary/                       # Session summaries and learning notes
├── CLAUDE.md                      # Project configuration (this file)
└── README.md                      # Project description
```

This is a C++ concept learning project with:
- `main.cpp`: Entry point containing the main function
- Example files: Various C++ concept demonstration files
- `executables/`: All compiled binaries go here automatically
- VSCode C++ Runner configuration with extensive warning flags enabled for code quality

## Build Configuration

**Default Output Directory**: All compiled executables will be placed in `./executables/` folder relative to the source file location
- Always work from the directory containing the .cpp files (2025-09-09/)
- Create `./executables/` in the same directory as source files
- Automatically creates the directory if it doesn't exist
- Keeps source and binaries organized together
- Use relative path `./executables/FILENAME` for output

## Session Summary Instructions

When a discussion session about related questions ends, create a summary file in the `summary` folder with the following format:
- Filename: `YYYY-MM-DD_HHMMSS_topic.md` (e.g., `2025-01-09_143022_compiler_concepts.md`)
- Content should include:
  - Main topics discussed
  - Key concepts explained
  - Code examples provided
  - Important insights or conclusions
  - Any follow-up questions or areas for further exploration