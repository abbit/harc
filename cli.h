//
// Created by Abbit on 25/05/2020.
//

#ifndef HARC_CLI_H
#define HARC_CLI_H

typedef enum {
    InvalidAction = -1,
    NoneAction = 0,
    ArchiveAction,
    ExtractAction,
    DeleteAction,
    LookAction,
    CheckAction,
    PrintHelpAction,
} Action;

typedef enum {
    NoneArgsError = 0, // handle situation with no errors
    NoArchivePathArgsError,
    InvalidActionArgsError,
} ArgsError;


typedef struct {
    Action action;

    char *archivePath;
    char **fileNameList;
    int fileNameListLength;
} Arguments;

typedef struct {
    ArgsError error;
    Arguments result;
} ParseArgsResult;

Action parseAction(char *command);

ParseArgsResult parseArgs(int argc, char **argv);

void handleArgsError(ArgsError err);

void printHelp();

#endif //HARC_CLI_H
