# MP3-tag-reader-and-editor
🎵 MP3 Tag Reader and Editor  --> A simple and efficient C-based MP3 Tag Reader and Editor that allows users to extract and modify metadata tags (ID3v2) from MP3 files. This project is built using C, compiled in VS Code, and demonstrates file handling, bitwise operations, and parsing skills.

**📌 Project Overview**

This project reads metadata from MP3 audio files using the ID3v2 tagging standard. It can extract information such as:
Title
Artist
Album
Year
Genre
Comment
It also provides editing functionality to update selected tags and rewrite them back into the MP3 file.

🎯 Features
✔️ Read ID3v2 tags from any MP3 file
✔️ Edit specific tags (title, artist, album, etc.)
✔️ Display all metadata in a clean format
✔️ Simple command-line interface
✔️ Supports multiple tags in a single run
✔️ Proper error handling for invalid files

**🛠️ Technologies Used**
C programming
VS Code (Development)
File I/O operations
ID3v2 MP3 Metadata Structure
Command-Line Arguments

**Run commands**
give command gcc *.c

To view tags:
./a.out -v sample.mp3

To edit tag (example: title):
./a.out -e -t "New Song Title" sample.mp3
