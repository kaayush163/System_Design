#include<iostream>
#include<vector>
using namespace std;

class Item_abstract{
public:
    virtual ~Item_abstract(){}
    virtual string getId() const = 0;
    virtual float getprice() const = 0;;
};

class Item : public Item_abstract{
private:
    string name;
    string Id;
    float price;
public:
    Item(string name, string Id, float price){
        this->name = name;
        this->Id = Id;
        this->price = price;
    }
    string getId() const override {return Id;}
    float getprice() const override {return price;}

};


class CustomerPersonalDetails_abstract{
public:
    virtual ~CustomerPersonalDetails_abstract(){}
    virtual void setName(string name, int Id) = 0;
    virtual string getName() const = 0;
    virtual int getId() const = 0;
};

class CustomerPersonalDetails : public CustomerPersonalDetails_abstract{
private:
 string name;
 int Id;
public:
 void setName(string name, int Id) override {
     this->name = name; this->Id = Id;
 }
 string getName()const override { return name; }
 int getId() const override { return Id; }
};

class ItemDetails_Abstract{
public:
    virtual ~ItemDetails_Abstract(){}
    virtual void addItem(const Item& item) = 0;
    virtual void removeItem(const string& itemId) = 0;
    virtual float calculateTotalSum() const = 0;
    virtual vector<Item> getItems() const = 0;
};

class ItemDetails : public ItemDetails_Abstract{
private:
 vector<Item> items; //list of Items
 float totalAmount;
public:
 void addItem(const Item& item) override {items.push_back(item);}
 void removeItem(const string& itemId) override {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == itemId) {
                items.erase(it);
                break;
            }
        }
    };
 float calculateTotalSum() const override {
        float total = 0;
        for(auto it : items){
            total += it.getprice();
        }
        return total;
    }
    vector<Item> getItems() const override {
        return items;
    }
};

class GenerateInvoice_Abstract{
public:
    virtual ~GenerateInvoice_Abstract(){}
    virtual void printInvoice(const vector<Item>& items) const = 0;
};

class GenerateInvoice : public GenerateInvoice_Abstract{
public:
 void printInvoice(const vector<Item>& items) const override {
        float total = 0;
        for(auto it : items){
            total += it.getprice();
        }
        cout << "Your bill is : " << total << endl;
    }
};

int main() {
    // Example usage
    CustomerPersonalDetails customer;
    customer.setName("Aayush", 1);

    ItemDetails itemDetails;
    itemDetails.addItem(Item("Item1", "1", 10.5));
    itemDetails.addItem(Item("Item2", "2", 20.75));

    GenerateInvoice invoiceGenerator;
    invoiceGenerator.printInvoice(itemDetails.getItems());

    return 0;
}
