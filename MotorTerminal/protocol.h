#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QByteArray>


enum{
    PROT_FRAME_LEN_RECV = 128           //数据接收缓冲区大小
};

enum{
    PROT_FRAME_LEN_CHECKSUM = 1         //校验数据的长度
};

#define FRAME_HEADER     0x59485A53    // 帧头

 //ID宏定义
#define XAxis                   0x01
#define YAxis                   0x02
#define ZAxis                   0x03
#define Sensor                  0x04


/* 指令(下位机 -> 上位机) */
#define SEND_ID_CMD             0x01     // 发送实际ID给上位机
#define SEND_START_CMD          0x02     // 发送上位机电机启动（同步上位机按钮状态）
#define SEND_DATA_CMD           0x03
//#define SEND_PAUSE_CMD          0x03     // 发送上位机电机暂停（同步上位机按钮状态）
//#define SEND_RESET_CMD          0x04     // 发送上位机电机复位（同步上位机按钮状态）
//#define SEND_STOP_CMD           0x05     // 发送上位机电机急停（同步上位机按钮状态）
//#define SEND_SPEED_CMD          0x06     // 发送速度（同步上位机显示的值）
//#define SEND_FORWARD_CMD        0x07     // 发送上位机电机前进（同步上位机按钮状态）
//#define SEND_BACKWARD_CMD       0x08     // 发送上位机电机后退（同步上位机按钮状态）

/* 指令(上位机 -> 下位机) */
#define START_CMD               0x10     // 启动指令
#define PAUSE_CMD               0x11     // 暂停指令
#define RESET_CMD               0x12     // 复位指令
#define STOP_CMD                0x13     // 急停指令
#define SET_SPEED_CMD           0x14     // 设置速度
#define FORWARD_CMD             0x15     // 前进指令
#define BACKWARD_CMD            0x16     // 后退指令
/* 空指令 */
#define CMD_NONE                0xFF     // 空指令

/* 索引值宏定义 */
#define HEAD_INDEX_VAL       0x3u     // 包头索引值（4字节）
#define ID_INDEX_VAL         0x4u     // ID索引值（1字节）
#define LEN_INDEX_VAL        0x5u     // 包长索引值（4字节）
#define CMD_INDEX_VAL        0x6u     // 命令索引值（1字节）

#define EXCHANGE_H_L_BIT(data)      ((((data) << 24) & 0xFF000000) |\
                                     (((data) <<  8) & 0x00FF0000) |\
                                     (((data) >>  8) & 0x0000FF00) |\
                                     (((data) >> 24) & 0x000000FF))     // 交换高低字节

#define COMPOUND_32BIT(data)        (((*(data-0) << 24) & 0xFF000000) |\
                                     ((*(data-1) << 16) & 0x00FF0000) |\
                                     ((*(data-2) <<  8) & 0x0000FF00) |\
                                     ((*(data-3) <<  0) & 0x000000FF))      // 合成为一个字

struct prot_frame_parser_t
{
    quint8 *recv_ptr;
    quint16 r_oft;
    quint16 w_oft;
    quint16 frame_len;
    quint16 found_frame_head;
};

struct packet_head_t{
    quint32 head;       // 包头
    quint8  id;         // ID
    quint32 len;        // 包长度
    quint8  cmd;        // 命令
};

class Protocol
{
public:
    Protocol();

    void protocol_data_recv(quint8 *data, quint16 data_len);

    quint32 protocol_init(void);
    quint8 receiving_process(void);
    //void set_mcu_cmd(quint8 cmd, quint8 id, void *data, quint8 num);
    quint8 Crc8(const QByteArray &data);
private:

  quint32 temp;

};
quint8 check_sum(quint8 init, quint8 *ptr, quint8 len );
#endif // PROTOCOL_H
