

#include <QApplication>
#include <QDebug>
#include <QTextToSpeech>
#include <QTimer>
#include <cstdio>
#include <malloc.h>
#include "audiorecord.h"
#include "speechrecognizer.h"
#include "QFile"


void readAudioData(const QString &filePath, QByteArray &audioData)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Failed to open audio file:" << filePath;
        return;
    }
    audioData = file.readAll();
    file.close();
}
int main(int argc, char *argv[])
{ /*
    ps_config_t* config;
    ps_decoder_t *decoder;
    ps_endpointer_t* ep;
    ps_vad_mode_t vad_mode;
    short *frame;
    size_t frame_size;
    vad_mode =  PS_VAD_LOOSE;
    config =

    config = ps_config_init(NULL);
    ps_default_search_args(config);
    ps_config_set_str(config, "hmm","");
    ps_config_set_int(config, "samprate", 16000);
    ps_config_set_int(config, "maxwpf", 40);

    decoder = ps_init(config);

    if(decoder == NULL){
        qCritical()<<"failed to initialize decoder";
        return -1;
    }




    if((decoder = ps_init(config)) == NULL){
        E_FATAL("POCKETSPHINX DECODER INIT FAILED");
    }
    if ((ep = ps_endpointer_init(0, 0.0, vad_mode, 0, 0)) == NULL)
        E_FATAL("PocketSphinx endpointer init failed\n");

    frame_size = ps_endpointer_frame_size(ep);
   frame = static_cast<short*>(std::malloc(frame_size * sizeof(frame[0])));
    if(frame == NULL)
        E_FATAL_SYSTEM("failed to allocate frame");*/


    QApplication a(argc, argv);
    SpeechRecognizer recognizer;

    // Initialize the SpeechRecognizer
    recognizer.initialize();

    // Load audio data from a file
    QByteArray audioData;
    readAudioData("C:/Users/umara/Downloads/output.wav", audioData);

    // Process the audio data
    recognizer.processAudio(audioData);


    QTextToSpeech *tts = new QTextToSpeech();


    if(!tts->availableEngines().isEmpty())
    {
        qDebug() <<"Engine initialized";

        tts->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        QList<QVoice> voices = tts->availableVoices();
        if(!voices.isEmpty()){
            tts->setVoice(voices.first());
        }
        tts->setPitch(1.0);  // Range: 0.0 to 1.0
        tts->setRate(0.0);
        tts->say("TTS initialized");

    }
    else{
        qDebug()<<"No TTS engine Available";
    }


    return a.exec();

  //  MainWindow w;
   // w.show();
//return a.exec();
}
