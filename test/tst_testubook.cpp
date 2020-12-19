//#include <QtTest>

//#include "../dWell/ubook.h"

//Q_DECLARE_METATYPE(user);
//Q_DECLARE_METATYPE(user::utype);
//Q_DECLARE_METATYPE(ubook);

//class testUbook : public QObject
//{
//    Q_OBJECT

//private slots:
//    void insertUsers();
//};

//void testUbook::insertUsers()
//{
//    user u1("a", "a", user::ADMIN);
//    ubook ub;
//    QVERIFY(ub.insert(u1));
//    QVERIFY2(ub.size()==1, "wrong size");
//    QVERIFY2(ub[0].name() == "a" && ub[0].passwd() == "a" && ub[0].type() == user::ADMIN, "error occurred when user pushing in userbook");
//    user u2("a", "a", user::ADMIN);
//    QVERIFY2(ub.insert(u2), "an error occurred while adding a user with a matching name");
//    user u3("b", "b", user::COMMANDANT);
//    user u4("c", "c", user::STUDENT);
//    QVERIFY2(ub.size() == 3, "wrong size");
//}

