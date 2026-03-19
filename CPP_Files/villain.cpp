// Placeholder villain implementation to satisfy build when referenced by the task
// No symbols needed; keep file present so the build system doesn't fail.

#include "villain.h"

// Constructors

Villain::Villain() {
    bounty = 0;
    dangerLevel = 0;
    weakness = "None";
}

// Parameterized constructor

Villain::Villain(int b, int d, string w) : bounty(b), dangerLevel(d), weakness(w) {
    bounty = b;
    dangerLevel = d;
    weakness = w;
}