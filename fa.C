

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// File fa.C written by Rika Yoshii

// ** Change this to fit the HW3C specification - look for **
// ** Be sure to put the name of the programmer above each function
// ** Must have the same types of tracing couts as mytoken.


// MYTOKEN DFA done by Rika Sensei has a sample
// This FA is for a b^+
bool mytoken(string s) {
 
    int state = 0;
    int charpos = 0;

    cout << "Trying the mytoken machine..." << endl;
 
    while (s[charpos] != '\0')
    {
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;
        
        if (state == 0 && s[charpos] == 'a')
          state = 1;
        else
            if (state == 1 && s[charpos] == 'b')
                state = 2;
            else
                if (state == 2 && s[charpos] == 'b')
                    state = 2;
                else
                {
                    cout << "I am stuck in state " << state << endl;
                    return(false);
                }
        charpos++;
    }//end of while

    // where did I end up????
    if (state == 2) return(true);  // end in a final state
    else return(false);
}


// IDENT DFA done by **
 // This FA is for **
bool ident_token(string s)
{
    // ** complete this based on mytoken
    return false;
};


// REAL DFA done by Jer Cherng Law
// This FA is for d^*.d^+
bool real_token(string s)
{
    // ** complete this based on mytoken
    int state = 0;
    int charpos = 0;
    bool is_it_really_real = false;
    
    cout << "Trying the mytoken machine..." << endl;
    
    while (s[charpos] != '\0')
    {
        cout << "current state: " << state << endl;
        cout << "character: " << s[charpos] << endl;
        
        if (state == 0 && (s[charpos] == '2' || s[charpos] == '3'))
            state = 4;
        else
            if (state == 4 && (s[charpos] == '2' || s[charpos] == '3'))
                state = 4;
            // if met a decimal point
            else
                // set to real number if decimal point
                // can only be decimal point once so state 4 guarantees it will only occur once
                if ((state == 4 || state == 0)&& s[charpos] == '.')
                    state = 3;
                else if(state == 3 && (s[charpos] == '2' || s[charpos] == '3')){
                    state = 3;
                    is_it_really_real = true;
                }
                else
                {
                    cout << "I am stuck in state " << state << endl;
                    return(false);
                }
        charpos++;
    }//end of while
    
    // where did I end up????
    if (state == 3 && is_it_really_real) return(true);  // end in a final state
    else return(false);
}


//INT DFA done by **
// This FA is for **
bool integer_token(string s)
{
    // ** complete this based on mytoken
    
    return false;
};


typedef enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};


// To be completed by the entire group
int scanner(tokentype& the_type, string& w)
{
    // This goes through all machines one by one on the input string

    cout << "Scanner was called..." << endl;

    cout << "Give me a string: " ;
    cin >> w;

    if (mytoken(w))
        the_type = MYTOKEN;
    
    // ** add other if-then's here in the right order to go through
    // all FAs one by one and set the_type to be IDENT, REAL or INT.
    
    else if (ident_token(w))
        the_type = IDENT;

    else if (real_token(w))
        the_type = REAL;

    else if (integer_token(w))
        the_type = INT;
    
  
    else //none of the FAs returned TRUE
    {
        cout << "Lexical Error: The string is not in my language" << endl;
        the_type = ERROR;
    }

    return 0;
}//the very end



// The test-driver: to be completed by the entire group
int main()
{

    tokentype thetype;
    string theword;
    string thetype_string;

    while (true)  // keep on going
    {
       scanner(thetype, theword);  // the paramers will be set by Scanner

       cout << "Word is:" << theword << endl;   
        
        switch (thetype) {
            case 0:
                thetype_string = "ERROR";
                break;

            case 2:
                thetype_string = "IDENT";
                break;
                
            case 3:
                thetype_string = "REAL";
                break;
                
            case 4:
                thetype_string = "INT";
                break;
            default:
                break;
        }
        
        // ** display the actual token_type instead of a number
        cout << "Type is:" << thetype_string  << endl;
        
    }
}



