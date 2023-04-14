#!/bin/bash

# Check if a filename was provided as an argument
if [ $# -eq 0 ]; then
    echo "Usage: ./cpp_run.sh <source_file>"
    exit 1
fi

# Set source file and executable file names
SOURCE_FILE=$1
EXECUTABLE_FILE="${SOURCE_FILE%.*}_bin"

# Delete the existing compiled binary if it exists
if [ -f "$EXECUTABLE_FILE" ]; then
    echo "Deleting existing binary: $EXECUTABLE_FILE"
    rm "$EXECUTABLE_FILE"
fi

# Compile the source code
echo "Compiling $SOURCE_FILE"
g++ "$SOURCE_FILE" -o "$EXECUTABLE_FILE"

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Running $EXECUTABLE_FILE"
    ./"$EXECUTABLE_FILE"
else
    echo "Compilation failed"
    exit 1
fi