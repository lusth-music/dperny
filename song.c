#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "piano-bright"

#define SONGFILE "song.rra"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "song";
char *PROGRAM_VERSION = "0.0.1";

static int last = 0;

static void verse(int instrument,int octave) {
  b(1,W,instrument,octave,"x--","-x-","--x",SX);
  c(6,W,instrument,octave-1);
  ci2(4,W,instrument,octave-1);
  ci2(5,W,instrument,octave-1);
}

int main() {
    int instrument;
    int octave = 4;

    songInit();

    instrument = readScale(dir,base);

    setTempo(250);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput(SONGNAME,0,0);

    verse(instrument,octave);
    last = 1;
    verse(instrument,octave);

    closeOutput();

    return 0;
}
