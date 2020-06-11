#include <stdlib.h>

#include "cli.h"
#include "archiver.h"
#include "extractor.h"
#include "actions.h"
#include "files.h"

void checkArchivePath(Arguments args) {
    if (((args.action == ExtractAction) ||
         (args.action == LookAction) ||
         (args.action == DeleteAction) ||
         (args.action == CheckAction)) &&
        !isFileExists(args.archivePath)) {
        printf("Such archive doesn't exist! Please, provide valid archive path\n");
        exit(0);
    }
}

void checkFilePaths(Arguments args) {
    for (int i = 0; i < args.fileNameListLength; ++i) {
        if (!isFileExists(args.fileNameList[i])) {
            printf("File %s doesn't exist! Please, provide valid path for file\n", args.fileNameList[i]);
            exit(0);
        }
    }
}


int main(int argc, char **argv) {
    ParseArgsResult parseArgsResult = parseArgs(argc - 1, argv + 1);

    if (parseArgsResult.error != 0) {
        handleArgsError(parseArgsResult.error);
        return 0;
    }

    Arguments args = parseArgsResult.result;

    checkArchivePath(args);

    switch (args.action) {
        case PrintHelpAction: {
            printHelp();
            break;
        }
        case ArchiveAction: {
            checkFilePaths(args);
            archive(args.fileNameList, args.fileNameListLength, args.archivePath);
            break;
        }
        case ExtractAction: {
            extract(args.archivePath);
            break;
        }
        case DeleteAction: {
            deleteFiles(args.archivePath);
            break;
        }
        case LookAction: {
            getActhiveInfo(args.archivePath);
            break;
        }
        case CheckAction: {
            validateArchive(args.archivePath);
            break;
        }
        default:
            break;
    }

    return 0;
}
