#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QDebug>
#include <QObject>
#include <QQuickView>
#include <QUrl>
#include <QString>
#include <QQuickItem>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass()
    {

    }
public slots:
    void cppSlot(const QVariant &v) {
        qDebug() << "Called the C++ slot with value:" << v;

        QQuickItem *item =
                qobject_cast<QQuickItem*>(v.value<QObject*>());
        qDebug() << "Item dimensions:" << item->width()
                 << item->height();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQuickView view(QUrl::fromLocalFile("qrc:/main.qml"));
    QObject *item = view.rootObject();

    MyClass myClass;
    QObject::connect(item, SIGNAL(qmlSignal(QVariant)),
                     &myClass, SLOT(cppSlot(QVariant)));



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
