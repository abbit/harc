#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    InvalidAction = -1,
    NoneAction = 0,
    ArchiveAction,
    ExtractAction,
    DeleteAction,
    LookAction,
    CheckAction,
} Action;

typedef enum {
    NoneArgsError = 0,
    NoArchivePathArgsError,
    InvalidActionArgsError,
} ArgsError;

typedef struct {
    ArgsError error;

    Action action;

    bool printHelp;

    char *archivePath;
    char **fileNameList;
    int fileNameListLength;
} Arguments;

Action parseAction(char *command) {
    Action action;

    if (command[0] != '-') {
        action = NoneAction;
        return action;
    }

    if(strlen(command + 1) != 1) {
        action = InvalidAction;
        return action;
    }

    switch (command[1]) {
        case 'a': {
            action = ArchiveAction;
            break;
        }

        case 'x': {
            action = ExtractAction;
            break;
        }

        case 'd': {
            action = DeleteAction;
            break;
        }

        case 'l': {
            action = LookAction;
            break;
        }

        case 't': {
            action = CheckAction;
            break;
        }

        default: {
            action = InvalidAction;
            break;
        }
    }

    return action;
}

Arguments parseArgs(int argc, char **argv) {
    const int fileNamesOffset = 2;

    Arguments args = {
            .error = NoneArgsError,
            .action = NoneAction,
            .printHelp = false,
            .archivePath= NULL,
            .fileNameList = NULL,
            .fileNameListLength = 0,
    };

    if (argc == 0) {
        args.printHelp = true;
        return args;
    }

    args.action = parseAction(argv[0]);
    if (args.action == InvalidAction) {
        args.error = InvalidActionArgsError;
        return args;
    }

    if (argc == 1) {
        args.error = NoArchivePathArgsError;
        return args;
    }

    args.archivePath = argv[1];

    args.fileNameListLength = argc - fileNamesOffset;

    if (args.fileNameListLength > 0) {
        args.fileNameList = (char **) calloc(args.fileNameListLength, sizeof(char *));
        for (int i = 0; i < args.fileNameListLength; ++i) {
            args.fileNameList[i] = argv[i + fileNamesOffset];
        }
    }

    return args;
}

void handleArgsError(ArgsError err) {
    switch (err) {
        case InvalidActionArgsError: {
            printf("Invalid action\n");
            break;
        }

        case NoArchivePathArgsError: {
            printf("Archive's path is not provided! Please, provide a path for archive\n");
            break;
        }

        default: {
            printf("Unknown arguments error\n");
            break;
        }
    }
}

void printHelp() {
    printf(" __    __       ___      .______        ______ \n"
           "|  |  |  |     /   \\     |   _  \\      /      |\n"
           "|  |__|  |    /  ^  \\    |  |_)  |    |  ,----'\n"
           "|   __   |   /  /_\\  \\   |      /     |  |     \n"
           "|  |  |  |  /  _____  \\  |  |\\  \\----.|  `----.\n"
           "|__|  |__| /__/     \\__\\ | _| `._____| \\______|\n"
           "\n"
           "harc is an archiver that you can use in order to compress your files\n"
           "\n"
           "USAGE:\n"
           "    harc [ACTION]\n"
           "\n"
           "ACTIONS:\n"
           "    -a <archive_path> <file_paths>...    Archive given file(s) in an archive and saves it with given path.\n"
           "    -x <archive_path>                    Extract file(s) from an archive.\n"
           "    -d <archive_path> <file_names>...    Detele file(s) from an archive\n"
           "    -l <archive_path>                    Print an information about file(s) in an archive\n"
           "    -t <archive_path>                    Check an integrity if an archive\n"
           "\n"
           "EXAMPLES:\n"
           "    harc -a my_archive.hrc plot.txt banner.png contract.pdf\n"
           "    harc -x my_archive.hrc\n"
           "\n"
           );
}

int main(int argc, char **argv) {
    Arguments args = parseArgs(argc - 1, argv + 1);

    if (args.error != 0) {
        handleArgsError(args.error);
        return 0;
    }

    if (args.printHelp) {
        printHelp();
        return 0;
    }

    return 0;
}
