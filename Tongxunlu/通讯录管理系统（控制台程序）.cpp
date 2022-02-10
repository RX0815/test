#include <iostream>
using namespace std;
#include <string>
#define MAX 1000 //�궨��ͨѶ¼�����ϵ������Ϊ1000

struct Person //��ϵ�˽ṹ��
{
    string m_Name;  //����
    int m_Sex;      //�Ա�   1���� 2��Ů
    int m_Age;      //����
    string m_Phone; //��ϵ�绰
    string m_Addr;  //��ַ
};

struct Addressbooks
{
    struct Person personArray[MAX]; //�����ṹ������: ��������(�ṹ��) + ������[ Ԫ�ظ��� ]
    int m_Size;                     //ͨѶ¼��Ա����
};

//��װshowMenu��������ʾ�˵�
void showMenu()
{
    cout << "******************************" << endl;
    cout << "*********1. �����ϵ��********" << endl;
    cout << "*********2. ��ʾ��ϵ��********" << endl;
    cout << "*********3. ɾ����ϵ��********" << endl;
    cout << "*********4. ������ϵ��********" << endl;
    cout << "*********5. �޸���ϵ��********" << endl;
    cout << "*********6. �����ϵ��********" << endl;
    cout << "*********0. �˳�ͨѶ¼********" << endl;
    cout << "******************************" << endl;
}

void addPerson(Addressbooks *abs) //�����ϵ��
{
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼�������޷��������ϵ��" << endl;
        return;
    }
    else
    {
        //����
        cout << "�������½���ϵ�˵�������" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        //�Ա�
        cout << "��������ϵ�˵��Ա�Ϊ:" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;

        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������";
        }

        //����
        cout << "�������½���ϵ�˵�����Ϊ��" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        //�绰
        cout << "�������½���ϵ�˵ĵ绰�����ǣ�" << endl;
        string phone = "";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //��ַ
        cout << "�������½���ϵ�˵ĵ�ַΪ��" << endl;
        string Addr;
        cin >> Addr;
        abs->personArray[abs->m_Size].m_Addr = Addr;

        abs->m_Size++; //��ӳɹ���ͨѶ¼��Ա������һ

        cout << "��ӳɹ�" << endl;
    }
    system("pause"); //������˳�
    system("cls");   //�����Ļ
}
void showperson(Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "��ǰͨѶ¼��ϵ������Ϊ�㣡��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "������ " << abs->personArray[i].m_Name << " \t ";
            cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"; //ע����Ŀ����������ȼ�
            cout << "���䣺 " << abs->personArray[i].m_Age << " \t ";
            cout << "��ϵ�绰�� " << abs->personArray[i].m_Phone << " \t ";
            cout << "��ַ�� " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause"); //������˳�
    system("cls");   //�����Ļ
}

//������ϵ���Ƿ����
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        //�����û��������ϵ������
        if (abs->personArray[i].m_Name == name)
        {
            return i; //�ҵ���ϵ���򷵻ظ���ϵ���������е��±���
        }
    }
    return -1; //û���ҵ��򷵻�-1
}

//��װɾ����ϵ�˵ĺ���
void deletePerson(Addressbooks *abs)
{
    cout << "������Ҫɾ������ϵ��������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1]; //����Ǩ�ƣ������±�
        }
        abs->m_Size--; //ͨѶ¼������һ
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause"); //������˳�
    system("cls");   //�����Ļ
}

//������ϵ��
int FindPerson(Addressbooks *abs)
{
    cout << "������Ҫ���ҵ���ϵ��������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
        for (int i = 0; i < abs->m_Size; i++)
        {
            if (abs->personArray[i].m_Name == name)
            {
                cout << "�鵽����ϵ�ˣ�������Ϣ���£�" << endl;
                cout << "������ " << abs->personArray[i].m_Name << " \t ";
                cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"; //ע����Ŀ����������ȼ�
                cout << "���䣺 " << abs->personArray[i].m_Age << " \t ";
                cout << "��ϵ�绰�� " << abs->personArray[i].m_Phone << " \t ";
                cout << "��ַ�� " << abs->personArray[i].m_Addr << endl;
            }
        }
    else
    {
        cout << "���޴��ˣ�����" << endl;
    }

    system("pause"); //������˳�
    system("cls");   //�����Ļ
}

//�޸���ϵ��
void changePerson(Addressbooks *abs)
{
    cout << "��Ҫ�޸ĵ���ϵ�������ǣ�" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "�������޸ĵ�����Ϊ��" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        cout << "�������޸ĵ��Ա�Ϊ��" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "�����������������룡��" << endl;
        }

        cout << "�������޸ĵ�����Ϊ��" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        cout << "������Ҫ�޸ĵĵ绰����Ϊ��" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        cout << "������Ҫ�޸ĵĵ�ַΪ:" << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

        cout << "�޸ĳɹ�������" << endl;
    }
    else
    {
        cout << "���޴��ˣ�����" << endl;
    }
    system("pause"); //������˳�
    system("cls");   //�����Ļ
}

//�����ϵ��
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0; //��ͨѶ¼�е��������㣬�߼����ͨѶ¼
    cout << "ͨѶ¼�����������ϵ�ˣ���" << endl;
    system("pause"); //������˳�
    system("cls");   //�����Ļ
}

int main()

{

    int select = 0; //�����û���ѡ�����

    Addressbooks abs; //�����ṹ�����
    abs.m_Size = 0;   //��ʼ��ͨѶ¼��ǰ��Ա����   .��������ʽṹ�����Ԫ��
    while (true)      //ѭ������Ϊ��ʱ�˳�ѭ��
    {
        showMenu(); //���÷�װ�ĺ�������ʾ�˵�ҳ

        cin >> select;
        switch (select)
        {
        case 1:              //1.�����ϵ��
            addPerson(&abs); //��ַ���ݿ�ͨ���β��޸�ʵ��ֵ
            break;
        case 2: //2.��ʾ��ϵ��
            showperson(&abs);
            break;
        case 3: //3.ɾ����ϵ��
            deletePerson(&abs);
            break;
        case 4: //4.������ϵ��

            FindPerson(&abs);
            break;
        case 5: //5.�޸���ϵ��
            changePerson(&abs);
            break;
        case 6: //6.�����ϵ��
            cleanPerson(&abs);
            break;
        case 0: //0.�˳�ͨѶ¼
            cout << "��ӭ�´�ʹ�ã���" << endl;
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
