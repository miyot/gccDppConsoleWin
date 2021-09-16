/** CDP5Protocol CDP5Protocol */
#pragma once

#include <math.h>
#include <vector>
#include <string>

enum TRANSMIT_PACKET_TYPE {
    //REQUEST_PACKETS_TO_DP5
    XMTPT_SEND_STATUS,
    XMTPT_SEND_SPECTRUM,
    XMTPT_SEND_CLEAR_SPECTRUM,
    XMTPT_SEND_SPECTRUM_STATUS,
    XMTPT_SEND_CLEAR_SPECTRUM_STATUS,
    XMTPT_BUFFER_SPECTRUM,
    XMTPT_BUFFER_CLEAR_SPECTRUM,
    XMTPT_SEND_BUFFER,
    XMTPT_SEND_DP4_STYLE_STATUS,
    XMTPT_SEND_PX4_CONFIG,
    XMTPT_SEND_SCOPE_DATA,
    XMTPT_SEND_512_BYTE_MISC_DATA,
    XMTPT_SEND_SCOPE_DATA_REARM,
    XMTPT_SEND_ETHERNET_SETTINGS,
    XMTPT_SEND_DIAGNOSTIC_DATA,
    XMTPT_SEND_NETFINDER_PACKET,
    XMTPT_SEND_LIST_MODE_DATA,
    XMTPT_SEND_HARDWARE_DESCRIPTION,
    XMTPT_SEND_SCA,
    XMTPT_LATCH_SEND_SCA,
    XMTPT_LATCH_CLEAR_SEND_SCA,
    XMTPT_SEND_ROI_OR_FIXED_BLOCK,
    XMTPT_PX4_STYLE_CONFIG_PACKET,
    XMTPT_SEND_CONFIG_PACKET_EX,
    XMTPT_SEND_CONFIG_PACKET_TO_HW,
    XMTPT_READ_CONFIG_PACKET,
    XMTPT_READ_CONFIG_PACKET_EX,
    XMTPT_FULL_READ_CONFIG_PACKET,
    XMTPT_SCA_READ_CONFIG_PACKET,
    XMTPT_ERASE_FPGA_IMAGE,
    XMTPT_UPLOAD_PACKET_FPGA,
    XMTPT_REINITIALIZE_FPGA,
    XMTPT_ERASE_UC_IMAGE_0,
    XMTPT_ERASE_UC_IMAGE_1,
    XMTPT_ERASE_UC_IMAGE_2,
    XMTPT_UPLOAD_PACKET_UC,
    XMTPT_SWITCH_TO_UC_IMAGE_0,
    XMTPT_SWITCH_TO_UC_IMAGE_1,
    XMTPT_SWITCH_TO_UC_IMAGE_2,
    XMTPT_UC_FPGA_CHECKSUMS,

    //VENDOR_REQUESTS_TO_DP5
    XMTPT_CLEAR_SPECTRUM_BUFFER_A,
    XMTPT_ENABLE_MCA_MCS,
    XMTPT_DISABLE_MCA_MCS,
    XMTPT_ARM_DIGITAL_OSCILLOSCOPE,
    XMTPT_AUTOSET_INPUT_OFFSET,
    XMTPT_AUTOSET_FAST_THRESHOLD,
    XMTPT_READ_IO3_0,
    XMTPT_WRITE_IO3_0,
    XMTPT_WRITE_512_BYTE_MISC_DATA,
    XMTPT_SET_DCAL,
    XMTPT_SET_PZ_CORRECTION_UC_TEMP_CAL_PZ,
    XMTPT_SET_PZ_CORRECTION_UC_TEMP_CAL_UC,
    XMTPT_SET_BOOT_FLAGS,
    XMTPT_SET_HV_DP4_EMULATION,
    XMTPT_SET_TEC_DP4_EMULATION,
    XMTPT_SET_INPUT_OFFSET_DP4_EMULATION,
    XMTPT_SET_ADC_CAL_GAIN_OFFSET,
    XMTPT_SET_SPECTRUM_OFFSET,
    XMTPT_REQ_SCOPE_DATA_MISC_DATA_SCA_PACKETS,
    XMTPT_SET_SERIAL_NUMBER,
    XMTPT_CLEAR_GP_COUNTER,
    XMTPT_SWITCH_SUPPLIES,

    XMTPT_SEND_TEST_PACKET,
    XMTPT_REQ_ACK_PACKET,
    XMTPT_FORCE_SCOPE_TRIGGER,
    XMTPT_READ_MCA8000D_OPTION_PA_CAL,
    XMTPT_AU34_2_RESTART
};  //TRANSMIT_PACKET_TYPE

