#ifndef AUDIORECORD_H
#define AUDIORECORD_H
#include <QCoreApplication>
#include <QObject>
#include <QAudioSource>
#include <QBuffer>
#include <QByteArray>
#include <QMediaDevices>

class Audiorecord: public QObject
{
    Q_OBJECT
public:
    Audiorecord(QObject *parent = nullptr);
    void startRecording();
    void stopRecording();
private slots:
    void processaudio(const QByteArray &audiodata);

private:
    QAudioSource *audioSource;
    QIODevice *audioDevice;
    QBuffer *audioBuf;
    QByteArray audiodata;
};

#endif // AUDIORECORD_H
