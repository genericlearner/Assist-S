#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <QObject>
#include <windows.h>
#include <string>

class Assistant: public QObject
{
    Q_OBJECT
public:

    explicit Assistant(QObject *parent = nullptr);
    void openNotepadAndType(const QString &text);
private:
    void typeText(const std::string &text);
};

#endif // ASSISTANT_H
