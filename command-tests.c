#include <stdlib.h>
#include <string.h>

#ifndef PN532_HLP_H
#include "hlp/hlp.h"
#endif

#ifndef PN532_UNITY_TESTS_H
#include "unity/unity.h"
#endif

void creates_command_frame(void)
{
    HLPCommandFrame *frame = MAKE_FRAME;

    TEST_ASSERT_EQUAL(0x00, frame->start_code[0]);
    TEST_ASSERT_EQUAL(0xff, frame->start_code[1]);
    free(frame);
}

void creates_get_version_frame(void)
{
    HLPCommandFrame *frame = MAKE_GET_VERSION_FRAME;

    TEST_ASSERT_TRUE(COMMAND_CODE(frame) == kGetVersionCommandCode);

    TEST_ASSERT_EQUAL(frame->payload.tfi, kOutgoingTFI);
    TEST_ASSERT_EQUAL(frame->len, sizeof(frame->payload));
    TEST_ASSERT_EQUAL(frame->lcs, hlp_compute_checksum(&frame->len, (unsigned char) (sizeof(frame->len))));
    TEST_ASSERT_EQUAL(frame->dcs, hlp_compute_checksum((unsigned char *) &frame->payload, (unsigned char) (sizeof(frame->payload))));

    free(frame);
}

void computes_data_checksum(void)
{
    unsigned char *data = (unsigned char *) "some data";

    TEST_ASSERT_EQUAL(hlp_compute_checksum(data, strlen((const char *) data)), 146);
}

void computes_int_checksum(void)
{
    unsigned char buff[1] = { 0x02 };
    unsigned char *data = buff;

    TEST_ASSERT_EQUAL(0xfe, hlp_compute_checksum(data, 1));
}
