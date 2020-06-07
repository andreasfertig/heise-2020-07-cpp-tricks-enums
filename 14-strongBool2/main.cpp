// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

void OpenFile() {}
#define STRONG_BOOL(name)                                                 \
    enum class name : bool                                                \
    {                                                                     \
        No  = false,                                                      \
        Yes = true                                                        \
    }

STRONG_BOOL(Open);
STRONG_BOOL(Close);
STRONG_BOOL(ReadOnly);

void FileAccess(Open open, Close close, ReadOnly readonly)
{
    if(Open::Yes == open) {
        OpenFile(/* ... */);
    }
}

// ...

void SomeFunction()
{
    FileAccess(Open::Yes, Close::No, ReadOnly::No);
}

int main(){}