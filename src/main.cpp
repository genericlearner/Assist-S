

#include <QApplication>
#include <QDebug>
#include <QTextToSpeech>
#include <cstdio>




int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
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
