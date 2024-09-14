#ifndef SPEECHRECOGNIZER_H
#define SPEECHRECOGNIZER_H

#include <QObject>
#include <QByteArray>
#include <pocketsphinx.h>

class SpeechRecognizer: public QObject
{
    Q_OBJECT
public:
    explicit SpeechRecognizer(QObject *parent = nullptr);
    ~SpeechRecognizer();
    void initialize();
    void processAudio(const QByteArray &audioData);

signals:
    void speechRecognized(const QString &text);

private:
    ps_decoder_t *decoder;
    ps_endpointer_t *ep;
    const char *hyp;
    QString res;

    void handleSpeech(const int16 *speech, size_t len);
    void processEp(const int16 *frame, size_t frame_size, size_t *end_samples);

};



#endif // SPEECHRECOGNIZER_H
