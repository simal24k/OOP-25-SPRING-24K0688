#include <iostream>
#include <string>
#include <vector>

class Product {
protected:
    std::string productID;
    double price;

public:
    Product(std::string id, double p) : productID(id), price(p) {}

    virtual double calculatePrice() { return price; }

    virtual void applyDiscount(double discount) {}

    double getPrice() const { return price; }
};

class Electronics : public Product {
public:
    Electronics(std::string id, double p) : Product(id, p) {}

    double calculatePrice() override { return price * 1.15; }

    void applyDiscount(double discount) override {
        price *= (1 - discount);
    }
};

class Clothing : public Product {
public:
    Clothing(std::string id, double p) : Product(id, p) {}

    double calculatePrice() override { return price * 1.05; }

    void applyDiscount(double discount) override {
        price -= discount;
    }
};

class ShoppingCart {
private:
    std::vector<Product*> items;

public:
    void addItem(Product* item) {
        items.push_back(item);
    }

    void removeItem(Product* item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                break;
            }
        }
    }

    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart newCart;
        for (Product* item : items) {
            newCart.addItem(item);
        }
        for (Product* item : other.items) {
            newCart.addItem(item);
        }
        return newCart;
    }

    double calculateTotalPrice() const {
        double total = 0;
        for (Product* item : items) {
            total += item->calculatePrice();
        }
        return total;
    }

    ShoppingCart operator*(double bulkDiscount) {
        ShoppingCart newCart;
        for (Product* item : items) {
            double discountedPrice = item->calculatePrice() * (1 - bulkDiscount);
            if (Electronics* electronicsItem = dynamic_cast<Electronics*>(item)) {
                newCart.addItem(new Electronics(electronicsItem->productID, discountedPrice));
            } else if (Clothing* clothingItem = dynamic_cast<Clothing*>(item)) {
                newCart.addItem(new Clothing(clothingItem->productID, discountedPrice));
            }
        }
        return newCart;
    }

    ShoppingCart operator/(int users) {
        ShoppingCart newCart;
        double splitPrice = calculateTotalPrice() / users;
        for (Product* item : items) {
            if (Electronics* electronicsItem = dynamic_cast<Electronics*>(item)) {
                newCart.addItem(new Electronics(electronicsItem->productID, splitPrice));
            } else if (Clothing* clothingItem = dynamic_cast<Clothing*>(item)) {
                newCart.addItem(new Clothing(clothingItem->productID, splitPrice));
            }
        }
        return newCart;
    }

    void displayCart() const {
        std::cout << "Shopping Cart Items:\n";
        for (const Product* item : items) {
            std::cout << "Product ID: " << item->productID << ", Price: $" << item->calculatePrice() << std::endl;
        }
        std::cout << "Total Price: $" << calculateTotalPrice() << std::endl;
    }
};

int main() {
    Electronics laptop("E101", 1200);
    Clothing shirt("C202", 30);
    Clothing jeans("C203", 50);

    ShoppingCart cart1;
    cart1.addItem(&laptop);
    cart1.addItem(&shirt);

    ShoppingCart cart2;
    cart2.addItem(&jeans);

    cart1.displayCart();
    cart2.displayCart();

    ShoppingCart mergedCart = cart1 + cart2;
    mergedCart.displayCart();

    mergedCart.removeItem(&shirt);
    mergedCart.displayCart();

    ShoppingCart bulkDiscountCart = mergedCart * 0.1;
    bulkDiscountCart.displayCart();

    ShoppingCart splitCart = mergedCart / 2;
    splitCart.displayCart();

    return 0;
}
//self note: same as Q1
