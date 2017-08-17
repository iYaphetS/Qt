#ifndef RIGHTSHOWDIALOG_H
#define RIGHTSHOWDIALOG_H

#include <QApplication>
#include <QDesktopWidget>
#include <QDialog>
#include <QTimer>
#include <QRect>
#include <QPoint>
#include <QDebug>
#include <QTextEdit>


class rightshowdialog : public QDialog
{
    Q_OBJECT
public:
    rightshowdialog(QWidget *parent = 0);
    ~rightshowdialog();
    void win_show();//窗口开始显示

private slots:
    void win_move();//窗口移动
    void win_stay();//窗口停留
    void win_cloes();//窗口关闭

private:
    QTimer *m_start;//弹窗开启
    QTimer *m_show;//弹窗显示时间
    QTimer *m_close;//弹窗关闭
    int m_DeskHigh;//屏幕高度
    double m_Transparent;//设置窗口透明度，取值范围为0.0~1.0，初始值为1.0,当等于0.0的时候窗口百分百透明
    QRect m_rect;
    QPoint m_point;
    QTextEdit *m_TextEdit;




};

#endif // RIGHTSHOWDIALOG_H
