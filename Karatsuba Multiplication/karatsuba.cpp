#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int makeEqualLength(string &str1, string &str2) 
{ 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
    
    if (len1 < len2) 
    { 
        for (int i = 0 ; i < len2 - len1 ; i++) 
            str1 = '0' + str1; 
        return len2; 
    } 
    else if (len1 > len2) 
    { 
        for (int i = 0 ; i < len1 - len2 ; i++) 
            str2 = '0' + str2; 
    } 
    return len1; // If len1 >= len2 
} 


string addStrings(string num1,string num2){
	makeEqualLength(num1,num2);
	int carry = 0;
	int value;
	string out = "";
	for(int i=num1.length()-1;i >= 0 ;i--){

		value = ((num1[i]-'0') + (num2[i]-'0') + carry ) % 10;
		out = to_string(value) + out ;
		carry = ((num1[i]-'0') + (num2[i]-'0') + carry)/10;}
	if(carry > 0){
		return(to_string(carry) + out);
		}
	else{
		return(out);}
}

void padZeros(string &num1,int zeros){

	for(int i =0;i<zeros;i++){
		num1 = num1 + "0" ;
	}	
}

string karatsuba(string num1,string num2){
//implement karatsuba multiplication

	if(num1.length() < 2 && num2.length() < 2){
		return(to_string(stoi(num1)* stoi(num2))); 
	}
	else{
		makeEqualLength(num1,num2);
		int exponent = num1.length() - floor(num1.length()/2);
		string a  = num1.substr(0,floor(num1.length()/2));
		string b  = num1.substr(floor(num1.length()/2),string::npos);
		string c  = num2.substr(0,floor(num2.length()/2));
		string d  = num2.substr(floor(num2.length()/2),string::npos);
		string ac = karatsuba(a,c);

		string bd = karatsuba(b,d);
		string adbc = addStrings(karatsuba(a,d),karatsuba(b,c)) ;

		padZeros(ac,2*exponent);
		padZeros(adbc,exponent);
		return(addStrings(addStrings(ac,adbc),bd));
		}

}

int main(){
	string num1;
	string num2;
	cout<<"Enter first number : " <<endl ;
	cin >> num1;
	cout << "Enter second number : " << endl ;
	cin >> num2 ;
	//padZeros(num1,1);
	cout<<karatsuba(num1,num2)<<endl;

}

