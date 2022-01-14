#include <QtTest>

// add necessary includes here

class TestXilften : public QObject
{
    Q_OBJECT

public:
    TestXilften();
    ~TestXilften();

private slots:
    void test_case1();

};

TestXilften::TestXilften()
{

}

TestXilften::~TestXilften()
{

}

void TestXilften::test_case1()
{

}

QTEST_APPLESS_MAIN(TestXilften)

#include "tst_testxilften.moc"
