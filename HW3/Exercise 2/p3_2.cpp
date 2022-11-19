#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Spaceship{
private:
    string mName;
    int mAttack, mShield;
public:
    Spaceship(){
        mName="nedefinit";
        mAttack=0;
        mShield=0;
    }
    Spaceship(string name,int attack, int shield){
        mName = name;
        mAttack = attack;
        mShield = shield;
    }
    Spaceship(const Spaceship &r)
    {
        this->mName = r.mName;
        this->mShield = r.mShield;
        this->mAttack = r.mAttack;
    }


    Spaceship& operator=(const Spaceship &r) {
        this->mName = r.mName;
        this->mShield = r.mShield;
        this->mAttack = r.mAttack;
        return *this;
    }
    Spaceship operator+=(const Spaceship &r) {
        setAttack(mAttack+r.mAttack);
        setShield(mShield+r.mShield);
        return *this;
    }
    Spaceship operator-=(const Spaceship &r){
        setShield(this->mShield-r.mAttack);
        return *this;
    }
    Spaceship operator^(const Spaceship &r) {
        Spaceship a(*this), b(r);
        while ( a.mShield >0 && b.mShield>0)
        {
            a-=b;
            if (a.mShield >0)
            {
                b-=a;
            }
        }
        if (a.mShield >0)
            return a;
        return b;
    }

    bool operator<(const Spaceship &r) {
        if ( this->mShield+this->mAttack > r.mShield+r.mAttack)
            return true;
        return false;
    }

    string getName()  const{
        return mName;
    }

    void setName(string mName) {
        Spaceship::mName = mName;
    }

    int getAttack() const {
        return mAttack;
    }

    void setAttack(int mAttack) {
        Spaceship::mAttack = mAttack;
    }

    int getShield() const {
        return mShield;
    }

    void setShield(int mShield) {
        this->mShield = mShield;
    }
};

int main() {
    int at,sh, n,k,i;
    string com,nume,nume2;
    map<string,pair<Spaceship,bool>> ss;
    vector<string> vnume;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>nume>>at>>sh;
        ss.insert({nume,{Spaceship(nume,at,sh),true}});
        vnume.push_back(nume);
    }

    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>com>>nume>>nume2;
        if(com=="lupta" || com =="fight")
        {
            Spaceship a(ss[nume].first^ss[nume2].first);
            if(a.getName()==nume)
            {
                ss[nume2].second=false;
            }
            else ss[nume].second=false;
        }
        if(com=="combina" || com=="transfer")
        {
            ss[nume].first+=ss[nume2].first;
                ss[nume2].second=false;
        }
    }

    for(i=vnume.size()-1;i>=0;--i)
    {
        string a;
        if(k!=0)
        {
            a = vnume.at(i);

        } else {
            a = vnume.at(vnume.size()-1-i);
        }
        if(ss[a].second)
            cout<<a<<endl;
    }

    return 0;
}