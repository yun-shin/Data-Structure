#include <iostream>
#include <cstring>
#include<string>
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

class TreapNode
{
public:
    TreapNode()
    {
        right = left = NULL;
    }

    TreapNode(const corona_nation& el, TreapNode* r = NULL, TreapNode* l = NULL, TreapNode* u = NULL)
    {
        info = el;
        right = r;
        left = l;
    }

    corona_nation info;
    TreapNode* right, * left;

    void InsertT(TreapNode* root, TreapNode* temp);
    void InsertTreap(const corona_nation& el);
    void printTreap(TreapNode* p);
    void search(TreapNode* p, string temp);
    void DeleteNode();
};

TreapNode* root = NULL;
TreapNode* returns = NULL;
TreapNode* up = NULL;

void TreapNode::InsertT(TreapNode* pt, TreapNode* temp)
{
    if (pt->info.m_death_rate > temp->info.m_death_rate) // 대스레이트 높은놈이 위임
    {
        if (pt->info.m_name > temp->info.m_name)//이름값이 큰ㄱ ㅔ오른쪽 temp 가왼쪽
        {
            if (pt->left == NULL)
            {
                pt->left = temp;
            }

            else if (pt->left->info.m_death_rate > temp->info.m_death_rate)
            {
                InsertT(pt->left, temp);
            }

            else
            {
                if (pt->left->info.m_name > temp->info.m_name)
                    temp->right = pt->left;
                else
                    temp->left = pt->left;
                pt->left = temp;
            }

        }
        else
        {
            if (pt->right == NULL)
            {
                pt->right = temp;
            }

            else if (pt->right->info.m_death_rate > temp->info.m_death_rate)
            {
                InsertT(pt->right, temp);
            }

            else
            {
                if (pt->right->info.m_name > temp->info.m_name)
                    temp->right = pt->right;
                else
                    temp->left = pt->right;
                pt->right = temp;
            }
        }
    }

    else
    {
        if (pt->info.m_name > temp->info.m_name)
        {
            temp->right = pt;
            root = temp;
        }

        else
        {
            temp->left = pt;
            root = temp;
        }
    }
}

void TreapNode::InsertTreap(const corona_nation& el)
{
    TreapNode* temp = new TreapNode;
    TreapNode* pt = root;
    temp->info = el;

    if (root == NULL)
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }

    else
    {
        InsertT(pt, temp);
    }
}

void TreapNode::printTreap(TreapNode* p)
{
    if (p == NULL)
    {
        cout << "root 오류: root가 없음" << endl;
        return;
    }

    if (p->right != NULL)
    {
        p->printTreap(p->right);
    }

    if (p->left != NULL)
    {
        p->printTreap(p->left);
    }

    p->info.print_info();
}