//enum RECEIVE_PACKET_TYPE {
//     //RESPONSE_PACKETS_FROM_DP5
//    RCVPT_DP4_STYLE_STATUS,
//    RCVPT_256_CHANNEL_SPECTRUM,
//    RCVPT_256_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_512_CHANNEL_SPECTRUM,
//    RCVPT_512_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_1024_CHANNEL_SPECTRUM,
//    RCVPT_1024_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_2048_CHANNEL_SPECTRUM,
//    RCVPT_2048_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_4096_CHANNEL_SPECTRUM,
//    RCVPT_4096_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_8192_CHANNEL_SPECTRUM,
//    RCVPT_8192_CHANNEL_SPECTRUM_STATUS,
//    RCVPT_SCOPE_DATA,
//    RCVPT_512_BYTE_MISC_DATA,
//    RCVPT_IO3_0_STATE
//};  //RECEIVE_PACKET_TYPE

enum PID1_TYPE {
    PID1_REQ_STATUS = 0x01,
    PID1_REQ_SPECTRUM = 0x02,
    PID1_REQ_SCOPE_MISC = 0x03,
    PID1_REQ_SCA = 0x04,
    PID1_REQ_CONFIG = 0x20,
    PID1_REQ_FPGA_UC = 0x30,
    PID1_RCV_STATUS = 0x80,
    PID1_RCV_SPECTRUM = 0x81,
    PID1_RCV_SCOPE_MISC = 0x82,
    PID1_RCV_SCA = 0x83,
    PID1_VENDOR_REQ = 0xF0,
    PID1_COMM_TEST = 0xF1,
    PID1_ACK = 0xFF
};  //PID1_TYPE

enum PID2_REQ_STATUS_TYPE {
    PID2_SEND_DP4_STYLE_STATUS = 0x01
};  //PID2_REQ_STATUS_TYPE

enum PID2_REQ_SPECTRUM_TYPE {
    // REQUEST_PACKETS_TO_DP5
    PID2_SEND_SPECTRUM = 0x01,
    PID2_SEND_CLEAR_SPECTRUM = 0x02,
    PID2_SEND_SPECTRUM_STATUS = 0x03,
    PID2_SEND_CLEAR_SPECTRUM_STATUS = 0x04
    //PID2_BUFFER_SPECTRUM,
    //PID2_BUFFER_CLEAR_SPECTRUM,
    //PID2_SEND_BUFFER,
    //PID2_SEND_CONFIG
};  //PID2_REQ_SPECTRUM_TYPE

enum PID2_REQ_SCOPE_MISC_TYPE {
    PID2_SEND_SCOPE_DATA = 0x01,
    PID2_SEND_512_BYTE_MISC_DATA = 0x02,
    PID2_SEND_SCOPE_DATA_REARM = 0x03,
    PID2_SEND_ETHERNET_SETTINGS = 0x04,
    PID2_SEND_DIAGNOSTIC_DATA = 0x05,
    PID2_SEND_HARDWARE_DESCRIPTION = 0x06,
    PID2_SEND_NETFINDER_READBACK = 0x07,
    PID2_SEND_I2C_DATA = 0x08,
    PID2_SEND_LIST_MODE_DATA = 0x09,
    PID2_SEND_OPTION_PA_CALIBRATION = 0x0A
};  //PID2_REQ_SCOPE_MISC_TYPE

enum PID2_REQ_SCA_TYPE {
    PID2_SEND_SCA = 0x01,
    PID2_LATCH_SEND_SCA = 0x02,
    PID2_LATCH_CLEAR_SEND_SCA = 0x03
};  //PID2_REQ_SCA_TYPE

enum PID2_REQ_CONFIG_TYPE {
    PID2_PX4_STYLE_CONFIG_PACKET = 0x01,
    PID2_TEXT_CONFIG_PACKET = 0x02,
    PID2_CONFIG_READBACK_PACKET = 0x03
};  //PID2_SEND_CONFIG_TYPE

enum PID2_REQ_FPGA_UC_TYPE {
    PID2_ERASE_FPGA_IMAGE = 0x01,
    PID2_UPLOAD_PACKET_FPGA = 0x02,
    PID2_REINITIALIZE_FPGA = 0x03,
    PID2_ERASE_UC_IMAGE_0 = 0x04,
    PID2_ERASE_UC_IMAGE_1 = 0x05,
    PID2_ERASE_UC_IMAGE_2 = 0x06,
    PID2_UPLOAD_PACKET_UC = 0x07,
    PID2_SWITCH_TO_UC_IMAGE_0 = 0x08,
    PID2_SWITCH_TO_UC_IMAGE_1 = 0x09,
    PID2_SWITCH_TO_UC_IMAGE_2 = 0x0A
    //PID2_UC_FPGA_CHECKSUMS
};  //PID2_REQ_FPGA_UC_TYPE

