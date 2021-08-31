
#include <bits/stdc++.h>
using namespace std;

class BigInteger{
bool positive=true;
    vector<int>number;

public:
    BigInteger(){
        positive=true;
    }
    BigInteger(long long num){
        if(num<0){
            positive=false;
            num*=-1;
        }
        else {
            positive = true;
        }
            int j=0;
        while(num>0){
            number.push_back(num%10);
            num/=10;//base
        j++;
        }
        reverse(number.begin(),number.end());
    }
    BigInteger(int num){
        if(num<0){
            positive=false;
            num*=-1;
        }
        else {
            positive = true;
        }
        int j=0;
        while(num>0){
            number.push_back(num%10);
            num/=10;//base
            j++;
        }
        reverse(number.begin(),number.end());
    }
  BigInteger(BigInteger &n):number(n.number),positive(n.positive){}

BigInteger(string snum){
        int a;
        int size=snum.length();
        positive=(snum[0] !='-');
        if(snum[0]=='-'){
            positive=false;
        }
        else{
            positive=true;
        }
if(positive) {

    for(int i=0;i<size;i++){
        number.push_back(snum[i]-'0');
    }
}
else{
    for(int i=1;i<size;i++){
        number.push_back(snum[i]-'0');
    }
}
    }


BigInteger operator+( BigInteger& b) {
BigInteger c;
int carry=0;
if(b.positive==false){
    BigInteger c;
    c=*this-b;
    return c;

}
else if(this->positive==false){
    BigInteger c;
    c=b-*this;
    return c;
}
else if(this->positive==false&&b.positive==false){
    BigInteger c;
    c.positive= false;
    c=b+*this;
    return c;

}
int i=this->number.size()-1,j=b.number.size()-1;
while((i>=0) and (j>=0)){
    int x=(this->number[i])+b.number[j]+carry;
    c.number.push_back(x%10);
    carry=x/10;
    i--;
    j--;
}
while(i>=0){
    int x=(this->number[i])+carry;
    c.number.push_back(x%10);
    carry=x/10;
    i--;
}
    while(j>=0){
        int x=(this->number[j])+carry;
        c.number.push_back(x%10);
        carry=x/10;
        j--;
    }
    while(carry){
        c.number.push_back(carry%10);
        carry/=10;
    }
    reverse(c.number.begin(),c.number.end());
    return c;
    }
 BigInteger operator -(BigInteger & b){
     BigInteger c;
     int carry=0;

     int i=this->number.size()-1,j=b.number.size()-1;
     while((i>=0) and (j>=0)){
         int x=(this->number[i])-b.number[j]-carry;
         c.number.push_back(x%10);
         carry=x/10;
         i--;
         j--;
     }
     while(i>=0){
         int x=(this->number[i])-carry;
         c.number.push_back(x%10);
         carry=x/10;
         i--;
     }
     while(j>=0){
         int x=(this->number[j])-carry;
         c.number.push_back(x%10);
         carry=x/10;
         j--;
     }
     while(carry){
         c.number.push_back(carry%10);
         carry/=10;
     }
     reverse(c.number.begin(),c.number.end());
     return c;
    }
BigInteger operator +=(BigInteger b){
        *this=*this+b;
    return *this;
    }
 BigInteger operator-=(BigInteger &b){
        *this=*this-b;
        return *this;
    }

int compare(const BigInteger &b)const{//for honest i get it from the internet but i understood it first
    if (positive && !b.positive) return 1;
    if (!positive && b.positive) return -1;

    int check = 1;
    if (!positive && !b.positive) check = -1;

    if (number.size() < b.number.size()) return -1 * check;
    if (number.size() > b.number.size()) return check;
    for (size_t i(number.size()); i > 0; --i) {
        if (number[i-1] < b.number[i-1]) return -1 * check;
        if (number[i-1] > b.number[i-1]) return check;
    }

    return 0;
    }
    bool operator<(BigInteger const &b)const{
        return compare(b)==-1;
    }
    bool operator>(BigInteger const &b)const{
        return compare(b)==1;
    }
    bool operator<=(BigInteger const &b)const{
        return compare(b)==-1||compare(b)==0;
    }
    bool operator>=(BigInteger const &b)const{
        return compare(b)==1||compare(b)==0;
    }
    bool operator==(BigInteger const &b)const{
        return compare(b)==0;
    }
    bool operator!=(BigInteger const &b)const{
        return !(*this==b);
    }
    BigInteger& operator ++( ){

BigInteger c(1);
*this+=c;
        return *this;
    }
    BigInteger& operator ++( int){
BigInteger tem=*this;
        ++(*this);
        return tem;
    }
    BigInteger& operator --( ){
        BigInteger c(1);
        *this-=c;
        return *this;
    }


    friend  istream &operator>>(istream &in,BigInteger &b);
     friend ostream &operator<<(ostream &out, BigInteger &b);
};
istream &operator>>(istream &in,BigInteger &b){
    string str;
    in>>str;
    b=str;
    return in;
}
  ostream &operator<<(ostream &out, BigInteger &b){

    if (b.positive==true) {

        for (int i =0; i<(b.number.size()); i++) {
            out << b.number[i];
        }
    } else {
        cout << "-";

        for (int i =0; i<b.number.size(); i++) {
            out << b.number[i];
        }
    }
}


int main() {


    return 0;
}
