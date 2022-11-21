#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


class Car{
protected:
    string mType;
    float mConsume;
public:

    virtual void print() = 0;
    virtual void calculateConsume() = 0;
    float getConsume()
    {
        return mConsume;
    }
    ~Car(){};
};

class Gas:public Car{
private:
    float mGas;
public:
    Gas(){
        Car::mType="nedefinit";
        Car::mConsume=0;
        this->mGas=0;
    }
    Gas(float gas)
    {
        this->mGas=gas;
        Car::mType="benzina";
    }
    ~Gas(){};
    void print() override{
        cout<<mType<<' ';
        printf("%.2f\n",this->mGas);
    }

    void calculateConsume() override{
        Car::mConsume = this->mGas*5.8;
    }

};

class Hybrid:public Car{
private:
    float mGas,mBattery;
public:
    Hybrid(){
        Car::mType="nedefinit";
        Car::mConsume=0;
        this->mGas=0;
        this->mBattery=0;
    }
    Hybrid(float gas,float battery)
    {
        Car::mType="hibrid";
        mGas = gas;
        mBattery = battery;
    }
    void print() override{
        cout<<mType<<' ';
        printf("%.2f %.2f\n",this->mGas, this->mBattery);
    }
    void calculateConsume() override{
        Car::mConsume = this->mGas*5.8 + this->mBattery;
    }

};

class Diesel:public Car{
private:
    float mDiesel;
public:
    Diesel(float diesel){
        this->mDiesel=diesel;
        Car::mType="diesel";
    }
    Diesel(){
        Car::mType="nedefinit";
        Car::mConsume=0;
        this->mDiesel=0;
    }
    void print() override{
        cout<<mType<<' ';
        printf("%.2f\n",this->mDiesel);
    }

    void calculateConsume() override{
        Car::mConsume = this->mDiesel*6;
    }
};

bool cmp(Car* a, Car* b)
{
    a->calculateConsume();
    b->calculateConsume();
    return a->getConsume()<b->getConsume();
}
int main() {
    vector<Car*> vec;
    int n,i;
    float consum,hib;
    string tip;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tip;
        if(tip=="hibrid")
        {
            cin>>consum>>hib;
            vec.push_back(new Hybrid(consum,hib));


        }else if(tip=="benzina")
        {
            cin>>consum;
            vec.push_back(new Gas(consum));
        }else if(tip=="diesel")
        {
            cin>>consum;
            vec.push_back(new Diesel(consum));
        }
    }

    sort(vec.begin(),vec.end(),cmp);
    for(Car* a : vec)
    {
        a->print();
    }

    return 0;
}
