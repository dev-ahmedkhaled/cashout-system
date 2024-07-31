#include <iostream>
#include <vector>

using namespace std;

int choice;
int number;

string items [] = {"Biscuits", "Pepsi", "Chips", "Water", "Juice", "Milk", "Vegetables", "Fruits", "Cereal", "Gum"};
vector<string> cart_items = {};
vector <int> cart_prices = {};
vector <int> cart_numbers = {};

int add_items(){
    while (true){
        cout<<"\nEnter your item: ";
        cin >> choice;
        if (choice <= 9 && choice>= 0){
            cout<<"Enter item quantity: ";
            cin>>number;
            if (number>=0){
                cart_numbers.push_back(number);
                cart_items.push_back(items[choice]);
                switch (choice) {
                    case 0:{
                        cart_prices.push_back(7);
                    }break;
                    case 1:{
                        cart_prices.push_back(10);
                    }
                    case 2:{
                        cart_prices.push_back(5);
                    }
                    case 3:{
                        cart_prices.push_back(5);
                    }
                    case 4:{
                        cart_prices.push_back(19);
                    }
                    case 5:{
                        cart_prices.push_back(22);
                    }
                    case 6:{
                        cart_prices.push_back(17);
                    }
                    case 7:{
                        cart_prices.push_back(13);
                    }
                    case 8:{
                        cart_prices.push_back(25);
                    }
                    case 9:{
                        cart_prices.push_back(2);
                    }
                }
            }else{
                cout<<"Enter a valid quantity";
                break;
            }
        }else{
            cout<<endl<<endl;
            break;
        }
    }
    return choice;
}

void check(){
    int num = cart_items.size();
    for (int i = 0; i < num; i++) {
        cout<<"-------------------------------------"<<endl;
        cout<<cart_items[i]<<" x "<<cart_numbers[i]<<" = ("<<cart_prices[i] * cart_numbers[i] <<" EGP)"<< endl;
    }
}

void total(){
    int sum = 0;
    int num = cart_items.size();
    for (int i = 0; i < num; i++) {
        sum += cart_prices[i] * cart_numbers[i];
    }
    cout<<"-------------------------------------"<<endl;
    cout<<"Your Total is: "<< sum <<" EGP"<< endl;
    cout<<"-------------------------------------"<<endl;
}



int main() {
    cout<<"Please choose the items you want from the list below using their corresponding number (To proceed to checkout enter any number other than the "
          "numbers listed below):\n0 --> Biscuits (7 EGP)\n1 --> Pepsi (10 EGP)\n2 --> Chips (5 EGP)\n3 --> Water (5 EGP)\n4 --> Juice (19 EGP)\n5 --> "
          "Milk (22 EGP)\n6 --> Vegetables (17 EGP)\n7 --> Fruits (13 EGP)\n8 --> Cereal (25 EGP)\n9 --> Gum (2 EGP)\n";
    add_items();
    if (!cart_items.empty()){
        check();
        total();
    }else if (cart_items.empty() && choice >= 9 || choice<= 0){
        cout<<"The item you chose isn't available at our store."<< endl;
    }
    return 0;
}