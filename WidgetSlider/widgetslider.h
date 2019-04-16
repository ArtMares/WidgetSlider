#ifndef WIDGETSLIDER_H
#define WIDGETSLIDER_H

#include <QWidget>
#include <QEasingCurve>
#include <QList>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class WidgetSlider : public QWidget
{
    Q_OBJECT

public:
    WidgetSlider(QWidget *parent = nullptr);
    ~WidgetSlider();
    enum Direction {
        RightToLeft,
        LeftToRight,
        UpToDown,
        DownToUp
    };
    enum State {
        Stopped,
        Running
    };
    void addWidget(QWidget *widget);
    void removeWidget(QWidget *widget);
    int currentIndex();
    QWidget *widget(int idx) const;

signals:
    void animationFinished(void);

public slots:
    void setAnimation(QEasingCurve::Type type);
    void setSpeed(int speed);
    void setLoop(bool loop);
    void setDirection(Direction direction);
    void next();
    void prev();
    void slideToIndex(int idx);
    void slideToWidget(QWidget *widget);

protected slots:
    void animationDone(void);
};

#endif
