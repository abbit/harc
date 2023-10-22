# harc

A primitive archiver ulitity based on Huffman coding.
Written as a final project for the course "Introduction to Programming".

## Prerequisites

- C compiler
- Make

## Build

```bash
$ make
```

this will create the executable `harc` in the `bin` directory.

## Usage

```bash
$ bin/harc
 __    __       ___      .______        ______
|  |  |  |     /   \     |   _  \      /      |
|  |__|  |    /  ^  \    |  |_)  |    |  ,----'
|   __   |   /  /_\  \   |      /     |  |
|  |  |  |  /  _____  \  |  |\  \----.|  `----.
|__|  |__| /__/     \__\ | _| `._____| \______|

harc is an archiver that you can use in order to compress your files

USAGE:
    harc [ACTION]

ACTIONS:
    -a <archive_path> <file_paths>...    Archive given file(s) in an archive and saves it with given path.
    -x <archive_path>                    Extract file(s) from an archive.
    -d <archive_path> <file_names>...    Detele file(s) from an archive
    -l <archive_path>                    Print an information about file(s) in an archive
    -t <archive_path>                    Check an integrity if an archive

EXAMPLES:
    harc -a my_archive.hrc plot.txt banner.png contract.pdf
    harc -x my_archive.hrc

```
