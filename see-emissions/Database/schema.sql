CREATE TABLE IF NOT EXISTS Polluters (
    polluterid          TEXT PRIMARY KEY,
    pollutername        TEXT NOT NULL,
    emitType            TEXT NOT NULL,
    amount              INTEGER NOT NULL
)