#include "rightshowdialog.h"

rightshowdialog::rightshowdialog(QWidget *parent)
    : QDialog(parent)
{
    resize(400,300);//-------------------------------------------------->设置窗口大小
    setWindowTitle("C++三期就业班：");//------------------------------>设置窗口标题
    m_start = new QTimer(this);//--------------------------------------->实例化窗口弹窗时钟
    m_show = new QTimer(this);//---------------------------------------->实例化停留显示时钟
    m_close = new QTimer(this);//--------------------------------------->实例化窗口透明渐淡关闭时钟
    m_Transparent = 1.0;// --------------------------------------------->初始化窗口的透明设定

    //QT5 信号槽写法
    connect(m_start,&QTimer::timeout,this,&rightshowdialog::win_move);//>窗口移动信号槽
    connect(m_show,&QTimer::timeout,this, &rightshowdialog::win_stay);//->窗口停留信号槽
    connect(m_close,&QTimer::timeout,this, &rightshowdialog::win_cloes);//窗口逐渐透明关闭信号槽


    //QT4 信号槽写法

    //connect(m_start,SIGNAL(timeout()),this,SLOT(win_move()));//--------->窗口移动信号槽
    //connect(m_show,SIGNAL(timeout()),this,SLOT(win_stay()));//---------->窗口停留信号
    //connect(m_close,SIGNAL(timeout()),this,SLOT(win_cloes()));//-------->窗口逐渐透明关闭信号槽



    m_TextEdit = new QTextEdit(this);
    m_TextEdit->resize(400,300);
    m_TextEdit->setText("深圳天气预报");
    m_TextEdit->append("夜间 — 白天  24-29℃");
    m_TextEdit->append("空气质量：优-良");
    m_TextEdit->append("分散阵雨转多云；气温24-29℃；东北风2-3级；相对湿度65%-90%");
    m_TextEdit->append("日出：5:40");
    m_TextEdit->append("日落：19:00");
    m_TextEdit->setAlignment(Qt::AlignCenter);
    win_show();//启动窗口显示
}

void rightshowdialog::win_show()//---------------------------------------->开始显示窗口
{
    m_rect = QApplication::desktop()->availableGeometry();//-------------->获取系统屏幕大小

    //m_rect.width()  屏幕的宽度
    m_point.setX(m_rect.width() - width());//----------------------------->用屏幕的宽度减去窗口的宽度

    //qDebug() << "m_rect.width()" << m_rect.width()<<"m_rect.height()"<<m_rect.height();
    //m_rect.height()  屏幕的高度

    m_point.setY(m_rect.height()- height());

    m_DeskHigh = m_rect.height() ;//-------------------------------------->窗口高度
    move(m_point.x(),m_point.y());
    m_start->start(5);
}

void rightshowdialog::win_move()//---------------------------------------->窗口移动
{
    m_DeskHigh--;//------------------------------------------------------->高度减减
    move(m_point.x(),m_DeskHigh - 30);//--------------------------------------->窗口高度减减移动
    if(m_DeskHigh <= m_point.y())
    {
        m_start->stop(); //----------------------------------------------->关闭移动时钟
        m_show->start(4000);//-------------------------------------------->启动显示时钟
    }
}

void rightshowdialog::win_stay()//---------------------------------------->窗口停留显示
{
    m_show->stop();//----------------------------------------------------->关闭显示时钟
    m_close->start(180);//------------------------------------------------>启动逐渐透明关闭
}

void rightshowdialog::win_cloes()//--------------------------------------->窗口渐淡关闭
{
    m_Transparent -= 0.1;//----------------------------------------------->窗口透明渐淡
    if (m_Transparent <= 0.0)//------------------------------------------->如果透明度小于等于0.0，窗口完全透明不见，关闭窗口
    {
        m_close->stop();//------------------------------------------------>关闭渐变时钟
        close();//-------------------------------------------------------->关闭窗口
    }
    else
    {
        setWindowOpacity(m_Transparent);//-------------------------------->设置窗口透明度
    }

}

rightshowdialog::~rightshowdialog()
{

}
