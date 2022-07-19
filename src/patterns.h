#ifndef PATTERNS_H_
#define PATTERNS_H_

#include <zic_seq_pattern.h>
#include <zic_note.h>

using namespace Zic;

#define PATTERN_COUNT 25

// NOTE
// Should there be some banks?
// selectable with the lower row of pots
Zic_Seq_Pattern patterns[PATTERN_COUNT] = {
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C3, SLIDE}, {_NOTE_C3}, {0}, {_NOTE_C3}, {END}},
    (Pat){{_NOTE_C3}, {_NOTE_E3}, {_NOTE_F3}, {_NOTE_C3}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
    (Pat){{_NOTE_C4}, {0}, {0}, {0}, {END}},
};

#endif
