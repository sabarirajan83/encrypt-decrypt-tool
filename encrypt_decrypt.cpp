// MESSAGE ENCRYPTION AND DECRYPTION PROGRAM 

#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstdlib>

using namespace std;

class message
{
string msg;
string num;
int *encnum;
int *decnum;
int encodemat[2][2] = { {2,3} , {1,2} };
int decmat[2][2] = { {2,-3} , {-1,2} };

public:
void inputenc();
void encode();
void printenc();
void inputdec();
void decode();
void printdec();
message() : encnum(nullptr), decnum(nullptr) {}
~message(){delete [] encnum;delete [] decnum;}
};

void message :: encode()
{
    if(encnum) 
    {
        delete[] encnum;
        encnum = nullptr;
    }
    
 int k=0;
 
    if(msg.length()%2 == 1)
        msg += ' ';
    
encnum = new int [msg.length()];

    for(int i=0;i<msg.length();i=i+2)
    {
        char c1,c2;
        int e1,e2,n1,n2;

        c1 = msg[i];
        c2 = msg[i+1];

        e1 = static_cast<int>(c1);
        e2 = static_cast<int>(c2);

        n1 = e1*encodemat[0][0] + e2*encodemat[1][0];
        n2 = e1*encodemat[0][1] + e2*encodemat[1][1];

        encnum[k] = n1;
        encnum[k+1] = n2;

        k+=2;
    }

printenc();
}

void message :: decode()
{
    if(decnum) 
    {
        delete[] decnum;
        decnum = nullptr;
    }

int len = num.length()/4;
msg = "";

decnum = new int [len];

    for(int i=0; i<len;++i) 
    {
        string four = num.substr(i*4,4);
        decnum[i] = stoi(four);
    }

    for(int i=0;i<len;i+=2)
    {
        char c1,c2;
        int d1,d2,n1,n2;
        
        d1 = decnum[i];
        d2 = decnum[i+1];
        
        n1 = d1*decmat[0][0] + d2*decmat[1][0];
        n2 = d1*decmat[0][1] + d2*decmat[1][1];
        
        c1 = static_cast<char>(n1);
        c2 = static_cast<char>(n2);
        
        msg+=c1;
        msg+=c2;
    }
    
printdec();
}

void message :: inputenc()
{
cout << "MESSAGE ENCRYPTION PROGRAM\n\n";
cout << "Give the message:\n";
getline(cin,msg);
cout << endl << "MESSAGE obtained !!\n\n";

encode();
}

void message :: inputdec()
{
cout << "MESSAGE DECRYPTION PROGRAM\n\n" << endl;

    while(1)
    {
    
    cout << "\nPaste the ENCODED CODE:\n";
    getline(cin,num);

    bool nums = true;
    
    for (int i=0;i<num.length();i++) 
    {
        if (!isdigit(num[i])) 
        {
            nums = false;
            break;
        }
    }

    if (!nums) 
    {
        cout << "\nInvalid input: contains non-digit characters\n";
        continue;
    } 
    else if (num.length() % 4 != 0) 
    {
        cout << "\nInvalid input: Incorrect type of CODE\n";
        continue;
    }
    else 
    {
        cout << "\nCODE Accepted!!\n";
        decode();
        break;
    }
    
    }
    
}

void message :: printenc()
{
cout << "ENCRYPTED CODE here" << endl;
    for(int i=0;i<msg.length();i++)
        cout << setw(4) << setfill('0') << encnum[i];
}

void message :: printdec()
{
cout << "\n\nDECODED MESSAGE:\n";
cout << endl << msg << endl;
}

int main()
{
    message m1;
    char c;
    
    cout << "MESSAGE ENCRYPTION AND DECRYPTION PROGRAM\n";
    
    while(1)
    {
    cout << "\n\nEnter\n(1) for Encryption\n(2) for Decryption\n(3) to Exit\n\nChoice :";
    cin >> c;
    cin.ignore();
    
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

        if(c=='1')
        {
            m1.inputenc();
            continue;
        }
        else if(c=='2')
        {
            m1.inputdec();
            continue;
        }
        else if(c=='3')
        {
            cout << "---Thank you---" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid input: Please try again\n";
            continue;
        }
    }
    
    return 0;
}
