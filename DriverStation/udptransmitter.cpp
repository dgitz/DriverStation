/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtNetwork>

#include "udptransmitter.h"
#define id "AB10"
UDPTransmitter::UDPTransmitter(QWidget *parent)
    : QObject(parent)
{
    //connect(&timer,SIGNAL(timeout()),this,SLOT(send_messages()));
    //timer.start(10);
    udpmessagehandler = new UDPMessageHandler();
    xmit_socket = new QUdpSocket(this);
    xmit_socket->bind(QHostAddress::Any,1234);
    RemoteControl_AB10_timer.start();
    ArmControl_AB26_timer.start();
    Command_AB02_timer.start();
    Heartbeat_AB31_timer.start();

}
bool UDPTransmitter::set_RC_server(QString server,uint32_t port)
{
    RC_Server = server;
    unicast_port = port;
    return true;
}
bool UDPTransmitter::send_ArmControl_0xAB26(int device,int axis1,int axis2,int axis3,int axis4,int axis5,int axis6,int button1,int button2,int button3,int button4,int button5,int button6)
{
    //qDebug() << "Sent ArmControl (0xAB26) @ " << (1000000000.0/ArmControl_AB26_timer.nsecsElapsed());
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    QString buffer = udpmessagehandler->encode_ArmControlUDP(device,axis1,axis2,axis3,axis4,axis5,axis6,
                                                             button1,button2,button3,button4,button5,button6);
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),unicast_port);
    ArmControl_AB26_timer.restart();
    return true;
    //qDebug() << "Send AB26 to" << RC_Server << " : " << buffer << endl;
}

bool UDPTransmitter::send_RemoteControl_0xAB10(quint64 timestamp,int axis1,int axis2,int axis3,int axis4,int axis5,int axis6,int axis7,int axis8,
                                                                           int button1,int button2,int button3,int button4, int button5,int button6,int button7,int button8)
{
    //qDebug() << "Sent RemoteControl (0xAB10) @ " << (1000000000.0/RemoteControl_AB10_timer.nsecsElapsed());
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    //std::string sendstr("123,456");
    QString buffer = udpmessagehandler->encode_RemoteControlUDP(timestamp,axis1,axis2,axis3,axis4,axis5,axis6,axis7,axis8,
                                                                button1,button2,button3,button4,button5,button6,button7,button8);
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),unicast_port);
    //qDebug() << "Send AB10 to" << RC_Server << " : " << buffer << endl;
    RemoteControl_AB10_timer.restart();
    return true;
}
bool UDPTransmitter::send_Command_0xAB02(int command,int option1,int option2,int option3, std::string commandtext, std::string description)
{
    //qDebug() << "Sent Command (0xAB02) @ " << (1000000000.0/Command_AB02_timer.nsecsElapsed());
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    //std::string sendstr("123,456");
    QString buffer = udpmessagehandler->encode_CommandUDP(command,option1,option2,option3,commandtext,description);
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),unicast_port);
    Command_AB02_timer.restart();
    return true;
}
bool UDPTransmitter::send_Heartbeat_0xAB31(std::string hostname,uint64_t t,uint64_t t2)
{
    //qDebug() << "Sent Heartbeat (0xAB31) @ " << (1000000000.0/Heartbeat_AB31_timer.nsecsElapsed());
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    QString buffer = udpmessagehandler->encode_HeartbeatUDP(hostname,t,t2);
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),unicast_port);
    //qDebug() << "Send AB31 to" << RC_Server << " : " << buffer << endl;
    Heartbeat_AB31_timer.restart();
    return true;
}
bool UDPTransmitter::send_TuneControlGroup_0xAB39(std::string name, std::string type, double v1, double v2, double v3,int maxvalue,int minvalue,int defaultvalue)
{
    //qDebug() << "Sent TuneControlGroup (0xAB39) @ " << (1000000000.0/TuneControlGroup_0A39_timer.nsecsElapsed());
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    QString buffer = udpmessagehandler->encode_TuneControlGroupUDP(name,v1,v2,v3,maxvalue,minvalue,defaultvalue);
    xmit_socket->writeDatagram(buffer.toUtf8(),QHostAddress(RC_Server),unicast_port);
    //qDebug() << "Send AB31 to" << RC_Server << " : " << buffer << endl;
    TuneControlGroup_0A39_timer.restart();
    return true;
}
