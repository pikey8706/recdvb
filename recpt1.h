/* -*- tab-width: 4; indent-tabs-mode: nil -*- */
#ifndef _RECPT1_H_
#define _RECPT1_H_

#define NUM_BSDEV       8
#define NUM_ISDB_T_DEV  8
#define CHTYPE_SATELLITE    0        /* satellite digital */
#define CHTYPE_GROUND       1        /* terrestrial digital */
#define MAX_QUEUE           8192
#define MAX_READ_SIZE       (188 * 87) /* 188*87=16356 splitterが188アライメントを期待しているのでこの数字とする*/
#define WRITE_SIZE          (1024 * 1024 * 2)
#define TRUE                1
#define FALSE               0
typedef int boolean;
typedef struct _BUFSZ {
    int size;
    u_char buffer[MAX_READ_SIZE];
} BUFSZ;

typedef struct _QUEUE_T {
    unsigned int in;        // 次に入れるインデックス
    unsigned int out;        // 次に出すインデックス
    unsigned int size;        // キューのサイズ
    unsigned int num_avail;    // 満タンになると 0 になる
    unsigned int num_used;    // 空っぽになると 0 になる
    pthread_mutex_t mutex;
    pthread_cond_t cond_avail;    // データが満タンのときに待つための cond
    pthread_cond_t cond_used;    // データが空のときに待つための cond
    BUFSZ *buffer[1];    // バッファポインタ
} QUEUE_T;

typedef struct _SETTINGS {
    boolean use_b25;
    boolean recording;
    boolean use_udp;
    boolean use_http;
    int port_http;
    int port_to;
    boolean use_stdout;
    boolean use_splitter;
    boolean use_lch;
    boolean indefinite;
    char *host_to;
    int dev_num;
    char *sid_list;
    unsigned int tsid;
    char *channel;
    char *preset_channel;
    char *rectime;
    char *destfile;
    char *local_address;
    char *interface;
} SETTINGS;

void * accept_http(void *);

#endif
