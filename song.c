#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"
#include "/usr/local/include/songlib/key.h"


#define dir "/usr/local/share/samples/"
#define base "mandolin/sample_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "song";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

static void verse(int instrument,int octave) {
  startMeasure();

  c(1, Q, instrument, octave);
  c(1, Q, instrument, octave);
  c(1, I, instrument, octave);
  c(1, I, instrument, octave);
  c(1, I, instrument, octave);
  c(1, I, instrument, octave);

  c(6, Q, instrument, octave);
  c(6, Q, instrument, octave);
  c(6, Q, instrument, octave);
  c(6, Q, instrument, octave);

  c(4, Q, instrument, octave);
  c(4, Q, instrument, octave);
  c(4, Q, instrument, octave);
  c(4, Q, instrument, octave);

  c(5, Q, instrument, octave);
  c(5, Q, instrument, octave);
  c(5, Q, instrument, octave);
  c(5, Q, instrument, octave);
  // c(1, W, instrument, octave);

  checkMeasure();
}

int main() {
  int instrument;
  int octave = 1;

  setKey(G);

  songInit();

  instrument = readScale(dir,base);

  setTempo(250);
  setTime(4,4);
  setStride(0.05);
  setSustain(0.99995);
  setAmplitude(0.3);

  openOutput("song.rra",0,0);

  verse(instrument,octave);
  last = 1;
  verse(instrument,octave);

  closeOutput();

  return 0;
}
