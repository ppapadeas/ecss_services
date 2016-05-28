#ifndef __EPS_H
#define __EPS_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "services.h"
#include "upsat.h"

//temp
#define TEST_ARRAY 1024

/*restriction for 8 char filename, for conversion from num to file name*/
#define MAX_FILE_NUM 0x5F5E0FF

struct _eps_data
{   

    struct uart_data obc_uart;
};


struct _sys_data {
    uint8_t rsrc;
    uint32_t *boot_counter;
};

extern struct _eps_data eps_data;

extern SAT_returnState export_pkt(TC_TM_app_id app_id, tc_tm_pkt *pkt, struct uart_data *data);

extern SAT_returnState free_pkt(tc_tm_pkt *pkt);

extern SAT_returnState verification_app(tc_tm_pkt *pkt);
extern SAT_returnState hk_app(tc_tm_pkt *pkt);
extern SAT_returnState function_management_app(tc_tm_pkt *pkt);
extern SAT_returnState test_app(tc_tm_pkt *pkt);

SAT_returnState route_pkt(tc_tm_pkt *pkt);

SAT_returnState event_log(uint8_t *buf, const uint16_t size);

SAT_returnState check_timeouts();
#endif
