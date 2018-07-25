#ifndef __KEY_H
#define __KEY_H

#include "sys.h"
#include "stm32f10x.h"

// 按行扫描读取按键
#define COL0	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)
#define COL1	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)
#define COL2	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define COL3	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define COL4	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define COL5	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)
#define COL6	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)
#define COL7	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)

#define ROW0_1	GPIO_SetBits(GPIOB,GPIO_Pin_0)
#define ROW0_0	GPIO_ResetBits(GPIOB,GPIO_Pin_0)

#define ROW1_1	GPIO_SetBits(GPIOB,GPIO_Pin_1)
#define ROW1_0	GPIO_ResetBits(GPIOB,GPIO_Pin_1)

#define ROW2_1	GPIO_SetBits(GPIOB,GPIO_Pin_3)
#define ROW2_0	GPIO_ResetBits(GPIOB,GPIO_Pin_3)

#define ROW3_1	GPIO_SetBits(GPIOB,GPIO_Pin_4)
#define ROW3_0	GPIO_ResetBits(GPIOB,GPIO_Pin_4)

#define ROW4_1	GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define ROW4_0	GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define ROW5_1	GPIO_SetBits(GPIOB,GPIO_Pin_6)
#define ROW5_0	GPIO_ResetBits(GPIOB,GPIO_Pin_6)

#define ROW6_1	GPIO_SetBits(GPIOB,GPIO_Pin_7)
#define ROW6_0	GPIO_ResetBits(GPIOB,GPIO_Pin_7)

#define ROW7_1	GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define ROW7_0	GPIO_ResetBits(GPIOB,GPIO_Pin_8)

#define ROW8_1	GPIO_SetBits(GPIOB,GPIO_Pin_9)
#define ROW8_0	GPIO_ResetBits(GPIOB,GPIO_Pin_9)

#define AT_1	GPIO_SetBits(GPIOC,GPIO_Pin_14)
#define AT_0	GPIO_ResetBits(GPIOC,GPIO_Pin_14)

#define CLEAR_1	GPIO_SetBits(GPIOC,GPIO_Pin_15)
#define CLEAR_0	GPIO_ResetBits(GPIOC,GPIO_Pin_15)

enum _KeyValue
{
    key_a=0x4, key_b, key_c, key_d, key_e, key_f, key_g,
    key_h, key_i, key_j, key_k, key_l, key_m, key_n,
    key_o, key_p, key_q, key_r, key_s, key_T,
    key_u, key_v, key_w, key_x, key_y, key_z,
    key_1, key_2, key_3, key_4, key_5, key_6, key_7, key_8, key_9, key_0,
    key_enter, key_esc, key_backspace, key_tab, key_spacebar, key_minus, key_equal,
    key_brace1, key_brace2, key_backslash, key_wave, key_semicolon,
    key_quotation_mark, key_grave, key_comma, key_full_stop, key_slash, key_caps_lock,
    key_F1, key_F2, key_F3, key_F4, key_F5, key_F6, key_F7, key_F8, key_F9, key_F10, key_F11, key_F12,
    key_print_screen, key_scroll_lock, key_pause, key_insert, key_home, key_page_up, key_delete, key_end, key_page_down,
    key_right, key_left, key_down, key_up, key_num_lock, key_divide, key_multiply, key_minus2, key_plus, key_enter2,
    key_1n, key_2n, key_3n, key_4n, key_5n, key_6n, key_7n, key_8n, key_9n, key_0n,
    key_dot=0x63, key_app=0x65, key_menu=0x76, key_at=0xce,
};

enum KeyApp
{
    mute=0x7f, vol_up=0x80, vol_down=0x81,
    R_FN=0xa5, L_FN, R_APP, L_APP, APP_START,
    APP_1, APP_2, APP_3, APP_4, APP_5, APP_6, APP_7, APP_8, APP_9, APP_0,
    APP_A, APP_S, APP_X, APP_G, APP_B, APP_N,
    APP_END,
    R_Gui=0x80, R_Alt=0x40, R_Shi=0x20, R_Ctl=0x10, L_Gui=0x08, L_Alt=0x04, L_Shi=0x02, L_Ctl=0x01,
};


void KEY_Init(void);    //IO初始化
u8 KEY_Scan(u8);        //按键扫描函数		
void ESC_KEY_DOWN(void);
void ESC_KEY_UP(void);
void low_power(void);
void change_mode(void);
void clear(void);
void pair(void);

void setrow0_0(void);
void setrow0_1(void);
void setrow1_1(void);
void setrow2_1(void);
void setrow3_1(void);
void setrow4_1(void);
void setrow5_1(void);
void setrow6_1(void);
void setrow7_1(void);
void setrow8_1(void);
void setrow9_1(void);

u8 app_fnc(u8);			//自定义app组合
u8 fn_fnc(u8);			//自定义fn组合
u8 read_inputdata(void);//读入一行
u8 *Read_KeyValue(void);//扫描键盘，过滤抖动，检测按键变动，并返回前六个按下的按键的位置
u8 *map_2_key(u8*);		//根据键盘布局，将位置翻译为按键意义，并做 fn 咿 app  组合键的处理
u8 send_key(void);		//组合数据报文给蓝牙模块发送数捿
u8* check_cmd(u8 *str);
u8 send_cmd(u8 *cmd,u8 *ack,u16 waittime);

#endif
