#include "key.h"
#include "append.h"
#include <stdio.h>
#include "delay.h"

void print_string(KEY_COMB *kc, unsigned char len)
{
    unsigned char i = 0;
    for(; i<len; i++)
    {
    	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 0x0c,0x00,0xa1,0x01,kc[i].comb,0x00,kc[i].key,0x00,0x00,0x00,0x00,0x00);
	    printf("%c%c%c%c%c%c%c%c%c%c%c%c", 0x0c,0x00,0xa1,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);
    }
    delay_ms(300);
}

void print_google()
{
    KEY_COMB text[] = { {key_w, 0}, {key_w, 0}, {key_w, 0}, {key_full_stop, 0}, {key_g, 0}, {key_o, 0}, {key_o, 0}, {key_g, 0}, {key_l, 0}, {key_e, 0}, {key_full_stop, 0}, {key_c, 0}, {key_o, 0}, {key_m, 0} };
    print_string(text, sizeof(text)/sizeof(KEY_COMB));
}

void print_baidu()
{
    KEY_COMB text[] = { {key_w, 0}, {key_w, 0}, {key_w, 0}, {key_full_stop, 0}, {key_b, 0}, {key_a, 0}, {key_i, 0}, {key_d, 0}, {key_u, 0}, {key_full_stop, 0}, {key_c, 0}, {key_o, 0}, {key_m, 0} };
    print_string(text, sizeof(text)/sizeof(KEY_COMB));
}

void print_126()
{
    KEY_COMB text[] = { {key_w, 0}, {key_w, 0}, {key_w, 0}, {key_full_stop, 0}, {key_1, 0}, {key_2, 0}, {key_6, 0}, {key_full_stop, 0}, {key_c, 0}, {key_o, 0}, {key_m, 0} };
    print_string(text, sizeof(text)/sizeof(KEY_COMB));
}

