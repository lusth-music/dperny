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
  int spot, j;
  startMeasure();

  for(j = 0; j < 16; j++) {
    spot = getLocation();
    drumkitKick  (1,1,"X-------X-------", SX); setLocation(spot);
    drumkitSnare (1,1,"----X-------X---", SX); setLocation(spot);
    drumkitHHOpen(1,1,"x---x---x---x---", SX);
    checkMeasure();
  }

  checkMeasure();
}

static void prechorus(int instrument, int octave) {
  int j, spot;
  startMeasure();
  for(j = 0; j < 8; j++) {
    spot = getLocation();
    drumkitKick  (1,1,"X-------X-------", SX); setLocation(spot);
    drumkitSnare (1,1,"----X-------X---", SX); setLocation(spot);
    drumkitHHOpen(1,1,"g---g---g---g---", SX);
    checkMeasure();
  }

  checkMeasure();
}

static void chorus(int instrument, int octave) {
  int spot, j;
  startMeasure();

  for(j = 0; j < 8; j++) {
    spot = getLocation();
    drumkitKick  (1,1,"X-------X-------", SX); setLocation(spot);
    drumkitSnare (1,1,"----X-------X---", SX); setLocation(spot);
    drumkitHHOpen(1,1,"x---x---x---x---", SX);
    checkMeasure();
  }
  
  checkMeasure();
}

static void bridge(int instrument, int octave) {
  startMeasure();
  int j, spot;
  for(j = 0; j < 12; j++) {
    spot = getLocation();
    drumkitKick  (1,1,"X-------X-------", SX); setLocation(spot);
    drumkitSnare (1,1,"----X-------X---", SX); setLocation(spot);
    drumkitHHOpen(1,1,"g---g---g---g---", SX);
    checkMeasure();
  }
  
  checkMeasure();
}

static void end(int instrument, int octave) {
  startMeasure();
  
  checkMeasure();
}

/* 
 * 8 bars
 */
static void intro(int instrument, int octave) {
  startMeasure();
  int spot;
  int j;

  for(j = 0; j < 8; j++) {
    spot = getLocation();
    drumkitKick  (1,1,"X-------X-------", SX); setLocation(spot);
    drumkitSnare (1,1,"----X-------X---", SX); setLocation(spot);
    drumkitHHOpen(1,1,"g---g---g---g---", SX);
    checkMeasure();
  }

  checkMeasure();
}

int main() {
  int instrument;
  int octave = 5;

  setKey(A);

  songInit();

  instrument = readScale(dir,base);

  setTempo(144);
  setTime(4,4);
  setStride(0.05);
  setSustain(0.99995);
  setAmplitude(0.1);

  openOutput("drums.rra",0,0);

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
