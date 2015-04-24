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

  checkMeasure();
}

/*
 * 8 bars
 */
static void prechorus(int instrument, int octave) {

}

/*
 * 6 bars
 */
static void chorus(int instrument, int octave) {
  startMeasure();
  
  checkMeasure();
}

static void bridge(int instrument, int octave) {
  startMeasure();

  checkMeasure();
}

static void intro(int instrument, int octave) {
  int i;
  int j;

  for(j = 0; j < 2; j++) {

    // 1 F#
    for(i = 0; i < 4; i++) {
      n(6,S,instrument, octave-1, 0);
    }

    // 2 A
    for(i = 0; i < 4; i++) {
      n(1,S,instrument, octave,0);
    }

    // 3 B
    for(i = 0; i < 4; i++) {
      n(2,S,instrument, octave, 0);
    }

    // 4 C#
    for(i = 0; i < 4; i++) {
      n(3,S,instrument, octave, 0);
    }

    // 5 E
    for(i = 0; i < 4; i++) {
      n(5,S, instrument, octave, 0);
    }
    
    // 6 F# 
    for(i = 0; i < 4; i++) {
      n(6,S,instrument, octave, 0);
    }
    
    // 7 A
    for(i = 0; i < 4; i++) {
      n(1,S,instrument, octave+1, 0);
    }

    // 8 B
    for(i = 0; i < 4; i++) {
      n(2,S,instrument, octave+1,0);
    }

    // 9 C#
    for(i = 0; i < 4; i++) {
      n(3,S,instrument, octave+1,0);
    }

    // 10 B
    for(i = 0; i < 4; i++) {
      n(2,S,instrument, octave+1,0);
    }

    // 11 A
    for(i = 0; i < 4; i++) {
      n(1,S,instrument, octave+1,0);
    }

    // 12 F#
    for(i = 0; i < 4; i++) {
      n(6,S,instrument, octave,0);
    }

    /*
    for(i = 0; i < 4; i++) {
      n(5,S,instrument, octave,0);
    }
    */

    // 12 13 14 15 B
    for(i = 0; i < 16; i++) {
      n(6,S,instrument, octave,0);
    }
  }
}

int main() {
  int instrument;
  int octave = 4;

  setKey(A);

  songInit();

  instrument = readScale(dir,base);

  setTempo(144);
  setTime(4,4);
  setStride(0.01);
  setSustain(0.99995);
  setAmplitude(0.3);

  openOutput("leadguitar.rra",0,0);

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

  closeOutput();

  return 0;
}
