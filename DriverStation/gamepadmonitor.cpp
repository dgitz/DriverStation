/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Gamepad module
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
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

#include "gamepadmonitor.h"
#include <QtGamepad/QGamepad>

#include <QDebug>

GamepadMonitor::GamepadMonitor(QObject *parent)
    : QObject(parent)
    , m_gamepad(0)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [](double value){
        qDebug() << "Left X" << value;
    });
    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [](double value){
        qDebug() << "Left Y" << value;
    });
    connect(m_gamepad, &QGamepad::buttonL2Changed, this, [](double value){
        qDebug() << "Button L2: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonL3Changed, this, [] (double value) {
        qDebug() << "Button L3: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonCenterChanged,this,[] (double value){
        qDebug() << "Center: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonDownChanged, this, [] (double value){
        qDebug() << "Down: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonLeftChanged, this, [] (double value) {
        qDebug() << "Left: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonRightChanged, this, [] (double value) {
        qDebug() << "Right: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonUpChanged, this, [] (double value) {
        qDebug() << "Up: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonAChanged, this, [] (double value) {
        qDebug() << "A: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonBChanged, this, [] (double value) {
        qDebug() << "B: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonXChanged, this, [] (double value) {
        qDebug() << "X: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonYChanged, this, [] (double value) {
        qDebug() << "Y: " << value;
    });


    connect(m_gamepad,&QGamepad::axisRightXChanged, this, [] (double value) {
        qDebug() << "Right X: " << value;
    });

    connect(m_gamepad,&QGamepad::axisRightYChanged, this, [] (double value) {
        qDebug() << "Right Y: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonL1Changed, this, [] (double value) {
        qDebug() << "Button L1: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonR1Changed, this, [] (double value) {
        qDebug() << "Button R1: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonR2Changed, this, [] (double value) {
        qDebug() << "Button R2: " << value;
    });

    connect(m_gamepad,&QGamepad::buttonR3Changed, this, [] (double value) {
        qDebug() << "Button R3: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonSelectChanged, this, [] (double value) {
        qDebug() << "Select: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonStartChanged, this, [] (double value) {
        qDebug() << "Start: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonCenterChanged, this, [] (double value) {
        qDebug() << "Center: " << value;
    });
    connect(m_gamepad,&QGamepad::buttonGuideChanged, this, [] (double value) {
        qDebug() << "Guide: " << value;
    });




}
bool GamepadMonitor::event(QEvent *event)
{

}

GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}
