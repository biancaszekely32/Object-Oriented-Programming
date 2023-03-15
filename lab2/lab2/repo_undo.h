#pragma once
#include "repo.h"

typedef struct
{
    Repo* data;
    int count;
    int max_length;
    int current_position;
    int total_operations;

}UndoRepo;


// With this function we create the repository for undo redo
UndoRepo* createUndoRepo(int capacity, Repo* repo);

// With this function we destroy the repository for undo redo
void destroy_ur(UndoRepo* UndoRedo);

// With this function we increase the size of the repository
void resize_ur(UndoRepo* U);

/// With this function we add a new repository to our bigger repository
void add_repo_ur(UndoRepo* U, Repo* repo);

// With this function we execute a redo operation
int RedoOperation(UndoRepo* UndoRedo);

// With this function we execute an undo operation
int UndoOperation(UndoRepo* UndoRedo);