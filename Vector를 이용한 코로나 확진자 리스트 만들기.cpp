#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class corona_nation
{
public:
    string A_name;
    string B_name;

    int people;
    int patient;
    int death;

    double patient_p;
    double death_p;
};

// �Ǻ� �Լ�
bool f_name(const corona_nation &a, const corona_nation &b)
{
    if (a.A_name < b.A_name)
        return true;
    else return false;
}

bool f_people(corona_nation x, corona_nation y)
{
    if (x.people > y.people)
        return true;
    else return false;
}

bool f_patient(corona_nation x, corona_nation y)
{
    if (x.patient > y.patient)
        return true;
    else return false;
}

bool f_death(corona_nation x, corona_nation y)
{
    if (x.death > y.death)
        return true;
    else return false;
}

bool f_patient_p(corona_nation x, corona_nation y)
{
    if (x.patient_p> y.patient_p)
        return true;
    else return false;
}

bool f_death_p(corona_nation x, corona_nation y)
{
    if (x.death_p > y.death_p)
        return true;
    else return false;
}

int main()
{
    int nnum;
    int show_num;
    int start;
    int erase_num;
    const int word = 15;

    corona_nation temp;
    vector <corona_nation> info;

    for(;;)
    {
        cout << "���ϴ� �۾��� ������ �ּ���" << endl;
        cout << "1. ����" << endl;
        cout << "2. ����" << endl;
        cout << "3. ����" << endl;
        cout << "4. ��Ϻ���" << endl;
        cout << "5. ������" << endl;
        cin >> start;
        switch(start)
        {
        case 1:
            cout << "�Է��� ������ ����" << endl;
            cin >> nnum;
            info.reserve(nnum+1);

            for (int i=0; i<nnum; i++)
            {
                cout << "��� : ";
                cin >> temp.A_name;
                cout << "������ : ";
                cin >> temp.B_name;
                cout << "�α��� : ";
                cin >> temp.people;
                cout << "Ȯ���� �� : ";
                cin >> temp.patient;
                cout << "����� �� : ";
                cin >> temp.death;
                cout << endl;
               temp.patient_p = ((double)temp.patient / (double)temp.people) * 100;
               temp.death_p = ((double)temp.death / (double)temp.patient) * 100;

                info.push_back(temp);
            }
            break;
        case 2:
            cout << "1. ������ ��" << endl;
            cout << "2. �α��� ��" << endl;
            cout << "3. Ȯ���� ��" << endl;
            cout << "4. ����� ��" << endl;
            cout << "5. Ȯ���� ���� ��" << endl;
            cout << "6. ����� ���� ��" << endl;

            cin >> show_num;

            switch (show_num)
            {
            case 1:
                sort(info.begin(), info.end(), f_name);
                break;

            case 2:
                sort(info.begin(), info.end(), f_people);
                break;

            case 3:
                sort(info.begin(), info.end(), f_patient);
                break;

            case 4:
                sort(info.begin(), info.end(), f_death);
                break;

            case 5:
                sort(info.begin(), info.end(), f_patient_p);
                break;

            case 6:
                sort(info.begin(), info.end(), f_death_p);
                break;
            }
            break;
        case 3:
            cout << "���ǥ�� �� ��°�� �����Ͻðڽ��ϱ�?" << endl;
            cin >> erase_num;

            info.erase(info.begin() + erase_num - 1);
            nnum--;
            break;
        case 4:
            cout.width(5);
            cout << "����";
            cout.width(word);
            cout << "�����";
            cout.width(word);
            cout << "������";
            cout.width(word);
            cout << "�α���";
            cout.width(word);
            cout << "Ȯ���� ��";
            cout.width(word);
            cout << "Ȯ���� ����";
            cout.width(word);
            cout << "����� ��";
            cout.width(word);
            cout << "����� ����" << endl;
            for (int i = 0; i < nnum; i++)
            {
                cout.width(5);
                cout << i + 1;
                cout.width(word); cout << info[i].A_name;
                cout.width(word); cout << info[i].B_name;
                cout.width(word); cout << info[i].people;
                cout.width(word); cout << info[i].patient;
                cout.width(word); cout << info[i].patient_p;
                cout.width(word); cout << info[i].death;
                cout.width(word); cout << info[i].death_p;
                cout << endl;
            }
            break;
        case 5:
            return 0;


        }
    }
}
