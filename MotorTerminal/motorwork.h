#ifndef MOTORWORK_H
#define MOTORWORK_H

//指令格式：帧头+ID+帧长度+指令+数据+校验和

#define FrameHeader 0x59485A53;

enum ID{
    Sensor = 0x00,
    XAxis  = 0x01,
    YAxis  = 0x02,
    ZAxis  = 0x03
};

#define CMD_MotorStart        0x01;
#define CMD_MotorPause        0x02;
#define CMD_MotorReset        0x03;
#define CMD_MotorStop         0x04;
#define CMD_MotorSpeed        0x05;
#define CMD_MotorForward      0x06;
#define CMD_MotorBackward     0x07;


#include <QByteArray>
#include <QList>

#ifndef QRINGBUFFER_CHUNKSIZE
#define QRINGBUFFER_CHUNKSIZE 4096
#endif

enum {

    MaxByteArraySize = 128
};



class QRingBuffer
{
public:
    //默认分配QRINGBUFFER_CHUNKSIZE大小的buffer
    QRingBuffer(int growth = QRINGBUFFER_CHUNKSIZE) :
        head(0), tail(0), tailBuffer(0), basicBlockSize(growth), bufferSize(0) { }
    ~QRingBuffer(){}
    //获取环形缓冲区指定位置的指针
    //length，输出这个指定位置到缓冲区结尾的长度
    char *readPointerAtPosition(qint64 pos, qint64 &length);
    //申请空间：从尾开始，返回新空间的指针
    char *reserve(qint64 bytes);
    //申请空间：从头开始，返回新空间的指针
    char *reserveFront(qint64 bytes);
    //缩短空间
    void truncate(qint64 pos)
    {
        if (pos < bufferSize)
            chop(bufferSize - pos);
    }
    //判断buffers数据是否为空
    bool isEmpty()
    {
        return bufferSize == 0;
    }
    //从头读取一个字符，并转换为int返回
    int getChar()
    {
        if (isEmpty())
            return -1;
        char c = *readPointer();
        free(1);
        return int(uchar(c));
    }
    //在缓冲区尾部添加字符
    void putChar(char c)
    {
        char *ptr = reserve(1);
        *ptr = c;
    }
    //在缓冲区头部添加字符
    void ungetChar(char c)
    {
        if (head > 0) {
            --head;
            buffers.first()[head] = c;
            ++bufferSize;
        } else {
            char *ptr = reserveFront(1);
            *ptr = c;
        }
    }
    //清空缓冲区
    void clear();
    //读取maxLength长度数据到data中，如果buffers中的数据少于maxLength，则读取所有数据，
    //返回读取数据的长度
    qint64 read(char *data, qint64 maxLength);
    //读取buffers中的第一个buffer
    QByteArray read();
    //从指定位置pos拷贝maxLength长度的数据到data中
    //返回实际截取的数据长度
    qint64 peek(char *data, qint64 maxLength, qint64 pos = 0);
    //扩展最后一个buffer
    void append(const char *data, qint64 size);
    //在最后添加一个新buffer
    void append(const QByteArray &qba);
    //从头释放lenght长度空间，一般需要配合reserve使用
    qint64 skip(qint64 length)
    {
        qint64 bytesToSkip = qMin(length, bufferSize);

        free(bytesToSkip);
        return bytesToSkip;
    }
    //从尾释放length长度空间，一般需要配合reserve使用
    void chop(qint64 length);
    //读取一行,包括该行的结束标志'\n'
    qint64 readLine(char *data, qint64 maxLength);

    bool canReadLine()
    {
        return indexOf('\n', bufferSize) >= 0;
    }
private:
    //获取下一个数据块的大小
    //如果只剩一个buffer，返回最后一个buffer所含数据的大小；否则返回第一个buffer所含数据的大小。
    qint64 nextDataBlockSize()
    {
        return (tailBuffer == 0 ? tail : buffers.first().size()) - head;
    }
    //获取缓冲区第一个有效数据的指针
    char *readPointer()
    {
        return bufferSize == 0 ? Q_NULLPTR : (buffers.first().data() + head);
    }
    qint64 indexOf(char c, qint64 maxLength, qint64 pos = 0);
    //释放空间
    void free(qint64 bytes);
private:
    QList<QByteArray> buffers;
    //标识第一个buffer数据起始位置和最后一个buffer数据的结尾位置
    int head, tail;
    //大小为buffers.size()-1，如果为0，说明只剩一个buffer
    int tailBuffer;
    //初始分配空间的大小
    int basicBlockSize;
    //buffers数据总大小
    qint64 bufferSize;

};

#endif // MOTORWORK_H