enum PID2_VENDOR_REQ_TYPE {
    PID2_CLEAR_SPECTRUM_BUFFER_A = 0x01,
    PID2_ENABLE_MCA_MCS = 0x02,
    PID2_DISABLE_MCA_MCS = 0x03,
    PID2_ARM_DIGITAL_OSCILLOSCOPE = 0x04,
    PID2_AUTOSET_INPUT_OFFSET = 0x05,
    PID2_AUTOSET_FAST_THRESHOLD = 0x06,
    PID2_READ_IO3_0 = 0x07,
    PID2_WRITE_IO3_0 = 0x08,
    PID2_WRITE_512_BYTE_MISC_DATA = 0x09,
    PID2_SET_DCAL = 0x0A,
    PID2_SET_PZ_CORRECTION_UC_TEMP_CAL_PZ = 0x0B,
    PID2_SET_PZ_CORRECTION_UC_TEMP_CAL_UC = 0x0C,
    PID2_SET_BOOT_FLAGS = 0x0D,
    //PID2_SET_HV_DP4_EMULATION
    //PID2_SET_TEC_DP4_EMULATION
    //PID2_SET_INPUT_OFFSET_DP4_EMULATION
    PID2_SET_ADC_CAL_GAIN_OFFSET = 0x0E,
    //PID2_SET_SPECTRUM_OFFSET
    //PID2_REQ_SCOPE_DATA_MISC_DATA_SCA_PACKETS
    PID2_SET_SERIAL_NUMBER = 0x0F,
    PID2_CLEAR_GP_COUNTER = 0x10,
    PID2_SET_ETHERNET_SETTINGS = 0x11,
    //PID2_SWITCH_SUPPLIES
    PID2_ETHERNET_ALLOW_SHAREING = 0x20,
    PID2_ETHERNET_NO_SHARING = 0x21,
    PID2_ETHERNET_LOCK_IP = 0x22,
    PID2_GENERIC_FPGA_WRITE = 0x89
};  //PID2_VENDOR_REQ_TYPE

enum PID2_RCV_STATUS_TYPE {
    RCVPT_DP4_STYLE_STATUS = 0x01
};  //PID2_RCV_STATUS_TYPE

enum PID2_RCV_SPECTRUM_TYPE {
    RCVPT_256_CHANNEL_SPECTRUM = 0x01,
    RCVPT_256_CHANNEL_SPECTRUM_STATUS = 0x02,
    RCVPT_512_CHANNEL_SPECTRUM = 0x03,
    RCVPT_512_CHANNEL_SPECTRUM_STATUS = 0x04,
    RCVPT_1024_CHANNEL_SPECTRUM = 0x05,
    RCVPT_1024_CHANNEL_SPECTRUM_STATUS = 0x06,
    RCVPT_2048_CHANNEL_SPECTRUM = 0x07,
    RCVPT_2048_CHANNEL_SPECTRUM_STATUS = 0x08,
    RCVPT_4096_CHANNEL_SPECTRUM = 0x09,
    RCVPT_4096_CHANNEL_SPECTRUM_STATUS = 0x0A,
    RCVPT_8192_CHANNEL_SPECTRUM = 0x0B,
    RCVPT_8192_CHANNEL_SPECTRUM_STATUS = 0x0C
};  //PID2_RCV_SPECTRUM_TYPE

enum PID2_RCV_SCOPE_MISC_TYPE {
    RCVPT_SCOPE_DATA = 0x01,
    RCVPT_512_BYTE_MISC_DATA = 0x02,
    RCVPT_SCOPE_DATA_WITH_OVERFLOW = 0x03,
    RCVPT_ETHERNET_SETTINGS = 0x04,
    RCVPT_DIAGNOSTIC_DATA = 0x05,
    RCVPT_HARDWARE_DESCRIPTION = 0x06,
    RCVPT_CONFIG_READBACK = 0x07,
    RCVPT_NETFINDER_READBACK = 0x08,
    RCVPT_I2C_DATA = 0x09,
    RCVPT_LIST_MODE_DATA = 0x0A,
    RCVPT_LIST_MODE_DATA_FIFO_FULL = 0x0B,
    RCVPT_OPTION_PA_CALIBRATION = 0x0C
};  //PID2_REQ_SCOPE_MISC_TYPE

enum PID2_RCV_SCA_TYPE {
    RCVPT_SCA = 0x01
};  //PID2_REQ_SCA_TYPE

