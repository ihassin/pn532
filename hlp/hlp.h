#ifndef PN532_HLP_H
#define PN532_HLP_H

typedef struct {
    unsigned char preamble;
    unsigned char start_code[2];
    unsigned char len;
    unsigned char lcs;
    struct {
        unsigned char tfi;
        struct {
            unsigned char command_code;
            char data[];
        } command;
    } payload;
    unsigned char dcs;
    unsigned char postamble;
} HLPCommandFrame;

typedef struct {
    unsigned char preamble;
    unsigned char spc;
    unsigned char ack_packet_code;
    unsigned char postamble;
} HLPACKFrame;

#define kOutgoingTFI    (unsigned char) 0xd4

#define kGetVersionCommandCode  0x02

#define COMMAND_CODE(frame)     (frame->payload.command.command_code)

#define MAKE_FRAME              (hlp_init_command_frame(hlp_alloc_command_frame()))
#define MAKE_GET_VERSION_FRAME  (hlp_make_get_version_frame(MAKE_FRAME))

HLPCommandFrame *hlp_alloc_command_frame(void);
HLPCommandFrame *hlp_init_command_frame(HLPCommandFrame *frame);
HLPCommandFrame *hlp_make_get_version_frame(HLPCommandFrame *frame);

unsigned char hlp_compute_checksum(unsigned char *data, int length);

#endif //PN532_HLP_H
