/********************************************************************
Engineer        : OmarElsobkey
Version         : 1.0
Date            : 6/2/2021
********************************************************************/

#include <util/delay.h>
#include "KPD.h"

const u8 KPD_SwitchValue[4][4] = KPD_Keys;

const u8 KPD_Rows[] = {R1, R2, R3, R4};
const u8 KPD_Cols[] = {C1, C2, C3, C4};

void kpd_init(void) {
    write_port_direction(KPD_PORT, 0x0f);
    clr_port_value(KPD_PORT);
}

u8 kpd_get_char(void) {
    for(u8 row = 0; row < 4; row++){
        set_pin_value(KPD_PORT, KPD_Rows[row]); // send high to the row

        for(u8 col = 0; col < 4; col++){
            if(get_pin_value(KPD_PORT, KPD_Cols[col])){
                _delay_ms(20); // for bouncing

                while(get_pin_value(KPD_PORT, KPD_Cols[col]));

                return KPD_SwitchValue[row][col];
            }
        }
        clr_pin_value(KPD_PORT, KPD_Rows[row]); // send low to the row
    }
    return 0;
}