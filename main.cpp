#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <regex>

using namespace std;
void op();
int main()
{

    while(true) {
        char c;
        cout << "A)start   B)exit";
        cin >> c;
        cin.ignore();
        c = tolower(c);
        if (c == 'a') {
            op();
        } else if (c == 'b')
            return 0;
        else{
            cout<<"invalid!!"<<"\n";
            continue;
        }

    }

    return 0;
}
void op() {
    //validate the input
    regex integer_expr("(\\+|\\-)?[0-9]+((\\+|\\-)?/[0-9]+)? [\\+\\-\\*/] (\\+|\\-)?[0-9]+((\\+|\\-)?/[0-9]+)?");

    while (true) {
        string s;

        double nominator1 = 0, nominator2 = 0, denominator1 = -1, denominator2 = -1, nominator = 0, denominator = 0;
        int move1 = 0, temp, j = 0;
        char operation = ' ', minus1 = ' ', minus2 = ' ';
        string n1 = "", n2 = "", d1 = "", d2 = "";
        while (true) {
            cout << "Enter the operation:";
            getline(cin, s);

            if (!regex_match(s, integer_expr)) {
                cout<< "Invalid input: You should follow this format: number then space then operation then space then another number"
                        <<"\n"<<"Note: it is not acceptable to put (-)sign in the denominator"<<"\n";
                continue;
            }
            break;
        }

        if (s[0] == '-') {
            minus1 = '-';
        }
//make loop inside the entered input to extract the dominators and nominators and the operation
        for (int i = 0; i < s.size(); i++) {
            move1 = i + 1;
            if (isdigit(s[i]))
                n1 += s[i];
            if (s[i] == '/' || s[i] == ' ')
                break;
        }
        //extract the nominantor of number1
        nominator1 = stod(n1);
       // cout<<nominator1<<"\n";

        for (int i = move1 - 1; i < s.size(); i++) {
            move1 = i + 1;
            if (isdigit(s[i]))
                d1 += s[i];
            if (s[i] == ' ')
                break;
        }
        //extract the denominator of number 1

        if (d1 != "") {
            denominator1 = stod(d1);

        }
        //cout<<denominator1<<"\n";

        //validate that the dominator is not zero
        if (denominator1 == 0) {
            cout << "Error: the dominator shouldn't be zero" << "\n";
            continue;

        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                j = i + 1;
                operation = s[i + 1];
                break;
            }
        }

        if (s[j + 2] == '-') {
            minus2 = '-';
        }

        for (int i = move1 + 2; i < s.size(); i++) {
            move1 = i + 1;
            if (isdigit(s[i]))
                n2 += s[i];
            if (s[i] == '/' || s[i] == '\0')
                break;
        }
        nominator2 = stod(n2);
        //cout<<nominator2<<"\n";

        for (int i = move1; i < s.size(); i++) {
            move1 = i + 1;
            if (isdigit(s[i]))
                d2 += s[i];
        }

        if (d2 != "") {
            denominator2 = stod(d2);
        }
        //cout<<denominator2<<"\n";
//check that the dominator isn't 0
        if (denominator2 == 0) {
            cout << "Error: the dominator shouldn't be zero" << "\n";
            continue;
        }
        if (denominator1 == -1) {
            denominator1 = 1;
        }
        if (denominator2 == -1) {
            denominator2 = 1;
        }

       // if (denominator1 > 0 && nominator2 == 0) {
       //     nominator2 = denominator1;
       //     denominator1 = 1;
       // }

        if (minus1 == '-') {
            nominator1 *= -1;
        }

        if (minus2 == '-') {
            nominator2 *= -1;
        }
        if (operation == '/' && n2 == "0") {
            cout << "Error: the dominator shouldn't be zero" << "\n";
            continue;
        }

// cases for the opeartion
        switch (operation) {
            case '+': {
                nominator = (nominator1 * denominator2) + (nominator2 * denominator1);
                denominator = denominator1 * denominator2;
                cout << nominator << '/' << denominator << endl;
                break;
            }

            case '-': {
                nominator = (nominator1 * denominator2) - (nominator2 * denominator1);
                denominator = denominator1 * denominator2;
                cout << nominator << '/' << denominator << endl;
                break;
            }

            case '*': {
                nominator = nominator1 * nominator2;
                denominator = denominator1 * denominator2;
                cout << nominator << '/' << denominator << endl;
                break;
            }

            case '/': {

                temp = nominator2;
                nominator2 = denominator2;
                denominator2 = temp;
                nominator = nominator1 * nominator2;
                denominator = denominator1 * denominator2;
                cout << nominator << '/' << denominator << endl;
                break;
            }
            default:
                cout << "Invalid operation" << endl;
                break;
        }
break;

    }
}