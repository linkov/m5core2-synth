#ifndef APP_VIEW_KEYBOARD_H_
#define APP_VIEW_KEYBOARD_H_

#include <M5Core2.h>

#include "app/app_tracks.h"

#include <zic_note.h>

#include "ui/ui_component.h"
#include "ui/ui_color.h"
#include "ui/ui_key.h"

using namespace Zic;

class App_View_Keyboard : public UI_Component
{
protected:
    App_Tracks *tracks;

    static const uint8_t KEYS_COUNT = 7 * 5;

    UI_Key keys[KEYS_COUNT] = {
        {0, 0, _NOTE_C6}, {45, 0, _NOTE_D6}, {90, 0, _NOTE_E6}, {135, 0, _NOTE_F6}, {180, 0, _NOTE_G6}, {225, 0, _NOTE_A6}, {270, 0, _NOTE_B6}, {0, 45, _NOTE_C5}, {45, 45, _NOTE_D5}, {90, 45, _NOTE_E5}, {135, 45, _NOTE_F5}, {180, 45, _NOTE_G5}, {225, 45, _NOTE_A5}, {270, 45, _NOTE_B5}, {0, 90, _NOTE_C4}, {45, 90, _NOTE_D4}, {90, 90, _NOTE_E4}, {135, 90, _NOTE_F4}, {180, 90, _NOTE_G4}, {225, 90, _NOTE_A4}, {270, 90, _NOTE_B4}, {0, 135, _NOTE_C3}, {45, 135, _NOTE_D3}, {90, 135, _NOTE_E3}, {135, 135, _NOTE_F3}, {180, 135, _NOTE_G3}, {225, 135, _NOTE_A3}, {270, 135, _NOTE_B3}, {0, 180, _NOTE_C2}, {45, 180, _NOTE_D2}, {90, 180, _NOTE_E2}, {135, 180, _NOTE_F2}, {180, 180, _NOTE_G2}, {225, 180, _NOTE_A2}, {270, 180, _NOTE_B2}};

public:
    App_View_Keyboard(App_Tracks *_tracks)
    {
        tracks = _tracks;
    }

    void render()
    {
        M5.Lcd.fillScreen(UI_BACKGROUND);
        for (uint8_t k = 0; k < KEYS_COUNT; k++)
        {
            keys[k].render();
        }
    }

    uint8_t update(Event &e)
    {
        // Serial.printf("Update keyboard %d %d %s\n", e.to.x, e.to.y, e.typeName());
        for (uint8_t k = 0; k < KEYS_COUNT; k++)
        {
            if (keys[k].update(e))
            {
                if (keys[k].isOn)
                {
                    tracks->synth->wave.setFrequency(NOTE_FREQ[keys[k].value]);
                    tracks->synth->asr.on(keys[k].value);
                    // Serial.printf("Play note %d on track %d\n", keys[k].value, tracks->track->id);
                }
                else
                {
                    tracks->synth->asr.nextOff(keys[k].value);
                }
            }
        }
        return false;
    }
};

#endif