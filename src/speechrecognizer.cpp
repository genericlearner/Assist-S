#include "speechrecognizer.h"
#include "QDebug"
#include "QFile"
#include <iostream>


SpeechRecognizer::SpeechRecognizer(QObject * parent): QObject(parent), decoder(nullptr), ep(nullptr), hyp(nullptr)
{
    initialize();
}

SpeechRecognizer::~SpeechRecognizer(){
    if(ep){
        ps_endpointer_free(ep);
    }
    if(decoder){
        ps_free(decoder);
    }

}

void SpeechRecognizer::initialize(){
    ps_config_t *config = ps_config_init(NULL);
    ps_vad_mode_t mode = PS_VAD_LOOSE;
    ps_default_search_args(config);

    ps_config_set_str(config, "hmm","C:/Users/umara/OneDrive/Documents/Assist-S/model/en-us/en-us");
    ps_config_set_str(config, "lm","C:/Users/umara/OneDrive/Documents/Assist-S/model/en-us/en-us.lm.bin");
    ps_config_set_str(config, "dict", "C:/Users/umara/OneDrive/Documents/Assist-S/model/en-us/cmudict-en-us.dict");



    decoder = ps_init(config);
    if(decoder == NULL){
        qCritical()<<"Failed to initialize the decoder;";
        return;
    }
    ep = ps_endpointer_init(0,0.0,mode,0,0);
    if(ep == NULL){
        qCritical()<<"Failed to initialize the endpointer";
        return;
    }
    ps_config_free(config);

}

void SpeechRecognizer::processAudio(const QByteArray &audioData){
    if (audioData.isEmpty()) {
        qCritical() << "No audio data provided.";
        return;
    }

    // Convert QByteArray to int16_t array for PocketSphinx
    const int16_t *frame = reinterpret_cast<const int16_t *>(audioData.constData());
    size_t frame_size = audioData.size() / sizeof(int16_t);

    if (frame_size == 0) {
        qCritical() << "Audio data conversion error.";
        return;
    }

    // Debug print the audio data size and some sample values
    qDebug() << "Audio data size:" << audioData.size();
    if (frame_size > 10) {
        qDebug() << "First few samples:" << frame[0] << frame[1] << frame[2] << frame[3];
    }

    size_t end_samples;
    // Process audio data with endpointer and decoder
    processEp(frame, frame_size, &end_samples);

    // Print the recognized speech
    if (!res.isEmpty()) {
        qDebug() << "Recognized Speech:" << res;
    }


}


void SpeechRecognizer::processEp(const int16 *frame, size_t frame_size, size_t *end_samples){
    int prev_in_speech = ps_endpointer_in_speech(ep);

    const int16 *speech = ps_endpointer_process(ep, frame);

    if (speech != NULL) {
        handleSpeech(speech, frame_size);

        if (!prev_in_speech) {
            ps_start_utt(decoder);
        }

        if (ps_process_raw(decoder, speech, frame_size, FALSE, FALSE) < 0) {
            qCritical() << "PocketSphinx process_raw() failed.";
            return;
        }

        hyp = ps_get_hyp(decoder, NULL);
        if (hyp != nullptr) {
            res = QString(hyp);
        }

        if (!ps_endpointer_in_speech(ep)) {
            ps_end_utt(decoder);
            if ((hyp = ps_get_hyp(decoder, NULL)) != NULL) {
                res = QString(hyp);
            }
        }
    } else {
        qDebug() << "Endpointer processing did not return speech.";
    }

}

void SpeechRecognizer::handleSpeech(const int16 *speech, size_t frame_size){
    //
}
