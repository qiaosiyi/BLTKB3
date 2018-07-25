#ifndef _APPEND_H_
#define _APPEND_H_

// length of name not longer than 32 B
#define BLT_NAME	"BLT-KB"

typedef struct _KEY_COMB
{
    unsigned char key;
    unsigned char comb;
}KEY_COMB;

void print_google(void);
void print_baidu(void);
void print_126(void);

#endif
