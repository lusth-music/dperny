#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"
#include "/usr/local/include/songlib/key.h"


#define dir "/usr/local/share/samples/"
#define base "guitar-electric/cleanstrat_"
// define base "mandolin/sample_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "song";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

/*
 * 16 bars
 */
static void verse(int instrument,int octave) {
  startMeasure();

  int i;
  int j;
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }

    for(j = 0; j < 8; j++) {
      n(6, Id, instrument, octave-1,0);
      n(6, S, instrument, octave-1,0);
    }
  }

  checkMeasure();
}

/*
 * 8 bars
 */
static void prechorus(int instrument, int octave) {
  startMeasure();

  int i;
  int j;
  // 4 bars
  for(i = 0; i < 2; i++) {
    for(j = 0; j < 2; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }

    for(j = 0; j < 4; j++) {
      n(6, Id, instrument, octave-1,0);
      n(6, S, instrument, octave-1,0);
    }
  }

  // 1 bar
  for(j = 0; j < 2; j++) {
    n(1, Id, instrument, octave,0);
    n(1, S, instrument, octave,0);
    n(1, Id, instrument, octave-1,0);
    n(1, S, instrument, octave-1,0);
  }

  // 1 bar
  for(j = 0; j < 4; j++) {
    n(6, Id, instrument, octave-1,0);
    n(6, S, instrument, octave-1,0);
  }

  // 1 bar
  for(j = 0; j < 4; j++) {
    n(5, Id, instrument, octave-1,0);
    n(5, S, instrument, octave-1,0);
  }
  
  // 1 bar
  for(j = 0; j < 4; j++) {
    n(5, Id, instrument, octave,0);
    n(5, S, instrument, octave,0);
  }

  checkMeasure();
}

/*
 * 6 bars
 */
static void chorus(int instrument, int octave) {
  startMeasure();
  
  int i, j;

  // 2 bars
  for(i = 0; i < 2; i++) {
    // 1 bar
    for(j = 0; j < 2; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }

    // 1 bar
    for(j = 0; j < 4; j++) {
      n(4, Id, instrument, octave,0);
      n(4, S, instrument, octave,0);
    }
  }

  // 2 bars
  for(i = 0; i < 2; i++) {
    // 1 bar
    for(j = 0; j < 2; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }

    // 1 bar
    for(j = 0; j < 4; j++) {
      n(5, Id, instrument, octave-1,0);
      n(5, S, instrument, octave-1,0);
    }
  }

  checkMeasure();
}

/*
 * 12 bars
 */
static void bridge(int instrument, int octave) {
  int i, j;

  // 2 bars
  for(i = 0; i < 2; i++) {
    // 1 bar
    for(j = 0; j < 2; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }

    // 1 bar
    for(j = 0; j < 4; j++) {
      n(6, Id, instrument, octave-1,0);
      n(6, S, instrument, octave-1,0);
    }
  }

  // 2 bars
  for(j = 0; j < 8; j++) {
    n(5, Id, instrument, octave-1,0);
    n(5, S, instrument, octave-1,0);
  }

  // 2 bars
  for(j = 0; j < 8; j++) {
    n(6, Id, instrument, octave-1,0);
    n(6, S, instrument, octave-1,0);
  }

  // 2 bars
  for(j = 0; j < 8; j++) {
    n(5, Id, instrument, octave-1,0);
    n(5, S, instrument, octave-1,0);
  }

  // 1 bar
  for(j = 0; j < 4; j++) {
    n(4, Id, instrument, octave,0);
    n(4, S, instrument, octave,0);
  }

  // 1 bar
  for(j = 0; j < 4; j++) {
    n(5, Id, instrument, octave,0);
    n(5, S, instrument, octave,0);
  }

  checkMeasure();
}

/*
 * 8 bars
 */
static void intro(int instrument, int octave) {
  setAmplitude(0.2);
  startMeasure();

  int i;
  int j;
  for(i = 0; i < 2; i++) {
    for(j = 0; j < 4; j++) {
      n(1, Id, instrument, octave,0);
      n(1, S, instrument, octave,0);
      n(1, Id, instrument, octave-1,0);
      n(1, S, instrument, octave-1,0);
    }
    checkMeasure();

    startMeasure();
    for(j = 0; j < 8; j++) {
      n(6, Id, instrument, octave-1,0);
      n(6, S, instrument, octave-1,0);
    }
    checkMeasure();
  }

  checkMeasure();
  setAmplitude(0.3);
}

static void end(int instrument, int octave) {
  b(1, W, instrument, octave, "x--", "-x-", "--x", "X--", SX);
  n(1, W, instrument, octave,0);
}

int main() {
  int instrument;
  int octave = 4;

  setKey(A);

  songInit();

  instrument = readScale(dir,base);

  setTempo(144);
  setTime(4,4);
  setStride(0.05);
  setSustain(0.99995);
  setAmplitude(0.2);

  openOutput("bass.rra",0,0);

  last = 1;
  intro(instrument,octave);
  verse(instrument,octave);
  prechorus(instrument, octave);
  verse(instrument,octave);
  prechorus(instrument, octave);
  chorus(instrument, octave);
  verse(instrument, octave);
  bridge(instrument, octave);
  chorus(instrument, octave);
  prechorus(instrument, octave);
  end(instrument, octave);

  closeOutput();

  return 0;
}
