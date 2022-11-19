#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

class Object{
private:
    string valuable;
    float price;
public:
    Object() : valuable(""), price(0) {}
    Object(const string &valuable, float price) : valuable(valuable), price(price) {}

    string getValuable() {
        return valuable;
    }

    float getPrice() {
        return price;
    }
};
class House{
private:
    string street,city;
    uint32_t number;
    vector<Object> valuables;
public:
    House() : street(""), city(""), number(0) {}
    House(const string &street, const string &city, uint32_t number) : street(street), city(city), number(number) {}

    string getStreet()  {
        return street;
    }

     string getCity()  {
        return city;
    }

    uint32_t getNumber()  {
        return number;
    }
    uint32_t getValuablesSize() {
        return valuables.size();
    }
    Object getValuable(uint32_t x){
        Object a(valuables[x].getValuable(),valuables[x].getPrice());
        return a;
    }
    void add(Object b)
    {
        valuables.push_back(b);
    } 
       
};
float getTotalPrice(House h){
        uint32_t size = h.getValuablesSize();
        float sum=0;
        for(int i=0;i<size;i++)
        {
            sum+=h.getValuable(i).getPrice();
        }
        return sum;
    } 
int main() {
string street,city,valuable;
uint32_t number,n,cont=0;
float price,sum;
vector<House> houses;
map<string,float> hnames;
vector<float> sums;
while(cin>>street)
{
    sum=0;
    cin>>city>>number>>n;
    House h(street,city,number);
    for (int i=0;i<n;i++)
    {
        cin>>valuable>>price;
        sum+=price;
        Object obj(valuable,price);
        h.add(obj);
    }

    houses.push_back(h);
    if(!hnames.count((street+" "+city)))
    {
        hnames.insert({(street+" "+city),sum});
    }
    else hnames[(street+" "+city)]+=sum;

}
for(pair<string,float> p : hnames)
{
     
    cout<<p.first<<" - ";
     
    cout<<p.second<<endl;
}

    return 0;
}

