# File System Search

<p align="center">
  <img src="https://github.com/RedheadRusskie/search-c/blob/main/public/search-icon.svg" alt="Logo" width="200" />
</p>

<p align="center">
  A lightweight utility for querying files and directories on Linux/OSX, written in C.
</p>

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)

## Requirements:
- A POSIX-compatible system (Linux or macOS)
- gcc or clang
- make

## Installation

1. **Clone the repository:**

```bash
git clone https://github.com/RedheadRusskie/search-c.git
```

2. **Navigate to the repository's directory:**

```bash
cd search-c
```

</br>

3. You can either:

#### Build and run locally:

```bash
make
```

#### Install globally:

```bash
sudo make install
```

</br>

If installed globally, you can uninstall with:

```bash
sudo make uninstall
```

## Usage:
```bash
search -f <name> [start_path]
OR
./search -f <name> [start_path]
```

```bash
search -d <name> [start_path]
OR
./search -d <name> [start_path]
```

- `-f` — search for files
- `-d` — search for directories
- `start_path` defaults to / if omitted

#### Example:
```bash
search -f test.txt ~/Desktop
OR
./search -f test.txt ~/Desktop
```
