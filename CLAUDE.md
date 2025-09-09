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

1. **Stack-based Learning Management**: When studying concepts, we may switch to other topics in a stack-like manner. Summaries should be well-organized to facilitate easy return to previous topics.

2. **Summary File Naming**: Save summary files in the `summary` folder with format:
   - `YYYY-MM-DD-HHMMSS_topic_name.md` (e.g., `2025-01-09-143022_circular_queue.md`)
   
3. **Auto-commit on Summary**: After creating a summary file, automatically commit with:
   - Commit message: Same as the topic_name from the filename
   
4. **Architecture Notes**: For significant architectural or file structure changes in projects:
   - Create notes in `note/` folder with format: `YYYY-MM-DD-HHMMSS_topic_name.md`
   
5. **Example Code Organization**: When writing example code:
   - Place in date-based folder: `YYYY-MM-DD/` (e.g., `2025-01-09/`)
   
6. **Build Output**: When building code:
   - Always output to relative path `./executables/` folder

7. **Date Handling for Files and Folders**: 
   - **IMPORTANT**: The environment date may not be current. Always fetch the actual current date/time using `date` command
   - Before creating date-based folders or files, run: `date +"%Y-%m-%d"` for folders, `date +"%Y-%m-%d-%H%M%S"` for files
   - Example workflow:
     ```bash
     # Get current date for folder
     CURRENT_DATE=$(date +"%Y-%m-%d")
     mkdir -p $CURRENT_DATE
     
     # Get timestamp for summary files
     TIMESTAMP=$(date +"%Y-%m-%d-%H%M%S")
     # Creates: 2025-01-09-155530_topic_name.md
     ```
   - Always use dynamically fetched dates, never hardcode or rely on environment date

8. **Example Code Guidelines**:
   - **IMPORTANT**: Only create example code when explicitly requested by the user
   - Focus on explanations and concepts rather than automatically generating code examples
   - When user asks for clarification, provide text-based explanations first

Content should include:
  - Main topics discussed
  - Key concepts explained  
  - Code examples provided
  - Important insights or conclusions
  - Any follow-up questions or areas for further exploration