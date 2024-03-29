#ifndef APP_AUDIO_TRACK_H_
#define APP_AUDIO_TRACK_H_

#include "patterns.h"

#include "wavetables/wavetable_Bank.h"
#include <zic_synth_wavetable.h>
#include <zic_seq_loop.h>

class App_Audio_Track
{
public:
    uint8_t id = 0;

    Zic_Synth_Wavetable synth;
    Zic_Seq_Loop looper;

    App_Audio_Track(uint8_t _id = 0) : synth(&wavetable_Bank), looper(&patterns[2])
    {
        id = _id;
    }

    void next()
    {
        looper.next();
        Zic_Seq_Step *stepOff = looper.getNoteOff();
        Zic_Seq_Step *stepOn = looper.getNoteOn();
        if (stepOff)
        {
            synth.asr.off();
        }
        if (stepOn)
        {
            synth.wave.setFrequency(NOTE_FREQ[stepOn->note]);
            synth.asr.on();
        }
    }
};

#endif