enum PID2_ACK_TYPE {  //PID1_ACK, PID2_ACK_TYPE)
    PID2_ACK_OK = 0x00,
    PID2_ACK_SYNC_ERROR = 0x01,
    PID2_ACK_PID_ERROR = 0x02,
    PID2_ACK_LEN_ERROR = 0x03,
    PID2_ACK_CHECKSUM_ERROR = 0x04,
    PID2_ACK_BAD_PARAM = 0x05,
    PID2_ACK_BAD_HEX_REC = 0x06,
    PID2_ACK_UNRECOG = 0x07,
    PID2_ACK_FPGA_ERROR = 0x08,
    PID2_ACK_CP2201_NOT_FOUND = 0x09,
    PID2_ACK_SCOPE_DATA_NOT_AVAIL = 0x0A,
    PID2_ACK_PC5_NOT_PRESENT = 0x0B,
    PID2_ACK_OK_ETHERNET_SHARE_REQ = 0x0C,
    PID2_ACK_ETHERNET_BUSY = 0x0D,
    PID2_ACK_I2C_ERROR = 0x0E,
    PID2_ACK_OK_FPGA_UPLOAD_ADDR = 0x0F,
    PID2_ACK_FEATURE_NOT_FPGA_SUPPORTED = 0x10,
    PID2_ACK_CAL_DATA_NOT_PRESENT = 0x11
};  //PID2_ACK_TYPE

//#define PID1_ACK 0xFF

#define ACK 0
//#define STATUS 1
//#define SPECTRUM 2
#define SYNC1_ 0xF5
#define SYNC2_ 0xFA

#define RS232 0
#define USB 1
#define ETHERNET 2

#define ETHERNET_TIMEOUT 1000   // default timeout of 1000mS
#define RS232_TIMEOUT 2500      // default timeout of 2500mS (8K spectrum ~2.2s)
#define USB_TIMEOUT 500         // default timeout of 500mS

#define Retries 2   // total of 3 attempts

typedef struct _Packet_In {
    unsigned char PID1;
    unsigned char PID2;
    unsigned short LEN;  // signed, but data payload always less than 32768
    unsigned char STATUS;
    unsigned char DATA[32768];
    long CheckSum;
} Packet_In;

struct Packet_Out {
    unsigned char PID1;
    unsigned char PID2;
    unsigned short LEN;  // signed, but data payload always less than 32768
    unsigned char EXPECTEDRESPONSE;
    unsigned char DATA[514];
};

#define MAX_BUFFER_DATA        8192
#define MAX_SCOPE_DATA        2048
#define USB_DiagDataDelayMS 2500
#define MAX_LIST_BUFFER_DATA 4096

struct Spec {
    long DATA[MAX_BUFFER_DATA];   // this keeps total of static data under 64K VB limit
    short CHANNELS;
};

struct List {
    long DATA[MAX_LIST_BUFFER_DATA];
    short CHANNELS;
    short RECORDS;
    std::vector< std::pair<std::string, std::string> > AMPLITUDEANDTIME;
};

class CDP5Protocol {
public:
    CDP5Protocol(void);

    ~CDP5Protocol(void);

    /// Inidicates the incoming packet type;
    short InPacketType;
    // Incoming packet buffer. (24648==largest possible IN packet.)
    unsigned char PacketIn[24648];

    /// Tracks the RS232 number of bytes in the input buffer.
    long RS232BytesInBuffer;
    /// RS232 receive buffer threshold.
    long RS232_RThreshold;
    /// RS232 header received indicator.
    bool RS232HeaderReceived;
    /// Points to the current incoming data save position in the input buffer.
    short RS232PacketPtr;

    /// Auto plot scale indicator.
    bool ScaleAuto;
    /// Oscilloscope data buffer.
    unsigned char Scope[2048];
    /// Miscellaneous data buffer.
    unsigned char MiscData[512];
    /// Communications error indicator.
    bool CommError;
    /// Output data buffer.
    unsigned char BufferOUT[520];
    /// Spectrum data buffer.
    Spec SPECTRUM;
    /// List-mode data buffer.
    List LISTDATA;
    /// Packet input buffer.
    Packet_In PIN;

    /// ACK received indicator.
    bool ACK_Received;
    /// Packet received indicator.
    bool Packet_Received;
    /// Communication timeout error indicator flag.
    bool Timeout_flag;

    int UDP_offset;
    bool Netfinder_active;
    int Netfinder_Seq;

    /// USB default timeout is the longest time period that the USB interface will wait for a transaction.
    bool USB_Default_Timeout;
};