void TreapNode::DeleteNode()
{
    TreapNode* temp = new TreapNode;
    temp->right = NULL;
    temp->left = NULL;

    if (root == returns)
    {
        if (returns->right == NULL && returns->left != NULL)
        {
            root = returns->left;
            delete returns;
        }

        else if (returns->left == NULL && returns->right != NULL)
        {
            root = returns->right;
            delete returns;
        }

        else if (returns->left == NULL && returns->right == NULL)
        {
            delete returns;
        }

        else
        {
            if (returns->right->info.m_death_rate > returns->left->info.m_death_rate) //큰놈이 위에
            {
                temp->right = root->right->right;
                temp->left = root->right->left;

                root = root->right;

                root->right = returns;
                root->left = returns->left;

                returns->right = temp->right;
                returns->left = temp->left;
                DeleteNode();
            }

            else
            {
                temp->right = root->left->right;
                temp->left = root->left->left;

                root = root->left;

                root->right = returns->right;
                root->left = returns;

                returns->right = temp->right;
                returns->left = temp->left;
                DeleteNode();
            }
        }
    }

    else
    {
        if (up->info.m_name > returns->info.m_name)//이름값이 큰ㄱ ㅔ오른쪽 returns 가왼쪽
        {
            if (returns->right == NULL && returns->left != NULL)
            {
                up->left = returns->left;
                delete returns;
            }

            else if (returns->left == NULL && returns->right != NULL)
            {
                up->left = returns->right;
                delete returns;
            }

            else if (returns->left == NULL && returns->right == NULL)
            {
                delete returns;
            }

            else
            {
                if (returns->right->info.m_death_rate > returns->left->info.m_death_rate) //큰놈이 위에
                {
                    temp->right = returns->right; //d
                    temp->left = returns->left; // c

                    returns->left = returns->right->left; //d_left
                    returns->right = returns->right->right; // d->right

                    up->left = temp->right; // d
                    up->left->left = temp->left; // c
                    up->left->right = returns;
                    DeleteNode();
                }

                else
                {
                    temp->right = returns->right; //d
                    temp->left = returns->left; // c

                    returns->right = returns->left->right;
                    returns->left = returns->left->left;

                    up->left = temp->left;
                    up->left->right = temp->right;
                    up->left->left = returns;
                    DeleteNode();
                }
            }
        }

        else
        {
            if (returns->right == NULL && returns->left != NULL)
            {
                up->right = returns->left;
                delete returns;
            }

            else if (returns->left == NULL && returns->right != NULL)
            {
                up->right = returns->right;
                delete returns;
            }

            else if (returns->left == NULL && returns->right == NULL)
            {
                delete returns;
            }

            else
            {
                if (returns->right->info.m_death_rate > returns->left->info.m_death_rate) //큰놈이 위에
                {
                    temp->right = returns->right; 
                    temp->left = returns->left; 

                    returns->left = returns->right->left; 
                    returns->right = returns->right->right; 

                    up->right = temp->right;  
                    up->right->left = temp->left;  
                    up->right->right = returns;
                    DeleteNode();
                }

                else
                {
                    temp->right = returns->right; 
                    temp->left = returns->left; 

                    returns->right = returns->left->right;
                    returns->left = returns->left->left;

                    up->right = temp->left;
                    up->right->right = temp->right;
                    up->right->left = returns;
                    DeleteNode();
                }
            }
        }
    }
}

void TreapNode::search(TreapNode* p, string temp)
{

    if (p->info.m_name == temp)
    {
        returns = p;
        return;
    }

    else if (p->info.m_name > temp)
    {
        if (p->left != NULL)
        {
            cout << "지나간 나라는: " << p->info.m_name << "입니다." << endl;
            up = p;
            search(p->left, temp);
        }

        else
        {
            cout << "지나간 나라는: " << p->info.m_name << "입니다." << endl;
            up = p;
            search(p->right, temp);
        }
    }

    else
    {
        if (p->right != NULL)
        {
            cout << "지나간 나라는: " << p->info.m_name << "입니다." << endl;
            up = p;
            search(p->right, temp);
        }

        else
        {
            cout << "지나간 나라는: " << p->info.m_name << "입니다." << endl;
            up = p;
            search(p->left, temp);
        }
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
    TreapNode TreapData;
    string temp;
    int num;

    TreapData.InsertTreap(corona_nation("Spain", 140510, 13798));   
    TreapData.InsertTreap(corona_nation("Italy", 135586, 17127));   
    TreapData.InsertTreap(corona_nation("Germany", 107591, 2012));  
    TreapData.InsertTreap(corona_nation("China", 81802, 3333));     
    TreapData.InsertTreap(corona_nation("France", 78167, 10328));   
    TreapData.InsertTreap(corona_nation("Iran", 62589, 3872));     
    TreapData.InsertTreap(corona_nation("U.K", 55242, 6159));      
    TreapData.InsertTreap(corona_nation("USA", 387547, 12291));    

    while (1)
    {
        cout << "메뉴" << endl;
        cout << "1. 검색" << endl;
        cout << "2. 지우기" << endl;
        cout << "3. 목록보기" << endl;
        cout << "4. 종료" << endl;

        cin >> num;

        switch (num)
        {
        case 1:
            cout << "검색할 국가를 입력하세요." << endl;
            cin >> temp;
            TreapData.search(root, temp);
            cout << "현재 위치는: " << returns->info.m_name << endl;
            break;

        case 2:
            cout << "제거 할 국가이름을 입력해주세요." << endl;
            cin >> temp;
            TreapData.search(root, temp);
            TreapData.DeleteNode();
            break;

        case 3:
            TreapData.printTreap(root);
            break;

        case 4:
            return 0;
        }
    }
}