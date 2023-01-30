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
    int i;
    //if (RawSignal.Number >= VONDOM_MinPulses && RawSignal.Number <= VONDOM_MaxPulses)
    if (RawSignal.Number >= VONDOM_PulseCount_Button_1)
    {
        unsigned long duration = ((unsigned long)RawSignal.Pulses[1])*RawSignal.Multiply;
        Serial.print(RawSignal.Number);
        Serial.print(" Pulses found \n");
        Serial.print("RawSignal Multiply ");
        Serial.print(RawSignal.Multiply);
        Serial.print("\n");
        Serial.print("Duration");
        Serial.print(duration);
        Serial.print("\n");
        for (i = 1; i < RawSignal.Number + 1; i++)
        {
            bool static start_found = false;
            bool static end_found = false;
            int static pulse_counter = 0; 
            

            unsigned long duration = ((unsigned long)RawSignal.Pulses[i])*RawSignal.Multiply;   
            
            if(duration >= PLUGIN_018_PREAMBLE_MIN || duration <= PLUGIN_018_PREAMBLE_MAX)
            {
                if(start_found)
                {
                   start_found = false;
                   end_found = true;
                }
                Serial.print("Start Found at position ");
                Serial.print(i);
                Serial.print("\n");
                Serial.print(RawSignal.Pulses[i]);

                start_found = true;
            }
            else if(start_found)
            {
                pulse_counter ++;
            }
            else if(end_found)
            {
                Serial.print(pulse_counter);
                Serial.print("Pulses Found between start and stop ");
                end_found = false;
                pulse_counter = 0;

            }



            RFLink::sendRawPrint(RawSignal.Pulses[i] * RawSignal.Multiply);
            if (i < RawSignal.Number)
               RFLink::sendRawPrint(',');
        }
        
        
        /*
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
*/
        //const int VONDOM_StartPulseDuration = 4200 / RawSignal.Multiply;
        //const int VONDOM_LongPulseMinDuration = 900 / RawSignal.Multiply;
        //const int VONDOM_LongPulseMaxDuration = 1400 / RawSignal.Multiply;
        //const int VONDOM_ShortPulseMinDuration = 200 / RawSignal.Multiply;
        //const int VONDOM_ShortPulseMaxDuration = 600 / RawSignal.Multiply;
        //const int VONDOM_PulsesCount = VONDOM_BitCount * 2;


    }
}
#endif //PLUGIN_018