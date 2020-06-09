#include "cli.h"
#include "archiver.h"
#include "extractor.h"
#include "actions.h"

int main(int argc, char **argv) {
    ParseArgsResult parseArgsResult = parseArgs(argc - 1, argv + 1);

    if (parseArgsResult.error != 0) {
        handleArgsError(parseArgsResult.error);
        return 0;
    }

    Arguments args = parseArgsResult.result;

    switch (args.action) {
        case PrintHelpAction: {
            printHelp();
            break;
        }
        case ArchiveAction: {
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
