#ifndef __SYSTEM__H__
#include "system.h"
#endif

#ifndef PN532_HLP_H
#include "hlp.h"
#endif

HLPCommandFrame *hlp_alloc_command_frame() {
    HLPCommandFrame *frame = malloc(sizeof(HLPCommandFrame));
    assert(frame);

    return(frame);
}

HLPCommandFrame *hlp_init_command_frame(HLPCommandFrame *frame)
{
    assert(frame);
    memset(frame, 0, sizeof(HLPCommandFrame));

    frame->start_code[1] = 0xff;
    return(frame);
}

HLPCommandFrame *hlp_make_get_version_frame(HLPCommandFrame *frame)
{
    assert(frame);

    frame->payload.tfi = kOutgoingTFI;                              // Direction
    frame->payload.command.command_code = kGetVersionCommandCode;   // Command
    frame->len = sizeof(frame->payload);                            // Length of data in the packet

    frame->lcs = 0xfe;                                              // Pre-calculated checksum on len
    frame->dcs = 0x2a;                                              // Pre-calculated checksum on TFI + data

    return(frame);
}

unsigned char hlp_compute_checksum(unsigned char *data, int length)
{
    assert(data);

    register int sum = 0;

    while(length-- > 0)
    {
        sum += *data++;
    }

    return((unsigned char ) (~sum + 1));
}
