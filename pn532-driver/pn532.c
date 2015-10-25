#ifndef __SYSTEM__H__
#include "system.h"
#endif

#ifndef PN532_PN532_H
#include "pn532.h"
#endif

int pn532_get_version(unsigned char *ic, unsigned char *ver, unsigned char *rev, unsigned char *support)
{
#ifdef MOCK_P532
    static unsigned char version_buffer[4] = { 0x00, 0xFF, 0x06, 0xFA };
    static unsigned char ack[] = { 0x00, 0x00, 0xff, 0x00, 0xff, 0x00 };
#else
    unsigned char version_buffer[4] = { 0x00, 0x00, 0x00, 0x00 };
    unsigned char ack[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
#endif

    HLPCommandFrame *frame = MAKE_GET_VERSION_FRAME;
    assert(frame);

    int error_code = pn532_write(frame);
    assert(error_code == kNoError);

    unsigned char *response = pn532_read_ack(ack);
    assert(memcmp(ack, response, sizeof(ack)) == 0);

    response = (unsigned char *) pn532_read((char *) version_buffer);

    *ic         = response[0];
    *ver        = response[1];
    *rev        = response[2];
    *support    = response[3];

    return(kNoError);
}

unsigned char *pn532_read_ack(unsigned char *ack) {
#ifdef MOCK_P532
    return(ack);
#else
    // Really read from the device
#endif
}

int pn532_write(HLPCommandFrame *frame)
{
#ifdef MOCK_P532
    return(0);
#else
    // Really write to the device
#endif
}

char *pn532_read(char *read_buffer)
{
#ifdef MOCK_P532
    return(read_buffer);
#else
    // Really read from the device
#endif
}
