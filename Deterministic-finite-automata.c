#include <iostream>
#include <string>
using namespace std;
class dfa
{
public:
    int d[30][10], final[30];
    char alphabets[10];
    int no_states = 0, no_alphabets = 0, no_finals = 0;
    void features()
    {
        cout << "\nEnter number of states (less than 20 pls): ";
        cin >> no_states;
        cout << "\nEnter number of alphabets (less than 10 pls): ";
        cin >> no_alphabets;
        for (int i = 0; i < no_alphabets; i++)
        {
            cout << "Enter your alphabet " << i << " : ";
            cin >> alphabets[i];
        }
        cout << "Enter Number of final states : ";
        cin >> no_finals;
        for (int i = 0; i < no_finals; i++)
        {
            cout << "Enter your final State no." << i << " : ";
            cin >> final[i];
        }
        cout << "Now Enter Transitions \n";
        for (int i = 0; i < no_states; i++)
        {
            for (int j = 0; j < no_alphabets; j++)
            {
                cout << "(q" << i << "," << alphabets[j] << ") : ";
                cin >> d[i][j];
            }
        }
    }
    int next(int i, int a)
    {
        // cout << "\nthis" << i << a << endl;
        // cout << d[i][a] << endl;
        return d[i][a];
    }
    void run()
    {
        system("cls");
        cout << "Intital state : 0" << endl;
        dfa A;
        A.features();
        int temp = 1;
        while (temp != -1)
        {
            cout << "Enter String to check : ";
            string s;
            cin >> s;
            int state = 0;
            cout << "Intital state : 0" << endl;
            for (int i = 0; i < s.length(); i++)
            {
                int alpha;
                cout << s[i] << endl;
                for (int j = 0; j < A.no_alphabets; j++)
                {
                    alpha = -1;
                    if (s[i] == A.alphabets[j])
                    {
                        alpha = j;
                        break;
                    }
                }
                if (alpha == -1)
                {
                    cout << "\nWrong Alphabet caught" << endl;
                    goto l;
                }
                // cout << "\nAlphabet : " << alpha << endl;
                // cout<<state<<endl;
                state = A.next(state, alpha);
                cout << s[i] << "," << state << endl;
            }
            for (int i = 0; i < A.no_finals; i++)
            {
                if (state == A.final[i])
                {
                    cout << "String Accepted";
                    goto l;
                }
            }
            cout << "String Rejected";
        l:
            system("color 00");
            cout << "\nenter -1 to exit or 1 to continue : ";
            cin >> temp;
        }
    }
};
class dfa_2
{
    int d[8][2] = {{3, 2}, {4, 2}, {4, 5}, {4, 7}, {4, 6}, {6, 6}, {4, 8}, {4, 2}};

public:
    int next(int i, int a)
    {
        // cout << d[i][a] << endl;
        return d[i - 1][a];
    }
    void run()
    {
        system("cls");
        dfa_2 A;
        int temp = 1;
        while (temp != -1)
        {
            cout << "Enter String to check : ";
            string s;
            cin >> s;
            int state = 1;
            cout << "Intital state : 1" << endl;
            for (int i = 0; i < s.length(); i++)
            {
                int alpha;
                if (s[i] == 'a')
                {
                    alpha = 0;
                }
                else if (s[i] == 'b')
                {
                    alpha = 1;
                }
                else
                {
                    cout << "\nWrong Alphabet caught" << endl;
                    exit(0);
                }
                // cout<<state<<endl;
                state = A.next(state, alpha);
                cout << s[i] << "," << state << endl;
            }
            if (state == 6 || state == 8)
            {
                cout << "String Accepted";
            }
            else
            {
                cout << "String Rejected";
            }
            cout << "\nenter -1 to exit or 1 to continue : ";
            cin >> temp;
        }
    }
};
int main()
{
    cout << "Enter 1 to run predefined DFA that accept strings starting or ending with \"abb\" \n2 to build custom DFA :";
    int choice = 1;
    cin >> choice;
    if (choice == 1)
    {
        dfa_2 A;
        A.run();
    }
    else if (choice == 2)
    {
        dfa B;
        B.run();
    }
    else
    {
        cout << "Wrong Choice " << endl;
    }
    return 0;
}
