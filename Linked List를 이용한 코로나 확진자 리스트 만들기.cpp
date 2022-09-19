#include <iostream>
#include <string>

using namespace std;

class corona_nation
{
public:
    corona_nation(string name = "empty", int num_of_confirmed_p = 0, int num_of_death_p = 0); 
    void print_info();


    string m_name;
    int m_num_of_confirmed_p;
    int m_num_of_death_p;
    double m_death_rate;
};

template <class T>
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = NULL;
    }

    DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL) {
        info = el;
        next = n;
        prev = p;
    }

    T info;
    DLLNode* next, * prev;
};

template <class T>
class DLL
{
public:
    DLL()
    {
        head = NULL;
    }

    ~DLL()
    {
        for (DLLNode<T>* p = NULL; p != NULL;)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    void AddtoDLLSorted(const T& el);
    void deleteDLLSorted(const string& name);
    void printDLLSorted();


    DLLNode<T>* head;
};

template <class T>
void DLL<T>::AddtoDLLSorted(const T& el)
{
    DLLNode<T>* temp = new DLLNode<T>;
    temp->info = el;

    if (head == NULL)
    {
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }

    else
    {
        DLLNode<T>* pt = head;
        while (el.m_name > pt->info.m_name)
        {
            if (pt->next == NULL) break;
            pt = pt->next;
        }

        if (pt == head)
        {
            pt->prev = temp;
            temp->next = pt;
            temp->prev = NULL;

            head = temp;
        }

        else if (pt->next == NULL)
        {
            pt->next = temp;
            temp->prev = pt;
            temp->next = NULL;
        }

        else
        {
            temp->prev = pt->prev;
            temp->next = pt;
            pt->prev->next = temp;
            pt->prev = temp;
        }
    }
}

template <class T>
void DLL<T>::deleteDLLSorted(const string& name)
{
    DLLNode<T>* pt = head;

    while (pt)
    {
        if (pt->info.m_name == name)
        {
            if (!pt->prev)
            {
                pt->next->prev = NULL;
                head = pt->next;	
            }

            else if (!pt->next) 
                pt->prev->next = NULL; 

            else 
            {
                pt->next->prev = pt->prev; 
                pt->prev->next = pt->next; 
            }			

            delete pt;
            break;
        }

        pt = pt->next;	
    }
}

template <class T>
void DLL<T>::printDLLSorted()
{
    DLLNode<T>* pt = head;
    while (pt != NULL)
    {
        pt->info.print_info();
        pt = pt->next;
    }
}


corona_nation::corona_nation(string name, int num_of_confirmed_p, int num_of_death_p)
{
    m_name = name;
    m_num_of_confirmed_p = num_of_confirmed_p;
    m_num_of_death_p = num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info()
{
    cout.width(12);
    cout << m_name;
    cout.width(12);
    cout << m_num_of_confirmed_p;
    cout.width(12);
    cout << m_num_of_death_p;
    cout.width(12);
    cout << m_death_rate << endl;
}

int main()
{
    DLL<corona_nation> DLLdata;

    DLLdata.AddtoDLLSorted(corona_nation("USA", 387547, 12291));
    DLLdata.AddtoDLLSorted(corona_nation("Spain", 140510, 13798));
    DLLdata.AddtoDLLSorted(corona_nation("Italy", 135586, 17127));
    DLLdata.AddtoDLLSorted(corona_nation("Germany", 107591, 2012));
    DLLdata.AddtoDLLSorted(corona_nation("China", 81802, 3333));
    DLLdata.AddtoDLLSorted(corona_nation("France", 78167, 10328));
    DLLdata.AddtoDLLSorted(corona_nation("Iran", 62589, 3872));
    DLLdata.AddtoDLLSorted(corona_nation("U.K", 55242, 6159));
    DLLdata.printDLLSorted();

    string temp;

    cout << "삭제 할 국가명을 입력해 주세요." << endl;
    cin >> temp;

    DLLdata.deleteDLLSorted(temp);

    DLLdata.printDLLSorted();

}
