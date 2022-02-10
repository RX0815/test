#include <iostream>
using namespace std;
#include <string>
#define MAX 1000 //宏定义通讯录最大联系人数量为1000

struct Person //联系人结构体
{
    string m_Name;  //姓名
    int m_Sex;      //性别   1、男 2、女
    int m_Age;      //年龄
    string m_Phone; //联系电话
    string m_Addr;  //地址
};

struct Addressbooks
{
    struct Person personArray[MAX]; //创建结构体数组: 数据类型(结构体) + 数组名[ 元素个数 ]
    int m_Size;                     //通讯录人员个数
};

//封装showMenu函数，显示菜单
void showMenu()
{
    cout << "******************************" << endl;
    cout << "*********1. 添加联系人********" << endl;
    cout << "*********2. 显示联系人********" << endl;
    cout << "*********3. 删除联系人********" << endl;
    cout << "*********4. 查找联系人********" << endl;
    cout << "*********5. 修改联系人********" << endl;
    cout << "*********6. 清空联系人********" << endl;
    cout << "*********0. 退出通讯录********" << endl;
    cout << "******************************" << endl;
}

void addPerson(Addressbooks *abs) //添加联系人
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加新联系人" << endl;
        return;
    }
    else
    {
        //姓名
        cout << "请输入新建联系人的姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //性别
        cout << "请输入联系人的性别为:" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;

        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入";
        }

        //年龄
        cout << "请输入新建联系人的年龄为：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //电话
        cout << "请输入新建联系人的电话号码是：" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //地址
        cout << "请输入新建联系人的地址为：" << endl;
        string Addr;
        cin >> Addr;
        abs->personArray[abs->m_Size].m_Addr = Addr;

        abs->m_Size++; //添加成功，通讯录人员数量加一

        cout << "添加成功" << endl;
    }
    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}
void showperson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前通讯录联系人数量为零！！" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名： " << abs->personArray[i].m_Name << " \t ";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"; //注意三目运算符的优先级
            cout << "年龄： " << abs->personArray[i].m_Age << " \t ";
            cout << "联系电话： " << abs->personArray[i].m_Phone << " \t ";
            cout << "地址： " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}

//查找联系人是否存在
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        //查找用户输入的联系人姓名
        if (abs->personArray[i].m_Name == name)
        {
            return i; //找到联系人则返回该联系人在数组中的下标编号
        }
    }
    return -1; //没有找到则返回-1
}

//封装删除联系人的函数
void deletePerson(Addressbooks *abs)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1]; //数据迁移，覆盖下标
        }
        abs->m_Size--; //通讯录人数减一
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}

//查找联系人
int FindPerson(Addressbooks *abs)
{
    cout << "请输入要查找的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
        for (int i = 0; i < abs->m_Size; i++)
        {
            if (abs->personArray[i].m_Name == name)
            {
                cout << "查到此联系人，他的信息如下：" << endl;
                cout << "姓名： " << abs->personArray[i].m_Name << " \t ";
                cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"; //注意三目运算符的优先级
                cout << "年龄： " << abs->personArray[i].m_Age << " \t ";
                cout << "联系电话： " << abs->personArray[i].m_Phone << " \t ";
                cout << "地址： " << abs->personArray[i].m_Addr << endl;
            }
        }
    else
    {
        cout << "查无此人！！！" << endl;
    }

    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}

//修改联系人
void changePerson(Addressbooks *abs)
{
    cout << "你要修改的联系人姓名是：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入修改的名字为：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        cout << "请输入修改的性别为：" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入！！" << endl;
        }

        cout << "请输入修改的年龄为：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "请输入要修改的电话号码为：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "请输入要修改的地址为:" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

        cout << "修改成功！！！" << endl;
    }
    else
    {
        cout << "查无此人！！！" << endl;
    }
    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}

//清空联系人
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0; //将通讯录中的人数置零，逻辑清空通讯录
    cout << "通讯录已清空所有联系人！！" << endl;
    system("pause"); //任意键退出
    system("cls");   //清除屏幕
}

int main()

{

    int select = 0; //创建用户的选择变量

    Addressbooks abs; //创建结构体变量
    abs.m_Size = 0;   //初始化通讯录当前人员个数   .运算符访问结构体变量元素
    while (true)      //循环条件为假时退出循环
    {
        showMenu(); //调用封装的函数来显示菜单页

        cin >> select;
        switch (select)
        {
        case 1:              //1.添加联系人
            addPerson(&abs); //地址传递可通过形参修改实参值
            break;
        case 2: //2.显示联系人
            showperson(&abs);
            break;
        case 3: //3.删除联系人
            deletePerson(&abs);
            break;
        case 4: //4.查找联系人

            FindPerson(&abs);
            break;
        case 5: //5.修改联系人
            changePerson(&abs);
            break;
        case 6: //6.清空联系人
            cleanPerson(&abs);
            break;
        case 0: //0.退出通讯录
            cout << "欢迎下次使用！！" << endl;
            system("pause");
            return 0;
            break;

        default:
            break;
        }
    }

    system("pause");
    return 0;
}
