#ifndef __INCLUDED_KARMA_CHANNEL_H
#define __INCLUDED_KARMA_CHANNEL_H

#include "program.h"
#include "note.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char data[3];
	long deltaFrames;
} karma_Event;

#define MAX_NOTES 10
#define MAX_EVENTS 10

typedef __declspec(align(32)) struct {
	char active;
	int playing_notes;
	int events;

	int panl;
	int panr;

	int *leftEcho;
	int *rightEcho;
	int echoPos;
	int echoSamples;


	karma_Program program;
	karma_Note note[MAX_NOTES];
	karma_Event event[MAX_EVENTS];
} karma_Channel;

void karma_Channel_init(karma_Channel *channel);
void karma_Channel_free(karma_Channel *channel);
void karma_Channel_process(karma_Channel *channel, int *left, int *right, long sampleFrames);
void karma_Channel_noteOn(karma_Channel *channel, long note, long velocity, long delta);
void karma_Channel_noteOff(karma_Channel *channel, long note);

void karma_Channel_processEvent(karma_Channel *channel, karma_Event *event);
void karma_Channel_addEvent(karma_Channel *channel, karma_Event *event);

void karma_Channel_allNotesOff(karma_Channel *channel);

#ifdef __cplusplus
}
#endif


#endif