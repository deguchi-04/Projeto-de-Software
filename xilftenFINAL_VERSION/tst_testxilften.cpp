#include <QtTest>
#include <QCoreApplication>

#include "admin.cpp"
#include "user.cpp"
#include "donated.cpp"



#include "QtSql"

// add necessary includes here

class TestXilften : public QObject
{
    Q_OBJECT


public:
    TestXilften();
    ~TestXilften();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_DB_isOpen();
    void test_Log_Admin();
    void test_LogIn();
    void test_Reg();
    void test_Donated();

};



TestXilften::TestXilften()
{

}

TestXilften::~TestXilften()
{

}

void TestXilften::initTestCase(){

}

void TestXilften::test_Log_Admin()
{
    Admin adm;
    int i=  adm.Admission("admin");
    QVERIFY(i == 0);

}

void TestXilften::test_DB_isOpen()
{
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName("db.fe.up.pt");
    DB.setDatabaseName("up201802575");
    DB.setUserName("up201802575");
    DB.setPassword("Y1a2mVSGD");
    QCOMPARE(DB.open(),true);

}

void TestXilften::test_LogIn()
{

    user u;
    int i = u.LogIN("helena", "123456");
    QVERIFY(i==0);
}

void TestXilften::test_Reg()
{
    user u;
    int i = u.Register("testeteste", "testeteste", "testeteste", "testeteste", "testeteste");
    QVERIFY(i==0);
    QSqlQuery query;
    query.exec("DELETE FROM users WHERE name = 'testeteste' ");
    query.exec("SET @num :=0 ");
    query.exec("update users set id = @num := (@num+1) ");
    query.exec("ALTER TABLE comment AUTO_INCREMENT = 1 ");
}

void TestXilften::test_Donated()
{
    QSqlQuery query;
    query.exec("INSERT INTO users (username, donated) values ('teste', 1)");
    donated d;
    int i = d.don("teste", 1);
    QVERIFY(i ==2);
    query.exec("DELETE FROM users where username = 'teste' ");
    query.exec("SET @num :=0 ");
    query.exec("update users set id = @num := (@num+1) ");
    query.exec("ALTER TABLE comment AUTO_INCREMENT = 1 ");

}





void TestXilften::cleanupTestCase(){

}



QTEST_APPLESS_MAIN(TestXilften)

#include "tst_testxilften.moc"
