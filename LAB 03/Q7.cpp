#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class Shop {
private:
    string products[10];  
    float rates[10];

public:
    void addProduct(string name, float cost, int index, int maxItems) {
        if (index >= maxItems) {
            cout << "Sorry no other items can be added" << endl;
            return;
        }
        products[index] = name;
        rates[index] = cost;
        index++;
        cout << "Item added successfully" << endl;
    }

    void displayProducts() {
        for (int i = 0; i < 10; i++) {
            cout << "Item " << i + 1 << " :" << products[i] << endl;
        }
    }

    void updatePrice(string name, float newRate) {
        bool found = false;
        for (int i = 0; i < 10; i++) {
            if (products[i] == name) {
                found = true;
                rates[i] = newRate;
                cout << "Price Updated successfully";
                break;
            }
        }
        if (!found) {
            cout << "Item not found" << endl;
        }
    }

    void listProductsWithRates() {
        cout << "Items and Prices" << endl;
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << products[i] << " - $" << fixed << setprecision(2) << rates[i] << endl;
        }
    }

    void generateBill() {
        string purchased[20];
        int amounts[20];
        float totalPrice[20];
        int totalItems = 0;
        float billTotal = 0;
        string productName;
        int qty;

        cout << "Enter the purchase items OR Press Esc for done " << endl;
        while (true) {
            cout << "Enter the name of item:";
            cin >> productName;
            if (productName == "done") {
                break;
            }

            bool exists = false;
            int index = -1;
            for (int i = 0; i < 10; i++) {
                if (productName == products[i]) {
                    exists = true;
                    index = i;
                    break;
                }
            }
            if (exists) {
                cout << "Enter quantity:";
                cin >> qty;
                float itemCost = qty * rates[index];
                billTotal += itemCost;

                purchased[totalItems] = productName;
                amounts[totalItems] = qty;
                totalPrice[totalItems] = itemCost;
                totalItems++;
            } else {
                cout << "Item not found" << endl;
            }
        }
        cout << "\nRECEIPT\n";
        cout << "Item        Quantity        Price       Total\n";
        for (int i = 0; i < totalItems; i++) {
            cout << "    " << purchased[i] << "     " << amounts[i] << "     " << rates[i] << "      " << totalPrice[i] << endl;
        }
        cout << "Grand Total :" << billTotal;
    }
};

int main() {
    Shop store;
    int maxItems = 10;
    int currentIndex = 0;
    char option;
    string itemName, updateItem;
    float itemCost, updateCost;

    while (true) {
        cout << "1.Add items\n2.Fetch Items\n3.Edit Prices\n4.View Items and Prices\n5.Create receipt\n6.Exit\n";
        option = _getch();
        switch (option) {
            case '1':
                cout << "Enter item name:";
                cin >> itemName;
                cout << "Enter item Price:";
                cin >> itemCost;
                store.addProduct(itemName, itemCost, currentIndex, maxItems);
                break;
            case '2':
                store.displayProducts();
                break;
            case '3':
                cout << "Enter the item name for update price:";
                cin >> updateItem;
                cout << "Enter the price:";
                cin >> updateCost;
                store.updatePrice(updateItem, updateCost);
                break;
            case '4':
                store.listProductsWithRates();
                break;
            case '5':
                store.generateBill();
                break;
            case '6':
                cout << "Thank you for coming:";
                return 0;
            default:
                cout << "Invalid Input";
                break;
        }
    }
}
