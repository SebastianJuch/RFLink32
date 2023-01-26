#define VONDOM_PLUGIN_ID 018
#define PLUGIN_DESC_018 "Vondom remote controlled RGBW Lights"

#define PLUGIN_018_DEBUG

#define PLUGIN_018_PREAMBLE     4200
#define PLUGIN_018_PREAMBLE_MIN 4100
#define PLUGIN_018_PREAMBLE_MAX 4600

#ifdef PLUGIN_018
#include "../4_Display.h"
//#include "../1_Radio.h"
#include "../7_Utils.h"

#define PLUGIN_018_ID "Vondom"

const int VONDOM_PulseCount_Button_1 = 160;
const int VONDOM_BitCount = 8;

//const int8_t VONDOM_CodeCount = 8;
//const uint16_t VONDOM_OnCodes[SLVCR_CodeCount] = {0xf756, 0x7441, 0xd9c5, 0xe3aa, 0x6af3, 0x453f, 0x0f6e, 0xc170};
//const uint16_t VONDOM_OffCodes[SLVCR_CodeCount] = {0x20e7, 0x5212, 0x9d88, 0x8c0b, 0x16bc, 0x3b99, 0xb8dd, 0xae24};


boolean Plugin_018(byte function, const  char *string)
{
    const  int VONDOM_MinPulses = 450;
    const  int VONDOM_MaxPulses = 600;

    //if (RawSignal.Number >= VONDOM_MinPulses && RawSignal.Number <= VONDOM_MaxPulses)
    if (RawSignal.Number >= VONDOM_PulseCount_Button_1)
    {
        Serial.print("Found 160 Pulses \n");
        
        unsigned long duration = ((unsigned long)RawSignal.Pulses[1])*RawSignal.Multiply;
        if(duration <= PLUGIN_018_PREAMBLE_MIN || duration >= PLUGIN_018_PREAMBLE_MAX) 
            {
                #ifdef PLUGIN_018_DEBUG
                    Serial.print("failed on check2 duration=");
                    Serial.print(RawSignal.Pulses[1]);
                    Serial.print("  multiply=");Serial.println(duration);
                #endif
            return false;
            }

        //const int VONDOM_StartPulseDuration = 4200 / RawSignal.Multiply;
        //const int VONDOM_LongPulseMinDuration = 900 / RawSignal.Multiply;
        //const int VONDOM_LongPulseMaxDuration = 1400 / RawSignal.Multiply;
        //const int VONDOM_ShortPulseMinDuration = 200 / RawSignal.Multiply;
        //const int VONDOM_ShortPulseMaxDuration = 600 / RawSignal.Multiply;
        //const int VONDOM_PulsesCount = VONDOM_BitCount * 2;


    }
}
#endif //PLUGIN_018