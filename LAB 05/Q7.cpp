#include <iostream>
using namespace std;

class MenuItem {
    string dishName;
    double dishPrice;
public:
    MenuItem(string name = "Unknown", double price = 0.0) 
        : dishName(name), dishPrice(price) {}
    string getName() { return dishName; }
    double getPrice() { return dishPrice; }
};

class MenuList {
    MenuItem* foodList;
    int totalItems;
public:
    MenuList(int num = 0) : totalItems(num) {
        foodList = new MenuItem[totalItems];
    }
    ~MenuList() { delete[] foodList; }
    
    void addDish(string name, double price, int pos) {
        if (pos < totalItems) {
            foodList[pos] = MenuItem(name, price);
        }
    }
    void showMenu() {
        cout << "Menu Available:" << endl;
        for (int i = 0; i < totalItems; i++) {
            cout << i + 1 << ". " << foodList[i].getName() 
                 << " - $" << foodList[i].getPrice() << endl;
        }
    }
    MenuItem getItem(int idx) {
        if (idx < totalItems) return foodList[idx];
        return MenuItem();
    }
};

class PaymentInfo {
    double totalDue;
public:
    PaymentInfo(double amt = 0.0) : totalDue(amt) {}
    void completePayment() {
        cout << "Processed payment of $" << totalDue << endl;
    }
};

class CustomerOrder {
    MenuItem* itemsOrdered;
    int numOrdered;
    double orderTotal;
public:
    CustomerOrder(int count = 0) : numOrdered(count), orderTotal(0.0) {
        itemsOrdered = new MenuItem[numOrdered];
    }
    ~CustomerOrder() { delete[] itemsOrdered; }
    
    void includeItem(MenuItem item, int idx) {
        if (idx < numOrdered) {
            itemsOrdered[idx] = item;
            orderTotal += item.getPrice();
        }
    }
    void showOrderDetails() {
        cout << "\nYour Order:" << endl;
        for (int i = 0; i < numOrdered; i++) {
            cout << itemsOrdered[i].getName() << ": $" 
                 << itemsOrdered[i].getPrice() << endl;
        }
        cout << "Total Amount: $" << orderTotal << endl;
    }
    void payForOrder() {
        PaymentInfo payment(orderTotal);
        payment.completePayment();
    }
};

class RestaurantSystem {
    MenuList restaurantMenu;
public:
    RestaurantSystem(int menuSize) : restaurantMenu(menuSize) {}
    MenuList& getMenu() { return restaurantMenu; }
};

int main() {
    RestaurantSystem myRestaurant(3);
    MenuList& menu = myRestaurant.getMenu();
    
    // Adding items to menu
    menu.addDish("Sandwich", 4.50, 0);
    menu.addDish("Salad", 6.75, 1);
    menu.addDish("Soup", 3.25, 2);
    menu.showMenu();

    // Placing an order
    CustomerOrder newOrder(2);
    newOrder.includeItem(menu.getItem(0), 0); // Sandwich
    newOrder.includeItem(menu.getItem(2), 1); // Soup
    newOrder.showOrderDetails();
    newOrder.payForOrder();

    return 0;
}
