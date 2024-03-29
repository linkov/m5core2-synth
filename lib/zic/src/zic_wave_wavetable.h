#ifndef ZIC_WAVE_WAVETABLE_H_
#define ZIC_WAVE_WAVETABLE_H_

#include "zic_wave_base.h"
#include "zic_wavetable_base.h"

class Zic_Wave_Wavetable : public Zic_Wave_Base
{
protected:
    // FIXME still out of tune
    int16_t sample(uint32_t *_freq)
    {
        int i = (FREQ_PI * (*_freq) * time + phase) * sampleCount;
        // return table[i % sampleCount];
        return table[((i % sampleCount) + pos) % size];
    }

public:
    int16_t *table = NULL;
    uint16_t sampleCount = 0;
    uint16_t size = 0;
    uint16_t pos = 0;

    Zic_Wave_Wavetable()
    {
        // This might be dangerous!!
    }

    Zic_Wave_Wavetable(Zic_Wavetable_Base *wavetable)
    {
        set(wavetable);
    }

    void set(Zic_Wavetable_Base *wavetable)
    {
        table = wavetable->table;
        size = wavetable->size;
        sampleCount = wavetable->sampleCount;
    }
};

#endif
