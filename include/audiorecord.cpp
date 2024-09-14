#include "audiorecord.h"
#include <QTimer>
#include <Qdebug>

Audiorecord::Audiorecord(QObject * parent)
    :QObject(parent), audioSource(nullptr), audioDevice(nullptr), audioBuf(nullptr)
{
    const auto input = QMediaDevices::defaultAudioInput();

    QAudioFormat format;
    format.setSampleRate(16000);
    format.setChannelCount(1);
    format.setSampleFormat(QAudioFormat::Int16);

    audioSource = new QAudioSource(input, format, this);

    audioBuf = new QBuffer(&audiodata, this);
    audioBuf->open(QIODevice::WriteOnly);

}

void Audiorecord::startRecording()
{
    audioDevice = audioSource->start();
    connect(audioDevice, &QIODevice::readyRead,[this](){
        QByteArray data = audioDevice->readAll();
        audioBuf->write(data);


    });
}

void Audiorecord::stopRecording()
{
    audioSource->stop();
    audioBuf->close();
    processaudio(audiodata);
}

void Audiorecord::processaudio(const QByteArray &audiodata)
{
    qDebug()<<"Processing audio data in memory"<<audiodata.size();
}
