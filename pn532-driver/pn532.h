//
// Created by Itamar on 10/24/15.
//
#ifndef PN532_PN532_H
#define PN532_PN532_H

#ifndef PN532_HLP_H
#include "../hlp/hlp.h"
#endif

#define MOCK_P532

#define kNoError 0

int pn532_write(HLPCommandFrame *frame);

unsigned char *pn532_read_ack(unsigned char *read_buffer);
char *pn532_read(char *read_buffer);

int pn532_get_version(unsigned char *ic, unsigned char *ver, unsigned char *rev, unsigned char *support);

#endif //PN532_PN532_H
