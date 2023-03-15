#include "service.h"
#include "repo_undo.h"
#include "repo.h"
#include "console.h"
#include <stdio.h>
#include <time.h>
#include <crtdbg.h>
#include <string.h>
#include "tests.h"
#include <stdlib.h>

int main()
{
    DynamicArray* DA = createDynamicArray(100);
    Repo* repo = createRepo(*DA);
    Repo new_repo;
    init_repo(repo);
    new_repo = duplicate_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, &new_repo);


    Service* service = createService(*repo, *UndoRedo);
    Console* console = createConsole(*service);
    start(console);
    destroy_ui(console);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy_r(repo);
    destroy(DA);

    free(new_repo.array.data);


    testALL(); // the leaks come from here
    _CrtDumpMemoryLeaks();
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);



    return 0;
}