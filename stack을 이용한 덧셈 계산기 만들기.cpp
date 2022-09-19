#include <iostream>
#include <stack>

#define MAX(x,y) x>y ? x:y

using namespace std;


class myStack
{
public:
    int input1, input2, num1, num2, minus, up = 0;

    int Digits1(int input1);
    int Digits2(int input2);

    void division_Input1(int input1, int num1, int minus);
    void division_Input2(int input2, int num2, int minus);
    int sumStack(int up);
    stack< int > stack1;
    stack< int > stack2;
    stack< int > stack3;

};

int main()
{
    myStack data;

    int big, up = 0, a = 0;

    cout << "덧셈할 정수 2개를 입력해주세요. : ";
    cin >> data.input1 >> data.input2;
    cout << endl;

    data.num1 = data.Digits1(data.input1);
    data.num2 = data.Digits2(data.input2);

    data.minus = data.num1 - data.num2;

    data.division_Input1(data.input1, data.num1, data.minus);
    data.division_Input2(data.input2, data.num2, data.minus);

    big = MAX(data.num1, data.num2);

    for (int i = 0; i < big; i++)
    {
        up = data.sumStack(data.up);
        if (up > 0)
            data.up = up;
        data.stack1.pop();
        data.stack2.pop();
    }

    if (data.stack1.empty() && up == 1)
        data.stack3.push(up);

    while (!data.stack3.empty())
    {
        cout << data.stack3.top();
        data.stack3.pop();
    }

    cout << endl;

    return 0;
}

int myStack::Digits1(int input1)
{
    int pro = input1;
    int count = 0;
    while (pro / 10 != 0)
    {
        pro = pro / 10;
        count++;
    }
    return count + 1;
}

int myStack::Digits2(int input2)
{
    int pro = input2;
    int count = 0;
    while (pro / 10 != 0)
    {
        pro = pro / 10;
        count++;
    }
    return count + 1;
}

void myStack::division_Input1(int input1, int num1, int minus)
{
    if (minus < 0)
    {
        minus *= -1;
        for (int n = 0; n < minus; n++)
            stack1.push(0);
    }
    else minus = 0;

    int i = 10, count = 1 + minus, a;
    a = input1;

    while (a != 0)
    {
        if (stack1.size() == num1 + minus)
            break;

        if (input1 < 10)
        {
            stack1.push(input1);
            break;
        }

        if (stack1.size() == minus && a < i)
        {
            stack1.push(a);
            a = input1;
            i *= 10;
        }
        if (stack1.size() == count && a < i)
        {
            a %= 10;
            stack1.push(a);
            a = input1 * 10;
            count++;
            i *= 10;
        }
        a /= 10;
    }
}

void myStack::division_Input2(int input2, int num2, int minus)
{
    if (minus > 0)
    {
        for (int n = 0; n < minus; n++)
            stack2.push(0);
    }
    else minus = 0;

    int i = 10, count = 1 + minus, a;
    a = input2;

    while (a != 0)
    {
        if (stack2.size() == num2 + minus)
            break;

        if (input2 < 10)
        {
            stack2.push(input2);
            break;
        }

        if (stack2.size() == minus && a < i)
        {
            stack2.push(a);
            a = input2;
            i *= 10;
        }
        if (stack2.size() == count && a < i)
        {
            a %= 10;
            stack2.push(a);
            a = input2 * 10;
            count++;
            i *= 10;
        }
        a /= 10;
    }
}

int myStack::sumStack(int up)
{
    int a, b, sum;

    a = stack1.top();
    b = stack2.top();

    sum = a + b + up;

    if (sum > 9)
    {
        up = 1;
        sum %= 10;
    }
    else up = 0;

    stack3.push(sum);

    return up;
}